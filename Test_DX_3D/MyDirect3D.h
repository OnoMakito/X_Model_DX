#ifndef MD3D_H	//�C���N���[�h�K�[�h

#define MD3D_H


#include <d3d9.h>
#include <d3dx9.h>



bool MyDirect3D_Init(HWND hWnd);
void MyDirect3D_Uninit(void);

LPDIRECT3DDEVICE9 GetDevice(void);








#endif
