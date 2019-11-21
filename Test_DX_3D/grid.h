#pragma once

#ifndef GRID_H
#define GRID_H

#include <d3d9.h>
#include <d3dx9.h>

typedef struct GridVertex_tag
{
	D3DXVECTOR3 position;
	D3DCOLOR color;
}GridVertex;
/*
44���_��LINELIST�ŕ`��
1�}�X1*1
10*10�}�X
������x,y,z=0.0.0�ɍ��킹��

DrawPrimitiveUp���ŕ`��

���[���h�ϊ��s��͒P�ʍs��

�r���[�s��Ɖ��H�����������s��͍���L���[�u��O���b�h�Ȃǂŋ��ʂɂȂ邩��Camera.h���쐬����E


*/



void GridInit(void);

void GridUpdate(void);

void GridDraw(void);




#endif