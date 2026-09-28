/*
 * function: MBi_EndTaskThread
 * address:  0x021F67BC
 * packet:   pkt_ov107_021F67BC
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK: TwlSDK/libmb.TWL.HYB.a(mb_task.o).
 *
 * symbols:
 *   OS_DisableInterrupts             0x02087988 arm
 *   MBi_IsTaskAvailable              0x021f6610 arm
 *   MBi_SetTask                      0x021f6658 arm
 *   OS_RestoreInterrupts             0x0208799c arm
 *   mbi_task_work                    0x021f7004 data
 */
typedef unsigned long u32;

struct MBiTaskInfo_tag;

extern void *mbi_task_work;
extern u32 OS_DisableInterrupts(void);
extern int MBi_IsTaskAvailable(void);
extern void MBi_SetTask(struct MBiTaskInfo_tag *pt, void (*task)(struct MBiTaskInfo_tag *), void (*callback)(struct MBiTaskInfo_tag *), u32 priority);
extern u32 OS_RestoreInterrupts(u32 state);

void MBi_EndTaskThread(void (*callback)(struct MBiTaskInfo_tag *))
{
    u32 bak_cpsr = OS_DisableInterrupts();

    if (MBi_IsTaskAvailable())
        MBi_SetTask((struct MBiTaskInfo_tag *)((char *)mbi_task_work + 0xC4), 0, callback, 0);
    OS_RestoreInterrupts(bak_cpsr);
}
