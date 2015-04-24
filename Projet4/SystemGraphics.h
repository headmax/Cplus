/********************************* *Class: D3D11API *Description: *Author: jkeon **********************************/ 
#ifndef _SYSTEMGRAPHICS_H_ #define _SYSTEMGRAPHICS_H_ 
////////////////////////////////////////////////////////////////////// 
// LINKING /////////////////////////////////////////////////////////// 
////////////////////////////////////////////////////////////////////// 
#pragma comment(lib, "dxgi.lib") 
#pragma comment(lib, "d3d11.lib") 
////////////////////////////////////////////////////////////////////// 
// INCLUDES ////////////////////////////////////////////////////////// 
////////////////////////////////////////////////////////////////////// 
#include "util/DebugUtil.h"
#include "util/Macros.h"
#include "SystemWindow.h"
#include <DXGI.h>
#include <D3D11.h>
#include <vector>


////////////////////////////////////////////////////////////////////// 
// NAMESPACE ///////////////////////////////////////////////////////// 
////////////////////////////////////////////////////////////////////// 
namespace Athena
{
	////////////////////////////////////////////////////////////////////// 
	// GLOBALS /////////////////////////////////////////////////////////// 
	////////////////////////////////////////////////////////////////////// 
	////////////////////////////////////////////////////////////////////// 
	
	// CLASS DECLARATION ///////////////////////////////////////////////// 
	////////////////////////////////////////////////////////////////////// 
	class SystemGraphics
	{
		//TYPEDEFS
		typedef std::vector< IDXGIAdapter1*> IDXGIAdapterVector; 
		typedef std::vector< IDXGIOutput*> IDXGIOutputVector;


		//PUBLIC FUNCTIONS public: SystemGraphics();


		virtual ~SystemGraphics();


		bool Init(SystemWindow *window, int adapterIndex, int outputIndex, int numBackBuffers, bool vsync);


		void Destroy();


		void Begin();


		void End();


		bool ToggleFullScreen(bool fullScreen);


		void GetDXGIAdapters(IDXGIAdapterVector & adapterVector);


		void SetDXGIAdapter(UINT adapterIndex, IDXGIAdapter1 *adapter);


		void GetDXGIOutputs(IDXGIOutputVector & outputVector);


		void SetDXGIOutput(UINT outputIndex, IDXGIOutput *output);


		DXGI_MODE_DESC* GetDisplayModes();


		void SetDisplayMode(DXGI_MODE_DESC *displayMode);


		DXGI_ADAPTER_DESC1* GetAdapterDesc();


		//PUBLIC VARIABLES public: //PROTECTED FUNCTIONS protected: //PROTECTED VARIABLES protected: //PRIVATE FUNCTIONS private: SystemGraphics(const SystemGraphics& other);


		SystemGraphics& operator = (const SystemGraphics& other);


		bool InitDXGIFactory();


		bool InitDXGIAdapter();


		bool InitDXGIOutput();


		bool InitDisplayModes();


		bool InitSwapChainDesc();


		bool InitDeviceAndSwapChain();


		bool InitBackBuffer();


		bool InitViewport();


		void OnWindowResize(WPARAM wparam, LPARAM lparam);


		//PRIVATE VARIABLES private: HRESULT hr;


		bool m_fullScreen;


		bool m_vsync;


		SystemWindow* p_window;


		int m_numBackBuffers;


		int m_msaaLevel;


		int m_msaaQuality;


		UINT m_adapterIndex;


		UINT m_outputIndex;


		IDXGIFactory1* p_factory;


		IDXGIAdapter1* p_adapter;


		IDXGIOutput* p_output;


		DXGI_FORMAT m_desiredFormat;
		DXGI_MODE_DESC* p_displayModes;


		DXGI_MODE_DESC m_displayMode;


		DXGI_ADAPTER_DESC1 m_adapterDesc;


		DXGI_SWAP_CHAIN_DESC m_swapChainDesc;


		IDXGISwapChain* p_swapChain;


		ID3D11Device* p_device;


		ID3D11DeviceContext* p_deviceContext;


		ID3D11Texture2D* p_backbuffer;


		ID3D11RenderTargetView* p_backbufferRenderTarget;


		D3D11_VIEWPORT m_viewport;


		D3D_FEATURE_LEVEL m_targetFeatureLevel;


		D3D_FEATURE_LEVEL m_highestFeatureLevel;



	}

	;


	////////////////////////////////////////////////////////////////////// // STATICS /////////////////////////////////////////////////////////// //////////////////////////////////////////////////////////////////////
}

#endif