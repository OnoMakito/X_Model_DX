#pragma once


#define MODEL_FILE_PATH ("gradriel\\")

#define MODEL_FILE_UMA_PATH ("cart\\")


void Player_Init(void);	//�������W�E�e�N�X�`���̏���

void Player_Update(void);	//�L�[���͂ňړ��E

void Player_Draw(void);	//�v���C���[�̏�Ԃ��Ď����ĕ`��(�����E���S�E�����Ȃ�)

void Player_Uninit(void);	//�e�N�X�`�����(�V�[���I�����ɊJ������Ȃ�A�����ɏ����K�v�͂Ȃ��B)



class Gradriel
{
public:

	D3DXVECTOR3 Position;	//���[���h���W�i�[�ϐ�
	D3DXVECTOR3 Rotate;	//��]
	D3DXVECTOR3 Scale;

	Gradriel(D3DXVECTOR3 position, D3DXVECTOR3 rotate,D3DXVECTOR3 scale)
	{
		Position = position;
		Rotate = rotate;
		Scale = scale;
	}

};




class Cart
{
public:
	LPD3DXMESH g_pMesh = NULL;
	DWORD g_MaterialsCount = 0;	//�}�e���A���i���o�[(�}�e���A���i�[�ԍ�)
	LPD3DXBUFFER g_pMaterialsBuffer = NULL;	//�}�e���A�����̊i�[��(MaterialCount�̐��̃}�e���A���������Ă�)

	int* g_pTextureIDs = NULL;	//�e�N�X�`���Ǘ��ԍ��i�[�ϐ�

	D3DMATERIAL9 mat = {};

	D3DXVECTOR3 Position;	//���[���h���W�i�[�ϐ�
	D3DXVECTOR3 Rotate;	//��]
	D3DXVECTOR3 Scale;

	Cart(D3DXVECTOR3 position, D3DXVECTOR3 rotate, D3DXVECTOR3 scale)
	{
		Position = position;
		Rotate = rotate;
		Scale = scale;

		/*�f�B�t���[�Y�l*/
		mat.Diffuse.r = 255;
		mat.Diffuse.g = 255;
		mat.Diffuse.b = 255;
		mat.Diffuse.a = 255;
		/*�A���r�G���g�l*/
		mat.Ambient.r = 255;
		mat.Ambient.g = 255;
		mat.Ambient.b = 255;
		mat.Ambient.a = 255;

	}

};




