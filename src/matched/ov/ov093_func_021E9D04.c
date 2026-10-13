/*
 * function: BTLV_CORE_StartBagMenu
 * address: 0x021E9D04
 * packet: pkt_ov093_021E9D04
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_MAIN_GetMyItem 0x021B90E8 thumb ov093
 *   BTL_MAIN_GetMapMatrix 0x021B90F0 thumb ov093
 *   func_021E9E60 0x021E9E60 thumb ov093
 *   BTL_MAIN_GetRegulationRules 0x021BA1E4 thumb ov093
 *   BTL_MAIN_GetCompetitor 0x021B86B8 thumb ov093
 *   BTL_MAIN_CheckSetupStatusFlag 0x021BA1A8 thumb ov093
 *   BTL_SIDE_CountLivingOfClient 0x021B9B04 thumb ov093
 *   BTLV_CORE_InitPartyWork 0x021E9984 thumb ov093
 *   BTL_CLIENT_GetSideData 0x021D3D7C thumb ov093
 *   BTL_SLOT_GetCount 0x021B9B94 thumb ov093
 *   BTL_SLOT_GetPokeParam 0x021B9C00 thumb ov093
 *   BTL_POKEPARAM_HasSick 0x021D62C4 thumb ov093
 */
#include "../include/Obj00056.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 BTL_MAIN_GetMyItem(void **p);
extern u32 BTL_MAIN_GetMapMatrix(void **p);
extern int func_021E9E60(void *);
extern char *BTL_MAIN_GetRegulationRules(char **);
extern void *BTL_MAIN_GetCompetitor(void ***);
struct Q1;
struct S2;
extern int BTL_MAIN_CheckSetupStatusFlag(char **p, int m);
extern unsigned char BTL_SIDE_CountLivingOfClient(int a, int b);
extern void BTLV_CORE_InitPartyWork(u8 *, u8 *, int, u8, int);
extern u32 BTL_CLIENT_GetSideData(u8 *p);
extern u8 BTL_SLOT_GetCount(struct Q1 *p);
extern u8 *BTL_SLOT_GetPokeParam(struct S2 *p, u32 i);
struct Unk021D62A8;
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);

void BTLV_CORE_StartBagMenu(u8 *p, int x, u8 a, u8 b, u8 c, u8 d)
{
    u32 i;
    u32 n;
    void *list;
    int flag;
    if (p[0x174]) return;
    ((struct Obj00056 *)p)->fC8 = (void *)BTL_MAIN_GetMyItem(((struct Obj00056 *)p)->f0);
    ((struct Obj00056 *)p)->fE4 = (void *)BTL_MAIN_GetMapMatrix(((struct Obj00056 *)p)->f0);
    ((struct Obj00056 *)p)->fD0 = x;
    ((struct Obj00056 *)p)->fCC = ((struct Obj00056 *)p)->fB0;
    ((struct Obj00056 *)p)->fD4 = ((struct Obj00056 *)p)->f184;
    p[0xdc] = a;
    p[0xdd] = b;
    ((struct Obj00056 *)p)->fDE = 0;
    ((struct Obj00056 *)p)->fF4 = func_021E9E60(((struct Obj00056 *)p)->f180);
    ((struct Obj00056 *)p)->fE8 = 0;
    *(char * *)&((struct Obj00056 *)p)->fD8 = BTL_MAIN_GetRegulationRules(*(char ** *)&((struct Obj00056 *)p)->f0);
    flag = 0;
    if ((int)BTL_MAIN_GetCompetitor(*(void *** *)&((struct Obj00056 *)p)->f0) != 3) flag = 1;
    ((struct Obj00056 *)p)->f108 = flag;
    ((struct Obj00056 *)p)->fEC = 0;
    flag = 0;
    if (BTL_MAIN_GetCompetitor(*(void *** *)&((struct Obj00056 *)p)->f0) == 0) flag = 1;
    p[0xf1] = flag;
    p[0xe1] = 0;
    flag = 0;
    if (c == 0) flag = 3;
    else if (BTL_MAIN_CheckSetupStatusFlag(((struct Obj00056 *)p)->f0, 0x40)) flag = 1;
    else if (BTL_MAIN_GetCompetitor(*(void *** *)&((struct Obj00056 *)p)->f0) == 0) {
        if (BTL_SIDE_CountLivingOfClient(((struct Obj00056 *)p)->f8, 1) > 1) flag = 2;
        else if (d) flag = 4;
    }
    p[0xf0] = flag;
    BTLV_CORE_InitPartyWork(p, p + 0x10c, 3, 0, 0);
    list = (void *)BTL_CLIENT_GetSideData(((struct Obj00056 *)p)->f4);
    n = BTL_SLOT_GetCount(list);
    for (i = 0; i < n; i++)
        p[0x144 + i] = BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)BTL_SLOT_GetPokeParam(list, (u8)i), 0x13);
    for (; i < 6; i++) p[0x144 + i] = 0;
    p[0x174] = 1;
}
