/*
 * function: FIELD_BUILDMODEL_GetNodeByHandle
 * address:  0x0218BA98
 * packet:   pkt_ov021_0218BA98
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef struct {
    unsigned char pad[0x1DC];
    void *arr[7];
} S;

void *FIELD_BUILDMODEL_GetNodeByHandle(S *p, int h)
{
    unsigned short idx = h & ~0xFFF0;
    if ((unsigned short)(h & 0xFFF0) != 0xFFF0)
        return 0;
    if (idx >= 7)
        return 0;
    return p->arr[idx];
}
