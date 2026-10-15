/*
 * function: VIEWER_MAIN_DrawRowBg
 * address:  0x021C523C
 * packet:   pkt_ov111_021C523C
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VIEWER_MAIN_ClearBgBuf  0x021C59DC  thumb  ov111
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u8 pad0[0x32C7];
    u8 blink;
    u8 phase;
} Work;

extern void VIEWER_MAIN_ClearBgBuf(u32 bg, int mode);

void VIEWER_MAIN_DrawRowBg(Work *p, int flag)
{
    if (flag) {
        p->phase = 0;
        p->blink = 0;
    } else {
        p->phase = 2;
    }
    VIEWER_MAIN_ClearBgBuf(7, p->phase);
}
