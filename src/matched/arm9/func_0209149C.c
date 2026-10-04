/*
 * function: func_0209149C
 * address:  0x0209149C
 * packet:   pkt_0209149C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The gated sweep of g_020A8730: same three 0x4C-byte records as
 * func_02091524, but each record is only offered to func_02091B5C when three
 * bits of its own header agree, and the record is rejected as soon as any of
 * them fails.
 *
 * Two shapes carry the bytes:
 *
 *  - the 3-bit field at bits 7..9 of the record word at +4 has to be read as
 *    a bitfield, not as `(x << 22) >> 29`.  Writing the shifts out gives the
 *    same value but lets the register allocator put the loaded word in r2 and
 *    the extracted value in r1; the bitfield spelling puts the word in r1 and
 *    the extraction in r2, which is what the original has.  The pad member is
 *    what places the field at bit 7: a `lsl #0x16` (32 - (7 + 3)) extraction
 *    is only produced for a field whose offset is 7.
 *  - the middle test is `((x << 25) >> 30) & 1`, an unequal shift pair (the
 *    docs/idioms/unequal-shift-pair-is-a-narrowing-cast-folded-with-a-shift
 *    shape) and not a bitfield read: `tst r1, #1` after a 2-bit extraction is
 *    bit 5 selected out of a two-bit field, which no single declaration
 *    produces.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0209149C.c \
 *       --func func_0209149C --addr 0x0209149C --cc 1.1p1 --arm
 *   EXACT, 136 bytes, 2 relocation sites, both resolved.
 *
 * symbols:
 *   g_020A8730     0x020A8730  data
 *   func_02091B5C  0x02091B5C  arm
 */
#include "../include/Obj00481.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern u8 g_020A8730[];
extern int func_02091B5C(u8 *p);

struct Cfg4 {
    u32 pad : 7;
    u32 f3  : 3;
    u32 rest : 22;
};

struct Cfg0209149C {
    u32 mode : 3;
    u32 rest : 29;
};

int func_0209149C(void)
{
    u8 *p = g_020A8730;
    int i = 1;
    int r = 0;

    do {
        if (((struct Cfg4 *)(p + 4))->f3 != 0 &&
            (((((struct Obj00481 *)p)->f4 << 25) >> 30) & 1) != 0 &&
            ((struct Cfg0209149C *)(p + 8))->mode == 1) {
            if (func_02091B5C(p) != 0)
                r = -1;
        }
        p = (i < 3) ? g_020A8730 + i++ * 0x4c : 0;
    } while (p != 0);
    return r;
}
