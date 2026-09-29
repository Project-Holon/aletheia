/*
 * function: func_021A8200
 * address:  0x021A8200
 * packet:   pkt_ov021_021A8200
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf: advance the Work step index and clear its frame counter.
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Work {
    u8 pad00[0x18];
    u16 f18;
    u8 pad1A[0x36 - 0x1A];
    u8 f36;
} Work;

void func_021A8200(Work *w)
{
    w->f36++;
    w->f18 = 0;
}
