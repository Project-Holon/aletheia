/*
 * file:     unit_021D771C.c
 * function: DWCi_TSKlSetParam
 * address:  0x021D771C
 * packet:   pkt_021D7474
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_TSKlSetParam   0x021D771C  arm
 *
 * Store a word at +0x08 of the argument.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_TSKlSetParam.c \
 *       --func DWCi_TSKlSetParam --addr 0x021D771C --region ov016 --cc dsi/1.1p1 --arm
 */

/* Task object of the DWC GUI task list (task.o); only the parameter word is written here. */
typedef struct TaskObj {
    unsigned char pad00[0x08];
    unsigned int param;
} TaskObj;

void DWCi_TSKlSetParam(TaskObj *task, unsigned int param)
{
    task->param = param;
}
