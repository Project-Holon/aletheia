/*
 * function: func_020423D4
 * address:  0x020423D4
 * packet:   pkt_02041F28
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02051E74   0x02051E74  arm
 *   sub_02040860    0x02040860  arm
 *
 * One layer's affine setup: fill a scratch parameter block on the stack,
 * then push it into the layer through sub_02040860 with a zero transform.
 * The block is 0x10 bytes at sp+4 and the first call's fifth argument is
 * the word at sp+0, which is why the frame is `sub sp, sp, #0x14`: four
 * bytes of outgoing argument plus sixteen of local.
 *
 * The first call's third and fourth arguments are the same literal, so the
 * compiler materialises 0x1000 once in r2 and copies it to r3; the zero is
 * shared the same way and survives into the second call.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020423D4.c \
 *       --func func_020423D4 --addr 0x020423D4 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct Param {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0c;
};

extern void func_02051E74(void *p, u32 a, u32 b, u32 c, u32 d);
extern void sub_02040860(u32 layer, const void *p, u32 b, u32 c);

void func_020423D4(u32 layer)
{
    struct Param p;

    func_02051E74(&p, 0, 0x1000, 0x1000, 0);
    sub_02040860(layer, &p, 0, 0);
}
