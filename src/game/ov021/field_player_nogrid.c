/*
 * file:     field_player_nogrid.c
 * unit:     yes
 * function: func_021A5880, func_021A5920, func_021A5928, func_021A5964, func_021A596C, func_021A59DC, func_021A59EC, func_021A5A00, func_021A5A0C, func_021A5A18, func_021A5A24, func_021A5A30, func_021A5A34, func_021A5A68, func_021A5AD4, func_021A5B4C, func_021A5B6C, func_021A5B7C, func_021A5BC0, func_021A5C3C, func_021A5CA4, func_021A5D04, func_021A5DD8, func_021A5E28, func_021A5EA0, func_021A5EA4, func_021A5EDC, func_021A5F14, func_021A5F38, func_021A5F74, func_021A5F98, func_021A6014, func_021A607C, func_021A60DC, func_021A61B0, func_021A6200, func_021A6278, func_021A627C, func_021A62B4, func_021A62D8, func_021A62FC, func_021A6338, func_021A635C, func_021A63EC, func_021A63F0, func_021A6428, func_021A6454, func_021A6478, func_021A64B4, func_021A652C, func_021A658C, func_021A661C, func_021A666C, func_021A66E4, func_021A66EC, func_021A66F8, func_021A6708, func_021A6714, func_021A6720, func_021A672C, func_021A6738, func_021A6744, func_021A6750, func_021A675C, func_021A6768, func_021A6774, func_021A6780, func_021A678C, func_021A6798, func_021A67A4, func_021A682C, func_021A6870, func_021A6908, func_021A6974, func_021A69D8, func_021A6A3C, func_021A6A64, func_021A6A8C, func_021A6AA0, func_021A6B08, func_021A6B30, func_021A6B50, func_021A6B88, func_021A6B9C, func_021A6BAC, func_021A6BB4, func_021A6C30, func_021A6C4C, func_021A6C64, func_021A6C6C
 * address:  0x021A5880
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from weather_task.c (lane L141): __FILE__ anchor 021A5914 (d_021DDF04 "field_player_nogrid.c"); 021A5880 is the nogrid constructor.
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   func_02030734  0x02030734  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_02006148  0x02006148  thumb
 *   func_020061F8  0x020061F8  thumb
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0219E2F4  0x0219E2F4  thumb
 *   func_0219E664  0x0219E664  thumb
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0216D608  0x0216D608  thumb  ov010
 *   func_021AB0F8  0x021AB0F8  thumb  ov021
 *   func_021AB158  0x021AB158  thumb  ov021
 *   func_021AB164  0x021AB164  thumb  ov021
 *   func_021AB170  0x021AB170  thumb  ov021
 *   func_021AB17C  0x021AB17C  thumb  ov021
 *   func_0216D4B4  0x0216D4B4  thumb  ov010
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_0216D7DC  0x0216D7DC  thumb  ov010
 *   func_021AB348  0x021AB348  thumb  ov021
 *   func_0216D550  0x0216D550  thumb  ov010
 *   func_0216D548  0x0216D548  thumb  ov010
 *   func_02012844  0x02012844  thumb
 *   func_0216D5A0  0x0216D5A0  thumb  ov010
 *   func_0216E0AC  0x0216E0AC  thumb  ov010
 *   func_0219E348  0x0219E348  thumb  ov021
 *   func_0219E2C0  0x0219E2C0  thumb  ov021
 *   d_021DDF04     0x021DDF04  data  a4
 *   d_021DDEE0     0x021DDEE0  data  a4
 *   d_021DDEE0b    0x021DDEE0  data  a4
 *   func_021B8028  0x021B8028  thumb  ov021
 *   func_0219E424  0x0219E424  thumb  ov021
 *   func_0219D724  0x0219D724  thumb  ov021
 *   func_021BB1AC  0x021BB1AC  thumb  ov021
 *   func_021BB1B8  0x021BB1B8  thumb  ov021
 *   func_021BB1C4  0x021BB1C4  thumb  ov021
 *   func_021BB1D0  0x021BB1D0  thumb  ov021
 *   func_021BB1DC  0x021BB1DC  thumb  ov021
 *   func_021BB1E8  0x021BB1E8  thumb  ov021
 *   data_021D8AB8  0x021D8AB8  data  a4
 *   func_021642A4  0x021642A4  thumb  ov010
 *   func_0216D60C  0x0216D60C  thumb  ov010
 *   func_0216D5D8  0x0216D5D8  thumb
 *   d_021D8AB0  0x021D8AB0  data  ov021  a4
 *   func_02162598  0x02162598  thumb  ov010
 *   func_021A395C  0x021A395C  thumb  ov021
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_021A3964  0x021A3964  thumb  ov021
 *   func_021A3974  0x021A3974  thumb  ov021
 *   func_021A3AB8  0x021A3AB8  thumb  ov021
 *   func_021A3AC4  0x021A3AC4  thumb  ov021
 *   func_021A3CB0  0x021A3CB0  thumb  ov021
 *   func_021A3CC0  0x021A3CC0  thumb  ov021
 *   func_021A3CE8  0x021A3CE8  thumb  ov021
 */
#include "field_player_nogrid_types.h"

typedef signed int s32;

/* Heap, sound and memory helpers. */
extern u32 func_020307B0(void *block);
extern void *func_02030734(u32 heapId, u32 size, int a, const char *file, u16 line);
void func_020061E4(u32 seId);
void func_02082BCC(void *dst, int value, int size);
int func_02006148(u32 seId);
void func_020061F8(int slot);

/* Field model (ov010). */
void func_0216D5E0(Mmdl *mmdl, int dir);
extern u16 func_0216D5F8(Mmdl *mmdl);
u16 func_0216D598(Mmdl *mmdl);
extern u16 func_0216D608(Mmdl *mmdl);
extern int func_0216D3CC(Mmdl *mmdl);
extern void *func_0216D4B4(Mmdl *mmdl);
void func_0216D410(Mmdl *mmdl, int acmdCode);
void func_0216D674(Mmdl *mmdl, u16 value);
u32 func_0216D7DC(Mmdl *mmdl);
u32 *func_0216D550(Mmdl *mmdl, u32 bits);
extern u32 *func_0216D548(Mmdl *mmdl, u32 bits); /* its third parameter is a scratch it never reads */
extern u16 func_0216D5A0(Mmdl *mmdl);
extern void func_0216E0AC(Mmdl *mmdl, void *header);
extern u16 func_021642A4(int dir);
extern int func_0216D60C(Mmdl *mmdl, int dir);
extern void func_0216D5D8(Mmdl *mmdl, int dir);
int func_02197E7C(int dir, int baseCode);

/* Field model on rails (ov021). */
extern void func_0219E2F4(Mmdl *mmdl, RailLocation *outLocation);
extern int func_0219E664(Mmdl *mmdl, u32 dir, RailLocation *outLocation);
extern struct RailWork *func_0219E348(Mmdl *mmdl);
extern void func_0219E2C0(Mmdl *mmdl, RailLocation *location);
extern int func_0219E424(Mmdl *mmdl, u32 dir, int *outAttr);
extern int func_0219D724(Mmdl *mmdl, RailLocation *location);
extern void func_021B8028(struct RailWork *railWork, void *outPos);

/* Tile attributes. */
u16 func_021AB0F0(u32 attr);
extern u16 func_021AB0F8(u32);
extern int func_021AB158(u16);
extern int func_021AB164(u16);
extern int func_021AB170(u16);
extern int func_021AB17C(u16);
int func_021AB348(u32 attr);
extern int func_021BB1AC(int attr);
extern int func_021BB1B8(int attr);
extern int func_021BB1C4(int attr);
extern int func_021BB1D0(int attr);
extern int func_021BB1DC(int attr);
extern int func_021BB1E8(int attr);

/* Game system and event data. */
void *func_020120F4(void *gameSystem);
extern void *func_02188C80(struct FieldMap *fieldMap);
extern void *func_02012844(void *gameData);
extern int func_02162598(void *eventData, RailLocation *location);

/* Player core (field_player_core.c). */
struct FieldMap *func_021A395C(struct FieldPlayerCore *core);
Mmdl *func_021A3960(struct FieldPlayerCore *core);
void func_021A3964(struct FieldPlayerCore *core, u32 state);
u32 func_021A3974(struct FieldPlayerCore *core);
u16 func_021A3AB8(struct FieldPlayerCore *core, u32 keyCont);
void func_021A3AC4(struct FieldPlayerCore *core, u32 keyCont);
int func_021A3CB0(struct FieldPlayerCore *core, u32 flags);
int func_021A3CC0(struct FieldPlayerCore *core);
void func_021A3CE8(struct FieldPlayerCore *core);

/* This file. */
FieldPlayerNogrid *func_021A5880(struct FieldPlayerCore *core, int heapId);
void func_021A5920(FieldPlayerNogrid *player);
void func_021A5928(FieldPlayerNogrid *player, RailLocation *location);
void func_021A5964(FieldPlayerNogrid *player);
void func_021A596C(FieldPlayerNogrid *player, u32 keyTrg, u32 keyCont);
int func_021A59DC(FieldPlayerNogrid *player);
u32 func_021A59EC(FieldPlayerNogrid *player);
void func_021A5A00(FieldPlayerNogrid *player, RailLocation *location);
void func_021A5A0C(FieldPlayerNogrid *player, RailLocation *outLocation);
int func_021A5A18(FieldPlayerNogrid *player, u32 dir, RailLocation *outLocation);
void func_021A5A24(FieldPlayerNogrid *player, void *outPos);
struct RailWork *func_021A5A30(FieldPlayerNogrid *player);
void func_021A5A34(FieldPlayerNogrid *player);
int func_021A5A68(FieldPlayerNogrid *player, u32 dir, u32 keyTrg, u32 keyCont, u32 forced);
void func_021A5AD4(FieldPlayerNogrid *player, u32 action, u32 dir, u32 keyTrg, u32 keyCont, u32 forced);
void func_021A5B4C(FieldPlayerNogrid *player, u32 keyCont, int action);
int func_021A5B6C(FieldPlayerNogrid *player, Mmdl *mmdl, u32 dir, int *outAttr);
void func_021A5B7C(FieldPlayerNogrid *player);
void func_021A5BC0(FieldPlayerNogrid *player, u32 action, u32 keyTrg, u32 keyCont, u16 dir, u32 forced);
int func_021A5C3C(FieldPlayerNogrid *player, u32 keyTrg, u32 keyCont, u16 dir, u32 forced);
int func_021A5CA4(FieldPlayerNogrid *player, Mmdl *mmdl, u32 keyTrg, u32 keyCont, u16 dir, u32 forced);
int func_021A5D04(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced);
int func_021A5DD8(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced);
int func_021A5E28(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced);
void func_021A5EA0(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, int dir, int forced);
void func_021A5EA4(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced);
void func_021A5EDC(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced);
void func_021A5F14(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced);
void func_021A5F38(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced);
void func_021A5F74(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced);
void func_021A5F98(FieldPlayerNogrid *player, u32 action, u32 keyTrg, u32 keyCont, u16 dir, u32 forced);
int func_021A6014(FieldPlayerNogrid *player, int keyTrg, int keyCont, u16 dir, int forced);
int func_021A607C(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced);
int func_021A60DC(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced);
int func_021A61B0(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced);
int func_021A6200(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced);
void func_021A6278(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, int dir, int forced);
void func_021A627C(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced);
void func_021A62B4(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced);
void func_021A62D8(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced);
void func_021A62FC(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced);
void func_021A6338(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced);
void func_021A635C(FieldPlayerNogrid *player, int action, int keyTrg, int keyCont, u16 dir, int forced);
void func_021A63EC(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, int dir, int forced);
void func_021A63F0(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced);
void func_021A6428(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced);
void func_021A6454(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced);
void func_021A6478(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced);
int func_021A64B4(FieldPlayerNogrid *player, int keyTrg, int keyCont, u16 dir, int forced);
int func_021A652C(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced);
int func_021A658C(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced);
int func_021A661C(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced);
u32 func_021A666C(FieldPlayerNogrid *player, Mmdl *mmdl, u32 keyTrg, u32 keyCont, u16 dir, u32 forced);
void func_021A66E4(FieldPlayerNogrid *player, u32 mask);
void func_021A66EC(FieldPlayerNogrid *player, u32 mask);
int func_021A66F8(FieldPlayerNogrid *player, int mask);
void func_021A6708(FieldPlayerNogrid *player);
void func_021A6714(FieldPlayerNogrid *player);
void func_021A6720(FieldPlayerNogrid *player);
void func_021A672C(FieldPlayerNogrid *player);
void func_021A6738(FieldPlayerNogrid *player);
void func_021A6744(FieldPlayerNogrid *player);
void func_021A6750(FieldPlayerNogrid *player);
void func_021A675C(FieldPlayerNogrid *player);
void func_021A6768(FieldPlayerNogrid *player);
void func_021A6774(FieldPlayerNogrid *player);
void func_021A6780(FieldPlayerNogrid *player);
void func_021A678C(FieldPlayerNogrid *player);
void func_021A6798(FieldPlayerNogrid *player);
u32 func_021A67A4(FieldPlayerNogrid *player);
u32 func_021A682C(FieldPlayerNogrid *player, u32 dir, u32 skipTileKind);
void func_021A6870(FieldPlayerNogrid *player);
u32 func_021A6908(FieldPlayerNogrid *player, u32 dir, u32 skipTileKind);
u32 func_021A6974(FieldPlayerNogrid *player, u32 dir);
u32 func_021A69D8(FieldPlayerNogrid *player, u32 dir);
int func_021A6A3C(FieldPlayerNogrid *player, int dir, int skipTileKind);
int func_021A6A64(FieldPlayerNogrid *player, int dir, int skipTileKind);
int func_021A6A8C(FieldPlayerNogrid *player, int dir, int skipTileKind);
u32 func_021A6AA0(FieldPlayerNogrid *player, u32 dir);
void func_021A6B08(NogridSpin *spin, u8 variant);
void func_021A6B30(NogridSpin *spin);
void func_021A6B50(NogridSpin *spin, Mmdl *mmdl);
int func_021A6B88(NogridInputHold *hold);
void func_021A6B9C(NogridInputHold *hold);
int func_021A6BAC(NogridInputHold *hold);
void func_021A6BB4(NogridInputHold *hold, u32 dir, Mmdl *mmdl);
void func_021A6C30(NogridInputHold *hold);
int func_021A6C4C(NogridInputHold *hold, int dir);
u32 func_021A6C64(NogridInputHold *hold);
int func_021A6C6C(FieldPlayerNogrid *player, u32 dir);

extern char d_021DDF04;                /* source file name string used by the heap allocation */
extern u16  d_021DDEE0[2];             /* header record handed to func_0216E0AC; [1] is the object code */
extern u16  d_021DDEE0b[2];            /* second symbol at the same address (the pool needs both) */
extern const NogridForcedMoveFunc data_021D8AB8[];  /* forced move handlers, indexed by tile kind */
extern const u8 d_021D8AB0[][4];       /* spin tile direction sequences */


/* Creates the controller for the player core and attaches the player's field model. */
FieldPlayerNogrid *func_021A5880(struct FieldPlayerCore *core, int heapId)
{
    FieldPlayerNogrid *player;

    player = func_02030734(heapId, 0x24, 1, &d_021DDF04, 0x1a0);
    player->core = core;
    player->fieldMap = func_021A395C(core);
    player->mmdl = func_021A3960(player->core);
    if (func_0216D5A0(player->mmdl) != 0x45) {
        d_021DDEE0[1] = func_0216D598(player->mmdl);
        func_0216E0AC(player->mmdl, d_021DDEE0b);
    }
    player->railWork = func_0219E348(player->mmdl);
    {
        RailLocation location = {0, 0, 0, 0, 0};
        func_0219E2C0(player->mmdl, &location);
    }
    func_021A6B88(&player->inputHold);
    {
        int kind = func_021A3974(player->core);
        switch (kind) {
        case 2:
            func_021A3CB0(player->core, 4);
            func_021A3CE8(player->core);
            break;
        case 3:
            func_021A3CB0(player->core, 0x100);
            func_021A3CE8(player->core);
            break;
        }
    }
    return player;
}


void func_021A5920(FieldPlayerNogrid *player)
{
    func_020307B0(player);
}


/* Attaches the model again after its header changed and stores its rail location. */
void func_021A5928(FieldPlayerNogrid *player, RailLocation *location)
{
    if (func_0216D5A0(player->mmdl) != 0x45) {
        d_021DDEE0[1] = func_0216D598(player->mmdl);
        func_0216E0AC(player->mmdl, d_021DDEE0b);
    }
    player->railWork = func_0219E348(player->mmdl);
    func_0219E2C0(player->mmdl, location);
}


void func_021A5964(FieldPlayerNogrid *player)
{
    player->railWork = 0;
}


/* One frame: keys to direction, forced move, check, execute, bookkeeping. */
void func_021A596C(FieldPlayerNogrid *player, u32 keyTrg, u32 keyCont)
{
    u32 inputDir;
    u32 moveDir;
    u32 action;

    inputDir = func_021A3AB8(player->core, keyCont);
    func_021A3CC0(player->core);
    func_021A6BB4(&player->inputHold, inputDir, player->mmdl);
    moveDir = func_021A682C(player, inputDir, 0);
    action = func_021A5A68(player, moveDir, keyTrg, keyCont, 0);
    func_021A5B4C(player, keyCont, action);
    func_021A5AD4(player, action, moveDir, keyTrg, keyCont, 0);
    func_021A5B7C(player);
    func_021A6C30(&player->inputHold);
}


int func_021A59DC(FieldPlayerNogrid *player)
{
    if (player->moveMode == FIELD_PLAYER_NOGRID_MODE_BLOCKED) {
        return 1;
    }
    return 0;
}


u32 func_021A59EC(FieldPlayerNogrid *player)
{
    u32 result = 1;
    if (func_021A66F8(player, FIELD_PLAYER_NOGRID_FLAG_FORCED_MOVE) == 0) {
        result = 0;
    }
    return result;
}


void func_021A5A00(FieldPlayerNogrid *player, RailLocation *location)
{
    func_0219E2C0(player->mmdl, location);
}


void func_021A5A0C(FieldPlayerNogrid *player, RailLocation *outLocation)
{
    func_0219E2F4(player->mmdl, outLocation);
}


int func_021A5A18(FieldPlayerNogrid *player, u32 dir, RailLocation *outLocation)
{
    return func_0219E664(player->mmdl, dir, outLocation);
}


void func_021A5A24(FieldPlayerNogrid *player, void *outPos)
{
    func_021B8028(player->railWork, outPos);
}


struct RailWork *func_021A5A30(FieldPlayerNogrid *player)
{
    return player->railWork;
}


/* Ends a blocked walk: frees the command, restores the facing direction. */
void func_021A5A34(FieldPlayerNogrid *player)
{
    Mmdl *mmdl;
    int dir;

    if (player->moveMode == FIELD_PLAYER_NOGRID_MODE_BLOCKED) {
        mmdl = player->mmdl;
        dir = func_0216D5F8(mmdl);
        func_0216D4B4(mmdl);
        func_0216D5E0(mmdl, dir);
        func_0216D674(mmdl, 0);
        func_021A3964(player->core, 0);
    }
}


/* Picks the check function of the core's movement kind. */
int func_021A5A68(FieldPlayerNogrid *player, u32 dir, u32 keyTrg, u32 keyCont, u32 forced)
{
    int action;

    switch (func_021A3974(player->core)) {
    case FIELD_PLAYER_NOGRID_KIND_WALK:
        action = func_021A5C3C(player, keyTrg, keyCont, dir, forced);
        break;
    case FIELD_PLAYER_NOGRID_KIND_SLOW:
        action = func_021A6014(player, keyTrg, keyCont, dir, forced);
        break;
    case 2:
    case 3:
        action = func_021A64B4(player, keyTrg, keyCont, dir, forced);
        break;
    }
    return action;
}


/* Picks the start function of the core's movement kind. */
void func_021A5AD4(FieldPlayerNogrid *player, u32 action, u32 dir, u32 keyTrg, u32 keyCont, u32 forced)
{
    switch (func_021A3974(player->core)) {
    case FIELD_PLAYER_NOGRID_KIND_WALK:
        func_021A5BC0(player, action, keyTrg, keyCont, (u16)dir, forced);
        break;
    case FIELD_PLAYER_NOGRID_KIND_SLOW:
        func_021A5F98(player, action, keyTrg, keyCont, dir, forced);
        break;
    case 2:
    case 3:
        func_021A635C(player, action, keyTrg, keyCont, (u16)dir, forced);
        break;
    }
}


void func_021A5B4C(FieldPlayerNogrid *player, u32 keyCont, int action)
{
    func_021A3AC4(player->core, keyCont);
    func_021A6738(player);
    if (action == FIELD_PLAYER_NOGRID_ACTION_WALK)
        func_021A672C(player);
}


/* Returns the hit bits of the tile next to the model in a direction. */
int func_021A5B6C(FieldPlayerNogrid *player, Mmdl *mmdl, u32 dir, int *outAttr)
{
    return func_0219E424(mmdl, dir, outAttr);
}


/* Starts or stops the spin tile animation by the spin flags, then steps it. */
void func_021A5B7C(FieldPlayerNogrid *player)
{
    if (func_021A66F8(player, FIELD_PLAYER_NOGRID_FLAG_SPIN_A)) {
        func_021A6B08(&player->spin, 0);
    } else if (func_021A66F8(player, FIELD_PLAYER_NOGRID_FLAG_SPIN_B)) {
        func_021A6B08(&player->spin, 1);
    } else {
        func_021A6B30(&player->spin);
    }
    func_021A6B50(&player->spin, player->mmdl);
}


void func_021A5BC0(FieldPlayerNogrid *player, u32 action, u32 keyTrg, u32 keyCont, u16 dir, u32 forced)
{
    Mmdl *mmdl = player->mmdl;

    switch (action) {
    case FIELD_PLAYER_NOGRID_ACTION_NONE:
        func_021A5EA0(player, mmdl, keyTrg, keyCont, dir, forced);
        break;
    case FIELD_PLAYER_NOGRID_ACTION_STAND:
        func_021A5EA4(player, mmdl, keyTrg, keyCont, dir, forced);
        break;
    case FIELD_PLAYER_NOGRID_ACTION_WALK:
        func_021A5EDC(player, mmdl, keyTrg, keyCont, dir, forced);
        break;
    case FIELD_PLAYER_NOGRID_ACTION_TURN:
        func_021A5F14(player, mmdl, keyTrg, keyCont, dir, forced);
        break;
    case FIELD_PLAYER_NOGRID_ACTION_BLOCKED:
        func_021A5F38(player, mmdl, keyTrg, keyCont, dir, forced);
        break;
    case FIELD_PLAYER_NOGRID_ACTION_LEDGE_JUMP:
        func_021A5F74(player, mmdl, keyTrg, keyCont, dir, forced);
        break;
    }
}


/* Check for the walk kind: by the running mode. */
int func_021A5C3C(FieldPlayerNogrid *player, u32 keyTrg, u32 keyCont, u16 dir, u32 forced)
{
    int mode = player->moveMode;
    int action = 0;
    Mmdl *mmdl = player->mmdl;

    switch (mode) {
    case FIELD_PLAYER_NOGRID_MODE_STAND:
        action = func_021A5CA4(player, mmdl, keyTrg, keyCont, dir, forced);
        break;
    case FIELD_PLAYER_NOGRID_MODE_WALK:
        action = func_021A5D04(player, mmdl, keyTrg, keyCont, dir, forced);
        break;
    case FIELD_PLAYER_NOGRID_MODE_TURN:
        action = func_021A5DD8(player, mmdl, keyTrg, keyCont, dir, forced);
        break;
    case FIELD_PLAYER_NOGRID_MODE_BLOCKED:
        action = func_021A5E28(player, mmdl, keyTrg, keyCont, dir, forced);
        break;
    }
    return action;
}


/* Walk kind, model standing: stand, turn first, or check the step. */
int func_021A5CA4(FieldPlayerNogrid *player, Mmdl *mmdl, u32 keyTrg, u32 keyCont, u16 dir, u32 forced)
{
    if (func_0216D3CC(mmdl) == 1) {
        if (dir != FIELD_PLAYER_NOGRID_DIR_NONE) {
            if (dir != func_0216D5F8(mmdl) && forced == 0) {
                return FIELD_PLAYER_NOGRID_ACTION_TURN;
            }
            return func_021A5D04(player, mmdl, keyTrg, keyCont, dir, forced);
        }
        return FIELD_PLAYER_NOGRID_ACTION_STAND;
    }
    return FIELD_PLAYER_NOGRID_ACTION_NONE;
}


/* Walk kind, step check: walk, bump into a wall or jump a ledge by the hit bits of the next tile. */
int func_021A5D04(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced)
{
    RailLocation nextLocation;
    u32 hitBits;
    u32 attr;
    u16 attrKind;
    int ledgeDir;

    if (func_0216D3CC(mmdl) == 0) {
        return FIELD_PLAYER_NOGRID_ACTION_NONE;
    }
    if (dir == FIELD_PLAYER_NOGRID_DIR_NONE) {
        return func_021A5CA4(player, mmdl, keyTrg, keyCont, dir, forced);
    }
    hitBits = func_021A5B6C(player, mmdl, dir, 0);
    if (forced == 1 && (hitBits & 2)) {
        hitBits = 0;
    }
    if (hitBits == 0) {
        return FIELD_PLAYER_NOGRID_ACTION_WALK;
    }
    if (hitBits & 2) {
        func_0219E664(mmdl, dir, &nextLocation);
        attr = func_0219D724(mmdl, &nextLocation);
        ledgeDir = FIELD_PLAYER_NOGRID_DIR_NONE;
        attrKind = func_021AB0F0(attr);
        func_021AB0F8(attr);
        if (func_021AB158(attrKind)) {
            ledgeDir = 0;
        } else if (func_021AB164(attrKind)) {
            ledgeDir = 1;
        } else if (func_021AB170(attrKind)) {
            ledgeDir = 2;
        } else if (func_021AB17C(attrKind)) {
            ledgeDir = 3;
        }
        if (ledgeDir != FIELD_PLAYER_NOGRID_DIR_NONE && ledgeDir == dir) {
            return FIELD_PLAYER_NOGRID_ACTION_LEDGE_JUMP;
        }
    }
    return FIELD_PLAYER_NOGRID_ACTION_BLOCKED;
}


/* Walk kind, model turning. */
int func_021A5DD8(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced)
{
    if (func_0216D3CC(mmdl) == 0) {
        return FIELD_PLAYER_NOGRID_ACTION_NONE;
    }
    if (dir == FIELD_PLAYER_NOGRID_DIR_NONE) {
        return func_021A5CA4(player, mmdl, keyTrg, keyCont, dir, forced);
    }
    return func_021A5D04(player, mmdl, keyTrg, keyCont, dir, forced);
}


/* Walk kind, model walking into a wall: a new direction frees the command first. */
int func_021A5E28(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced)
{
    int facing = func_0216D5F8(mmdl);
    if (dir != FIELD_PLAYER_NOGRID_DIR_NONE && dir != facing) {
        func_0216D4B4(mmdl);
        return func_021A5D04(player, mmdl, keyTrg, keyCont, dir, forced);
    }
    if (func_0216D3CC(mmdl) == 0) {
        return FIELD_PLAYER_NOGRID_ACTION_NONE;
    }
    if (dir == FIELD_PLAYER_NOGRID_DIR_NONE) {
        return func_021A5CA4(player, mmdl, keyTrg, keyCont, dir, forced);
    }
    return func_021A5D04(player, mmdl, keyTrg, keyCont, dir, forced);
}


/* Walk kind, no action. */
void func_021A5EA0(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, int dir, int forced)
{
}


/* Walk kind, stand: face the direction (the model's own one when no key). */
void func_021A5EA4(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced)
{
    if (dir == FIELD_PLAYER_NOGRID_DIR_NONE) {
        dir = func_0216D5F8(mmdl);
    }
    func_0216D410(mmdl, func_02197E7C(dir, 0));
    player->moveMode = FIELD_PLAYER_NOGRID_MODE_STAND;
    func_021A3964(player->core, 0);
}


/* Walk kind, step: forced step, run (B held) or walk. */
void func_021A5EDC(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced)
{
    int acmdBase;
    if (forced == 1) {
        acmdBase = 0x14;
    } else if (keyCont & 2) {
        acmdBase = 0x58;
    } else {
        acmdBase = 0xc;
    }
    func_0216D410(mmdl, func_02197E7C(dir, acmdBase));
    player->moveMode = FIELD_PLAYER_NOGRID_MODE_WALK;
    func_021A3964(player->core, 1);
}


void func_021A5F14(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced)
{
    func_0216D410(mmdl, func_02197E7C(dir, 0x28));
    player->moveMode = FIELD_PLAYER_NOGRID_MODE_TURN;
    func_021A3964(player->core, 2);
}


/* Walk kind, blocked: bump animation; the bump sound plays when the map has no connection there. */
void func_021A5F38(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced)
{
    func_0216D410(mmdl, func_02197E7C(dir, 0x1c));
    player->moveMode = FIELD_PLAYER_NOGRID_MODE_BLOCKED;
    func_021A3964(player->core, 0);
    if (func_021A6C6C(player, dir) == 0) {
        func_020061E4(0x55a);
    }
}


void func_021A5F74(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced)
{
    func_0216D410(mmdl, func_02197E7C(dir, 0x38));
    player->moveMode = FIELD_PLAYER_NOGRID_MODE_WALK;
    func_021A3964(player->core, 1);
}


void func_021A5F98(FieldPlayerNogrid *player, u32 action, u32 keyTrg, u32 keyCont, u16 dir, u32 forced)
{
    Mmdl *mmdl = player->mmdl;
    switch (action) {
    case 0: func_021A6278(player, mmdl, keyTrg, keyCont, dir, forced); break;
    case 1: func_021A627C(player, mmdl, keyTrg, keyCont, dir, forced); break;
    case 2: func_021A62B4(player, mmdl, keyTrg, keyCont, dir, forced); break;
    case 3: func_021A62D8(player, mmdl, keyTrg, keyCont, dir, forced); break;
    case 4: func_021A62FC(player, mmdl, keyTrg, keyCont, dir, forced); break;
    case 5: func_021A6338(player, mmdl, keyTrg, keyCont, dir, forced); break;
    }
}


int func_021A6014(FieldPlayerNogrid *player, int keyTrg, int keyCont, u16 dir, int forced)
{
    int mode = player->moveMode;
    int action = 0;
    Mmdl *mmdl = player->mmdl;
    switch (mode) {
    case 0: action = func_021A607C(player, mmdl, keyTrg, keyCont, dir, forced); break;
    case 1: action = func_021A60DC(player, mmdl, keyTrg, keyCont, dir, forced); break;
    case 2: action = func_021A61B0(player, mmdl, keyTrg, keyCont, dir, forced); break;
    case 3: action = func_021A6200(player, mmdl, keyTrg, keyCont, dir, forced); break;
    }
    return action;
}


/* Slow kind, same checks as the walk kind. */
int func_021A607C(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced)
{
    if (func_0216D3CC(mmdl) == 1) {
        if (dir != FIELD_PLAYER_NOGRID_DIR_NONE) {
            if (dir != func_0216D5F8(mmdl) && forced == 0) {
                return FIELD_PLAYER_NOGRID_ACTION_TURN;
            }
            return func_021A60DC(player, mmdl, keyTrg, keyCont, dir, forced);
        }
        return FIELD_PLAYER_NOGRID_ACTION_STAND;
    }
    return FIELD_PLAYER_NOGRID_ACTION_NONE;
}


int func_021A60DC(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced)
{
    RailLocation nextLocation;
    u32 hitBits;
    u32 attr;
    u16 attrKind;
    int ledgeDir;

    if (func_0216D3CC(mmdl) == 0) {
        return FIELD_PLAYER_NOGRID_ACTION_NONE;
    }
    if (dir == FIELD_PLAYER_NOGRID_DIR_NONE) {
        return func_021A607C(player, mmdl, keyTrg, keyCont, dir, forced);
    }
    hitBits = func_021A5B6C(player, mmdl, dir, 0);
    if (forced == 1 && (hitBits & 2)) {
        hitBits = 0;
    }
    if (hitBits == 0) {
        return FIELD_PLAYER_NOGRID_ACTION_WALK;
    }
    if (hitBits & 2) {
        func_0219E664(mmdl, dir, &nextLocation);
        attr = func_0219D724(mmdl, &nextLocation);
        ledgeDir = FIELD_PLAYER_NOGRID_DIR_NONE;
        attrKind = func_021AB0F0(attr);
        func_021AB0F8(attr);
        if (func_021AB158(attrKind)) {
            ledgeDir = 0;
        } else if (func_021AB164(attrKind)) {
            ledgeDir = 1;
        } else if (func_021AB170(attrKind)) {
            ledgeDir = 2;
        } else if (func_021AB17C(attrKind)) {
            ledgeDir = 3;
        }
        if (ledgeDir != FIELD_PLAYER_NOGRID_DIR_NONE && ledgeDir == dir) {
            return FIELD_PLAYER_NOGRID_ACTION_LEDGE_JUMP;
        }
    }
    return FIELD_PLAYER_NOGRID_ACTION_BLOCKED;
}


int func_021A61B0(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced)
{
    if (func_0216D3CC(mmdl) == 0) {
        return FIELD_PLAYER_NOGRID_ACTION_NONE;
    }
    if (dir == FIELD_PLAYER_NOGRID_DIR_NONE) {
        return func_021A607C(player, mmdl, keyTrg, keyCont, dir, forced);
    }
    return func_021A60DC(player, mmdl, keyTrg, keyCont, dir, forced);
}


int func_021A6200(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced)
{
    int facing = func_0216D5F8(mmdl);
    if (dir != FIELD_PLAYER_NOGRID_DIR_NONE && dir != facing) {
        func_0216D4B4(mmdl);
        return func_021A60DC(player, mmdl, keyTrg, keyCont, dir, forced);
    }
    if (func_0216D3CC(mmdl) == 0) {
        return FIELD_PLAYER_NOGRID_ACTION_NONE;
    }
    if (dir == FIELD_PLAYER_NOGRID_DIR_NONE) {
        return func_021A607C(player, mmdl, keyTrg, keyCont, dir, forced);
    }
    return func_021A60DC(player, mmdl, keyTrg, keyCont, dir, forced);
}


/* Slow kind, no action. */
void func_021A6278(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, int dir, int forced)
{
}


void func_021A627C(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced)
{
    if (dir == FIELD_PLAYER_NOGRID_DIR_NONE) {
        dir = func_0216D5F8(mmdl);
    }
    func_0216D410(mmdl, func_02197E7C(dir, 0));
    player->moveMode = FIELD_PLAYER_NOGRID_MODE_STAND;
    func_021A3964(player->core, 0);
}


void func_021A62B4(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced)
{
    func_0216D410(mmdl, func_02197E7C(dir, 0x14));
    player->moveMode = FIELD_PLAYER_NOGRID_MODE_WALK;
    func_021A3964(player->core, 1);
}


void func_021A62D8(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced)
{
    func_0216D410(mmdl, func_02197E7C(dir, 0x28));
    player->moveMode = FIELD_PLAYER_NOGRID_MODE_TURN;
    func_021A3964(player->core, 2);
}


void func_021A62FC(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced)
{
    func_0216D410(mmdl, func_02197E7C(dir, 0x1c));
    player->moveMode = FIELD_PLAYER_NOGRID_MODE_BLOCKED;
    func_021A3964(player->core, 0);
    if (func_021A6C6C(player, dir) == 0) {
        func_020061E4(0x55a);
    }
}


void func_021A6338(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced)
{
    func_0216D410(mmdl, func_02197E7C(dir, 0x38));
    player->moveMode = FIELD_PLAYER_NOGRID_MODE_WALK;
    func_021A3964(player->core, 1);
}


void func_021A635C(FieldPlayerNogrid *player, int action, int keyTrg, int keyCont, u16 dir, int forced)
{
    Mmdl *mmdl = func_021A3960(player->core);
    switch (action) {
    case 0: func_021A63EC(player, mmdl, keyTrg, keyCont, dir, forced); break;
    case 1: func_021A63F0(player, mmdl, keyTrg, keyCont, dir, forced); break;
    case 2: func_021A6428(player, mmdl, keyTrg, keyCont, dir, forced); break;
    case 3: func_021A6454(player, mmdl, keyTrg, keyCont, dir, forced); break;
    case 4: func_021A6478(player, mmdl, keyTrg, keyCont, dir, forced); break;
    }
}


/* Rail kind, no action. */
void func_021A63EC(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, int dir, int forced)
{
}


void func_021A63F0(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced)
{
    if (dir == FIELD_PLAYER_NOGRID_DIR_NONE) {
        dir = func_0216D5F8(mmdl);
    }
    func_0216D410(mmdl, func_02197E7C(dir, 0));
    player->moveMode = FIELD_PLAYER_NOGRID_MODE_STAND;
    func_021A3964(player->core, 0);
}


void func_021A6428(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced)
{
    func_0216D410(mmdl, func_02197E7C(dir, (forced == 1) ? 0x14 : 0x10));
    player->moveMode = FIELD_PLAYER_NOGRID_MODE_WALK;
    func_021A3964(player->core, 1);
}


void func_021A6454(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced)
{
    func_0216D410(mmdl, func_02197E7C(dir, 0x28));
    player->moveMode = FIELD_PLAYER_NOGRID_MODE_TURN;
    func_021A3964(player->core, 2);
}


void func_021A6478(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced)
{
    func_0216D410(mmdl, func_02197E7C(dir, 0x1c));
    player->moveMode = FIELD_PLAYER_NOGRID_MODE_BLOCKED;
    func_021A3964(player->core, 0);
    if (func_021A6C6C(player, dir) == 0) {
        func_020061E4(0x55a);
    }
}


/* Check for the rail kinds: by the running mode, on the core's model. */
int func_021A64B4(FieldPlayerNogrid *player, int keyTrg, int keyCont, u16 dir, int forced)
{
    Mmdl *mmdl = func_021A3960(player->core);
    int action = 0;
    switch (player->moveMode) {
    case 0: action = func_021A652C(player, mmdl, keyTrg, keyCont, dir, forced); break;
    case 1: action = func_021A658C(player, mmdl, keyTrg, keyCont, dir, forced); break;
    case 2: action = func_021A661C(player, mmdl, keyTrg, keyCont, dir, forced); break;
    case 3: action = func_021A666C(player, mmdl, keyTrg, keyCont, dir, forced); break;
    }
    return action;
}


int func_021A652C(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced)
{
    if (func_0216D3CC(mmdl) == 1) {
        if (dir != FIELD_PLAYER_NOGRID_DIR_NONE) {
            if (dir != func_0216D5F8(mmdl) && forced == 0) {
                return FIELD_PLAYER_NOGRID_ACTION_TURN;
            }
            return func_021A658C(player, mmdl, keyTrg, keyCont, dir, forced);
        }
        return FIELD_PLAYER_NOGRID_ACTION_STAND;
    }
    return FIELD_PLAYER_NOGRID_ACTION_NONE;
}


/* Rail kind, step check: the next tile's attribute decides between walk and bump. */
int func_021A658C(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced)
{
    int hitBits;
    int attr;
    if (func_0216D3CC(mmdl) == 0) {
        return FIELD_PLAYER_NOGRID_ACTION_NONE;
    }
    if (dir == FIELD_PLAYER_NOGRID_DIR_NONE) {
        return func_021A652C(player, mmdl, keyTrg, keyCont, dir, forced);
    }
    hitBits = func_021A5B6C(player, mmdl, dir, &attr);
    if (forced == 1 && hitBits != 0 && (hitBits & 0x10) == 0) {
        hitBits = 0;
    }
    if (attr != -1) {
        int attrBits;
        func_021AB0F0(attr);
        attrBits = func_021AB0F8(attr);
        if (hitBits == 0) {
            if (attrBits & 2) {
                return FIELD_PLAYER_NOGRID_ACTION_WALK;
            }
            if (forced == 1) {
                return FIELD_PLAYER_NOGRID_ACTION_WALK;
            }
        }
    }
    return FIELD_PLAYER_NOGRID_ACTION_BLOCKED;
}


int func_021A661C(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced)
{
    if (func_0216D3CC(mmdl) == 0) {
        return FIELD_PLAYER_NOGRID_ACTION_NONE;
    }
    if (dir == FIELD_PLAYER_NOGRID_DIR_NONE) {
        return func_021A652C(player, mmdl, keyTrg, keyCont, dir, forced);
    }
    return func_021A658C(player, mmdl, keyTrg, keyCont, dir, forced);
}


u32 func_021A666C(FieldPlayerNogrid *player, Mmdl *mmdl, u32 keyTrg, u32 keyCont, u16 dir, u32 forced)
{
    u32 facing = func_0216D5F8(mmdl);

    if (dir != FIELD_PLAYER_NOGRID_DIR_NONE && dir != facing) {
        func_0216D4B4(mmdl);
        return func_021A658C(player, mmdl, keyTrg, keyCont, dir, forced);
    }
    if (!func_0216D3CC(mmdl))
        return FIELD_PLAYER_NOGRID_ACTION_NONE;
    if (dir == FIELD_PLAYER_NOGRID_DIR_NONE)
        return func_021A652C(player, mmdl, keyTrg, keyCont, dir, forced);
    return func_021A658C(player, mmdl, keyTrg, keyCont, dir, forced);
}


void func_021A66E4(FieldPlayerNogrid *player, u32 mask)
{
    player->flags |= mask;
}


void func_021A66EC(FieldPlayerNogrid *player, u32 mask)
{
    player->flags &= ~mask;
}


int func_021A66F8(FieldPlayerNogrid *player, int mask)
{
    if (player->flags & mask) {
        return 1;
    }
    return 0;
}


void func_021A6708(FieldPlayerNogrid *player)
{
    func_021A66E4(player, FIELD_PLAYER_NOGRID_FLAG_FORCED_MOVE);
}


void func_021A6714(FieldPlayerNogrid *player)
{
    func_021A66EC(player, FIELD_PLAYER_NOGRID_FLAG_FORCED_MOVE);
}


void func_021A6720(FieldPlayerNogrid *player)
{
    func_021A66E4(player, FIELD_PLAYER_NOGRID_FLAG_FORCED_MOVE_ENDED);
}


void func_021A672C(FieldPlayerNogrid *player)
{
    func_021A66EC(player, FIELD_PLAYER_NOGRID_FLAG_FORCED_MOVE_ENDED);
}


void func_021A6738(FieldPlayerNogrid *player)
{
    func_021A66EC(player, FIELD_PLAYER_NOGRID_FLAG_PENDING);
}


void func_021A6744(FieldPlayerNogrid *player)
{
    func_021A66E4(player, FIELD_PLAYER_NOGRID_FLAG_SPIN_A);
}


void func_021A6750(FieldPlayerNogrid *player)
{
    func_021A66EC(player, FIELD_PLAYER_NOGRID_FLAG_SPIN_A);
}


void func_021A675C(FieldPlayerNogrid *player)
{
    func_021A66E4(player, FIELD_PLAYER_NOGRID_FLAG_SPIN_B);
}


void func_021A6768(FieldPlayerNogrid *player)
{
    func_021A66EC(player, FIELD_PLAYER_NOGRID_FLAG_SPIN_B);
}


void func_021A6774(FieldPlayerNogrid *player)
{
    func_021A66E4(player, FIELD_PLAYER_NOGRID_FLAG_FACE_RIGHT);
}


void func_021A6780(FieldPlayerNogrid *player)
{
    func_021A66EC(player, FIELD_PLAYER_NOGRID_FLAG_FACE_RIGHT);
}


void func_021A678C(FieldPlayerNogrid *player)
{
    func_021A66E4(player, FIELD_PLAYER_NOGRID_FLAG_INPUT_HOLD);
}


void func_021A6798(FieldPlayerNogrid *player)
{
    func_021A66EC(player, FIELD_PLAYER_NOGRID_FLAG_INPUT_HOLD);
}


/* Reads the tile under the model; returns the forced move kind (an index of the
 * handler table, 0 for none). */
u32 func_021A67A4(FieldPlayerNogrid *player)
{
    u32 attr = func_0216D7DC(player->mmdl);

    if (!func_021A66F8(player, FIELD_PLAYER_NOGRID_FLAG_FORCED_MOVE_ENDED)) {
        attr = func_021AB0F0(attr);
        if (func_021AB348(attr) == 1)
            return 1;
        if (func_021BB1AC(attr) == 1)
            return 2;
        if (func_021BB1B8(attr) == 1)
            return 3;
        if (func_021BB1C4(attr) == 1)
            return 4;
        if (func_021BB1D0(attr) == 1)
            return 5;
        if (func_021BB1DC(attr) == 1)
            return 6;
        if (func_021BB1E8(attr) == 1)
            return 7;
    }
    return 0;
}


/* Runs the forced move of the tile under the model, or ends a running one. */
u32 func_021A682C(FieldPlayerNogrid *player, u32 dir, u32 skipTileKind)
{
    u32 kind;

    if (!func_0216D3CC(player->mmdl))
        return dir;
    if (skipTileKind == 0) {
        kind = func_021A67A4(player);
        if (kind != 0)
            return data_021D8AB8[kind](player, dir, skipTileKind);
    }
    func_021A6870(player);
    return dir;
}


/* Ends every forced move state that is set. */
void func_021A6870(FieldPlayerNogrid *player)
{
    Mmdl *mmdl = player->mmdl;

    if (func_021A66F8(player, 0x59))
        func_0216D550(mmdl, 0x18);
    if (func_021A66F8(player, FIELD_PLAYER_NOGRID_FLAG_FORCED_MOVE)) {
        func_021A6714(player);
        func_021A6720(player);
        func_021A3964(player->core, 0);
    }
    if (func_021A66F8(player, 0x18)) {
        func_021A6750(player);
        func_021A6768(player);
        func_0216D60C(mmdl, func_021642A4(func_0216D608(mmdl)));
    }
    if (func_021A66F8(player, FIELD_PLAYER_NOGRID_FLAG_FACE_RIGHT)) {
        func_021A6780(player);
        func_0216D60C(mmdl, 3);
    }
    if (func_021A66F8(player, FIELD_PLAYER_NOGRID_FLAG_INPUT_HOLD)) {
        func_021A6798(player);
        func_021A6BAC(&player->inputHold);
    }
}


/* Forced move: keep sliding in the model's move direction until blocked. */
u32 func_021A6908(FieldPlayerNogrid *player, u32 dir, u32 skipTileKind)
{
    Mmdl *mmdl = player->mmdl;
    u32 moveDir = func_0216D608(mmdl);

    if (func_021A5B6C(player, mmdl, moveDir, 0)) {
        func_021A6870(player);
        return dir;
    }
    func_021A6708(player);
    func_021A6750(player);
    func_021A6768(player);
    func_0216D5E0(mmdl, moveDir);
    func_0216D410(mmdl, func_02197E7C(moveDir, 0x10));
    func_0216D548(mmdl, 0x18);
    player->moveMode = FIELD_PLAYER_NOGRID_MODE_WALK;
    func_021A3964(player->core, 1);
    return moveDir;
}


/* Forced move: slide with the first spin animation. */
u32 func_021A6974(FieldPlayerNogrid *player, u32 dir)
{
    Mmdl *mmdl = player->mmdl;
    u32 moveDir = func_0216D608(mmdl);

    if (func_021A5B6C(player, mmdl, moveDir, 0)) {
        func_021A6870(player);
        return dir;
    }
    func_021A6708(player);
    func_021A6744(player);
    func_021A6768(player);
    func_0216D410(mmdl, func_02197E7C(moveDir, 0x10));
    func_0216D548(mmdl, 0x18);
    player->moveMode = FIELD_PLAYER_NOGRID_MODE_WALK;
    func_021A3964(player->core, 1);
    return moveDir;
}


/* Forced move: slide with the second spin animation. */
u32 func_021A69D8(FieldPlayerNogrid *player, u32 dir)
{
    Mmdl *mmdl = player->mmdl;
    u32 moveDir = func_0216D608(mmdl);

    if (func_021A5B6C(player, mmdl, moveDir, 0)) {
        func_021A6870(player);
        return dir;
    }
    func_021A6708(player);
    func_021A675C(player);
    func_021A6750(player);
    func_0216D410(mmdl, func_02197E7C(moveDir, 0x10));
    func_0216D548(mmdl, 0x18);
    player->moveMode = FIELD_PLAYER_NOGRID_MODE_WALK;
    func_021A3964(player->core, 1);
    return moveDir;
}


/* Forced move: a slide that the model must not enter with move direction 2. */
int func_021A6A3C(FieldPlayerNogrid *player, int dir, int skipTileKind)
{
    if (func_0216D608(player->mmdl) == 2) {
        func_020061E4(0x55e);
    }
    return func_021A6908(player, dir, skipTileKind);
}


/* Forced move: a slide that the model must not enter with move direction 3. */
int func_021A6A64(FieldPlayerNogrid *player, int dir, int skipTileKind)
{
    if (func_0216D608(player->mmdl) == 3) {
        func_020061E4(0x55e);
    }
    return func_021A6908(player, dir, skipTileKind);
}


/* Forced move: a slide that ends facing right. */
int func_021A6A8C(FieldPlayerNogrid *player, int dir, int skipTileKind)
{
    int result = func_021A6908(player, dir, skipTileKind);
    func_021A6774(player);
    return result;
}


/* Forced move: the held direction keeps the model going while the keys are idle. */
u32 func_021A6AA0(FieldPlayerNogrid *player, u32 dir)
{
    u32 result;

    if (!func_021A66F8(player, FIELD_PLAYER_NOGRID_FLAG_INPUT_HOLD)) {
        func_021A678C(player);
        func_021A6B9C(&player->inputHold);
    }
    result = (u16)func_021A6C4C(&player->inputHold, dir);
    if (func_021A6C64(&player->inputHold)) {
        func_0216D548(player->mmdl, 0x18);
        func_0216D410(player->mmdl, func_02197E7C(result, 8));
        func_021A3964(player->core, 1);
        result = FIELD_PLAYER_NOGRID_DIR_NONE;
    } else {
        func_0216D550(player->mmdl, 0x18);
    }
    return result;
}


/* Starts the spin animation of a variant (or keeps it running). */
void func_021A6B08(NogridSpin *spin, u8 variant)
{
    if (spin->active != 1 || variant != spin->variant) {
        func_020061E4(0x6d1);
        spin->active = 1;
        spin->variant = variant;
        spin->phase = 0;
    }
}


void func_021A6B30(NogridSpin *spin)
{
    if (spin->active) {
        spin->active = 0;
        spin->phase = 0;
        func_020061F8(func_02006148(0x6d1));
    }
}


/* Turns the model to the next direction of the spin sequence. */
void func_021A6B50(NogridSpin *spin, Mmdl *mmdl)
{
    if (spin->active) {
        spin->phase = (spin->phase + 1) % 4;
        func_0216D5D8(mmdl, d_021D8AB0[spin->variant][spin->phase]);
    }
}


int func_021A6B88(NogridInputHold *hold)
{
    func_02082BCC(hold, 0, 8);
    hold->heldDir = FIELD_PLAYER_NOGRID_DIR_NONE;
    return 9;
}


void func_021A6B9C(NogridInputHold *hold)
{
    hold->enabled = 1;
}


int func_021A6BAC(NogridInputHold *hold)
{
    return func_021A6B88(hold);
}


/* Counts the frames without a direction key; after 30 the hold is armed. */
void func_021A6BB4(NogridInputHold *hold, u32 dir, Mmdl *mmdl)
{
    if (hold->enabled) {
        if (hold->idleDone != 0) {
            if (dir != FIELD_PLAYER_NOGRID_DIR_NONE) {
                hold->idleFrames = 0;
                hold->idleDone = 0;
                if (hold->keepDir)
                    hold->heldDir = dir;
            }
        } else if (dir == FIELD_PLAYER_NOGRID_DIR_NONE) {
            if (hold->idleFrames < 30)
                hold->idleFrames = hold->idleFrames + 1;
            else
                hold->idleDone = 1;
        }
        if (func_0216D3CC(mmdl) == 1) {
            if (hold->idleDone == 0) {
                hold->keepDir = 0;
                hold->held = 0;
            } else {
                hold->keepDir = 1;
                hold->held = 1;
            }
        }
    }
}


void func_021A6C30(NogridInputHold *hold)
{
    if (hold->held) {
        hold->held = 0;
    }
    if (!hold->keepDir) {
        hold->heldDir = FIELD_PLAYER_NOGRID_DIR_NONE;
    }
}


int func_021A6C4C(NogridInputHold *hold, int dir)
{
    int result;
    if (hold->held) {
        return 1;
    }
    result = hold->heldDir;
    if (result == FIELD_PLAYER_NOGRID_DIR_NONE) {
        result = dir;
    }
    return result;
}


u32 func_021A6C64(NogridInputHold *hold)
{
    return hold->keepDir;
}


/* True when the map has a connection at the tile ahead of the model in a direction. */
int func_021A6C6C(FieldPlayerNogrid *player, u32 dir)
{
    RailLocation location;
    Mmdl *mmdl = func_021A3960(player->core);
    void *eventData;

    eventData = func_02012844(func_020120F4(func_02188C80(player->fieldMap)));
    func_0219E664(mmdl, dir, &location);
    return func_02162598(eventData, &location) != 0xFFFF;
}
