/*
 * unit:     yes
 * address:  0x0201D4BC
 * packet:   pkt_0201CEE0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_0201D4BC
 *
 * Finds the index of the 0xBD06 tag whose first parameter is the caller's
 * value, counting 0xFFFE separators as it goes.  The tag's parameter is read
 * with func_0201D670's body written out inline (`p[0] == 0xF000 ? p[3] : 0`),
 * including the redundant re-test of p[0] that the caller has already made: that
 * guard is in the bytes and removing it costs four instructions.
 *
 * 0xFFFE is not a second pool word.  The original loads 0xFFFF once and derives
 * 0xFFFE with `subs r4, r0, #1`, which is ordinary common subexpression
 * elimination on the constant and needs nothing in the source.
 *
 * The leading call to func_02045A90 whose result is discarded is in the original
 * and is reproduced rather than tidied.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201D4BC.c \
 *       --addr 0x0201D4BC --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 *func_02045A90(void *s);
extern u16 *func_0201D688(u16 *p);

u32 func_0201D4BC(void *s, u32 v)
{
    u16 *p;
    u16 n = 0;
    u32 t;

    func_02045A90(s);
    p = func_02045A90(s);
    while (p[0] != 0xFFFF) {
        if (p[0] == 0xFFFE) {
            n = (u16)(n + 1);
        }
        if (p[0] == 0xF000) {
            if (p[1] == 0xBD06) {
                if (p[0] == 0xF000) {
                    t = p[3];
                } else {
                    t = 0;
                }
                if (v == t) {
                    return (u8)n;
                }
            }
            p = func_0201D688(p);
        } else {
            p = p + 1;
        }
    }
    return 0;
}
