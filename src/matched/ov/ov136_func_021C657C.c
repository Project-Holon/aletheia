/*
 * function: MB_SEQ_DeleteActors
 * address:  0x021C657C
 * packet:   pkt_021C657C
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MB_SEQ_DeleteAllActors  0x021C6688  thumb
 *   MB_SEQ_ExitActorSystem  0x021C65E4  thumb
 *   MB_SEQ_FreeActorArc  0x021C674C  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj10605.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void MB_SEQ_DeleteAllActors(u8 *p);
extern void MB_SEQ_ExitActorSystem(u8 *p);
extern void MB_SEQ_FreeActorArc(u8 *p);

void MB_SEQ_DeleteActors(u8 *p)
{
    MB_SEQ_DeleteAllActors(((struct Obj10605 *)p)->f8);
    MB_SEQ_ExitActorSystem(((struct Obj10605 *)p)->f8);
    MB_SEQ_FreeActorArc(((struct Obj10605 *)p)->f8);
}
