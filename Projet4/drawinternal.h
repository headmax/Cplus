
/************ COLORED NAMESPACE ******************/
namespace Colored
{
	// Standard colors (Red/Green/Blue/Alpha)
	Color AliceBlue = { 0.941176534f, 0.972549081f, 1.000000000f, 1.000000000f };
	Color AntiqueWhite = { 0.980392218f, 0.921568692f, 0.843137324f, 1.000000000f };
	Color Bisque = { 0.980392218f, 0.921454565f, 0.843141124f, 1.000000000f };
}

///////////////////////////////////////frames par secondes////////////////////
// Variables used to calculate frames per second:
DWORD g_dwFrames = 0;
DWORD g_dwCurrentTime = 0;
DWORD g_dwLastUpdateTime = 0;
DWORD g_dwElapsedTime = 0;
DWORD g_dwFPS = 0;
TCHAR g_szFPS[32] = { 0 };

std::unique_ptr<DirectX::GeometricPrimitive> g_Shape = NULL;
// Calculate the number of frames per one second:
DWORD GetFps()
{
	g_dwFrames++;
#pragma warning(suppress: 28159)
	g_dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
	g_dwElapsedTime = g_dwCurrentTime - g_dwLastUpdateTime;
	if (g_dwElapsedTime >= 1000)
	{
		g_dwFPS = (UINT)(g_dwFrames * 1000.0 / g_dwElapsedTime);
		wsprintf(g_szFPS, _T("FPS = %u"), (UINT)g_dwFPS);
		g_dwFrames = 0;
		g_dwLastUpdateTime = g_dwCurrentTime;
	}
	return g_dwFPS;
}
///////////////////////////////////////////////////////////////////////////////////////
Vector2 GetScreenXY()
{
	Vector2 screenXY = { 1, 1 };
	DxRenderer* pDxRenderer = DxRenderer::GetInstance();
	if (!IsValidPtr(pDxRenderer)) return screenXY;
	screenXY.x = (float)pDxRenderer->m_pScreen->m_WindowWidth;
	screenXY.y = (float)pDxRenderer->m_pScreen->m_WindowHeight;
	return screenXY;
}


bool WorldToScreen(Vector4 pV, Vector2* pOut2d)
{

	Matrix pWorld = DirectX::XMMatrixIdentity();

	GameRenderer* pGameRenderer = GameRenderer::GetInstance();
	if (!IsValidPtr(pGameRenderer)) return false;

	Matrix pProjection = pGameRenderer->m_pRenderView->m_ProjectionMatrix;
	Matrix pView = pGameRenderer->m_pRenderView->m_viewMatrix;

	Vector2 screenXY = GetScreenXY();

	float Width = screenXY.x;
	float Height = screenXY.y;

	Vector4  pOut = DirectX::XMVector3Project(pV, 0, 0, Width, Height, 0, 1, pProjection, pView, pWorld);

	if (pOut.z < 1.0f && pOut.w < 0.19) // a voir (pOut.z < 1.0f && pOut.w < 0.19)
	{
		pOut2d->x = pOut.x; pOut2d->y = pOut.y;
		return true;
	}

	return false;
}



bool worldToScreen2(Vec3 vWorldLocationVec3, Vec3* vOut)
{
	DxRenderer* pDxRenderer = DxRenderer::GetInstance();
	if (!IsValidPtr(pDxRenderer)) return false;

	GameRenderer* pGameRenderer = GameRenderer::GetInstance();
	if (!IsValidPtr(pGameRenderer)) return false;

	float mX = pDxRenderer->m_pScreen->m_Width * 0.5f;
	float mY = pDxRenderer->m_pScreen->m_Height * 0.5f;

	Matrix pProjection = pGameRenderer->m_pRenderView->m_ProjectionMatrix;
	Matrix pView = pGameRenderer->m_pRenderView->m_viewMatrix;

	float w =
		pView(0, 3) * vWorldLocationVec3.x +
		pView(1, 3) * vWorldLocationVec3.y +
		pView(2, 3) * vWorldLocationVec3.z +
		pView(3, 3);

	/*	if (w < 0.65f)
	{
	vOut->z = w;
	return false;
	}*/

	if (w < 0.19f)
	{
		vOut->z = w;
		return false;
	}

	float x =
		pView(0, 0) * vWorldLocationVec3.x +
		pView(1, 0) * vWorldLocationVec3.y +
		pView(2, 0) * vWorldLocationVec3.z +
		pView(3, 0);

	float y =
		pView(0, 1) * vWorldLocationVec3.x +
		pView(1, 1) * vWorldLocationVec3.y +
		pView(2, 1) * vWorldLocationVec3.z +
		pView(3, 1);

	vOut->x = mX + mX * x / w;
	vOut->y = mY - mY * y / w;
	vOut->z = w;

	return true;
}


namespace fb
{
	template <class T>
	class Tuple2
	{
	public:
		T Element1;
		T Element2;

	public:
		Tuple2(T _Element1, T _Element2)
		{
			Element1 = _Element1;
			Element2 = _Element2;
		}
	};

	class Color32
	{
	public:
		union
		{
			struct
			{
				BYTE R;
				BYTE G;
				BYTE B;
				BYTE A;
			};
			DWORD dwColor;
		};

	public:
		Color32(const DWORD _Color)
		{
			dwColor = _Color;
		}

		Color32(const BYTE Red, const BYTE Green, const BYTE Blue, const BYTE Alpha)
		{
			A = Alpha;
			R = Red;
			G = Green;
			B = Blue;
		}
	};

	class DebugRenderer2
	{
	public:
		static DebugRenderer2* Singleton(void) //Credits to KingOrgy for giving me some hints
		{
			typedef fb::DebugRenderer2* (__stdcall* fb__DebugRenderManager_getThreadContext_t)(void);
			fb__DebugRenderManager_getThreadContext_t fb__DebugRenderManager_getThreadContext = (fb__DebugRenderManager_getThreadContext_t)OFFSET_DBRENDERER;
			return fb__DebugRenderManager_getThreadContext();
		}


		void drawText(int x, int y, Color32 color, char* text, float scale)
		{
			typedef void(__thiscall *tdrawText)(fb::DebugRenderer2*, int, int, char*, Color32, float);
			tdrawText mdrawText = (tdrawText)OFFSET_DRAWTEXT;
			mdrawText(this, x, y, text, color, scale);
		}

		void drawLine2d(float x1, float y1, float x2, float y2, Color32 color)
		{
			Tuple2< float > minpos = Tuple2< float >(x1, y1);
			Tuple2< float > maxpos = Tuple2< float >(x2, y2);
			typedef void(__thiscall *tdrawLine2d)(fb::DebugRenderer2*, Tuple2<float>*, Tuple2<float>*, Color32);
			tdrawLine2d mdrawLine2d = (tdrawLine2d)OFFSET_DRAWLINE;
			mdrawLine2d(this, &minpos, &maxpos, color);
		}

		void drawLineRect2d(float x1, float y1, float x2, float y2, Color32 color)
		{
			Tuple2< float > minpos = Tuple2< float >(x1, y1);
			Tuple2< float > maxpos = Tuple2< float >(x2, y2);
			typedef void(__thiscall *tdrawLineRect2d)(fb::DebugRenderer2*, Tuple2<float>*, Tuple2<float>*, Color32);
			tdrawLineRect2d mdrawLineRect2d = (tdrawLineRect2d)OFFSET_DRAWLINERECT;
			mdrawLineRect2d(this, &minpos, &maxpos, color);
		}

		void drawRect2d(float x1, float y1, float x2, float y2, Color32 color)
		{
			Tuple2< float > minpos = Tuple2< float >(x1, y1);
			Tuple2< float > maxpos = Tuple2< float >(x2, y2);
			typedef void(__thiscall *tdrawRect2d)(fb::DebugRenderer2*, Tuple2<float>*, Tuple2<float>*, Color32);
			tdrawRect2d mdrawRect2d = (tdrawRect2d)OFFSET_DRAWFILLRECT;
			mdrawRect2d(this, &minpos, &maxpos, color);
		}

		void drawBox2d(float x1, float y1, float x2, float y2, float width, Color32 color) {
			drawRect2d(x1, y1, x2, y1 + width, color);
			drawRect2d(x1, y2 - width, x2, y2, color);
			drawRect2d(x1, y1 + width, x1 + width, y1 - width, color);
			drawRect2d(x2 - width, y1 + width, x2, y2 - width, color);
		}

		void drawSphere(Vec3 &pos, float radius, fb::Color32 color, bool renderLines, bool scalesmall)
		{
			typedef void(__thiscall *tDrawSphere)(fb::DebugRenderer2*, Vec3&, float, fb::Color32, bool renderLines, bool scalesmall);
			tDrawSphere mdrawSphere = (tDrawSphere)OFFSET_DRAWSPHERE;
			mdrawSphere(this, pos,radius, color, renderLines, scalesmall);
		};

		void cdrawCircle2d(float x, float y, float radius, Color32 color)
		{
			const int NUMPOINTS = 8 * 2;
			float X, Y;
			float PX = x + radius;
			float PY = y;
			float Theta, WedgeAngle; //Size of angle between two points on the circle (single wedge)
			WedgeAngle = (float)(DirectX::XM_2PI / NUMPOINTS);
			for (int i = 0; i <= NUMPOINTS; i++)
			{
				Theta = i * WedgeAngle;
				X = (float)(x + radius * cos(Theta));
				Y = (float)(y - radius * sin(Theta));
				drawLine2d(PX, PY, X, Y, color);
				PX = X;
				PY = Y;
			}
		}
		void cdrawLine3d(Vector4 start, Vector4 end, Color32 color)
		{
			Vector2 start2d = { 0, 0 }, end2d = { 0, 0 };
			if (WorldToScreen(start, &start2d) && WorldToScreen(end, &end2d)) drawLine2d(start2d.x, start2d.y, end2d.x, end2d.y, color);
		}

		void cdrawCircle3d(Vector4 point, float radius, Color32 color,unsigned int segment)
		{
			const int NUMPOINTS = 8 * 2;
			float X, Y;
			float PX = point.x + radius;
			float PY = point.y;
			float Theta, WedgeAngle; //Size of angle between two points on the circle (single wedge)
			WedgeAngle = (float)(DirectX::XM_2PI / NUMPOINTS);
			for (int i = 0; i <= NUMPOINTS; i++)
			{
				Theta = i * WedgeAngle;
				X = (float)(point.x + radius * cos(Theta));
				Y = (float)(point.y - radius * sin(Theta));
				cdrawLine3d({ PX, PY, point.z, 0 }, { X, Y, point.z, 0 }, color);
				PX = X;
				PY = Y;
			}
		}
		void cdrawSphere3d(Vector4 point, float radius, Color32 color, unsigned int segment)
		{
			unsigned int i = 0;
			Vector4 start;
			Vector4 end;
			end = { point.x, point.y + radius * cos(float(i) / segment * DirectX::XM_2PI), point.z + radius * sin(float(i) / segment * DirectX::XM_2PI), 0 };
			for (i = 1; i <= segment; i++)
			{
				start = end;
				end = { point.x, point.y + radius * cos(float(i) / segment * DirectX::XM_2PI), point.z + radius * sin(float(i) / segment * DirectX::XM_2PI), 0 };
				cdrawLine3d(start, end, color);
			}

			i = 0;
			end = { point.x + radius * sin(float(i) / segment *  DirectX::XM_2PI), point.y + radius * cos(float(i) / segment *  DirectX::XM_2PI), point.z, 0 };
			for (i = 1; i <= segment; i++)
			{
				start = end;
				end = { point.x + radius * sin(float(i) / segment *  DirectX::XM_2PI), point.y + radius * cos(float(i) / segment *  DirectX::XM_2PI), point.z, 0 };
				cdrawLine3d(start, end, color);
			}

			i = 0;
			end = { point.x + radius * sin(float(i) / segment * DirectX::XM_2PI), point.y, point.z + radius * cos(float(i) / segment * DirectX::XM_2PI), 0 };
			for (i = 1; i <= segment; i++)
			{
				start = end;
				end = { point.x + radius * sin(float(i) / segment * DirectX::XM_2PI), point.y, point.z + radius * cos(float(i) / segment * DirectX::XM_2PI), 0 };
				cdrawLine3d(start, end, color);
			}

	
		}
		void cdrawAabb3d(Vector4 vPosition, Vector4 vMin, Vector4 vMax, Matrix mTransform, Color32 color)
		{
			Vector4 vcrnr3d[9];
			vcrnr3d[1] = { vMin.x, vMin.y, vMin.z, 0 };
			vcrnr3d[2] = { vMax.x, vMin.y, vMin.z, 0 };
			vcrnr3d[3] = { vMax.x, vMin.y, vMax.z, 0 };
			vcrnr3d[4] = { vMin.x, vMin.y, vMax.z, 0 };
			vcrnr3d[5] = { vMin.x, vMax.y, vMax.z, 0 };
			vcrnr3d[6] = { vMin.x, vMax.y, vMin.z, 0 };
			vcrnr3d[7] = { vMax.x, vMax.y, vMin.z, 0 };
			vcrnr3d[8] = { vMax.x, vMax.y, vMax.z, 0 };

			for (int coin = 1; coin <= 8; coin++)
			{
				vcrnr3d[coin] = XMVector4Transform(vcrnr3d[coin], mTransform);
				vcrnr3d[coin] += vPosition;
			}
			//	   .5------8
			//	.'  |    .'|
			//	6---+--7'  |
			//	|   |  |   |
			//	|  ,4--+---3
			//	|.'    | .'
			//	1------2'
			cdrawLine3d(vcrnr3d[1], vcrnr3d[2], color);
			cdrawLine3d(vcrnr3d[6], vcrnr3d[7], color);
			cdrawLine3d(vcrnr3d[1], vcrnr3d[6], color);
			cdrawLine3d(vcrnr3d[2], vcrnr3d[7], color);

			cdrawLine3d(vcrnr3d[4], vcrnr3d[3], color);
			cdrawLine3d(vcrnr3d[5], vcrnr3d[8], color);
			cdrawLine3d(vcrnr3d[4], vcrnr3d[5], color);
			cdrawLine3d(vcrnr3d[3], vcrnr3d[8], color);

			cdrawLine3d(vcrnr3d[4], vcrnr3d[1], color);
			cdrawLine3d(vcrnr3d[5], vcrnr3d[6], color);
			cdrawLine3d(vcrnr3d[2], vcrnr3d[3], color);
			cdrawLine3d(vcrnr3d[7], vcrnr3d[8], color);

		}
	};
}


////////////////////////////////////////////
std::unique_ptr<DirectX::SpriteFont> m_SpriteFont = NULL;
std::unique_ptr<DirectX::SpriteBatch> m_SpriteBatch = NULL;
std::unique_ptr<DirectX::PrimitiveBatch<DirectX::VertexPositionColor>> m_PrimitiveBatch = NULL;
std::unique_ptr<DirectX::BasicEffect> m_BasicEffect = NULL;
Microsoft::WRL::ComPtr<ID3D11InputLayout> inputLayout;
/////////////////////////////////////////////////////////
HINSTANCE  inj_hModule;
namespace tk
{

	bool initSpriteFont()
	{
		if (!m_SpriteFont)
		{
			HRSRC hRsrc = FindResource(inj_hModule, MAKEINTRESOURCE(IDR_TKFONT1), "tkfont");
			if (hRsrc)
			{
				HGLOBAL hGlob = NULL;
				if (HGLOBAL hGlob = LoadResource(inj_hModule, hRsrc))
				{
					DWORD dwResSize = SizeofResource(inj_hModule, hRsrc);
					FILE_LOG(logINFO) << "Ressource Found size 0x" << std::hex << dwResSize;
					LPVOID pRes = LockResource(hGlob);
					FILE_LOG(logINFO) << "Ressource Found at 0x" << std::hex << pRes;
					m_SpriteBatch = std::unique_ptr<DirectX::SpriteBatch>(new DirectX::SpriteBatch(DxRenderer::GetInstance()->m_pContext));
					//m_SpriteFont = std::unique_ptr<DirectX::SpriteFont>(new DirectX::SpriteFont(DxRenderer::GetInstance()->m_pDevice, L"C:\\out\\wingdings.spritefont"));
					m_SpriteFont = std::unique_ptr<DirectX::SpriteFont>(new DirectX::SpriteFont(DxRenderer::GetInstance()->m_pDevice, (const uint8_t *)pRes, dwResSize));
					return true;
				}
				else return false;
			}
			else return false;
		}
		else return true;
	}
	bool initPrimitiveBatch()
	{
		if (!m_PrimitiveBatch)
		{
			m_BasicEffect = std::unique_ptr<DirectX::BasicEffect>(new DirectX::BasicEffect(DxRenderer::GetInstance()->m_pDevice));
			m_PrimitiveBatch = std::unique_ptr<DirectX::PrimitiveBatch<DirectX::VertexPositionColor>>(new DirectX::PrimitiveBatch<DirectX::VertexPositionColor>(DxRenderer::GetInstance()->m_pContext));
			m_BasicEffect->SetVertexColorEnabled(true);
			void const* shaderByteCode;
			size_t byteCodeLength;
			m_BasicEffect->GetVertexShaderBytecode(&shaderByteCode, &byteCodeLength);
			DxRenderer::GetInstance()->m_pDevice->CreateInputLayout(DirectX::VertexPositionColor::InputElements, DirectX::VertexPositionColor::InputElementCount, shaderByteCode, byteCodeLength, inputLayout.GetAddressOf());
			return true;
		}
		else return true;
	}
	void drawText(int x, int y, Color color, wchar_t* text, float scale)
	{
		initSpriteFont();
		//std::wstring name(L"hello, world!");
		//const wchar_t* wcstring = name.c_str();
		//Vector2 textOrigin = m_SpriteFont->MeasureString(wcstring);
		m_SpriteBatch->Begin();
		m_SpriteFont->DrawString(m_SpriteBatch.get(), text, Vector2((float)x, (float)y));
		m_SpriteBatch->End();
	}

	void drawLine2d(float x1, float y1, float x2, float y2, Color color)
	{

	}

	void drawLineRect2d(float x1, float y1, float x2, float y2, Color color)
	{

	}

	void drawRect2d(float x1, float y1, float x2, float y2, Color color)
	{

	}

	void drawBox2d(float x1, float y1, float x2, float y2, float width, Color color) {
		drawRect2d(x1, y1, x2, y1 + width, color);
		drawRect2d(x1, y2 - width, x2, y2, color);
		drawRect2d(x1, y1 + width, x1 + width, y1 - width, color);
		drawRect2d(x2 - width, y1 + width, x2, y2 - width, color);
	}

	void DrawShape(Matrix mTransform, Color color, float scale, bool wireFrame, bool allowocculted)
	{

		Matrix pWorld = pWorld.Identity();
		Quaternion Rotation;
		Vector3 Scale, Translation;
		mTransform.Decompose(Scale, Rotation, Translation);
		Matrix local = pWorld * Matrix::CreateScale(Scale) * Matrix::CreateFromQuaternion(Rotation) *Matrix::CreateTranslation(Translation);

		g_Shape->Draw(local, GameRenderer::GetInstance()->m_pRenderView->m_viewMatrix, GameRenderer::GetInstance()->m_pRenderView->m_ProjectionMatrix, color, nullptr, wireFrame,
			[=]
		{

			std::unique_ptr<DirectX::CommonStates> m_states = std::unique_ptr<DirectX::CommonStates>(new DirectX::CommonStates(DxRenderer::GetInstance()->m_pDevice));
			if (allowocculted)
				DxRenderer::GetInstance()->m_pContext->OMSetDepthStencilState(m_states->DepthNone(), 0); // visible a travers les objets du jeu
			else
				DxRenderer::GetInstance()->m_pContext->OMSetDepthStencilState(m_states->DepthRead(), 0); // non visible a travers les objets du jeu
		});
	}



	void DrawSphere(Vector4 position, Color color = Colored::AliceBlue, float scale = 1.0f, bool wireFrame = false, bool allowocculted = false)
	{
		Matrix pWorld = pWorld.Identity();
		Quaternion Rotation;
		Vector3 Scale, Translation;
		Matrix local = pWorld * Matrix::CreateTranslation((Vector3)position);
		g_Shape = DirectX::GeometricPrimitive::CreateSphere(DxRenderer::GetInstance()->m_pContext, scale);
		DrawShape(local, color, scale, wireFrame, allowocculted);
	}
	void cdrawCircle2d(float x, float y, float radius, Color color)
	{
		const int NUMPOINTS = 8 * 2;
		float X, Y;
		float PX = x + radius;
		float PY = y;
		float Theta, WedgeAngle; //Size of angle between two points on the circle (single wedge)
		WedgeAngle = (float)(DirectX::XM_2PI / NUMPOINTS);
		for (int i = 0; i <= NUMPOINTS; i++)
		{
			Theta = i * WedgeAngle;
			X = (float)(x + radius * cos(Theta));
			Y = (float)(y - radius * sin(Theta));
			drawLine2d(PX, PY, X, Y, color);
			PX = X;
			PY = Y;
		}
	}
	void cdrawLine3d(Vector4 start, Vector4 end, Color color)
	{
		initPrimitiveBatch();
		Matrix pWorld = pWorld.Identity();
		m_BasicEffect.get()->SetWorld(pWorld);
		m_BasicEffect.get()->SetView(GameRenderer::GetInstance()->m_pRenderView->m_viewMatrix);
		m_BasicEffect.get()->SetProjection(GameRenderer::GetInstance()->m_pRenderView->m_ProjectionMatrix);

		m_BasicEffect->Apply(DxRenderer::GetInstance()->m_pContext);
		DxRenderer::GetInstance()->m_pContext->IASetInputLayout(inputLayout.Get());

		m_PrimitiveBatch->Begin();
		DirectX::VertexPositionColor Vertex1;
		DirectX::VertexPositionColor Vertex2;
		Vertex1.color = color;
		Vertex2.color = color;
		Vertex1.position = (Vector3)start;
		Vertex2.position = (Vector3)end;

		m_PrimitiveBatch->DrawLine(Vertex1, Vertex2);
		m_PrimitiveBatch->End();
	}

	void cdrawCircle3d(Vector4 point, float radius, Color color, unsigned int segment)
	{
		const int NUMPOINTS = 8 * 2;
		float X, Y;
		float PX = point.x + radius;
		float PY = point.y;
		float Theta, WedgeAngle; //Size of angle between two points on the circle (single wedge)
		WedgeAngle = (float)(DirectX::XM_2PI / NUMPOINTS);
		for (int i = 0; i <= NUMPOINTS; i++)
		{
			Theta = i * WedgeAngle;
			X = (float)(point.x + radius * cos(Theta));
			Y = (float)(point.y - radius * sin(Theta));
			cdrawLine3d({ PX, PY, point.z, 0 }, { X, Y, point.z, 0 }, color);
			PX = X;
			PY = Y;
		}
	}
	void cdrawSphere3d(Vector4 point, float radius, Color color, unsigned int segment)
	{
		unsigned int i = 0;
		Vector4 start;
		Vector4 end;
		end = { point.x, point.y + radius * cos(float(i) / segment * DirectX::XM_2PI), point.z + radius * sin(float(i) / segment * DirectX::XM_2PI), 0 };
		for (i = 1; i <= segment; i++)
		{
			start = end;
			end = { point.x, point.y + radius * cos(float(i) / segment * DirectX::XM_2PI), point.z + radius * sin(float(i) / segment * DirectX::XM_2PI), 0 };
			cdrawLine3d(start, end, color);
		}

		i = 0;
		end = { point.x + radius * sin(float(i) / segment *  DirectX::XM_2PI), point.y + radius * cos(float(i) / segment *  DirectX::XM_2PI), point.z, 0 };
		for (i = 1; i <= segment; i++)
		{
			start = end;
			end = { point.x + radius * sin(float(i) / segment *  DirectX::XM_2PI), point.y + radius * cos(float(i) / segment *  DirectX::XM_2PI), point.z, 0 };
			cdrawLine3d(start, end, color);
		}

		i = 0;
		end = { point.x + radius * sin(float(i) / segment * DirectX::XM_2PI), point.y, point.z + radius * cos(float(i) / segment * DirectX::XM_2PI), 0 };
		for (i = 1; i <= segment; i++)
		{
			start = end;
			end = { point.x + radius * sin(float(i) / segment * DirectX::XM_2PI), point.y, point.z + radius * cos(float(i) / segment * DirectX::XM_2PI), 0 };
			cdrawLine3d(start, end, color);
		}
	}
	void cdrawAabb3d(Vector4 vPosition, Vector4 vMin, Vector4 vMax, Matrix mTransform, Color color)
	{
		Vector4 vcrnr3d[9];
		vcrnr3d[1] = { vMin.x, vMin.y, vMin.z, 0 };
		vcrnr3d[2] = { vMax.x, vMin.y, vMin.z, 0 };
		vcrnr3d[3] = { vMax.x, vMin.y, vMax.z, 0 };
		vcrnr3d[4] = { vMin.x, vMin.y, vMax.z, 0 };
		vcrnr3d[5] = { vMin.x, vMax.y, vMax.z, 0 };
		vcrnr3d[6] = { vMin.x, vMax.y, vMin.z, 0 };
		vcrnr3d[7] = { vMax.x, vMax.y, vMin.z, 0 };
		vcrnr3d[8] = { vMax.x, vMax.y, vMax.z, 0 };

		for (int coin = 1; coin <= 8; coin++)
		{
			vcrnr3d[coin] = XMVector4Transform(vcrnr3d[coin], mTransform);
			vcrnr3d[coin] += vPosition;
		}
		//    .5------8
		// .'  |    .'|
		// 6---+--7'  |
		// |   |  |   |
		// |  ,4--+---3
		// |.'    | .'
		// 1------2'
		cdrawLine3d(vcrnr3d[1], vcrnr3d[2], color);
		cdrawLine3d(vcrnr3d[6], vcrnr3d[7], color);
		cdrawLine3d(vcrnr3d[1], vcrnr3d[6], color);
		cdrawLine3d(vcrnr3d[2], vcrnr3d[7], color);

		cdrawLine3d(vcrnr3d[4], vcrnr3d[3], color);
		cdrawLine3d(vcrnr3d[5], vcrnr3d[8], color);
		cdrawLine3d(vcrnr3d[4], vcrnr3d[5], color);
		cdrawLine3d(vcrnr3d[3], vcrnr3d[8], color);

		cdrawLine3d(vcrnr3d[4], vcrnr3d[1], color);
		cdrawLine3d(vcrnr3d[5], vcrnr3d[6], color);
		cdrawLine3d(vcrnr3d[2], vcrnr3d[3], color);
		cdrawLine3d(vcrnr3d[7], vcrnr3d[8], color);
	}
	void drawteapot(Matrix mTransform, Color color, float scale)
	{
		g_Shape = DirectX::GeometricPrimitive::CreateTeapot(DxRenderer::GetInstance()->m_pContext, scale);
		Matrix pWorld = pWorld.Identity();
		Vector3 Scale, Translation;
		Quaternion Rotation;
		mTransform.Decompose(Scale, Rotation, Translation);

		Matrix local = pWorld * Matrix::CreateScale(Scale) * Matrix::CreateFromQuaternion(Rotation) *Matrix::CreateTranslation(Translation);
		g_Shape->Draw(local, GameRenderer::GetInstance()->m_pRenderView->m_viewMatrix, GameRenderer::GetInstance()->m_pRenderView->m_ProjectionMatrix, color); //DirectX::Colors::CornflowerBlue
	}

	void drawwiresphere(Matrix mTransform, int r, int g, int b, int a, float scale)
	{
		Color myColor;
		myColor.R((float)r);
		myColor.G((float)g);
		myColor.B((float)b);
		myColor.A((float)a);

		g_Shape = DirectX::GeometricPrimitive::CreateSphere(DxRenderer::GetInstance()->m_pContext, scale);
		Matrix pWorld = pWorld.Identity();
		Vector3 Scale, Translation;
		Quaternion Rotation;
		mTransform.Decompose(Scale, Rotation, Translation);

		Matrix local = pWorld * Matrix::CreateScale(Scale) * Matrix::CreateFromQuaternion(Rotation) *Matrix::CreateTranslation(Translation);
		g_Shape->Draw(local, GameRenderer::GetInstance()->m_pRenderView->m_viewMatrix, GameRenderer::GetInstance()->m_pRenderView->m_ProjectionMatrix, myColor, nullptr, true); //DirectX::Colors::CornflowerBlue
	}

	void drawwiresphere(Matrix mTransform, Color color, float scale)
	{
		g_Shape = DirectX::GeometricPrimitive::CreateSphere(DxRenderer::GetInstance()->m_pContext, scale);
		Matrix pWorld = pWorld.Identity();
		Vector3 Scale, Translation;
		Quaternion Rotation;
		mTransform.Decompose(Scale, Rotation, Translation); // dont know why i have to do that

		Matrix local = pWorld * Matrix::CreateScale(Scale) * Matrix::CreateFromQuaternion(Rotation) *Matrix::CreateTranslation(Translation); // then recompose
		g_Shape->Draw(local, GameRenderer::GetInstance()->m_pRenderView->m_viewMatrix, GameRenderer::GetInstance()->m_pRenderView->m_ProjectionMatrix, color, nullptr, true); //DirectX::Colors::CornflowerBlue
	}

	void drawText(wchar_t* text, Vec3 position, int r, int g, int b, int a){

		DirectX::SimpleMath::Color myColor;

		myColor.A((float)a);
		myColor.B((float)b);
		myColor.R((float)r);
		myColor.G((float)g);

		float x = position.x;
		float y = position.y;
		float z = position.z;

		//DxTk init
		if (!m_SpriteFont)
		{
			m_SpriteBatch = std::unique_ptr<DirectX::SpriteBatch>(new DirectX::SpriteBatch(DxRenderer::GetInstance()->m_pContext));
			m_SpriteFont = std::unique_ptr<DirectX::SpriteFont>(new DirectX::SpriteFont(DxRenderer::GetInstance()->m_pDevice, L"C:\\out\\lucidaconsole.spritefont"));
		}
		//DxTk endinit

		if (m_SpriteFont)
		{
			m_SpriteBatch->Begin();
			m_SpriteFont->DrawString(m_SpriteBatch.get(), text, Vector2(x, y), myColor);
			m_SpriteBatch->End();
		}
	}
}

