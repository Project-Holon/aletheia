/*
 * function: DWC_NdSetAttr
 * address:  0x021C5C04
 * packet:   pkt_ov114_021C5C04
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_NdSetAttr (libdwcnd.TWL.HYB.a dwc_nd.o)
 *
 * symbols:
 *   func_02059F38  0x02059F38  arm
 *   DWCi_NdSetAttr  0x021C5F90  arm  ov114
 */

extern int func_02059F38(void);
extern int DWCi_NdSetAttr(char *attr1, char *attr2, char *attr3);

int DWC_NdSetAttr(char *attr1, char *attr2, char *attr3)
{
    if (func_02059F38())
        return 0;
    return DWCi_NdSetAttr(attr1, attr2, attr3);
}
