/*
 * function: FS_LoadOverlayInfo
 * address:  0x02078D34
 * packet:   pkt_02078D34
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * blocker:  the pool word for SDK_OVERLAY_NUMBER (0x000000ED) is an ABS32
 *           against the linker's absolute symbol; this is its only site in the
 *           image, so it has no literal witness and stays wildcarded.
 *
 * TwlSDK libfs fs_overlay.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 * Reads one overlay table entry for the ARM9 or ARM7 into *p_ovi, from the
 * overlay table already in memory when FSiOverlayContext has one, else from
 * the ROM through the card header's table region, then opens the overlay's
 * file to record its image position and length.  Overlay IDs past
 * SDK_OVERLAY_NUMBER are accepted only on TWL hardware.
 *
 * symbols:
 *   OS_IsRunOnTwl         0x02085D3C  arm
 *   FS_InitFile           0x020788AC  arm
 *   MI_CpuCopy8           0x02082D44  arm
 *   FS_GetOverlayFileID   0x02078D08  arm
 *   FS_OpenFileFast       0x020789A4  arm
 *   CARD_GetOwnRomHeader  0x02075DF8  arm
 *   FS_CreateFileFromRom  0x0207ACD4  arm
 *   FS_ReadFile           0x02078B70  arm
 *   FS_CloseFile          0x02078A80  arm
 *   FS_GetFileImageTop    0x0207A7BC  arm
 *   FS_GetFileLength      0x02078A94  arm
 *   FSiOverlayContext     0x02150D24  data
 *   SDK_OVERLAY_NUMBER    0x000000ED  data
 */

typedef unsigned char u8;
typedef unsigned long u32;
typedef long s32;
typedef int BOOL;

typedef int MIProcessor;
#define MI_PROCESSOR_ARM9 0

typedef struct CARDRomRegion {
    u32 offset;
    u32 length;
} CARDRomRegion;

typedef struct CARDRomHeader {
    u8 pad[0x50];
    CARDRomRegion main_ovt;
    CARDRomRegion sub_ovt;
} CARDRomHeader;

typedef struct FSOverlaySource {
    void *arc;
    CARDRomRegion ovt9;
    CARDRomRegion ovt7;
    void *digest_key_ptr;
    u32 digest_key_len;
} FSOverlaySource;

typedef struct FSOverlayInfoHeader {
    u32 id;
    u8 *ram_address;
    u32 ram_size;
    u32 bss_size;
    void *sinit_init;
    void *sinit_init_end;
    u32 file_id;
    u32 flag;
} FSOverlayInfoHeader;

typedef struct FSOverlayInfo {
    FSOverlayInfoHeader header;
    MIProcessor target;
    CARDRomRegion file_pos;
} FSOverlayInfo;

typedef struct FSFileID {
    void *arc;
    u32 file_id;
} FSFileID;

typedef struct FSFile {
    u8 opaque[0x48];
} FSFile;

extern FSOverlaySource FSiOverlayContext;
extern u32 SDK_OVERLAY_NUMBER[];

extern BOOL OS_IsRunOnTwl(void);
extern void FS_InitFile(FSFile *file);
extern void MI_CpuCopy8(const void *srcp, void *dstp, u32 size);
extern FSFileID FS_GetOverlayFileID(const FSOverlayInfo *p_ovi);
extern BOOL FS_OpenFileFast(FSFile *file, FSFileID id);
extern const CARDRomHeader *CARD_GetOwnRomHeader(void);
extern BOOL FS_CreateFileFromRom(FSFile *p_file, u32 offset, u32 size);
extern s32 FS_ReadFile(FSFile *file, void *buffer, s32 length);
extern BOOL FS_CloseFile(FSFile *file);
extern u32 FS_GetFileImageTop(const FSFile *file);
extern u32 FS_GetFileLength(FSFile *file);

BOOL FS_LoadOverlayInfo(FSOverlayInfo *p_ovi, MIProcessor target, u32 id)
{
    BOOL retval = 0;
    const u32 pos = id * sizeof(FSOverlayInfoHeader);
    const CARDRomRegion *pr = (target == MI_PROCESSOR_ARM9) ? &FSiOverlayContext.ovt9 : &FSiOverlayContext.ovt7;

    if ((id < (u32)SDK_OVERLAY_NUMBER) || OS_IsRunOnTwl()) {
        if (pr->offset != 0) {
            if (pos < pr->length) {
                FSFile file[1];
                FS_InitFile(file);
                MI_CpuCopy8((const void *)(pr->offset + pos), p_ovi, sizeof(FSOverlayInfoHeader));
                p_ovi->target = target;
                if (FS_OpenFileFast(file, FS_GetOverlayFileID(p_ovi))) {
                    p_ovi->file_pos.offset = FS_GetFileImageTop(file);
                    p_ovi->file_pos.length = FS_GetFileLength(file);
                    (void)FS_CloseFile(file);
                    retval = 1;
                }
            }
        } else {
            pr = (target == MI_PROCESSOR_ARM9) ? &CARD_GetOwnRomHeader()->main_ovt : &CARD_GetOwnRomHeader()->sub_ovt;
            if (pos < pr->length) {
                FSFile file[1];
                FS_InitFile(file);
                if (FS_CreateFileFromRom(file, pr->offset + pos, pr->offset + pr->length)) {
                    if (FS_ReadFile(file, p_ovi, sizeof(FSOverlayInfoHeader)) != sizeof(FSOverlayInfoHeader)) {
                        (void)FS_CloseFile(file);
                    } else {
                        (void)FS_CloseFile(file);
                        p_ovi->target = target;
                        if (FS_OpenFileFast(file, FS_GetOverlayFileID(p_ovi))) {
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
