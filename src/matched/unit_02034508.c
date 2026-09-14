/*
 * function: sub_02034508
 * address:  0x02034508
 * packet:   pkt_020339D0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020344C8  0x020344C8  arm
 *
 * Guard-and-forward: calls the offset-8 field of `p` through
 * func_020344C8 only when that field is non-zero.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/unit_02034508.c \
 *       --func sub_02034508 --addr 0x02034508 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct Obj02034508 {
    char pad[8];
    u32 unk08;
};

extern void func_020344C8(struct Obj02034508 *p);

void sub_02034508(struct Obj02034508 *p)
{
    if (p->unk08 != 0) {
        func_020344C8(p);
    }
}
