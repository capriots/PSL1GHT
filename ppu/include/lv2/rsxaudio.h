/*! \file lv2/rsxaudio.h
*/

#ifndef __LV2_RSXAUDIO_H__
#define __LV2_RSXAUDIO_H__

#include <ppu-types.h>


#ifdef __cplusplus
extern "C" {
#endif

s32 sysRsxaudioInitialize(u32 *handle);
s32 sysRsxaudioFinalize(u32 handle);
s32 sysRsxaudioImportSharedMemory(u32 handle, u64 *addr);
s32 sysRsxaudioUnimportSharedMemory(u32 handle, u64 *addr);
s32 sysRsxaudioCreateConnection(u32 handle);
s32 sysRsxaudioCloseConnection(u32 handle);
s32 sysRsxaudioPrepareProcess(u32 handle);
s32 sysRsxaudioStartProcess(u32 handle);
s32 sysRsxaudioStopProcess(u32 handle);
s32 sysRsxaudioGetDmaParam(u32 handle, u32 flag, u64 *param);

#ifdef __cplusplus
}
#endif

#endif
