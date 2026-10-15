/*
 * function: WORLDTRADE_SERVER_RecordTradeResult
 * address: 0x02201B44
 * packet: pkt_ov135_02201B44
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: u16 local joins species branches; byte flags use explicit masked RMW.
 * symbols:
 *   func_02008DF0 0x02008DF0 thumb
 *   MISC_SAVEDATA_GetBlock44 0x0200ED48 thumb
 *   MISC_SAVEDATA_InsertRecentValue 0x0200ED54 thumb
 *   WORLDTRADE_DEMO_ReadMyStatus 0x021F72C4 thumb ov135
 *   TRADE_HISTORY_GetFromSave 0x02009EC8 thumb
 *   func_02009DE8 0x02009DE8 thumb
 *   func_020307B0 0x020307B0 arm
 *   memset 0x02082BCC arm
 *   MYSTATUS_Copy 0x02008494 thumb
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   func_0202EB7C 0x0202EB7C thumb
 */
#include "../include/Obj06521.h"
#include "../include/Obj08195.h"
#include "../include/Obj23452.h"
#include "../include/Obj23453.h"
#include "../include/Obj23454.h"
#include "../include/Obj23455.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {
    u8 raw[0x20];
    u16 old_species;
    u16 new_species;
    u8 x;
    u8 y;
    u8 flags;
    u8 tail;
} Record;
struct L0200ED54;
struct Sub0200852CObj;
struct Sub02008C20Obj;
struct Sub02009D9CObj;
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern void *MISC_SAVEDATA_GetBlock44(void *);
extern void MISC_SAVEDATA_InsertRecentValue(struct L0200ED54 *l, u32 val);
extern void *WORLDTRADE_DEMO_ReadMyStatus(void *);
extern void *TRADE_HISTORY_GetFromSave(void *);
extern void func_02009DE8(struct Sub02009D9CObj *obj, struct Sub0200852CObj *p);
extern u32 func_020307B0(void *p);
extern void *memset(void *, int, u32);
extern void MYSTATUS_Copy(void *src, void *dst);
extern u32 POKE_TOOL_GetPartyValue(void *, u32, u32);
extern u32 func_0202EB7C(u32 a0, u32 a1);
void WORLDTRADE_SERVER_RecordTradeResult(u8 *p, void *mon, u8 *r, void *old)
{
    void *copy;
    Record rec;
    u16 species;
    func_02008DF0(((struct Obj23452 *)(*(u8 * *)&((struct Obj08195 *)p)->f0))->f24, 0x10);
    MISC_SAVEDATA_InsertRecentValue(MISC_SAVEDATA_GetBlock44(((struct Obj23453 *)(*(u8 * *)&((struct Obj08195 *)p)->f0))->f3C), ((struct Obj06521 *)r)->f10C);
    copy = WORLDTRADE_DEMO_ReadMyStatus(r);
    func_02009DE8(TRADE_HISTORY_GetFromSave(((struct Obj23454 *)(*(u8 * *)&((struct Obj08195 *)p)->f0))->f3C), copy);
    func_020307B0(copy);
    copy = WORLDTRADE_DEMO_ReadMyStatus(r);
    memset(&rec, 0, sizeof(rec));
    MYSTATUS_Copy(copy, &rec);
    if (old != 0) species = POKE_TOOL_GetPartyValue(old, 5, 0);
    else species = ((struct Obj06521 *)r)->fEC;
    rec.old_species = species;
    rec.new_species = POKE_TOOL_GetPartyValue(mon, 5, 0);
    rec.x = ((struct Obj06521 *)r)->f126;
    rec.flags = (rec.flags & ~7) | (((struct Obj06521 *)r)->fF7 & 7);
    rec.y = ((struct Obj06521 *)r)->f127;
    func_0202EB7C((u32)(((struct Obj23455 *)(*(u8 * *)&((struct Obj08195 *)p)->f0))->f18), (u32)(&rec));
    func_020307B0(copy);
}
