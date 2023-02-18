#pragma once

#define CODEC_PTS_INVALID  0xffffffff

#define CODEC_DTS_INVALID  0xffffffff

#include <ppu-types.h>
#ifdef __cplusplus
extern "C" {
#endif

	typedef struct CodecTimeStamp
	{
		u32 hi;
		u32 low;
	} CodecTimeStamp;

	typedef struct CodecEsFilterId
	{
		u32 filter_id_major;
		u32 filter_id_minor;
		u32 supplemental_info_1;
		u32 supplemental_info_2;
	} CodecEsFilterId;


#ifdef __cplusplus
	}
#endif

