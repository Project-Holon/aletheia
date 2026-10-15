/*
 * function: func_021D4AB4
 * address:  0x021D4AB4
 * packet:   pkt_ov118_021D4AB4
 * region:   ov118
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKETRADE_DEMO_COMMON_SetFinishFlag  0x021D4490  thumb  ov118
 *   MCSS_SetAnimeIndex  0x02016028  thumb
 *   MCSS_SetPosition  0x02015C48  thumb
 *   POKETRADE_DEMO_COMMON_SetFrame  0x021D4484  thumb  ov118
 *   POKETRADE_PROC_SetStep  0x021D8E84  thumb  ov119
 *   POKETRADE_DEMO_COMMON_StepCompareMons  0x021D449C  thumb  ov118
 *   d_021D7C90     0x021D7C90  data
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj08049.h"

typedef unsigned int u32;
typedef unsigned char u8;
typedef int s32;

typedef struct {
    s32 x, y, z;
} Vec;

extern void POKETRADE_DEMO_COMMON_SetFinishFlag(u8 *p);
extern void MCSS_SetAnimeIndex(void *a, u32 flag);
extern void MCSS_SetPosition(void *p, u32 *src);
extern void POKETRADE_DEMO_COMMON_SetFrame(u8 *p, u32 v);
extern void POKETRADE_PROC_SetStep(void *p, int next);
extern void POKETRADE_DEMO_COMMON_StepCompareMons(u8 *p);
extern const Vec d_021D7C90;

void func_021D4AB4(u8 *p)
{
    POKETRADE_DEMO_COMMON_SetFinishFlag(p);
    ((struct Obj08049 *)p)->f854 = 1;
    MCSS_SetAnimeIndex((void *)(((struct Obj08049 *)p)->f844), 0);
    if (((struct Obj08049 *)p)->f118C == 6) {
        Vec v = d_021D7C90;
        MCSS_SetPosition((void *)(((struct Obj08049 *)p)->f844), (u32 *)(&v));
    }
    POKETRADE_DEMO_COMMON_SetFrame(p, 0);
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_DEMO_COMMON_StepCompareMons);
}
