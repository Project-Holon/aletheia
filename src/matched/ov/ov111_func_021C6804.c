/*
 * function: VIEWER_TEXT_SetScrollParam
 * address:  0x021C6804
 * packet:   pkt_ov111_021C6804
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VIEWER_TEXT_SetScroll  0x021C67E8  thumb  ov111
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u8 pad0[0x68];
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 b4 : 1;
} Info;

extern void VIEWER_TEXT_SetScroll(void *p, int v);

void VIEWER_TEXT_SetScrollParam(void *p, Info *info)
{
    int i;

    for (i = 0; i < 13; i++) {
        VIEWER_TEXT_SetScroll(p, i);
    }
    if (info->b0) {
        VIEWER_TEXT_SetScroll(p, 14);
        VIEWER_TEXT_SetScroll(p, 13);
    }
    if (info->b1) {
        VIEWER_TEXT_SetScroll(p, 15);
    }
    if (info->b2) {
        VIEWER_TEXT_SetScroll(p, 16);
    }
    if (info->b3) {
        VIEWER_TEXT_SetScroll(p, 17);
    }
    if (info->b4) {
        VIEWER_TEXT_SetScroll(p, 18);
    }
}
