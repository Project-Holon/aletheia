/*
 * function: FIELD_BUILDMODEL_CreateNodeNearPos
 * address:  0x0218C7D8
 * packet:   pkt_ov021_0218C7D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_BUILDMODEL_GetFirstEntryNearPos  0x0218C654  thumb  ov021
 *   FIELD_BUILDMODEL_CreateNodeFromEntry  0x0218C724  thumb  ov021
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
int FIELD_BUILDMODEL_GetFirstEntryNearPos(int a, int b, int c);
u8 *FIELD_BUILDMODEL_CreateNodeFromEntry(u8 *owner, u32 *obj);

int FIELD_BUILDMODEL_CreateNodeNearPos(void *p, int b, int c)
{
    int r = FIELD_BUILDMODEL_GetFirstEntryNearPos((int)p, b, c);
    if (r == 0)
        return 0;
    return (int)FIELD_BUILDMODEL_CreateNodeFromEntry(p, (u32 *)r);
}
