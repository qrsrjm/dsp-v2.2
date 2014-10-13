/**
* @file 		I2C.c
* @brief		This is a brief description.
* @details	This is the detail description.
* @author		qmd
* @date		2014-8-18
* @version	001
* @par Copyright (c): 
* 		�����������������޹�˾
* @par History:         
*	version: author, date, desc\n
*/


#include 	"I2C.h"
#include <stdio.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h> 

#include <unistd.h> //sleep close
#include <stdlib.h> //exit




/* ����ΪI2C����ʱ����Ҫ�ı��� */
//volatile  uint8  I2C_sla;  		/* �ӻ���ַ (��������ַ)											*/
//volatile  uint8  I2C_suba;      /* �ӵ�ַ															*/
//volatile  uint8  *I2C_buf;      /* ���ݻ�����ָ�� (������ʱ�ᱻ����)								*/
//volatile  uint8  I2C_num;       /* �������ݸ��� (�ᱻ����)											*/
//volatile  uint8  I2C_end;       /* ����������־��Ϊ1ʱ��ʾ����������Ϊ0xFFʱ��ʾ����ʧ�� (�ᱻ����) */
//volatile  uint8  I2C_suba_en;   /* �ӵ�ַʹ�ܿ��ƣ�������ʱ������Ϊ1��д����ʱ������Ϊ2 (�ᱻ����)  */

struct i2c_write_data2 wdata2;

unsigned char DEVICE_ADDRESS=0x7a>>1;  /// Write Addr : 0x7a, Read Addr, 0x7a | 0x01

//����״̬��ʶ��1��ʾok
int check_aplus_ok_g = 0;


/** i2c �豸������*/
int fd_i2c = -1;

int open_fd_i2c(void)
{
	char nm[16];
	int fd = -1;

    if (fd_i2c >= 0) return fd_i2c;
    
	snprintf(nm, 16, "/dev/%s", I2C_DEV_NAME);
	if ((fd = open(nm, O_RDONLY)) < 0) {
		perror(nm);
		return -1;
	}
	
	fd_i2c = fd;
	
	return fd;
}

int close_fd_i2c(void)
{
    close(fd_i2c);
    return 0;
}


/**
 * �����ʱ���ṩ��I2C���ߵȴ���ʱʹ��
 * @param[in]	dly		��ʱ������ֵԽ����ʱԽ��
 * @retval	��
 * @par �޸���־
 * 		XXX��201X-XX-XX����
 */
uint8 I2CDlyEnd(uint32 dly)
{
	uint32  i;

	for (; dly>0; dly--)
	for (i = 0; i<5000; i++) {
        ;
	}
	return 0;
}


/**
 * �����ӵ�ַ�������Ͷ��ֽ����ݡ� ʹ��ǰҪ��ʼ����I2C���Ź��ܺ�I2C�жϣ�����ʹ��I2C��ģʽ
 * @param[in]	sla		�����ӻ���ַ
 * @param[in]   suba	�����ӵ�ַ
 * @param[in]   s		���ݷ��ͻ�����ָ��
 * @param[in]   no		�������ݸ���
 * @retval	1	�ɹ�
 * @retval	0	���� 
 * @par �޸���־
 * 		XXX��201X-XX-XX����
 */
uint8 I2CSendStr(uint8 sla, uint8 suba, uint8 *s, uint8 no)
{
	/* �������� */
	//I2C_sla = sla;			/* д������������ַ		 */
	//I2C_suba = suba;			/* �ӵ�ַ				 */
	//I2C_buf = s;
	//I2C_num = no;
	//I2C_suba_en = 2;			/* ���ӵ�ַд 			 */
	//I2C_end = 0;

	printf("%s\n",__FUNCTION__);

	unsigned char ert = _i2c_write(sla, suba, s, no);
	int ret=-1;
	
	if(ert == 1)	/**ʧ��*/
		ret = 0;
	else			/**�ɹ�*/
		ret = 1;

	return ret;
}

/**
 * �����ӵ�ַ������ȡ���ֽ����ݡ� ʹ��ǰҪ��ʼ����I2C���Ź��ܺ�I2C�жϣ�����ʹ��I2C��ģʽ
 * @param[in]	sla		�����ӻ���ַ
 * @param[in]   suba	�����ӵ�ַ
 * @param[out]   s		���ݽ��ջ�����ָ��
 * @param[in]   no		��ȡ���ݸ���
 * @retval	1	�ɹ�
 * @retval	0	���� 
 * @par �޸���־
 * 		XXX��201X-XX-XX����
 */
uint8 I2CRcvStr(uint8 sla, uint8 suba, uint8 *s, uint8 no)
{
	if (0 == no)
		return 0;

	/* �������� */
	//I2C_sla = sla + 1;		/* ��������������ַ		  */
	//I2C_suba = suba;
	//I2C_buf = s;
	//I2C_num = no;
	//I2C_suba_en = 1;			/* ���ӵ�ַ��			  */
	//I2C_end = 0;

	printf("%s\n", __FUNCTION__);
    
	unsigned char ert = _i2c_write(sla, suba, s, no);
	int ret=-1;
	
	if(ert == 1)	/**ʧ��*/
		ret = 0;
	else			/**�ɹ�*/
		ret = 1;
		
	return ret;
}

/**
 * �����ӵ�ַ�������Ͷ�32λ�����ݡ���
 * @param[in]	sla		�����ӻ���ַ
 * @param[in]   suba	�����ӵ�ַ
 * @param[in]   s		���ݷ��ͻ�����ָ��
 * @param[in]   no		�������ݸ���
 * @retval	1	�ɹ�
 * @retval	0	���� 
 * @par �޸���־
 * 		XXX��201X-XX-XX����
 */
uint8 I2CWriteMultiWord(uint8 sla, uint8 suba, uint32* s, uint8 no)
{
	uint8 	charbuf[20];
	uint32 	i;
    
    printf("%s\n", __FUNCTION__);

	for (i = 0; i<no; i++) {
		charbuf[4 * i] = (uint8)(s[i] >> 24);
		charbuf[4 * i + 1] = (uint8)(s[i] >> 16);
		charbuf[4 * i + 2] = (uint8)(s[i] >> 8);
		charbuf[4 * i + 3] = (uint8)s[i];
	}

	if (_i2c_write(sla, suba, charbuf, 4 * no) == 0)
		return 1;
	else
		return 0;
}

/**
 * �����ӵ�ַ������ȡ���32λ�����ݡ�
 * @param[in]	sla		�����ӻ���ַ
 * @param[in]   suba	�����ӵ�ַ
 * @param[in]   s		���ݽ��ջ�����ָ��
 * @param[in]   no		��ȡ���ݸ���
 * @retval	1	�ɹ�
 * @retval	0	���� 
 * @par �޸���־
 * 		XXX��201X-XX-XX����
 */
uint8 I2CReadMultiWord(uint8 sla, uint8 suba, uint32* s, uint8 no)
{
	uint8 	charbuf[20];
	uint32 	i;

    printf("%s\n", __FUNCTION__);

	if (_i2c_read(sla, suba, charbuf, 4 * no) == 0) {
		for (i = 0; i<no; i++) {
			s[i] = ((uint32)charbuf[4 * i]) << 24;
			s[i] |= ((uint32)charbuf[4 * i + 1]) << 16;
			s[i] |= ((uint32)charbuf[4 * i + 2]) << 8;
			s[i] |= ((uint32)charbuf[4 * i + 3]);
		}
		return 1;
	}
	else
		return 0;
}



/**
 * This is a brief description.
 * This is a detail description.
 * @param[in]	inArgName input argument description.
 * @param[out]	outArgName output argument description. 
 * @retval	0	�ɹ�
 * @retval	1	���� 
 * @par ��ʶ��
 * 		����
 * @par ����
 * 		��
 * @par �޸���־
 * 		XXX��201X-XX-XX����
 */
static unsigned char _i2c_write2(int fd_i2c,unsigned char device_addr, unsigned char sub_addr, unsigned char *buff, int ByteNo)
{
	if((fd_i2c < 0) || !buff) {
        printf("fd<0 or !buff\n");
        return 1;
    }
	
	//����iicоƬ��ַ
	if(ioctl(fd_i2c, RT2880_I2C_SET_ADDR, device_addr) != 0){
        printf("set device_addr error.\n");
        return 1;
    }
	
	//usleep(50000);
	//usleep(500);

	wdata2	.address = sub_addr;
	//wdata2.pData_i2c = buff;
	memcpy(wdata2.data_i2c,buff,ByteNo);
	wdata2.size = ByteNo;

	if(ioctl(fd_i2c, RT2880_I2C_WRITE, &wdata2) != 0){
        printf("sub and buff fail.\n");
        return 1;
    }

	//usleep(50000);
	//usleep(500);

    //printf("%s\n", __FUNCTION__);
    
	return 0;
}


/**
 * This is a brief description.
 * This is a detail description.
 * @param[in]	inArgName input argument description.
 * @param[out]	outArgName output argument description. 
 * @retval	0	�ɹ�
 * @retval	1	���� 
 * @par ��ʶ��
 * 		����
 * @par ����
 * 		��
 * @par �޸���־
 * 		XXX��201X-XX-XX����
 */
static unsigned char _i2c_read2(int fd_i2c,unsigned char device_addr, unsigned char sub_addr, unsigned char *buff, int ByteNo)
{
	if((fd_i2c < 0) || !buff){
        printf("%s> fd < 0\n",__FUNCTION__);
		return 1;
    }
	
	//����iicоƬ��ַ
	if(ioctl(fd_i2c, RT2880_I2C_SET_ADDR, device_addr) != 0){
        printf("%s> set device_addr fail.\n",__FUNCTION__);
		return 1;
    }

	//usleep(50000);
    //usleep(500);

	wdata2.address = sub_addr;
	//wdata2.pData_i2c = buff;
	//memcpy(wdata2.data_i2c,buff,ByteNo);
	wdata2.size = ByteNo;
	
	if (ioctl(fd_i2c, RT2880_I2C_READ, &wdata2) != 0){
        printf("%s> RT2880_I2C_READ fail.\n",__FUNCTION__);
		return 1;
    }

	if(wdata2.size != ByteNo){
        printf("%s> ByteNo fail. %d,%d\n",__FUNCTION__,wdata2.size,ByteNo);
		return 1;
    }

	memcpy(buff,wdata2.data_i2c,ByteNo);
	
	//usleep(50000);
	//usleep(500);

    //printf("%s\n", __FUNCTION__);
    
	return 0;
}

/**
 * ��ʱ���� ��������ʱ�ĵ�λΪMS
 * @param[in]	inArgName input argument description.
 * @par �޸���־
 * 		XXX��201X-XX-XX����
 */
void _alpu_delay_ms(unsigned int i)
{
	//Delay_ms(i);
	usleep(i*1000);
}

/**
 * �����������
 * @retval	 
 * @retval	 
 * @par �޸���־
 * 		XXX��201X-XX-XX����
 */
unsigned char _alpu_rand(void)   //Modify this fuction using RTC. But you should not change the function name.
{
  static unsigned long seed; // 2byte, must be a static variable

  seed = seed + rand(); // rand(); <------------------ add time value
  seed =  seed * 1103515245 + 12345;

  return (seed/65536) % 32768;
}


/**
 * This is a brief description.
 * This is a detail description.
 * @param[in] device_addr :�豸��ַ������ͨ�Ų����豸��ַ ��һ�µģ�����Ĭ�ϵ�ֵ��7A ��������������ò�ͬ�����Բ�ʹ��������ݣ�	
 * @param[in] sub_addr���ӵ�ַ
 * @param[out] buff���洢���ݵ�buff
 * @param[in] ByteNo:���ݵĳ���
 * @retval	0	    �ɹ�
 * @retval	����	���� 
 * @par �޸���־
 * 		XXX��201X-XX-XX����
 */
unsigned char _i2c_read(unsigned char device_addr, unsigned char sub_addr, unsigned char *buff, int ByteNo)
{
	//iic_read_fun()                          //your IIC read funtion 
	return  _i2c_read2(fd_i2c, device_addr, sub_addr, buff, ByteNo);
}


/**
 * This is a brief description.
 * This is a detail description.
 * @param[in] device_addr :�豸��ַ������ͨ�Ų����豸��ַ ��һ�µģ�����Ĭ�ϵ�ֵ��7A ��������������ò�ͬ�����Բ�ʹ��������ݣ�	
 * @param[in] sub_addr���ӵ�ַ
 * @param[in] buff���洢���ݵ�buff
 * @param[in] ByteNo:���ݵĳ���
 * @retval	0	    �ɹ�
 * @retval	����	���� 
 * @par �޸���־
 * 		XXX��201X-XX-XX����
 */
unsigned char _i2c_write(unsigned char device_addr, unsigned char sub_addr, unsigned char *buff, int ByteNo)
{
	//iic_write_fun()                          //your IIC write funtion
	return _i2c_write2(fd_i2c, device_addr,  sub_addr, buff, ByteNo);
}



/**
 *For Encryption mode, you are supposed to call the _alpum_process() function in ALPU Check fuction or main source.
 *The return value would be "0"(zero) if the library file is work well. otherwise, the return value would be error_code value.
 * @retval		    �ɹ�
 * @retval		���� 
 * @par �޸���־
 * 		XXX��201X-XX-XX����
 */
#if test_i2c
void _alpuc_process_bypass(void)
{
	int i;
	int j=0;
    unsigned char error_code;
	unsigned char dx_data[8];		 // ��������ݣ� ���� ��ȷ�Ļ�Ӧ�ú�tx_data���
	unsigned char tx_data[8];		//	����� �� ����ϵͳ������

	static int seed2=0;

    //for(j=0; j<1000; j++)   {
    for(j=0; j<1; j++)   {
		
#if 0		
	for(i=0; i<8; i++)
	{	
		tx_data[i] = _alpu_rand();
		dx_data[i] = 0;
	}
#else
	for(i=0; i<8; i++)
	{
		srand((int) time(0) + i + seed2++); //������srand��������������ӣ�����rand�������������
		tx_data[i] = rand()&0xff;
		dx_data[i] = 0;
	}
#endif	
	
		error_code = alpuc_process(tx_data,dx_data);  //����API�ӿ�

		if(error_code){
			printf("\r\nAlpu-M Encryption Test Fail!!!\r\n");
			check_aplus_ok_g = 0;
			break;
		}

		else{
			printf("\r\nAlpu-M Encryption Test Success!!!\r\n");
			check_aplus_ok_g = 1;
    		}

    }

	//other functions..
}
#else 

unsigned char dec_tx_data[8];
unsigned char dec_rx_data[8];
unsigned char dec_dx_data[8];


static void _alpuc_bypass(void)
{
    int i;
    for ( i=0; i<8; i++ ) 
		dec_dx_data[i] = dec_tx_data[i] ^ 0x01 ;
}


//���ô˺�������ͨ����Ȼ������ҳ��Ҷ��Ƽ����㷨
//����0��ʾ�ɹ�
unsigned char _alpuc_process_bypass(void)
{
    unsigned char error_code;
    int i;

	char nm[16];
	
#if 0
	int fd_i2c;
	//��iic�豸
	snprintf(nm, 16, "/dev/%s", I2C_DEV_NAME);
	if ((fd_i2c = open(nm, O_RDONLY)) < 0) {
		printf("_alpuc_process_bypass(open i2c error)\n");
		return 1;
	}
#else
	if(fd_i2c <= 0)
		return 0x88;
#endif

	for(i=0; i<8;i++)
	{
		dec_tx_data[i] =0x00;
		dec_rx_data[i] =0x00;
		dec_dx_data[i] =0x00;
	}
	
	//Seed Generate
    //for(i=0; i<8; i++) dec_tx_data[i] = _alpu_rand();
    for(i=0; i<8; i++)
	{
		srand((int) time(0)+i); //������srand��������������ӣ�����rand�������������
		dec_tx_data[i] = rand()&0xff;
	}

    //Write Seed Data to ALPU-C
    unsigned char sub_address = 0x80;
    error_code = _i2c_write(DEVICE_ADDRESS, sub_address, dec_tx_data, 8);
    if ( error_code ) 
    {
    	//close(fd_i2c);
		return error_code ;
    }

    //Read Result Data from ALPU-C
    error_code = _i2c_read(DEVICE_ADDRESS, sub_address, dec_rx_data, 8);
    if ( error_code ) 
    {
    	//close(fd_i2c);
		return error_code ;
    }
	
    //Bypass Operation
    _alpuc_bypass();

    //Compare the encoded data and received data
    for (i=0; i<8; i++) 
    {
		if(dec_dx_data[i] != dec_rx_data[i]) 
		{
			//close(fd_i2c);
			printf("fail........\n");
			return 60;
		}
    }

	printf(" ok  ........\n");
	
	//�ر�iic�豸
	//close(fd_i2c);
	
    return 0;
}

void dsp_reset()
{
	printf("-->%s\n",__FUNCTION__);

    if (ioctl(fd_i2c, 99, NULL) < 0)
       return; 
	usleep(100);
    if (ioctl(fd_i2c, 88, NULL) < 0)
       return;
	usleep(290*1000);	
}

#endif



unsigned char alpuc_process(unsigned char *a, unsigned char *b)
{

}





































