#ifndef G_VARIABLE_H__
#define G_VARIABLE_H__

#include "lrx.h"



typedef struct SCTDATA
{
	HLPF_STR hpf;
	DRC_STR AGChp;

	BPF_STR  bpf;
	DRC_STR AGCbp;

	HLPF_STR lpf;
	DRC_STR AGClp;

	float hVolDepth;
    float bVolDepth;
    float lVolDepth;
	float mix[4];//���һ��·��ϵ��,����
	uint8_t en;//ʹ�ܣ�en=1,en=0�ر�
	uint8_t Ch;//ͨ������Ch={0,1}
}SCTDATA_STR;



typedef struct bpfstrOp
{
	uint16_t Fp;
	uint16_t Fs;
	int8_t  Type;
	uint8_t en;
	uint8_t Ch;  // �����ֽڶ���1
	uint8_t reserved1;  // �����ֽڶ���2
} BPF_OP;



/**
 * The brief description.
 * The detail description.
 */
typedef struct Crossbar
{
    uint8_t in;
    uint8_t out;
    uint8_t rd;
    fp32    mix;
}Crossbar_STR;


typedef struct  
{
    VOL_OP    vol[3];                   //VOL_STR  vol;               //8
    EQOP_STR   achEQ[48];       //16 * 48    
    EQOP_STR   bchEQ[2][7];     //16 * 14
    Outdly   outDly[6];         //12 * 6
    LimiterOP_STR  limit[6];    //24 * 6    
    Music3DOp_STR  m3D[2];      //28 * 2
    SCTDATA_STR    sct[2];        //104 * 2
    CHanHLPF_STR  hpf[6];       //8 * 6
    CHanHLPF_STR  lpf;       //8 * 2
    BPF_OP        bpf;
    AnaOrDigSrc_STR   ad;       //8
    Crossbar_STR    crossbar1[2][6];  //8      ���������·��
    float   outVol[6];
    char version[8];
} STR_DSP;



#define NAME_CNT   11
#define NAME_LEN   20

///������Ϣ
typedef struct MachineInformation
{
    char name[NAME_LEN];  //<�����浵��
    int sv;               //<����汾  
    int hv;               //<Ӳ���汾
    int SerialNumber;     //<���к�  
    int date;             //< ����
    int flag;
}MACINFO;

typedef struct Machine
{
    MACINFO macInfo;
    char archiveName[NAME_CNT][NAME_LEN];  //<�浵��
    STR_DSP *readDspInfo;
}MACHINE;


#define MACINF_ADDR     0
#define NAME_ADDRX(x)   (sizeof(MACINFO) + sizeof(char)*NAME_LEN*(x))
#define DATA_ADDRX(x)   (sizeof(MACINFO) + sizeof(char)*NAME_CNT*NAME_LEN + sizeof(STR_DSP)*(x))

#define MACINF_FLAG_ADDR     (NAME_LEN+ sizeof(int)*4)



extern STR_DSP dspInfo;
extern STR_DSP *rDspInfo;

extern MACHINE machine;




#endif //G_VARIABLE_H__
