/*
 * function: VIEWER_TEXT_DrawWindow
 * address:  0x021C636C
 * packet:   pkt_ov111_021C636C
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VIEWER_TEXT_DrawPage  0x021C6874  thumb  ov111
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef short s16;

typedef struct {
    u8 pad0[0x32E2];
    s16 scroll;
} Work;

extern void VIEWER_TEXT_DrawPage(Work *p, int scroll, int flush, int idx);

void VIEWER_TEXT_DrawWindow(Work *p, void *bg, void *info)
{
    VIEWER_TEXT_DrawPage(p, p->scroll, 0, 0);
}
