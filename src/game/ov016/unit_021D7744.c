/*
 * file:     unit_021D7744.c
 * function: DWCi_TSKlDeleteByIndex
 * address:  0x021D7744
 * packet:   pkt_021D7474
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_TSKlDeleteByIndex   0x021D7744  arm
 *
 * ARM tail-call thunk into func_021D7750.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_TSKlDeleteByIndex.c \
 *       --func DWCi_TSKlDeleteByIndex --addr 0x021D7744 --region ov016 --cc dsi/1.1p1 --arm
 */

typedef unsigned int   u32;
struct TaskList;
extern void func_021D7750(u32 taskIdx, struct TaskList *taskList);

void DWCi_TSKlDeleteByIndex(unsigned int taskIdx, struct TaskList *taskList)
{
    func_021D7750(taskIdx, taskList);
}
