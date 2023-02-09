#ifndef __EXPORTS_H__
#define __EXPORTS_H__


EXPORT(sysModuleInitialize, 0x63ff6ff9);
EXPORT(sysModuleFinalize, 0x96c07adf);

EXPORT(sysModuleLoad, 0x32267A31);
EXPORT(sysModuleUnload, 0x112A5EE9);
EXPORT(sysModuleIsLoaded, 0x5a59e258);

EXPORT(sysModuleGetImagesize, 0x1ef115ef);
EXPORT(sysModuleFetchImage, 0x3c92be09);
EXPORT(sysModuleSetMemcontainer, 0xa193143c);

EXPORT(sysModuleLoadInternal, 0xd9b8c0ee);
EXPORT(sysModuleUnloadInternal, 0xb498bf77);
EXPORT(sysModuleLoadEx, 0x1a267f98);
EXPORT(sysModuleUnloadEx, 0xfd0e1cac);
EXPORT(sysModuleIsLoadedEx, 0x70e319b5);

EXPORT(sysModule_0x002CD0BF, 0x002cd0bf);
EXPORT(sysModule_0x03D90241, 0x03d90241);
EXPORT(sysModule_0x205FE2A0, 0x205fe2a0);
EXPORT(sysModule_0x59521326, 0x59521326);
EXPORT(sysModule_0xC93200DE, 0xc93200de);


#endif
