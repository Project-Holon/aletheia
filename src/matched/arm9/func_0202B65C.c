/*
 * function: ISS_SYS_Create3ds
 * address:  0x0202B65C
 * packet:   pkt_0202B59C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * closed:   blocker ISS_SYS_Setup.c is now a manifest entry (matched class)
 *
 * Builds the +0x24 sub-object from the object's u16 id.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_SYS_Create3ds.c \
 *       --func ISS_SYS_Create3ds --addr 0x0202B65C --thumb --cc 1.1p1
 *
 * symbols:
 *   ISS_3DS_SYS_Create  0x0202B894  thumb
 */
#include "../include/Obj00563.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj;

extern u8 *ISS_3DS_SYS_Create(u32 id);

void ISS_SYS_Create3ds(struct Obj *o)
{
    ((struct Obj00563 *)o)->f24 = (u32)ISS_3DS_SYS_Create(((struct Obj00563 *)o)->f0);
}
