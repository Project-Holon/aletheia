/*
 * function: func_021A81EC
 * address:  0x021A81EC
 * packet:   pkt_ov021_021A81EC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf: the Work step table entry after the current one
 * (step[f36 + 1]); func_021A81DC reads step[f36].
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Work {
    u8 pad00[0x2C];
    u8 step[10];
    u8 f36;
} Work;

u8 func_021A81EC(Work *w)
{
    return w->step[(u8)(w->f36 + 1)];
}
