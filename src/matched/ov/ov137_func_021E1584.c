/*
 * function: GURU2_MAIN_StartBlendFade
 * address: 0x021E1584
 * packet: pkt_ov137_021E1584
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gGuru2FadeValues 0x021E2018 data a4
 *   gGuru2MainAllocFileName 0x021E22B8 data a1
 *   func_02030734 0x02030734 arm
 *   func_02030DA8 0x02030DA8 arm
 *   GURU2_MAIN_BlendFadeTask 0x021E1540 thumb ov137
 */
#include "../include/Obj02209.h"
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int a, b; } Pair;
extern const Pair gGuru2FadeValues;
extern const char gGuru2MainAllocFileName[];
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02030DA8(void *, void (*)(void *, int *), void *, int);
extern void GURU2_MAIN_BlendFadeTask(void *, int *);
void GURU2_MAIN_StartBlendFade(char *p, int flag)
{
    Pair values = gGuru2FadeValues;
    int *q = func_02030734(0x8072, 12, 0, gGuru2MainAllocFileName, 5992);
    q[0] = (int)p;
    q[1] = flag;
    q[2] = ((int *)&values)[flag];
    func_02030DA8(((struct Obj02209 *)p)->fD98, GURU2_MAIN_BlendFadeTask, q, 0);
}
