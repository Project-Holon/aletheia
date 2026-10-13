/*
 * function: FIELD_BUILDMODEL_DrawNodes
 * address:  0x0218B88C
 * packet:   pkt_ov021_0218B88C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_BUILDMODEL_DrawNode  0x0218C934  thumb  ov021
 */

void FIELD_BUILDMODEL_DrawNode(unsigned char *p);

void FIELD_BUILDMODEL_DrawNodes(unsigned char *p)
{
    int i;
    for (i = 0; i < 7; i++) {
        if (((void **)(p + 0x1DC))[i] != 0)
            FIELD_BUILDMODEL_DrawNode(((void **)(p + 0x1DC))[i]);
    }
}
