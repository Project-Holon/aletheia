/*
 * function: BTLV_SCU_ProcQuickEntryDouble
 * address:  0x021EB670
 * packet:   pkt_ov093_021EB670
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_SCU_ProcQuickEntry  0x021EB5B4  thumb  ov093
 *   gBtlvScuQuickSidesDouble  0x021F38AE  data  a4
 */
typedef unsigned char u8;
extern int BTLV_SCU_ProcQuickEntry(u8 *, int *, u8 *, u8);
extern u8 gBtlvScuQuickSidesDouble[];
int BTLV_SCU_ProcQuickEntryDouble(u8 *p, int *state)
{
    return BTLV_SCU_ProcQuickEntry(p, state, gBtlvScuQuickSidesDouble, 4);
}
