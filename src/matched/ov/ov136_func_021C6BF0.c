/*
 * unit: yes
 * function: MB_SEQ_StateChildWait, MB_SEQ_StateFadeInToList
 * address: 0x021C6BF0
 * packet: pkt_ov136_021C6BF0
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PROCSYS_Main 0x02031330 arm
 *   d_021C7D7C 0x021C7D7C data a4
 *   MB_SEQ_StartFadeIn 0x021C714C thumb ov136
 */
#include "../include/Obj14194.h"
typedef unsigned char u8;
struct Row { int (*call)(u8 *); int result; int other; };
extern const struct Row d_021C7D7C[];
typedef unsigned int   u32;
extern unsigned int PROCSYS_Main(void *p);
extern int MB_SEQ_StartFadeIn(u8 *p, u32 v);
int MB_SEQ_StateChildWait(u8 *p)
{
    if (PROCSYS_Main(((struct Obj14194 *)p)->f30) == 1) return 7;
    ((struct Obj14194 *)p)->f28 = d_021C7D7C[*(int *)(p + 0x14)].call(p);
    return d_021C7D7C[*(int *)(p + 0x14)].result;
}
int MB_SEQ_StateFadeInToList(u8 *p)
{
    return MB_SEQ_StartFadeIn(p, 9);
}
