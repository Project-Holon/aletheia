/*
 * function: MB_SEQ_StartPartyListToTake
 * address:  0x021C7600
 * packet:   pkt_ov136_021C7600
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MB_SEQ_StartFadeOut 0x021C7178 thumb
 *   MB_SEQ_CreatePartyListArgs 0x021C7430 thumb
 */
#include "../include/Obj10611.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void MB_SEQ_CreatePartyListArgs(u8 *, int, u16, u16);
extern int MB_SEQ_StartFadeOut(u8 *, u32);
int MB_SEQ_StartPartyListToTake(u8 *p)
{
    MB_SEQ_CreatePartyListArgs(p, 9, ((struct Obj10611 *)p)->f22, 0);
    ((struct Obj10611 *)p)->f14 = 1;
    ((struct Obj10611 *)p)->f28 = 6;
    return MB_SEQ_StartFadeOut(p, 1);
}
