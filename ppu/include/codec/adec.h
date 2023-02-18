#pragma once

#include <ppu-types.h>
#include <spurs/types.h>
#include <codec/types.h>

#define ADEC_ERROR_FATAL				0x80610001
#define ADEC_ERROR_SEQ					0x80610002
#define ADEC_ERROR_ARG					0x80610003
#define ADEC_ERROR_BUSY					0x80610004
#define ADEC_ERROR_EMPTY				0x80610005

#define ADEC_TYPE_RESERVED1				0
#define ADEC_TYPE_LPCM_PAMF				1
#define ADEC_TYPE_AC3					2
#define ADEC_TYPE_ATRACX				3
#define ADEC_TYPE_MP3					4
#define ADEC_TYPE_ATRAC3				5
#define ADEC_TYPE_MPEG_L2				6
#define ADEC_TYPE_M2AAC					7
#define ADEC_TYPE_EAC3					8
#define ADEC_TYPE_TRUEHD				9
#define ADEC_TYPE_RESERVED8				10
#define ADEC_TYPE_CELP					11
#define ADEC_TYPE_RESERVED10			12 // ???
#define ADEC_TYPE_ATRACX_2CH			13
#define ADEC_TYPE_ATRACX_6CH			14
#define ADEC_TYPE_ATRACX_8CH			15
#define ADEC_TYPE_M4AAC					16
#define ADEC_TYPE_RESERVED12			17 // ???
#define ADEC_TYPE_WMA					18
#define ADEC_TYPE_DTSLBR				19
#define ADEC_TYPE_RESERVED15			20
#define ADEC_TYPE_DTSHD					21
#define ADEC_TYPE_RESERVED17			22 // "MPL1"
#define ADEC_TYPE_MP3S					23
#define ADEC_TYPE_RESERVED19			24
#define ADEC_TYPE_CELP8					25
#define ADEC_TYPE_RESERVED20			26
#define ADEC_TYPE_RESERVED21			27
#define ADEC_TYPE_RESERVED22			28
#define ADEC_TYPE_RESERVED23			29
#define ADEC_TYPE_RESERVED24			30
#define ADEC_TYPE_RESERVED25			31

#define ADEC_CH_RESERVED1				0
#define ADEC_CH_MONO					1
#define ADEC_CH_RESERVED2				2
#define ADEC_CH_STEREO					3
#define ADEC_CH_3_0						4
#define ADEC_CH_2_1						5
#define ADEC_CH_3_1						6
#define ADEC_CH_2_2						7
#define ADEC_CH_3_2						8
#define ADEC_CH_3_2_LFE					9
#define ADEC_CH_3_4						10
#define ADEC_CH_3_4_LFE					11
#define ADEC_CH_RESERVED3				12

#define ADEC_FS_RESERVED1				0
#define ADEC_FS_48kHz					1
#define ADEC_FS_16kHz					2
#define ADEC_FS_8kHz					5

#define ADEC_BIT_LENGTH_RESERVED1		0
#define ADEC_BIT_LENGTH_16				1
#define ADEC_BIT_LENGTH_20				2
#define ADEC_BIT_LENGTH_24				3

#define ADEC_CALLBACK_AUDONE			0
#define ADEC_CALLBACK_PCMOUT			1
#define ADEC_CALLBACK_ERROR				2
#define ADEC_CALLBACK_SEQDONE			3

#ifdef __cplusplus
extern "C" {
#endif

typedef void* adecHandle ATTRIBUTE_PRXPTR;

typedef s32(*adecCallbackMsg)(adecHandle handle, u32 msgType, s32 msgData, void *callbackArg) ATTRIBUTE_PRXPTR;

typedef struct _adec_type
{
	u32 codec_type;
} adecType;

typedef struct _adec_attr
{
	u32 mem_size;
	u32 ver_major;
	u32 ver_minor;
} adecAttr;

typedef struct _adec_callback
{
	adecCallbackMsg fn;
	void *arg ATTRIBUTE_PRXPTR;
} adecCallback;

typedef struct _adec_resource
{
	u32 total_mem_size;
	void *start_addr ATTRIBUTE_PRXPTR;
	u32 ppu_thread_prio;
	u32 spu_thread_prio;
	u32 ppu_thread_stack_size;
} adecResource;

typedef struct _adec_resource_ex
{
	u32 total_mem_size;
	void *start_addr ATTRIBUTE_PRXPTR;
	u32 ppu_thread_prio;
	u32 ppu_thread_stack_size;
	Spurs *spurs ATTRIBUTE_PRXPTR;
	u8 prio[8];
	u32 max_contention;
} adecResourceEx;

typedef struct _adec_param_lpcm
{
	u32 channel_number;
	u32 sample_rate;
	u32 size_of_word;
	u32 audio_payload_size;
} adecParamLpcm;

typedef struct _adec_param_ac3
{
	s8 word_size;
	s8 output_mode;
	s8 out_lfe_on;
	f32 drc_cut_scale_factor;
	f32 drc_boost_scale_factor;
	s8 compression_mode;
	s8 number_of_channels;
	s8 stereo_mode;
	s8 dualmono_mode;
	s8 karaoke_capable_mode;
	f32 pcm_scale_factor;
	s32 channel_pointer0;
	s32 channel_pointer1;
	s32 channel_pointer2;
	s32 channel_pointer3;
	s32 channel_pointer4;
	s32 channel_pointer5;
} adecParamAc3;

typedef struct _adec_param_eac3
{
	s32 wordSize; // 0, 2 or 17 to 24
	s8 karaokeCapableMode;  // 0 to 3
	s8 compressionMode;  // 0 to 3
	s8 outLfeOn;  // 0 to 2
	s8 outputMode;  // -1 or 1 to 22
	s8 numberOfChannels;  // 1 to 8
	f32 pcmScaleFactor; // 0.0f to 1.0f
	s8 unk_0x10;  // 0 or not 0      // default: 1
	s8 stereoMode;  // 0 to 2
	s8 dualmonoMode;  // 0 to 3
	f32 drcCutScaleFactor; // 0.0f to 1.0f
	f32 drcBoostScaleFactor; // 0.0f to 1.0f
	s32 channel_pointer0; // -1 to 8
	s32 channel_pointer1; // -1 to 8
	s32 channel_pointer2; // -1 to 8
	s32 channel_pointer3; // -1 to 8
	s32 channel_pointer4; // -1 to 8
	s32 channel_pointer5; // -1 to 8
	s32 channel_pointer6; // -1 to 8
	s32 channel_pointer7; // -1 to 8
	// ...?
} adecParamEac3;

typedef struct _adec_param_truehd
{
	u32 outputMode; // 0 to 2
	u32 unk_0x04; // 0 or 1
	u32 unk_0x08; // 0 to 2 // drc mode, 2: on
	u32 drcBoostScalePercent; // 0 to 100
	u32 drcCutScalePercent; // 0 to 100
	u32 unk_0x14; // ???
	u32 unk_0x18; // ????????????????????
	u32 wordSize; // 0 or 1
	u32 unk_0x20; // 0 or 1, if 0x1c == 0 ignored
	u32 unk_0x24; // ???
	// ...?
} adecParamTruehd;

typedef struct _adec_param_atrac3
{
	s32 nch;
	s32 is_joint;
	s32 nbytes;
	s32 bw_pcm;
} adecParamAtrac3;

typedef struct _adec_param_atracx
{
	s32 sampling_freq;
	s32 ch_config_idx;
	s32 nch_out;
	s32 nbytes;
	u8 extra_config_data[4];
	s32 bw_pcm;
	u8 downmix_flag;
	u8 au_includes_ats_hdr_flg;
} adecParamAtracX;

typedef struct _adec_param_mp3
{
	s32 bw_pcm;
} adecParamMp3;

typedef struct _adec_param_mpmc
{
	u32 channel_number;
	u32 downmix;
	u32 lfe_up_sample;
} adecParamMpmc;

typedef struct _adec_param_celp
{
	u32 excitation_mode;
	u32 sample_rate;
	u32 configuration;
	u32 word_size;
} adecParamCelp;

typedef struct _adec_param_m4aac
{
	u32 config_number;
	union
	{
		struct
		{
			u32 program_number;
		} adifConfig;
		struct
		{
			u32 sampling_freq_index;
			u32 profile;
		} rawDataBlockConfig;
	} configInfo;
	u32 enable_downmix;
} adecParamM4Aac;

typedef struct _adec_param_celp8
{
	u32 excitation_mode;
	u32 sample_rate;
	u32 configuration;
	u32 word_size;
} adecParamCelp8;

// Undocumented codecs
// ...
// ...

typedef struct _adec_au_info
{
	void *start_addr ATTRIBUTE_PRXPTR;
	u32 size;
	CodecTimeStamp pts;
	u32 truehd_user_data;
	u32 celp_user_data;
} adecAuInfo;

typedef struct _adec_pcm_attr
{
	void *bsi_info ATTRIBUTE_PRXPTR;
} adecPcmAttr;

typedef struct _adec_pcm_item
{
	u32 pcm_handle;
	u32 status;
	void *start_addr ATTRIBUTE_PRXPTR;
	u32 size;
	adecPcmAttr pcm_attr;
	adecAuInfo au_info;
} adecPcmItem;

typedef struct _adec_lpcm_info
{
	u32 channel_number;
	u32 sample_rate;
	u32 output_data_size;
} adecLpcmInfo;

typedef struct _adec_bsi_ac3
{
	u32 codec_type;
	u32 version_info;
	u32 total_call_carry_run;
	u32 total_call_num;
	u32 bitrate_value;
	u32 pcm_size;
	u32 es_size_bit;
	s32 error_code;
	u8 lib_info_flag;
	u8 validity;
	u8 channel_value;
	u8 fs_index;
	u8 output_quantization;
	u8 output_channel;
	u8 mono_flag;
	u32 bsi[2];
	u16 frm_size_cod;
	u8 acmod;
	u8 lfe_on;
	u8 karaoke_mode;
	u8 cmixlev;
	u8 surmixlev;
	u8 dsurmod;
	u8 copyright;
	u8 original;
	u8 bsmod;
	u8 bsid;
	u8 xbsi1e;
	u8 dmixmod;
	u8 xbsi2e;
	u8 dsurexmod;
	u8 dheadphonmod;
	u8 adconvtyp;
	u8 crc_error_flag;
	u8 exec_dmix_type;
} adecBsiAc3;

typedef struct _adec_atrac3_info
{
	s32 nch;
	s32 is_joint;
	s32 nbytes;
} adecAtrac3Info;

typedef struct _adec_atracx_info
{
	u32 sampling_freq;
	u32 channel_config_index;
	u32 nbytes;
} adecAtracXInfo;

typedef struct _adec_mp3_info
{
	vu32 ui_header;
	vu32 ui_main_data_begin;
	vu32 ui_main_data_remain_size;
	vu32 ui_main_data_now_size;
	vu8 uc_crc;
	vu8 uc_mode;
	vu8 uc_mode_extension;
	vu8 uc_copyright;
	vu8 uc_original;
	vu8 uc_emphasis;
	vu8 uc_crc_error_flag;
	vu32 i_error_code;
} adecMp3Info;

typedef struct _adec_mpmc_info
{
	u32 channel_number;
	u32 sample_freq;
	u32 error_protection;
	u32 bitrate_index;
	u32 stereo_mode;
	u32 stereo_mode_extension;
	u32 emphasis;
	u32 copyright;
	u32 original;
	u32 surround_mode;
	u32 center_mode;
	u32 audio_mix;
	u32 output_frame_size;
	u32 multi_codec_mode;
	u32 lfe_present;
	u32 channel_configuration;
} adecMpmcInfo;

typedef struct _adec_celp_info
{
	u32 excitation_mode;
	u32 sample_rate;
	u32 configuration;
	u32 word_size;
} adecCelpInfo;

typedef struct _adec_m4aac_info
{
	u32 sampling_freq;
	u32 number_of_channels;
	u32 number_of_front_channels;
	u32 number_of_front_mono_channels;
	u32 number_of_side_channels;
	u32 number_of_back_channels;
	u32 number_of_lfe_channels;
	u32 enable_sbr;
	u32 sbr_upsampling_factor;
	u32 is_bsi_valid;
	u32 config_number;
	union
	{
		struct
		{
			u32 copyright_id_present;
			char copyright_id[9];
			u32 original_copy;
			u32 home;
			u32 bitstream_type;
			u32 bitrate;
			u32 number_of_program_config_elements;
			u32 buffer_fullness;
		} adif;
		struct
		{
			u32 id;
			u32 layer;
			u32 protection_absent;
			u32 profile;
			u32 sampling_freq_index;
			u32 private_bit;
			u32 channel_configuration;
			u32 original_copy;
			u32 home;
			u32 copyright_id_bit;
			u32 copyright_id_start;
			u32 frame_length;
			u32 buffer_fullness;
			u32 number_of_row_data_blocks;
			u32 crc_check;
		} adts;
	} bsi;
	struct
	{
		u32 is_matrix_mixdown_present;
		u32 mixdown_index;
		u32 pseudo_surround_enable;
	} matrix_mixdown;
	u32 reserved;
} adecM4AacInfo;

typedef struct _adec_celp8_info
{
	u32 excitation_mode;
	u32 sample_rate;
	u32 configuration;
	u32 word_size;
} adecCelp8Info;

// Undocumented codecs
// ...
// ...

s32 adecQueryAttr(const adecType *type,adecAttr *attr);
s32 adecOpen(const adecType *type,const adecResource *resource,const adecCallback *cb,adecHandle *handle);
s32 adecOpenEx(const adecType *type,const adecResourceEx *resource,const adecCallback *cb,adecHandle *handle);
s32 adecOpenExt(const adecType *type,const adecResourceEx *resource,const adecCallback *cb,adecHandle *handle);
s32 adecClose(adecHandle handle);
s32 adecStartSequence(adecHandle handle,void *param);
s32 adecEndSequence(adecHandle handle);
s32 adecDecodeAu(adecHandle handle,const adecAuInfo *auInfo);
s32 adecGetPcm(adecHandle handle,void *buffer);
s32 adecGetPcmItem(adecHandle handle,const adecPcmItem **pcmItem);


#ifdef __cplusplus
	}
#endif

