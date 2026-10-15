/*
 * function: WIFI_2DCHAR_ReleaseCell
 * address:  0x021C4424
 * packet:   pkt_021C4424
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WIFI_2DCHAR_ReleaseCellPair  0x021C4440  thumb
 *   WIFI_2DCHAR_ReleaseCellChar  0x021C4464  thumb
 *
 * Addresses are Black-image addresses.
 */

extern void WIFI_2DCHAR_ReleaseCellPair(char *, int);
typedef unsigned char  u8;
extern void WIFI_2DCHAR_ReleaseCellChar(u8 *p, int i);

void WIFI_2DCHAR_ReleaseCell(char *p, int i)
{
    if (*(int *)(p + i * 0x14 + 0x10) == 0)
        WIFI_2DCHAR_ReleaseCellPair(p, i);
    else
        WIFI_2DCHAR_ReleaseCellChar((u8 *)p, i);
}
