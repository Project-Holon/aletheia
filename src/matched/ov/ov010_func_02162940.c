/*
 * function: EVENTDATA_SYSTEM_GetAutoPosEventScriptId
 * address: 0x02162940
 * packet: pkt_ov010_02162940
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   EVENTDATA_SYSTEM_SearchAutoPosEvent 0x02162890 thumb ov010
 */
typedef unsigned short u16;
struct Ctx;
struct Rec;
extern struct Rec *EVENTDATA_SYSTEM_SearchAutoPosEvent(struct Ctx *c, void *a, int key);
u16 EVENTDATA_SYSTEM_GetAutoPosEventScriptId(void *p, void *q, int key) { u16 *r=(u16 *)EVENTDATA_SYSTEM_SearchAutoPosEvent(p,q,key); if(r) return *r; return 0xffff; }
