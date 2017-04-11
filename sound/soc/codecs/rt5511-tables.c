/* sound/soc/codecs/rt5511-tables.c
 * RT5511 registers tables / registers cache
 *
 * Copyright (C) 2013 Richtek Technology Corp.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 */

#include "rt5511.h"
#include <linux/mfd/rt5511/core.h>
#include <linux/string.h>

/* always BE */
const struct rt5511_access_mask rt5511_access_masks[RT5511_CACHE_SIZE] = {
	{"VID", 0xff, 0x00, 1},       /* 0x00 */
	{"I2S_CK_SEL", 0x1f, 0x1f, 0},   /* 0x01 */
	{"AUD_FMT/AUF1_FMT", 0x7f, 0x7f,  0},  /* 0x02 (RT5511A) */
	{"CLK1_MODE", 0xff, 0xff,  0},  /* 0x03 */
	{"CLK2_MODE", 0xff, 0xff,  0},  /* 0x04 */
	{"AIF_CTRL1", 0x7f, 0x7f,  0},  /* 0x05 */
	{"SOURCE_ENABLE", 0x7f, 0x7f,  0},  /* 0x06 */
	{"MUTE_CTRL", 0xef, 0xef,  0},  /* 0x07 */
	{"DAC_VOL", 0x003f003f, 0x003f003f,  0},    /* 0x08 */
	{"TX2_VOL", 0x003f003f, 0x003f003f,  0},    /* 0x09 */
	{"AUD_DAC1_VOL", 0x003f003f, 0x003f003f,  0},    /* 0x0a */
	{"AUD_DAC2_VOL", 0x003f003f, 0x003f003f,  0},    /* 0x0b */
	{"AUD_ADC1_VOL", 0x003f003f, 0x003f003f,  0},    /* 0x0c */
	{"AUD_ADC2_VOL", 0x003f003f, 0x003f003f,  0},    /* 0x0d */
	{"ADC_FG_VOL", 0x003f003f, 0x003f003f,  0},    /* 0x0e */
	{"SDM_VOL", 0xffffffff, 0xffffffff,  0},    /* 0x0f */

	{"DAC_L_MIX", 0xff, 0xff,  0},  /* 0x10 */
	{"DAC_R_MIX", 0xff, 0xff,  0},  /* 0x11 */
	{"AUD_TX2_L_MIX", 0xff, 0xff,  0},  /* 0x12 */
	{"AUD_TX2_R_MIX", 0xff, 0xff,  0},  /* 0x13 */
	{"BASS_3D_EN/AUD2_FMT", 0xff, 0xff,  0},  /* 0x14 (RT5511A) */
	{"DAC_DRC_EQ_EN", 0xbf, 0xbf,  0},  /* 0x15 */
	{"ADC_CTRL", 0xff, 0xff,  0},  /* 0x16 */
	{"ADC_HPF_MODE", 0x3f, 0x3f,  0},  /* 0x17 */
	{"DMIC_CTRL", 0xef, 0xff,  0},  /* 0x18 */
	{"DMIC_STS", 0x07, 0x00,  0},  /* 0x19 */
	{"ASRC_CTRL1", 0xff, 0xff,  0},  /* 0x1a */
	{"ASRC_CTRL2", 0x3f, 0x00,  0},  /* 0x1b */
	{"VOL_RAMP_DEF_CTRL", 0x3f, 0x3f,  0},  /* 0x1c */
	{"AIF_CTRL2", 0x37ffffff, 0x37ffffff,  0},    /* 0x1d */
	{"Reserve", 0x0, 0x0,  0},    /* 0x1e */
	{"EQ_BAND_SEL", 0x03, 0x03,  0},  /* 0x1f */

	{"BQ1", 0x0, 0x0,  0},    /* 0x20 */
	{"BQ2", 0x0, 0x0,  0},    /* 0x21 */
	{"BQ3", 0x0, 0x0,  0},    /* 0x22 */
	{"BQ4", 0x0, 0x0,  0},    /* 0x23 */
	{"BQ5", 0x0, 0x0,  0},    /* 0x24 */
	{"BQ6", 0x0, 0x0,  0},    /* 0x25 */
	{"BQ7", 0x0, 0x0,  0},    /* 0x26 */
	{"BQ8", 0x0, 0x0,  0},    /* 0x27 */
	{"BQ9", 0x0, 0x0,  0},    /* 0x28 */
	{"BQ10", 0x0, 0x0,  0},    /* 0x29 */
	{"IIR4_S1", 0x0, 0x0,  0},    /* 0x2a */
	{"IIR4_S2", 0x0, 0x0,  0},    /* 0x2b */
	{"BE_BQ", 0x0, 0x0,  0},    /* 0x2c */
	{"Reserve", 0x0, 0x0,  0},    /* 0x2d */
	{"Reserve", 0x0, 0x0,  0},    /* 0x2e */
	{"Reserve", 0x0, 0x0,  0},    /* 0x2f */

	{"DRC_DAC_SEL", 0xff, 0xff,  0},  /* 0x30 */
	{"DRC_ADC_SEL", 0x3f, 0x3f,  0},  /* 0x31 */
	{"Reserve", 0x0, 0x0,  0},    /* 0x32 */
	{"Reserve", 0x0, 0x0,  0},    /* 0x33 */
	{"Reserve", 0x0, 0x0,  0},    /* 0x34 */
	{"Reserve", 0x0, 0x0,  0},    /* 0x35 */
	{"Reserve", 0x0, 0x0,  0},    /* 0x36 */
	{"Reserve", 0x0, 0x0,  0},    /* 0x37 */
	{"DAC_DRC1_COEFF_CTRL", 0x0, 0x0,  0},    /* 0x38 */
	{"DAC_DRC2_COEFF_CTRL", 0x0, 0x0,  0},    /* 0x39 */
	{"DAC_DRC3_COEFF_CTRL", 0x0, 0x0,  0},    /* 0x3a */
	{"DAC_DRC4_COEFF_CTRL", 0x0, 0x0,  0},    /* 0x3b */
	{"ADC_DRC1_COEFF_CTRL", 0x0, 0x0,  0},    /* 0x3c */
	{"ADC_DRC2_COEFF_CTRL", 0x0, 0x0,  0},    /* 0x3d */
	{"DRC_NG_CTRL", 0x0, 0x0,  0},    /* 0x3e */
	{"BE_GAIN/DRE", 0x0, 0x0,  0},    /* 0x3f (RT5511A) */

	{"DAC_DRC1_alpha", 0x0, 0x0,  0},    /* 0x40 */
	{"DAC_DRC2_alpha", 0x0, 0x0,  0},    /* 0x41 */
	{"DAC_DRC3_alpha", 0x0, 0x0,  0},    /* 0x42 */
	{"DAC_DRC4_alpha", 0x0, 0x0,  0},    /* 0x43 */
	{"ADC_DRC1_alpha", 0x0, 0x0,  0},    /* 0x44 */
	{"ADC_DRC2_alpha", 0x0, 0x0,  0},    /* 0x45 */
	{"MS_SYNC_SEL/AIF_TRI_STATE", 0x1f, 0x1f,  0},  /* 0x46 (RT5511A) */
	{"Reserve/NEW_CLK_RATE_CTRL", 0x0f, 0x0f,  0},    /* 0x47 (RT5511A) */
	{"Reserve", 0x0, 0x0,  0},    /* 0x48 */
	{"TDM_Debug", 0x03, 0x03,  0},    /* 0x49 (RT5511E)*/
	{"Reserve", 0x0, 0x0,  0},    /* 0x4a */
	{"Reserve", 0x0, 0x0,  0},    /* 0x4b */
	{"Reserve", 0x0, 0x0,  0},    /* 0x4c */
	{"Reserve", 0x0, 0x0,  0},    /* 0x4d */
	{"Reserve", 0x0, 0x0,  0},    /* 0x4e */
	{"Reserve", 0x0, 0x0,  0},    /* 0x4f */

	{"GPIO_CTRL1", 0x77, 0x77,  0},  /* 0x50 */
	{"GPIO_CTRL2", 0x77, 0x77,  0},  /* 0x51 */
	{"GPIO_CTRL3", 0x77, 0x77,  0},  /* 0x52 */
	{"SLIMBus_CTRL1/AUD3_FMT", 0x7f, 0x7f,  0},  /* 0x53 (RT5511A) */
	{"SLIMBus_CTRL2", 0x1f, 0x1f,  0},  /* 0x54 */
	{"PLL_N", 0x1fffffff, 0x1fffffff,  0},    /* 0x55 */
	{"PLL_BWCON", 0xff, 0xff,  0},  /* 0x56 */
	{"PLL_LPF", 0xff, 0xff,  0},  /* 0x57 */
	{"PLL_RSEL", 0xff, 0xff,  0},  /* 0x58 */
	{"PLL_LOCKDET", 0x0f, 0x00,  0},  /* 0x59 */
	{"DAC_DITHER", 0x1f, 0x1f,  0},  /* 0x5a */
	{"PLL_BW_RATIO", 0x3f, 0x3f,  0},  /* 0x5b */
	{"OC_OT_J_DET_EN", 0xff, 0xff,  0},  /* 0x5c */
	{"OC_OT_J_DET_Read", 0xff, 0x00,  0},  /* 0x5d */
	{"Reserve", 0x0, 0x0,  0},    /* 0x5e */
	{"Reserve", 0x0, 0x0,  0},    /* 0x5f */

	{"Reserve", 0x0, 0x0,  0},    /* 0x60 */
	{"Reserve", 0x0, 0x0,  0},    /* 0x61 */
	{"Reserve", 0x0, 0x0,  0},    /* 0x62 */
	{"Reserve", 0x0, 0x0,  0},    /* 0x63 */
	{"Reserve", 0x0, 0x0,  0},    /* 0x64 */
	{"Reserve", 0x0, 0x0,  0},    /* 0x65 */
	{"Reserve", 0x0, 0x0,  0},    /* 0x66 */
	{"Reserve", 0x0, 0x0,  0},    /* 0x67 */
	{"Reserve", 0x0, 0x0,  0},    /* 0x68 */
	{"Reserve", 0x0, 0x0,  0},    /* 0x69 */
	{"Reserve", 0x0, 0x0,  0},    /* 0x6a */
	{"Reserve", 0x0, 0x0,  0},    /* 0x6b */
	{"Reserve", 0x0, 0x0,  0},    /* 0x6c */
	{"Reserve", 0x0, 0x0,  0},    /* 0x6d */
	{"Reserve", 0x0, 0x0,  0},    /* 0x6e */
	{"Reserve", 0x0, 0x0,  0},    /* 0x6f */

	{"TESTMODE_EN", 0x00, 0xff,  0},  /* 0x70 */
	{"RAMBIST_REPORT_7_0", 0xff, 0x00,  0},  /* 0x71 */
	{"RAMBIST_REPORT_15_8", 0xff, 0x00,  0},  /* 0x72 */
	{"RAMBIST_CTRL", 0xe7, 0x80,  0},  /* 0x73 */
	{"SCAN_MODE_CTRL", 0x00, 0x80,  0},  /* 0x74 */
	{"CLOCK_Gating_CTRL", 0xff, 0xff,  0},  /* 0x75 */
	{"DSP_PATH_TEST_CTRL", 0xff, 0xff,  0},  /* 0x76 */
	{"ANA_DAC_CTRL", 0x7f, 0x7f,  0},  /* 0x77 */
	{"PAD_DRV", 0xff, 0xff,  0},  /* 0x78 */
	{"Reserve", 0x00, 0x00, 0},   /* 0x79 */
	{"SLIMBus_Report1", 0x03, 0x03,  0},  /* 0x7a */
	{"SLIMBus_Report2", 0xff, 0x00,  0},  /* 0x7b */
	{"SLIMBus_Report3", 0xff, 0x00,  0},  /* 0x7c */
	{"SLIMBus_Report4", 0xff, 0x00,  0},  /* 0x7d */
	{"SLIMBus_Report5", 0xff, 0x00,  0},  /* 0x7e */
	{"Reserve", 0x0, 0x00,  0},   /* 0x7f */

	{"SWReset_PowerDown", 0x41, 0xc1,  0},  /* 0x80 */
	{"BIASE_MIC_CTRL", 0xff, 0xff,  0},  /* 0x81 */
	{"MIX_EN_DAC_EN", 0xff, 0xff,  0},  /* 0x82 */
	{"SPK_HP_Driver", 0x9f, 0x9f,  0},  /* 0x83 */
	{"RCV_CTRL", 0xfb, 0xfb,  0},  /* 0x84 */
	{"ADC_MIC", 0xff, 0xff,  0},  /* 0x85 */
	{"MIX_PGA", 0xf3, 0xf3,  0},  /* 0x86 */
	{"HP_PGA_Vol", 0xff, 0xff,  0},  /* 0x87 */
	{"LHP_Mix_Vol", 0x1f, 0x1f,  0},  /* 0x88 */
	{"RHP_Mix_Vol", 0x1f, 0x1f, 0},   /* 0x89 */
	{"LHP_DRV_Vol", 0x0f, 0x0f,  0},  /* 0x8a */
	{"RHP_DRV_Vol", 0x0f, 0x0f,  0},  /* 0x8b */
	{"Mixer_Enable_CTRL", 0xff, 0xff,  0},  /* 0x8c */
	{"PGA2PGA_Mixer_Vol", 0xff, 0xff,  0},  /* 0x8d */
	{"LSPKPGA_Vol", 0x3f, 0x3f,  0},  /* 0x8e */
	{"RSPKPGA_Vol", 0x3f, 0x3f,  0},  /* 0x8f */

	{"SPK_BYPASS_BOOST", 0xbb, 0xbb,  0},  /* 0x90 */
	{"AUX_PGA_Vol", 0x1f, 0x1f,  0},  /* 0x91 */
	{"MIC1_CTRL", 0xdf, 0xdf,  0},  /* 0x92 */
	{"MIC2_CTRL", 0xdf, 0xdf,  0},  /* 0x93 */
	{"MIC3_CTRL", 0xdf, 0xdf,  0},  /* 0x94 */
	{"ANA_PATH_Mixer_CTRL_TO_PGA", 0xff, 0xff,  0},  /* 0x95 */
	{"ANA_PATH_Mixer_Vol_AUXL2LPGA_Vol", 0xff, 0xff,  0},  /* 0x96 */
	{"ANA_PATH_Mixer_Vol_AUXR2LPGA_Vol", 0xff, 0xff,  0},  /* 0x97 */
	{"BYPASS_SEL", 0x03, 0x03,  0},  /* 0x98 */
	{"ZC_RAMP_TIME", 0xff, 0xff, 0},   /* 0x99 */
	{"ZC_RAMP_TIME_EN", 0xf3, 0xf3,  0},  /* 0x9a */
	{"ZC_TIME_OUT_AUX_MIC", 0xff, 0xff,  0},  /* 0x9b */
	{"ZC_TIME_OUT_SPK_HP", 0xff, 0xff,  0},  /* 0x9c */
	{"MICBIAS1_LVL", 0x3f, 0x3f,  0},  /* 0x9d */
	{"MIC_LPM_CTRL", 0x8f, 0x8f,  0},  /* 0x9e */
	{"J_DET_SEL", 0xf7, 0xf7,  0},  /* 0x9f */

	{"HP_J_DET", 0xf7, 0x00,  0},  /* 0xa0 */
	{"IM_SENSE_CTRL1_TRIG", 0xff, 0xf8,  0},  /* 0xa1 */
	{"HPL_RAW", 0xff, 0x00,  0},  /* 0xa2 */
	{"HPR_RAW", 0xff, 0x00,  0},  /* 0xa3 */
	{"MIC_RAW", 0xff, 0x00,  0},  /* 0xa4 */
	{"MIC_TH1", 0xff, 0xff,  0},  /* 0xa5 */
	{"MIC_TH2", 0xff, 0xff,  0},  /* 0xa6 */
	{"MIC_TH3", 0xff, 0xff,  0},  /* 0xa7 */
	{"D_DIS_HPR2GND", 0xe0, 0xe0,  0},  /* 0xa8 */
	{"Reserve", 0x0, 0x0,  0},    /* 0xa9 */
	{"Reserve", 0x0, 0x0,  0},    /* 0xaa */
	{"Reserve", 0x0, 0x0,  0},    /* 0xab */
	{"Reserve", 0x0, 0x0,  0},    /* 0xac */
	{"Reserve", 0x0, 0x0,  0},    /* 0xad */
	{"Reserve", 0x0, 0x0,  0},    /* 0xae */
	{"Reserve", 0x0, 0x0,  0},    /* 0xaf */

	{"Reserve", 0x0, 0x0,  0},    /* 0xb0 */
	{"Reserve", 0x0, 0x0,  0},    /* 0xb1 */
	{"Reserve", 0x0, 0x0,  0},    /* 0xb2 */
	{"Reserve", 0x0, 0x0,  0},    /* 0xb3 */
	{"Reserve", 0x0, 0x0,  0},    /* 0xb4 */
	{"Reserve", 0x0, 0x0,  0},    /* 0xb5 */
	{"Reserve", 0x0, 0x0,  0},    /* 0xb6 */
	{"Reserve", 0x0, 0x0,  0},    /* 0xb7 */
	{"Reserve", 0xff, 0xff,  0},  /* 0xb8 */
	{"Reserve", 0xff, 0xff,  0},  /* 0xb9 */
	{"Reserve", 0x3f, 0x3f,  0},  /* 0xba */
	{"Reserve", 0xff, 0xff,  0},  /* 0xbb */
	{"Reserve", 0x9f, 0x9f,  0},  /* 0xbc */
	{"Reserve", 0xff, 0xff,  0},  /* 0xbd */
	{"Reserve", 0xbf, 0x3f,  0},  /* 0xbe */
	{"Reserve", 0xfe, 0xfe,  0},  /* 0xbf */

	{"HP_OUT_EN_CTRL", 0xff, 0xff,  0},  /* 0xc0 */
	{"LHP_DC_CNT", 0xff, 0x00,  0},  /* 0xc1 */
	{"RHP_DC_CNT", 0xff, 0x00,  0},  /* 0xc2 */
	{"SPK_Servo_D_LSPKABVCM_FC", 0x77, 0x77,  0},  /* 0xc3 */
	{"LSPK_DC_CNT", 0xff, 0x00,  0},  /* 0xc4 */
	{"RSPK_DC_CNT", 0xff, 0x00,  0},  /* 0xc5 */
	{"RCV_DC_Servo_EN", 0x1f, 0x1f,  0},  /* 0xc6 */
	{"RCV_DC_CNT", 0xff, 0x00,  0},  /* 0xc7 */
	{"DC_Servo_Busy_Report", 0x1f, 0x00,  0},  /* 0xc8 */
	{"SPK_LSPK_GAIN_CTRL", 0xff, 0xff,  0},  /* 0xc9 */
	{"D_CP_AUTO_EN", 0x77, 0x77,  0},  /* 0xca */
	{"D_CP_FREQ", 0xff, 0xff,  0},  /* 0xcb */
	{"D_AMPDET_FREQ", 0xcf, 0xcf,  0},  /* 0xcc */
	{"D_AMPDET_VTH", 0xff, 0xf8,  0},  /* 0xcd */
	{"IMS_IMSNS_AVG", 0xff, 0xff,  0},  /* 0xce */
	{"IMS_D_IMG_EN", 0x9f, 0x9f,  0},  /* 0xcf */

	{"IM_ADC_D_IMADC_IBSEL", 0xff, 0xff,  0},  /* 0xd0 */
	{"Reserve", 0x0, 0x0,  0},    /* 0xd1 */
	{"Reserve", 0x0, 0x0,  0},    /* 0xd2 */
	{"Reserve", 0x0, 0x0,  0},    /* 0xd3 */
	{"Reserve", 0x0, 0x0,  0},    /* 0xd4 */
	{"Reserve", 0x0, 0x0,  0},    /* 0xd5 */
	{"Reserve", 0x0, 0x0,  0},    /* 0xd6 */
	{"Reserve", 0x0, 0x0,  0},    /* 0xd7 */
	{"Reserve", 0x0, 0x0,  0},    /* 0xd8 */
	{"Reserve", 0x0, 0x0,  0},    /* 0xd9 */
	{"Reserve", 0x0, 0x0,  0},    /* 0xda */
	{"Reserve", 0x0, 0x0,  0},    /* 0xdb */
	{"Reserve", 0x0, 0x0,  0},    /* 0xdc */
	{"Reserve", 0x0, 0x00, 0},    /* 0xdd */
	{"Reserve", 0x0, 0x0,  0},    /* 0xde */
	{"Reserve", 0x0, 0x0,  0},    /* 0xdf */

	{"D_HP_IBSEL", 0xff, 0xff,  0},  /* 0xe0 */
	{"D_RCV_IBSEL", 0xff, 0xff,  0},  /* 0xe1 */
	{"D_SPK_IBSEL", 0xff, 0xff,  0},  /* 0xe2 */
	{"D_CLASSD_SR_SEL", 0xff, 0xff,  0},  /* 0xe3 */
	{"D_HPDAC_CHP_EN", 0xff, 0xff,  0},  /* 0xe4 */
	{"D_IMADC_CHP_EN", 0x77, 0x77,  0},  /* 0xe5 */
	{"D_INT1_IBSEL", 0x3f, 0x3f,  0},  /* 0xe6 */
	{"D_MICLDO_IBSEL", 0xff, 0xff,  0},  /* 0xe7 */
	{"D_ADCPGA_IBSEL", 0xff, 0xff,  0},  /* 0xe8 */
	{"D_HPMIX_IBSEL", 0xff, 0xff,  0},  /* 0xe9 */
	{"D_CLASSD_2ND_IBSEL", 0xff, 0xff,  0},  /* 0xea */
	{"D_VREF_LDO_EN", 0xbd, 0xbd,  0},  /* 0xeb */
	{"OC_OT_CTRL", 0xcf, 0xcf,  0},  /* 0xec */
	{"Reserve", 0x0, 0x00, 0},    /* 0xed */
	{"Reserve", 0x0, 0x0,  0},    /* 0xee */
	{"Reserve", 0x0, 0x0,  0},    /* 0xef */

	{"Reserve", 0x0, 0x0,  0},    /* 0xf0 */
	{"Reserve", 0x0, 0x0,  0},    /* 0xf1 */
	{"Reserve", 0x0, 0x0,  0},    /* 0xf2 */
	{"Reserve", 0x0, 0x0,  0},    /* 0xf3 */
	{"Reserve", 0x0, 0x0,  0},    /* 0xf4 */
	{"Reserve", 0x0, 0x0,  0},    /* 0xf5 */
	{"Reserve", 0x0, 0x0,  0},    /* 0xf6 */
	{"Reserve", 0x0, 0x0,  0},    /* 0xf7 */
	{"Reserve", 0x0, 0x0,  0},    /* 0xf8 */
	{"Reserve", 0x0, 0x0,  0},    /* 0xf9 */
	{"Reserve", 0x0, 0x0,  0},    /* 0xfa */
	{"Reserve", 0x0, 0x0,  0},    /* 0xfb */
	{"Reserve", 0x0, 0x0,  0},    /* 0xfc */
	{"Reserve", 0x0, 0x0,  0},    /* 0xfd */
	{"Reserve", 0x0, 0x0,  0},    /* 0xfe */
	{"Reserve", 0x0, 0x0,  0},    /* 0xff */
};

const u32 rt5511_reg_defaults[RT5511_CACHE_SIZE] = {
	0x0, /* ID must get from */
	0x0,
	0x0,  /* 0x02 */
	0x75, /* 0x03 */
	0x75, /* 0x04 */
	0x0,  /* 0x05 */
	0x30, /* 0x06 */
	0xef, /* 0x07 */
	0x00C000C0,  /* 0x08 */
	0x00C000C0,  /* 0x09 */
	0x00C000C0,  /* 0x0a */
	0x00C000C0,  /* 0x0b */
	0x00C000C0,  /* 0x0c */
	0x00C000C0,  /* 0x0d */
	0x00C000C0,  /* 0x0e */
	0x0,  /* 0x0f */

	0xc0, /* 0x10 */
	0xc0, /* 0x11 */
	0xc0, /* 0x12 */
	0xc0, /* 0x13 */
	0x00, /* 0x14 */
	0x0,  /* 0x15 */
	0x0e, /* 0x16 */
	0x0,  /* 0x17 */
	0x0,  /* 0x18 */
	0x04,  /* 0x19 */
	0x10, /* 0x1a */
	0x05,  /* 0x1b */
	0x0,  /* 0x1c */
	0x0,  /* 0x1d */
	0x0,  /* 0x1e */
	0x0,  /* 0x1f */

	0x0,  /* 0x20 */
	0x0,  /* 0x21 */
	0x0,  /* 0x22 */
	0x0,  /* 0x23 */
	0x0,  /* 0x24 */
	0x0,  /* 0x25 */
	0x0,  /* 0x26 */
	0x0,  /* 0x27 */
	0x0,  /* 0x28 */
	0x0,  /* 0x29 */
	0x0,  /* 0x2a */
	0x0,  /* 0x2b */
	0x0,  /* 0x2c */
	0x0,  /* 0x2d */
	0x0,  /* 0x2e */
	0x0,  /* 0x2f */

	0x0,  /* 0x30 */
	0x0,  /* 0x31 */
	0x0,  /* 0x32 */
	0x0,  /* 0x33 */
	0x0,  /* 0x34 */
	0x0,  /* 0x35 */
	0x0,  /* 0x36 */
	0x0,  /* 0x37 */
	0x0,  /* 0x38 */
	0x0,  /* 0x39 */
	0x0,  /* 0x3a */
	0x0,  /* 0x3b */
	0x0,  /* 0x3c */
	0x0,  /* 0x3d */
	0x0,  /* 0x3e */
	0x0,  /* 0x3f */

	0x0,  /* 0x40 */
	0x0,  /* 0x41 */
	0x0,  /* 0x42 */
	0x0,  /* 0x43 */
	0x0,  /* 0x44 */
	0x0,  /* 0x45 */
	0x0,  /* 0x46 */
	0x0,  /* 0x47 */
	0x0,  /* 0x48 */
	0x0,  /* 0x49 */
	0x0,  /* 0x4a */
	0x0,  /* 0x4b */
	0x0,  /* 0x4c */
	0x0,  /* 0x4d */
	0x0,  /* 0x4e */
	0x0,  /* 0x4f */

	0x0,  /* 0x50 */
	0x0,  /* 0x51 */
	0x0,  /* 0x52 */
	0x0,  /* 0x53 */
	0x0,  /* 0x54 */
	0x00020000,  /* 0x55 */
	0xa5, /* 0x56 */
	0x0,  /* 0x57 */
	0x0,  /* 0x58 */
	0x0,  /* 0x59 */
	0x0,  /* 0x5a */
	0x1c, /* 0x5b */
	0xfc, /* 0x5c */
	0x04, /* 0x5d */
	0x0,  /* 0x5e */
	0x0,  /* 0x5f */

	0x0,  /* 0x60 */
	0x0,  /* 0x61 */
	0x0,  /* 0x62 */
	0x0,  /* 0x63 */
	0x0,  /* 0x64 */
	0x0,  /* 0x65 */
	0x0,  /* 0x66 */
	0x0,  /* 0x67 */
	0x0,  /* 0x68 */
	0x0,  /* 0x69 */
	0x0,  /* 0x6a */
	0x0,  /* 0x6b */
	0x0,  /* 0x6c */
	0x0,  /* 0x6d */
	0x0,  /* 0x6e */
	0x0,  /* 0x6f */

	0x0,  /* 0x70 */
	0x0,  /* 0x71 */
	0x0,  /* 0x72 */
	0x0,  /* 0x73 */
	0x0,  /* 0x74 */
	0xff, /* 0x75 */
	0x0,  /* 0x76 */
	0x0,  /* 0x77 */
	0x0,  /* 0x78 */
	0x0,  /* 0x79 */
	0x0,  /* 0x7a */
	0x0,  /* 0x7b */
	0x0,  /* 0x7c */
	0x0,  /* 0x7d */
	0x0,  /* 0x7e */
	0x0,  /* 0x7f */

	0x0,  /* 0x80 */
	0x44, /* 0x81 (different with datasheet; disable bit1 by MFD driver) */
	0x0,  /* 0x82 */
	0x0,  /* 0x83 */
	0x08, /* 0x84 */
	0x0,  /* 0x85 */
	0x0,  /* 0x86 */
	0xaa, /* 0x87 */
	0x1f, /* 0x88 */
	0x1f, /* 0x89 */
	0x0c, /* 0x8a */
	0x0c, /* 0x8b */
	0x0,  /* 0x8c */
	0xaa, /* 0x8d */
	0x2c, /* 0x8e */
	0x2c, /* 0x8f */

	0x0,  /* 0x90 */
	0x0b, /* 0x91 */
	0x0b, /* 0x92 */
	0x0b, /* 0x93 */
	0x0b, /* 0x94 */
	0x0,  /* 0x95 */
	0x40, /* 0x96 */
	0x40, /* 0x97 */
	0x0,  /* 0x98 */
	0xf0, /* 0x99 */
	0x03, /* 0x9a */
	0xcc, /* 0x9b */
	0xcc, /* 0x9c */
	0x15, /* 0x9d */
	0x80, /* 0x9e */
	0x40, /* 0x9f */

	0xc0, /* 0xa0 */
	0x0,  /* 0xa1 */
	0x0,  /* 0xa2 */
	0x0,  /* 0xa3 */
	0x0,  /* 0xa4 */
	0x40, /* 0xa5 */
	0x80, /* 0xa6 */
	0xc0, /* 0xa7 */
	0x80, /* 0xa8 */
	0x0,  /* 0xa9 */
	0x0,  /* 0xaa */
	0x0,  /* 0xab */
	0x0,  /* 0xac */
	0x0,  /* 0xad */
	0x0,  /* 0xae */
	0x0,  /* 0xaf */

	0x0,  /* 0xb0 */
	0x0,  /* 0xb1 */
	0x0,  /* 0xb2 */
	0x0,  /* 0xb3 */
	0x0,  /* 0xb4 */
	0x0,  /* 0xb5 */
	0x0,  /* 0xb6 */
	0x0,  /* 0xb7 */
	0x0,  /* 0xb8 */
	0x0,  /* 0xb9 */
	0x0,  /* 0xba */
	0x0,  /* 0xbb */
	0x0,  /* 0xbc */
	0x0,  /* 0xbd */
	0x0,  /* 0xbe */
	0x0,  /* 0xbf */

	0x00, /* 0xc0 */
	0xff, /* 0xc1 */
	0xff, /* 0xc2 */
	0x00, /* 0xc3 */
	0xff, /* 0xc4 */
	0xff, /* 0xc5 */
	0x10, /* 0xc6 */
	0xff, /* 0xc7 */
	0x00, /* 0xc8 */
	0xdd, /* 0xc9 */
	0x70, /* 0xca */
	0xa5, /* 0xcb */
	0x84, /* 0xcc */
	0x50, /* 0xcd */
	0x60, /* 0xce */
	0x00, /* 0xcf */

	0x90, /* 0xd0 */
	0x0,  /* 0xd1 */
	0x0,  /* 0xd2 */
	0x0,  /* 0xd3 */
	0x0,  /* 0xd4 */
	0x0,  /* 0xd5 */
	0x0,  /* 0xd6 */
	0x0,  /* 0xd7 */
	0x0,  /* 0xd8 */
	0x0,  /* 0xd9 */
	0x0,  /* 0xda */
	0x0,  /* 0xdb */
	0x0,  /* 0xdc */
	0x0,  /* 0xdd */
	0x0,  /* 0xde */
	0x0,  /* 0xdf */

	0x6c, /* 0xe0 */
	0xa1, /* 0xe1 */
	0x91, /* 0xe2 */
	0x15, /* 0xe3 */
	0x33, /* 0xe4 */
	0x13, /* 0xe5 */
	0x2a, /* 0xe6 */
	0x6a, /* 0xe7 */
	0x5f, /* 0xe8 */
	0x55, /* 0xe9 */
	0xa5, /* 0xea */
	0x94, /* 0xeb */
	0x04, /* 0xec */
	0x0,  /* 0xed */
	0x0,  /* 0xee */
	0x0,  /* 0xef */

	0x0,  /* 0xf0 */
	0x01, /* 0xf1 */
	0x0,  /* 0xf2 */
	0x0,  /* 0xf3 */
	0x0,  /* 0xf4 */
	0x0,  /* 0xf5 */
	0x0,  /* 0xf6 */
	0x0,  /* 0xf7 */
	0x0,  /* 0xf8 */
	0x0,  /* 0xf9 */
	0x0,  /* 0xfa */
	0x0,  /* 0xfb */
	0x0,  /* 0xfc */
	0x0,  /* 0xfd */
	0x0,  /* 0xfe */
	0x0,  /* 0xff */
};

const int rt5511_reg_size[RT5511_CACHE_SIZE] = {
	/* 0 : not exist, otherwise : size */
	1, /* 0x00 */
	1, /* 0x01 */
	1, /* 0x02 */
	1, /* 0x03 */
	1, /* 0x04 */
	1, /* 0x05 */
	1, /* 0x06 */
	1, /* 0x07 */
	4, /* 0x08 */
	4, /* 0x09 */
	4, /* 0x0a */
	4, /* 0x0b */
	4, /* 0x0c */
	4, /* 0x0d */
	4, /* 0x0e */
	4, /* 0x0f */

	1, /* 0x10 */
	1, /* 0x11 */
	1, /* 0x12 */
	1, /* 0x13 */
	1, /* 0x14 */
	1, /* 0x15 */
	1, /* 0x16 */
	1, /* 0x17 */
	1, /* 0x18 */
	1, /* 0x19 */
	1, /* 0x1a */
	1, /* 0x1b */
	1, /* 0x1c */
	4, /* 0x1d */
	0, /* 0x1e */
	1, /* 0x1f */

	20,/* 0x20 */
	20,/* 0x21 */
	20,/* 0x22 */
	20,/* 0x23 */
	20,/* 0x24 */
	20,/* 0x25 */
	20,/* 0x26 */
	20,/* 0x27 */
	20,/* 0x28 */
	20,/* 0x29 */
	20,/* 0x2a */
	20,/* 0x2b */
	20,/* 0x2c */
	0, /* 0x2d */
	0, /* 0x2e */
	0, /* 0x2f */

	1, /* 0x30 */
	1, /* 0x31 */
	0, /* 0x32 */
	0, /* 0x33 */
	0, /* 0x34 */
	0, /* 0x35 */
	0, /* 0x36 */
	0, /* 0x37 */
	8, /* 0x38 */
	8, /* 0x39 */
	8, /* 0x3a */
	8, /* 0x3b */
	8, /* 0x3c */
	8, /* 0x3d */
	8, /* 0x3e */
	8, /* 0x3f */

	16,/* 0x40 */
	16,/* 0x41 */
	16,/* 0x42 */
	16,/* 0x43 */
	16,/* 0x44 */
	16,/* 0x45 */
	1, /* 0x46 */
	1, /* 0x47 (RT5511A) */
	0, /* 0x48 */
	1, /* 0x49 (RT5511E) */
	0, /* 0x4a */
	0, /* 0x4b */
	0, /* 0x4c */
	0, /* 0x4d */
	0, /* 0x4e */
	0, /* 0x4f */

	1, /* 0x50 */
	1, /* 0x51 */
	1, /* 0x52 */
	1, /* 0x53 */
	1, /* 0x54 */
	4, /* 0x55 */
	1, /* 0x56 */
	1, /* 0x57 */
	1, /* 0x58 */
	1, /* 0x59 */
	1, /* 0x5a */
	1, /* 0x5b */
	1, /* 0x5c */
	1, /* 0x5d */
	0, /* 0x5e */
	0, /* 0x5f */

	0, /* 0x60 */
	0, /* 0x61 */
	0, /* 0x62 */
	0, /* 0x63 */
	0, /* 0x64 */
	0, /* 0x65 */
	0, /* 0x66 */
	0, /* 0x67 */
	0, /* 0x68 */
	0, /* 0x69 */
	0, /* 0x6a */
	0, /* 0x6b */
	0, /* 0x6c */
	0, /* 0x6d */
	0, /* 0x6e */
	0, /* 0x6f */

	1, /* 0x70 */
	1, /* 0x71 */
	1, /* 0x72 */
	1, /* 0x73 */
	1, /* 0x74 */
	1, /* 0x75 */
	1, /* 0x76 */
	1, /* 0x77 */
	1, /* 0x78 */
	0, /* 0x79 */
	1, /* 0x7a */
	1, /* 0x7b */
	1, /* 0x7c */
	1, /* 0x7d */
	1, /* 0x7e */
	0, /* 0x7f */

	1, /* 0x80 */
	1, /* 0x81 */
	1, /* 0x82 */
	1, /* 0x83 */
	1, /* 0x84 */
	1, /* 0x85 */
	1, /* 0x86 */
	1, /* 0x87 */
	1, /* 0x88 */
	1, /* 0x89 */
	1, /* 0x8a */
	1, /* 0x8b */
	1, /* 0x8c */
	1, /* 0x8d */
	1, /* 0x8e */
	1, /* 0x8f */

	1, /* 0x90 */
	1, /* 0x91 */
	1, /* 0x92 */
	1, /* 0x93 */
	1, /* 0x94 */
	1, /* 0x95 */
	1, /* 0x96 */
	1, /* 0x97 */
	1, /* 0x98 */
	1, /* 0x99 */
	1, /* 0x9a */
	1, /* 0x9b */
	1, /* 0x9c */
	1, /* 0x9d */
	1, /* 0x9e */
	1, /* 0x9f */

	1, /* 0xa0 */
	1, /* 0xa1 */
	1, /* 0xa2 */
	1, /* 0xa3 */
	1, /* 0xa4 */
	1, /* 0xa5 */
	1, /* 0xa6 */
	1, /* 0xa7 */
	1, /* 0xa8 */
	0, /* 0xa9 */
	0, /* 0xaa */
	0, /* 0xab */
	0, /* 0xac */
	0, /* 0xad */
	0, /* 0xae */
	0, /* 0xaf */

	0, /* 0xb0 */
	0, /* 0xb1 */
	0, /* 0xb2 */
	0, /* 0xb3 */
	0, /* 0xb4 */
	0, /* 0xb5 */
	0, /* 0xb6 */
	0, /* 0xb7 */
	1, /* 0xb8 */
	1, /* 0xb9 */
	1, /* 0xba */
	1, /* 0xbb */
	1, /* 0xbc */
	1, /* 0xbd */
	1, /* 0xbe */
	1, /* 0xbf */

	1, /* 0xc0 */
	1, /* 0xc1 */
	1, /* 0xc2 */
	1, /* 0xc3 */
	1, /* 0xc4 */
	1, /* 0xc5 */
	1, /* 0xc6 */
	1, /* 0xc7 */
	1, /* 0xc8 */
	1, /* 0xc9 */
	1, /* 0xca */
	1, /* 0xcb */
	1, /* 0xcc */
	1, /* 0xcd */
	1, /* 0xce */
	1, /* 0xcf */

	1, /* 0xd0 */
	0, /* 0xd1 */
	0, /* 0xd2 */
	0, /* 0xd3 */
	0, /* 0xd4 */
	0, /* 0xd5 */
	0, /* 0xd6 */
	0, /* 0xd7 */
	0, /* 0xd8 */
	0, /* 0xd9 */
	0, /* 0xda */
	0, /* 0xdb */
	0, /* 0xdc */
	0, /* 0xdd */
	0, /* 0xde */
	0, /* 0xdf */

	1, /* 0xe0 */
	1, /* 0xe1 */
	1, /* 0xe2 */
	1, /* 0xe3 */
	1, /* 0xe4 */
	1, /* 0xe5 */
	1, /* 0xe6 */
	1, /* 0xe7 */
	1, /* 0xe8 */
	1, /* 0xe9 */
	1, /* 0xea */
	1, /* 0xeb */
	1, /* 0xec */
	0, /* 0xed */
	0, /* 0xee */
	0, /* 0xef */

	0, /* 0xf0 */
	0, /* 0xf1 */
	0, /* 0xf2 */
	0, /* 0xf3 */
	0, /* 0xf4 */
	0, /* 0xf5 */
	0, /* 0xf6 */
	0, /* 0xf7 */
	1, /* 0xf8 (virt_ctrl) */
	0, /* 0xf9 */
	0, /* 0xfa */
	0, /* 0xfb */
	0, /* 0xfc */
	0, /* 0xfd */
	0, /* 0xfe */
	0, /* 0xff */
};


u32 rt5511_reg_cache[RT5511_CACHE_SIZE];

void rt5511_init_cache(void)
{
	memcpy(rt5511_reg_cache, rt5511_reg_defaults, sizeof(rt5511_reg_cache));
}

int rt5511_reg_cache_sync(struct snd_soc_codec *codec)
{
	struct rt5511_priv *rt5511 = snd_soc_codec_get_drvdata(codec);
	int ret, i, size;

	for (i = 0; i < RT5511_CACHE_SIZE; i++) {
		size = rt5511_reg_size[i];
		if (i == RT5511E_TDM_DEBUG) {
			if (rt5511->revision < RT5511_VID_5511E)
				continue;
		}

		if (size != 0 &&
		    rt5511_access_masks[i].is_volatile == 0) {
			if (rt5511_reg_cache[i] != rt5511_reg_defaults[i]) {
				ret = rt5511_reg_write(codec->control_data,
					i, rt5511_reg_cache[i], size);
				if (ret < 0) {
					dev_err(rt5511->codec->dev,
						"Write 0x%x to Reg[0x%x] failed: %d\n",
						rt5511_reg_cache[i], i, ret);
				}
			}
		}
	}
	return 0;

}
