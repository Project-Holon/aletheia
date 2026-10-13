/*
 * function: BTLV_SCU_ProcQuickEntryTriple
 * address:  0x021EB680
 * packet:   pkt_ov093_021EB680
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_SCU_ProcQuickEntry  0x021EB5B4  thumb  ov093
 *   gBtlvScuQuickSidesTriple  0x021F38B2  data  a4
 */
typedef unsigned char u8;
extern int BTLV_SCU_ProcQuickEntry(u8 *, int *, u8 *, u8);
extern u8 gBtlvScuQuickSidesTriple[];
int BTLV_SCU_ProcQuickEntryTriple(u8 *p, int *state)
{
    return BTLV_SCU_ProcQuickEntry(p, state, gBtlvScuQuickSidesTriple, 6);
}
