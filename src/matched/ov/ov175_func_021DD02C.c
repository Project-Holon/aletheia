/*
 * function: WIFIBATTLEMATCH_NET_GetRegNameA
 * address:  0x021DD02C
 * packet:   pkt_021DD02C
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021E3270  0x021E3270  data
 *
 * Returns the address of the ov175 table at 0x021E3270.
 */

typedef unsigned long u32;

extern char d_021E3270[];

char *WIFIBATTLEMATCH_NET_GetRegNameA(void)
{
    return d_021E3270;
}
