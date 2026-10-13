/*
 * file:     task_3.c
 * function: DWCi_TSKlDelete
 * address:  0x021D7724
 * packet:   pkt_ov016_021D7724
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_TSKlDelete (task.o), callee of DWCi_WINlEnd / taskWait (L5)
 *
 * symbols:
 *   MemTask            0x021DE6E4 data
 *   DWCi_QUElPushBack  0x021D546C arm
 */

struct tagMEMTASK {
    unsigned int f0;
    void *task;                  /* 0x04 */
    unsigned char rest[0x38];
};

extern struct tagMEMTASK *MemTask;

void DWCi_QUElPushBack(void *queue, void *data);

void DWCi_TSKlDelete(int kind, void *task)
{
    DWCi_QUElPushBack(MemTask[kind].task, task);
}
