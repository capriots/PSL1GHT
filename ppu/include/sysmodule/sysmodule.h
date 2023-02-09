#pragma once

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
	SYSMODULE_DMUX_PAMF = 0x002a,
	SYSMODULE_VDEC_AL = 0x002b,
	SYSMODULE_ADEC_AL = 0x002c,
	SYSMODULE_DMUX_AL = 0x002d,
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
	// 0x0058 = unused
	SYSMODULE_SYSUTIL_NP_SNS = 0x0059,
	SYSMODULE_GEM = 0x005a,
	// 0x005b
	SYSMODULE_SYSUTIL_CROSS_CONTROLLER = 0x005c,

	SYSMODULE_INVALID = 0xffff,
} sysModuleId;

typedef enum
{
	SYSMODULE_INTERNAL_AT3ENC = 0xf000,               //
	SYSMODULE_INTERNAL_ATXENC = 0xf001,               //
	SYSMODULE_INTERNAL_VDEC_AL = 0xf002,              //
	SYSMODULE_INTERNAL_VPOST_INTERNAL = 0xf003,       //
	SYSMODULE_INTERNAL_MP3ENC = 0xf004,               //
	SYSMODULE_INTERNAL_AACENC = 0xf005,               //
	SYSMODULE_INTERNAL_ADEC_AL_INTERNAL = 0xf006,     //
	// 0xf007, internal/libapostsrc.sprx
	SYSMODULE_INTERNAL_AUDIO_INTERNAL = 0xf008,       //
	// 0xf009, external/libavchatjpgdec.sprx
	SYSMODULE_INTERNAL_CELPENC = 0xf00a,              // libcelpenc(CELP encoder)
	// 0xf00b, internal/libddlenc.sprx
	SYSMODULE_INTERNAL_DMUX_AL = 0xf00c,              //
	// 0xf00d, internal/libexif.sprx
	// 0xf00e, internal/libft2d.sprx
	// 0xf00f, internal/libgcm_osd.sprx
	SYSMODULE_INTERNAL_GIFDEC = 0xf010,               // libgifdec(GIF decoder)
	SYSMODULE_INTERNAL_JPGDEC = 0xf011,               //
	SYSMODULE_INTERNAL_JPGENC = 0xf012,               //
	SYSMODULE_INTERNAL_M4VENC = 0xf013,               //
	SYSMODULE_INTERNAL_PAMF = 0xf014,                 //
	SYSMODULE_INTERNAL_PNGDEC = 0xf015,               //
	SYSMODULE_INTERNAL_PNGENC = 0xf016,               //
	// 0xf017, internal/libps2savedata.sprx
	SYSMODULE_INTERNAL_TIFFDEC = 0xf018,              //
	SYSMODULE_INTERNAL_ADEC_CELP = 0xf019,            // libadec(CELP decoder)
	SYSMODULE_INTERNAL_ADEC_DTS = 0xf01a,             // DO NOT USE
	SYSMODULE_INTERNAL_ADEC_M2BC = 0xf01b,            // libadec(MPEG2 BC decoder)
	SYSMODULE_INTERNAL_ADEC_M2AAC = 0xf01c,           //
	SYSMODULE_INTERNAL_ADEC_M4AAC = 0xf01d,           // libadec(MPEG4 AAC decoder)
	SYSMODULE_INTERNAL_ADEC_MP3 = 0xf01e,             // libadec(MP3 decoder)
	SYSMODULE_INTERNAL_ADEC_TRUEHD = 0xf01f,          //
	SYSMODULE_INTERNAL_VDEC_VC1 = 0xf020,             // REQUIRES PARAMSFO FLAG ??? // VC-1 decoder // TODO: check
	SYSMODULE_INTERNAL_VDEC_MPEG4 = 0xf021,           // MPEG-4 Part 2 video decoder                // TODO: check
	SYSMODULE_INTERNAL_SYSUTIL_REMOTEPLAY = 0xf022,   //
	SYSMODULE_INTERNAL_IMEJP = 0xf023,                // ImeJp utility
	SYSMODULE_INTERNAL_ADEC_WMA = 0xf024,             // REQUIRES PARAMSFO FLAG ???
	// 0xf025, internal/libasfparser.sprx
	SYSMODULE_INTERNAL_ADEC_EAC3 = 0xf026,            // Dolby Digital Plus decoder
	SYSMODULE_INTERNAL_ADEC_DTSLBR_INTERNAL = 0xf027, // DTS Express decoder, uses internal/libdtslbrdec.sprx
	SYSMODULE_INTERNAL_SYSUTIL_MUSIC = 0xf028,        // Music utility(playback using a memory container)
	SYSMODULE_INTERNAL_PHOTO_EXPORT = 0xf029,         // Photo utility(export)
	SYSMODULE_INTERNAL_PRINT = 0xf02a,                // Print utility
	SYSMODULE_INTERNAL_PHOTO_IMPORT = 0xf02b,         // Photo utility(import)
	SYSMODULE_INTERNAL_MUSIC_EXPORT = 0xf02c,         // Music utility(export)
	SYSMODULE_INTERNAL_AVCENC_SMALL = 0xf02d,         //
	SYSMODULE_INTERNAL_PHOTO_DECODE = 0xf02e,         // Photo utility(decode)
	SYSMODULE_INTERNAL_SYSUTIL_SEARCH = 0xf02f,       // Content search utility
	SYSMODULE_INTERNAL_SYSUTIL_AVCHAT2 = 0xf030,      // AV chat 2 utility
	// 0xf031, external/libmp4.sprx
	SYSMODULE_INTERNAL_SYSUTIL_RTCALARM = 0xf032,     //
	// 0xf033, external/libavcenc_small.sprx
	SYSMODULE_INTERNAL_SAIL_REC = 0xf034,             // libsail_rec(media recording)
	SYSMODULE_INTERNAL_SYSUTIL_NP_TROPHY = 0xf035,    // NP trophy utility
	// 0xf036, external/libsjvtd.sprx, video decoder // Motion JPEG?
	SYSMODULE_INTERNAL_ADEC_DTSHD = 0xf037,           //
	SYSMODULE_INTERNAL_ADEC_MP3S = 0xf038,            // MP3 Surround decoder
	SYSMODULE_INTERNAL_SAIL_AVI = 0xf039,             //
	SYSMODULE_INTERNAL_AVCENC = 0xf03a,               //
	// 0xf03b, external/libapostsrc_mini.sprx
	SYSMODULE_INTERNAL_VOICE_INTERNAL = 0xf03c,       //
	// 0xf03d, external/libmpl1dec.sprx, audio decoder
	// 0xf03e, external/libasfparser2_astd.sprx // REQUIRES PARAMSFO FLAG ???
	SYSMODULE_INTERNAL_ADEC2_AL = 0xf03f,             //
	SYSMODULE_INTERNAL_ADEC2_AC3 = 0xf040,            //
	SYSMODULE_INTERNAL_ADEC2_ATX = 0xf041,            //
	// 0xf042, internal/libdivx311dec.sprx, video decoder
	SYSMODULE_INTERNAL_VPOST2 = 0xf043,               //
	SYSMODULE_INTERNAL_SYSUTIL_NP_EULA = 0xf044,      // NP EULA utility
	SYSMODULE_INTERNAL_SYSUTIL_STORAGEDATA = 0xf045,  //
	SYSMODULE_INTERNAL_M4HDENC = 0xf046,              // MPEG-4 Advanced Coding Efficiency encoder
	SYSMODULE_INTERNAL_SYSUTIL_SAVEDATA_PSP = 0xf047, //
	SYSMODULE_INTERNAL_SYSUTIL_VIDEO_PLAYER = 0xf048, //
	SYSMODULE_INTERNAL_VDEC_MVC = 0xf049,             //
	// 0xf04a, external/libaacenc_spurs.sprx
	// 0xf04b, internal/libdtshdcoredec.sprx, audio decoder
	// 0xf04c, internal/libpidvd.sprx
	SYSMODULE_INTERNAL_SYSUTIL_DTCP_IP = 0xf04d,      //
	SYSMODULE_INTERNAL_SYSUTIL_SYSCHAT = 0xf04e,      //
	SYSMODULE_INTERNAL_SYSUTIL_NP_INSTALLER = 0xf04f, //
	// 0xf050, external/libbemp2sys.sprx
	// 0xf051, external/libbeisobmf.sprx
	SYSMODULE_INTERNAL_PHOTO_EXPORT2 = 0xf052,        //
	SYSMODULE_INTERNAL_ADEC_AT3MULTI = 0xf053,        //
	SYSMODULE_INTERNAL_LIBATRAC3MULTI = 0xf054,       //
	SYSMODULE_INTERNAL_SYSUTIL_DEC_PSNVIDEO = 0xf055, //
	SYSMODULE_INTERNAL_ADEC_DTSLBR = 0xf056,          // DTS Express decoder, uses external/libdtslbrdec.sprx
} sysModuleInternalId;

s32 sysModuleInitialize();
s32 sysModuleFinalize();

s32 sysModuleLoad(sysModuleId id);
s32 sysModuleUnload(sysModuleId id);
s32 sysModuleIsLoaded(sysModuleId id);

s32 sysModuleGetImagesize(u16 unk1, u32 *unk2);
s32 sysModuleFetchImage(u16 unk1, void *unk2, u32 *unk3);
s32 sysModuleSetMemcontainer(u32 ct);

s32 sysModuleLoadInternal(sysModuleInternalId id);
s32 sysModuleUnloadInternal(sysModuleInternalId id);
s32 sysModuleLoadEx(sysModuleInternalId id);
s32 sysModuleUnloadEx(sysModuleInternalId id);
s32 sysModuleIsLoadedEx(sysModuleInternalId id);

s32 sysModule_0x002CD0BF(); // Does nothing
s32 sysModule_0x03D90241(u32 unk); // Sets library directory to /app_home if unk == 1, else /dev_flash/sys
s32 sysModule_0x205FE2A0(u32 *unk);
s32 sysModule_0x59521326(void *unk);
s32 sysModule_0xC93200DE(u8 *unk1, u32 *unk2);

#ifdef __cplusplus
	}
#endif
