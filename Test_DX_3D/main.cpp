
//Window�̕\��
#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include "common.h"
#include "MyDirect3D.h"
#include "MyTex.h"
#include "Sprite.h"
#include "debug_font.h"
#include "system_timer.h"
#include "PatternAnimation.h"
#include "input.h"
#include "Game.h"

#pragma comment(lib,"d3d9.lib")	//���C�u�����̒��ڃ����N	�v���O�}�f�B���N�e�B�u

#define CP (100*2*D3DX_PI)	//�w�i*2*��
#define RADIAN (D3DX_PI*2/CP)


/*
#if defined(DEBUG)||defined(_DEBUG)
#pragma comment(lib,"d3dx9d.lib")
#else
#pragma comment(lib,"d3dx9.lib")
#endif*/

//�萔��`
#define CLASS_NAME	"GetWindow"
#define WINDOW_CAPTION	"Window"


//�v���g�^�C�v�錾
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
bool Init();
void Update();
void Draw();
void Uninit();
//�ǉ��e�X�g�֐�
void Update(void);	//�X�V�֐�

LPDIRECT3DDEVICE9 g_pDevice=NULL;

static float move_x = 0.0f;
static float move_y = 0.0f;
static float Rowling = 0;
int kakudai = 0;
bool W = false;
bool A = false;
bool S = false;
bool D = false;

static int kaiten=0;


HWND hWnd = NULL;


static int tex[TEXTUREDATA_MAX];

static int g_FrameCount = 0;	//�t���[���J�E���^�@�P�t���[���o�ƂP�v���X�����B
static int g_FPSBaseFrameCount = 0;	//FPS�v���̊�ƂȂ�t���[���J�E���^
static double g_FPSBaseTime = 0.0f;	//FPS�v���̊�ƂȂ鎞��
static double g_StaticFrameTime = 0.0f;	//�t���[���Œ�ϐ�
float g_FPS = 0.0f;	//FPS


		RECT window_rect = { 0,0,SCREEN_WIDTH,SCREEN_HEIGHT };	//RECT�^�\���̂�錾�A������

//���C��
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	UNREFERENCED_PARAMETER(hPrevInstance);	//�g��Ȃ��ϐ��ɑ΂��Čx�����o�Ȃ��悤�ɂ���B
	UNREFERENCED_PARAMETER(lpCmdLine);

	///////////////////////////////////////////////////////////////////////////////////////////////�E�B���h�E�����Ă�
		WNDCLASS wc = {};	//�E�B���h�E�N���X�^��wc�\���̂�S�ď������B(�S��0������)

		wc.lpfnWndProc = WndProc;	//�E�B���h�E�v���V�[�W���̓o�^�F�֐��|�C���^ ( ()�����Ă��Ȃ��B )		�n�r�����b�Z�[�W�𑗂��A�n�r�������Ŏg�p����B
		wc.lpszClassName = CLASS_NAME;	//�N���X��(Window�̖��O)�̓o�^
		wc.hInstance = hInstance;	//�n���h���̐��l
		wc.hCursor = LoadCursor(NULL, IDC_ARROW);	//�J�[�\���̃f�U�C��
		wc.hbrBackground = (HBRUSH)(COLOR_BACKGROUND + 1);	//�E�B���h�E�̔w�i�F

		RegisterClass(&wc);


		int window_width = window_rect.right - window_rect.left;	//�E�B���h�E�o�[�̕��g�咲��
		int window_height = window_rect.bottom - window_rect.top;	//�E�B���h�E�o�[�̕��g�咲��
		int primary_width = GetSystemMetrics(SM_CXSCREEN);	//������ʂ̉�
		int primary_height = GetSystemMetrics(SM_CYSCREEN);	//������ʂ̍���
		int wndout_x = max((primary_width - window_width) / 2, 0);	//�E�B���h�E�̏o�͍��W��X���̐^�񒆂ɂ���
		int wndout_y = max((primary_height - window_height) / 2, 0);	//�E�B���h�E�̏o�͍��W��Y���̐^�񒆂ɂ���
		DWORD window_style = WS_OVERLAPPEDWINDOW ^ (WS_THICKFRAME | WS_MAXIMIZEBOX);	//�E�B���h�E�̌`�����w��(�����u�t�H���Y��ɏ�������)

		AdjustWindowRect(&window_rect, WS_OVERLAPPEDWINDOW ^ (WS_THICKFRAME | WS_MAXIMIZEBOX), FALSE);	//�E�B���h�E�̒���

		hWnd = CreateWindow(
			CLASS_NAME,
			WINDOW_CAPTION,
			window_style,	//�E�B���h�E�̌`��(OVERLAPEDWINDOW:���ʂ̂��.WS_POPUPWINDOW:�g�̂Ȃ��E�B���h�E�A�t���X�N���[��)
			wndout_x,		//�E�B���h�E�̏o�͏����ʒuX
			wndout_y,		//�E�B���h�E�̏o�͏����ʒuY
			window_width,		//�E�B���h�E�̕�
			window_height,		//�E�B���h�E�̍���
			NULL,
			NULL,
			hInstance,
			NULL

		);	//�n���h���l���Ԃ����B

		Keyboard_Initialize(hInstance, hWnd);	// �ł����Init�Ɉڂ�
		
		ShowWindow(hWnd, nCmdShow);	//�\���������E�B���h�E�̃n���h��������B
		
		UpdateWindow(hWnd);	//GetMessage�ŃV�X�e�����烁�b�Z�[�W���󂯎��A���b�Z�[�W���[�v(�ҋ@)���s���B���b�Z�[�W������܂Ō���̎���

		if (!Init())
		{
			return -1;
		}

	///////////////////////////////////////////////////////////////////////////////////////////////////�E�B���h�E�ݒ�I��


	MSG msg = {};	//���b�Z�[�W�i�[�ϐ��錾
		
	while (WM_QUIT != msg.message)	//�I�����b�Z�[�W�����Ȃ����胋�[�v
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);	//�L�[���͎擾
			DispatchMessage(&msg);	//���b�Z�[�W���E�B���h�E�v���V�[�W���Ɏ󂯓n��
		}
		else
		{
			double time = SystemTimer_GetTime();
			if (time - g_StaticFrameTime < 1.0 / 60.0)
			{
				Sleep(0);
			}
			else
			{
				g_StaticFrameTime = time;

				Update();
				Draw();
				
				
				//�Q�[������
			}
		}
	}
	
	Uninit();

	return (int)msg.wParam;


}



LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)	//�V�X�e��������ɌĂяo���Ă����v���V�[�W��
{
	switch (uMsg)
	{
	case WM_KEYDOWN:	//�Ȃ�炩�̃L�[�������ꂽ�ۂɑ����Ă��郁�b�Z�[�W
		if (wParam == VK_ESCAPE)
		{

			SendMessage(hWnd, WM_CLOSE, 0, 0);

		}
		break;

	case WM_CLOSE:
		if (MessageBox(hWnd, "�{���ɏI�����܂����H", "�I���m�F", MB_OKCANCEL | MB_DEFBUTTON2) == IDOK)
		{
			DestroyWindow(hWnd);	//���ł���E�B���h�E�̃n���h�����w�肷��B(�܂����ł��Ȃ�)
		}
		return 0;

	case WM_DESTROY:	//DESTROY���b�Z�[�W�𑗂��ė����ۂɃE�B���h�E�����ł�����B
		PostQuitMessage(0);
		return 0;

	};

	return DefWindowProc(hWnd, uMsg, wParam, lParam);

}

bool Init()
{
	bool hr = MyDirect3D_Init(hWnd);
	if (hr==false)
	{
		MessageBox(hWnd, "�f�o�C�X�̐ݒ�Ɏ��s���܂����B", "�G���[", MB_OK|MB_DEFBUTTON1);
		return false;
	}
	
	g_pDevice = GetDevice();
	DebugFont_Initialize();	//�f�o�b�O�t�H���g���W���[���̏�����


	Sprite_Init();





	if (Texture_Load() > 0)
	{
		MessageBox(NULL, "�e�N�X�`���G���[MAIN", "�G���[", MB_OK);
	}

	SystemTimer_Initialize();
	SystemTimer_Start();


	 g_FrameCount = g_FPSBaseFrameCount = 0;	//�S��0�ɂł���B
	 g_FPS = 0.0f;

	 g_StaticFrameTime = g_FPSBaseTime = SystemTimer_GetTime();	//�S�ĂɌ��݂̎���������B

	PatternAnimation_Init();

	GameInit();


	return true;
}

void Draw()
{
	g_pDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_RGBA(100, 100, 255, 1), 1.0f, 0);//0,NULL:�S����	target~zbuffer:���s������(��)	color_rgba:��������F	1.0f:���s���(0�`1.0)	0:

	g_pDevice->BeginScene();	//�V�[���J�n




	DebugFont_Draw(100, 500, "fps:%f", g_FPS);



	GameDraw();


	g_pDevice->EndScene();		//�V�[���I��
	g_pDevice->Present(NULL, NULL, NULL, NULL);	//�`�揈��(���ӁF�d���Ȃ邽��present�͕K��������B)

}


void Update()
{		

	/*/�@FPS�v���͍Ō�ɍs���@/*/

	g_FrameCount++;	//�t���[���J�E���g�A�b�v

					//���݂̃V�X�e�����Ԃ̎擾
	double time = SystemTimer_GetTime();

	//���݂�FPS�v�����Ԃ���K�莞�Ԃ����Ă�����FPS�v��	�@���̎��Ԃ���O�̎��Ԃ������ƌo�ߎ��Ԃ��o��B
	if (time - g_FPSBaseTime >= FPS_MEASUREMENT_TIME)
	{
		g_FPS = (float)((g_FrameCount - g_FPSBaseFrameCount) / (time - g_FPSBaseTime));
	
		//FPS�v���̊�ɂȂ�l
		g_FPSBaseFrameCount = g_FrameCount;
		g_FPSBaseTime = time;
	}
	

	Keyboard_Update();	//�P�t���[���Ɉ��L�[�{�[�h�̏�Ԃ𒲂ׂ�

	GameUpdate();




}



void Uninit()
{
	MyDirect3D_Uninit();
	DebugFont_Finalize();
	Keyboard_Finalize();



}



