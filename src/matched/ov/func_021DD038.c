/*
 * function: func_021DD038
 * address:  0x021DD038
 * packet:   pkt_021DD038
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021E3250  0x021E3250  data
 *
 * Returns the address of the ov175 table at 0x021E3250.
 */

typedef unsigned long u32;

extern char d_021E3250[];

char *func_021DD038(void)
{
    return d_021E3250;
}
