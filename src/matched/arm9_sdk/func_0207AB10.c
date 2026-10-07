/*
 * function: func_0207AB10
 * address:  0x0207AB10
 * packet:   pkt_0207AB10
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      FSi_InitRomArchive (libfs.TWL.HYB.a fs_proc_rom.o)
 *
 * symbols:
 *   CARD_Init  0x02075CAC  arm
 *   OS_GetLockID  0x02084EB8  arm
 *   FS_InitArchive  0x02078360  arm
 *   FS_RegisterArchiveName  0x02078384  arm
 *   OS_GetBootType  0x02087B04  arm
 *   CARD_GetOwnRomHeader  0x02075DF8  arm
 *   FS_SetArchiveProc  0x0207A5A8  arm
 *   FS_LoadArchive  0x0207A4B0  arm
 *   FSi_OverrideRomArchive  0x0207AB08  arm
 *   FS_SetCurrentDirectory  0x02077F44  arm
 *   fsi_default_dma_no  0x02150DA0  data
 *   fsi_arc_rom  0x02150DA8  data
 *   fsi_str_rom  0x020A84B0  data
 *   FSi_RomArchiveProc  0x0207AA34  arm
 *   FSi_ReadRomCallback  0x0207A9EC  arm
 *   FSi_EmptyArchiveProc  0x0207AAE4  arm
 *   FSi_ReadDummyCallback  0x0207AAF8  arm
 *   FSi_WriteDummyCallback  0x0207AB00  arm
 *   fsi_str_root  0x020A84B4  data
 */

#include "../include/G_FSiRomState.h"
#include "../include/G_fsi_arc_rom.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef long s32;
typedef int BOOL;

typedef struct FSFile FSFile;

typedef struct FSArchive
{
    u8 pad00[0x14];
    u32 flag;
} FSArchive;

typedef struct CARDRomRegion
{
    u32 offset;
    u32 length;
} CARDRomRegion;

typedef struct CARDRomHeader
{
    u8 pad00[0x40];
    CARDRomRegion fnt;
    CARDRomRegion fat;
} CARDRomHeader;

typedef struct FSiRomState FSiRomState;

extern struct FSiRomState fsi_default_dma_no;
extern struct G_fsi_arc_rom fsi_arc_rom;
extern const char fsi_str_rom[];
extern const char fsi_str_root[];

extern void CARD_Init(void);
extern s32 OS_GetLockID(void);
extern void FS_InitArchive(FSArchive *p_arc);
extern BOOL FS_RegisterArchiveName(FSArchive *p_arc, const char *name, u32 name_len);
extern u16 OS_GetBootType(void);
extern const CARDRomHeader *CARD_GetOwnRomHeader(void);
extern void FS_SetArchiveProc(FSArchive *arc, int (*proc)(FSFile *, u32), u32 flags);
extern BOOL FS_LoadArchive(FSArchive *arc, u32 base, u32 fat, u32 fat_size, u32 fnt, u32 fnt_size,
                           int (*read_func)(FSArchive *, void *, u32, u32),
                           int (*write_func)(FSArchive *, void *, u32, u32));
extern BOOL FSi_OverrideRomArchive(FSArchive *arc);
extern BOOL FS_SetCurrentDirectory(const char *path);
extern int FSi_RomArchiveProc(FSFile *p_file, u32 cmd);
extern int FSi_ReadRomCallback(FSArchive *p_arc, void *dst, u32 src, u32 len);
extern int FSi_EmptyArchiveProc(FSFile *p_file, u32 cmd);
extern int FSi_ReadDummyCallback(FSArchive *p_arc, void *dst, u32 src, u32 len);
extern int FSi_WriteDummyCallback(FSArchive *p_arc, void *dst, u32 src, u32 len);

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

void func_0207AB10(u32 default_dma_no)
{
    CARD_Init();
    fsi_default_dma_no.default_dma_no = default_dma_no;
    fsi_default_dma_no.card_lock_id = OS_GetLockID();
    FS_InitArchive(((FSArchive *)&fsi_arc_rom));
    (void)FS_RegisterArchiveName(((FSArchive *)&fsi_arc_rom), fsi_str_rom, 3);
    if (OS_GetBootType() == 1)
    {
        const CARDRomRegion *const fnt = CARD_GetRomRegionFNT();
        const CARDRomRegion *const fat = CARD_GetRomRegionFAT();

        FS_SetArchiveProc(((FSArchive *)&fsi_arc_rom), FSi_RomArchiveProc, 0x682);
        if ((fnt->offset != 0xFFFFFFFF) && (fnt->offset != 0) &&
            (fat->offset != 0xFFFFFFFF) && (fat->offset != 0))
        {
            (void)FS_LoadArchive(((FSArchive *)&fsi_arc_rom), 0, fat->offset, fat->length, fnt->offset, fnt->length,
                                 FSi_ReadRomCallback, 0);
        }
    }
    else
    {
        (void)FSi_OverrideRomArchive(((FSArchive *)&fsi_arc_rom));
    }
    if (!FS_IsArchiveLoaded(((FSArchive *)&fsi_arc_rom)))
    {
        FS_SetArchiveProc(((FSArchive *)&fsi_arc_rom), FSi_EmptyArchiveProc, 0xFFFFFFFF);
        (void)FS_LoadArchive(((FSArchive *)&fsi_arc_rom), 0, 0, 0, 0, 0, FSi_ReadDummyCallback, FSi_WriteDummyCallback);
    }
    (void)FS_SetCurrentDirectory(fsi_str_root);
}
