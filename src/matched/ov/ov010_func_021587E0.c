/*
 * function: SCRIPT_SYS_HasVm
 * address: 0x021587E0
 * packet: pkt_ov010_021587E0
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Extent ends in two alignment padding bytes.
 * symbols:
 *   SCRIPT_SYS_GetFromWork 0x021589DC thumb ov010
 *   SCRIPT_SYS_GetVm 0x02158894 thumb ov010
 */
extern int SCRIPT_SYS_GetFromWork(int a0);
extern int SCRIPT_SYS_GetVm(int a0, int a1);
int SCRIPT_SYS_HasVm(int a, int b) {
    void *p = (void *)SCRIPT_SYS_GetFromWork(a);
    if (!p) return 0;
    if (SCRIPT_SYS_GetVm((int)p, b)) return 1;
    return 0;
}
