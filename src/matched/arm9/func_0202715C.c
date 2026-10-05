/*
 * function: func_0202715C
 * address:  0x0202715C
 * packet:   pkt_0202715C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * EXACT*: the listing extent runs 60 bytes to the next label; only the
 * first 24 bytes belong to this function (the follower at 0x02027174 is
 * an unlabelled leaf).
 *
 * The original splits the address arithmetic into `adds r0, r4, #4` then
 * `adds r0, #0x5e`, which a flat `*(u8 *)(p + 0x62)` folds into one
 * `adds r4, #0x62`.  Taking a pointer to a NESTED struct member (the
 * inner object starts at +4) before the call is what pins the two-step
 * form: `&g->in` is its own value, materialised at +0x0A, and the field
 * offset is added separately at +0x0E.
 *
 * symbols:
 *   g_02146940     0x02146940  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Inner {
    u8  pad[0x5e];
    u8  f5e;
};

struct Outer {
    u32 f00;
    struct Inner in;
};

extern struct Outer *g_02146940;
extern void  func_020274B4(u32 a0);

void func_0202715C(u32 a0)
{
    struct Inner *in = &g_02146940->in;

    func_020274B4(a0);
    in->f5e = 1;
}
