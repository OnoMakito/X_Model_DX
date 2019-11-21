#ifndef MT_H	//�C���N���[�h�K�[�h

#define MT_H


#include <d3d9.h>
#include <d3dx9.h>

#define FILENAME_MAX (128)	//�t�@�C�����̍ő啶��
#define TEXTUREDATA_MAX (50)	//�g���e�N�X�`���̍ő喇��

typedef struct TextureData_tag
{
	char filename[FILENAME_MAX];
	int width;
	int height;
	LPDIRECT3DTEXTURE9 p_Texture;
}TextureData;

int Texture_SetLoadFile(const char*pFilename, int width, int height);	//�������F�t�@�C�����@�������F���@��O�����F����
//���\��ԍ��Fid

int Texture_Load(void);	//�t�@�C���̓ǂݍ���	�G���[�������Ԃ�l�ɂȂ�B

void Texture_Destroy(int ids[], int count);	//�e�N�X�`���̉��	�������F�������e�N�X�`��(id)�̐擪�A�h���X�@�������F�z��

LPDIRECT3DTEXTURE9 Texture_GetTexture(int id);	//SetLoadFile�̗\��l

void Texture_Destroy(void);	//�I�[�o�[���[�h�g�p

int Texture_GetWidth(int id);
int Texture_GetHeight(int id);





#endif
