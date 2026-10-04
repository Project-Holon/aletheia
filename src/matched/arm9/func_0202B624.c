/*
 * function: func_0202B624
 * address:  0x0202B624
 * packet:   pkt_0202B59C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * closed:   blocker func_0202B3A0.c is now a manifest entry (matched class)
 *
 * Builds the +0x18 sub-object.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B624.c \
 *       --func func_0202B624 --addr 0x0202B624 --thumb --cc 1.1p1
 */
#include "../include/Obj00563.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj;

extern void *func_0202B7F8(struct Obj *o);
struct Node;
extern struct Node *func_0202B3A0(u32 a, u32 b, u32 heapId);

void func_0202B624(struct Obj *o)
{
    ((struct Obj00563 *)o)->f18 = (u32)func_0202B3A0(((struct Obj00563 *)o)->f4,
                                             (u32)func_0202B7F8(o), ((struct Obj00563 *)o)->f0);
}
