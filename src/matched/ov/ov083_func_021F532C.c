/*
 * function: GPOWER_EVENT_CreateTimeoutScriptEvent
 * address: 0x021F532C
 * packet: pkt_ov083_021F532C
 * region: ov083
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   SCRIPT_SYS_CreateScriptEventSimple 0x02158768 thumb ov010
 */
struct Desc;
extern struct Desc *SCRIPT_SYS_CreateScriptEventSimple(int a0, int a1, int a2, int a3);
void GPOWER_EVENT_CreateTimeoutScriptEvent(void *p) { SCRIPT_SYS_CreateScriptEventSimple((int)p,0x28ba,0,0x15); }
