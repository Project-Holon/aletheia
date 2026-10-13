/*
 * function: ghttpGetState
 * address:  0x021C22D4
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   ghiRequestToConnection  0x021C0DA4  arm  ov114
 *
 *
 * Current object's +0x10 word, or 0 when nothing is selected.
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern u8 *ghiRequestToConnection(void);

int ghttpGetState(int request)
{
    u8 *p = ghiRequestToConnection();
    if (p != 0)
        return *(u32 *)(p + 0x10);
    return 0;
}
