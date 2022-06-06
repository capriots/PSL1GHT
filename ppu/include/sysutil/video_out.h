/*! \file video_out.h
    \brief Video output mode management.
*/

#ifndef __LV2_VIDEO_OUT_H__
#define __LV2_VIDEO_OUT_H__

#include <ppu-types.h>

#define VIDEO_OUT_STATE_DISABLED                              0x00
#define VIDEO_OUT_STATE_ENABLED                               0x01
#define VIDEO_OUT_STATE_BUSY                                  0x02

#define VIDEO_OUT_PRIMARY                                     0x00
#define VIDEO_OUT_SECONDARY                                   0x01

#define VIDEO_OUT_SCAN_MODE_INTERLACE                         0x00
#define VIDEO_OUT_SCAN_MODE_PROGRESSIVE                       0x01

#define VIDEO_OUT_SCAN_MODE2_AUTO                             0x00
#define VIDEO_OUT_SCAN_MODE2_INTERLACE                        0x01
#define VIDEO_OUT_SCAN_MODE2_PROGRESSIVE                      0x02

#define VIDEO_OUT_BUFFER_FORMAT_XRGB                          0x00
#define VIDEO_OUT_BUFFER_FORMAT_XBGR                          0x01
#define VIDEO_OUT_BUFFER_FORMAT_FLOAT                         0x02

#define VIDEO_OUT_ASPECT_AUTO                                 0x00
#define VIDEO_OUT_ASPECT_4_3                                  0x01
#define VIDEO_OUT_ASPECT_16_9                                 0x02

#define VIDEO_OUT_RESOLUTION_UNDEFINED                        0x00
#define VIDEO_OUT_RESOLUTION_1080                             0x01
#define VIDEO_OUT_RESOLUTION_720                              0x02
#define VIDEO_OUT_RESOLUTION_480                              0x04
#define VIDEO_OUT_RESOLUTION_576                              0x05
#define VIDEO_OUT_RESOLUTION_1600x1080                        0x0a
#define VIDEO_OUT_RESOLUTION_1440x1080                        0x0b
#define VIDEO_OUT_RESOLUTION_1280x1080                        0x0c
#define VIDEO_OUT_RESOLUTION_960x1080                         0x0d
#define VIDEO_OUT_RESOLUTION_720_3D_FRAME_PACKING             0x81
#define VIDEO_OUT_RESOLUTION_1024x720_3D_FRAME_PACKING        0x88
#define VIDEO_OUT_RESOLUTION_960x720_3D_FRAME_PACKING         0x89
#define VIDEO_OUT_RESOLUTION_800x720_3D_FRAME_PACKING         0x8a
#define VIDEO_OUT_RESOLUTION_640x720_3D_FRAME_PACKING         0x8b
#define VIDEO_OUT_RESOLUTION_720_DUALVIEW_FRAME_PACKING       0x91
#define VIDEO_OUT_RESOLUTION_720_SIMULVIEW_FRAME_PACKING      0x91
// #define ...3D something?... 0x92
#define VIDEO_OUT_RESOLUTION_1024x720_DUALVIEW_FRAME_PACKING  0x98
#define VIDEO_OUT_RESOLUTION_1024x720_SIMULVIEW_FRAME_PACKING 0x98
#define VIDEO_OUT_RESOLUTION_960x720_DUALVIEW_FRAME_PACKING   0x99
#define VIDEO_OUT_RESOLUTION_960x720_SIMULVIEW_FRAME_PACKING  0x99
#define VIDEO_OUT_RESOLUTION_800x720_DUALVIEW_FRAME_PACKING   0x9a
#define VIDEO_OUT_RESOLUTION_800x720_SIMULVIEW_FRAME_PACKING  0x9a
#define VIDEO_OUT_RESOLUTION_640x720_DUALVIEW_FRAME_PACKING   0x9b
#define VIDEO_OUT_RESOLUTION_640x720_SIMULVIEW_FRAME_PACKING  0x9b
#define VIDEO_OUT_RESOLUTION_1080_BRAVIA_4k_PHOTO             0xa1

#define VIDEO_OUT_COLOR_RGB                                   0x01
#define VIDEO_OUT_COLOR_YUV                                   0x02
#define VIDEO_OUT_COLOR_XVYCC                                 0x04

#define VIDEO_OUT_REFRESH_AUTO                                0x00
#define VIDEO_OUT_REFRESH_59_94HZ                             0x01
#define VIDEO_OUT_REFRESH_50HZ                                0x02
#define VIDEO_OUT_REFRESH_60HZ                                0x04
#define VIDEO_OUT_REFRESH_30HZ                                0x08
// #define 0x10
// #define 0x20
// #define 0x40
// #define 0x80

#define VIDEO_OUT_PORT_NONE                                   0x00
#define VIDEO_OUT_PORT_HDMI                                   0x01
#define VIDEO_OUT_PORT_NETWORK                                0x41
#define VIDEO_OUT_PORT_COMPOSITE_S                            0x81
#define VIDEO_OUT_PORT_D                                      0x82
#define VIDEO_OUT_PORT_COMPONENT                              0x83
#define VIDEO_OUT_PORT_RGB                                    0x84
#define VIDEO_OUT_PORT_AVMULTI_SCART                          0x85
#define VIDEO_OUT_PORT_DSUB                                   0x86

#ifdef __cplusplus
extern "C" {
#endif

/*! \brief Video resolution.
*/
typedef struct _videoOutResolution
{
    u16 width;               /*!< \brief Screen width in pixels. */
    u16 height;              /*!< \brief Screen height in pixels. */
} videoOutResolution;

/*! \brief Video display mode.
*/
typedef struct _videoOutDisplayMode
{
/*! \brief resolution id.

    The possible values are:
    - \c VIDEO_OUT_RESOLUTION_1080
    - \c VIDEO_OUT_RESOLUTION_720
    - \c VIDEO_OUT_RESOLUTION_480
    - \c VIDEO_OUT_RESOLUTION_576
*/
    u8 resolution;
/*! \brief Scan mode.
    \todo more explanations needed. */
    u8 scanMode;
/*! \brief Conversion mode.
    \todo more explanations needed. */
    u8 conversion;
/*! \brief aspect ratio.

    The possible values are:
    - \c VIDEO_OUT_ASPECT_AUTO
    - \c VIDEO_OUT_ASPECT_4_3
    - \c VIDEO_OUT_ASPECT_16_9
*/
    u8 aspect;
/*! \brief unused. */
    u8 padding[2];
/*! \brief Refresh rates.
    \todo more explanations needed. */
    u16 refreshRates;
} videoOutDisplayMode;

/*! \brief Video state stucture.
*/
typedef struct _videoOutState
{
/*! \brief state value.

    The possible values are:
    - \c VIDEO_OUT_STATE_DISABLED
    - \c VIDEO_OUT_STATE_ENABLED
    - \c VIDEO_OUT_STATE_BUSY
*/
    u8 state;
/*! \brief color space.

    The possible values are:
    - \c VIDEO_OUT_BUFFER_FORMAT_XRGB
    - \c VIDEO_OUT_BUFFER_FORMAT_XBGR
    - \c VIDEO_OUT_BUFFER_FORMAT_FLOAT
    \todo verify
*/
    u8 colorSpace;
/*! \brief unused. */
    u8 padding[6];
/*! \brief display mode. */
    videoOutDisplayMode displayMode;
} videoOutState;

/*! \brief Video configuration structure.
*/
typedef struct _videoOutConfig
{
/*! \brief resolution id.

    Most commonly used values are:
    - \c VIDEO_OUT_RESOLUTION_1080
    - \c VIDEO_OUT_RESOLUTION_720
    - \c VIDEO_OUT_RESOLUTION_480
    - \c VIDEO_OUT_RESOLUTION_576
*/
    u8 resolution;

/*! \brief video buffer format.

    The possible values are:
    - \c VIDEO_OUT_BUFFER_FORMAT_XRGB
    - \c VIDEO_OUT_BUFFER_FORMAT_XBGR
    - \c VIDEO_OUT_BUFFER_FORMAT_FLOAT
*/
    u8 format;

/*! \brief aspect ratio.

    The possible values are:
    - \c VIDEO_OUT_ASPECT_AUTO
    - \c VIDEO_OUT_ASPECT_4_3
    - \c VIDEO_OUT_ASPECT_16_9
*/
    u8 aspect;

    u8 scanMode2;
    
/*! \brief unused. */
    u8 padding[7];
    
    u8 refreshRate;

/*! \brief offset in bytes between the beginnings of consecutive lines.
*/
    u32 pitch;
} videoOutConfiguration;

typedef struct _videoOutColorInfo
{
    u16 redX;
    u16 redY;
    u16 greenX;
    u16 greenY;
    u16 blueX;
    u16 blueY;
    u16 whiteX;
    u16 whiteY;
    u32 gamma;
} videoOutColorInfo;

typedef struct _videoOutKSVList
{
    u8 ksv[32*5];
    u8 padding[4];
    u32 count;
} videoOutKSVList;

typedef struct _videoOutDeviceInfo
{
    u8 portType;
    u8 colorSpace;
    u16 latency;
    u8 availableModeCount;
    u8 state;
    u8 rgbOutputRange;
    u8 padding[5];
    videoOutColorInfo colorInfo;
    videoOutDisplayMode availableModes[32];
    videoOutKSVList ksvList;
} videoOutDeviceInfo;

typedef struct _videoOutOption
{
    u32 reserved;
} videoOutOption;

typedef s32 (*videoOutCallback)(u32 slot, u32 videoOut, u32 deviceIndex, u32 event, videoOutDeviceInfo *info, void *userData);

/*! \brief Get video state

    For the default display, just use 0 for \p videoOut and \p deviceIndex.
    \param videoOut Video output id.
    \param deviceIndex Devide index.
    \param state Pointer to a video state structure to be updated.
    \return zero if no error, nonzero otherwise.
    \todo verify the parameters signification.
*/
s32 videoOutGetState(s32 videoOut,s32 deviceIndex,videoOutState *state);

/*! \brief Get video resolution from resolution id.
    \param resolutionId The input resolution id. The possible values are:
    - \c VIDEO_OUT_RESOLUTION_1080
    - \c VIDEO_OUT_RESOLUTION_720
    - \c VIDEO_OUT_RESOLUTION_480
    - \c VIDEO_OUT_RESOLUTION_576
    \param resolution Pointer to the video resolution structure to be updated.
    \return zero if no error, nonzero otherwise.
*/
s32 videoOutGetResolution(s32 resolutionId,videoOutResolution *resolution);

/*! \brief Configure the video output.
    \param videoOut Video output id.
    \param config Pointer to a video configuration structure.
    \param option Pointer to additional video configuration data.
    \param blocking Nonzero indicates if the call is blocking or not.
    \return zero if no error, nonzero otherwise.
    \todo verify the parameters signification.
*/
s32 videoOutConfigure(s32 videoOut,videoOutConfiguration *config,videoOutOption *option,s32 blocking);

s32 videoOutGetNumberOfDevice(u32 videoOut);
s32 videoOutGetDeviceInfo(u32 videoOut, u32 deviceIndex, videoOutDeviceInfo *info);
s32 videoOutGetConfiguration(u32 videoOut, videoOutConfiguration *config, void *option);
s32 videoOutGetResolutionAvailability(u32 videoOut, u32 resolutionId, u32 aspect, u32 option);
s32 videoOutDebugSetMonitorType(u32 videoOut, u32 monitorType);
s32 videoOutGetConvertCursorColorInfo(u8 *rgbOutputRange);

s32 videoOutRegisterCallback(u32 slot, videoOutCallback cbVideo, void *userData);
s32 videoOutUnregisterCallback(u32 slot);

// libsysutil_avconf_ext functions
//s32 videoOutSetXVColor()
//s32 videoOutSetupDisplay()
s32 videoOutConvertCursorColor(u32 videoOut, s32 displaybuffer_format, f32 gamma, s32 source_buffer_format, void *src_addr, u32 *dest_addr, s32 num);
s32 videoOutGetGamma(u32 videoOut, f32 *gamma);
s32 videoOutSetGamma(u32 videoOut, f32 gamma);
s32 videoOutGetScreenSize(u32 videoOut, f32* screenSize);
s32 videoOutSetCopyControl(u32 videoOut, u32 control);
s32 videoOutConfigure2(s32 videoOut, videoOutConfiguration *config, videoOutOption *option, s32 blocking);
s32 videoOutGetResolutionAvailability2(u32 videoOut, u32 resolutionId, u32 aspect, u32 refreshRate);

#ifdef __cplusplus
    }
#endif

#endif
