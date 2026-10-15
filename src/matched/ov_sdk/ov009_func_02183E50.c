/*
 * function: gsXmlReadChildAsLargeInt
 * address:  0x02183E50
 * packet:   pkt_02156B70
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Clear 0x104 bytes at `c`, then fill `c+4` with up to 0x200 bytes through
 * gsXmlReadChildAsHexBinary; the byte count it reports is rounded up to a word count and
 * stored at c[0].  Returns 1 when the object validates, 0 when the fill loop
 * reports nothing produced.
 *
 * symbols:
 *   gsLargeIntReverseBytes  0x0217E934  arm
 *   gsXmlReadChildAsHexBinary  0x021837A4  arm
 *   MSL_C_LIB_MemsetPtr  0x020923B0  arm  arm9
 */

typedef unsigned int u32;

extern void *MSL_C_LIB_MemsetPtr(void *p, int c, u32 n);
extern int gsXmlReadChildAsHexBinary(void *stream, char *matchtag, unsigned char *valueOut, int maxLen, int *lenOut);
extern int gsLargeIntReverseBytes(char *p);

int gsXmlReadChildAsLargeInt(void *a, int b, int *c)
{
    u32 n = 0;
    u32 k;

    MSL_C_LIB_MemsetPtr(c, 0, 0x104);
    if (gsXmlReadChildAsHexBinary(a, (char *)b, (unsigned char *)(c + 1), 0x200, (int *)(&n)) == 0)
        return 0;

    k = n >> 2;
    c[0] = k;
    if (n & 3)
        c[0] = k + 1;

    if (gsLargeIntReverseBytes((char *)c) == 0)
        return 0;
    return 1;
}
