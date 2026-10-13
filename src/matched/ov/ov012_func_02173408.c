/*
 * function: UNION_COMM_ClearBeaconPcs
 * address:  0x02173408
 * packet:   pkt_ov012_02173408
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     unlabelled leaf (prints as .word in ov012.s); called from
 *           ov019 UNION_ONESELF_ColosseumExitMain.
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 */

typedef unsigned char u8;

void MI_CpuFill8(void *p, int v, int n);

void UNION_COMM_ClearBeaconPcs(u8 *w)
{
    MI_CpuFill8(w + 0x2910, 0, 0x578);
}
