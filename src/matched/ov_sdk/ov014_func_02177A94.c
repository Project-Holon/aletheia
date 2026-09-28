/*
 * function: CTRDGi_IsTaskAvailable
 * address:  0x02177A94
 * packet:   pkt_ov014_02177A94
 * region:   ov014
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * sdk:      CTRDGi_IsTaskAvailable (libctrdg.TWL.HYB.thumb.a(ctrdg_task.o))
 *
 * symbols:
 *   ctrdgi_task_work 0x021797a4 data
 */

extern void *ctrdgi_task_work;

int CTRDGi_IsTaskAvailable(void)
{
    return ctrdgi_task_work != 0;
}
