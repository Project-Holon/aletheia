/*
 * function: BTL_SIDE_WriteBackParty
 * address: 0x021B969C
 * packet: pkt_ov093_021B969C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT* (258 bytes, two trailing padding bytes)
 * symbols:
 *   BTL_SIDE_GetParty 0x021B985C thumb ov093
 *   BTL_SIDE_GetSlotOfClient 0x021B9AEC thumb ov093
 *   POKEPARTY_GetCount 0x0201AA18 thumb
 *   POKEPARTY_Init 0x0201A948 thumb
 *   BTL_SLOT_GetPoke 0x021B9BF0 thumb ov093
 *   BTL_POKEPARAM_WriteBackToParam 0x021D6B84 thumb ov093
 *   BTL_POKEPARAM_GetMon 0x021D5844 thumb ov093
 *   POKEPARTY_Add 0x0201A98C thumb
 *   BTL_POKEPARAM_IsIllusionActive 0x021D6C24 thumb ov093
 *   BTL_POKEPARAM_GetDisplayMon 0x021D5864 thumb ov093
 *   POKEPARTY_Copy 0x0201AC2C thumb
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 *   BTL_POKEPARAM_SetPokeParam 0x021D6C3C thumb ov093
 *   BTL_POKEPARAM_SetFakeMon 0x021D5848 thumb ov093
 */
#include "../include/Obj09940.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int BTL_SIDE_GetParty(char *p, int i);
extern char *BTL_SIDE_GetSlotOfClient(char *, int);
struct Party;
struct PartyMon;
struct QH;
struct R4;
struct Rec534;
struct Work;
extern u32 POKEPARTY_GetCount(void *p);
extern void POKEPARTY_Init(struct Party *p);
struct S2;
extern u32 BTL_SLOT_GetPoke(struct S2 *p, u32 i);
extern void BTL_POKEPARAM_WriteBackToParam(void *, int);
extern void *BTL_POKEPARAM_GetMon(void *);
extern u32 POKEPARTY_Add(struct Party *p, const struct PartyMon *src);
extern int BTL_POKEPARAM_IsIllusionActive(struct R4 *p);
extern void *BTL_POKEPARAM_GetDisplayMon(struct Work *p);
extern void POKEPARTY_Copy(const struct Rec534 *src, struct Rec534 *dst);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern void BTL_POKEPARAM_SetPokeParam(void **p, void *q);
extern void BTL_POKEPARAM_SetFakeMon(struct QH *p, void *v);
void BTL_SIDE_WriteBackParty(char *a, char *b, int k, int flag)
{
    void *list;
    char *g;
    u32 n, i, j;
    void *m, *e;
    void *h;
    u8 links[6];
    list = (void *)BTL_SIDE_GetParty(a, k);
    g = BTL_SIDE_GetSlotOfClient(a, k);
    n = POKEPARTY_GetCount(list);
    POKEPARTY_Init(((struct Obj09940 *)b)->f2B8);
    for (i = 0; i < 6; i++) links[i] = 6;
    for (i = 0; i < n; i++) {
        m = (void *)BTL_SLOT_GetPoke((struct S2 *)g, (u8)i);
        BTL_POKEPARAM_WriteBackToParam(m, flag);
        POKEPARTY_Add(((struct Obj09940 *)b)->f2B8, BTL_POKEPARAM_GetMon(m));
        if (BTL_POKEPARAM_IsIllusionActive(m)) {
            h = BTL_POKEPARAM_GetDisplayMon(m);
            for (j = 0; j < n; j++) {
                if (h == BTL_POKEPARAM_GetMon((void *)BTL_SLOT_GetPoke((struct S2 *)g, (u8)j))) {
                    links[i] = j;
                    break;
                }
            }
        }
    }
    POKEPARTY_Copy(((struct Obj09940 *)b)->f2B8, list);
    for (i = 0; i < n; i++) {
        e = POKEPARTY_GetMember(list, i);
        m = (void *)BTL_SLOT_GetPoke((struct S2 *)g, (u8)i);
        BTL_POKEPARAM_SetPokeParam(m, e);
        if (links[i] != 6)
            BTL_POKEPARAM_SetFakeMon(m, POKEPARTY_GetMember(list, links[i]));
    }
}
