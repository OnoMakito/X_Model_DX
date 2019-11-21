#pragma once

#ifndef CUBE_H
#define CUBE_H

#include <d3d9.h>
#include <d3dx9.h>
#include "MyTex.h"
#include "Sprite.h"

typedef struct CubeVertex_tag
{
	D3DXVECTOR3 position;
	D3DXVECTOR3 normal;	//�@��(DirectX�̓s����Aposition,normal,color�̏��ɒ�`����)	�@���͒P�ʃx�N�g���œ����(XYZ�ǂꂩ���1��-1�A����ȊO��0)
	D3DCOLOR color;
	D3DXVECTOR2 uv;
}CubeVertex;


#define CUBE_FVF (D3DFVF_XYZ|D3DFVF_DIFFUSE|D3DFVF_NORMAL|D3DFVF_TEX1)


void CubeInit(void);

void CubeUpdate(void);

void CubeDraw(/*const D3DXMATRIX *pMatrix*/);
/*�s��͊O��������������Y��ɏ����邩��*/

void CubeUnInit(void);

#endif