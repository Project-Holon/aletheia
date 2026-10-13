/*
 * function: FIELD_BUILDMODEL_GetFirstEntryNearPos
 * address:  0x0218C654
 * packet:   pkt_ov021_0218C654
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_BUILDMODEL_MakeSearchRect  0x0218C9C4  thumb  ov021
 *   FIELD_BUILDMODEL_GetFirstEntryInRect  0x0218C638  thumb  ov021
 */

void FIELD_BUILDMODEL_MakeSearchRect(unsigned char *buf, int c);
int FIELD_BUILDMODEL_GetFirstEntryInRect(int a, int b, int c);

int FIELD_BUILDMODEL_GetFirstEntryNearPos(int a, int b, int c)
{
    unsigned char buf[16];
    FIELD_BUILDMODEL_MakeSearchRect(buf, c);
    return FIELD_BUILDMODEL_GetFirstEntryInRect(a, b, (int)buf);
}
