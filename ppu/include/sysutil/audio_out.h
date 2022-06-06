/*! \file audio_out.h
    \brief Audio output mode management.
*/

#ifndef __LV2_AUDIO_OUT_H__
#define __LV2_AUDIO_OUT_H__

#include <ppu-types.h>

#define AUDIO_OUT_PRIMARY                        0x00
#define AUDIO_OUT_SECONDARY                      0x01

#define AUDIO_OUT_PORT_HDMI                      0x00
#define AUDIO_OUT_PORT_SPDIF                     0x01
#define AUDIO_OUT_PORT_ANALOG                    0x02
#define AUDIO_OUT_PORT_USB                       0x03
#define AUDIO_OUT_PORT_BLUETOOTH                 0x04
#define AUDIO_OUT_PORT_NETWORK                   0x05

#define AUDIO_OUT_OUTPUT_STATE_ENABLED           0x00
#define AUDIO_OUT_OUTPUT_STATE_DISABLED          0x01
#define AUDIO_OUT_OUTPUT_STATE_BUSY              0x02

#define AUDIO_OUT_DEVICE_STATE_UNAVAILABLE       0x00
#define AUDIO_OUT_DEVICE_STATE_AVAILABLE         0x01

#define AUDIO_OUT_CODING_TYPE_LPCM               0x00
#define AUDIO_OUT_CODING_TYPE_AC3                0x01
#define AUDIO_OUT_CODING_TYPE_MPEG1              0x02
#define AUDIO_OUT_CODING_TYPE_MP3                0x03
#define AUDIO_OUT_CODING_TYPE_MPEG2              0x04
#define AUDIO_OUT_CODING_TYPE_AAC                0x05
#define AUDIO_OUT_CODING_TYPE_DTS                0x06
#define AUDIO_OUT_CODING_TYPE_ATRAC              0x07
// 0x08
#define AUDIO_OUT_CODING_TYPE_DOLBY_DIGITAL_PLUS 0x09
// 0x0a
// 0x0b
#define AUDIO_OUT_CODING_TYPE_BITSTREAM          0xff

#define AUDIO_OUT_FS_32KHZ                       0x01
#define AUDIO_OUT_FS_44KHZ                       0x02
#define AUDIO_OUT_FS_48KHZ                       0x04
#define AUDIO_OUT_FS_88KHZ                       0x08
#define AUDIO_OUT_FS_96KHZ                       0x10
#define AUDIO_OUT_FS_176KHZ                      0x20
#define AUDIO_OUT_FS_192KHZ                      0x40

#define AUDIO_OUT_CHNUM_2                        0x02
#define AUDIO_OUT_CHNUM_4                        0x04
#define AUDIO_OUT_CHNUM_6                        0x06
#define AUDIO_OUT_CHNUM_8                        0x08

#define AUDIO_OUT_SBIT_NONE                      0x00
#define AUDIO_OUT_SBIT_16BIT                     0x01
#define AUDIO_OUT_SBIT_20BIT                     0x02
#define AUDIO_OUT_SBIT_24BIT                     0x04

#define AUDIO_OUT_SPEAKER_LAYOUT_DEFAULT         0x00000000
#define AUDIO_OUT_SPEAKER_LAYOUT_2CH             0x00000001
#define AUDIO_OUT_SPEAKER_LAYOUT_6CH_LREClr      0x00010000
#define AUDIO_OUT_SPEAKER_LAYOUT_8CH_LREClrxy    0x40000000

#define AUDIO_OUT_DOWNMIXER_NONE                 0x00
#define AUDIO_OUT_DOWNMIXER_TYPE_A               0x01
#define AUDIO_OUT_DOWNMIXER_TYPE_B               0x02

#define AUDIO_OUT_EVENT_DEVICE_CHANGED           0x00
#define AUDIO_OUT_EVENT_OUTPUT_DISABLED          0x01
#define AUDIO_OUT_EVENT_DEVICE_AUTHENTICATED     0x02
#define AUDIO_OUT_EVENT_OUTPUT_ENABLED           0x03

#define AUDIO_OUT_COPY_CONTROL_COPY_FREE         0x00
#define AUDIO_OUT_COPY_CONTROL_COPY_ONCE         0x01
#define AUDIO_OUT_COPY_CONTROL_COPY_NEVER        0x02

#define AUDIO_OUT_SINGLE_DEVICE_MODE             0x00
#define AUDIO_OUT_MULTI_DEVICE_MODE              0x01
#define AUDIO_OUT_MULTI_DEVICE_MODE_2            0x02

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _audioOutSoundMode
{
    u8 type;
    u8 channel;
    u8 fs;
    u8 reserved;
    u32 layout;
} audioOutSoundMode;

typedef struct _audioOutState
{
    u8 state;
    u8 encoder;
    u8 padding[6];
    u32 downMixer;
    audioOutSoundMode soundMode;
} audioOutState;

typedef struct _audioOutDeviceInfo
{
    u8 portType;
    u8 availableModeCount;
    u8 state;
    u8 padding[3];
    u16 latency;
    audioOutSoundMode availableModes[16];
} audioOutDeviceInfo;

typedef struct _audioOutConfiguration
{
    u8 channel;
    u8 encoder;
    u8 padding[10];
    u32 downMixer;
} audioOutConfiguration;

typedef struct _audioOutOption
{
    u32 reserved;
} audioOutOption;

typedef struct _audioOutSoundMode2
{
    u8 type;
    u8 channel;
    u16 fs;
    u8 padding[4];
} audioOutSoundMode2;

typedef struct _audioOutDeviceInfo2
{
    u8 portType;
    u8 availableModeCount;
    u8 state;
    u8 deviceNumber;
    u8 padding[12];
    u64 deviceId;
    u64 type;
    char name[64];
    audioOutSoundMode2 availableModes[16];
} audioOutDeviceInfo2;

typedef struct _audioOutRegistrationOption
{
    u32 reserved;
} audioOutRegistrationOption;

typedef struct _audioOutDeviceConfiguration
{
    u8 volume;
    u8 padding[31];
} audioOutDeviceConfiguration;

typedef s32 (*audioOutCallback)(u32 slot, u32 audioOut, u32 deviceIndex, u32 event, audioOutDeviceInfo *info, void *userData);

s32 audioOutRegisterCallback(u32 slot, audioOutCallback function, void *userData);
s32 audioOutUnregisterCallback(u32 slot);
s32 audioOutGetNumberOfDevice(u32 audioOut);
s32 audioOutGetDeviceInfo(u32 audioOut, u32 deviceIndex, audioOutDeviceInfo *info);
s32 audioOutGetState(u32 audioOut, u32 deviceIndex, audioOutState *state);
s32 audioOutConfigure(u32 audioOut, audioOutConfiguration *config, audioOutOption *option, u32 waitForEvent);
s32 audioOutGetConfiguration(u32 audioOut, audioOutConfiguration *config, audioOutOption *option);
s32 audioOutSetCopyControl(u32 audioOut, u32 control);
s32 audioOutGetSoundAvailability(u32 audioOut, u32 type, u32 fs, u32 option);
s32 audioOutGetSoundAvailability2(u32 audioOut, u32 type, u32 fs, u32 ch, u32 option);

//libsysutil_avconf_ext functions
s32 audioOutUnregisterDevice(u32 deviceNumber);
s32 audioOutGetDeviceInfo2(u32 deviceNumber, u32 deviceIndex, audioOutDeviceInfo2 *info);
s32 audioOutGetAvailableDeviceInfo(u32 count, audioOutDeviceInfo2 *info);
s32 audioOutRegisterDevice(u64 deviceType, const char *name, audioOutRegistrationOption *option, audioOutDeviceConfiguration *config);
s32 audioOutSetDeviceMode(u32 deviceMode);

s32 audioOutGetConfiguration2(u32 audioOut, audioOutConfiguration *config, audioOutOption *option);
s32 audioOutConfigure2(u32 audioOut, audioOutConfiguration* config, audioOutOption* option, u32 waitForEvent);

#ifdef __cplusplus
	}
#endif

#endif
