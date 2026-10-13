/*
 * function: SCRIPT_WORK_CmdWaitKeyDecide
 * address: 0x02159974
 * packet: pkt_ov010_02159974
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   SCRIPT_WORK_WaitKeyDecide 0x02159960 thumb ov010
 *   VM_SetWait  0x020113D0  thumb  arm9
 */
extern int SCRIPT_WORK_WaitKeyDecide(int a0, int a1);
extern void VM_SetWait(char *, int);
int SCRIPT_WORK_CmdWaitKeyDecide(char *p)
{
    VM_SetWait(p, (int)SCRIPT_WORK_WaitKeyDecide);
    return 1;
}
