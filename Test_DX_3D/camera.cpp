


#include "MyDirect3D.h"
#include "camera.h"
#include "Cube.h"
#include <d3d9.h>
#include <d3dx9.h>
#include "input.h"


/*�f�o�b�O�p�J����*//////////////////////////////////////////////////////
static D3DXVECTOR3 g_VecFront;	//�O�����x�N�g��
static D3DXVECTOR3 g_VecRight;	//�E�����x�N�g��
static D3DXVECTOR3 g_VecUp(0.0f, 0.0f, 0.0f);	//������x�N�g��

static float g_MoveSpeed=0.0f;	//�ړ����x
static float g_RotationSpeed=0.0f;	//�ړ����x
static D3DXVECTOR3 g_Position(0.0f,1.0f,-8.0f);	//���W

static float g_Fov = 0.0f;	//��p
/////////////////////////////////////////////////////////////////////////



void CameraInit()
{
	/*�O�x�N�g���Ə�x�N�g���������ɂȂ�悤�ɂ���*/
	g_VecFront = D3DXVECTOR3(0.0f, 0.0f, 1.0f);	//�O����
	g_VecRight = D3DXVECTOR3(1.0f, 0.0f, 0.0f);	//�E����

	D3DXVec3Normalize(&g_VecFront, &g_VecFront);	//�P�ʉ�����
	D3DXVec3Cross(&g_VecUp, &g_VecFront, &g_VecRight);	//�O�ς��g���đO�����x�N�g���ƉE�����x�N�g���̗����ɑ΂��Đ����ȃx�N�g�������߂�(�����)...�������Ƒ�O�����̏��ԂɋC��t����(�~�X��ƃ}�C�i�X�̒l�ɂȂ�) 
	D3DXVec3Normalize(&g_VecUp, &g_VecUp);	//�P�ʉ�
	
	g_MoveSpeed = 0.08f;	//�X�s�[�h

	g_RotationSpeed = 0.01f;	//��]���x
	g_Fov = 1.0f;	//��p(1���W�A����60�x)

}


void CameraUpdate()
{

	/*�ړ�*/
	D3DXVECTOR3 vecDir(0.0f,0.0f,0.0f);
	if (Keyboard_IsPress(DIK_LSHIFT) || Keyboard_IsPress(DIK_RSHIFT))
	{
		if (Keyboard_IsPress(DIK_W))
		{
			vecDir+=g_VecUp;	//�㏸
		}

		if (Keyboard_IsPress(DIK_S))
		{
			vecDir-=g_VecUp;	//���~
		}
	}
	else
	{
		if (Keyboard_IsPress(DIK_W))
		{
			vecDir += g_VecFront;

		}
		if (Keyboard_IsPress(DIK_A))
		{
			vecDir -= g_VecRight;

		}
		if (Keyboard_IsPress(DIK_D))
		{
			vecDir += g_VecRight;

		}
		if (Keyboard_IsPress(DIK_S))
		{
			vecDir -= g_VecFront;

		}
	}
	D3DXVec3Normalize(&vecDir, &vecDir);	//�P�ʉ�(�����������Ă��ςɉ������Ȃ��悤�ɂ���)
	g_Position += g_MoveSpeed * vecDir;	//���W��ύX






	/*��]*/

	D3DXMATRIX mtxRotation;
	D3DXVECTOR3 At_Point = g_Position + g_VecFront*5;	//�����_


	
	 if (Keyboard_IsPress(DIK_LCONTROL) || Keyboard_IsPress(DIK_RCONTROL))	//���S�_�����Ƃ�����](������)
	{
		if (Keyboard_IsPress(DIK_RIGHTARROW))	//�E��]
		{
			D3DXMatrixRotationY(&mtxRotation, g_RotationSpeed);
			D3DXVec3TransformNormal(&g_VecFront, &g_VecFront, &mtxRotation);	//W�̒l��0�ɂ���˕��s�ړ��̉e�����󂯂Ȃ�
			D3DXVec3TransformNormal(&g_VecRight, &g_VecRight, &mtxRotation);
			D3DXVec3TransformNormal(&g_VecUp, &g_VecUp, &mtxRotation);

			g_Position=At_Point - g_VecFront * 5;	//��]��Ɏ������ړ�������W�����߂�(�����_�����߂鎮���t�Z����)

			//D3DXVec3TransformCoord()	//W�̒l��1�ɂ���˕��s�ړ��̉e�����󂯂�(����͉�]�������邽�߂��������g���Ă����ʓI�ɂ͕ς��Ȃ��B)
		}
		if (Keyboard_IsPress(DIK_LEFTARROW))	//����]
		{
			D3DXMatrixRotationY(&mtxRotation, -g_RotationSpeed);
			D3DXVec3TransformNormal(&g_VecFront, &g_VecFront, &mtxRotation);	//W�̒l��0�ɂ���˕��s�ړ��̉e�����󂯂Ȃ�
			D3DXVec3TransformNormal(&g_VecRight, &g_VecRight, &mtxRotation);
			D3DXVec3TransformNormal(&g_VecUp, &g_VecUp, &mtxRotation);
			
			g_Position = At_Point - g_VecFront * 5;//��]��Ɏ������ړ�������W�����߂�(�����_�����߂鎮���t�Z����)

			//D3DXVec3TransformCoord()	//W�̒l��1�ɂ���˕��s�ړ��̉e�����󂯂�(����͉�]�������邽�߂��������g���Ă����ʓI�ɂ͕ς��Ȃ��B)
		}
	}
	else//���W����]
	{
		if (Keyboard_IsPress(DIK_RIGHTARROW))	//�E��]
		{
			D3DXMatrixRotationY(&mtxRotation, g_RotationSpeed);
			D3DXVec3TransformNormal(&g_VecFront, &g_VecFront, &mtxRotation);	//W�̒l��0�ɂ���˕��s�ړ��̉e�����󂯂Ȃ�
			D3DXVec3TransformNormal(&g_VecRight, &g_VecRight, &mtxRotation);
			D3DXVec3TransformNormal(&g_VecUp, &g_VecUp, &mtxRotation);

		}
		if (Keyboard_IsPress(DIK_LEFTARROW))	//����]
		{

			D3DXMatrixRotationY(&mtxRotation, -g_RotationSpeed);
			D3DXVec3TransformNormal(&g_VecFront, &g_VecFront, &mtxRotation);	//W�̒l��0�ɂ���˕��s�ړ��̉e�����󂯂Ȃ�
			D3DXVec3TransformNormal(&g_VecRight, &g_VecRight, &mtxRotation);
			D3DXVec3TransformNormal(&g_VecUp, &g_VecUp, &mtxRotation);

		}
		if (Keyboard_IsPress(DIK_UPARROW))	//���]
		{
			D3DXMatrixRotationAxis(&mtxRotation, &g_VecRight, -g_RotationSpeed);	//VecUp�����ɉE��]
			D3DXVec3TransformNormal(&g_VecFront, &g_VecFront, &mtxRotation);	//W�̒l��0�ɂ���˕��s�ړ��̉e�����󂯂Ȃ�
			D3DXVec3TransformNormal(&g_VecUp, &g_VecUp, &mtxRotation);

		}
		if (Keyboard_IsPress(DIK_DOWNARROW))	//����]
		{
			D3DXMatrixRotationAxis(&mtxRotation, &g_VecRight, g_RotationSpeed);	//VecUp�����ɉE��]
			D3DXVec3TransformNormal(&g_VecFront, &g_VecFront, &mtxRotation);	//W�̒l��0�ɂ���˕��s�ړ��̉e�����󂯂Ȃ�
			D3DXVec3TransformNormal(&g_VecUp, &g_VecUp, &mtxRotation);

		}
	}

	

	if (Keyboard_IsPress(DIK_R) && Keyboard_IsPress(DIK_LSHIFT) && Keyboard_IsPress(DIK_LCONTROL))	//���Z�b�g
	{
		g_Position=D3DXVECTOR3(0.0f, 1.0f, -8.0f);	//���W
		g_VecFront = D3DXVECTOR3(0.0f, 0.0f, 1.0f);	//�O����
		g_VecRight = D3DXVECTOR3(1.0f, 0.0f, 0.0f);	//�E����

		D3DXVec3Normalize(&g_VecFront, &g_VecFront);	//�P�ʉ�����
		D3DXVec3Cross(&g_VecUp, &g_VecFront, &g_VecRight);	//�O�ς��g���đO�����x�N�g���ƉE�����x�N�g���̗����ɑ΂��Đ����ȃx�N�g�������߂�(�����)...�������Ƒ�O�����̏��ԂɋC��t����(�~�X��ƃ}�C�i�X�̒l�ɂȂ�) 
		D3DXVec3Normalize(&g_VecUp, &g_VecUp);	//�P�ʉ�
	}


	D3DXVec3Normalize(&g_VecFront, &g_VecFront);	//�덷�̔������Ȃ������߂ɒP�ʉ�
	D3DXVec3Normalize(&g_VecRight, &g_VecRight);
	D3DXVec3Normalize(&g_VecUp, &g_VecUp);


}


void CameraDraw()
{

	/*�r���[�ϊ��s��*/
	D3DXMATRIX mtxView;
	D3DXVECTOR3 camera_eye=g_Position;	//�J�����̍��W
	D3DXVECTOR3 camera_at=g_Position+g_VecFront;	//�J���������Ă����(�����_)
	D3DXVECTOR3 camera_up=g_VecUp;	//�J�����̏�����x�N�g����ݒ�

	D3DXMatrixLookAtLH(&mtxView, &camera_eye, &camera_at, &camera_up);	//�J�����Ɉڂ�悤�ɐ��E�𓮂����s��

	GetDevice()->SetTransform(D3DTS_VIEW, &mtxView);	//�r���[�ϊ��s��𔽉f


													/*�v���W�F�N�V�����ϊ�(�p�[�X�y�N�e�B��)*/
	D3DXMATRIX mtxProjection;
	D3DXMatrixPerspectiveFovLH(&mtxProjection, D3DXToRadian(30),//��p�̔���
		(float)SCREEN_WIDTH / SCREEN_HEIGHT,//�A�X�� �����ɂȂ邽��Float�ŃL���X�g����
		0.1f,	//near	//0�����傫��
		1000.0f//far
	);


	GetDevice()->SetTransform(D3DTS_PROJECTION, &mtxProjection);//�p�[�X�y�N�e�B�u�ϊ��s��𔽉f

}
void CameraUnInit()
{

}


