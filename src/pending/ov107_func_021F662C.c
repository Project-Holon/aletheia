/*
 * function: MBi_InitTaskInfo
 * address:  0x021F662C
 * packet:   pkt_ov107_021F662C
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   PENDING
 *
 * SDK: TwlSDK/libmb.TWL.HYB.a(mb_task.o).  decl_line 161.
 */
typedef unsigned long u32;

extern void MI_CpuFill8(void *dst, int val, u32 len);

void MBi_InitTaskInfo(void *pt)
{
    MI_CpuFill8(pt, 0, 0x20);
}
