#include "Cube.h"
#include "Sprite.h"
#include "MyDirect3D.h"
#include "common.h"
#include "input.h"
#include "MyTex.h"


static const CubeVertex cv[] =
{
	{D3DXVECTOR3(-0.5f,0.5f,-0.5f),D3DXVECTOR3(0,0,-1),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0,0)},//��O���ʂP����
	{D3DXVECTOR3(0.5f,0.5f,-0.5f),D3DXVECTOR3(0,0,-1),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.25f,0) },//��O���ʂP�E��Q
	{D3DXVECTOR3(0.5f,-0.5f,-0.5f),D3DXVECTOR3(0,0,-1),D3DCOLOR_RGBA(255,255,255,255), D3DXVECTOR2(0.25f,0.25f) },//��O���ʂP�E��
	{D3DXVECTOR3(-0.5f,-0.5f,-0.5f),D3DXVECTOR3(0,0,-1),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0,0.25f) },//��O���ʂP����
	//{D3DXVECTOR3(-0.5f,0.5f,-0.5f),D3DXVECTOR3(0,0,-1),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0,0) },//��O���ʂP����Q
	//{D3DXVECTOR3(0.5f,-0.5f,-0.5f),D3DXVECTOR3(0,0,-1),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.25f,0.25f) },//��O���ʂP�E���Q

	{ D3DXVECTOR3(0.5f,0.5f,-0.5f),D3DXVECTOR3(1,0,0),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.25f,0.0f) },//�E���ʍ���
{ D3DXVECTOR3(0.5f,0.5f,0.5f),D3DXVECTOR3(1,0,0),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.5f,0.0f) },//�E����2�E��
{ D3DXVECTOR3(0.5f,-0.5f,0.5f),D3DXVECTOR3(1,0,0),D3DCOLOR_RGBA(255,255,255,255) ,D3DXVECTOR2(0.5f,0.25f) },//�E���ʉE��
{ D3DXVECTOR3(0.5f,-0.5f,-0.5f),D3DXVECTOR3(1,0,0),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.25f,0.25f) },//�E���ʍ���
//{ D3DXVECTOR3(0.5f,0.5f,-0.5f),D3DXVECTOR3(1,0,0),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.25f,0.0f) },//�E����2����
//{ D3DXVECTOR3(0.5f,-0.5f,0.5f),D3DXVECTOR3(1,0,0),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.5f,0.25f) },//�E����2�E��

{ D3DXVECTOR3(-0.5f,0.5f,0.5f),D3DXVECTOR3(-1,0,0),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.5f,0.0f) },//�����ʍ���
{ D3DXVECTOR3(-0.5f,0.5f,-0.5f),D3DXVECTOR3(-1,0,0),D3DCOLOR_RGBA(255,255,255,255) ,D3DXVECTOR2(0.75f,0.0f) },//�����ʉE��
{ D3DXVECTOR3(-0.5f,-0.5f,-0.5f),D3DXVECTOR3(-1,0,0),D3DCOLOR_RGBA(255,255,255,255) ,D3DXVECTOR2(0.75f,0.25f) },//�����ʉE��
{ D3DXVECTOR3(-0.5f,-0.5f,0.5f),D3DXVECTOR3(-1,0,0),D3DCOLOR_RGBA(255,255,255,255) ,D3DXVECTOR2(0.5f,0.25f) },//�����ʍ���
//{ D3DXVECTOR3(-0.5f,0.5f,-0.5f),D3DXVECTOR3(-1,0,0),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.75f,0.0f) },//������2�E��
//{ D3DXVECTOR3(-0.5f,-0.5f,0.5f),D3DXVECTOR3(-1,0,0),D3DCOLOR_RGBA(255,255,255,255) ,D3DXVECTOR2(0.5f,0.25f) },//������2����

{ D3DXVECTOR3(-0.5f,0.5f,0.5f),D3DXVECTOR3(0,0,1),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.75f,0.0f) },//�����ʂP����
{ D3DXVECTOR3(0.5f,0.5f,0.5f),D3DXVECTOR3(0,0,1),D3DCOLOR_RGBA(255,255,255,255) ,D3DXVECTOR2(1,0.0f) },//�����ʂP�E��Q
{ D3DXVECTOR3(0.5f,-0.5f,0.5f),D3DXVECTOR3(0,0,1),D3DCOLOR_RGBA(255,255,255,255) ,D3DXVECTOR2(1,0.25f) },//�����ʂP�E��
{ D3DXVECTOR3(-0.5f,-0.5f,0.5f),D3DXVECTOR3(0,0,1),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.75f,0.25f) },//�����ʂP����
//{ D3DXVECTOR3(-0.5f,0.5f,0.5f),D3DXVECTOR3(0,0,1),D3DCOLOR_RGBA(255,255,255,255) ,D3DXVECTOR2(0.75f,0.0f) },//�����ʂP����Q
//{ D3DXVECTOR3(0.5f,-0.5f,0.5f),D3DXVECTOR3(0,0,1),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(1,0.25f) },//�����ʂP�E���Q

{ D3DXVECTOR3(-0.5f,0.5f,0.5f),D3DXVECTOR3(0,1,0),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.0f,0.25f) },//�V�䉜����
{ D3DXVECTOR3(0.5f,0.5f,0.5f),D3DXVECTOR3(0,1,0),D3DCOLOR_RGBA(255,255,255,255) ,D3DXVECTOR2(0.25f,0.25f) },//�V�䉜�E��
{ D3DXVECTOR3(0.5f,0.5f,-0.5f),D3DXVECTOR3(0,1,0),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.25f,0.5f) },//�V���O�E��
{ D3DXVECTOR3(-0.5f,0.5f,-0.5f),D3DXVECTOR3(0,1,0),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.0f,0.5f) },//�V���O����
//{ D3DXVECTOR3(-0.5f,0.5f,0.5f),D3DXVECTOR3(0,1,0),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.0f,0.25f) },//�V�䉜����
//{ D3DXVECTOR3(0.5f,0.5f,-0.5f),D3DXVECTOR3(0,1,0),D3DCOLOR_RGBA(255,255,255,255) ,D3DXVECTOR2(0.25f,0.5f) },//�V���O�E��

{ D3DXVECTOR3(-0.5f,-0.5f,0.5f),D3DXVECTOR3(0,-1,0),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.25f,0.25f) },//�ꉜ����
{ D3DXVECTOR3(0.5f,-0.5f,0.5f),D3DXVECTOR3(0,-1,0),D3DCOLOR_RGBA(255,255,255,255) ,D3DXVECTOR2(0.5f,0.25f) },//�ꉜ�E��
{ D3DXVECTOR3(0.5f,-0.5f,-0.5f),D3DXVECTOR3(0,-1,0),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.5f,0.5f) },//���O�E��
{ D3DXVECTOR3(-0.5f,-0.5f,-0.5f),D3DXVECTOR3(0,-1,0),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.25f,0.5f) },//���O����
//{ D3DXVECTOR3(0.5f,-0.5f,-0.5f),D3DXVECTOR3(0,-1,0),D3DCOLOR_RGBA(255,255,255,255) ,D3DXVECTOR2(0.5f,0.5f) },//���O�E��
//{ D3DXVECTOR3(-0.5f,-0.5f,0.5f),D3DXVECTOR3(0,-1,0),D3DCOLOR_RGBA(255,255,255,255) ,D3DXVECTOR2(0.25f,0.5f) },//�ꉜ����


};



static const CubeVertex gv[] = {
	{D3DXVECTOR3(-10,-2.0,10),D3DXVECTOR3(0,1,0),D3DCOLOR_RGBA(100,100,0,255)},//����
	{D3DXVECTOR3(10,-2.0,-10),D3DXVECTOR3(0,1,0),D3DCOLOR_RGBA(100,100,0,255)},//�E��O
	{D3DXVECTOR3(-10,-2.0,-10),D3DXVECTOR3(0,1,0),D3DCOLOR_RGBA(100,100,0,255)},//����O

{ D3DXVECTOR3(-10,-2.0,10),D3DXVECTOR3(0,1,0),D3DCOLOR_RGBA(100,100,0,255) },//����
{ D3DXVECTOR3(10,-2.0,10),D3DXVECTOR3(0,1,0),D3DCOLOR_RGBA(100,100,0,255) },//�E��
{ D3DXVECTOR3(10,-2.0,-10),D3DXVECTOR3(0,1,0),D3DCOLOR_RGBA(100,100,0,255) },//�E��O

};

/*��]�p*/
static float angleY;
static float angleX;


/*�O�����[�v�p*/
static D3DXVECTOR3 RunPosition;
static int RunVector;//0��O�@1���@2���@3�E


/*�g��p*/
static D3DXVECTOR3 ScalingPosition;
static D3DXVECTOR3 Scaling;
static bool bScaling;

/*�ςݏd�Ȃ���*/
static int CubeCount;
static D3DXVECTOR3 FallCubePosition1;
static D3DXVECTOR3 FallCubePosition2;
static D3DXVECTOR3 FallCubePosition3;
static D3DXVECTOR3 FallCubePosition4;
static D3DXVECTOR3 FallCubePosition5;

/*��������*/
static bool Movement;
static int DiceVector;	//1:�O�i 2�F�E�ց@3�F���ց@4�F���
static D3DXVECTOR3 DicePosition;
static float DiceAngleX;
static float DiceAngleZ;


static int CubeTexture;

LPDIRECT3DINDEXBUFFER9 g_pIndexBuffer_cube = NULL;
LPDIRECT3DVERTEXBUFFER9 g_pVertexBuffer_cube = NULL;







void CubeInit()
{
	LPDIRECT3DDEVICE9 pDevice=GetDevice();
	/////////////////////////////IndexDraw�̏���
	pDevice->CreateVertexBuffer(sizeof(CubeVertex) * 24,	//�w�蒸�_���̃f�[�^��ǂݍ��ނ��Ƃ��\�ɂ���
		D3DUSAGE_WRITEONLY,	//WRITEONLY:�ǂݍ��ݕs��
		FVF_VERTEX2D,
		D3DPOOL_MANAGED,	//�f�o�C�X�j�󂪔��������ۂɃ_�C���N�gX�������I�ɕ������s��
		&g_pVertexBuffer_cube,
		NULL);

	pDevice->CreateIndexBuffer(sizeof(WORD) * 36, D3DUSAGE_WRITEONLY, D3DFMT_INDEX16, D3DPOOL_MANAGED, &g_pIndexBuffer_cube, NULL);


	WORD* pIndex;
	g_pIndexBuffer_cube->Lock(0, 0, (void**)&pIndex, D3DLOCK_DISCARD);	//VRAM�̂O�Ԗڂ���؂��EVRAM�̂��ׂĂ��擾����E���z�A�h���X(��������VRAM�͑S���Ⴄ���߁AVRAM�̃A�h���X�����z�I�ɃA�h���X���쐬����B)�E
	pIndex[0] = 0;//��O����P
	pIndex[1] =1;//��O�E��P
	pIndex[2] = 2;//��O�����P
	pIndex[3] = 0;//��O�E��Q
	pIndex[4] =2;//��O�E���Q
	pIndex[5] = 3;//��O�����Q

	pIndex[6] = 4;//�E������1
	pIndex[7] = 5;//�E���E��1
	pIndex[8] = 7;//�E������1
	pIndex[9] = 5;//�E���E��2
	pIndex[10] = 6;//�E���E��2
	pIndex[11] = 7;//�E������2
	
	pIndex[12] = 8;//��������1
	pIndex[13] = 9;//�����E��1
	pIndex[14] = 11;//��������1
	pIndex[15] = 9;//�����E��2
	pIndex[16] = 10;//�����E��2
	pIndex[17] = 11;//��������2

	pIndex[18] = 12;//��������1
	pIndex[19] = 15;//�����E��1
	pIndex[20] = 13;//��������1
	pIndex[21] = 13;//�����E��2
	pIndex[22] = 15;//�����E��2
	pIndex[23] = 14;//��������2

	pIndex[24] = 16;//�V�䍶��1
	pIndex[25] = 17;//�V��E��1
	pIndex[26] = 19;//�V�䍶��1
	pIndex[27] = 17;//�V��E��2
	pIndex[28] = 18;//�V��E��2
	pIndex[29] = 19;//�V�䍶��2

	pIndex[30] = 20;//�ꍶ��1
	pIndex[31] = 23;//��E��1
	pIndex[32] = 21;//�ꍶ��1
	pIndex[33] = 21;//��E��2
	pIndex[34] = 23;//��E��2
	pIndex[35] = 22;//�ꍶ��2

	g_pIndexBuffer_cube->Unlock();


	vertex1* pv;
	g_pVertexBuffer_cube->Lock(0, 0, (void**)&pv, D3DLOCK_DISCARD);
	memcpy(pv, cv, sizeof(cv));
	g_pVertexBuffer_cube->Unlock();








	//////////////////////////////////��������

	CubeTexture = Texture_SetLoadFile("Asset\\�Ί_.jpg", 1024, 1024);
	Texture_Load();


	/*��]*/
	angleY = 0.0f;
	angleX = 0.0f;

	/*�O�����[�v*/
	RunPosition = { 4.5f, 0.5f, -4.5f };
	RunVector = 0;

	/*�g��*/
	ScalingPosition = { 4.5f,0.5f,4.5f };
	bScaling = false;/*false�F�g��@true:�k��*/

	/*�ςݏd�Ȃ���*/
	CubeCount = 0;
	FallCubePosition1 = { -4.5f,10,4.5f };
	FallCubePosition2 = { -4.5f,10,4.5f };
	FallCubePosition3 = { -4.5f,10,4.5f };
	FallCubePosition4 = { -4.5f,10,4.5f };
	FallCubePosition5 = { -4.5f,10,4.5f };


	/*��������*/
	Movement = true;	//false:�ړ��� true:�ړ��ς�
	DicePosition.x = 0;
	DicePosition.y = 0.5f;
	DicePosition.z = 0;
	DiceAngleX = 0;
}

void CubeUpdate()
{
	/*��]������*/
	angleY += 0.01f;
	angleX += 0.01f;

	/*�O��������*/
	if (RunVector == 0)	//��O�ړ�
	{
		RunPosition.x -= 0.1;
		if (RunPosition.x <= -4.5)
		{
			RunVector = 1;
		}
	}
	else if (RunVector == 1)	//���ӈړ�
	{
		RunPosition.z += 0.1;
		if (RunPosition.z >= 4.5)
		{
			RunVector = 2;
		}
	}
	else if (RunVector == 2)	//�E��
	{
		RunPosition.x += 0.1;
		if (RunPosition.x >= 4.5)
		{
			RunVector = 3;
		}
	}
	else if (RunVector == 3)
	{
		RunPosition.z -= 0.1;
		if (RunPosition.z <= -4.5)
		{
			RunVector = 0;
		}
	}



	/*�g�傷����*/
	if (!bScaling)
	{
		Scaling.x += 0.05;
		Scaling.z += 0.05;

		if (Scaling.x >= 3 && Scaling.z >= 3)
		{
			bScaling = true;
		}
	}
	else
	{
		Scaling.x -= 0.05;
		Scaling.z -= 0.05;
		if (Scaling.x <= 1 && Scaling.z <= 1)
		{
			bScaling = false;
		}
	}


	/*�ςݏd�Ȃ���*/
	if (CubeCount == 0)
	{
		if (FallCubePosition1.y > 0.5)
		{
			FallCubePosition1.y -= 0.5f;
		}
		else
		{
			CubeCount = 1;
		}
	}
	else if (CubeCount == 1)
	{
		if (FallCubePosition2.y > 1.5)
		{
			FallCubePosition2.y -= 0.5f;
		}
		else
		{
			CubeCount = 2;
		}
	}
	else if (CubeCount == 2)
	{
		if (FallCubePosition3.y > 2.5)
		{
			FallCubePosition3.y -= 0.5f;
		}
		else
		{
			CubeCount = 3;
		}
	}
	else if (CubeCount == 3)
	{
		if (FallCubePosition4.y > 3.5)
		{
			FallCubePosition4.y -= 0.5f;
		}
		else
		{
			CubeCount = 4;
		}
	}
	else if (CubeCount == 4)
	{
		if (FallCubePosition5.y > 4.5)
		{
			FallCubePosition5.y -= 0.5f;
		}
		else
		{
			CubeCount = 0;
			FallCubePosition1 = { -4.5f,10,4.5f };
			FallCubePosition2 = { -4.5f,10,4.5f };
			FallCubePosition3 = { -4.5f,10,4.5f };
			FallCubePosition4 = { -4.5f,10,4.5f };
			FallCubePosition5 = { -4.5f,10,4.5f };
		}
	}



	/*��������*/
	//if (Keyboard_IsPress(DIK_W) && Movement)
	//{
	//	DiceVector = 1;	//�O�i
	//	Movement = false;
	//}
	//if (Keyboard_IsPress(DIK_S) && Movement)
	//{
	//	DiceVector = 4;	//���
	//	Movement = false;
	//}
	//if (Keyboard_IsPress(DIK_A) && Movement)
	//{
	//	DiceVector = 3;	//��
	//	Movement = false;
	//}
	//if (Keyboard_IsPress(DIK_D) && Movement)
	//{
	//	DiceVector = 2;	//�E
	//	Movement = false;
	//}

}

void CubeDraw(/*const D3DXMATRIX *pMatrix*/)
{
	LPDIRECT3DDEVICE9	p_Device = GetDevice();	//�f�o�C�X�擾


	/*���[���h�ϊ�*/
	D3DXMATRIX mtxWorld, mtxRotationX, mtxRotationY, mtxTranslation, mtxScaling, mtxScalingPosition, mtxScalingPosition2, mtxDiceRotation;//���[���h�ϊ��s��E��]�s��E���s�ړ��s��


	D3DXMatrixIdentity(&mtxWorld);	//�s��̒P�ʉ�	(*1)


	D3DXMatrixRotationY(&mtxRotationY, angleY);	//��]������
	D3DXMatrixRotationX(&mtxRotationX, angleX);	//��]������
	D3DXMatrixTranslation(&mtxTranslation, 0, 0.5f, 0);//���[���h���W���X�V


	mtxWorld = mtxTranslation * mtxRotationX*mtxRotationY;	//�����̏��Ԃɒ���



	p_Device->SetTransform(D3DTS_WORLD, &mtxWorld);//�P�ʉ������s��𔽉f




	ReSetSamplerState();
	p_Device->SetFVF(CUBE_FVF);
	p_Device->SetTexture(0, Texture_GetTexture(CubeTexture));	//�e�N�X�`��
	p_Device->SetRenderState(D3DRS_LIGHTING, TRUE);	//Value�l��true�ɂ��邱�ƂŃ��C�e�B���O���s��



	//p_Device->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 12, cv, sizeof(CubeVertex));	//�L���[�u�o��


	/*�O������L���[�u*/
	D3DXMatrixTranslation(&mtxTranslation, RunPosition.x, RunPosition.y, RunPosition.z);//���[���h���W���X�V
	mtxWorld = mtxTranslation;	//�����̏��Ԃɒ���
	p_Device->SetTransform(D3DTS_WORLD, &mtxWorld);//�P�ʉ������s��𔽉f
	//p_Device->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 12, cv, sizeof(CubeVertex));
	p_Device->SetStreamSource(0, g_pVertexBuffer_cube, 0, sizeof(CubeVertex));	//0�Ԃ߂̃p�C�v���C���E
	p_Device->SetIndices(g_pIndexBuffer_cube);
	p_Device->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 24, 0, 12);	//�ō����`��


	/*�����ŉ�]����L���[�u*/
	D3DXMatrixTranslation(&mtxTranslation, -4.5f, 0.5f, -4.5f);//���[���h���W���X�V
	mtxWorld = mtxRotationX * mtxTranslation;	//�����̏��Ԃɒ���
	p_Device->SetTransform(D3DTS_WORLD, &mtxWorld);//�P�ʉ������s��𔽉f
	//p_Device->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 12, cv, sizeof(CubeVertex));
	p_Device->SetStreamSource(0, g_pVertexBuffer_cube, 0, sizeof(CubeVertex));	//0�Ԃ߂̃p�C�v���C���E
	p_Device->SetIndices(g_pIndexBuffer_cube);
p_Device->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 24, 0, 12);	//�ō����`��

	/*�E���3�{�܂Ŋg��k������*/
	D3DXMatrixTranslation(&mtxScalingPosition, -0.5f, 0.5, -0.5f);//���[���h���W���X�V
	D3DXMatrixTranslation(&mtxScalingPosition2, 0.5f, -0.5, 0.5f);//���[���h���W���X�V
	D3DXMatrixScaling(&mtxScaling, Scaling.x, Scaling.x, Scaling.z);
	D3DXMatrixTranslation(&mtxTranslation, ScalingPosition.x, ScalingPosition.y, ScalingPosition.z);//���[���h���W��
	mtxWorld = mtxScalingPosition * mtxScaling*mtxScalingPosition2*mtxTranslation;	//�����̏��Ԃɒ���

	//mtxWorld *= mtxTranslation;	//�����̏��Ԃɒ���

	p_Device->SetTransform(D3DTS_WORLD, &mtxWorld);//�P�ʉ������s��𔽉f
	//p_Device->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 12, cv, sizeof(CubeVertex));
	p_Device->SetStreamSource(0, g_pVertexBuffer_cube, 0, sizeof(CubeVertex));	//0�Ԃ߂̃p�C�v���C���E
	p_Device->SetIndices(g_pIndexBuffer_cube);
p_Device->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 24, 0, 12);	//�ō����`��


	/*�ςݏd�Ȃ���*/
	D3DXMatrixTranslation(&mtxTranslation, FallCubePosition1.x, FallCubePosition1.y, FallCubePosition1.z);//���[���h���W���X�V
	mtxWorld = mtxTranslation;	//�����̏��Ԃɒ���
	p_Device->SetTransform(D3DTS_WORLD, &mtxWorld);//�P�ʉ������s��𔽉f
	//p_Device->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 12, cv, sizeof(CubeVertex));
	p_Device->SetStreamSource(0, g_pVertexBuffer_cube, 0, sizeof(CubeVertex));	//0�Ԃ߂̃p�C�v���C���E
	p_Device->SetIndices(g_pIndexBuffer_cube);
p_Device->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 24, 0, 12);	//�ō����`��

	D3DXMatrixTranslation(&mtxTranslation, FallCubePosition2.x, FallCubePosition2.y, FallCubePosition2.z);//���[���h���W���X�V
	mtxWorld = mtxTranslation;	//�����̏��Ԃɒ���
	p_Device->SetTransform(D3DTS_WORLD, &mtxWorld);//�P�ʉ������s��𔽉f
	//p_Device->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 12, cv, sizeof(CubeVertex));
	p_Device->SetStreamSource(0, g_pVertexBuffer_cube, 0, sizeof(CubeVertex));	//0�Ԃ߂̃p�C�v���C���E
	p_Device->SetIndices(g_pIndexBuffer_cube);
p_Device->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 24, 0, 12);	//�ō����`��

	D3DXMatrixTranslation(&mtxTranslation, FallCubePosition3.x, FallCubePosition3.y, FallCubePosition3.z);//���[���h���W���X�V
	mtxWorld = mtxTranslation;	//�����̏��Ԃɒ���
	p_Device->SetTransform(D3DTS_WORLD, &mtxWorld);//�P�ʉ������s��𔽉f
	//p_Device->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 12, cv, sizeof(CubeVertex));
	p_Device->SetStreamSource(0, g_pVertexBuffer_cube, 0, sizeof(CubeVertex));	//0�Ԃ߂̃p�C�v���C���E
	p_Device->SetIndices(g_pIndexBuffer_cube);
p_Device->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 24, 0, 12);	//�ō����`��

	D3DXMatrixTranslation(&mtxTranslation, FallCubePosition4.x, FallCubePosition4.y, FallCubePosition4.z);//���[���h���W���X�V
	mtxWorld = mtxTranslation;	//�����̏��Ԃɒ���
	p_Device->SetTransform(D3DTS_WORLD, &mtxWorld);//�P�ʉ������s��𔽉f
	//p_Device->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 12, cv, sizeof(CubeVertex));
	p_Device->SetStreamSource(0, g_pVertexBuffer_cube, 0, sizeof(CubeVertex));	//0�Ԃ߂̃p�C�v���C���E
	p_Device->SetIndices(g_pIndexBuffer_cube);
p_Device->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 24, 0, 12);	//�ō����`��

	D3DXMatrixTranslation(&mtxTranslation, FallCubePosition5.x, FallCubePosition5.y, FallCubePosition5.z);//���[���h���W���X�V
	mtxWorld = mtxTranslation;	//�����̏��Ԃɒ���
	p_Device->SetTransform(D3DTS_WORLD, &mtxWorld);//�P�ʉ������s��𔽉f
	//p_Device->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 12, cv, sizeof(CubeVertex));
	p_Device->SetStreamSource(0, g_pVertexBuffer_cube, 0, sizeof(CubeVertex));	//0�Ԃ߂̃p�C�v���C���E
	p_Device->SetIndices(g_pIndexBuffer_cube);
p_Device->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 24, 0, 12);	//�ō����`��





	/*��������*/
	D3DXMatrixTranslation(&mtxTranslation, -DicePosition.x, DicePosition.y, DicePosition.z);//��������̍��W

	if (DiceVector == 1 && !Movement)	//�O�i
	{
		D3DXMatrixTranslation(&mtxTranslation, DicePosition.x, DicePosition.y, DicePosition.z);//���[���h���W���X�V
		D3DXMatrixTranslation(&mtxScalingPosition, 0, 0.5, -0.5f);//���[���h���W���X�V
		D3DXMatrixTranslation(&mtxScalingPosition2, 0, -0.5, 0.5f);//���[���h���W���X�V
		D3DXMatrixRotationX(&mtxDiceRotation, D3DXToRadian(DiceAngleX));	//��]������
		DicePosition.z += 0.015f;
		DiceAngleX++;
		DicePosition.z += 0.01f;
		if (DiceAngleX >= 90)
		{
			DiceAngleX = 0;
			Movement = true;
		}
		mtxWorld = mtxScalingPosition * mtxDiceRotation*mtxScalingPosition2*mtxTranslation;	//�����̏��Ԃɒ���
		p_Device->SetTransform(D3DTS_WORLD, &mtxWorld);//�P�ʉ������s��𔽉f
		p_Device->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 12, cv, sizeof(CubeVertex));
	}
	if (DiceVector == 2 && !Movement)	//�E
	{
		D3DXMatrixTranslation(&mtxTranslation, DicePosition.x, DicePosition.y, DicePosition.z);
		D3DXMatrixTranslation(&mtxScalingPosition, -0.5f, 0.5, 0);//���[���h���W���X�V
		D3DXMatrixTranslation(&mtxScalingPosition2, -0.5f, -0.5, 0);//���[���h���W���X�V
		D3DXMatrixRotationX(&mtxDiceRotation, D3DXToRadian(DiceAngleZ));	//��]������
		DicePosition.x += 0.015f;
		DiceAngleZ++;
		if (DiceAngleZ >= 90)
		{
			DiceAngleZ = 0;
			Movement = true;
		}
		mtxWorld = mtxScalingPosition * mtxDiceRotation*mtxScalingPosition2*mtxTranslation;	//�����̏��Ԃɒ���
		p_Device->SetTransform(D3DTS_WORLD, &mtxWorld);//�P�ʉ������s��𔽉f
		p_Device->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 12, cv, sizeof(CubeVertex));
	}
	if (DiceVector == 3 && !Movement)	//��
	{
		D3DXMatrixTranslation(&mtxTranslation, DicePosition.x, DicePosition.y, DicePosition.z);
		D3DXMatrixTranslation(&mtxScalingPosition, 0.5f, 0.5, 0);//���[���h���W���X�V
		D3DXMatrixTranslation(&mtxScalingPosition2, 0.5f, -0.5, 0);//���[���h���W���X�V
		D3DXMatrixRotationX(&mtxDiceRotation, -D3DXToRadian(DiceAngleZ));	//��]������
		DicePosition.x -= 0.015f;
		DiceAngleZ++;
		if (DiceAngleZ >= 90)
		{
			DiceAngleZ = 0;
			Movement = true;
		}
		mtxWorld = mtxScalingPosition * mtxDiceRotation*mtxScalingPosition2*mtxTranslation;	//�����̏��Ԃɒ���
		p_Device->SetTransform(D3DTS_WORLD, &mtxWorld);//�P�ʉ������s��𔽉f
		p_Device->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 12, cv, sizeof(CubeVertex));
	}
	if (DiceVector == 4 && !Movement)	//���
	{
		D3DXMatrixTranslation(&mtxTranslation, DicePosition.x, DicePosition.y, DicePosition.z);
		D3DXMatrixTranslation(&mtxScalingPosition, 0, 0.5, 0.5f);//���[���h���W���X�V
		D3DXMatrixTranslation(&mtxScalingPosition2, 0, -0.5, 0.5f);//���[���h���W���X�V
		D3DXMatrixRotationX(&mtxDiceRotation, -D3DXToRadian(DiceAngleX));	//��]������
		DicePosition.z -= 0.015f;
		DiceAngleX++;
		if (DiceAngleX >= 90)
		{
			DiceAngleX = 0;
			Movement = true;
		}
		mtxWorld = mtxScalingPosition * mtxDiceRotation*mtxScalingPosition2*mtxTranslation;	//�����̏��Ԃɒ���
		p_Device->SetTransform(D3DTS_WORLD, &mtxWorld);//�P�ʉ������s��𔽉f
		//p_Device->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 12, cv, sizeof(CubeVertex));
		p_Device->SetStreamSource(0, g_pVertexBuffer_cube, 0, sizeof(CubeVertex));	//0�Ԃ߂̃p�C�v���C���E
		p_Device->SetIndices(g_pIndexBuffer_cube);
	p_Device->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 24, 0, 12);	//�ō����`��

	}
	else
	{
		mtxWorld = mtxTranslation;	//�����̏��Ԃɒ���
		p_Device->SetTransform(D3DTS_WORLD, &mtxWorld);//�P�ʉ������s��𔽉f
		//p_Device->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 12, cv, sizeof(CubeVertex));
		p_Device->SetStreamSource(0, g_pVertexBuffer_cube, 0, sizeof(CubeVertex));	//0�Ԃ߂̃p�C�v���C���E
		p_Device->SetIndices(g_pIndexBuffer_cube);
	p_Device->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 24, 0, 12);	//�ō����`��
	}








	//p_Device->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 2, gv, sizeof(CubeVertex));


}

void CubeUnInit()
{

}