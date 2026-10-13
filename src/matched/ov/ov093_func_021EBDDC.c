/*
 * function: BTLV_SCU_ProcEntryDoubleTrainerComm
 * address:  0x021EBDDC
 * packet:   pkt_ov093_021EBDDC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_SCU_ProcQuickEntryDouble  0x021EB670  thumb  ov093
 *   gBtlvScuDoubleTrainerCommPhases  0x021F38DC  data  a4
 */

typedef unsigned char u8;

extern int BTLV_SCU_ProcQuickEntryDouble(u8 *, int *);
extern int (*const gBtlvScuDoubleTrainerCommPhases[])(u8 *, int *);


int BTLV_SCU_ProcEntryDoubleTrainerComm(int *a, u8 *b)
{
    if (b[0x150] != 0)
        return BTLV_SCU_ProcQuickEntryDouble(b, a);
    if (b[0x14f] < 3) {
        if (gBtlvScuDoubleTrainerCommPhases[b[0x14f]](b, a) != 0) {
            b[0x14f] = b[0x14f] + 1;
            *a = 0;
        }
        return 0;
    }
    return 1;
}
