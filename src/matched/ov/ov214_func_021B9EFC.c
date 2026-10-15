/*
 * function: BTL_REC_SEL_StartEntryB
 * address:  0x021B9EFC
 * packet:   pkt_021B9EFC
 * region:   ov214
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_REC_SEL_SetEntryB 0x021B9F10 thumb
 */

extern void BTL_REC_SEL_SetEntryB(int unused, char *b, int c, int d);

void BTL_REC_SEL_StartEntryB(int *out, int a, int b, int c, int d)
{
    *out = 4;
    BTL_REC_SEL_SetEntryB(a, (char *)b, c, d);
}