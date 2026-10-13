/*
 * function: SCRCMD_NETWORK_InitCommBattleOv181Param
 * address:  0x0215F920
 * packet:   pkt_0215F920
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * blocked:  listing 40 compiled 38
 *
 * symbols:
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_0200873C  0x0200873C  thumb
 *   CONFIG_GetAppliedFlag  0x020083E4  thumb
 */
#include "../include/Obj05853.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Big;
struct Sub02008700Obj;

extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern int CONFIG_GetAppliedFlag(unsigned short *p);

int SCRCMD_NETWORK_InitCommBattleOv181Param(int a0)
{
    int t4;
    void *big;
    struct Sub02008700Obj *obj;

t4 = a0 + 0;
a0 = ((struct Obj05853 *)t4)->f8;
    if (a0 != 1) goto loc_0215F92E;
loc_0215F92A:
a0 = 1;
    goto loc_0215F930;
loc_0215F92E:
a0 = 0;
loc_0215F930:
((struct Obj05853 *)t4)->f28 = a0;
a0 = ((struct Obj05853 *)t4)->f4;
    big = GAME_DATA_GetSaveControl((struct Big *)a0);
loc_0215F938:
    obj = func_0200873C(big);
loc_0215F93C:
    a0 = CONFIG_GetAppliedFlag((short unsigned int *)obj);
loc_0215F940:
((struct Obj05853 *)t4)->f2C = a0;
((struct Obj05853 *)t4)->f30 = a0;
    return a0;}
