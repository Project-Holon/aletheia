/*
 * function: FIELD_GIMMICK_BSUBWAY_Update
 * address:  0x021F3724
 * packet:   pkt_ov052_021F3724
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

void FIELD_GIMMICK_BSUBWAY_Update(void *a)
{
    int s1;
    int s0;
    unsigned h;
    unsigned short *p;
    void (*f)(void *, void *);

    FIELDMAP_GetHeapId(a);
    h = (unsigned int)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(a)));
    FIELD_GIMMICK_BSUBWAY_FindZoneEntry(FIELDMAP_GetZoneId(a), &s0, &s1);
    p = (short unsigned int *)GIMMICK_WORK_GetSaveArea((struct Rec94 *)h, s0);
    f = sFieldGimmickBsubwayZoneHandlers[p[1]].f1;
    if (f)
        f(p, a);
}
