/*
 * function: func_021C5FA8
 * address:  0x021C5FA8
 * packet:   pkt_ov021_021C5FA8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf (saves no lr) after func_021C5DF4's pool; its only caller
 * is func_021C5DF4.  Frame counter at +0x60: true once it passes n, then
 * rewinds.
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u8 pad0[0x60];
    u32 f60;
} Work;

int func_021C5FA8(Work *w, u32 n)
{
    if (w->f60++ < n)
        return 0;
    w->f60 = 0;
    return 1;
}
