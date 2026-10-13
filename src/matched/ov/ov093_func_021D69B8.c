/*
 * function: BTL_POKEPARAM_AddExp
 * address: 0x021D69B8
 * packet: pkt_ov093_021D69B8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02018584 0x02018584 thumb
 *   POKE_TOOL_DecodePartyParam 0x02017D30 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   POKE_TOOL_SetPartyValue 0x02017E40 thumb
 *   POKE_TOOL_RecalcParam 0x020185C4 thumb
 *   POKE_TOOL_EncodePartyParam 0x02017D70 thumb
 *   BTL_POKEPARAM_SaveMovesToMon 0x021D505C thumb ov093
 *   func_02082BCC 0x02082BCC arm
 */
#include "../include/Obj00041.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
struct Obj {void *w; u32 f4,exp; u16 species,hp,total,item,f14,f16; u8 level,f19,f1A; u8 low:5,b5:1,b6:1,b7:1;};
struct Result {u8 level,pad; u16 hp,a,b,c,d,e;};
extern u32 func_02018584(u16,u16,u16);
struct Sav;
extern u32 POKE_TOOL_DecodePartyParam(struct Sav *p);
extern u32 func_02017E1C(void *,u32,u32);
extern void POKE_TOOL_SetPartyValue(void *,u32,u32);
extern void POKE_TOOL_RecalcParam(void *);
extern u32 POKE_TOOL_EncodePartyParam(struct Sav *p, u32 f);
struct A;
extern void BTL_POKEPARAM_SaveMovesToMon(struct A *a);
extern void func_02082BCC(void *,u8,u32);
int BTL_POKEPARAM_AddExp(struct Obj *p, u32 *remaining, struct Result *r)
{
    u32 old, total, delta, threshold;
    u16 hp,a,b,d,e,c;
    u8 saved;
    if (p->level < 100) {
        old = p->exp;
        total = old + *remaining;
        threshold = func_02018584(p->species,((u8 *)p)[0x141],p->level + 1);
        if (total >= threshold) {
            delta = threshold - old;
            hp = p->hp;
            saved = POKE_TOOL_DecodePartyParam(p->w);
            a = func_02017E1C(p->w,0xa2,0);
            b = func_02017E1C(p->w,0xa3,0);
            c = func_02017E1C(p->w,0xa4,0);
            d = func_02017E1C(p->w,0xa5,0);
            e = func_02017E1C(p->w,0xa6,0);
            p->exp = old + delta;
            POKE_TOOL_SetPartyValue(p->w,8,p->exp);
            POKE_TOOL_RecalcParam(p->w);
            p->hp = func_02017E1C(p->w,0xa1,0);
            p->level = func_02017E1C(p->w,0x9e,0);
            hp = p->hp - hp;
            r->a = func_02017E1C(p->w,0xa2,0);
            r->b = func_02017E1C(p->w,0xa3,0);
            r->c = func_02017E1C(p->w,0xa5,0);
            r->d = func_02017E1C(p->w,0xa6,0);
            r->e = func_02017E1C(p->w,0xa4,0);
            if (p->b5 == 0) {
                ((struct Obj00041 *)p)->fEE = r->a;
                ((struct Obj00041 *)p)->fF0 = r->b;
                ((struct Obj00041 *)p)->fF2 = r->c;
                ((struct Obj00041 *)p)->fF4 = r->d;
                ((struct Obj00041 *)p)->fF6 = r->e;
            }
            r->level = p->level;
            r->hp = hp;
            r->a -= a;
            r->b -= b;
            r->c -= d;
            r->d -= e;
            r->e -= c;
            p->total += hp;
            POKE_TOOL_SetPartyValue(p->w,0xa0,p->total);
            BTL_POKEPARAM_SaveMovesToMon((struct A *)p);
            POKE_TOOL_EncodePartyParam(p->w,saved);
            *remaining -= delta;
            return 1;
        } else {
            p->exp = total;
            POKE_TOOL_SetPartyValue(p->w,8,total);
        }
    }
    if (r != 0) func_02082BCC(r,0,14);
    return 0;
}
