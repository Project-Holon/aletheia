/*
 * function: func_02079264
 * address:  0x02079264
 * packet:   pkt_02079264
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      FS_LoadOverlay (libfs.TWL.HYB.a fs_overlay.o)
 *
 * symbols:
 *   FS_LoadOverlayInfo  0x02078D34  arm
 *   FS_LoadOverlayImage  0x02078EB0  arm
 *   FS_StartOverlay  0x0207902C  arm
 */

typedef unsigned char u8;
typedef unsigned long u32;
typedef int BOOL;

typedef struct FSOverlayInfo
{
    u8 data[0x2C];
} FSOverlayInfo;

extern BOOL FS_LoadOverlayInfo(FSOverlayInfo *p_ovi, int target, u32 id);
extern BOOL FS_LoadOverlayImage(FSOverlayInfo *p_ovi);
extern void FS_StartOverlay(FSOverlayInfo *p_ovi);

BOOL func_02079264(int target, u32 id)
{
    BOOL retval = 0;
    FSOverlayInfo ovi;

    if (FS_LoadOverlayInfo(&ovi, target, id) && FS_LoadOverlayImage(&ovi))
    {
        FS_StartOverlay(&ovi);
        retval = 1;
    }
    return retval;
}
