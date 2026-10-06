/*
 * function: func_02078D34
 * address:  0x02078D34
 * packet:   pkt_02078D34
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * notes:    bytes identical; SDK_OVERLAY_NUMBER (0xED) resolves under the `linker` class (undefined in fs_overlay.o and in libfs; value = layout.json counts.overlays)
 *
 * sdk:      FS_LoadOverlayInfo (libfs.TWL.HYB.a fs_overlay.o)
 *
 * symbols:
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   FS_InitFile  0x020788AC  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   FS_GetOverlayFileID  0x02078D08  arm
 *   FS_OpenFileFast  0x020789A4  arm
 *   CARD_GetOwnRomHeader  0x02075DF8  arm
 *   FS_CreateFileFromRom  0x0207ACD4  arm
 *   FS_ReadFile  0x02078B70  arm
 *   FS_CloseFile  0x02078A80  arm
 *   FS_GetFileImageTop  0x0207A7BC  arm
 *   FS_GetFileLength  0x02078A94  arm
 *   FSiOverlayContext  0x02150D24  data
 *   SDK_OVERLAY_NUMBER  0x000000ED  data
 */

typedef unsigned char u8;
typedef unsigned long u32;
typedef long s32;
typedef int BOOL;

typedef struct OSThread OSThread;

typedef struct OSThreadQueue
{
    OSThread *head;
    OSThread *tail;
} OSThreadQueue;

typedef struct FSArchive FSArchive;

typedef struct FSFile
{
    struct FSFile *next;
    void *userdata;
    FSArchive *arc;
    u32 stat;
    void *argument;
    int error;
    OSThreadQueue queue[1];
    u8 prop[16];
    u8 arg[24];
} FSFile;


typedef struct FSFileID
{
    FSArchive *arc;
    u32 file_id;
} FSFileID;

typedef struct CARDRomRegion
{
    u32 offset;
    u32 length;
} CARDRomRegion;

typedef struct CARDRomHeader
{
    u8 pad00[0x50];
    CARDRomRegion main_ovt;
    CARDRomRegion sub_ovt;
} CARDRomHeader;

typedef struct FSOverlayInfo
{
    u8 header[0x20];
    int target;
    CARDRomRegion file_pos;
} FSOverlayInfo;

typedef struct FSOverlaySource
{
    u8 *buffer;
    u32 length;
} FSOverlaySource;

typedef struct FSiOverlayContext
{
    FSArchive *arc;
    FSOverlaySource source[2];
} FSiOverlayContextType;

extern FSiOverlayContextType FSiOverlayContext;
extern u8 SDK_OVERLAY_NUMBER[];

extern BOOL OS_IsRunOnTwl(void);
extern void FS_InitFile(FSFile *file);
extern void MI_CpuCopy8(const void *srcp, void *dstp, u32 size);
extern FSFileID FS_GetOverlayFileID(FSOverlayInfo *p_ovi);
extern BOOL FS_OpenFileFast(FSFile *file, FSFileID id);
extern const CARDRomHeader *CARD_GetOwnRomHeader(void);
extern BOOL FS_CreateFileFromRom(FSFile *p_file, u32 offset, u32 size);
extern s32 FS_ReadFile(FSFile *file, void *buffer, s32 length);
extern BOOL FS_CloseFile(FSFile *file);
extern u32 FS_GetFileImageTop(FSFile *file);
extern u32 FS_GetFileLength(FSFile *file);

BOOL func_02078D34(FSOverlayInfo *p_ovi, u32 target, u32 id)
{
    BOOL retval = 0;
    const u32 pos = id * 32;
    FSOverlaySource *const src = (target == 0) ? &FSiOverlayContext.source[0] : &FSiOverlayContext.source[1];

    if ((id < (u32)SDK_OVERLAY_NUMBER) || OS_IsRunOnTwl())
    {
        if (src->buffer)
        {
            if (pos < src->length)
            {
                FSFile file[1];

                FS_InitFile(file);
                MI_CpuCopy8(src->buffer + pos, p_ovi, 32);
                p_ovi->target = target;
                if (FS_OpenFileFast(file, FS_GetOverlayFileID(p_ovi)))
                {
                    p_ovi->file_pos.offset = FS_GetFileImageTop(file);
                    p_ovi->file_pos.length = FS_GetFileLength(file);
                    (void)FS_CloseFile(file);
                    retval = 1;
                }
            }
        }
        else
        {
            const CARDRomRegion *const pr = (target == 0) ? &CARD_GetOwnRomHeader()->main_ovt : &CARD_GetOwnRomHeader()->sub_ovt;

            if (pos < pr->length)
            {
                FSFile file[1];

                FS_InitFile(file);
                if (FS_CreateFileFromRom(file, pr->offset + pos, pr->offset + pr->length))
                {
                    if (FS_ReadFile(file, p_ovi, 32) != 32)
                    {
                        (void)FS_CloseFile(file);
                    }
                    else
                    {
                        (void)FS_CloseFile(file);
                        p_ovi->target = target;
                        if (FS_OpenFileFast(file, FS_GetOverlayFileID(p_ovi)))
                        {
                            p_ovi->file_pos.offset = FS_GetFileImageTop(file);
                            p_ovi->file_pos.length = FS_GetFileLength(file);
                            (void)FS_CloseFile(file);
                            retval = 1;
                        }
                    }
                }
            }
        }
    }
    return retval;
}
