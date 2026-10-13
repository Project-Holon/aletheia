/*
 * function: P_STA_SKILL_SetSlotAnim
 * address:  0x021DBA78
 * packet:   pkt_021DBA78
 * region:   ov131
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj14080.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);

void P_STA_SKILL_SetSlotAnim(u8 *p, int i)
{
    CLACT_SetActorAnimSeq(((struct Obj14080 *)p)->f8, (u16)(p[0] + i * 5));
}
