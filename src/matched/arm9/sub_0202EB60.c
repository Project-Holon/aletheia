/*
 * unit:     no
 * function: sub_0202EB60
 * address:  0x0202EB60
 * packet:   pkt_0202E770
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02087C88  0x02087C88  arm
 *
 * Fills an 0x54-byte structure on the stack from an ARM SDK getter and
 * copies two of its bytes out through the two pointer parameters. The
 * whole 0x54 bytes are reserved even though only offsets 2 and 3 are
 * read, so the stack object is the SDK's structure and not a pair of
 * bytes; `add r0, sp, #0` is emitted twice, once for the call and once
 * as the base of the two loads, which is what a named local rather than
 * a re-taken address looks like here.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202EB60.c \
 *       --func sub_0202EB60 --addr 0x0202EB60 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;

struct Info0202EB60 {
    u8 unk00;
    u8 unk01;
    u8 unk02;
    u8 unk03;
    u8 pad[0x50];
};

extern void func_02087C88(struct Info0202EB60 *p);

void sub_0202EB60(u8 *a, u8 *b)
{
    struct Info0202EB60 info;

    func_02087C88(&info);
    *a = info.unk02;
    *b = info.unk03;
}
