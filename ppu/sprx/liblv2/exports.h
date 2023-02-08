#ifndef __EXPORTS_H__
#define __EXPORTS_H__


/* system */
EXPORT(sysGetSystemTime, 0x8461e528); // sys_time_get_system_time
EXPORT(sysGetSystemSwVersion, 0x620e35a7); // sys_game_get_system_sw_version
EXPORT(sysGetTemperature, 0x3172759d); // sys_game_get_temperature
EXPORT(sysGetRandomNumber, 0x71a8472a); // sys_get_random_number
EXPORT(sysGetRtcStatus, 0x9f950780); // sys_game_get_rtc_status
EXPORT(sysGetBdMediaId, 0xef666b52); // sys_get_bd_media_id
EXPORT(sysGetConsoleId, 0xf220f751); // sys_get_console_id
EXPORT(sysSetDiscAccessControl, 0xa84fd3c3); // unknown name, calls syscall sys_ss_disc_access_control
EXPORT(sysGetDiscAccessControl, 0xbb7cd1ae); // unknown name, calls syscall sys_ss_disc_access_control

/* board storage */
EXPORT(sysBoardStorageRead, 0xe76964f5); // sys_game_board_storage_read
EXPORT(sysBoardStorageWrite, 0x8bb03ab8); // sys_game_board_storage_write

/* processes */
EXPORT(sysProcessIsStack, 0x4f7172c9); // sys_process_is_stack
EXPORT(sysProcessExit, 0xe6f2c1e7); // sys_process_exit
EXPORT(sysProcessExitspawn, 0xfc52a7a9); // sys_game_process_exitspawn
EXPORT(sysProcessExitSpawn2Ex, 0x67f9fedb); // sys_game_process_exitspawn2
EXPORT(sysProcessAtExitSpawn, 0x2c847572); // _sys_process_atexitspawn
EXPORT(sysProcess_At_ExitSpawn, 0x96328741); // _sys_process_at_Exitspawn

EXPORT(_sys_process_wait_for_game_process, 0xBAB62B99);
EXPORT(sysProcessAtexit, 0xde2f9c85); // sys_process_atexit
EXPORT(sysProcessGetParamsfo, 0xe75c40f2); // sys_process_get_paramsfo
EXPORT(sysProcessSpawn, 0x9d2ec4ff); // sys_process_spawn
EXPORT(sysProcessSpawnWithMemoryBudget, 0xbf8ee5bb); // sys_process_spawn_with_memory_budget
EXPORT(sysProcessWaitForGameProcess, 0xe95ffa0a); // sys_process_wait_for_game_process

/* prx handling */
EXPORT(sysPrxRegisterLibrary, 0x42b23552); // sys_prx_register_library
EXPORT(sysPrxUnregisterLibrary, 0xd0ea47a7); // sys_prx_unregister_library
EXPORT(sysPrxStartModule, 0x9f18429d); // sys_prx_start_module
EXPORT(sysPrxStopModule, 0x80fb0c19); // sys_prx_stop_module
EXPORT(sysPrxLoadModule, 0x26090058); // sys_prx_load_module
EXPORT(sysPrxLoadModuleByFd, 0xef68c17c); // sys_prx_load_module_by_fd
EXPORT(sysPrxLoadModuleList, 0xb27c8ae7); // sys_prx_load_module_list
EXPORT(sysPrxLoadModuleListOnMemcontainer, 0xe7ef3a80); // sys_prx_load_module_list_on_memcontainer
EXPORT(sysPrxLoadModuleOnMemcontainer, 0xaa6d9bff); // sys_prx_load_module_on_memcontainer
EXPORT(sysPrxLoadModuleOnMemcontainerByFd, 0xa330ad84); // sys_prx_load_module_on_memcontainer_by_fd
EXPORT(sysPrxGetModuleInfo, 0x84bb6774); // sys_prx_get_module_info
EXPORT(sysPrxGetModuleList, 0xa5d06bf0); // sys_prx_get_module_list
EXPORT(sysPrxGetModuleId, 0x74311398); // sys_prx_get_my_module_id
EXPORT(sysPrxGetModuleIdByAddress, 0x0341bb97); // sys_prx_get_module_id_by_address
EXPORT(sysPrxGetModuleIdByName, 0xe0998dbf); // sys_prx_get_module_id_by_name
EXPORT(sysPrxUnloadModule, 0xf0aece0d); // sys_prx_unload_module
EXPORT(sysPrxExitSpawnWithLevel, 0xa2c7ba64); // sys_prx_exitspawn_with_level

/* thread handling */
EXPORT(sysThreadCreateEx, 0x24a1ea07); // sys_ppu_thread_create
EXPORT(sysThreadExit, 0xaff080a4); // sys_ppu_thread_exit
EXPORT(sysThreadGetId, 0x350d454e); // sys_ppu_thread_get_id
EXPORT(sysThreadOnce, 0xa3e3be68); // sys_ppu_thread_once
EXPORT(sysThreadInitialzeTLS, 0x744680a2); // sys_initialize_tls
EXPORT(sysThreadRegisterAtexit, 0x3dd4a957); // sys_ppu_thread_register_atexit
EXPORT(sysThreadUnregisterAtexit, 0xac6fc404); // sys_ppu_thread_unregister_atexit

/* thread interupt handling */
EXPORT(sysInterruptThreadDisestablish, 0x4a071d98); // sys_interrupt_thread_disestablish

/* mutex handling */
EXPORT(sysLwMutexCreate, 0x2f85c0ef); // sys_lwmutex_create
EXPORT(sysLwMutexDestroy, 0xc3476d0c); // sys_lwmutex_destroy
EXPORT(sysLwMutexLock, 0x1573dc3f); // sys_lwmutex_lock
EXPORT(sysLwMutexTryLock, 0xaeb78725); // sys_lwmutex_trylock
EXPORT(sysLwMutexUnlock, 0x1bc200f4); // sys_lwmutex_unlock

/* cond variable handling */
EXPORT(sysLwCondCreate, 0xda0eb71a); // sys_lwcond_create
EXPORT(sysLwCondWait, 0x2a6d9d51); // sys_lwcond_wait
EXPORT(sysLwCondSignal, 0xef87a695); // sys_lwcond_signal
EXPORT(sysLwCondSignalTo, 0x52aadadf); // sys_lwcond_signal_to
EXPORT(sysLwCondSignalAll, 0xe9a1bd84); // sys_lwcond_signal_all
EXPORT(sysLwCondDestroy, 0x1c9a942c); // sys_lwcond_destroy

/* spinlock handling */
EXPORT(sysSpinlockInitialize, 0x8c2bb498); // sys_spinlock_initialize
EXPORT(sysSpinlockLock, 0xa285139d); // sys_spinlock_lock
EXPORT(sysSpinlockTryLock, 0x722a0254); // sys_spinlock_trylock
EXPORT(sysSpinlockUnlock, 0x5267cb35); // sys_spinlock_unlock

/* watchdog */
EXPORT(sysWatchdogClear, 0xacad8fb6); // sys_game_watchdog_clear
EXPORT(sysWatchdogStart, 0x9e0623b5); // sys_game_watchdog_start
EXPORT(sysWatchdogStop, 0x6e05231d); // sys_game_watchdog_stop

/* memory handling */
EXPORT(sysMalloc, 0xbdb18f83); // _sys_malloc
EXPORT(sysMemalign, 0x318f17e1); // _sys_memalign
EXPORT(sysMemchr, 0x3bd53c7b); // _sys_memchr
EXPORT(sysMemcmp, 0xfb5db080); // _sys_memcmp
EXPORT(sysMemcpy, 0x6bf66ea7); // _sys_memcpy
EXPORT(sysMemmove, 0x27427742); // _sys_memmove
EXPORT(sysMemset, 0x68b9b011); // _sys_memset
EXPORT(sysFree, 0xf7f7fb20); // _sys_free

/* heap handling */
EXPORT(sysHeapAllocHeapMemory, 0xb9bf1078); // _sys_heap_alloc_heap_memory
EXPORT(sysHeapCreateHeap, 0xb2fcf2c8); // _sys_heap_create_heap
EXPORT(sysHeapDeleteHeap, 0xaede4b03); // _sys_heap_delete_heap
EXPORT(sysHeapFree, 0x8a561d92); // _sys_heap_free
EXPORT(sysHeapGetMallInfo, 0xd1ad4570); // _sys_heap_get_mallinfo
EXPORT(sysHeapGetTotalFreeSize, 0xb6369393); // _sys_heap_get_total_free_size
EXPORT(sysHeapMalloc, 0x35168520); // _sys_heap_malloc
EXPORT(sysHeapMemalign, 0x44265c08); // _sys_heap_memalign
EXPORT(sysHeapStats, 0x8985b5b6); // _sys_heap_stats

/* quicksort */
EXPORT(sysQsort, 0xc4fd6121); // _sys_qsort

/* memory pool */
EXPORT(sysMempoolCreate, 0xca9a60bf); // sys_mempool_create
EXPORT(sysMempoolDestroy, 0x9d3c0f81); // sys_mempool_destroy
EXPORT(sysMempoolGetCount, 0x25596f51); // sys_mempool_get_count
EXPORT(sysMempoolAllocateBlock, 0xa146a143); // sys_mempool_allocate_block
EXPORT(sysMempoolTryAllocateBlock, 0x05c65656); // sys_mempool_try_allocate_block
EXPORT(sysMempoolFreeBlock, 0x608212fc); // sys_mempool_free_block

/* memory management */
EXPORT(sysMMapperFreeMemory, 0x409ad939); // sys_mmapper_free_memory
EXPORT(sysMMapperMapMemory, 0xdc578057); // sys_mmapper_map_memory
EXPORT(sysMMapperUnmapMemory, 0x4643ba6e); // sys_mmapper_unmap_memory
EXPORT(sysMMapperAllocateMemory, 0xb257540b); // sys_mmapper_allocate_memory
EXPORT(sysMMapperAllocateMemoryFromContainer, 0x70258515); // sys_mmapper_allocate_memory_from_container

/* strings */
EXPORT(sysStrlen, 0x2d36462b); // _sys_strlen
EXPORT(sysStrcpy, 0x99c88692); // _sys_strcpy
EXPORT(sysStrncpy, 0xd3039d4d); // _sys_strncpy
EXPORT(sysStrcat, 0x052d29a6); // _sys_strcat
EXPORT(sysStrncat, 0x996f7cf8); // _sys_strncat
EXPORT(sysStrchr, 0x7498887b); // _sys_strchr
EXPORT(sysStrrchr, 0x191f0c4a); // _sys_strrchr
EXPORT(sysStrcmp, 0x459b4393); // _sys_strcmp
EXPORT(sysStrncmp, 0x04e83d2c); // _sys_strncmp
EXPORT(sysStrncasecmp, 0x1ca525a2); // _sys_strncasecmp
EXPORT(sysToLower, 0x4b2f301a); // _sys_tolower
EXPORT(sysToUpper, 0xeef75113); // _sys_toupper

/* spu handling */
EXPORT(sysSpuElfGetSegments, 0xdb6b3250); // sys_spu_elf_get_segments
EXPORT(sysSpuElfGetInformation, 0x1ed454ce); // sys_spu_elf_get_information
EXPORT(sysSpuRawLoad, 0x893305fa); // sys_raw_spu_load
EXPORT(sysSpuRawImageLoad, 0xb995662e); // sys_raw_spu_image_load
EXPORT(sysSpuImageClose, 0xe0da8efd); // sys_spu_image_close
EXPORT(sysSpuImageImport, 0xebe5f72f); // sys_spu_image_import

/* the following exports are renamed due to our own _working_ implementation */
EXPORT(sysSpuPrintfAttachGroupEx, 0xdd0c1e09); // _sys_spu_printf_attach_group
EXPORT(sysSpuPrintfAttachThreadEx, 0x1ae10b92); // _sys_spu_printf_attach_thread
EXPORT(sysSpuPrintfDetachGroupEx, 0x5fdfb2fe); // _sys_spu_printf_detach_group
EXPORT(sysSpuPrintfDetachThreadEx, 0xb3bbcf2a); // _sys_spu_printf_detach_thread
EXPORT(sysSpuPrintfFinalizeEx, 0xdd3b27ac); // _sys_spu_printf_finalize
EXPORT(sysSpuPrintfInitializeEx, 0x45fe2fce); // _sys_spu_printf_initialize

/* console */
EXPORT(sysConsoleGetc, 0x8a2f159b); // console_getc
EXPORT(sysConsolePutc, 0xe66bac36); // console_putc
EXPORT(sysConsoleWrite, 0xf57e1d6f); // console_write
EXPORT(sysPrintf, 0x9f04f7af); // _sys_printf
EXPORT(sysSprintf, 0xa1f9eafe); // _sys_sprintf
EXPORT(sysSnprintf, 0x06574237); // _sys_snprintf
EXPORT(sysVprintf, 0xfa7f693d); // _sys_vprintf
EXPORT(sysVsprintf, 0x791b9219); // _sys_vsprintf
EXPORT(sysVsnprintf, 0x0618936b); // _sys_vsnprintf

/* rsxaudio */
EXPORT(sysRsxaudioInitialize, 0xc839bb4c); // sys_rsxaudio_initialize
EXPORT(sysRsxaudioFinalize, 0x87c87495); // sys_rsxaudio_finalize
EXPORT(sysRsxaudioImportSharedMemory, 0x2f256b29); // sys_rsxaudio_import_shared_memory
EXPORT(sysRsxaudioUnimportSharedMemory, 0x39e9b068); // sys_rsxaudio_unimport_shared_memory
EXPORT(sysRsxaudioCreateConnection, 0xa9879a33); // sys_rsxaudio_create_connection
EXPORT(sysRsxaudioCloseConnection, 0xb1bd7a61); // sys_rsxaudio_close_connection
EXPORT(sysRsxaudioPrepareProcess, 0x7b034c78); // sys_rsxaudio_prepare_process
EXPORT(sysRsxaudioStartProcess, 0x9c9605ee); // sys_rsxaudio_start_process
EXPORT(sysRsxaudioStopProcess, 0xff34c76c); // sys_rsxaudio_stop_process
EXPORT(sysRsxaudioGetDmaParam, 0x094ff0d1); // unknown name, calls syscall sys_rsxaudio_get_dma_param


EXPORT(__sys_look_ctype_table, 0x3ef17f8c);
EXPORT(__sys_printf_basename, 0x02e20ec1);
EXPORT(__sys_time, 0xfecc05b6);
EXPORT(__tls_get_addr, 0x8cfef376);
EXPORT(_proc_spawn, 0x637bdaae);
EXPORT(_sys_net_eurus_post_command, 0x4bbf59d0);
EXPORT(_sys_panic, 0x4232b0db);

EXPORT(sysPrxForUser_0x0FB028AF, 0x0fb028af);
EXPORT(sysPrxForUser_0x121E5DA5, 0x121e5da5);
EXPORT(sysPrxForUser_0x25062C8E, 0x25062c8e);
EXPORT(sysPrxForUser_0x728FD7C3, 0x728fd7c3);
EXPORT(sysPrxForUser_0x750DD5CD, 0x750dd5cd);
EXPORT(sysPrxForUser_0x7DAFF8BB, 0x7daff8bb);
EXPORT(sysPrxForUser_0x92A7EB40, 0x92a7eb40);
EXPORT(sysPrxForUser_0x9FB6228E, 0x9fb6228e);
EXPORT(sysPrxForUser_0xB5D5F64E, 0xb5d5f64e);
EXPORT(sysPrxForUser_0xD19688BC, 0xd19688bc);
EXPORT(sysPrxForUser_0xD66C2D52, 0xd66c2d52);
EXPORT(sysPrxForUser_0xD8A6F882, 0xd8a6f882);
EXPORT(sysPrxForUser_0xDE0C682C, 0xde0c682c);
EXPORT(sysPrxForUser_0xEDEA5F4A, 0xedea5f4a);
EXPORT(sysPrxForUser_0xF82CF400, 0xf82cf400);
EXPORT(sysPrxForUser_0xF923DADA, 0xf923dada);

#endif
