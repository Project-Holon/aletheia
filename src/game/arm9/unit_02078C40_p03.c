/*
 * file:     unit_02078C40_p03.c
 * unit:     yes
 * function: func_02079254, func_02079264, func_020792B8
 * address:  0x02079254
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
 *   FS_LoadOverlayInfo  0x02078D34  arm
 *   FS_LoadOverlayImage  0x02078EB0  arm
 *   FS_StartOverlay  0x0207902C  arm
 *   func_02078D34  0x02078D34  arm
 *   func_02079254  0x02079254  arm
 */
struct FSOverlayInfo;
typedef int BOOL;

typedef unsigned char u8;

typedef unsigned long u32_02079264;

typedef struct FSOverlayInfo
{
    u8 data[0x2C];
} FSOverlayInfo;

typedef unsigned int u32_020792B8;

struct Iter020792B8 {
    u32_020792B8 words[11];
};

extern void func_02079164(void);
extern BOOL FS_LoadOverlayInfo(FSOverlayInfo *p_ovi, int target, u32_02079264 id);
extern BOOL FS_LoadOverlayImage(FSOverlayInfo *p_ovi);
extern void FS_StartOverlay(FSOverlayInfo *p_ovi);
extern int func_02078D34(struct FSOverlayInfo *p_ovi, u32_020792B8 target, u32_020792B8 id);
extern int func_02079254(struct Iter020792B8 *it);
BOOL FS_UnloadOverlayImage(void);
BOOL func_02079264(int target, u32_02079264 id);
int func_020792B8(u32_020792B8 a, u32_020792B8 b);


BOOL FS_UnloadOverlayImage(void)
{
    func_02079164();
    return 1;
}


/*
 * sdk:      FS_LoadOverlay (libfs.TWL.HYB.a fs_overlay.o)
 */
BOOL func_02079264(int target, u32_02079264 id)
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


/*
 * Builds a 44-byte iterator/descriptor on the stack from (a, b) and, if
 * that succeeded, runs it once; the result is normalised to 0/1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020792B8.c \
 *       --func func_020792B8 --addr 0x020792B8 --cc 1.1p1 --arm
 */
int func_020792B8(u32_020792B8 a, u32_020792B8 b)
{
    struct Iter020792B8 it;

    if (func_02078D34((struct FSOverlayInfo *)(&it), a, b) != 0 && func_02079254(&it) != 0) {
        return 1;
    }
    return 0;
}
