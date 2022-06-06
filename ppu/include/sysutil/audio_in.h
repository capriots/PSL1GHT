/*! \file audio_in.h
    \brief Audio input mode management.
*/

#ifndef __LV2_AUDIO_IN_H__
#define __LV2_AUDIO_IN_H__

#include <ppu-types.h>

#define AUDIO_IN_SINGLE_DEVICE_MODE       0
#define AUDIO_IN_MULTI_DEVICE_MODE        1
#define AUDIO_IN_MULTI_DEVICE_MODE_2      2
#define AUDIO_IN_MULTI_DEVICE_MODE_10     10

#define AUDIO_IN_PORT_USB                 0x03
#define AUDIO_IN_PORT_BLUETOOTH           0x04

#define AUDIO_IN_DEVICE_STATE_UNAVAILABLE 0x00
#define AUDIO_IN_DEVICE_STATE_AVAILABLE   0x01

#define AUDIO_IN_CODING_TYPE_LPCM         0x00

#define AUDIO_IN_CHNUM_NONE               0x00
#define AUDIO_IN_CHNUM_1                  0x01
#define AUDIO_IN_CHNUM_2                  0x02

#define AUDIO_IN_FS_UNDEFINED             0x00
#define AUDIO_IN_FS_8KHZ                  0x01
#define AUDIO_IN_FS_12KHZ                 0x02
#define AUDIO_IN_FS_16KHZ                 0x04
#define AUDIO_IN_FS_24KHZ                 0x08
#define AUDIO_IN_FS_32KHZ                 0x10
#define AUDIO_IN_FS_48KHZ                 0x20

#ifdef __cplusplus
extern "C" {
#endif

typedef struct audioInSoundMode
{
    u8 type;
    u8 channel;
    u16 fs;
    u8 padding[4];
} audioInSoundMode;

typedef struct audioInDeviceInfo
{
    u8 portType;
    u8 availableModeCount;
    u8 state;
    u8 deviceNumber;
    u8 padding[12];
    u64 deviceId;
    u64 type;
    char name[64];
    audioInSoundMode availableModes[16];
} audioInDeviceInfo;

typedef struct audioInDeviceConfiguration
{
    u8 volume;
    u8 padding[31];
} audioInDeviceConfiguration;

typedef struct audioInRegistrationOption
{
    u32 reserved;
} audioInRegistrationOption;

s32 audioInGetDeviceInfo(u32 deviceNumber, u32 deviceIndex, audioInDeviceInfo *info);
s32 audioInGetAvailableDeviceInfo(u32 count, audioInDeviceInfo *device_info);
s32 audioInSetDeviceMode(u32 deviceMode);
s32 audioInRegisterDevice(u64 deviceType, const char *name, audioInRegistrationOption *option, audioInDeviceConfiguration *config);
s32 audioInUnregisterDevice(u32 deviceNumber);

#ifdef __cplusplus
	}
#endif

#endif
