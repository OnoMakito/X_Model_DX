#include "common.h"
#include "MyDirect3D.h"
#include "Light.h"



static D3DLIGHT9 Light = {};//������



void LightInit()
{
	LPDIRECT3DDEVICE9 p_Device;
	p_Device = GetDevice();


	Light.Type = D3DLIGHT_DIRECTIONAL;

	D3DXVECTOR3 vecDirLight(-1.0f, -1.0f, 1.0f);	//�P�ʃx�N�g���ɂ���(���̕���)


//D3DXVec3Normalize(&vecDirLight,&vecDirLight);//���K�����s�� (�o��,����)
//Light.Direction = vecDirLight;
	D3DXVec3Normalize((D3DXVECTOR3*)&Light.Direction, &vecDirLight);//��Q�s����s�ɏW��


	/*���C�g�J���[*/
	Light.Diffuse.r = 1.0f;
	Light.Diffuse.g = 1.0f;
	Light.Diffuse.b = 1.0f;
	Light.Diffuse.a = 0.0f;//a�͖��������?


	p_Device->SetLight(0, &Light);	//���C�g�̃X���b�g�ԍ�,���C�g�̐ݒ���	(���𓮓I�ɑ��삷��ꍇ���t���[���Z�b�g����K�v������)

	p_Device->LightEnable(0, TRUE);	//���C�g�̃X���b�g�ԍ�,���C�g��ON/OFF

	p_Device->SetRenderState(D3DRS_NORMALIZENORMALS, TRUE);	//�����I�ɐ��K������̂��ǂ���
	
	/*�A���r�G���g�̐ݒ�*/
	p_Device->SetRenderState(D3DRS_AMBIENT, D3DCOLOR_XRGB(150, 150, 100));	//�A���r�G���g�J���[
	p_Device->SetRenderState(D3DRS_AMBIENTMATERIALSOURCE, D3DMCS_COLOR1);	
	
	//�F���A���r�G���g�}�e���A��*�A���r�G���g���C�g+�f�B���N�V���i�����C�g*�f�B�q���[�Y�}�e���A��
	//���̐F�ʂ͂��̂悤�ɐݒ肳���B(���𓖂Ă�����Ɣ��ɋ߂Â��Ă��܂����ߒ���)
	/*�J�����Ƃ͐^�t�̕����Ɍ��𓖂Ă邱�ƂŃI�u�W�F�N�g�ɗ֊s����������*/



	p_Device->SetRenderState(D3DRS_DIFFUSEMATERIALSOURCE, D3DMCS_COLOR1);//(DIFFUSEMATERIAL)�}�e���A���͒��_�J���[�Ŏw�肷��
}


void LightUpdate()
{

}


void LightDraw()
{

}

void LightUnInit()
{

}