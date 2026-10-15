/*
 * function: TRIAL_HOUSE_CreateWork
 * address:  0x021D096C
 * packet:   pkt_ov021_021D096C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Callee witnesses filed in wave A1 (witness lane).
 *
 * symbols:
 *   BATTLE_EXAMINATION_GetBlockSize  0x0200E588  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_02030734  0x02030734  arm
 *   POKEPARTY_Create  0x0201A920  thumb
 *   TRIAL_HOUSE_LoadDeliveryState  0x021D09D0  thumb  ov021
 *   d_021DE674     0x021DE674  data  a4
 */
#include "../include/Obj07595.h"

typedef unsigned short u16;

extern int d_021DE674;

typedef unsigned int   u32;
extern u32 BATTLE_EXAMINATION_GetBlockSize(void);
struct Big;
struct Ctx;
struct Party;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *func_02030734(u32 heap, u32 size, int clear, const char *site, u16 tag);
extern struct Party *POKEPARTY_Create(u32 heap);
extern void TRIAL_HOUSE_LoadDeliveryState(int a, char *out);

void *TRIAL_HOUSE_CreateWork(int a)
{
    char *p;
    int r7;

    r7 = BATTLE_EXAMINATION_GetBlockSize();
    GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData((const struct Ctx *)a));
    p = func_02030734(5, 0x154, 1, (const char *)&d_021DE674, 0x5D);
    ((struct Obj07595 *)p)->f120 = 5;
    ((struct Obj07595 *)p)->f14C = (int)func_02030734(5, r7, 1, (const char *)&d_021DE674, 0x5F);
    TRIAL_HOUSE_LoadDeliveryState(a, p);
    ((struct Obj07595 *)p)->f128 = (int)POKEPARTY_Create(((struct Obj07595 *)p)->f120);
    return p;
}
