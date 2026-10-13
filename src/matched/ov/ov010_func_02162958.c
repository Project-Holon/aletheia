/*
 * function: EVENTDATA_SYSTEM_GetRailPosEventScriptId
 * address: 0x02162958
 * packet: pkt_ov010_02162958
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   EVENTDATA_SYSTEM_SearchRailPosEvent 0x021628E4 thumb ov010
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Ctx;
struct Rec;
extern struct Rec *EVENTDATA_SYSTEM_SearchRailPosEvent(struct Ctx *c, void *a, int key);
u16 EVENTDATA_SYSTEM_GetRailPosEventScriptId(void *c, void *a, int key)
{
    u16 *r = (u16 *)EVENTDATA_SYSTEM_SearchRailPosEvent(c, a, key);
    if (r != 0) return *r;
    return 0xffff;
}
