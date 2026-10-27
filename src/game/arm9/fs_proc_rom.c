/*
 * file:     fs_proc_rom.c
 * unit:     yes
 * function: FSi_IsUnreadableRomOffset, FSi_OnRomReadDone, FSi_ReadRomCallback, FSi_RomArchiveProc, FSi_EmptyArchiveProc, FSi_ReadDummyCallback, FSi_WriteDummyCallback, FSi_OverrideRomArchive, FSi_InitRomArchive, FS_SetDefaultDMA, FS_TryLoadTable, FS_CreateFileFromRom
 * address:  0x0207A980
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   FS_GetArchiveName                0x02078530 arm
 *   STD_CompareString                0x0208cd94 arm
 *   OS_IsRunOnTwl                    0x02085d3c arm
 *   CARD_GetOwnRomHeader             0x02075df8 arm
 *   g_020A84B0                       0x020a84b0 data
 *   CARD_IsPulledOut                 0x020774b0 arm
 *   FS_NotifyArchiveAsyncEnd         0x02078734 arm
 *   CARDi_ReadRom                    0x020771b4 arm
 *   FSi_OnRomReadDone                0x0207a9c8 arm
 *   CARD_LockRom 0x02075E10 arm
 *   CARD_UnlockRom 0x02075E80 arm
 *   fsi_default_dma_no 0x02150DA0 data
 *   CARD_Init  0x02075CAC  arm
 *   OS_GetLockID  0x02084EB8  arm
 *   FS_InitArchive  0x02078360  arm
 *   FS_RegisterArchiveName  0x02078384  arm
 *   OS_GetBootType  0x02087B04  arm
 *   FS_SetArchiveProc  0x0207A5A8  arm
 *   FS_LoadArchive  0x0207A4B0  arm
 *   FSi_OverrideRomArchive  0x0207AB08  arm
 *   FS_SetCurrentDirectory  0x02077F44  arm
 *   fsi_default_dma_no  0x02150DA0  data
 *   fsi_arc_rom  0x02150DA8  data
 *   fsi_str_rom  0x020A84B0  data
 *   FSi_ReadRomCallback  0x0207A9EC  arm
 *   fsi_str_root  0x020A84B4  data
 *   OS_DisableInterrupts  0x02087988  arm
 *   FS_SuspendArchive  0x02078648  arm
 *   FS_ResumeArchive  0x020786D8  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   FS_LoadArchiveTables   0x0207A5C8  arm
 *   fsi_arc_rom      0x02150DA8  data  a4
 *   FS_OpenFileDirect  0x02078964  arm
 */
#define FS_COMMAND_READFILE        0
#define FS_COMMAND_WRITEFILE       1
#define FS_COMMAND_SEEKDIR         2
#define FS_COMMAND_READDIR         3
#define FS_COMMAND_FINDPATH        4
#define FS_COMMAND_GETPATH         5
#define FS_COMMAND_OPENFILEFAST    6
#define FS_COMMAND_OPENFILEDIRECT  7
#define FS_COMMAND_CLOSEFILE       8
#define FS_COMMAND_ACTIVATE        9
#define FS_COMMAND_IDLE            10
#define FS_COMMAND_SUSPEND         11
#define FS_COMMAND_RESUME          12
#define FS_COMMAND_OPENFILE        13
#define FS_COMMAND_SEEKFILE        14
#define FS_COMMAND_GETFILELENGTH   15
#define FS_COMMAND_GETFILEPOSITION 16
#define FS_COMMAND_MOUNT           17
#define FS_COMMAND_UNMOUNT         18
#include "../sdk_fs.h"

#include "../types.h"

#include "../sdk_os.h"

#include "../sdk_os_thread.h"

#include "../sdk_card.h"

typedef struct FSiRomState
{
    u32 default_dma_no;
    s32 card_lock_id;
} FSiRomState;

#include "fs_archive.h"
#include "std_string.h"
#include "os_emulator.h"
#include "card_pullout.h"
extern void CARDi_ReadRom(u32 dma, const void *src, void *dst, u32 len,
                          void (*callback)(void *), void *arg, int is_async);
#include "card_api.h"
#include "os_spinlock.h"
#include "os_systemwork.h"
#include "fs_proc_default.h"
#include "os_system.h"
#include "fs_file.h"
int FSi_IsUnreadableRomOffset(FSArchive *arc, u32 offset);
FSResult FSi_RomArchiveProc(FSFile *file, FSCommandType cmd);
FSResult FSi_EmptyArchiveProc(FSFile *file, FSCommandType cmd);
FSResult FSi_ReadDummyCallback(FSArchive *p_arc, void *dst, u32 src, u32 len);
FSResult FSi_WriteDummyCallback(FSArchive *p_arc, const void *src, u32 pos, u32 len);
BOOL FSi_OverrideRomArchive(FSArchive *arc);
void FSi_InitRomArchive(u32 default_dma_no);
u32 FS_SetDefaultDMA(u32 dma_no);
u32 FS_TryLoadTable(void *p_mem, u32 size);
BOOL FS_CreateFileFromRom(FSFile *p_file, u32 offset, u32 size);
extern FSiRomState fsi_default_dma_no;
extern FSArchive fsi_arc_rom;
extern const char fsi_str_rom[];
extern const char fsi_str_root[];

static void FSi_OnRomReadDone(void *arg);

static FSResult FSi_ReadRomCallback(FSArchive *p_arc, void *dst, u32 src, u32 len);

/*
 * sdk:      FSi_IsUnreadableRomOffset (fs_proc_rom.o)
 */
int FSi_IsUnreadableRomOffset(FSArchive *arc, u32 offset)
{
    int result = 0;

    if (STD_CompareString(FS_GetArchiveName(arc), fsi_str_rom) == 0 && !OS_IsRunOnTwl()) {
        const CARDRomHeader *header = CARD_GetOwnRomHeader();
        if (offset >= (u32)header->twl_ltd_area_rom_offset * 0x80000) {
            result = 1;
        }
    }
    return result;
}

/*
 * sdk:      FSi_OnRomReadDone (fs_proc_rom.o)
 */
static void FSi_OnRomReadDone(void *arg)
{
    FS_NotifyArchiveAsyncEnd((FSArchive *)arg, CARD_IsPulledOut() ? FS_RESULT_ERROR : FS_RESULT_SUCCESS);
}

/*
 * sdk:      FSi_ReadRomCallback (fs_proc_rom.o)
 */
static FSResult FSi_ReadRomCallback(FSArchive *p_arc, void *dst, u32 src, u32 len)
{
    CARDi_ReadRom(fsi_default_dma_no.default_dma_no, (const void *)(uptr)src, dst, len, FSi_OnRomReadDone, p_arc, 1);
    return FS_RESULT_PROC_ASYNC;
}

FSResult FSi_RomArchiveProc(FSFile *file, FSCommandType cmd)
{
    switch (cmd) {
    case FS_COMMAND_ACTIVATE:
        CARD_LockRom((u16)fsi_default_dma_no.card_lock_id);
        return FS_RESULT_SUCCESS;
    case FS_COMMAND_IDLE:
        CARD_UnlockRom((u16)fsi_default_dma_no.card_lock_id);
        return FS_RESULT_SUCCESS;
    case FS_COMMAND_OPENFILEDIRECT:
        if (FSi_IsUnreadableRomOffset(file->arc, file->arg.openfiledirect.top)) {
            return FS_RESULT_PERMISSION_DENIED;
        }
        return FS_RESULT_PROC_DEFAULT;
    case FS_COMMAND_WRITEFILE:
        return FS_RESULT_UNSUPPORTED;
    default:
        return FS_RESULT_PROC_UNKNOWN;
    }
}

FSResult FSi_EmptyArchiveProc(FSFile *file, FSCommandType cmd)
{
    return (cmd == FS_COMMAND_WRITEFILE) ? FS_RESULT_UNSUPPORTED : FS_RESULT_PROC_UNKNOWN;
}

/*
 * sdk:      FSi_ReadDummyCallback (libfs.TWL.HYB.a fs_proc_rom.o, static; no catalog row, named by the ABS32 relocation of its caller)
 */
FSResult FSi_ReadDummyCallback(FSArchive *p_arc, void *dst, u32 src, u32 len)
{
    return FS_RESULT_UNSUPPORTED;
}

/*
 * sdk:      FSi_WriteDummyCallback (libfs.TWL.HYB.a fs_proc_rom.o, static; no catalog row, named by the ABS32 relocation of its caller)
 */
FSResult FSi_WriteDummyCallback(FSArchive *p_arc, const void *src, u32 pos, u32 len)
{
    return FS_RESULT_UNSUPPORTED;
}

BOOL FSi_OverrideRomArchive(FSArchive *arc)
{
    return 0;
}

static inline const CARDRomRegion *CARD_GetRomRegionFNT(void)
{
    return &CARD_GetOwnRomHeader()->fnt;
}

static inline const CARDRomRegion *CARD_GetRomRegionFAT(void)
{
    return &CARD_GetOwnRomHeader()->fat;
}

static inline BOOL FS_IsArchiveLoaded(volatile const FSArchive *arc)
{
    return (arc->flag & 2) ? 1 : 0;
}

/*
 * sdk:      FSi_InitRomArchive (libfs.TWL.HYB.a fs_proc_rom.o)
 */
void FSi_InitRomArchive(u32 default_dma_no)
{
    CARD_Init();
    fsi_default_dma_no.default_dma_no = default_dma_no;
    fsi_default_dma_no.card_lock_id = OS_GetLockID();
    FS_InitArchive(&fsi_arc_rom);
    (void)FS_RegisterArchiveName(&fsi_arc_rom, fsi_str_rom, 3);
    if (OS_GetBootType() == 1)
    {
        const CARDRomRegion *const fnt = CARD_GetRomRegionFNT();
        const CARDRomRegion *const fat = CARD_GetRomRegionFAT();

        FS_SetArchiveProc(&fsi_arc_rom, (uptr)FSi_RomArchiveProc, 0x682);
        if ((fnt->offset != 0xFFFFFFFF) && (fnt->offset != 0) &&
            (fat->offset != 0xFFFFFFFF) && (fat->offset != 0))
        {
            (void)FS_LoadArchive(&fsi_arc_rom, 0, fat->offset, fat->length, fnt->offset, fnt->length,
                                 FSi_ReadRomCallback, 0);
        }
    }
    else
    {
        (void)FSi_OverrideRomArchive(&fsi_arc_rom);
    }
    if (!FS_IsArchiveLoaded(&fsi_arc_rom))
    {
        FS_SetArchiveProc(&fsi_arc_rom, (uptr)FSi_EmptyArchiveProc, 0xFFFFFFFF);
        (void)FS_LoadArchive(&fsi_arc_rom, 0, 0, 0, 0, 0, FSi_ReadDummyCallback, FSi_WriteDummyCallback);
    }
    (void)FS_SetCurrentDirectory(fsi_str_root);
}

/*
 * sdk:      FS_SetDefaultDMA (libfs.TWL.HYB.a fs_proc_rom.o)
 */
u32 FS_SetDefaultDMA(u32 dma_no)
{
    u32 bak_psr = OS_DisableInterrupts();
    u32 bak_dma_no = fsi_default_dma_no.default_dma_no;
    BOOL bak_stat = FS_SuspendArchive(&fsi_arc_rom);

    fsi_default_dma_no.default_dma_no = dma_no;
    if (bak_stat)
    {
        (void)FS_ResumeArchive(&fsi_arc_rom);
    }
    (void)OS_RestoreInterrupts(bak_psr);
    return bak_dma_no;
}

u32 FS_TryLoadTable(void *p_mem, u32 size)
{
    return FS_LoadArchiveTables(&fsi_arc_rom, p_mem, size);
}

/*
 * sdk:      FS_CreateFileFromRom (libfs.TWL.HYB.a fs_proc_rom.o)
 */
BOOL FS_CreateFileFromRom(FSFile *p_file, u32 offset, u32 size)
{
    return FS_OpenFileDirect(p_file, &fsi_arc_rom, offset, offset + size, 0xFFFF);
}
