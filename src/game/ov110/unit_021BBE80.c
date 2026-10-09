/*
 * file:     unit_021BBE80.c
 * function: GX_GetVCount
 * address:  0x021BBE80
 * packet:   pkt_ov110_021BBE80
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * SDK: TwlSDK/libos.TWL.HYB.thumb.a(os_valarm.o) per symbols_sdk.  Thumb leaf
 * (match.py show guesses ARM off the listing; the symbol's own thumb flag and
 * the 2-byte encodings make it Thumb).  Reads the VCOUNT register.
 */
typedef volatile unsigned short vu16;

vu16 GX_GetVCount(void)
{
    return *(vu16 *)0x04000006;
}
