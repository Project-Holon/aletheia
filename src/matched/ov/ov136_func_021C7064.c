/*
 * function: MB_SEQ_BeginReturnFade
 * address:  0x021C7064
 * packet:   pkt_ov136_021C7064
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MB_SEQ_SetActorVisible 0x021C66B8 thumb
 *   MB_SEQ_StartFadeIn 0x021C714C thumb
 *   MB_SEQ_SetButtonsEnabled 0x021C7298 thumb
 */
#include "../include/Obj10608.h"

typedef unsigned char u8;
typedef unsigned int u32;
extern void MB_SEQ_SetActorVisible(u8 *, int, u32);
extern void MB_SEQ_SetButtonsEnabled(void *p, int v);
extern int MB_SEQ_StartFadeIn(u8 *p, u32 v);
void MB_SEQ_BeginReturnFade(u8 *p)
{
    MB_SEQ_SetActorVisible(*(u8 * *)&((struct Obj10608 *)p)->f8, 2, 0);
    MB_SEQ_SetButtonsEnabled(*(u8 * *)&((struct Obj10608 *)p)->f8, 1);
    MB_SEQ_StartFadeIn(p, 0x16);
}
