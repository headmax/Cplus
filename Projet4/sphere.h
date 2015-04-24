class sphere{
	Matrix mTransform;
	float scale;
	DirectX::SimpleMath::Color myColor;
public:
	sphere(Matrix mTransform, int r, int g, int b, int a, float scale){

		this->mTransform = mTransform;
		this->scale = scale;
		
		this->myColor.A((float)a);
		this->myColor.B((float)b);
		this->myColor.R((float)r);
		this->myColor.G((float)g);
	}

	void drawwiresphere()
	{
		g_Shape = DirectX::GeometricPrimitive::CreateSphere(DxRenderer::GetInstance()->m_pContext, this->scale);
		Matrix pWorld = pWorld.Identity();
		Vector3 Scale, Translation;
		Quaternion Rotation;
		this->mTransform.Decompose(Scale, Rotation, Translation);

		Matrix local = pWorld * Matrix::CreateScale(Scale) * Matrix::CreateFromQuaternion(Rotation) *Matrix::CreateTranslation(Translation);
		g_Shape->Draw(local, GameRenderer::GetInstance()->m_pRenderView->m_viewMatrix, GameRenderer::GetInstance()->m_pRenderView->m_ProjectionMatrix, this->myColor, nullptr, true); //DirectX::Colors::CornflowerBlue
	}

	void DrawText3D(){
	/*	Vector3 textPosition = Vector3(0, 45, 0);

		basicEffect.World = Matrix.CreateScale(1, -1, 1) * Matrix.CreateTranslation(textPosition);
		basicEffect.View = view;
		basicEffect.Projection = projection;

		const string message = "hello, world!";
		Vector2 textOrigin = spriteFont.MeasureString(message) / 2;
		const float textSize = 0.25f;

		spriteBatch.Begin(0, null, null, DepthStencilState.DepthRead, RasterizerState.CullNone, basicEffect);
		spriteBatch.DrawString(spriteFont, message, Vector2.Zero, Color.White, 0, textOrigin, textSize, 0, 0);
		spriteBatch.End();*/
	}
};

class sphere;