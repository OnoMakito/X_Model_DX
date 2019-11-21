#pragma once
#include "common.h"

#define MODEL_STAGE_PATH ("Stage\\")

class Stage
{
public:

	D3DXVECTOR3 Position;	//ÉèÅ[ÉãÉhç¿ïWäiî[ïœêî
	D3DXVECTOR3 Rotate;	//âÒì]
	D3DXVECTOR3 Scale;	//ägèk

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
