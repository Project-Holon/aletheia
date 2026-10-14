/*
 * function: func_021D59B0
 * address:  0x021D59B0
 * packet:   pkt_ov118_021D59B0
 * region:   ov118
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D56F0  0x021D56F0  thumb  ov118
 *   MCSS_SetAnimeIndex  0x02016028  thumb
 *   MCSS_SetVanishFlag  0x02015EA0  thumb
 *   MCSS_SetPosition  0x02015C48  thumb
 *   POKETRADE_2D_ScheduleMainPlaneVisible  0x021E71F0  thumb  ov119
 *   POKETRADE_2D_ScheduleSubPlaneVisible  0x021E7208  thumb  ov119
 *   func_021D54F0  0x021D54F0  thumb  ov118
 *   POKETRADE_PROC_SetStep  0x021D8E84  thumb  ov119
 *   func_021D5A60  0x021D5A60  thumb  ov118
 *   d_021D7CA8     0x021D7CA8  data
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj03770.h"

typedef unsigned int u32;
typedef unsigned char u8;
typedef int s32;

typedef struct {
    s32 x, y, z;
} Vec;

extern void func_021D56F0(u8 *p);
extern void MCSS_SetAnimeIndex(void *a, u32 flag);
extern void MCSS_SetVanishFlag(void *p);
extern void MCSS_SetPosition(void *p, u32 *src);
extern void POKETRADE_2D_ScheduleMainPlaneVisible(void *p, int a);
extern void POKETRADE_2D_ScheduleSubPlaneVisible(void *p, int a);
extern void func_021D54F0(u8 *p, u8 *outSame, u8 *outFlag, u32 key, int enemy);
extern void POKETRADE_PROC_SetStep(void *p, int next);
extern void func_021D5A60(u8 *p);
extern const Vec d_021D7CA8;

void func_021D59B0(u8 *p)
{
    func_021D56F0(p);
    ((struct Obj03770 *)p)->f854 = 1;
    MCSS_SetAnimeIndex((void *)(((struct Obj03770 *)p)->f844), 0);
    MCSS_SetVanishFlag((void *)(((struct Obj03770 *)p)->f844));
    MCSS_SetVanishFlag((void *)(((struct Obj03770 *)p)->f848));
    if (((struct Obj03770 *)p)->f118C == 6) {
        Vec v = d_021D7CA8;
        MCSS_SetPosition((void *)(((struct Obj03770 *)p)->f844), (u32 *)(&v));
    }
    POKETRADE_2D_ScheduleMainPlaneVisible(p, 0x11);
    POKETRADE_2D_ScheduleSubPlaneVisible(p, 0);
    func_021D54F0(p, p + 0x11ED, p + 0x11EF, ((struct Obj03770 *)p)->f834, 1);
    func_021D54F0(p, p + 0x11EE, p + 0x11F0, ((struct Obj03770 *)p)->f830, 0);
    POKETRADE_PROC_SetStep(p, (int)func_021D5A60);
}
