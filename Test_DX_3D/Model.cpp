#include "Model.h"
#include "Player.h"
#include "Stage.h"

/*�v���C���[�̃��f�����*/
LPD3DXMESH PlayerModel::Mesh;
DWORD PlayerModel::MaterialCount;
LPD3DXBUFFER PlayerModel::MaterialBuffer;
int* PlayerModel::TextureIDs;
D3DMATERIAL9 PlayerModel::Material;

/*�n�Ԃ̃��f�����*/
LPD3DXMESH HorseModel::Mesh;
DWORD HorseModel::MaterialCount;
LPD3DXBUFFER HorseModel::MaterialBuffer;
int* HorseModel::TextureIDs;
D3DMATERIAL9 HorseModel::Material;

/*�X�e�[�W�̃��f�����*/
LPD3DXMESH StageModel::Mesh;
DWORD StageModel::MaterialCount;
LPD3DXBUFFER StageModel::MaterialBuffer;
int* StageModel::TextureIDs;
D3DMATERIAL9 StageModel::Material;



void PlayerModelInit()
{
	PlayerModel::Material.Diffuse = { 255,255,255,255 };	//�}�e���A��������

	HRESULT hr = D3DXLoadMeshFromX("gradriel\\gradriel.x", D3DXMESH_MANAGED /*|D3DXMESH_32BIT*/, GetDevice(), NULL, &PlayerModel::MaterialBuffer, NULL, &PlayerModel::MaterialCount, &PlayerModel::Mesh);//Exe����̑��΃p�X�t�@�C����(10���߂��|���S�����̃��f����ǂݍ��ޏꍇ"�`32BIT"������),�f�o�C�X,null,�}�e���A���̊i�[��,NULL,�ǂݍ��ރ}�e���A���̐�,���b�V��

	if (FAILED(hr))	//���b�V���ǂݍ��ݎ��s
	{
		MessageBox(NULL, "���f���̓ǂݍ��݂Ɏ��s���܂����B", "�x��", MB_OK);
	}

	/////////////////////////////////////////////////���m
	/*���b�V���̓ǂݍ���*/

	D3DXMATERIAL* pMtx = (D3DXMATERIAL*)PlayerModel::MaterialBuffer->GetBufferPointer();	//�}�e���A����������

	PlayerModel::TextureIDs = new int[PlayerModel::MaterialCount];	//���I�Ƀ}�e���A�����������������m�ۂ���

																/*�e�}�e���A�����̎擾*/
	for (int i = 0; i < PlayerModel::MaterialCount; i++)	//�}�e���A�����������[�v������
	{
		/*�F�ʏ��*/
		pMtx[i].MatD3D.Diffuse;

		/*�e�N�X�`�����[�h*/
		if (pMtx[i].pTextureFilename == NULL)	//�e�N�X�`�����Ȃ�
		{
			/*���i�[�̏���*/

			PlayerModel::TextureIDs [i] = -1;

		}
		else//�e�N�X�`���i�[�ς�
		{
			char TexNameBuf[MAX_PATH];	//�t�@�C�����錾
			strcpy(TexNameBuf, MODEL_FILE_PATH);	//�t�@�C�����ɕ������ǉ�����
			strcat(TexNameBuf, pMtx[i].pTextureFilename);//�t�@�C�����̘A��
			PlayerModel::TextureIDs[i] = Texture_SetLoadFile(TexNameBuf, 0, 0);	//�e�N�X�`���ǂݍ���(�t�@�C�����͉��H����K�v������B)

		}
	}


}

void HorseModelInit(void)
{
	/*�n*/
	HRESULT hr = D3DXLoadMeshFromX("cart\\cart.x", D3DXMESH_MANAGED /*|D3DXMESH_32BIT*/, GetDevice(), NULL, &HorseModel::MaterialBuffer, NULL, &HorseModel::MaterialCount, &HorseModel::Mesh);//Exe����̑��΃p�X�t�@�C����(10���߂��|���S�����̃��f����ǂݍ��ޏꍇ"�`32BIT"������),�f�o�C�X,null,�}�e���A���̊i�[��,NULL,�ǂݍ��ރ}�e���A���̐�,���b�V��

	if (FAILED(hr))	//���b�V���ǂݍ��ݎ��s
	{
		MessageBox(NULL, "���f���̓ǂݍ��݂Ɏ��s���܂����B", "�x��", MB_OK);
	}

	D3DXMATERIAL* pMtx = (D3DXMATERIAL*)HorseModel::MaterialBuffer->GetBufferPointer();	//�}�e���A����������

	HorseModel::TextureIDs= new int[HorseModel::MaterialCount];	//���I�Ƀ}�e���A�����������������m�ۂ���

															/*�e�}�e���A�����̎擾*/
	for (int i = 0; i < HorseModel::MaterialCount; i++)	//�}�e���A�����������[�v������
	{
		/*�F�ʏ��*/
		pMtx[i].MatD3D.Diffuse;

		/*�e�N�X�`�����[�h*/
		if (pMtx[i].pTextureFilename == NULL)	//�e�N�X�`�����Ȃ�
		{
			/*���i�[�̏���*/

			HorseModel::TextureIDs[i] = -1;

		}
		else//�e�N�X�`���i�[�ς�
		{
			char TexNameBuf[MAX_PATH];	//�t�@�C�����錾
			strcpy(TexNameBuf, MODEL_FILE_UMA_PATH);	//�t�@�C�����ɕ������ǉ�����
			strcat(TexNameBuf, pMtx[i].pTextureFilename);//�t�@�C�����̘A��
			HorseModel::TextureIDs[i] = Texture_SetLoadFile(TexNameBuf, 0, 0);	//�e�N�X�`���ǂݍ���(�t�@�C�����͉��H����K�v������B)

		}
	}
}


void StageModelInit(void)
{
	HRESULT hr = D3DXLoadMeshFromX("Stage\\West_Block24.x", D3DXMESH_MANAGED /*|D3DXMESH_32BIT*/, GetDevice(), NULL, &StageModel::MaterialBuffer, NULL, &StageModel::MaterialCount, &StageModel::Mesh);//Exe����̑��΃p�X�t�@�C����(10���߂��|���S�����̃��f����ǂݍ��ޏꍇ"�`32BIT"������),�f�o�C�X,null,�}�e���A���̊i�[��,NULL,�ǂݍ��ރ}�e���A���̐�,���b�V��

	if (FAILED(hr))	//���b�V���ǂݍ��ݎ��s
	{
		MessageBox(NULL, "���f���̓ǂݍ��݂Ɏ��s���܂����B", "�x��", MB_OK);
	}

	D3DXMATERIAL* pMtx = (D3DXMATERIAL*)StageModel::MaterialBuffer->GetBufferPointer();	//�}�e���A����������

	StageModel::TextureIDs = new int[StageModel::MaterialCount];	//���I�Ƀ}�e���A�����������������m�ۂ���

															/*�e�}�e���A�����̎擾*/
	for (int i = 0; i < StageModel::MaterialCount; i++)	//�}�e���A�����������[�v������
	{
		/*�F�ʏ��*/
		pMtx[i].MatD3D.Diffuse;

		/*�e�N�X�`�����[�h*/
		if (pMtx[i].pTextureFilename == NULL)	//�e�N�X�`�����Ȃ�
		{
			/*���i�[�̏���*/

			StageModel::TextureIDs[i] = -1;

		}
		else//�e�N�X�`���i�[�ς�
		{
			char TexNameBuf[MAX_PATH];	//�t�@�C�����錾
			strcpy(TexNameBuf, MODEL_STAGE_PATH);	//�t�@�C�����ɕ������ǉ�����
			strcat(TexNameBuf, pMtx[i].pTextureFilename);//�t�@�C�����̘A��
			StageModel::TextureIDs[i] = Texture_SetLoadFile(TexNameBuf, 0, 0);	//�e�N�X�`���ǂݍ���(�t�@�C�����͉��H����K�v������B)

		}
	}


}
//
//void ModelInit(const char* FileName,const char* AddFileName, LPD3DXMESH* Mesh, LPD3DXBUFFER* MaterialBuffer,LPVOID MaterialBufferPointer, DWORD* MaterialCount, int* TexID)
//{
//
//	/////////////////////////////////////////////////���m
//	/*���b�V���̓ǂݍ���*/
//	HRESULT hr = D3DXLoadMeshFromX(FileName, D3DXMESH_MANAGED /*|D3DXMESH_32BIT*/, GetDevice(), NULL, MaterialBuffer, NULL, MaterialCount, Mesh);//Exe����̑��΃p�X�t�@�C����(10���߂��|���S�����̃��f����ǂݍ��ޏꍇ"�`32BIT"������),�f�o�C�X,null,�}�e���A���̊i�[��,NULL,�ǂݍ��ރ}�e���A���̐�,���b�V��
//
//	if (FAILED(hr))	//���b�V���ǂݍ��ݎ��s
//	{
//		MessageBox(NULL, "���f���̓ǂݍ��݂Ɏ��s���܂����B", "�x��", MB_OK);
//	}
//
//	D3DXMATERIAL* pMtx = (D3DXMATERIAL*)MaterialBufferPointer;	//�}�e���A����������
//
//	TexID = new int[*MaterialCount];	//���I�Ƀ}�e���A�����������������m�ۂ���
//
//										/*�e�}�e���A�����̎擾*/
//	for (int i = 0; i < *MaterialCount; i++)	//�}�e���A�����������[�v������
//	{
//		/*�F�ʏ��*/
//		pMtx[i].MatD3D.Diffuse;
//
//		/*�e�N�X�`�����[�h*/
//		if (pMtx[i].pTextureFilename == NULL)	//�e�N�X�`�����Ȃ�
//		{
//			/*���i�[�̏���*/
//
//			TexID[i] = -1;
//
//		}
//		else//�e�N�X�`���i�[�ς�
//		{
//			char TexNameBuf[MAX_PATH];	//�t�@�C�����錾
//			strcpy(TexNameBuf, AddFileName);	//�t�@�C�����ɕ������ǉ�����
//			strcat(TexNameBuf, pMtx[i].pTextureFilename);//�t�@�C�����̘A��
//			TexID[i] = Texture_SetLoadFile(TexNameBuf, 0, 0);	//�e�N�X�`���ǂݍ���(�t�@�C�����͉��H����K�v������B)
//
//		}
//	}
//
//
//
//
//
//}



void ModelUpdate()
{

}


void PlayerModelDraw(D3DXVECTOR3 Position, D3DXVECTOR3 Scaling, const D3DXVECTOR3 Rotate, bool Lighting)
{
	/*�s��ݒ�*/
	D3DXMATRIX mtxWorld, mtxScaling,mtxTranslation, mtxRotationX,mtxRotationY, mtxRotationZ;//���[���h�ϊ��s��E��]�s��E���s�ړ��s��

	D3DXMatrixIdentity(&mtxWorld);	//�s��̒P�ʉ�	(*1)
	D3DXMatrixTranslation(&mtxTranslation, Position.x, Position.y, Position.z);//���[���h���W���X�V
	D3DXMatrixScaling(&mtxScaling, Scaling.x, Scaling.x, Scaling.z);	//�g��k���s��
	D3DXMatrixRotationX(&mtxRotationX, Rotate.x);	//x����]
	D3DXMatrixRotationY(&mtxRotationY, Rotate.y);	//y����]
	D3DXMatrixRotationZ(&mtxRotationZ, Rotate.z);	//z����]
	//D3DXMatrixRotationQuaternion(&mtxRotation, );



	mtxWorld = mtxRotationX* mtxRotationY*mtxRotationZ *mtxScaling* mtxTranslation;	//�����̏��Ԃɒ���

	GetDevice()->SetTransform(D3DTS_WORLD, &mtxWorld);//�P�ʉ������s��𔽉f



													  /*���C�e�B���O�ݒ�(���̉e�����󂯂邩�ǂ���)*/
	GetDevice()->SetRenderState(D3DRS_LIGHTING, Lighting);	//Value�l��true�ɂ��邱�ƂŃ��C�e�B���O���s��



	//�V�K�}�e���A���錾�A������


	GetDevice()->SetMaterial(&PlayerModel::Material);	//�}�e���A���Z�b�g

									/*���f����ǂݍ��ލۂ͑�������D3DMCS_MATERIAL�ɂ���B(���_�J���[�����݂�����̂ɂ�D3DMCS_COLOR1�ɂ���)*/
	GetDevice()->SetRenderState(D3DRS_DIFFUSEMATERIALSOURCE, D3DMCS_MATERIAL);



	for (DWORD i = 0; i < PlayerModel::MaterialCount; i++)	//�}�e���A�����`����s��(���b�V���̓}�e���A���ŕ�������Ă��邱�Ƃ�����) 
	{
		/*�}�e���A���̐ݒ�*/

		if (PlayerModel::TextureIDs[i] < 0)//�e�N�X�`�����Ȃ����Ȃ��ꍇ-1������
		{
			/*�}�e���A���݂̂ł̐ݒ�*/

		}
		else
		{
			/*�}�e���A���J���[�𔒂ɂ��ăe�N�X�`����ݒ�*/
			GetDevice()->SetTexture(0, Texture_GetTexture(PlayerModel::TextureIDs[i]));	//�e�N�X�`����ID���w�肵�Ē���t����
		}

		/*���b�V���`��*/
		PlayerModel::Mesh->DrawSubset(i);
	}

}

void HorseModelDraw(D3DXVECTOR3 Position, D3DXVECTOR3 Scaling, const D3DXVECTOR3 Rotate, bool Lighting)
{
	/*�s��ݒ�*/
	D3DXMATRIX mtxWorld, mtxScaling, mtxTranslation, mtxRotationX, mtxRotationY, mtxRotationZ;//���[���h�ϊ��s��E��]�s��E���s�ړ��s��

	D3DXMatrixIdentity(&mtxWorld);	//�s��̒P�ʉ�	(*1)
	D3DXMatrixTranslation(&mtxTranslation, Position.x, Position.y, Position.z);//���[���h���W���X�V
	D3DXMatrixScaling(&mtxScaling, Scaling.x, Scaling.x, Scaling.z);	//�g��k���s��
	D3DXMatrixRotationX(&mtxRotationX, Rotate.x);	//x����]
	D3DXMatrixRotationY(&mtxRotationY, Rotate.y);	//y����]
	D3DXMatrixRotationZ(&mtxRotationZ, Rotate.z);	//z����]
													//D3DXMatrixRotationQuaternion(&mtxRotation, );



	mtxWorld = mtxRotationX * mtxRotationY*mtxRotationZ *mtxScaling* mtxTranslation;	//�����̏��Ԃɒ���

	GetDevice()->SetTransform(D3DTS_WORLD, &mtxWorld);//�P�ʉ������s��𔽉f



													  /*���C�e�B���O�ݒ�(���̉e�����󂯂邩�ǂ���)*/
	GetDevice()->SetRenderState(D3DRS_LIGHTING, Lighting);	//Value�l��true�ɂ��邱�ƂŃ��C�e�B���O���s��



															//�V�K�}�e���A���錾�A������


	GetDevice()->SetMaterial(&HorseModel::Material);	//�}�e���A���Z�b�g

														/*���f����ǂݍ��ލۂ͑�������D3DMCS_MATERIAL�ɂ���B(���_�J���[�����݂�����̂ɂ�D3DMCS_COLOR1�ɂ���)*/
	GetDevice()->SetRenderState(D3DRS_DIFFUSEMATERIALSOURCE, D3DMCS_MATERIAL);



	for (DWORD i = 0; i < HorseModel::MaterialCount; i++)	//�}�e���A�����`����s��(���b�V���̓}�e���A���ŕ�������Ă��邱�Ƃ�����) 
	{
		/*�}�e���A���̐ݒ�*/

		if (HorseModel::TextureIDs[i] < 0)//�e�N�X�`�����Ȃ����Ȃ��ꍇ-1������
		{
			/*�}�e���A���݂̂ł̐ݒ�*/

		}
		else
		{
			/*�}�e���A���J���[�𔒂ɂ��ăe�N�X�`����ݒ�*/
			GetDevice()->SetTexture(0, Texture_GetTexture(HorseModel::TextureIDs[i]));	//�e�N�X�`����ID���w�肵�Ē���t����
		}

		/*���b�V���`��*/
		HorseModel::Mesh->DrawSubset(i);
	}
}

void StageModelDraw(D3DXVECTOR3 Position, D3DXVECTOR3 Scaling, const D3DXVECTOR3 Rotate, bool Lighting)
{
	/*�s��ݒ�*/
	D3DXMATRIX mtxWorld, mtxScaling, mtxTranslation, mtxRotationX, mtxRotationY, mtxRotationZ;//���[���h�ϊ��s��E��]�s��E���s�ړ��s��

	D3DXMatrixIdentity(&mtxWorld);	//�s��̒P�ʉ�	(*1)
	D3DXMatrixTranslation(&mtxTranslation, Position.x, Position.y, Position.z);//���[���h���W���X�V
	D3DXMatrixScaling(&mtxScaling, Scaling.x, Scaling.x, Scaling.z);	//�g��k���s��
	D3DXMatrixRotationX(&mtxRotationX, Rotate.x);	//x����]
	D3DXMatrixRotationY(&mtxRotationY, Rotate.y);	//y����]
	D3DXMatrixRotationZ(&mtxRotationZ, Rotate.z);	//z����]
													//D3DXMatrixRotationQuaternion(&mtxRotation, );



	mtxWorld = mtxRotationX * mtxRotationY*mtxRotationZ *mtxScaling* mtxTranslation;	//�����̏��Ԃɒ���

	GetDevice()->SetTransform(D3DTS_WORLD, &mtxWorld);//�P�ʉ������s��𔽉f



													  /*���C�e�B���O�ݒ�(���̉e�����󂯂邩�ǂ���)*/
	GetDevice()->SetRenderState(D3DRS_LIGHTING, Lighting);	//Value�l��true�ɂ��邱�ƂŃ��C�e�B���O���s��



															//�V�K�}�e���A���錾�A������


	GetDevice()->SetMaterial(&StageModel::Material);	//�}�e���A���Z�b�g

														/*���f����ǂݍ��ލۂ͑�������D3DMCS_MATERIAL�ɂ���B(���_�J���[�����݂�����̂ɂ�D3DMCS_COLOR1�ɂ���)*/
	GetDevice()->SetRenderState(D3DRS_DIFFUSEMATERIALSOURCE, D3DMCS_MATERIAL);



	for (DWORD i = 0; i < StageModel::MaterialCount; i++)	//�}�e���A�����`����s��(���b�V���̓}�e���A���ŕ�������Ă��邱�Ƃ�����) 
	{
		/*�}�e���A���̐ݒ�*/

		if (StageModel::TextureIDs[i] < 0)//�e�N�X�`�����Ȃ����Ȃ��ꍇ-1������
		{
			/*�}�e���A���݂̂ł̐ݒ�*/

		}
		else
		{
			/*�}�e���A���J���[�𔒂ɂ��ăe�N�X�`����ݒ�*/
			GetDevice()->SetTexture(0, Texture_GetTexture(StageModel::TextureIDs[i]));	//�e�N�X�`����ID���w�肵�Ē���t����
		}

		/*���b�V���`��*/
		StageModel::Mesh->DrawSubset(i);
	}
}




void ModelUnInit()
{
}

