/*
 * function: DWCi_MOVlEnd
 * address:  0x021C115C
 * packet:   pkt_ov016_021C115C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_MOVlEnd (move.o), TwlDWC libdwcutil.TWL.HYB.a
 *           callee of endScene1 (0x021C43AC), same region.
 *
 * symbols:
 *   DWCi_TSKlForm                    0x021D7680  arm
 *   taskEnd                          0x021C117C  arm
 */
extern void *DWCi_TSKlForm(int kind, void (*func)(void *), void *work, unsigned char prio);
extern void taskEnd(void *task);

void DWCi_MOVlEnd(void)
{
    DWCi_TSKlForm(0, taskEnd, 0, 0x78);
}
