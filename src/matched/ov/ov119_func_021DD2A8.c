/*
 * function: POKETRADE_NEGO_CanConfirmOffers
 * address: 0x021DD2A8
 * packet: pkt_ov119_021DD2A8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAME_DATA_GetBoxManager 0x0201293C thumb
 *   GAME_DATA_GetMyParty 0x02012934 thumb
 *   POKEPARTY_GetCount 0x0201AA18 thumb
 *   func_02007984 0x02007984 thumb
 *   POKETRADE_NEGO_CountOwnOffers 0x021DD21C thumb ov119
 */
#include "../include/Obj13896.h"
struct BigObj;
extern unsigned int GAME_DATA_GetBoxManager(const struct BigObj *p);
typedef unsigned int   u32;
struct BigObj;
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern u32 POKEPARTY_GetCount(void *p);
extern int func_02007984(void *save);
extern int POKETRADE_NEGO_CountOwnOffers(char *p);
int POKETRADE_NEGO_CanConfirmOffers(char *p)
{
    int a, b, n;
    a = GAME_DATA_GetBoxManager((const struct BigObj *)(*(int *)&((struct Obj13896 *)p)->f82C));
    b = POKETRADE_NEGO_CountOwnOffers(p);
    n = POKEPARTY_GetCount(GAME_DATA_GetMyParty(((struct Obj13896 *)p)->f82C));
    n += func_02007984((void *)a);
    if (n == 2 && b >= 1) return 1;
    if (n > 2 && b >= 2) return 1;
    return 0;
}
