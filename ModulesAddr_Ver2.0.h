/*=================================================================================
FFile Name:    I2C_HEX_Addr.addr
DDate:         2014/9/16 15:38:18










// TAS3XXX��ʱ�ӼĴ�����I2C�ӵ�ַ
/*
#define  TAS3204AudioApp_1		0x1		//0x1 0x4 ! (TAS3204AudioApp_1) Reserved by Texas Instruments
#define  TAS3204AudioApp_1		0x2		//0x2 0x4 ! (TAS3204AudioApp_1) Status Register
#define  TAS3204AudioApp_1		0x3		//0x3 0x4 ! (TAS3204AudioApp_1) Reserved by Texas Instruments
#define  TAS3204AudioApp_1		0x4		//0x4 0x8 ! (TAS3204AudioApp_1) I2C Memory Load Control
#define  TAS3204AudioApp_1		0x5		//0x5 0x8 ! (TAS3204AudioApp_1) I2C Memory Load Data
#define  TAS3204AudioApp_1		0x6		//0x6 0x4 ! (TAS3204AudioApp_1) Peek/Poke Address
#define  TAS3204AudioApp_1		0x7		//0x7 0x8 ! (TAS3204AudioApp_1) Peek/Poke Data
#define  TAS3204AudioApp_1		0x8		//0x8 0x4 ! (TAS3204AudioApp_1) Application Version
#define  TAS3204AudioApp_1		0x9		//0x9 0x4 ! (TAS3204AudioApp_1) Reserved by Texas Instruments
#define  TAS3204AudioApp_1		0xA		//0xA 0x4 ! (TAS3204AudioApp_1) Reserved by Texas Instruments
#define  TAS3204AudioApp_1		0xB		//0xB 0x4 ! (TAS3204AudioApp_1) DSP PC Start Address
#define  TAS3204AudioApp_1		0xC		//0xC 0x4 ! (TAS3204AudioApp_1) GPIO Control via I2C
#define  TAS3204AudioApp_1		0xD		//0xD 0x4 ! (TAS3204AudioApp_1) Reserved by Texas Instruments
#define  TAS3204AudioApp_1		0xE		//0xE 0x4 ! (TAS3204AudioApp_1) Treble/Bass Slew Rate
#define  TAS3204AudioApp_1		0xF		//0xF 0x4 ! (TAS3204AudioApp_1) Master Download
#define  TAS3204AudioApp_1		0x10		//0x10 0x4 ! (TAS3204AudioApp_1) Analog Central Power Down
#define  TAS3204AudioApp_1		0x11		//0x11 0x4 ! (TAS3204AudioApp_1) Analog Individual Power Down
#define  TAS3204AudioApp_1		0x12		//0x12 0x4 ! (TAS3204AudioApp_1) ADC Mux Control
#define  TAS3204AudioApp_1		0x13		//0x13 0x4 ! (TAS3204AudioApp_1) ADC DEM Control
#define  TAS3204AudioApp_1		0x14		//0x14 0x4 ! (TAS3204AudioApp_1) ADC2 Current Control 1
#define  TAS3204AudioApp_1		0x15		//0x15 0x4 ! (TAS3204AudioApp_1) ADC2 Current Control  2
#define  TAS3204AudioApp_1		0x16		//0x16 0x4 ! (TAS3204AudioApp_1) Reserved by Texas Instruments
#define  TAS3204AudioApp_1		0x17		//0x17 0x4 ! (TAS3204AudioApp_1) ADC1 Current Control 1
#define  TAS3204AudioApp_1		0x18		//0x18 0x4 ! (TAS3204AudioApp_1) ADC1 Current Control 2
#define  TAS3204AudioApp_1		0x19		//0x19 0x4 ! (TAS3204AudioApp_1) Reserved by Texas Instruments
#define  TAS3204AudioApp_1		0x1A		//0x1A 0x4 ! (TAS3204AudioApp_1) DAC Current Control
#define  TAS3204AudioApp_1		0x1B		//0x1B 0x4 ! (TAS3204AudioApp_1) DAC Chopper Control
#define  TAS3204AudioApp_1		0x1C		//0x1C 0x4 ! (TAS3204AudioApp_1) Reserved by Texas Instruments
#define  TAS3204AudioApp_1		0x1D		//0x1D 0x4 ! (TAS3204AudioApp_1) Reserved by Texas Instruments
#define  TAS3204AudioApp_1		0x1E		//0x1E 0x4 ! (TAS3204AudioApp_1) ADC/DAC Reset
#define  TAS3204AudioApp_1		0x1F		//0x1F 0x4 ! (TAS3204AudioApp_1) DEM bit toggle for ADC DWA
#define  TAS3204AudioApp_1		0x20		//0x20 0x4 ! (TAS3204AudioApp_1) ADC Input Gain
#define  TAS3204AudioApp_1		0x21		//0x21 0x4 ! (TAS3204AudioApp_1) MCLK OUT 2 Divider
#define  TAS3204AudioApp_1		0x22		//0x22 0x4 ! (TAS3204AudioApp_1) MCLK OUT 3 Divider
#define  TAS3204ADCIn_1		0x23		//0x23 0xC ! (TAS3204ADCIn_1) I2C Interface to pass High pass filter coefficients


#define  Limiter1		0x73		//0x73 0x10 ! (Limiter1) T1_input and T2_input
#define  Limiter1		0x74		//0x74 0xC ! (Limiter1) k0, k1, and k2
#define  Limiter1		0x75		//0x75 0x10 ! (Limiter1) O1_input and O2_input
#define  Limiter1		0x76		//0x76 0x10 ! (Limiter1) aa, 1_aa, ad, and 1_ad
#define  Limiter1		0x77		//0x77 0x8 ! (Limiter1) DRC enable
#define  Limiter2		0x79		//0x79 0x10 ! (Limiter2) T1_input and T2_input
#define  Limiter2		0x7A		//0x7A 0xC ! (Limiter2) k0, k1, and k2
#define  Limiter2		0x7B		//0x7B 0x10 ! (Limiter2) O1_input and O2_input
#define  Limiter2		0x7C		//0x7C 0x10 ! (Limiter2) aa, 1_aa, ad, and 1_ad
#define  Limiter2		0x7D		//0x7D 0x8 ! (Limiter2) DRC enable
#define  Limiter3		0x7F		//0x7F 0x10 ! (Limiter3) T1_input and T2_input
#define  Limiter3		0x80		//0x80 0xC ! (Limiter3) k0, k1, and k2
#define  Limiter3		0x81		//0x81 0x10 ! (Limiter3) O1_input and O2_input
#define  Limiter3		0x82		//0x82 0x10 ! (Limiter3) aa, 1_aa, ad, and 1_ad
#define  Limiter3		0x83		//0x83 0x8 ! (Limiter3) DRC enable
#define  Limiter4		0x85		//0x85 0x10 ! (Limiter4) T1_input and T2_input
#define  Limiter4		0x86		//0x86 0xC ! (Limiter4) k0, k1, and k2
#define  Limiter4		0x87		//0x87 0x10 ! (Limiter4) O1_input and O2_input
#define  Limiter4		0x88		//0x88 0x10 ! (Limiter4) aa, 1_aa, ad, and 1_ad
#define  Limiter4		0x89		//0x89 0x8 ! (Limiter4) DRC enable
#define  Limiter5		0x8B		//0x8B 0x10 ! (Limiter5) T1_input and T2_input
#define  Limiter5		0x8C		//0x8C 0xC ! (Limiter5) k0, k1, and k2
#define  Limiter5		0x8D		//0x8D 0x10 ! (Limiter5) O1_input and O2_input
#define  Limiter5		0x8E		//0x8E 0x10 ! (Limiter5) aa, 1_aa, ad, and 1_ad
#define  Limiter5		0x8F		//0x8F 0x8 ! (Limiter5) DRC enable

#define  Limiter6		0xF1		//0xF1 0x10 ! (Limiter6) T1_input and T2_input
#define  Limiter6		0xF2		//0xF2 0xC ! (Limiter6) k0, k1, and k2
#define  Limiter6		0xF3		//0xF3 0x10 ! (Limiter6) O1_input and O2_input
#define  Limiter6		0xF4		//0xF4 0x10 ! (Limiter6) aa, 1_aa, ad, and 1_ad
#define  Limiter6		0xF5		//0xF5 0x8 ! (Limiter6) DRC enable



#define  AGC_H1		0xC4		//0xC4 0x10 ! (AGC_H1) T1_input and T2_input
#define  AGC_H1		0xC5		//0xC5 0xC ! (AGC_H1) k0, k1, and k2
#define  AGC_H1		0xC6		//0xC6 0x10 ! (AGC_H1) O1_input and O2_input
#define  AGC_H1		0xC7		//0xC7 0x10 ! (AGC_H1) aa, 1_aa, ad, and 1_ad


/*
#define  TAS3204AudioApp_1		0xCD		//0xCD 0x4 ! (TAS3204AudioApp_1) Delay Pointer 10 and 11 Length
#define  TAS3204AudioApp_1		0xCE		//0xCE 0x4 ! (TAS3204AudioApp_1) Delay Pointer 12 and 13 Length
#define  TAS3204AudioApp_1		0xCF		//0xCF 0x4 ! (TAS3204AudioApp_1) Delay Pointer 14 and 15 Length
#define  TAS3204AudioApp_1		0xD0		//0xD0 0x4 ! (TAS3204AudioApp_1) Delay Pointer 16 and 17 Length
#define  TAS3204AudioApp_1		0xD1		//0xD1 0x4 ! (TAS3204AudioApp_1) Delay Pointer 18 and 19 Length
#define  TAS3204AudioApp_1		0xD2		//0xD2 0x4 ! (TAS3204AudioApp_1) Delay Pointer 20 and 21 Length
#define  TAS3204AudioApp_1		0xD3		//0xD3 0x4 ! (TAS3204AudioApp_1) Delay Pointer 22 and 23 Length

#define  AGC_B1		0xD7		//0xD7 0x10 ! (AGC_B1) T1_input and T2_input
#define  AGC_B1		0xD8		//0xD8 0xC ! (AGC_B1) k0, k1, and k2
#define  AGC_B1		0xD9		//0xD9 0x10 ! (AGC_B1) O1_input and O2_input
#define  AGC_B1		0xDA		//0xDA 0x10 ! (AGC_B1) aa, 1_aa, ad, and 1_ad
#define  AGC_B1		0xDB		//0xDB 0x8 ! (AGC_B1) DRC enable
#define  AGC_L1		0xDD		//0xDD 0x10 ! (AGC_L1) T1_input and T2_input
#define  AGC_L1		0xDE		//0xDE 0xC ! (AGC_L1) k0, k1, and k2
#define  AGC_L1		0xDF		//0xDF 0x10 ! (AGC_L1) O1_input and O2_input
#define  AGC_L1		0xE0		//0xE0 0x10 ! (AGC_L1) aa, 1_aa, ad, and 1_ad
#define  AGC_L1		0xE1		//0xE1 0x8 ! (AGC_L1) DRC enable
#define  AGC_H2		0xE3		//0xE3 0x10 ! (AGC_H2) T1_input and T2_input
#define  AGC_H2		0xE4		//0xE4 0xC ! (AGC_H2) k0, k1, and k2
#define  AGC_H2		0xE5		//0xE5 0x10 ! (AGC_H2) O1_input and O2_input
#define  AGC_H2		0xE6		//0xE6 0x10 ! (AGC_H2) aa, 1_aa, ad, and 1_ad
#define  AGC_H2		0xE7		//0xE7 0x8 ! (AGC_H2) DRC enable
#define  AGC_B2		0xE9		//0xE9 0x10 ! (AGC_B2) T1_input and T2_input
#define  AGC_B2		0xEA		//0xEA 0xC ! (AGC_B2) k0, k1, and k2
#define  AGC_B2		0xEB		//0xEB 0x10 ! (AGC_B2) O1_input and O2_input
#define  AGC_B2		0xEC		//0xEC 0x10 ! (AGC_B2) aa, 1_aa, ad, and 1_ad
#define  AGC_B2		0xED		//0xED 0x8 ! (AGC_B2) DRC enable

#define  AGC_L2		0xF7		//0xF7 0x10 ! (AGC_L2) T1_input and T2_input
#define  AGC_L2		0xF8		//0xF8 0xC ! (AGC_L2) k0, k1, and k2
#define  AGC_L2		0xF9		//0xF9 0x10 ! (AGC_L2) O1_input and O2_input
#define  AGC_L2		0xFA		//0xFA 0x10 ! (AGC_L2) aa, 1_aa, ad, and 1_ad
#define  AGC_L2		0xFB		//0xFB 0x8 ! (AGC_L2) DRC enable