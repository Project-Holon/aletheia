/*
 * function: SCRIPT_SYS_RunRecoverScript
 * address: 0x02158A20
 * packet: pkt_ov010_02158A20
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
void SCRIPT_SYS_RunRecoverScript(int a, int v) { SCRIPT_SYS_RunScriptNow(a, 0, 9601, 2); }
