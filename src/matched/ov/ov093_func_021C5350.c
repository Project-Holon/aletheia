/*
 * function: BTL_SERVER_FLOW_ApplyPartyExp
 * address: 0x021C5350
 * packet: pkt_ov093_021C5350
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: const entry source schedules byte arguments early; k precedes entry in declarations.
 * symbols:
 *   BTL_SLOT_GetPoke 0x021B9BF0 thumb ov093
 *   BTL_POKEPARAM_GetValue 0x021D59B4 thumb ov093
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_SERVER_CMD_PushVariable 0x021CD64C thumb ov093
 *   BTL_SERVER_CMD_Push 0x021CD4B0 thumb ov093
 *   BTL_POKEPARAM_AddExp 0x021D69B8 thumb ov093
 *   BTL_MAIN_TrainerRecordAddDelta 0x021BA1CC thumb ov093
 */
#include "../include/Obj05193.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Entry { u32 value; u8 flag; u8 a, b, c, d, e, f, pad; };
struct Obj;
struct Result;
struct S2;
extern u32 BTL_SLOT_GetPoke(struct S2 *p, u32 i);
extern int BTL_POKEPARAM_GetValue(u8 *p, int k);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_SERVER_CMD_PushVariable(void *, u8, ...);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
extern int BTL_POKEPARAM_AddExp(struct Obj *p, u32 *remaining, struct Result *r);
extern void BTL_MAIN_TrainerRecordAddDelta(char **p, int i, u32 delta);
int BTL_SERVER_FLOW_ApplyPartyExp(u8 *p, u8 *g, const struct Entry *q)
{
    u32 i;
    int result = 0;
    u8 *a;
    int k;
    u32 value;
    int cmd;
    const struct Entry *entry;
    u32 remaining;
    for (i = 0; i < 6; i++) {
        entry = &q[i];
        if (!entry->value) continue;
        a = (u8 *)BTL_SLOT_GetPoke((struct S2 *)g, (u8)i);
        if (BTL_POKEPARAM_GetValue(a, 15) >= 100) continue;
        value = entry->value;
        cmd = entry->flag ? 0x2b : 0x2a;
        k = BTL_POKEPARAM_GetPokeId(a);
        BTL_SERVER_CMD_PushVariable(((struct Obj05193 *)p)->fC, 0x5a, (u16)cmd, k, value, 0xffff0000);
        BTL_SERVER_CMD_Push(((struct Obj05193 *)p)->fC, 0x3e, k, q->a, q->b, q->c, q->d, q->e, q->f);
        remaining = value;
        while (BTL_POKEPARAM_AddExp((struct Obj *)a, &remaining, (struct Result *)(p + 0x4c0))) {}
        BTL_SERVER_CMD_Push(((struct Obj05193 *)p)->fC, 0x45, k, value);
        BTL_MAIN_TrainerRecordAddDelta(((struct Obj05193 *)p)->f4, 0x1b, value);
        result = 1;
    }
    return result;
}
