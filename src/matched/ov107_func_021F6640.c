/*
 * function: MBi_IsTaskBusy
 * address:  0x021F6640
 * packet:   pkt_ov107_021F6640
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK: TwlSDK/libmb.TWL.HYB.a(mb_task.o).  decl_line 176.
 */
typedef unsigned long u32;

typedef struct
{
    u32 pad0;
    u32 busy : 1;
} MBiTaskInfo;

int MBi_IsTaskBusy(MBiTaskInfo *pt)
{
    return pt->busy != 0;
}
