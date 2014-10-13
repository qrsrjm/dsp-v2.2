/*
*****************************************Copyright (c)*********************************************
**
**
**									 �����������������޹�˾
**                             Guangzhou Lrsun Electronic Co.,Ltd.
**
**                                    http://www.lrsun.net
**
**
**
**	�ļ���	��DataStg.h
**	
**	����Ա	���¼ҳ�
**
**	�ա���  ��2009��1��19��
**
**	�ļ�����������������ת��ɶ���ֽڴ洢���Ӷ��������ֽڶ�����ת������Ӧ�����͵�����
**
**
***************************************************************************************************
*/
#ifndef _DataStg_H
#define _DataStg_H

#include <stdint.h>
#include "MyType.h"
#include "UserMath.h"

extern void DstFlt2Chr(uint8 *px, fp32 fVal);

extern fp32 DstChr2Flt(uint8 *px);

extern void DstInt2Chr(uint8 *px, int32 iVal);

extern int32 DstChr2Int(uint8 *px);

extern void DstSht2Chr(uint8 *px, int16 sVal);

extern int16 DstChr2Sht(uint8 *px);

extern void DSTStr2Byte(uint8 *pDat, void *pStr, int32 len);

extern void DSTByte2Str(uint8 *pDat, void *pStr, int32 len);
 
#endif


