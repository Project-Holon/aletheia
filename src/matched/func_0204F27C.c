/*
 * function: func_0204F27C
 * address:  0x0204F27C
 * packet:   pkt_0204EA64
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0204F150  0x0204F150  arm
 *
 * Walk the actor's u16 count at +0xc and release every entry.  The count is
 * re-read on each iteration because func_0204F150 may change it.  The
 * comparison comes out signed (blt, not blo) because the u16 count promotes
 * to int against an s32 counter.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed int     s32;

struct Actor {
    u8  pad_000[0xc];
    u16 count;
};

extern void func_0204F150(struct Actor *p, s32 idx);

void func_0204F27C(struct Actor *p)
{
    s32 i;

    for (i = 0; i < p->count; i++) {
        func_0204F150(p, i);
    }
}
