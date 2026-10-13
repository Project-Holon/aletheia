/*
 * function: func_021E57E0
 * address:  0x021E57E0
 * packet:   pkt_021E57E0
 * region:   ov178
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAME_DATA_GetSaveControl   0x02012EBC  thumb
 *   GAME_DATA_GetMyStatus   0x02012944  thumb
 *   ZUKAN_SAVE_GetFromGameData   0x0200CA1C  thumb
 *   func_0200873C   0x0200873C  thumb
 *   POKEPARTY_GetCount   0x0201AA18  thumb
 *   ZUKAN_SAVE_IsNationalDexEnabled   0x0200CA38  thumb
 *
 * Populate the 0x28-byte record from the two source objects.
 */
#include "../include/Obj01763.h"


typedef unsigned int   u32;
typedef unsigned char  u8;
struct Big;
struct Blk37;
struct Sub02008700Obj;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern void *ZUKAN_SAVE_GetFromGameData(void *a);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern unsigned int POKEPARTY_GetCount(void *p);
extern u32 ZUKAN_SAVE_IsNationalDexEnabled(struct Blk37 *p);

void func_021E57E0(int *r5, int *r6, char *r4)
{
    int a;
    int b;
    a = (int)GAME_DATA_GetSaveControl((struct Big *)r5[5]);
    GAME_DATA_GetMyStatus((void *)r5[5]);
    b = (int)ZUKAN_SAVE_GetFromGameData((void *)r5[5]);
    ((struct Obj01763 *)r4)->f0 = r6[1];
    ((struct Obj01763 *)r4)->f8 = r5[5];
    ((struct Obj01763 *)r4)->f4 = (int)func_0200873C((void *)a);
    ((struct Obj01763 *)r4)->fC = 1;
    ((struct Obj01763 *)r4)->fD = 1;
    ((struct Obj01763 *)r4)->fE = POKEPARTY_GetCount((void *)r6[1]);
    ((struct Obj01763 *)r4)->fF = 0;
    ((struct Obj01763 *)r4)->f10 = 0;
    ((struct Obj01763 *)r4)->f11 = 0;
    ((struct Obj01763 *)r4)->f12 = 0;
    ((struct Obj01763 *)r4)->f14 = 0;
    ((struct Obj01763 *)r4)->f18 = ZUKAN_SAVE_IsNationalDexEnabled((struct Blk37 *)b);
    ((struct Obj01763 *)r4)->f20 = 0;
    ((struct Obj01763 *)r4)->f24 = 0;
}
