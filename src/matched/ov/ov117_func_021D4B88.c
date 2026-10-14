/*
 * function: func_021D4B88
 * address:  0x021D4B88
 * packet:   pkt_ov117_021D4B88
 * region:   ov117
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D4490  0x021D4490  thumb  ov117
 *   MCSS_SetAnimeIndex  0x02016028  thumb
 *   MCSS_SetAnmStopFlag  0x02015E04  thumb
 *   MCSS_SetPosition  0x02015C48  thumb
 *   func_021D4484  0x021D4484  thumb  ov117
 *   POKETRADE_PROC_SetStep  0x021D8E84  thumb  ov119
 *   func_021D449C  0x021D449C  thumb  ov117
 *   d_021D51DC     0x021D51DC  data
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj06419.h"

typedef unsigned int u32;
typedef unsigned char u8;
typedef int s32;

typedef struct {
    s32 x, y, z;
} Vec;

extern void func_021D4490(u8 *p);
extern void MCSS_SetAnimeIndex(void *a, u32 flag);
extern void MCSS_SetAnmStopFlag(void *p);
extern void MCSS_SetPosition(void *p, u32 *src);
extern void func_021D4484(u8 *p, u32 v);
extern void POKETRADE_PROC_SetStep(void *p, int next);
extern void func_021D449C(u8 *p);
extern const Vec d_021D51DC;

void func_021D4B88(u8 *p)
{
    func_021D4490(p);
    ((struct Obj06419 *)p)->f854 = 1;
    MCSS_SetAnimeIndex((void *)(((struct Obj06419 *)p)->f844), 0);
    MCSS_SetAnmStopFlag((void *)(((struct Obj06419 *)p)->f844));
    if (((struct Obj06419 *)p)->f118C == 4) {
        Vec v = d_021D51DC;
        MCSS_SetPosition((void *)(((struct Obj06419 *)p)->f844), (u32 *)(&v));
    }
    func_021D4484(p, 0);
    POKETRADE_PROC_SetStep(p, (int)func_021D449C);
}
