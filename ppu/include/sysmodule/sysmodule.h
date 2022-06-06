#ifndef __LV2_SYSMODULE_H__
#define __LV2_SYSMODULE_H__

#include <ppu-types.h>

#ifdef __cplusplus
extern "C" {
#endif

/* constants */
#define SYSMODULE_OK                             0x00
#define SYSMODULE_LOADED                         0x00
#define SYSMODULE_ERR_DUPLICATE                  0x80012001 /* already loaded */
#define SYSMODULE_ERR_UNKNOWN                    0x80012002 /* unknown prx */
#define SYSMODULE_ERR_UNLOADED                   0x80012003 /* already unloaded */
#define SYSMODULE_ERR_INVALID_MEM                0x80012004 /* invalid memory container */
#define SYSMODULE_ERR_FATAL                      0x800120ff /* call failed */


typedef enum
{
	SYSMODULE_NET = 0x0000,
	SYSMODULE_HTTP = 0x0001,
	SYSMODULE_HTTP_UTIL = 0x0002,
	SYSMODULE_SSL = 0x0003,
	SYSMODULE_HTTPS = 0x0004,
	SYSMODULE_VDEC = 0x0005,
	SYSMODULE_ADEC = 0x0006,
	SYSMODULE_DMUX = 0x0007,
	SYSMODULE_VPOST = 0x0008,
	SYSMODULE_RTC = 0x0009,
	SYSMODULE_SPURS = 0x000a,
	SYSMODULE_OVIS = 0x000b,
	SYSMODULE_SHEAP = 0x000c,
	SYSMODULE_SYNC = 0x000d,
	SYSMODULE_FS = 0x000e,
	SYSMODULE_JPGDEC = 0x000f,
	SYSMODULE_GCM_SYS = 0x0010,
	SYSMODULE_AUDIO = 0x0011,
	SYSMODULE_PAMF = 0x0012,
	SYSMODULE_ATRAC3 = 0x0013,
	SYSMODULE_NETCTL = 0x0014,
	SYSMODULE_SYSUTIL = 0x0015,
	SYSMODULE_SYSUTIL_NP = 0x0016,
	SYSMODULE_IO = 0x0017,
	SYSMODULE_PNGDEC = 0x0018,
	SYSMODULE_FONT = 0x0019,
	SYSMODULE_FONTFT = 0x001a,
	SYSMODULE_FREETYPE = 0x001b,
	SYSMODULE_USB = 0x001c,
	SYSMODULE_SAIL = 0x001d,
	SYSMODULE_L10N = 0x001e,
	SYSMODULE_RESC = 0x001f,
	SYSMODULE_DAISY = 0x0020,
	SYSMODULE_KEY2CHAR = 0x0021,
	SYSMODULE_MIC = 0x0022,
	SYSMODULE_CAMERA = 0x0023,
	SYSMODULE_VDEC_MPEG2 = 0x0024,
	SYSMODULE_VDEC_H264 = 0x0025,
	SYSMODULE_ADEC_LPCM = 0x0026,
	SYSMODULE_ADEC_AC3 = 0x0027,
	SYSMODULE_ADEC_ATX = 0x0028,
	SYSMODULE_ADEC_AT3 = 0x0029,
	SYSMODULE_ADEC_PAMF = 0x002a,

	SYSMODULE_VDEC_AL = 0x002b, // TODO: check
	SYSMODULE_ADEC_AL = 0x002c, // TODO: check
	SYSMODULE_DMUX_AL = 0x002d, // TODO: check

	SYSMODULE_LV2DBG = 0x002e,

	SYSMODULE_SYSUTIL_AVCHAT = 0x002f, // TODO: check

	SYSMODULE_USBPSPCM = 0x0030,
	SYSMODULE_AVCONF_EXT = 0x0031,
	SYSMODULE_USERINFO = 0x0032,
	SYSMODULE_SAVEDATA = 0x0033,
	SYSMODULE_SUBDISPLAY = 0x0034,
	SYSMODULE_SYSUTIL_REC = 0x0035,
	SYSMODULE_VIDEO_EXPORT = 0x0036,
	SYSMODULE_SYSUTIL_GAME_EXEC = 0x0037,
	SYSMODULE_SYSUTIL_NP2 = 0x0038,
	SYSMODULE_SYSUTIL_AP = 0x0039,
	SYSMODULE_SYSUTIL_NP_CLANS = 0x003a,
	SYSMODULE_SYSUTIL_OSK_EXT = 0x003b,
	SYSMODULE_VDEC_DIVX = 0x003c,
	SYSMODULE_JPGENC = 0x003d,
	SYSMODULE_SYSUTIL_GAME = 0x003e,
	SYSMODULE_BGDL = 0x003f,
	SYSMODULE_FREETYPE_TT = 0x0040,
	SYSMODULE_SYSUTIL_VIDEO_UPLOAD = 0x0041,
	SYSMODULE_SYSUTIL_SYSCONF_EXT = 0x0042,
	SYSMODULE_FIBER = 0x0043,
	SYSMODULE_SYSUTIL_NP_COMMERCE2 = 0x0044,
	SYSMODULE_SYSUTIL_NP_TUS = 0x0045,
	SYSMODULE_VOICE = 0x0046,
	SYSMODULE_ADEC_CELP8 = 0x0047,
	SYSMODULE_CELP8ENC = 0x0048,
	SYSMODULE_SYSUTIL_LICENSEAREA = 0x0049,
	SYSMODULE_MUSIC2 = 0x004a,

	SYSMODULE_AD_CORE = 0x004b,           // TODO: check
	SYSMODULE_AD_ASYNC = 0x004c,          // TODO: check
	SYSMODULE_AD_BILLBOARD_UTIL = 0x004d, // TODO: check

	SYSMODULE_SYSUTIL_SCREENSHOT = 0x004e,
	SYSMODULE_MUSIC_DEC = 0x004f,
	SYSMODULE_SPURS_JQ = 0x0050,
	// 0x0051
	SYSMODULE_PNGENC = 0x0052,
	SYSMODULE_MUSIC_DEC2 = 0x0053,
	SYSMODULE_MEDI = 0x0054,
	SYSMODULE_SYNC2 = 0x0055,
	SYSMODULE_SYSUTIL_NP_UTIL = 0x0056,
	SYSMODULE_RUDP = 0x0057,
	// 0x0058
	SYSMODULE_SYSUTIL_NP_SNS = 0x0059,
	SYSMODULE_GEM = 0x005a,
	// 0x005b
	SYSMODULE_SYSUTIL_CROSS_CONTROLLER = 0x005c,


	SYSMODULE_CELPENC = 0xf00a,           // libcelpenc(CELP encoder)
	SYSMODULE_GIFDEC = 0xf010,            // libgifdec(GIF decoder)
	SYSMODULE_ADEC_CELP = 0xf019,         // libadec(CELP decoder)
	SYSMODULE_ADEC_M2BC = 0xf01b,         // libadec(MPEG2 BC decoder)
	SYSMODULE_ADEC_M4AAC = 0xf01d,        // libadec(MPEG4 AAC decoder)
	SYSMODULE_ADEC_MP3 = 0xf01e,          // libadec(MP3 decoder)
	SYSMODULE_IMEJP = 0xf023,             // ImeJp utility
	SYSMODULE_SYSUTIL_MUSIC = 0xf028,     // Music utility(playback using a memory container)
	SYSMODULE_PHOTO_EXPORT = 0xf029,      // Photo utility(export)
	SYSMODULE_PRINT = 0xf02a,             // Print utility
	SYSMODULE_PHOTO_IMPORT = 0xf02b,      // Photo utility(import)
	SYSMODULE_MUSIC_EXPORT = 0xf02c,      // Music utility(export)
	SYSMODULE_PHOTO_DECODE = 0xf02e,      // Photo utility(decode)
	SYSMODULE_SYSUTIL_SEARCH = 0xf02f,    // Content search utility
	SYSMODULE_SYSUTIL_AVCHAT2 = 0xf030,   // AV chat 2 utility
	SYSMODULE_SAIL_REC = 0xf034,          // libsail_rec(media recording)
	SYSMODULE_SYSUTIL_NP_EULA = 0xf044,   // NP EULA utility
	SYSMODULE_SYSUTIL_NP_TROPHY = 0xf035, // NP trophy utility
	SYSMODULE_LIBATRAC3MULTI = 0xf054,

	SYSMODULE_INVALID = 0xffff,
} sysModuleId;


s32 sysModuleLoad(sysModuleId id);
s32 sysModuleUnload(sysModuleId id);
s32 sysModuleIsLoaded(sysModuleId id);


#ifdef __cplusplus
	}
#endif

#endif
