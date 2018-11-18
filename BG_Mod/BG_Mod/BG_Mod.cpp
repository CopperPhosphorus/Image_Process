#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//for opencv
#include "cvhead.h"

using namespace cv;
using namespace std;

void Average_Mean_Bg_Fg(unsigned char* src_img , int width, int height, unsigned char* bg_mod, unsigned char* dst)
{
    int Thre = 25;
    double alp = 0.65;  //alp Խ��Ա����仯����Ӧ�ٶ�Խ��  

    for (int i = 0; i < height; ++i)
    {
        int index = i * width;
        for (int j = 0; j < width; ++j)
        {
            unsigned char tmp = abs(src_img[index + j] - bg_mod[index + j]);
            dst[index + j] = (tmp > Thre) ? 255 : 0;

            //��������  ����������ֵ���������(��Ϊ̫�鷳��)
            bg_mod[index + j] = alp * src_img[index + j] + (1 - alp) * bg_mod[index + j];
            bg_mod[index + j] = bg_mod[index + j] > 255 ? 255 : bg_mod[index + j];
        }
    }

    return;
}

void Average_Mean_SBG_Fg(unsigned char* src_img, int width, int height,
                    unsigned char* bg_mod, unsigned char* sbg_mod, unsigned char* dst)
{
    int Thre  = 25;
    int Thres = 65;
    double alp = 0.65;  //alp Խ��Ա����仯����Ӧ�ٶ�Խ��  

    for (int i = 0; i < height; ++i)
    {
        int index = i * width;
        for (int j = 0; j < width; ++j)
        {
            unsigned char tmp = abs(src_img[index + j] - bg_mod[index + j]);
            unsigned char tmps = abs(src_img[index + j] - sbg_mod[index + j]);

            dst[index + j] = ( (tmps > Thres) && (tmps > Thre)) ? 255 : 0;  //outputs == 1 and output == 1

            //���¸�������
            if (tmp < Thre)  //output == 0 ���¸�������
            {
                sbg_mod[index + j] = src_img[index + j];
            }

            //��������  ����������ֵ���������(��Ϊ̫�鷳��)
            bg_mod[index + j] = alp * src_img[index + j] + (1 - alp) * bg_mod[index + j];
            bg_mod[index + j] = bg_mod[index + j] > 255 ? 255 : bg_mod[index + j];

            
        }
    }

    return;
}

//���µ���˹������ģ�ı�׼��������
void Update_var_and_std(float varInit, int index, float *var_img, float *std_img)
{
    var_img[index] = varInit;
    std_img[index] = sqrt(varInit);
}

void Gauss_BGM(unsigned char* src_img, int width, int height, 
            unsigned char* bg_img, float* var_img, 
            float *std_img,  unsigned char* dst)
{
    float varInit = 0.0;  //��ʼ������
    float alp = 0.02;     //������ģalp ԽС�Ա����仯����Ӧ�ٶ�Խ��(��������Խ��)  
    int lamda = 3;        //�������²���

    for (int i = 0; i < height; ++i)
    {
        int index = i * width;
        for (int j = 0; j < width; ++j)
        {
            int tmp = src_img[index + j] - bg_img[index + j];

            //|I-U|<lamda * stdInitʱ��Ϊ�Ǳ��������б�������  
            if (abs(tmp) < lamda * std_img[index+j])
            {
                //���±���ģ�ͣ���������
                bg_img[index + j] = (1 - alp) * bg_img[index + j] + alp * src_img[index + j];

                //���·����׼��
               varInit = (1 - alp) * var_img[index + j] + alp * tmp *tmp;
               Update_var_and_std(varInit, index + j, var_img, std_img);

                dst[index + j] = 0;
            }
            else
            {
                dst[index + j] = 255;
            }
        }
    }
}