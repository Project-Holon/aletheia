/*
 * function: FIELD_BUILDMODEL_GetModelIndexOut
 * address:  0x0218C574
 * packet:   pkt_ov021_0218C574
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_BUILDMODEL_GetModelIndex  0x0218BBD0  thumb  ov021
 */

typedef struct {
    int a, b, c;
    int *d;
} S;

int FIELD_BUILDMODEL_GetModelIndex(int a, int b);

void FIELD_BUILDMODEL_GetModelIndexOut(int a, S *s, int b)
{
    *s->d = FIELD_BUILDMODEL_GetModelIndex(a, b);
}
