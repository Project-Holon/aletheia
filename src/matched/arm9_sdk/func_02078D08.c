/*
 * function: func_02078D08
 * address:  0x02078D08
 * packet:   pkt_02078D08
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK symbol: FS_GetOverlayFileID (TwlSDK libfs.TWL.HYB.a fs_overlay.o)
 *
 * symbols:
 *   FSiOverlayContext   0x02150D20  data
 */

typedef unsigned char u8;
typedef unsigned long u32;

typedef struct FSFileID
{
    void *arc;
    u32 file_id;
} FSFileID;

extern u8 FSiOverlayContext[];

FSFileID func_02078D08(const u8 *p_ovi)
{
    FSFileID fileid;

    fileid.arc = *(void **)(FSiOverlayContext + 4);
    fileid.file_id = *(u32 *)(p_ovi + 0x18);
    return fileid;
}
