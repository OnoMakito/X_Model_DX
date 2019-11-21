#pragma once

#ifndef SPRITE_H

#define SPRITE_H






#define FVF_VERTEX2D (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)	//XYZ��RHW�������_�f�[�^��\���B	RHW:���_���W�ύX�������������

typedef struct vertex2d_tag		//�^�O�����邱�Ƃ��ł���B(�C��)
{
	D3DXVECTOR4 position;	//���_���W
	D3DCOLOR color;			//�F���
	D3DXVECTOR2 uv;			//�摜��UV���W


}vertex1;



void Sprite_Init();


void Sprite_Draw(int Texture_id, float dx, float dy, int cut_x, int cut_y, int cut_w, int cut_h, float angle, float cx, float cy, float zoom);	//�g��A�k���B


//id:�e�N�X�`����Id�@ d:��ʍ��W �@cut:�؂���UV���W�@c:��]�̒��S���W


void Sprite_Uninit();




void Sprite_Draw_Mirror(int Texture_id, float dx, float dy, int cut_x, int cut_y, int cut_w, int cut_h);	//���]������B

void ReSetSamplerState();	//�T���v���[�X�e�[�g�ݒ�

#endif
