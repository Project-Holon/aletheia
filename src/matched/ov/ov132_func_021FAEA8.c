/*
 * function: STA_ACT_SCRIPT_StepTaskActor
 * address: 0x021FAEA8
 * packet: pkt_ov132_021FAEA8
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * note: extent ends with two bytes of zero alignment padding.
 * symbols:
 *   STA_ACTING_GetActorSystem 0x021F9DA0 thumb ov132
 *   STA_ACT_LIGHT_ElemOpA 0x021F8044 thumb ov112
 *   VEC_Add 0x0207C9D0 arm
 */
#include "../include/Obj06489.h"
typedef unsigned short u16;
extern void *STA_ACTING_GetActorSystem(char *p);
typedef unsigned int   u32;
extern void STA_ACT_LIGHT_ElemOpA(void *unused, u32 *p, u32 *q);
extern void VEC_Add(void *, void *, void *);
int STA_ACT_SCRIPT_StepTaskActor(char *p, void *out)
{
    int v[3];
    STA_ACT_LIGHT_ElemOpA(STA_ACTING_GetActorSystem(((struct Obj06489 *)p)->f0), (u32 *)(((struct Obj06489 *)p)->f4), (u32 *)v);
    VEC_Add(v, p + 8, out);
    (((struct Obj06489 *)p)->f16)++;
    if (((struct Obj06489 *)p)->f16 >= ((struct Obj06489 *)p)->f14) return 1;
    return 0;
}
