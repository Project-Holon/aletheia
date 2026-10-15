/*
 * function: SYMBOL_SAVE_SetRank
 * address:  0x0200E27C
 * packet:   pkt_0200E1A8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   _s32_div_f  0x0209C0A4  arm
 *
 * Slot-index arithmetic for the 0x84A/u8 table at +0x849: the byte written is
 * `(idx - 0x32) / 0x3c - 1` clamped to 6, and the three guards answer for
 * 0xffff, below 0xaa and above 0x212.  The divide is SIGNED (`_s32_div_f` at
 * 0x0209C0A4) while the two range tests are UNSIGNED, so the index parameter is
 * an `int` and the guards cast it to u32; spelling the parameter u32 instead
 * moves the divide to `_u32_div_f` and loses the site.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SYMBOL_SAVE_SetRank.c \
 *       --func SYMBOL_SAVE_SetRank --addr 0x0200E27C --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

extern int _s32_div_f(int a, int b);

void SYMBOL_SAVE_SetRank(u8 *obj, int idx)
{
    u8 v = (idx - 0x32) / 0x3c - 1;

    if (idx == 0xffff) {
        return;
    }
    if ((u32)idx < 0xaa) {
        return;
    }
    if ((u32)idx > 0x212) {
        return;
    }
    if (v > 6) {
        v = 6;
    }
    obj[0x849] = v;
}
