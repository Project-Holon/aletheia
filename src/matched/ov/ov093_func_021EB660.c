/*
 * function: BTLV_SCU_ProcQuickEntrySingle
 * address:  0x021EB660
 * packet:   pkt_ov093_021EB660
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_SCU_ProcQuickEntry  0x021EB5B4  thumb  ov093
 *   gBtlvScuQuickSidesSingle  0x021F38AC  data  a4
 */
typedef unsigned char u8;
extern int BTLV_SCU_ProcQuickEntry(u8 *, int *, u8 *, u8);
extern u8 gBtlvScuQuickSidesSingle[];
int BTLV_SCU_ProcQuickEntrySingle(u8 *p, int *state)
{
    return BTLV_SCU_ProcQuickEntry(p, state, gBtlvScuQuickSidesSingle, 2);
}
