/*
 * function: SCRIPT_SYS_AddScript
 * address: 0x021589A0
 * packet: pkt_ov010_021589A0
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Extent ends in two alignment padding bytes.
 * symbols:
 *   SCRIPT_SYS_GetFromWork 0x021589DC thumb ov010
 *   SCRIPT_SYS_CreateVm 0x02158BFC thumb ov010
 *   SCRIPT_SYS_AddVm 0x0215886C thumb ov010
 */
typedef unsigned short u16;
extern int SCRIPT_SYS_GetFromWork(int a0);
extern int *SCRIPT_SYS_CreateVm(int a0, int a1, int a2, int a3, int a4);
extern int SCRIPT_SYS_AddVm(int a0, int a1);
int SCRIPT_SYS_AddScript(int a, int b, int c) {
    u16 *p = (u16 *)SCRIPT_SYS_GetFromWork(a);
    if (p) return SCRIPT_SYS_AddVm((int)p, (int)SCRIPT_SYS_CreateVm(*p, a, b, c, 0));
    return 3;
}
