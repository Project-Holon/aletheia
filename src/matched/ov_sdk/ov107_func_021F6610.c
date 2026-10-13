/*
 * function: MBi_IsTaskAvailable
 * address:  0x021F6610
 * packet:   pkt_ov107_021F6610
 * region:   ov107
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MBi_IsTaskAvailable (libctrdg.TWL.HYB.a(ctrdg_task.o))
 *
 * symbols:
 *   ctrdgi_task_work 0x021f7004 data
 */

extern void *ctrdgi_task_work;

int MBi_IsTaskAvailable(void)
{
    return ctrdgi_task_work != 0;
}
