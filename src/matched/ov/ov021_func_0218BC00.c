/*
 * function: FIELD_BUILDMODEL_GetModelResourceData
 * address:  0x0218BC00
 * packet:   pkt_ov021_0218BC00
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Leaf: offset-table walk.  p[2] is a byte count; the table starts at p+4,
 * each entry a 32-bit relative offset.  Returns p + entry[i + (p[2]>>1)].
 * Callee of FIELD_BUILDMODEL_LoadArea.
 */

char *FIELD_BUILDMODEL_GetModelResourceData(char *p, int i)
{
    unsigned n = (unsigned char)p[2];
    return p + *(int *)(p + 4 + ((n >> 1) + i) * 4);
}
