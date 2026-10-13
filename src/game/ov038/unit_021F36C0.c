/*
 * file:     unit_021F36C0.c
 * unit:     yes
 * function: func_021F36C0, func_021F39B4, func_021F39D8, func_021F3A08, func_021F3A88, func_021F3B3C, func_021F3DFC, func_021F3F40, func_021F407C, func_021F4184, func_021F41B0, func_021F41DC, func_021F4200, func_021F42BC
 * address:  0x021F36C0
 * region:   ov038
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021F464C     0x021F464C  data  a4
 *   d_021F46E8     0x021F46E8  data  a4
 *   d_021F4748     0x021F4748  data  a4
 *   d_021F4694     0x021F4694  data  a4
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 *   GFL_HEAP_GetTotalFreeSize  0x02030344  arm
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02189764  0x02189764  thumb  ov021
 *   func_021BE760  0x021BE760  thumb  ov021
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021BE4A4  0x021BE4A4  thumb  ov021
 *   func_021BE4B4  0x021BE4B4  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B8  0x021BE6B8  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_021BE6CC  0x021BE6CC  thumb  ov021
 *   func_021BE748  0x021BE748  thumb  ov021
 *   func_021897BC 0x021897BC thumb ov021
 *   func_021897A0 0x021897A0 thumb ov021
 *   func_021BE418 0x021BE418 thumb ov021
 *   func_021BE580 0x021BE580 thumb ov021
 *   func_0201210C 0x0201210C thumb
 *   func_02188CB4 0x02188CB4 thumb
 *   func_021A3050 0x021A3050 thumb ov021
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E4  0x020124E4  thumb
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_0203630C  0x0203630C  arm
 *   func_021A3044  0x021A3044  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_0201235C  0x0201235C  thumb
 *   func_02197DA0  0x02197DA0  thumb  ov021
 *   func_02197DAC  0x02197DAC  thumb  ov021
 *   func_021618A0  0x021618A0  thumb  ov010
 *   func_02012374  0x02012374  thumb
 *   GFL_USE_StopAllSe  0x02006210  thumb
 *   func_021BE6E8  0x021BE6E8  thumb  ov021
 *   func_021BE6BC  0x021BE6BC  thumb  ov021
 *   func_02197D3C  0x02197D3C  thumb  ov021
 *   d_021F45F8     0x021F45F8  data  a4
 *   d_021F4600     0x021F4600  data  a4
 *   d_021F4608     0x021F4608  data  a4
 *   d_021F4620     0x021F4620  data  a4
 *   func_021F44C0 0x021F44C0 thumb ov038
 *   func_0200B3A8 0x0200B3A8 thumb
 *   d_021F4628    0x021F4628 data a1
 *   d_021F4632    0x021F4632 data a1
 */
#include "../ov037/unit_021F36C0_types.h"
#include "unit_021F36C0_types.h"

struct GameSystem;
struct GameData;
struct GimmickWork;
struct GameEvent;
struct FieldMap;
typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int     s32;

typedef unsigned char  u8;

typedef signed char s8;

extern int func_02188D2C(int *fieldMap);
extern void *func_02188C80(void *fieldMap);
extern void *func_020120F4(const struct GameSystem *gameSystem);
extern struct GimmickWork *func_02012EC4(struct GameData *gameData);
extern void *func_0200B3A4(struct GimmickWork *gimmickSave, u32 gimmickId);
extern void *GFL_HEAP_GetTotalFreeSize(u32 heapId);
extern u16 func_02188C84(u8 *fieldMap);
extern void *func_02189764(unsigned char *fieldMap, int id, int heapId, int size);
extern void  func_021BE760(void *expObj, void *unitDef, int unitIdx);
extern VecFx32 *func_021BE480(void *expObj, int unitIdx, u16 modelIdx);
extern void func_021BE4A4(char *expObj, int unitIdx, int modelIdx, int cullDraw);
extern void func_021BE4B4(void *expObj, int unitIdx, u16 modelIdx, int hidden);
extern void *func_021BE674(void *expObj, int unitIdx, u16 modelIdx, u16 animeIdx);
extern void func_021BE6B8(unsigned char *anime, int loop);
extern void func_021BE6B0(unsigned char *anime, int paused);
extern void func_021BE700(void *expObj, int unitIdx, u16 modelIdx, u16 animeIdx, int enable);
extern void func_021BE6CC(void *expObj, int unitIdx, u16 modelIdx, u16 animeIdx, int frame);
extern int func_021BE748(u32 anime);
extern struct Gimmick38Runtime *func_021897BC(char *fieldMap, int idx);
extern void func_021897A0(unsigned char *fieldMap, int id);
extern void func_021BE418(unsigned char *expObj, u16 unitIdx);
extern void func_021BE580(void *expObj);
extern void *func_0201210C(const struct GameSystem *gameSystem);
extern void *func_02188CB4(struct FieldMap *fieldMap);
extern u16 func_021A3050(u8 *fieldPlayer);
extern struct GameEvent *func_020122C0(void *owner, void *work, void *run, u32 size);
extern void *func_020124E4(struct GameEvent *event);
extern void *func_021A3074(unsigned char *fieldPlayer);
extern int func_0216D454(void *mmdl);
extern int func_0216D3CC(int mmdl);
extern void func_021A3038(unsigned char *fieldPlayer, VecFx32 *out);
extern void func_021A3044(u8 *fieldPlayer, VecFx32 *pos);
extern int func_021BE6BC(int *anime);
extern int func_021BE6E8(int expObj, int unitIdx, int modelIdx, int animeIdx);
extern unsigned int func_0203630C(void);
extern void func_020061E4(u32 se);
extern void GFL_USE_StopAllSe(void);
extern void func_0201235C(struct GameEvent *event, u32 *newEvent);
extern void func_02012374(struct GameEvent *event, struct GameEvent **out);
extern void *func_021618A0(void *gameSystem, int fieldMap, int arg, int acmdTable);
extern int func_02197DA0(u32 acmdList);
extern void func_02197DAC(void *acmdList);
extern int func_02197D3C(void *mmdl, void *acmdTable);
extern int func_021F44C0(void *, int *);
extern u16 *func_0200B3A8(struct GimmickWork *gimmickSave, u32 gimmickId);
void func_021F36C0(void *fieldMap);
void func_021F39B4(void *fieldMap);
void func_021F39D8(void *fieldMap);
int func_021F3A08(Gimmick38Work *work, int cellX, int cellZ, int *doorOpen, int *exactCell);
int func_021F3A88(int gameSystem, int cellX, int cellZ);
int func_021F3B3C(int event, int *state);
int func_021F3DFC(int event, int *state);
int func_021F3F40(int event, int *state);
int func_021F407C(int event, int *state);
void *func_021F4184(void *gameSystem, int switchIdx);
void *func_021F41B0(void *gameSystem, int plateIdx);
void *func_021F41DC(void *gameSystem, int variant);
int func_021F4200(int event, int *state);
int func_021F42BC(int event, int *state);
extern int d_021F464C;
extern VecFx32 d_021F46E8[];
extern VecFx32 d_021F4748[];
extern VecFx32 d_021F4694[];
extern u32 d_021F45F8[];
extern u32 d_021F4600[];
extern u32 d_021F4608[];
extern u32 d_021F4620[];
extern const s8 d_021F4628[];
extern const u8 d_021F4632[];




/*
 * Init: places the eight switches, ten plates and seven doors, and sets the
 * look of each from the saved state.
 */
void func_021F36C0(void *fieldMap)
{
    void *expObj;
    int i;
    Gimmick38Work *save;
    int doorIdx;
    int j;
    int plateModel;
    int closedModel;
    int openModel;
    void *anime;
    VecFx32 *status;
    VecFx32 pos;

    expObj = (void *)func_02188D2C(fieldMap);
    save = func_0200B3A4(func_02012EC4((struct GameData *)func_020120F4(func_02188C80(fieldMap))), 6);
    GFL_HEAP_GetTotalFreeSize(0x15);
    func_02189764(fieldMap, 1, func_02188C84(fieldMap), 0x24);
    func_021BE760(expObj, &d_021F464C, 0);
    GFL_HEAP_GetTotalFreeSize(0x15);
    for (i = 0; i < 8; i++) {
        status = func_021BE480(expObj, 0, i);
        *status = d_021F46E8[i];
        func_021BE4A4(expObj, 0, (u16)i, 1);
        for (j = 0; j < 2; j++) {
            anime = func_021BE674(expObj, 0, i, j);
            func_021BE6B8(anime, 0);
            func_021BE700(expObj, 0, i, j, 1);
            func_021BE6B0(anime, 1);
            if (save->switchFound[i] != 0)
                func_021BE6CC(expObj, 0, i, j, func_021BE748((u32)anime));
        }
    }
    for (i = 0; i < 10; i++) {
        plateModel = i + 8;
        status = func_021BE480(expObj, 0, plateModel);
        *status = d_021F4748[i];
        func_021BE4A4(expObj, 0, (u16)plateModel, 1);
        for (j = 0; j < 2; j++) {
            anime = func_021BE674(expObj, 0, plateModel, j);
            func_021BE6B8(anime, 0);
            func_021BE700(expObj, 0, plateModel, j, 1);
            func_021BE6B0(anime, 1);
            if (save->platePressed[i] != 0)
                func_021BE6CC(expObj, 0, plateModel, j, func_021BE748((u32)anime));
        }
    }
    for (doorIdx = 0; doorIdx < 7; doorIdx++) {
        closedModel = doorIdx + 0x12;
        openModel = doorIdx + 0x19;
        status = func_021BE480(expObj, 0, closedModel);
        pos = d_021F4694[doorIdx];
        *status = pos;
        *func_021BE480(expObj, 0, openModel) = pos;
        func_021BE4A4(expObj, 0, (u16)closedModel, 1);
        func_021BE4A4(expObj, 0, (u16)openModel, 1);
        switch (save->doorOpen[doorIdx]) {
        case 0:
            func_021BE4B4(expObj, 0, openModel, 1);
            break;
        case 1:
            func_021BE4B4(expObj, 0, closedModel, 1);
            break;
        }
    }
    func_021BE4A4(expObj, 0, (u16)0x20, 1);
    for (i = 0; i < 2; i++) {
        anime = func_021BE674(expObj, 0, 0x20, i);
        func_021BE6B8(anime, 0);
        func_021BE6B0(anime, 1);
    }
    for (i = 0; i < 8; i++) {
        anime = func_021BE674(expObj, 0, 0x21, i);
        func_021BE6B8(anime, 0);
        func_021BE700(expObj, 0, 0x21, i, 0);
    }
    for (i = 0; i < 4; i++) {
        anime = func_021BE674(expObj, 0, 0x22, i);
        func_021BE6B8(anime, 0);
    }
    func_021BE4B4(expObj, 0, 0x21, 1);
    func_021BE4B4(expObj, 0, 0x22, 1);
    GFL_HEAP_GetTotalFreeSize(0x15);
}



/* Exit: frees the runtime state and the expansion object unit. */
void func_021F39B4(void *fieldMap)
{
    int expObj = func_02188D2C(fieldMap);
    func_021897BC(fieldMap, 1);
    func_021897A0(fieldMap, 1);
    func_021BE418((unsigned char *)expObj, 0);
}



/*
 * extent: two bytes of alignment padding at 021F3A06.
 */
void func_021F39D8(void *fieldMap)
{
    int expObj = func_02188D2C(fieldMap);
    func_021897BC(fieldMap, 1);
    func_0200B3A4(func_02012EC4((struct GameData *)func_020120F4(func_02188C80(fieldMap))), 6);
    func_021BE580((void *)expObj);
}




/*
 * Finds the door at the cell or one cell to its left or right.  exactCell is
 * 1 when the cell is the door's own, doorOpen gets the saved state of the
 * door.  Returns the door index, or 7 when there is none.
 */
int func_021F3A08(Gimmick38Work *work, int cellX, int cellZ, int *doorOpen, int *exactCell)
{
    int found;
    int doorX;
    int doorZ;
    int i;
    VecFx32 *door;

    for (i = 0; i < 7; i++) {
        door = &d_021F4694[i];
        doorX = door->x / 0x10000;
        doorZ = door->z / 0x10000;
        found = 0;
        if (doorX == cellX && doorZ == cellZ) {
            *exactCell = 1;
            found = 1;
        } else if (doorX - 1 == cellX && doorZ == cellZ) {
            *exactCell = 0;
            found = 1;
        } else if (doorX + 1 == cellX && doorZ == cellZ) {
            *exactCell = 0;
            found = 1;
        }
        if (found != 0) {
            *doorOpen = work->doorOpen[i];
            return i;
        }
    }
    *exactCell = 0;
    *doorOpen = 0;
    return 7;
}




/*
 * Starts the event for the door that the player faces: pushing the open door,
 * or bumping the closed one or the side of a door.
 */
int func_021F3A88(int gameSystem, int cellX, int cellZ)
{
    int doorOpen;
    int exactCell;
    int fieldInfo; /* int-typed on purpose: pointer local changes codegen; holds the field map, the player, then the facing */
    int workOrDoor;
    Gimmick38Runtime *runtime;

    fieldInfo = (int)func_0201210C((void *)gameSystem);
    runtime = func_021897BC((char *)((void *)fieldInfo), 1);
    fieldInfo = (int)func_02188CB4((void *)fieldInfo);
    workOrDoor = (int)func_0200B3A4(func_02012EC4((struct GameData *)func_020120F4((const struct GameSystem *)(int)func_02188C80(func_0201210C((void *)gameSystem)))), 6);
    fieldInfo = func_021A3050((u8 *)fieldInfo);
    if (fieldInfo != 0 && fieldInfo != 1)
        return 0;
    workOrDoor = func_021F3A08((Gimmick38Work *)workOrDoor, cellX, cellZ, &doorOpen, &exactCell);
    if (workOrDoor < 7) {
        if (exactCell != 0) {
            if (doorOpen == 1)
                func_020122C0((void *)gameSystem, 0, func_021F3B3C, 0);
            else
                func_020122C0((void *)gameSystem, 0, func_021F407C, 0);
        } else {
            func_020122C0((void *)gameSystem, 0, func_021F3F40, 0);
        }
    } else {
        return 0;
    }
    runtime->slideFrames = 0;
    runtime->holdFrames = 0;
    runtime->side = fieldInfo;
    runtime->doorIdx = workOrDoor;
    runtime->acmdList = 0;
    runtime->acmdDone = 0;
    runtime->acmdActive = 0;
}




/*
 * Event: the player slides an open door by holding up or down, then lets go.
 * note:     u8 side and u8 j locals as in ov038_func_021F3F40.  Case 1 keeps the pressed
 *           path in the if body (the release path, a task swap to
 *           func_021F3DFC, is the else) so case 0's two failed tests reuse
 *           its `b` to the shared tail; slideUnits = (u32)slideFrames >> 1 gives the plain lsrs.
 */
int func_021F3B3C(int event, int *state)
{
    void *gameSystem;
    void *fieldMap;
    int expObj;
    Gimmick38Runtime *runtime;
    void *fieldPlayer;
    u8 openModel;
    u8 side;
    void *anime;
    void *mmdl;
    VecFx32 *srcStatus;
    int keyMask;
    int direction;
    u32 slideUnits;
    VecFx32 pos;

    gameSystem = func_020124E4((struct GameEvent *)event);
    fieldMap = func_0201210C(gameSystem);
    expObj = func_02188D2C(fieldMap);
    runtime = func_021897BC(fieldMap, 1);
    fieldPlayer = func_02188CB4(fieldMap);
    func_0200B3A4(func_02012EC4((struct GameData *)func_020120F4(func_02188C80(fieldMap))), 6);
    side = 0;
    openModel = runtime->doorIdx + 0x19;
    if (runtime->side == 1)
        side++;
    anime = func_021BE674((char *)expObj, 0, 0x22, side);
    switch (*state) {
    case 0:
        mmdl = func_021A3074((void *)fieldPlayer);
        if (func_0216D454(mmdl) != 0 && func_0216D3CC((int)mmdl) != 0) {
            runtime->acmdActive = 1;
            func_021A3038(fieldPlayer, &runtime->doorPos);
            func_021BE4B4((char *)expObj, 0, openModel, 1);
            func_021BE4B4((char *)expObj, 0, 0x22, 0);
            srcStatus = func_021BE480((char *)expObj, 0, openModel);
            *func_021BE480((char *)expObj, 0, 0x22) = *srcStatus;
            func_021BE700((void *)expObj, 0, 0x22, side, 1);
            func_021BE6CC((void *)expObj, 0, 0x22, side, 0);
            func_021BE6B0(anime, 1);
            runtime->slideSePlayed = 0;
            *state = *state + 1;
        }
        break;
    case 1:
        if (runtime->side == 0) {
            keyMask = 0x40;
            direction = -1;
        } else {
            keyMask = 0x80;
            direction = 1;
        }
        if ((func_0203630C() & keyMask) != 0) {
            runtime->holdFrames++;
            if (runtime->holdFrames >= 2) {
                runtime->holdFrames = 0;
                runtime->slideFrames++;
                func_021A3038(fieldPlayer, &pos);
                pos.z += direction << 12;
                func_021A3044(fieldPlayer, &pos);
                slideUnits = (u32)runtime->slideFrames >> 1;
                if (runtime->slideSePlayed == 0 && slideUnits != 0) {
                    func_020061E4(0x6C2);
                    runtime->slideSePlayed = 1;
                }
                func_021BE6CC((void *)expObj, 0, 0x22, side, slideUnits << 12);
                if (runtime->slideFrames >= 0x20)
                    *state = *state + 1;
            }
        } else {
            func_0201235C((struct GameEvent *)event, (u32 *)func_020122C0(gameSystem, 0, func_021F3DFC, 0));
            return 0;
        }
        break;
    case 2:
        if (runtime->acmdList != 0) {
            if (func_02197DA0(runtime->acmdList) == 1) {
                func_02197DAC((void *)(runtime->acmdList));
                runtime->acmdList = 0;
                runtime->acmdDone = 1;
                *state = *state + 1;
            }
        } else {
            runtime->acmdDone = 1;
            *state = *state + 1;
        }
        if (runtime->acmdDone != 0) {
            func_021BE6B0(anime, 0);
            func_02012374((struct GameEvent *)event, func_021618A0(gameSystem, (int)fieldMap, 0xff, (int)(runtime->side == 0 ? d_021F4608 : d_021F4600)));
            GFL_USE_StopAllSe();
            func_020061E4(0x6C3);
        }
        break;
    case 3:
        func_021BE6E8(expObj, 0, 0x22, side);
        if (func_021BE6BC(anime)) {
            func_021BE700((void *)expObj, 0, 0x22, side, 0);
            func_021BE4B4((char *)expObj, 0, 0x22, 1);
            func_021BE4B4((char *)expObj, 0, openModel, 0);
            return 1;
        }
        break;
    }
    if (runtime->acmdActive != 0 && runtime->acmdDone == 0) {
        mmdl = func_021A3074((void *)fieldPlayer);
        if (runtime->acmdList == 0) {
            runtime->acmdList = func_02197D3C(mmdl, runtime->side == 0 ? d_021F4620 : d_021F45F8);
        } else if (func_02197DA0(runtime->acmdList) == 1) {
            func_02197DAC((void *)(runtime->acmdList));
            runtime->acmdList = 0;
        }
    }
    return 0;
}




/*
 * Event: the open door slides back to its home position.
 * note:     same u8 side spelling as ov038_func_021F3F40 (side++ on a u8 local;
 *           the 0x021BE6xx callees take u16 parameters).
 */
int func_021F3DFC(int event, int *state)
{
    void *fieldMap;
    int expObj;
    Gimmick38Runtime *runtime;
    void *fieldPlayer;
    u8 openModel;
    u8 side;
    int done;
    int slideUnits;
    VecFx32 pos;

    fieldMap = func_0201210C(func_020124E4((void *)event));
    expObj = func_02188D2C(fieldMap);
    runtime = func_021897BC(fieldMap, 1);
    fieldPlayer = func_02188CB4(fieldMap);
    side = 0;
    openModel = runtime->doorIdx + 0x19;
    if (runtime->side == 1)
        side++;
    switch (*state) {
    case 0:
        GFL_USE_StopAllSe();
        *state = *state + 1;
    case 1:
        if (runtime->acmdList != 0) {
            if (func_02197DA0(runtime->acmdList) == 1) {
                func_02197DAC((void *)(runtime->acmdList));
                runtime->acmdList = 0;
                runtime->slideFrames = 0;
                *state = *state + 1;
            }
        } else {
            runtime->slideFrames = 0;
            *state = *state + 1;
        }
        if (*state == 2)
            runtime->slideSePlayed = 0;
        break;
    case 2:
        func_021A3038(fieldPlayer, &pos);
        done = 0;
        runtime->slideFrames++;
        if (runtime->side == 0) {
            pos.z += runtime->slideFrames << 12;
            if (pos.z >= runtime->doorPos.z) {
                pos.z = runtime->doorPos.z;
                done = 1;
            }
            slideUnits = (runtime->doorPos.z - pos.z) / 2;
        } else {
            pos.z += -runtime->slideFrames << 12;
            if (pos.z <= runtime->doorPos.z) {
                pos.z = runtime->doorPos.z;
                done = 1;
            }
            slideUnits = (pos.z - runtime->doorPos.z) / 2;
        }
        if (runtime->slideSePlayed == 0 && slideUnits != 0) {
            func_020061E4(0x6C4);
            runtime->slideSePlayed = 1;
        }
        func_021BE6CC((void *)expObj, 0, 0x22, side, slideUnits);
        func_021A3044(fieldPlayer, &pos);
        if (done) {
            func_021BE700((void *)expObj, 0, 0x22, side, 0);
            func_021BE4B4((char *)expObj, 0, 0x22, 1);
            func_021BE4B4((char *)expObj, 0, openModel, 0);
            return 1;
        }
        break;
    }
    return 0;
}





/*
 * Event: the player bumps the side of a door (shake animation on the open or
 * closed door model).
 * note:     animeIdx and tempModel (0x021BE674/0x021BE700/0x021BE6CC arguments) are u8 locals,
 *           so the u16 parameters add no narrowing at the call; animeIdx++ keeps the
 *           unfolded increment of the stored value.
 */
int func_021F3F40(int event, int *state)
{
    void *fieldMap;
    int expObj;
    Gimmick38Runtime *runtime;
    Gimmick38Work *save;
    u8 srcModel;
    u8 tempModel;
    u8 animeIdx;
    void *anime;
    VecFx32 *srcStatus;

    fieldMap = func_0201210C(func_020124E4((void *)event));
    expObj = func_02188D2C(fieldMap);
    runtime = func_021897BC(fieldMap, 1);
    func_02188CB4(fieldMap);
    save = func_0200B3A4(func_02012EC4((struct GameData *)func_020120F4(func_02188C80(fieldMap))), 6);
    if (save->doorOpen[runtime->doorIdx] == 0) {
        srcModel = runtime->doorIdx + 0x12;
        tempModel = 0x21;
    } else {
        srcModel = runtime->doorIdx + 0x19;
        tempModel = 0x22;
    }
    animeIdx = 2;
    if (runtime->side == 1)
        animeIdx++;
    anime = func_021BE674((char *)expObj, 0, tempModel, animeIdx);
    switch (*state) {
    case 0:
        func_021BE4B4((char *)expObj, 0, srcModel, 1);
        func_021BE4B4((char *)expObj, 0, tempModel, 0);
        srcStatus = func_021BE480((char *)expObj, 0, srcModel);
        *func_021BE480((char *)expObj, 0, tempModel) = *srcStatus;
        func_021BE700((void *)expObj, 0, tempModel, animeIdx, 1);
        func_021BE6B0(anime, 0);
        func_021BE6CC((void *)expObj, 0, tempModel, animeIdx, 0);
        func_020061E4(0x6C5);
        *state = *state + 1;
        break;
    case 1:
        if (func_021BE6BC(anime)) {
            func_021BE700((void *)expObj, 0, tempModel, animeIdx, 0);
            func_021BE4B4((char *)expObj, 0, tempModel, 1);
            func_021BE4B4((char *)expObj, 0, srcModel, 0);
            return 1;
        }
        break;
    }
    return 0;
}






/*
 * Event: the player bumps a closed door (shake animation on the closed model).
 * note:     `animeIdx++` on the u8 local keeps the increment of the stored zero
 *           (adds; lsls; lsrs); `animeIdx = animeIdx + 1` folds it to `movs #1` and swaps
 *           state/fieldMap between r5 and r6.
 */
int func_021F407C(int event, int *state)
{
    void *fieldMap;
    char *expObj;
    Gimmick38Runtime *runtime;
    u8 closedModel;
    u8 animeIdx;
    void *anime;
    VecFx32 *srcStatus;

    fieldMap = func_0201210C(func_020124E4((void *)event));
    expObj = (char *)func_02188D2C(fieldMap);
    runtime = func_021897BC((char *)fieldMap, 1);
    func_02188CB4(fieldMap);
    animeIdx = 0;
    closedModel = runtime->doorIdx + 0x12;
    if (runtime->side == 1) {
        animeIdx++;
    }
    anime = func_021BE674(expObj, 0, 0x21, animeIdx);
    switch (*state) {
    case 0:
        func_021BE4B4(expObj, 0, closedModel, 1);
        func_021BE4B4(expObj, 0, 0x21, 0);
        srcStatus = func_021BE480(expObj, 0, closedModel);
        *func_021BE480(expObj, 0, 0x21) = *srcStatus;
        func_021BE700(expObj, 0, 0x21, animeIdx, 1);
        func_021BE6B0(anime, 0);
        func_021BE6CC((void *)expObj, 0, 0x21, animeIdx, 0);
        func_020061E4(0x6C5);
        *state = *state + 1;
        break;
    case 1:
        if (func_021BE6BC(anime)) {
            func_021BE700(expObj, 0, 0x21, animeIdx, 0);
            func_021BE4B4(expObj, 0, 0x21, 1);
            func_021BE4B4(expObj, 0, closedModel, 0);
            return 1;
        }
        break;
    }
    return 0;
}





/* Script command: starts the press event of a switch. */
void *func_021F4184(void *gameSystem, int switchIdx)
{
    Gimmick38Runtime *runtime = func_021897BC((char *)func_0201210C(gameSystem), 1);
    if (switchIdx >= 8) return 0;
    runtime->switchIdx = switchIdx;
    return func_020122C0(gameSystem, 0, func_021F4200, 0);
}




/* Script command: starts the press event of a plate. */
void *func_021F41B0(void *gameSystem, int plateIdx)
{
    Gimmick38Runtime *runtime = func_021897BC((char *)func_0201210C(gameSystem), 1);
    if (plateIdx >= 10) return 0;
    runtime->plateIdx = plateIdx;
    return func_020122C0(gameSystem, 0, func_021F42BC, 0);
}




/* Script command: starts the scripted event, whose script depends on the variant. */
void *func_021F41DC(void *gameSystem, int variant)
{
    Gimmick38Runtime *runtime = func_021897BC((char *)func_0201210C(gameSystem), 1);
    runtime->scriptVariant = variant;
    return func_020122C0(gameSystem, 0, func_021F44C0, 0);
}



/*
 * Event: plays the press animation of a switch and saves it as found.
 * note:     the case-0 byte must be held in a u8 (or u16) local: an int local
 *           swaps the 0x0201210C result and the 0x021897BC pointer between r4
 *           and r5.  func_020124E4/func_0201210C are argless as in the twin
 *           ov045_func_021F39B8.  func_021BE700/func_021BE674 take their
 *           fourth argument as u16 (the caller truncates it before the bl).
 *           func_021BE674's third parameter must be `int` here, as for
 *           func_021BE700: its own file's `unsigned int j` brings the r4/r5
 *           swap back even with the u8 local.
 */
int func_021F4200(int event, int *state)
{
    void *fieldMap;
    int expObj;
    Gimmick38Runtime *runtime;
    Gimmick38Work *save;
    unsigned int gimmickSave;
    u16 *progress;
    int i;
    u8 switchModel;

    fieldMap = func_0201210C(func_020124E4((void *)event));
    expObj = func_02188D2C(fieldMap);
    runtime = func_021897BC(fieldMap, 1);
    gimmickSave = (unsigned int)func_02012EC4((struct GameData *)func_020120F4((const struct GameSystem *)func_02188C80(fieldMap)));
    save = func_0200B3A4((struct GimmickWork *)gimmickSave, 6);
    progress = func_0200B3A8((struct GimmickWork *)gimmickSave, 6);
    switch (*state) {
    case 0:
        switchModel = runtime->switchIdx;
        for (i = 0; i < 2; i++) {
            func_021BE700((void *)expObj, 0, switchModel, (u16)i, 1);
            func_021BE6B0(func_021BE674((char *)expObj, 0, switchModel, i), 0);
        }
        *state = *state + 1;
        break;
    case 1:
        if (func_021BE6BC(func_021BE674((char *)expObj, 0, runtime->switchIdx, 0))) {
            save->switchFound[runtime->switchIdx] = 1;
            progress[runtime->switchIdx] = 1;
            return 1;
        }
        break;
    }
    return 0;
}



/*
 * Event: plays the press animation of a plate; when the plate it depends on is
 * pressed and its door is still closed, the door lights up and opens.
 * note:     the work block's two int arrays are struct fields (index*4 then
 *           [#0x20]/[#0x48]); the flag test is `if (n != -1) { if (a[n])
 *           f = 1; } else f = 1;`, whose cross-jumped else arm gives the
 *           `beq SET ... beq SKIP; b SET` shape (an `||` or else-if does not).
 */
int func_021F42BC(int event, int *state)
{
    void *fieldMap;
    int expObj;
    Gimmick38Runtime *runtime;
    Gimmick38Work *save;
    int i;
    int ready;
    u8 plateModel;
    u8 doorIdx;
    s8 prerequisite;
    VecFx32 *srcStatus;

    fieldMap = func_0201210C(func_020124E4((void *)event));
    expObj = func_02188D2C(fieldMap);
    runtime = func_021897BC((char *)fieldMap, 1);
    save = func_0200B3A4(func_02012EC4((struct GameData *)func_020120F4((const struct GameSystem *)func_02188C80(fieldMap))), 6);
    switch (*state) {
    case 0:
        plateModel = runtime->plateIdx + 8;
        for (i = 0; i < 2; i++) {
            func_021BE700((void *)expObj, 0, plateModel, (u16)i, 1);
            func_021BE6B0(func_021BE674((char *)expObj, 0, plateModel, i), 0);
        }
        *state = *state + 1;
        break;
    case 1:
        ready = 0;
        if (func_021BE6BC(func_021BE674((char *)expObj, 0, (u8)(runtime->plateIdx + 8), 0))) {
            save->platePressed[runtime->plateIdx] = 1;
            prerequisite = d_021F4628[runtime->plateIdx];
            if (prerequisite != -1) {
                if (save->platePressed[prerequisite] != 0) {
                    ready = 1;
                }
            } else {
                ready = 1;
            }
            if (ready) {
                doorIdx = d_021F4632[runtime->plateIdx];
                if (save->doorOpen[doorIdx] == 0) {
                    runtime->plateDoorIdx = doorIdx;
                    plateModel = doorIdx + 0x12;
                    func_021BE4B4((char *)expObj, 0, (u16)plateModel, 1);
                    func_021BE4B4((char *)expObj, 0, (u16)0x21, 0);
                    srcStatus = func_021BE480((char *)expObj, 0, plateModel);
                    *func_021BE480((char *)expObj, 0, 0x21) = *srcStatus;
                    for (i = 0; i < 4; i++) {
                        plateModel = i + 4;
                        func_021BE700((void *)expObj, 0, 0x21, (u16)plateModel, 1);
                        func_021BE6B0(func_021BE674((char *)expObj, 0, 0x21, plateModel), 0);
                        func_021BE6CC((void *)expObj, 0, 0x21, plateModel, 0);
                    }
                    func_020061E4(0x6C8);
                    *state = *state + 1;
                    break;
                }
                return 1;
            }
            return 1;
        }
        break;
    case 2:
        if (func_021BE6BC(func_021BE674((char *)expObj, 0, 0x21, 4))) {
            for (i = 0; i < 4; i++) {
                func_021BE700((void *)expObj, 0, 0x21, (u16)((u8)(i + 4)), 0);
            }
            save->doorOpen[runtime->plateDoorIdx] = 1;
            doorIdx = runtime->plateDoorIdx;
            func_021BE4B4((char *)expObj, 0, (u16)(doorIdx + 0x12), 1);
            func_021BE4B4((char *)expObj, 0, (u16)(doorIdx + 0x19), 0);
            func_021BE4B4((char *)expObj, 0, (u16)0x21, 1);
            func_020061E4(0x6DC);
            return 1;
        }
        break;
    }
    return 0;
}
