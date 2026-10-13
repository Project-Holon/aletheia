/*
 * function: EVENT_FIELDMAP_CONTROL_RunWipeInEffect5
 * address:  0x021BF348
 * packet:   pkt_ov021_021BF348
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FADE_Start  0x0204E720  arm
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   WIPE_SYS_Start  0x0202208C  thumb
 *   WIPE_SYS_EndCheck  0x020221A4  thumb
 *   EVENT_FIELDMAP_CONTROL_ResetBgModeKeepPlanes  0x021BF564  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_ResetBgAffine  0x021BF584  thumb  ov021
 */
#include "../include/Obj09668.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef signed int     s32;
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
extern u16 FIELDMAP_GetHeapId(u8 *p);
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern u32 WIPE_SYS_EndCheck(void);
extern void EVENT_FIELDMAP_CONTROL_ResetBgModeKeepPlanes(void);
extern void EVENT_FIELDMAP_CONTROL_ResetBgAffine(u8 *a0);

int EVENT_FIELDMAP_CONTROL_RunWipeInEffect5(u32 p0, int *st, u8 *q)
{
    u32 x = ((struct Obj09668 *)q)->f4;

    switch (*st) {
    case 0:
        EVENT_FIELDMAP_CONTROL_ResetBgModeKeepPlanes();
        EVENT_FIELDMAP_CONTROL_ResetBgAffine((u8 *)(((struct Obj09668 *)q)->f4));
        FADE_Start(((struct Obj09668 *)q)->fC, 0x10, 0, -1);
        *st = *st + 1;
        break;
    case 1:
        WIPE_SYS_Start((void *)3, 3, 3, 0, 6, 1, FIELDMAP_GetHeapId((u8 *)x));
        *st = *st + 1;
        break;
    case 2:
        if (WIPE_SYS_EndCheck() != 0)
            *st = *st + 1;
        break;
    case 3:
        return 1;
    }
    return 0;
}
