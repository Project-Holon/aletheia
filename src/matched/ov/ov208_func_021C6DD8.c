/*
 * function: ZUKAN_DETAIL_FORM_GetScrollSlotAtX
 * address:  0x021C6DD8
 * packet:   pkt_ov208_021C6DD8
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ZUKAN_DETAIL_FORM_GetScrollSlotRange  0x021C6D6C  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;

extern void ZUKAN_DETAIL_FORM_GetScrollSlotRange(int n, int i, u8 *lo, u8 *mid, u8 *hi);

u16 ZUKAN_DETAIL_FORM_GetScrollSlotAtX(u16 n, u8 x)
{
    u8 b[3];
    u16 i;

    for (i = 0; i < n; i++) {
        ZUKAN_DETAIL_FORM_GetScrollSlotRange(n, i, &b[2], &b[1], &b[0]);
        if (i == 0) {
            if (x < b[0])
                break;
        } else {
            if (i == n - 1)
                break;
            if (b[2] <= x && x < b[0])
                break;
        }
    }
    return i;
}
