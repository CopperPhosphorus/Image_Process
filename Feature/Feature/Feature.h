//////////////////////////////////////////////////////////////////////////
/// \file       Feature.h
/// \brief      LBP������ȡͷ�ļ�
/// \author     
/// \version    
///             [V1.0] 2018/11/12, draft
/// \copyright  
///             
//////////////////////////////////////////////////////////////////////////

#ifndef  _FEATURE_H

#define _FEATURE_H
//for opencv
#include "cvhead.h"

using namespace cv;
using namespace std;

//////////////////////////////////////////////////////////////////////////
/// \brief  ԭʼLBP������ȡ
/// \remark 
/// \param[in]  src_img  Դ�Ҷ�ͼ
/// \param[in]  width    Դͼ��
/// \param[in]  height   Դͼ��
/// \param[in/out]  lbp_img  ���lbp����ͼ
//////////////////////////////////////////////////////////////////////////
void LBP_3X3_Ori(unsigned char* src_img, int width, int height, unsigned char* lbp_img);

//////////////////////////////////////////////////////////////////////////
/// \brief  ��ת����LBP����
/// \remark 
/// \param[in]  src_img  Դ�Ҷ�ͼ
/// \param[in]  width    Դͼ��
/// \param[in]  height   Դͼ��
/// \param[in/out]  lbp_img  ���lbp����ͼ
//////////////////////////////////////////////////////////////////////////
void LBP_3X3_Ratio(unsigned char* src_img, int width, int height, unsigned char* lbp_img);

//////////////////////////////////////////////////////////////////////////
/// \brief  Բ��LBP����
/// \remark 
/// \param[in]  src_img  Դ�Ҷ�ͼ
/// \param[in]  width    Դͼ��
/// \param[in]  height   Դͼ��
/// \param[in]  radius    �����뾶
/// \param[in]  neighbors   ����������Ĭ��Ϊ8
/// \param[in/out]  lbp_img  ���lbp����ͼ
//////////////////////////////////////////////////////////////////////////
void LBP_Circle(unsigned char* src_img, int width, int height, int radius, int neighbors, unsigned char* lbp_img);

//////////////////////////////////////////////////////////////////////////
/// \brief  ��ȡ8bit���ڵ��������
/// \remark 
/// \param[in]  num
/// \return  num���������
//////////////////////////////////////////////////////////////////////////
int GetHopCount(unsigned char num);

//////////////////////////////////////////////////////////////////////////
/// \brief  Uniform LBP����
/// \remark 
/// \param[in]  src_img  Դ�Ҷ�ͼ
/// \param[in]  width    Դͼ��
/// \param[in]  height   Դͼ��
/// \param[in/out]  lbp_img  ���lbp����ͼ
//////////////////////////////////////////////////////////////////////////
void Unifom_LBP(unsigned char* src_img, int width, int height, unsigned char* lbp_img);

//////////////////////////////////////////////////////////////////////////
/// \brief  MB-LBP����
/// \remark 
/// \param[in]  src_img  Դ�Ҷ�ͼ
/// \param[in]  width    Դͼ��
/// \param[in]  height   Դͼ��
/// \param[in]  Block_size   �ֿ�ߴ�,Ĭ��ʹ��9
/// \param[in/out]  lbp_img  ���lbp����ͼ
//////////////////////////////////////////////////////////////////////////
void MB_LBP(unsigned char* src_img, int width, int height, int Block_size, unsigned char* lbp_img);

//////////////////////////////////////////////////////////////////////////
/// \brief  ��ȡlbpͼ���LBPH����
/// \remark 
/// \param[in]  src  lbp����ͼ
/// \param[in]  numPatterns    lbp����ͼ��ģʽ���ࣨuniform lbpΪ59��
/// \param[in]  grid_x   �ֿ�Ŀ�
/// \param[in]  grid_y   �ֿ�ĸ�
/// \param[in]  normed   �Ƿ��һ��ֱ��ͼ��Ĭ��true
/// \return     ���ȫͼ��lbph����
//////////////////////////////////////////////////////////////////////////
Mat getLBPH(Mat src, int numPatterns, int grid_x, int grid_y, bool normed);

//////////////////////////////////////////////////////////////////////////
/// \brief  ��ȡlbpͼ��ֿ��LBPH����
/// \remark 
/// \param[in]  src  lbp����ͼ
/// \param[in]  minValue   ͼ����С�Ҷ�ֵ
/// \param[in]  maxValue   ͼ�����Ҷ�ֵ
/// \param[in]  normed   �Ƿ��һ��ֱ��ͼ��Ĭ��true
/// \return     ������lbph����
//////////////////////////////////////////////////////////////////////////
Mat getLocalRegionLBPH(const Mat& src, int minValue, int maxValue, bool normed);

int LBP();


#define ENABLE_INTEGRAL   (1)
//////////////////////////////////////////////////////////////////////////
/// \brief  ����ͼ�Ŀ���ʵ���㷨
/// \remark 
/// \param[in]  src    Դ�Ҷ�ͼ
/// \param[in]  width  Դ�Ҷ�ͼ��
/// \param[in]  height  Դ�Ҷ�ͼ��
/// \param[in/out]  integral   ����ͼ���,Ϊ����opencv��ʾ�����Ŷ���Ϊfloat�͵ģ�ʵ�ʿ�ʹ��int*
/// \return     success/fail
//////////////////////////////////////////////////////////////////////////
int integral_image_cacul(const unsigned char*  src, int width, int height, float *  integral);

#endif