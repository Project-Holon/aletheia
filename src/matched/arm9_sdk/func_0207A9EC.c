/*
 * function: FSi_ReadRomCallback
 * address:  0x0207A9EC
 * packet:   pkt_0207A9EC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      FSi_ReadRomCallback (fs_proc_rom.o)
 *
 * symbols:
 *   CARDi_ReadRom                    0x020771b4 arm
 *   FSi_OnRomReadDone                0x0207a9c8 arm
 *   fsi_default_dma_no               0x02150da0 data
 */

typedef struct FSArchive FSArchive;

typedef enum FSResult {
    FS_RESULT_SUCCESS = 0,
    FS_RESULT_FAILURE,
    FS_RESULT_BUSY,
    FS_RESULT_CANCELED,
    FS_RESULT_UNSUPPORTED,
    FS_RESULT_ERROR,
    FS_RESULT_PROC_ASYNC = 0x100
} FSResult;

extern void CARDi_ReadRom(unsigned long dma, const void *src, void *dst, unsigned long len,
                          void (*callback)(void *), void *arg, int is_async);
extern void func_0207A9C8(void *arg);
extern unsigned long fsi_default_dma_no;

static FSResult FSi_ReadRomCallback(FSArchive *p_arc, void *dst, unsigned long src, unsigned long len)
{
    CARDi_ReadRom(fsi_default_dma_no, (const void *)src, dst, len, func_0207A9C8, p_arc, 1);
    return FS_RESULT_PROC_ASYNC;
}
