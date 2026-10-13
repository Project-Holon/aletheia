/*
 * function: TALKMSGWIN_Close
 * address:  0x02194950
 * packet:   pkt_02194B78
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call with a strided element address and the index.
 *
 * symbols:
 *   TALKMSGWIN_RequestClose  0x02194B78  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void TALKMSGWIN_RequestClose(u8 *e, int i);

void TALKMSGWIN_Close(u8 *p, int i)
{
    TALKMSGWIN_RequestClose(p + 0x18 + i * 100, i);
}
