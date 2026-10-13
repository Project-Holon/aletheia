/*
 * function: BTL_MAIN_WriteBackResults
 * address: 0x021BA2E4
 * packet: pkt_ov093_021BA2E4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: separate per-site product temporaries reproduce the scalar-add operand order.
 * symbols:
 *   NATSUKI_CalcParty 0x0201B818 thumb
 *   POKEPARTY_GetCount 0x0201AA18 thumb
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   POKE_TOOL_SetPartyValue 0x02017E40 thumb
 *   POKEPARTY_Copy 0x0201AC2C thumb
 *   BTL_SIDE_WriteBackPartyOrdered 0x021B97A0 thumb ov093
 *   BTL_SIDE_GetParty 0x021B985C thumb ov093
 *   BTL_MAIN_GetTrainerType 0x021BA020 thumb ov093
 *   BTL_CALC_IsBossTrainer 0x021D7F60 thumb ov093
 *   BTL_MAIN_GetFieldSituation 0x021B8714 thumb ov093
 *   BTL_CALC_GetMonParamWithHeap 0x021D805C thumb ov093
 *   BTL_MAIN_GetOpponentClient 0x021B9064 thumb ov093
 *   BTL_SIDE_WriteBackParty 0x021B969C thumb ov093
 *   BTL_MAIN_GetRelativeClientIndex 0x021BA710 thumb ov093
 *   BTL_MAIN_IsClientUsed 0x021B8B9C thumb ov093
 *   BTL_SIDE_GetSlotOfClient 0x021B9AEC thumb ov093
 *   BTL_SLOT_GetCount 0x021B9B94 thumb ov093
 *   BTL_SLOT_GetPoke 0x021B9BF0 thumb ov093
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   BTL_POKEPARAM_IsFainted 0x021D5B68 thumb ov093
 *   BTL_POKEPARAM_GetMajorStatusIndex 0x021D62A8 thumb ov093
 *   data_021EFCF0 0x021EFCF0 data ov093 a1
 *   _u32_div_f 0x0209C2B0 arm
 */
#include "../include/Obj00324.h"
#include "../include/Obj21005.h"
#include "../include/Obj21009.h"
#include "../include/Obj21010.h"
#include "../include/Obj21012.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void BTL_SIDE_WriteBackPartyOrdered(char *, char *, int);
extern int BTL_SIDE_GetParty(char *, int);
struct Unk021D62A8;
extern unsigned short BTL_MAIN_GetTrainerType(char *p, int i);
extern int BTL_CALC_IsBossTrainer(u32);
extern char *BTL_MAIN_GetFieldSituation(char **);
struct Rec534;
extern void NATSUKI_CalcParty(void *a0, int a1, int a2);
extern u32 POKEPARTY_GetCount(void *p);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern void POKE_TOOL_SetPartyValue(void *p, u32 id, u32 v);
struct Q1;
struct S2;
extern u32 BTL_CALC_GetMonParamWithHeap(void *p, u32 n);
extern void POKEPARTY_Copy(const struct Rec534 *src, struct Rec534 *dst);
extern u32 BTL_MAIN_GetOpponentClient(u8 *p, int k, int x);
extern void BTL_SIDE_WriteBackParty(char *, char *, int, int);
extern u8 BTL_MAIN_GetRelativeClientIndex(int, int);
extern int BTL_MAIN_IsClientUsed(u8 *, u8);
extern char *BTL_SIDE_GetSlotOfClient(char *, int);
extern u8 BTL_SLOT_GetCount(struct Q1 *p);
extern u32 BTL_SLOT_GetPoke(struct S2 *p, u32 i);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern int func_021D59B4(u8 *p, int k);
extern int BTL_POKEPARAM_IsFainted(void *);
extern int BTL_POKEPARAM_GetMajorStatusIndex(struct Unk021D62A8 *p);
extern const u8 data_021EFCF0[];
extern u32 _u32_div_f(u32, u32);
void BTL_MAIN_WriteBackResults(char *p)
{
    void *list;
    u32 n, move, k0, i0, k, slot;
    char *group;
    u32 count, total, maximum, i, base, j, obj;
    void *old, *mon;
    u8 *m;
    u32 tmp, tmp1, tmp2;
    if (((struct Obj21005 *)(*(char * *)&((struct Obj00324 *)p)->f0))->f23 != 0) return;
    if (*(u32 *)*(char * *)&((struct Obj00324 *)p)->f0 <= 1) {
        BTL_SIDE_WriteBackPartyOrdered(p + 0x1b0, p, (u8)p[0x46c]);
        list = (void *)BTL_SIDE_GetParty(p + 0x1b0, (u8)p[0x46c]);
        if (*(u32 *)*(char * *)&((struct Obj00324 *)p)->f0 == 1 && BTL_CALC_IsBossTrainer((u16)(u32)BTL_MAIN_GetTrainerType(p, 1)))
            NATSUKI_CalcParty(list, *(u16 *)(BTL_MAIN_GetFieldSituation((char **)p) + 10), (u16)((((struct Obj00324 *)p)->f468 & 0x7fff) | 0x8000));
        if (*(u32 *)*(char * *)&((struct Obj00324 *)p)->f0 == 1) {
            n = POKEPARTY_GetCount(list);
            for (i0 = 0; i0 < n; i0++) {
                old = POKEPARTY_GetMember(((struct Obj21009 *)(*(char * *)&((struct Obj00324 *)p)->f0))->f24, i0);
                mon = POKEPARTY_GetMember(list, i0);
                move = (u16)POKE_TOOL_GetPartyValue(old, 6, 0);
                if (!BTL_CALC_GetMonParamWithHeap((void *)move, 0x10))
                    POKE_TOOL_SetPartyValue(mon, 6, move);
                else if (move != POKE_TOOL_GetPartyValue(mon, 6, 0))
                    POKE_TOOL_SetPartyValue(mon, 6, 0);
            }
        }
        POKEPARTY_Copy(list, ((struct Obj21010 *)(*(char * *)&((struct Obj00324 *)p)->f0))->f24);
        for (i0 = 0; i0 < (u32)POKEPARTY_GetCount(list); i0++) POKEPARTY_GetMember(list, i0);
    }
    if (*(u32 *)*(char * *)&((struct Obj00324 *)p)->f0 == 0) {
        k0 = (u8)BTL_MAIN_GetOpponentClient((u8 *)p, (u8)p[0x46c], 0);
        BTL_SIDE_WriteBackParty(p + 0x1b0, p, k0, 1);
        POKEPARTY_Copy((void *)BTL_SIDE_GetParty(p + 0x1b0, k0), ((struct Obj21012 *)(*(char * *)&((struct Obj00324 *)p)->f0))->f28);
    }
    if (*(u32 *)*(char * *)&((struct Obj00324 *)p)->f0 == 4) return;
    for (k = 0; k < 4; k++) {
        slot = BTL_MAIN_GetRelativeClientIndex((u8)p[0x46c], (u8)k);
        for (j = 0; j < 6; j++) { obj = *(u32 *)&((struct Obj00324 *)p)->f0; tmp1 = slot * 6; *(u8 *)(j + (tmp1 + obj) + 0xc8) = 0; }
        if (BTL_MAIN_IsClientUsed((u8 *)p, (u8)slot)) {
            group = BTL_SIDE_GetSlotOfClient(p + 0xc8, slot);
            count = BTL_SLOT_GetCount((struct Q1 *)group);
            total = maximum = 0;
            base = data_021EFCF0[slot];
            for (j = 0; j < count; j++) {
                m = (u8 *)BTL_SLOT_GetPoke((struct S2 *)group, (u8)j);
                i = (u8)(BTL_POKEPARAM_GetPokeId(m) - base);
                total += func_021D59B4(m, 13);
                maximum += func_021D59B4(m, 14);
                if (BTL_POKEPARAM_IsFainted(m)) { obj = *(u32 *)&((struct Obj00324 *)p)->f0; tmp = slot * 6; *(u8 *)(i + (tmp + *(u32 *)&((struct Obj00324 *)p)->f0) + 0xc8) = 2; }
                else if (BTL_POKEPARAM_GetMajorStatusIndex((struct Unk021D62A8 *)m)) { obj = *(u32 *)&((struct Obj00324 *)p)->f0; tmp2 = slot * 6; *(u8 *)(i + (tmp2 + obj) + 0xc8) = 1; }
            }
            *(u32 *)(*(char * *)&((struct Obj00324 *)p)->f0 + slot * 4 + 0xe0) = _u32_div_f(total * 100, maximum);
        }
    }
}
