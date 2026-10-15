/*
 * function: BR_PROC_SYS_BuildProfileRecord2
 * address:  0x021F966C
 * packet:   pkt_021F966C
 * region:   ov186
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Blocker: every concrete byte reproduces; 0x0200E9F4 and 0x0200EA04 are
 *   unlabelled Thumb leaves with no branch anywhere outside this range, so
 *   the two calls stay wildcarded.
 *
 * symbols:
 *   GAME_DATA_GetSaveControl   0x02012EBC  thumb
 *   BR_GRAPHIC_GetActorUnit   0x021FC4DC  thumb
 *   MISC_SAVEDATA_GetBlock3C   0x0200E9F4  thumb
 *   MISC_SAVEDATA_GetStatsBase2   0x0200EA04  thumb
 *
 * Fill the output record from the source object and its nested handle.
 */
#include "../include/Obj05494.h"
#include "../include/Obj05495.h"


typedef unsigned int   u32;
typedef unsigned char  u8;
struct Big;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern u32 BR_GRAPHIC_GetActorUnit(u8 *p);
extern void *MISC_SAVEDATA_GetBlock3C(void *p);
extern int MISC_SAVEDATA_GetStatsBase2(int);

void BR_PROC_SYS_BuildProfileRecord2(char *r5, int *r4)
{
    int x;
    x = (int)GAME_DATA_GetSaveControl((struct Big *)(*(int *)(*(int *)(((struct Obj05495 *)r4)->f18 + 0xC) + 4)));
    ((struct Obj05494 *)r5)->f8 = r4[1];
    ((struct Obj05494 *)r5)->f4 = r4[3];
    ((struct Obj05494 *)r5)->fC = r4[2];
    ((struct Obj05494 *)r5)->f0 = BR_GRAPHIC_GetActorUnit((u8 *)r4[0]);
    ((struct Obj05494 *)r5)->f10 = *(int *)(*(int *)(((struct Obj05495 *)r4)->f18 + 0xC) + 4);
    ((struct Obj05494 *)r5)->f14 = MISC_SAVEDATA_GetStatsBase2((int)MISC_SAVEDATA_GetBlock3C((void *)x));
}
