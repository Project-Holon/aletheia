/*
 * function: func_021EC548
 * address:  0x021EC548
 * packet:   pkt_ov170_021EC548
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   _u32_div_f 0x0209C2B0 arm
 *   d_021EFD4C 0x021EFD4C data a2
 */

typedef struct { short x; short y; } Pos;
extern const Pos d_021EFD4C[];

void func_021EC548(unsigned i, short *x, short *y, int mode)
{
    if (i < 0x1E) {
        *x = (i % 6 + 1) * 0x18;
        *y = (i / 6) * 0x18 + 0x30;
        return;
    }
    i -= 0x1E;
    *x = d_021EFD4C[i].x;
    *y = d_021EFD4C[i].y - 0x90;
    if (mode == 2)
        *x += 0x98;
}
