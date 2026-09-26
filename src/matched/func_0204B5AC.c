/*
 * function: func_0204B5AC
 * address:  0x0204B5AC
 * packet:   pkt_0204B5AC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Unlabelled ARM leaf: copy two words from src into the pair at +0x14/+0x18
 * of dst.  `ldr r2,[r1]; ldr r1,[r1,#4]; str r2,[r0,#0x14]; str r1,[r0,#0x18]`.
 */

typedef unsigned int u32;

struct Pair {
    u32 a;
    u32 b;
};

struct Obj {
    char pad[0x14];
    struct Pair p;
};

void func_0204B5AC(struct Obj *dst, struct Pair *src)
{
    struct Pair v = *src;

    dst->p = v;
}
