#define _CRT_SECURE_NO_WARNINGS

#include <d3d9.h>
#include <d3dx9.h>
#include "MyDirect3D.h"
#include "MyTex.h"


static TextureData g_TextureData[TEXTUREDATA_MAX] = {};


PDIRECT3DTEXTURE9 g_pTexture = NULL;
static LPDIRECT3DDEVICE9 g_pDevice = NULL;





/////////////////////////////////////////////////////////////////////////�O���[�o���錾�I��


int Texture_SetLoadFile(const char*pFilename, int width, int height)	//�������F�t�@�C�����@�������F���@��O�����F����
{
	//�����t�@�C������T��
	for (int i = 0; i < TEXTUREDATA_MAX; i++)
	{
		if (strcmp(g_TextureData[i].filename, pFilename) == 0)	//������̍Ō�ɂ�0�������Ă��āA�Ō�̕����܂œ����ꍇ�Ō�ɕK��0����v����B
		{
			return i;
		}
	}

	//�݂���Ȃ������ꍇ�V�K�o�^���s��
	for (int i = 0; i < TEXTUREDATA_MAX; i++)
	{
		//�g�p����Ă��Ȃ��ꏊ��T��
		if (g_TextureData[i].filename[0] != 0)	//�t�@�C���f�[�^�z����̃����o���̍ŏ���0�ł���΁A���g�p�̗̈�(�g�p�\)
		{
			continue;	//0�ɂȂ�܂ŒT���i0�ł͂Ȃ��ꍇ�A���̍s�̎��_�ŏ����𒆒f���Afor�̊J�n�s�ɖ߂�j
		}

		//�o�^�J�n
		strcpy(g_TextureData[i].filename, pFilename);
		g_TextureData[i].width = width;
		g_TextureData[i].height = height;
		//�o�^����
		return i;
	}

	return -1;	//���s
}

int Texture_Load()
{
	g_pDevice = GetDevice();

	int error_count = 0;

	for (int i = 0; i < TEXTUREDATA_MAX; i++)
	{
		if (g_TextureData[i].filename[0] == 0)
		{
			continue;
		}

		if (g_TextureData[i].p_Texture != NULL)
		{
			continue;
		}

		//�e�N�X�`���ǂݍ���
		HRESULT hr=D3DXCreateTextureFromFile(g_pDevice, g_TextureData[i].filename, &g_TextureData[i].p_Texture);
		if (FAILED(hr))
		{
			MessageBox(NULL, "�e�N�X�`���̓ǂݍ��݂Ɏ��s���܂����B", "�x��", MB_OK);
			return false;
		 }
		
	}

	return error_count;
}

void Texture_Destroy(int ids[], int count)
{

	for (int i = 0; i < count; i++)
	{
		if (g_TextureData[ids[i]].p_Texture != NULL)
		{
			g_TextureData[ids[i]].p_Texture->Release();
			g_TextureData[ids[i]].height = 0;
			g_TextureData[ids[i]].width = 0;
			g_TextureData[ids[i]].p_Texture = NULL;
			g_TextureData[ids[i]].filename[0] = 0;
		}
	}


}

void Texture_Destroy(void)
{

	for (int i = 0; i < TEXTUREDATA_MAX; i++)
	{
		if (g_TextureData[i].p_Texture != NULL)
		{
			g_TextureData[i].p_Texture->Release();
			g_TextureData[i].height = 0;
			g_TextureData[i].width = 0;
			g_TextureData[i].p_Texture = NULL;
			g_TextureData[i].filename[0] = 0;
		}
	}

}

LPDIRECT3DTEXTURE9 Texture_GetTexture(int id)
{
	return g_TextureData[id].p_Texture;

}

int Texture_GetWidth(int id)
{
	return g_TextureData[id].width;
}

int Texture_GetHeight(int id)
{
	return g_TextureData[id].height;
}

