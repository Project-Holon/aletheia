/*
 * function: WIFICLUB_StateOpenPartyMenu
 * address:  0x021BD15C
 * packet:   pkt_ov099_021BD15C
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFICLUB_UpdateTalkStream  0x021BA928  thumb  ov099
 *   WIFICLUB_CreateRuleChoiceMenu  0x021BBE7C  thumb  ov099
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   WIFICLUB_LoadPartyIcons  0x021BBD0C  thumb  ov099
 */
#include "../include/Obj07946.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;

extern int WIFICLUB_UpdateTalkStream(char *p, int v);
extern void WIFICLUB_CreateRuleChoiceMenu(char *p);
struct BigObj;
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern void WIFICLUB_LoadPartyIcons(char *p, int a, int b);

int WIFICLUB_StateOpenPartyMenu(char *p, int v)
{
    if (WIFICLUB_UpdateTalkStream(p, v) == 0) {
        return v;
    }
    ((struct Obj07946 *)p)->f1354 = 2;
    WIFICLUB_CreateRuleChoiceMenu(p);
    WIFICLUB_LoadPartyIcons(p, (int)GAME_DATA_GetMyParty(((struct Obj07946 *)p)->fC4), ((struct Obj07946 *)p)->fCC);
    ((struct Obj07946 *)p)->f1CC = 0x66;
    return v;
}
