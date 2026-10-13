/*
 * function: BTL_SERVER_FLOW_BuildDamageList
 * address: 0x021C0A4C
 * packet: pkt_ov093_021C0A4C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: const descriptor q hoists its halfword load before the record store.
 * symbols:
 *   func_021C0C04 0x021C0C04 thumb ov093
 *   func_021C0C14 0x021C0C14 thumb ov093
 *   func_021C0C24 0x021C0C24 thumb ov093
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_SERVER_FLOW_CheckCriticalHit 0x021C6BF8 thumb ov093
 *   func_021CC8B8 0x021CC8B8 thumb ov093
 *   BTL_SERVER_FLOW_CalcMoveDamage 0x021C1E74 thumb ov093
 *   BTL_POKEPARAM_HasSubstitute 0x021D6D7C thumb ov093
 *   BTL_SERVER_FLOW_ClampDamageToHp 0x021C15D4 thumb ov093
 *   BTL_SERVER_FLOW_CheckEndureEvent 0x021C1678 thumb ov093
 *   func_021C7C24 0x021C7C24 thumb ov093
 */
#include "../include/Obj21063.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Entry { u16 value; u16 id:5; u16 mode:4; u16 type:4; u16 marked:1; u16 special:1; u16 error:1; };
struct List { u8 good, bad, count, pad; struct Entry entries[1]; };
extern void func_021C0C04(u8 *);
extern u8 *func_021C0C14(u8 *);
extern u8 *func_021C0C24(u8 *);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern int BTL_SERVER_FLOW_CheckCriticalHit(u8 *p, u8 *a, u8 *b, u16 q);
extern u32 func_021CC8B8(u32 *p, u32 i);
extern int BTL_SERVER_FLOW_CalcMoveDamage(u8 *, u8 *, u8 *, const u8 *, u32, u16, u32, u32, u16 *);
extern u32 BTL_POKEPARAM_HasSubstitute(u8 *p);
extern u32 BTL_SERVER_FLOW_ClampDamageToHp(void *p, u32 n);
extern int BTL_SERVER_FLOW_CheckEndureEvent(u8 *, u8 *, u8 *, u32, u16 *);
extern void func_021C7C24(u16 *, int, u8 *, u8 *, int);
void BTL_SERVER_FLOW_BuildDamageList(u8 *p, u8 *a, u8 *b, const u8 *q, const u32 *c, u16 k, struct List *out)
{
    int i = 0;
    u8 *r;
    struct { u16 x, y; } temp;
    out->good = 0;
    out->bad = 0;
    func_021C0C04(b);
    r = func_021C0C14(b);
    if (r != 0) {
        do {
            out->entries[i].id = BTL_POKEPARAM_GetPokeId(r);
            out->entries[i].marked = (u16)BTL_SERVER_FLOW_CheckCriticalHit(p, a, r, (u32)(((struct Obj21063 *)q)->f0));
            out->entries[i].mode = (u16)(int)func_021CC8B8((u32 *)c, (u8)out->entries[i].id);
            out->entries[i].special = (u16)BTL_SERVER_FLOW_CalcMoveDamage(p, a, r, q, out->entries[i].mode, k, out->entries[i].marked, 0, &temp.y);
            out->entries[i].value = temp.y;
            if (out->entries[i].special) {
                out->entries[i].marked = 0;
                out->entries[i].mode = 3;
            }
            out->entries[i].error = (u16)BTL_POKEPARAM_HasSubstitute(r);
            if (!out->entries[i].error) {
                temp.x = BTL_SERVER_FLOW_ClampDamageToHp(r, out->entries[i].value);
                out->entries[i].type = (u16)BTL_SERVER_FLOW_CheckEndureEvent(p, a, r, 1, &temp.x);
                out->entries[i].value = temp.x;
                out->good++;
            } else {
                out->entries[i].value = temp.y;
                out->entries[i].type = 0;
                out->bad++;
            }
            func_021C7C24((u16 *)(p + 0x1f7c), (int)p, a, r, out->entries[i].mode);
            i++;
            r = func_021C0C24(b);
        } while (r != 0);
    }
    out->count = i;
}
