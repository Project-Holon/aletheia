/*
 * unit:     no
 * function: sub_0202E0C8
 * address:  0x0202E0C8
 * packet:   pkt_0202DBC4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B3B4  0x0204B3B4  arm
 *
 * A two-iteration loop over a two-element pointer array at offset 8, not
 * two calls written out: the `lsls`/`adds`/`ldr` address arithmetic and
 * the `cmp r4, #2` are what a loop with a counter looks like, and the
 * counter is signed (`blt`, not `blo`).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202E0C8.c \
 *       --func sub_0202E0C8 --addr 0x0202E0C8 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef signed int    s32;

struct Obj0202E0C8 {
    u8    pad[8];
    void *unk08[2];
};

extern void func_0204B3B4(void *p);

void sub_0202E0C8(struct Obj0202E0C8 *p)
{
    s32 i;

    for (i = 0; i < 2; i++) {
        func_0204B3B4(p->unk08[i]);
    }
}
