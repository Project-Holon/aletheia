/*
 * function: func_0202B64C
 * address:  0x0202B64C
 * packet:   pkt_0202B64C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Blocked: the only site, the THM_CALL at +0006 to func_0202C070, has no
 * manifest entry.  0x0202C070 is byte-correct but capped in turn on 0x0202C148,
 * which is a DIFF (docs/notes/pkt_0202C148.c.txt), so this row cannot close
 * this pass.  Every concrete byte reproduces.
 *
 * Builds the +0x20 sub-object from the object's u16 id.
 *
 * symbols:
 *   func_0202C070  0x0202C070  thumb
 */
#include "../include/Obj00563.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj;

extern u8 *func_0202C070(u32 heap);

void func_0202B64C(struct Obj *o)
{
    ((struct Obj00563 *)o)->f20 = (u32)func_0202C070(((struct Obj00563 *)o)->f0);
}
