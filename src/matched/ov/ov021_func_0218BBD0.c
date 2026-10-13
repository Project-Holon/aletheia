/*
 * function: FIELD_BUILDMODEL_GetModelIndex
 * address:  0x0218BBD0
 * packet:   pkt_ov021_0218BBD0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef struct {
    unsigned char pad[0x1C];
    unsigned char arr[0x190];
    unsigned short n;
} S;

int FIELD_BUILDMODEL_GetModelIndex(S *p, unsigned int i)
{
    unsigned char v;
    if (i >= 0x190)
        i = 0;
    v = p->arr[i];
    if (v >= 0x80 || v >= p->n)
        v = 0;
    return v;
}
