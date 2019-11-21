#include "common.h"
#include "Player.h"
#include "Model.h"

Gradriel Player(D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(1, 1, 1));
Cart Horse(D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(1, 1, 1));

void Player_Init()	//�������W�E�e�N�X�`���̏���
{
	
	PlayerModelInit();
	HorseModelInit();
//ModelInit("gradriel\\gradriel.x", MODEL_FILE_PATH, &Player.g_pMesh, &Player.g_pMaterialsBuffer,Player.g_pMaterialsBuffer->GetBufferPointer(), &Player.g_MaterialsCount, Player.g_pTextureIDs);

	





	
}

void Player_Update()	//�L�[���͂ňړ��E
{

}


void Player_Draw()	//�v���C���[�`��
{
	PlayerModelDraw(Player.Position, Player.Scale, Player.Rotate, true);
	
	/*��]���������*/
	PlayerModelDraw(Player.Position+D3DXVECTOR3(0.0f,0.0f,1.0f), Player.Scale, Player.Rotate+D3DXVECTOR3(0,180,0), true);

	HorseModelDraw(Horse.Position, Horse.Scale, Horse.Rotate, true);





}


void Player_Uninit()	//�e�N�X�`�����(�V�[���I�����ɊJ������Ȃ�A�����ɏ����K�v�͂Ȃ��B)
{

}

