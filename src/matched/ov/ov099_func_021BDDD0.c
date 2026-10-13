/*
 * function: func_021BDDD0
 * address: 0x021BDDD0
 * packet: pkt_ov099_021BDDD0
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAME_DATA_GetBoxManager 0x0201293C thumb
 *   GAME_DATA_GetMyParty 0x02012934 thumb
 *   POKEPARTY_GetNonEggCount 0x0201AA1C thumb
 */
#include "../include/Obj13698.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct BigObj;
extern u32 GAME_DATA_GetBoxManager(const struct BigObj *p);
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern u32 POKEPARTY_GetNonEggCount(void *);
int func_021BDDD0(char *p)
{
    GAME_DATA_GetBoxManager(((struct Obj13698 *)p)->fC4);
    if ((int)POKEPARTY_GetNonEggCount(GAME_DATA_GetMyParty(((struct Obj13698 *)p)->fC4)) >= 2) return 1;
    return 0;
}
