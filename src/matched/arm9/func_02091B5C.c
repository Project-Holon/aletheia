/*
 * function: func_02091B5C
 * address:  0x02091B5C
 * packet:   pkt_02091B5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The state machine the g_020A8730 sweep calls per record (and the entry the
 * null argument routes to func_02091524).  A record is rejected when its +0xd
 * byte is set or when its +4 field at bits 7..9 is zero, is a no-op when the
 * +4 field at bits 2..4 is 1, otherwise its +8 three-bit mode is forced to 2
 * when it is 3 or more (clearing the low three bits first), the record is
 * cleared when that mode is 2, and anything but mode 1 clears the mode and
 * returns.  Mode 1 runs the transaction func_02091650, and either sets the
 * +0xd byte and returns -1 or clears mode, +0x18 and +0x28 and returns 0.
 *
 * Every one of the five field accesses is a bitfield read/write against a
 * view struct cast onto the word, and that is load-bearing: written as
 * `(p->f08 << 29) >> 29` the three-mode tests are re-derived as `and #7` and
 * the whole tail renumbers, while a bitfield extraction is emitted as the
 * shift pair directly and is never folded (this is the same finding as
 * src/matched/func_0209149C.c and func_02091524.c's neighbour).  The mode
 * writes come out as exactly `bic`/`orr` on the low three bits, which is what
 * a bitfield assignment emits, and the constant -1 the failure path returns is
 * derived by the compiler from the 1 it has just stored (`subne r0, r0, #2`).
 *
 * The `||` over the two rejection tests is what shares the `mvn r0, #0`
 * epilogue; two separate `if`s cost 20 bytes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02091B5C.c \
 *       --func func_02091B5C --addr 0x02091B5C --cc 1.1p1 --arm
 *   EXACT, 228 bytes, 2 relocation sites, both resolved.
 *
 * symbols:
 *   func_02091524  0x02091524  arm
 *   func_02091650  0x02091650  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct P02091B5C {
    u32 f00;
    u32 f04;
    u32 f08;
    u8  f0c;
    u8  f0d;
    u8  pad0e[0xa];
    u32 f18;
    u32 pad1c[3];
    u32 f28;
};

struct F04hi { u32 lo : 7; u32 mode : 3; u32 hi : 22; };
struct F04lo { u32 lo : 2; u32 sub : 3; u32 hi : 27; };
struct F08   { u32 mode : 3; u32 hi : 29; };

extern int func_02091524(void);
struct S02091650;
extern int func_02091650(struct S02091650 *p, u32 *a1);

int func_02091B5C(struct P02091B5C *p)
{
    int r;

    if (p == 0)
        return func_02091524();
    if (p->f0d != 0 || ((struct F04hi *)&p->f04)->mode == 0)
        return -1;
    if (((struct F04lo *)&p->f04)->sub == 1)
        return 0;
    if (((struct F08 *)&p->f08)->mode >= 3)
        ((struct F08 *)&p->f08)->mode = 2;
    if (((struct F08 *)&p->f08)->mode == 2)
        p->f28 = 0;
    if (((struct F08 *)&p->f08)->mode != 1) {
        ((struct F08 *)&p->f08)->mode = 0;
        return 0;
    }
    r = func_02091650((struct S02091650 *)p, 0);
    if (r != 0) {
        p->f0d = 1;
        p->f28 = 0;
        return -1;
    }
    ((struct F08 *)&p->f08)->mode = 0;
    p->f18 = 0;
    p->f28 = 0;
    return 0;
}
