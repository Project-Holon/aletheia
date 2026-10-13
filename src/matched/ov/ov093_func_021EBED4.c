/*
 * function: BTLV_SCU_ProcEntryTriple
 * address:  0x021EBED4
 * packet:   pkt_ov093_021EBED4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_SCU_ProcQuickEntryTriple  0x021EB680  thumb  ov093
 *   gBtlvScuEntryTriplePhases  0x021F38C4  data  a4
 */

typedef unsigned char u8;

extern int BTLV_SCU_ProcQuickEntryTriple(u8 *, int *);
extern int (*const gBtlvScuEntryTriplePhases[])(u8 *, int *);


int BTLV_SCU_ProcEntryTriple(int *a, u8 *b)
{
    if (b[0x150] != 0)
        return BTLV_SCU_ProcQuickEntryTriple(b, a);
    if (b[0x14f] < 3) {
        if (gBtlvScuEntryTriplePhases[b[0x14f]](b, a) != 0) {
            b[0x14f] = b[0x14f] + 1;
            *a = 0;
        }
        return 0;
    }
    return 1;
}
