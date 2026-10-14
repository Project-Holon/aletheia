/*
 * function: GURU2_MAIN_CreateEntranceEffectTask
 * address: 0x021E11B4
 * packet: pkt_ov137_021E11B4
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   func_02030DA8 0x02030DA8 arm
 *   GURU2_MAIN_EntranceEffectTask 0x021E11A0 thumb ov137
 */
#include "../include/Obj14246.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void MI_CpuFill8(void *, int, unsigned);
extern void *func_02030DA8(void *, void (*)(void *, u8 *), void *, int);
extern void GURU2_MAIN_EntranceEffectTask(void *, u8 *);
void GURU2_MAIN_CreateEntranceEffectTask(char *p)
{
    MI_CpuFill8(p + 0xc74, 0, 20);
    ((struct Obj14246 *)p)->fD88 = func_02030DA8(((struct Obj14246 *)p)->fD98, GURU2_MAIN_EntranceEffectTask, p, 255);
}
