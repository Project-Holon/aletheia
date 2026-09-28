/*
 * function: func_02091CBC
 * address:  0x02091CBC
 * packet:   pkt_02091B5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Reads back the amount a record still owes: reject the record when its +4
 * bits 7..9 mode is neither 0 nor 1 or when its +0xd byte is set (leaving
 * 0x28 in the reserved word and returning -1), return the running f18 when
 * the +8 three-bit mode is 0, otherwise f34 + (f24 - f1c), reduced by
 * (mode - 2) for modes of 3 or more.
 *
 * Two spellings are pinned here and neither is the obvious one:
 *
 *  - `u8 sel = mode + 0xff;` is the decrement.  `mode - 1` compiles to
 *    `sub r1, r1, #1`; the original has `and #0xff; add r1, r1, #0xff;
 *    and #0xff`, i.e. the wrap-around add the source wrote, narrow once on
 *    being stored into the `u8 mode` and once on the sum
 *    (docs/idioms/a-u8-decrement-is-spelled-as-the-wraparound-add.md).
 *  - the +8 mode is read through a bitfield view struct.  A shift-pair
 *    spelling that feeds a `== 0` test is folded to `ands`, which loses both
 *    the second `lsr` and the register the original keeps.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02091CBC.c \
 *       --func func_02091CBC --addr 0x02091CBC --cc 1.1p1 --arm
 *   EXACT, 124 bytes, 1 relocation site, resolved.
 *
 * symbols:
 *   g_02153FAC     0x02153FAC  data
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct P02091CBC {
    u32 f00;
    u32 f04;
    u32 f08;
    u8  f0c;
    u8  f0d;
    u8  pad0e[0xa];
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2c;
    u32 f30;
    u32 f34;
};

struct F04hiP { u32 lo : 7; u32 mode : 3; u32 hi : 22; };
struct F08P   { u32 mode : 3; u32 hi : 29; };

extern u32 g_02153FAC;

int func_02091CBC(struct P02091CBC *p)
{
    struct F08P *m08 = (struct F08P *)&p->f08;
    u8 mode;
    u8 sel;
    u32 m;
    u32 v;

    mode = ((struct F04hiP *)&p->f04)->mode;
    sel = mode + 0xff;
    if (sel > 1 || p->f0d != 0) {
        g_02153FAC = 0x28;
        return -1;
    }
    m = m08->mode;
    if (m == 0)
        return p->f18;
    v = p->f34 + (p->f24 - p->f1c);
    if (m >= 3)
        v -= m - 2;
    return v;
}
