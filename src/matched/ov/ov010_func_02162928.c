/*
 * function: EVENTDATA_SYSTEM_GetPosEventScriptId
 * address: 0x02162928
 * packet: pkt_ov010_02162928
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   EVENTDATA_SYSTEM_SearchPosEvent 0x021627C8 thumb ov010
 */
typedef unsigned short u16;
struct Ctx;
struct Rec;
extern struct Rec *EVENTDATA_SYSTEM_SearchPosEvent(struct Ctx *c, void *a, int key, int mode);
u16 EVENTDATA_SYSTEM_GetPosEventScriptId(void *p, void *q, int key, int mode) { u16 *r=(u16 *)EVENTDATA_SYSTEM_SearchPosEvent(p,q,key,mode); if(r) return *r; return 0xffff; }
