/*
 * function: sub_02035080
 * address:  0x02035080
 * packet:   pkt_02035080
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * A plain two-field setter in the ARM SDK-style block at
 * 0x02035000..0x02038000: "str r1,[r0,#0x1c]; str r2,[r0,#0x2c]; bx lr",
 * twelve bytes, no relocations at all.  The struct here only pins the two
 * offsets this function touches, not the real layout.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02035080.c \
 *       --func sub_02035080 --addr 0x02035080 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct Obj02035080 {
    unsigned char pad[0x1c];
    u32 unk1C;
    unsigned char pad2[0x0C];
    u32 unk2C;
};

void sub_02035080(struct Obj02035080 *p, u32 a, u32 b)
{
    p->unk1C = a;
    p->unk2C = b;
}
