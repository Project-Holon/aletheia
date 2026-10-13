/*
 * function: FIELD_CLOCK_GetTimeZone
 * address:  0x021690B4
 * packet:   pkt_021690B4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_02008B14  0x02008B14  thumb
 *   GAME_DATA_GetSeason  0x02012984  thumb
 *   TIMEZONE_GetTimeZoneOfHour  0x020113F0  thumb
 */
#include "../include/Obj17735.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Big;
struct Sub02008AECSession;

extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern struct Sub02008AECSession *func_02008B14(void *sys);
struct BigObj;
extern u8 GAME_DATA_GetSeason(const struct BigObj *p);
extern int TIMEZONE_GetTimeZoneOfHour(int row, int col);

int FIELD_CLOCK_GetTimeZone(int a0)
{
    int a1;
    struct Sub02008AECSession *t4;
    void *big;
    int t5;

t5 = a0 + 0;
    big = GAME_DATA_GetSaveControl((struct Big *)a0);
loc_021690BC:
    t4 = func_02008B14(big);
loc_021690C0:
a0 = t5 + 0;
    a0 = GAME_DATA_GetSeason((const struct BigObj *)a0);
loc_021690C8:
a1 = ((struct Obj17735 *)t4)->f14;
    a0 = TIMEZONE_GetTimeZoneOfHour(a0, a1);
loc_021690CE:
    return a0;}
