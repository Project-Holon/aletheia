/*
 * function: SCRIPT_SYS_SetNextEventFromWork
 * address: 0x0215898C
 * packet: pkt_ov010_0215898C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   SCRIPT_SYS_GetFromWork 0x021589DC thumb ov010
 *   SCRIPT_SYS_SetNextEvent 0x021588A4 thumb ov010
 */
extern int SCRIPT_SYS_GetFromWork(int a0);
extern void SCRIPT_SYS_SetNextEvent(void *, int);
void SCRIPT_SYS_SetNextEventFromWork(int a, int b) {
    void *p = (void *)SCRIPT_SYS_GetFromWork(a);
    if (p != 0) SCRIPT_SYS_SetNextEvent(p, b);
}
