#ifndef __EXPORTS_H__
#define __EXPORTS_H__

/* video output support */
EXPORT(videoOutSetXVColor, 0x1cfa1a11);
EXPORT(videoOutSetupDisplay, 0x269ffedd);
EXPORT(videoOutConvertCursorColor, 0x4ec8c141);
EXPORT(videoOutGetGamma, 0x655a0364);
EXPORT(videoOutSetGamma, 0xc7020f62);
EXPORT(videoOutGetScreenSize, 0xfaa275a4);
EXPORT(videoOutSetCopyControl, 0x1a324e03);
EXPORT(videoOutConfigure2, 0x9faa12be);
EXPORT(videoOutGetResolutionAvailability2, 0x21036f4e);

/* audio output support */
EXPORT(audioOutUnregisterDevice, 0x0bddef7d);
EXPORT(audioOutGetDeviceInfo2, 0x18d0ada6);
EXPORT(audioOutGetAvailableDeviceInfo, 0xc3273d9b);
EXPORT(audioOutRegisterDevice, 0xc7087631);
EXPORT(audioOutSetDeviceMode, 0xe4645af8);
EXPORT(audioOutGetConfiguration2, 0x44d2ba34);
EXPORT(audioOutConfigure2, 0xfa611df4);

/* audio input support */
EXPORT(audioInGetDeviceInfo, 0x3d5730ce);
EXPORT(audioInGetAvailableDeviceInfo, 0x65bf9ea3);
EXPORT(audioInSetDeviceMode, 0xeb6c50fb);
EXPORT(audioInRegisterDevice, 0xeb6fcff1);
EXPORT(audioInUnregisterDevice, 0xfa6bcc17);

#endif
