/*
 * function: taskEnd
 * address:  0x021D1B3C
 * packet:   pkt_ov016_021D1B3C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      taskEnd (window.o), callee of DWCi_WINlEnd (L5)
 *
 * symbols:
 *   DWCi_TSKlChangeFunc 0x021D771C arm
 *   MemWin             0x021DE658 data
 *   taskEnd1           0x021D1B78 arm
 */

struct tagMEMWIN {
    char pad[0x14];
    void *task;                  /* 0x14 */
    char pad2[0x1d - 0x18];
    unsigned char count;         /* 0x1d */
};

extern struct tagMEMWIN *MemWin;

void taskEnd1(void *task);
void DWCi_TSKlChangeFunc(void *task, void (*func)(void *));

void taskEnd(void *task)
{
    MemWin->count++;
    if (MemWin->count < 8)
        return;
    DWCi_TSKlChangeFunc(task, taskEnd1);
}
