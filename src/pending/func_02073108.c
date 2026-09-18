/*
 * function: func_02073108
 * address:  0x2073108
 * packet:   pkt_02072EA8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * blocker:  0x02072894 has no witness outside this range: its only caller is this function
 *
 * Returns 0 to the caller when the guarded pointer is null, and forwards its
 *  * own v and w to the callee (they are already in r1/r2, so the call sets only
 *  * r0).
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Sub { u8 pad00[0x2c]; u8 b2c; u8 pad2[0x3c - 0x2d]; u8 b3c; };
struct Obj { struct Sub * volatile p; };
extern int func_02072894(u8, u32, u32);

int func_02073108(struct Obj *o, u32 v, u32 w)
{
    if (o->p == 0) return 0;
    return func_02072894(o->p->b3c, v, w);
}
