/*
 * function: GIMMICK38_StartDoorEvent
 * address:  0x021F3A88
 * packet:   pkt_ov038_021F3A88
 * region:   ov038
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetFieldMap 0x0201210C thumb
 *   FIELDMAP_GetCommonWork 0x021897BC thumb
 *   FIELDMAP_GetFieldPlayer 0x02188CB4 thumb
 *   FIELDMAP_GetGameSystem 0x02188C80 thumb
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetFieldSave 0x02012EC4 thumb
 *   GIMMICK_WORK_GetSaveArea 0x0200B3A4 thumb
 *   FIELD_PLAYER_GetDirDisp 0x021A3050 thumb ov021
 *   GIMMICK38_FindDoor 0x021F3A08 thumb ov038
 *   func_020122C0 0x020122C0 thumb
 *   GIMMICK38_EventSlideDoor 0x021F3B3C thumb ov038
 *   GIMMICK38_EventBumpClosedDoor 0x021F407C thumb ov038
 *   GIMMICK38_EventBumpDoorSide 0x021F3F40 thumb ov038
 */
#include "../include/Obj04317.h"

struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern unsigned char *FIELDMAP_GetCommonWork(void *, int);
extern void *FIELDMAP_GetFieldPlayer(unsigned char *p);
extern int FIELDMAP_GetGameSystem(void *);
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Big;
struct Desc;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
typedef signed int     s32;
struct Rec94;
extern s32 *GIMMICK_WORK_GetSaveArea(struct Rec94 *p, u32 b);
extern u16 FIELD_PLAYER_GetDirDisp(u8 *p);
extern int GIMMICK38_FindDoor(int *, int, int, int *, int *);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern int GIMMICK38_EventSlideDoor(int a0, int *a1);
extern int GIMMICK38_EventBumpClosedDoor(int a0, int *a1);
extern int GIMMICK38_EventBumpDoorSide(int a0, int *a1);

int GIMMICK38_StartDoorEvent(int a0, int a1, int a2)
{
    int o1;
    int o2;
    int r6; /* int-typed on purpose: pointer local changes codegen */
    int r7;
    unsigned char *r4;

    r6 = (int)GAMESYSTEM_GetFieldMap((void *)a0);
    r4 = FIELDMAP_GetCommonWork((void *)r6, 1);
    r6 = (int)FIELDMAP_GetFieldPlayer((void *)r6);
    r7 = (int)GIMMICK_WORK_GetSaveArea((struct Rec94 *)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData((const struct Ctx *)FIELDMAP_GetGameSystem(GAMESYSTEM_GetFieldMap((void *)a0)))), 6);
    r6 = FIELD_PLAYER_GetDirDisp((u8 *)r6);
    if (r6 != 0 && r6 != 1)
        return 0;
    r7 = GIMMICK38_FindDoor((int *)r7, a1, a2, &o1, &o2);
    if (r7 < 7) {
        if (o2 != 0) {
            if (o1 == 1)
                func_020122C0((void *)a0, 0, GIMMICK38_EventSlideDoor, 0);
            else
                func_020122C0((void *)a0, 0, GIMMICK38_EventBumpClosedDoor, 0);
        } else {
            func_020122C0((void *)a0, 0, GIMMICK38_EventBumpDoorSide, 0);
        }
    } else {
        return 0;
    }
    r4[5] = 0;
    r4[7] = 0;
    r4[6] = r6;
    r4[3] = r7;
    ((struct Obj04317 *)r4)->f14 = 0;
    ((struct Obj04317 *)r4)->f18 = 0;
    ((struct Obj04317 *)r4)->f1C = 0;
}
