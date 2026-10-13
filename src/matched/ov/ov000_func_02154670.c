/*
 * function: EVENT_GSYNC_Create
 * address:  0x02154670
 * packet:   pkt_02154670
 * region:   ov000
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Straight-line constructor wrapper over the ARM9 object/service helpers.
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   EVENT_GSYNC_Main  0x021542C0  thumb  ov000
 */
#include "../include/Obj04140.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Desc;
struct Obj;
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
struct Big;
struct Ctx;
void *GAMESYSTEM_GetGameData(const struct Ctx *p);
void *GAME_DATA_GetSaveControl(struct Big *p);
u32 EVENT_GSYNC_Main(void *obj, u32 *mode, char *args);

void *EVENT_GSYNC_Create(void *p)
{
    void *r7;
    char *r4;
    int q;

    r7 = (void *)func_020122C0(p, 0, EVENT_GSYNC_Main, 0x2CC);
    r4 = func_020124E8(r7);
    q = (int)GAMESYSTEM_GetGameData(p);
    ((struct Obj04140 *)r4)->f4 = q;
    ((struct Obj04140 *)r4)->f8 = (int)GAME_DATA_GetSaveControl((struct Big *)q);
    ((struct Obj04140 *)r4)->f0 = p;
    ((struct Obj04140 *)r4)->f258 = (int)GAMESYSTEM_GetGameData(p);
    ((struct Obj04140 *)r4)->f25C = 1;
    ((struct Obj04140 *)r4)->f260 = 0;
    ((struct Obj04140 *)r4)->f264 = 0x31;
    return r7;
}
