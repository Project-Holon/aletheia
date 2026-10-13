/*
 * function: SCRIPT_SYS_RunInitScript
 * address: 0x02158A10
 * packet: pkt_ov010_02158A10
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   SCRIPT_SYS_RunScriptNow 0x02158A34 thumb ov010
 */
typedef unsigned short u16;
extern void SCRIPT_SYS_RunScriptNow(int a, int b, u16 c, int d);
void SCRIPT_SYS_RunInitScript(int a, int b) { SCRIPT_SYS_RunScriptNow(a, 0, 9600, 2); }
