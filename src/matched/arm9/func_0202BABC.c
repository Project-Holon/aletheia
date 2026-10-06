/*
 * function: func_0202BABC
 * address:  0x0202BABC
 * packet:   pkt_0202B9F0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 *
 * status:   EXACT*
 *
 * Closed by the `matched` class: 0x0202B9F0 became an EXACT shard entry
 * (pkt_0202B9F0) in this wave.  The listing extent runs to 0x0202BAF4
 * because the follower at 0x0202BAE6 is unlabelled, so the verdict is EXACT*.
 * symbols:
 *   func_0202B9E0  0x0202B9E0  thumb
 *   func_0202B9F0  0x0202B9F0  thumb
 *   func_0202BB48  0x0202BB48  thumb
 *
 */
#include "../include/Obj02601.h"

typedef unsigned char u8;
typedef unsigned int  u32;

typedef unsigned short u16;
extern u16 func_02005C44(void);
struct Obj;
extern u8 func_0202B9F0(const struct Obj *p, u32 key);
extern void func_0202B9E0(void *o, u32 v);
extern void func_0202BB48(void *o);

void func_0202BABC(u8 *o)
{
    if (((struct Obj02601 *)o)->f4 != 0) {
        return;
    }
    ((struct Obj02601 *)o)->f4 = 1;
    func_0202B9E0(o, func_0202B9F0((const struct Obj *)o, func_02005C44()));
    func_0202BB48(o);
}
