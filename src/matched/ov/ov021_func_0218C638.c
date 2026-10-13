/*
 * function: FIELD_BUILDMODEL_GetFirstEntryInRect
 * address:  0x0218C638
 * packet:   pkt_ov021_0218C638
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_BUILDMODEL_CollectEntriesInRect  0x0218C584  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 */

int *FIELD_BUILDMODEL_CollectEntriesInRect(int a, int b, int c, int *out);
typedef unsigned int   u32;
u32 func_020307B0(void *p);

int FIELD_BUILDMODEL_GetFirstEntryInRect(int a, int b, int c)
{
    int tmp;
    int *r = FIELD_BUILDMODEL_CollectEntriesInRect(a, c, b, &tmp);
    int v = *r;
    func_020307B0(r);
    return v;
}
