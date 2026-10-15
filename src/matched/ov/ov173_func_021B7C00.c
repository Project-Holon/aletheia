/*
 * function: POKE_SUMMARY_ACTOR_StartNetRestart
 * address:  0x021B7C00
 * packet:   pkt_ov173_021B7C00
 * region:   ov173
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKE_SUMMARY_MAIN_InitScreen  0x021B63AC  thumb  ov173
 *   POKE_SUMMARY_ACTOR_PositionMonActor  0x021B7ADC  thumb  ov173
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm
 */
#include "../include/Obj06566.h"

typedef unsigned int   u32;
typedef unsigned char  u8;
extern void POKE_SUMMARY_MAIN_InitScreen(u8 *p);
extern void POKE_SUMMARY_ACTOR_PositionMonActor(unsigned char *p, u32 idx, int unused);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);

int POKE_SUMMARY_ACTOR_StartNetRestart(void *p)
{
    unsigned char v;

    POKE_SUMMARY_MAIN_InitScreen(p);
    POKE_SUMMARY_ACTOR_PositionMonActor(p, (unsigned char)(*(unsigned short *)(((struct Obj06566 *)p)->f0 + 0x14)), 3);
    GFL_NET_RestartWithDefaultTimeout(1, 0x4f);
    v = ((struct Obj06566 *)p)->f192;
    if (v == 0) {
        v = ((struct Obj06566 *)p)->f191;
    } else {
        v = 4;
    }
    *(unsigned char *)(((struct Obj06566 *)p)->f0 + 0x1b) = v;
    ((struct Obj06566 *)p)->f1B0 = 7;
    return 0;
}
