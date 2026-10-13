/*
 * function: FIELD_GIMMICK_BSUBWAY_Init
 * address:  0x021F36C0
 * packet:   pkt_ov052_021F36C0
 * region:   ov052
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   FIELD_GIMMICK_BSUBWAY_FindZoneEntry  0x021F3998  thumb  ov052
 *   GIMMICK_WORK_GetSaveArea  0x0200B3A4  thumb
 *   sFieldGimmickBsubwayZoneHandlers     0x021F3A2C  data  a4
 */
#include "../include/Obj05135.h"
#include "../include/G_021F3A2C.h"

typedef unsigned short u16;
typedef unsigned char  u8;
extern u16 FIELDMAP_GetHeapId(u8 *p);
struct Big;
struct Ctx;
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
extern u16 FIELDMAP_GetZoneId(u8 *p);
extern void FIELD_GIMMICK_BSUBWAY_FindZoneEntry(int, int *, int *);
typedef signed int     s32;
typedef unsigned int   u32;
struct Rec94;
extern s32 *GIMMICK_WORK_GetSaveArea(struct Rec94 *p, u32 b);
extern struct G_021F3A2C sFieldGimmickBsubwayZoneHandlers[];

void FIELD_GIMMICK_BSUBWAY_Init(void *a)
{
    int s1;
    int s0;
    int r4;
    int r6;
    int r7;
    unsigned h;
    char *p;
    void (*f)(void *, void *);

    r4 = FIELDMAP_GetHeapId(a);
    r6 = (int)FIELDMAP_GetGameSystem(a);
    h = (unsigned int)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData((const struct Ctx *)r6));
    r7 = FIELDMAP_GetZoneId(a);
    FIELD_GIMMICK_BSUBWAY_FindZoneEntry(r7, &s0, &s1);
    p = (char *)GIMMICK_WORK_GetSaveArea((struct Rec94 *)h, s0);
    ((struct Obj05135 *)p)->f2 = s1;
    ((struct Obj05135 *)p)->f4 = s0;
    ((struct Obj05135 *)p)->f8 = r7;
    ((struct Obj05135 *)p)->fC = r4;
    ((struct Obj05135 *)p)->f1C = r6;
    ((struct Obj05135 *)p)->f20 = a;
    f = sFieldGimmickBsubwayZoneHandlers[*(unsigned short *)(p + 2)].f0;
    if (f)
        f(p, a);
}
