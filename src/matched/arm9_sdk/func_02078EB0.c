/*
 * function: FS_LoadOverlayImage
 * address:  0x02078EB0
 * packet:   pkt_02078EB0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      FS_LoadOverlayImage (libfs.TWL.HYB.a fs_overlay.o)
 *
 * symbols:
 *   FS_InitFile  0x020788AC  arm
 *   FS_GetOverlayFileID  0x02078D08  arm
 *   FS_OpenFileFast  0x020789A4  arm
 *   FSi_GetOverlayBinarySize  0x02078CB0  arm
 *   FS_ClearOverlayImage  0x02078CCC  arm
 *   FS_ReadFile  0x02078B70  arm
 *   FS_CloseFile  0x02078A80  arm
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

typedef struct FSOverlayInfo
{
    u32 id;
    u8 *ram_address;
} FSOverlayInfo;

extern void FS_InitFile(FSFile *file);
extern FSFileID FS_GetOverlayFileID(FSOverlayInfo *p_ovi);
extern BOOL FS_OpenFileFast(FSFile *file, FSFileID id);
extern u32 FSi_GetOverlayBinarySize(FSOverlayInfo *p_ovi);
extern void FS_ClearOverlayImage(FSOverlayInfo *p_ovi);
extern s32 FS_ReadFile(FSFile *file, void *buffer, s32 length);
extern BOOL FS_CloseFile(FSFile *file);

BOOL FS_LoadOverlayImage(FSOverlayInfo *p_ovi)
{
    BOOL retval = 0;
    FSFile p_file[1];

    FS_InitFile(p_file);
    if (FS_OpenFileFast(p_file, FS_GetOverlayFileID(p_ovi)))
    {
        s32 size = (s32)FSi_GetOverlayBinarySize(p_ovi);

        FS_ClearOverlayImage(p_ovi);
        if (FS_ReadFile(p_file, p_ovi->ram_address, size) == size)
        {
            retval = 1;
        }
        (void)FS_CloseFile(p_file);
    }
    return retval;
}
