#pragma once

#include <ppu-types.h>
#include <spurs/types.h>
#include <codec/types.h>

#define VDEC_ERROR_ARG					0x80610101
#define VDEC_ERROR_SEQ					0x80610102
#define VDEC_ERROR_BUSY					0x80610103
#define VDEC_ERROR_EMPTY				0x80610104
#define VDEC_ERROR_AU					0x80610105
#define VDEC_ERROR_PIC					0x80610106

#define	VDEC_CODEC_TYPE_MPEG2			0
#define	VDEC_CODEC_TYPE_H264			1

#define VDEC_CALLBACK_AUDONE			0
#define VDEC_CALLBACK_PICOUT			1
#define VDEC_CALLBACK_SEQDONE			2
#define VDEC_CALLBACK_ERROR				3

#define VDEC_DECODER_MODE_NORMAL		0
#define VDEC_DECODER_MODE_SKIP_NON_REF	1

#define VDEC_PICFMT_ARGB32				0
#define VDEC_PICFMT_RGBA32				1
#define VDEC_PICFMT_UYVY422				2
#define VDEC_PICFMT_YUV420P				3

#define VDEC_COLOR_MATRIX_BT601			0
#define VDEC_COLOR_MATRIX_BT709			1

#define VDEC_PICTURE_NORMAL				0
#define VDEC_PICTURE_SKIPPED			1

#define VDEC_FRC_24000DIV1001			0x80
#define VDEC_FRC_24						0x81
#define VDEC_FRC_25						0x82
#define VDEC_FRC_30000DIV1001			0x83
#define VDEC_FRC_30						0x84
#define VDEC_FRC_50						0x85
#define VDEC_FRC_60000DIV1001			0x86
#define VDEC_FRC_60						0x87

#define VDEC_MPEG2_MP_LL				0
#define VDEC_MPEG2_MP_ML				1
#define VDEC_MPEG2_MP_H14				2
#define VDEC_MPEG2_MP_HL				3

#define VDEC_MPEG2_ARI_SAR_1_1			1
#define VDEC_MPEG2_ARI_DAR_4_3			2
#define VDEC_MPEG2_ARI_DAR_16_9			3
#define VDEC_MPEG2_ARI_DAR_2P21_1		4

#ifdef __cplusplus
extern "C" {
#endif

typedef void *vdecHandle ATTRIBUTE_PRXPTR;

typedef u32(*vdecCallbackMsg)(vdecHandle handle, u32 msgType, u32 msgData, void *callbackArg) ATTRIBUTE_PRXPTR;

typedef struct _vdec_type
{
	u32 codec_type;
	u32 profile_level;
} vdecType;

typedef struct _vdec_type_ex
{
	u32 codec_type;
	u32 profile_level;
	void *codec_specific_info ATTRIBUTE_PRXPTR;
} vdecTypeEx;

typedef struct _vdec_mpeg2_specific_info
{
	u32 this_size;
	u16 max_decoded_frame_width;
	u16 max_decoded_frame_height;
} vdecMpeg2SpecificInfo;

typedef struct _vdec_h264_specific_info
{
	u32 this_size;
	u16 max_decoded_frame_width;
	u16 max_decoded_frame_height;
	bool disable_deblocking_filter;
	u8 number_of_decoded_frame_buffer;
} vdecH264SpecificInfo;

typedef struct _vdec_divx_specific_info2
{
	u32 this_size;
	u16 max_decoded_frame_width;
	u16 max_decoded_frame_height;
	u16 number_of_decoded_frame_buffer;
} vdecDivxSpecificInfo2;

typedef struct _vdec_attr
{
	u32 mem_size;
	u8 cmd_depth;
	u32 ver_major;
	u32 ver_minor;
} vdecAttr;

typedef struct _vdec_resource
{
	void *mem_addr ATTRIBUTE_PRXPTR;
	u32 mem_size;
	s32 ppu_thread_prio;
	u32 ppu_thread_stack_size;
	s32 spu_thread_prio;
	u32 num_spus;
} vdecResource;

typedef struct vdec_resource_spurs
{
	Spurs* spurs ATTRIBUTE_PRXPTR;
	u8 prio[8];
	u32 max_contention;
} vdecResourceSpurs;

typedef struct _vdec_resource_ex
{
	void *mem_addr ATTRIBUTE_PRXPTR;
	u32 mem_size;
	s32 ppu_thread_prio;
	u32 ppu_thread_stack_size;
	s32 spu_thread_prio;
	u32 num_spus;
	vdecResourceSpurs *spurs_resource ATTRIBUTE_PRXPTR;
} vdecResourceEx;

typedef struct _vdec_resource_ext
{
	void *mem_addr ATTRIBUTE_PRXPTR;
	u32 mem_size;
	s32 ppu_thread_prio;
	u32 ppu_thread_stack_size;
	vdecResourceSpurs spursResource;
} vdecResourceExt;

typedef struct _vdec_callback
{
	vdecCallbackMsg fn;
	void *arg ATTRIBUTE_PRXPTR;
} vdecCallback;

typedef struct _vdec_au_info
{
	void *start_addr ATTRIBUTE_PRXPTR;
	u32 size;
	CodecTimeStamp pts;
	CodecTimeStamp dts;
	u64 user_data;
	u64 codec_specific_data;
} vdecAuInfo;

typedef struct _vdec_au_info_ex2
{
	void *start_addr ATTRIBUTE_PRXPTR;
	u32 unk1;
	u32 size;
	u32 unk2;
	CodecTimeStamp pts;
	CodecTimeStamp dts;
	u64 user_data;
	u64 codec_specific_data;
} vdecAuInfoEx2;

typedef struct _vdec_pic_item
{
	u32 codec_type;
	void *start_addr ATTRIBUTE_PRXPTR;
	u32 size;
	u8 au_num;
	CodecTimeStamp au_pts[2];
	CodecTimeStamp au_dts[2];
	u64 au_user_data[2];
	u32 status;
	u32 attr;
	void *pic_info ATTRIBUTE_PRXPTR;
} vdecPicItem;


typedef struct _vdec_pic_format 
{
	u32 format_type;
	u32 color_matrix;
	u8 alpha;
} vdecPicFormat;

typedef struct _vdec_pic_format_ext
{
	u32 format_type;
	u32 color_matrix;
	u32 unk1;
	u8 alpha;
	u32 unk2;
} vdecPicFormatExt;

typedef struct _vdec_mpeg2_info
{
	u16 width;
	u16 height;
	u8  aspect_ratio;
	u8  frame_rate;
	bool progressive_sequence;
	bool low_delay;
	u8  video_format;
	bool color_description;
	u8  color_primaries;
	u8  transfer_characteristics;
	u8  matrix_coefficients;
	u16 temporal_reference[2];
	u8  picture_coding_type[2];
	u8  picture_structure[2];
	bool top_field_first;
	bool repeat_first_field;
	bool progressive_frame;
	u32 time_code;
	bool closed_gop;
	bool broken_link;
	u16 vbv_delay[2];
	u16 display_horizontal_size;
	u16 display_vertical_size;
	u8  number_of_frame_centre_offsets[2];
	u16 frame_centre_horizontal_offset[2][3];
	u16 frame_centre_vertical_offset[2][3];
	u32 headerPresentFlags;
	u32 headerRetentionFlags;
	bool mpeg1Flag;
} vdecMPEG2Info;

typedef struct _vdec_h264_info 
{
	u16 width;
	u16 height;
	u8  picture_type[2];
	bool idr_picture_flag;
	u8  aspect_ratio_idc;
	u16 sar_height;
	u16 sar_width;
	u8  pic_struct;
	s8  pic_order_count[2];
	bool vui_parameters_present_flag;
	bool frame_mbs_only_flag;
	bool video_signal_type_present_flag;
	u8  video_format;
	bool video_full_range_flag;
	bool color_description_present_flag;
	u8  color_primaries;
	u8  transfer_characteristics;
	u8  matrix_coefficients;
	bool timing_info_present_flag;
	u8  frame_rate;
	bool fixed_frame_rate_flag;
	bool low_delay_hrd_flag;
	bool entropy_coding_mode_flag;
	u16 nalUnitPresentFlags;
} vdecH264Info;

typedef struct _vdec_divx_info
{
	u8 picture_type;
	u16 horizontal_size;
	u16 vertical_size;
	u8 pixel_aspect_ratio;
	u8 par_width;
	u8 par_height;
	bool colour_description;
	u8 colour_primaries;
	u8 transfer_characteristics;
	u8 matrix_coefficients;
	u8 picture_struct;
	u16 frame_rate_code;
} vdecDivxInfo;

s32 vdecQueryAttr(const vdecType *type,vdecAttr *attr);
s32 vdecQueryAttrEx(const vdecTypeEx *type,vdecAttr *attr);
s32 vdecOpen(const vdecType *type,const vdecResource *resource,const vdecCallback *cb,vdecHandle *handle);
s32 vdecOpenEx(const vdecTypeEx *type,const vdecResourceEx *resource,const vdecCallback *cb,vdecHandle *handle);
s32 vdecOpenExt(const vdecType *type,const vdecResourceExt *resource,const vdecCallback *cb,vdecHandle *handle);
s32 vdecClose(vdecHandle handle);
s32 vdecStartSequence(vdecHandle handle);
s32 vdecStartSequenceExt(vdecHandle handle,u32 unk);
s32 vdecEndSequence(vdecHandle handle);
s32 vdecDecodeAu(vdecHandle handle,s32 mode,const vdecAuInfo *auInfo);
s32 vdecDecodeAuEx2(vdecHandle,s32 mode,const vdecAuInfoEx2 *auInfo);
s32 libvdec_0x652B7BC0(vdecHandle,s32 mode,const vdecAuInfoEx2 *auInfo); // identical to vdecDecodeAuEx2() on firmware 4.89
s32 vdecGetPicture(vdecHandle handle,const vdecPicFormat *format,void *buffer);
s32 vdecGetPictureExt(vdecHandle handle,const vdecPicFormatExt *format,void *buffer,u32 unk);
s32 vdecGetPicItem(vdecHandle handle,vdecPicItem **picItem);
s32 vdecGetPicItemEx(vdecHandle handle,vdecPicItem **picItem,u32 unk);
s32 vdecGetPicItemExt(vdecHandle handle,vdecPicItem **picItem,u32 unk); // identical to vdecGetPicItemEx() on firmware 4.89
s32 vdecGetInputStatus(u32 unk1, u32 unk2);
s32 vdecSetFrameRate(vdecHandle handle,u32 frameRateCode);
s32 vdecSetFrameRateExt(vdecHandle handle,u32 unk1,u32 unk2);
s32 vdecSetPts(vdecHandle handle,u32 unk);

s32 libvdec_0x20DA0CFA(u32 unk1,u32 unk2,u32 unk3);


#ifdef __cplusplus
	}
#endif

