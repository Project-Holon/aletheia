/*
 * function: DWCi_WINlEnd
 * address:  0x021D1524
 * packet:   pkt_ov016_021D1524
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_WINlEnd (window.o), callee of procError (L5)
 *
 * symbols:
 *   DWCi_TSKlDelete   0x021D7724 arm
 *   DWCi_TSKlForm     0x021D7680 arm
 *   MemWin            0x021DE658 data
 *   taskEnd           0x021D1B3C arm
 */

struct tagMEMWIN {
    unsigned char pad[0x14];
    void *task;
};

extern struct tagMEMWIN *MemWin;

void DWCi_TSKlDelete(int kind, void *task);
void *DWCi_TSKlForm(int kind, void (*func)(void *, void *), void *work, unsigned char prio);
void taskEnd(void *task, void *work);

void DWCi_WINlEnd(void)
{
    DWCi_TSKlDelete(0, MemWin->task);
    MemWin->task = DWCi_TSKlForm(1, taskEnd, 0, 0x78);
}
