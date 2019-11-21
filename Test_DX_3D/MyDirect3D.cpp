
#include <d3d9.h>
#include <d3dx9.h>
#include "MyDirect3D.h"
#include "common.h"
#include "MyTex.h"
#include "Sprite.h"
#include "system_timer.h"
#include "debug_font.h"

#define CP (100*2*D3DX_PI)	//�w�i*2*��
#define RADIAN (D3DX_PI*2/CP)


static LPDIRECT3D9 g_pD3D = NULL;
static LPDIRECT3DDEVICE9 g_pDevice = NULL;

D3DPRESENT_PARAMETERS d3dpp = {};


bool MyDirect3D_Init(HWND hWnd)
{

	g_pD3D = Direct3DCreate9(D3D_SDK_VERSION);

	if (g_pD3D == NULL)
	{
		MessageBox(NULL, "�f�o�C�X�̎擾�Ɏ��s���܂����B", "�x��", MB_OK);
		return false;
	}

	d3dpp.BackBufferWidth = SCREEN_WIDTH;			//��ʃT�C�Y
	d3dpp.BackBufferHeight = SCREEN_HEIGHT;		//��ʃT�C�Y
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;	//�E�B���h�E�T�C�Y���w��(���m��)
	d3dpp.BackBufferCount = 1;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.Windowed = true;	//�E�B���h�E�Ȃ�true�@�t���X�N���[���Ȃ�false
	d3dpp.EnableAutoDepthStencil = TRUE;	//�[�x�o�b�t�@�E�X�e���V���o�b�t�@��L���ɂ���B(Z�o�b�t�@�F�|���S���̑O��𔻒f����B)
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
	d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;	//IMMEDIATE:��Ɏg�������c�H(����������ҋ@�����ɉ�ʂ��X�V����B�R���s���[�^�̏����ɍ��킹�čX�V���邽��60���ȏ�ɂȂ�B)


	HRESULT hr = g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3dpp, &g_pDevice);
																																		  //HRESULT hr3 = g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3dpp, &g_pDevice);//�ǂ̃��j�^�[���g�����A�ǂ̃A�_�v�^���g�����B	//HAL:HardwareAcceLeration
																													  //FAILED�}�N������HRESULT�^�̕ϐ������邱�ƂŁA�E�B���h�E�X�V�Ɏ��s���Ă����ꍇ�̏������ł���悤�ɂȂ�B
	if (FAILED(hr))
	{
		MessageBox(NULL,"�f�o�C�X�G���[���������܂����B", "�G���[", MB_OK);
		return false;
	}

	return true;	//�Ō�ɏ���
}


void MyDirect3D_Uninit(void)
{
	if (g_pDevice != NULL)	//�f�o�C�X�̕ԋp
	{
		g_pDevice->Release();	//g_pD3D�̃A�h���X�����ׂĉ��
		g_pDevice = NULL;	//g_pD3D�A�h���X������B
	}

	if (g_pD3D != NULL)	//�C���^�[�t�F�[�X�̕ԋp
	{
		g_pD3D->Release();	//g_pD3D�̃A�h���X�����ׂĉ��
		g_pD3D = NULL;	//g_pD3D�A�h���X�����
	}
}




	



LPDIRECT3DDEVICE9 GetDevice()
{

	return g_pDevice;

}
