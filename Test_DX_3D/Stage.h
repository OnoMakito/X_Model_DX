#pragma once
#include "common.h"

#define MODEL_STAGE_PATH ("Stage\\")

class Stage
{
public:

	D3DXVECTOR3 Position;	//���[���h���W�i�[�ϐ�
	D3DXVECTOR3 Rotate;	//��]
	D3DXVECTOR3 Scale;	//�g�k

	Stage(D3DXVECTOR3 position, D3DXVECTOR3 rotate, D3DXVECTOR3 scale)
	{
		Position = position;
		Rotate = rotate;
		Scale = scale;

	}
};




void StageInit(void);
void StageUpdate(void);
void StageDraw(void);
void StageUnInit(void);
