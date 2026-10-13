/*
 * function: ISS_SYS_CreateSwitch
 * address:  0x0202B64C
 * packet:   pkt_0202B64C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Blocked: the only site, the THM_CALL at +0006 to ISS_SWITCH_SYS_Create, has no
 * manifest entry.  0x0202C070 is byte-correct but capped in turn on 0x0202C148,
 * which is a DIFF (docs/notes/pkt_0202C148.c.txt), so this row cannot close
 * this pass.  Every concrete byte reproduces.
 *
 * Builds the +0x20 sub-object from the object's u16 id.
 *
 * symbols:
 *   ISS_SWITCH_SYS_Create  0x0202C070  thumb
 */
#include "../include/Obj00563.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj;

extern u8 *ISS_SWITCH_SYS_Create(u32 heap);

void ISS_SYS_CreateSwitch(struct Obj *o)
{
    ((struct Obj00563 *)o)->f20 = (u32)ISS_SWITCH_SYS_Create(((struct Obj00563 *)o)->f0);
}
