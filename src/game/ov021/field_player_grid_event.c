/*
 * file:     field_player_grid_event.c
 * unit:     yes
 * function: func_021C0CA4, func_021C0CE4, func_021C0D08, func_021C0DDC, func_021C0E4C, func_021C0E98, func_021C1024, func_021C1094, func_021C10A0, func_021C10B4, func_021C1228, func_021C12C4, func_021C12D0, func_021C12E4, func_021C1318, func_021C146C, func_021C14F8, func_021C157C, func_021C161C, func_021C1670, func_021C16AC
 * address:  0x021C0CA4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_0216D454 0x0216D454 thumb ov010
 *   func_0216D480 0x0216D480 thumb ov010
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   _s32_div_f     0x0209C0A4  arm
 *   func_021A5728  0x021A5728  thumb  ov021
 *   func_021A572C  0x021A572C  thumb  ov021
 *   func_021A3AB8  0x021A3AB8  thumb  ov021
 *   func_021A44BC  0x021A44BC  thumb  ov021
 *   func_021A448C  0x021A448C  thumb  ov021
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_02164208  0x02164208  thumb  ov010
 *   func_0216D91C  0x0216D91C  thumb  ov010
 *   func_0216D924  0x0216D924  thumb  ov010
 *   func_021AB0D4  0x021AB0D4  thumb  ov021
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 *   func_021AB11C  0x021AB11C  thumb  ov021
 *   func_021AB2DC  0x021AB2DC  thumb  ov021
 *   func_021C19B4  0x021C19B4  thumb  ov021
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0216E5FC  0x0216E5FC  thumb  ov010
 *   func_021A395C  0x021A395C  thumb  ov021
 *   func_021639C0  0x021639C0  thumb  ov010
 *   func_021A3990  0x021A3990  thumb  ov021
 *   func_02082BCC  0x02082BCC  arm
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_021A5408  0x021A5408  thumb  ov021
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_02163E58  0x02163E58  thumb  ov010
 *   func_0216DB4C  0x0216DB4C  thumb  ov010
 *   func_0216DAE0  0x0216DAE0  thumb  ov010
 *   func_0216D89C  0x0216D89C  thumb  ov010
 *   func_0216D8E0  0x0216D8E0  thumb  ov010
 *   func_0216E014  0x0216E014  thumb  ov010
 *   func_0216E57C  0x0216E57C  thumb  ov010
 *   func_02030734  0x02030734  arm
 *   d_021DE3AC     0x021DE3AC  data  ov021  a4
 *   func_021A3068  0x021A3068  thumb  ov021
 *   func_021A36E0  0x021A36E0  thumb  ov021
 *   func_021AB2E8  0x021AB2E8  thumb  ov021
 *   func_02188D30  0x02188D30  thumb  ov021
 *   func_02030DA8  0x02030DA8  arm
 *   func_02030EE8  0x02030EE8  arm
 *   func_02030EAC  0x02030EAC  arm
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_02164280  0x02164280  thumb  ov010
 *   func_021ACB38  0x021ACB38  thumb  ov021
 *   func_021A2F8C  0x021A2F8C  thumb  ov021
 *   func_02188CE8  0x02188CE8  thumb  ov021
 *   func_021AA900  0x021AA900  thumb  ov021
 *   func_021AAB1C  0x021AAB1C  thumb  ov021
 *   func_021A2F98  0x021A2F98  thumb  ov021
 *   func_021ACBB8  0x021ACBB8  thumb  ov021
 *   func_021A2F48  0x021A2F48  thumb  ov021
 *   func_021A2F54  0x021A2F54  thumb  ov021
 *   func_021A35A0  0x021A35A0  thumb  ov021
 *   func_021C1988  0x021C1988  thumb  ov021
 *   func_021ABE30  0x021ABE30  thumb  ov021
 *   func_021AD564  0x021AD564  thumb  ov021
 *   func_021C6B18  0x021C6B18  thumb  ov021
 *   func_021AC154  0x021AC154  thumb  ov021
 *   func_0209C0A4  0x0209C0A4  arm
 *   func_021AD5CC  0x021AD5CC  thumb  ov021
 *   func_021ABE64  0x021ABE64  thumb  ov021
 */
#include "../ov010/fldmmdl_types.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

typedef struct FieldPlayer FieldPlayer;
typedef struct FieldPlayerCore FieldPlayerCore;
typedef struct FieldPlayerAnim FieldPlayerAnim;
typedef struct FieldMap FieldMap;
typedef struct G3dMapper G3dMapper;
typedef struct FieldEffectSys FieldEffectSys;
typedef struct EncountSys EncountSys;
typedef struct GameSystem GameSystem;
typedef struct GameEvent GameEvent;
typedef struct TcblSys TcblSys;
typedef struct TcblTask TcblTask;

/* Event work of the boulder drop (0x24 bytes). */
typedef struct BoulderDropWork {
    FieldPlayer *player;
    u16 dir;
    u16 fillsHole;       /* 1 when the boulder covers the whole hole */
    s16 frame;
    u8 pad0A[2];
    int targetY;         /* height the boulder sinks to */
    MmdlVec drawOffset;  /* wobble of the boulder while it sinks; y moves */
    Mmdl *boulder;
    Mmdl *playerMmdl;
} BoulderDropWork;

/* Task work of the hop (0x18 bytes). */
typedef struct HopWork {
    u16 state;
    s16 frame;
    u16 done;
    u16 startDir;
    u16 isLong;          /* 1: moves two tiles instead of one */
    u8 pad0A[2];
    FieldMap *fieldMap;
    FieldPlayer *player;
    GameSystem *gameSystem;
} HopWork;

/* Task work of the jump up and jump down (0x4C bytes). */
typedef struct JumpWork {
    u16 targetHigher;    /* 1 when the landing tile is higher */
    s16 state;
    u16 dir;
    u16 done;
    u16 frame;
    u8 pad0A[6];
    int gravity;
    u8 pad14[4];
    MmdlVec drawOffset;
    MmdlVec target;      /* landing position */
    int stepX;
    int velocityY;
    int stepZ;
    FieldPlayer *player;
    FieldMap *fieldMap;
    GameSystem *gameSystem;
    u32 effectHandle;
} JumpWork;

extern void func_020061E4(u32 seId);
extern GameEvent *func_020122C0(GameSystem *gameSystem, GameEvent *parent, int (*func)(), u32 workSize);
extern void *func_020124E8(GameEvent *event);
extern void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short tag);
extern u32 func_020307B0(void *block);
extern void func_02030DA8(TcblSys *tcblSys, void (*func)(), void *work, u32 priority);
extern void *func_02030EE8(TcblTask *task);
extern u32 func_02030EAC(TcblTask *task);
extern void func_02082BCC(void *dst, int value, int size);
extern int func_0209C0A4(int dividend, int divisor);
extern void func_02163E58(Mmdl *mmdl, MmdlVec *pos, int *outHeight);
extern u32 func_021639C0(Mmdl *mmdl, u32 dir);
extern void func_02164208(int dir, MmdlVec *pos, int amount);
extern void func_02164280(int x, int z, MmdlVec *out);
extern int func_0216D3CC(Mmdl *mmdl);
extern void func_0216D410(Mmdl *mmdl, u32 acmd);
extern int func_0216D454(Mmdl *mmdl);
extern int func_0216D480(Mmdl *mmdl);
extern u16 func_0216D598(Mmdl *mmdl);
extern u16 func_0216D5F8(Mmdl *mmdl);
extern int func_0216D83C(Mmdl *mmdl);
extern int func_0216D86C(Mmdl *mmdl);
extern void func_0216D88C(const Mmdl *mmdl, MmdlVec *out);
extern void func_0216D89C(Mmdl *mmdl, const MmdlVec *pos);
extern void func_0216D8E0(Mmdl *mmdl, const MmdlVec *offset);
extern u8 func_0216D91C(const Mmdl *mmdl);
extern u8 func_0216D924(const Mmdl *mmdl);
extern void func_0216DAE0(Mmdl *mmdl, unsigned int value);
extern int func_0216DB4C(Mmdl *mmdl, int value);
extern void func_0216E014(Mmdl *mmdl, MmdlVec *pos, int dir);
extern void func_0216E57C(Mmdl *mmdl);
extern int func_0216E5FC(u16 objCode);
extern G3dMapper *func_02188C98(FieldMap *fieldMap);
extern FieldEffectSys *func_02188CD0(FieldMap *fieldMap);
extern EncountSys *func_02188CE8(FieldMap *fieldMap);
extern TcblSys *func_02188D30(FieldMap *fieldMap);
extern int func_02197E7C(int dir, int base);
extern void func_021A2F48(FieldPlayer *player, u32 value);
extern int func_021A2F54(FieldPlayer *player);
extern void func_021A2F8C(FieldPlayer *player, u32 value);
extern FieldPlayerAnim *func_021A2F98(FieldPlayer *player);
extern FieldMap *func_021A3068(FieldPlayer *player);
extern Mmdl *func_021A3074(FieldPlayer *player);
extern void func_021A35A0(FieldPlayer *player, int value);
extern GameSystem *func_021A36E0(FieldPlayer *player);
extern FieldMap *func_021A395C(FieldPlayerCore *core);
extern void *func_021A3960(FieldPlayerCore *core);
extern GameSystem *func_021A3990(FieldPlayerCore *core);
extern u16 func_021A3AB8(FieldPlayerCore *core, u32 keyDir);
extern int func_021A448C(FieldPlayer *player, u32 dir);
extern int func_021A44BC(FieldPlayer *player, int dir);
extern int func_021A5408(FieldPlayer *player);
extern FieldPlayerCore *func_021A5728(FieldPlayer *player);
extern void *func_021A572C(FieldPlayer *player);
extern int func_021AA900(EncountSys *encount, short *tile);
extern void func_021AAB1C(EncountSys *encount, int value);
extern int func_021AB0D4(G3dMapper *map, const MmdlVec *pos);
extern u16 func_021AB0F0(u32 attr);
extern int func_021AB11C(u32 attr);
extern int func_021AB2DC(u16 id);
extern int func_021AB2E8(int id);
extern void func_021ABE30(FieldEffectSys *effects, int *effectId, int value);
extern void func_021ABE64(FieldEffectSys *effects, int effectId);
extern void func_021AC154(u32 handle);
extern u32 func_021ACB38(FieldEffectSys *effects, u32 dir, MmdlVec *pos, Mmdl *mmdl, int value);
extern void func_021ACBB8(FieldPlayerAnim *anim, u8 value);
extern u32 func_021AD564(FieldEffectSys *effects, u32 kind, FieldPlayerAnim *anim);
extern int func_021AD5CC(u32 handle);
extern void func_021C1988(void *work, u16 *state);
extern Mmdl *func_021C19B4(FieldPlayer *player, u32 dir);
extern void func_021C6B18(FieldMap *fieldMap, u16 kind, u32 value);
extern u8 d_021DE3AC;

int func_021C0CA4(FieldPlayer *player, int unused, int keyDir, int flags);
int func_021C0CE4(FieldPlayer *player, u32 dir, u32 flags);
int func_021C0D08(Mmdl *boulder, u32 dir, G3dMapper *map);
int func_021C0DDC(FieldPlayer *player, u32 dir, int hitResult);
GameEvent *func_021C0E4C(FieldPlayer *player, u32 dir, Mmdl *boulder, u32 fillsHole);
int func_021C0E98(GameEvent *event, int *seq, BoulderDropWork *work);
void func_021C1024(FieldPlayer *player, u16 dir, u32 attr, u32 heapId);
int func_021C1094(TcblTask *task);
int func_021C10A0(TcblTask *task);
void func_021C10B4(TcblTask *task, HopWork *work);
void func_021C1228(FieldPlayer *player, u16 dir, u32 attr, u32 heapId);
int func_021C12C4(TcblTask *task);
void func_021C12D0(TcblTask *task);
void func_021C12E4(Mmdl *mmdl, const MmdlVec *offset);
int func_021C1318(JumpWork *work);
int func_021C146C(JumpWork *work);
int func_021C14F8(JumpWork *work);
int func_021C157C(JumpWork *work);
int func_021C161C(JumpWork *work);
int func_021C1670(JumpWork *work);
void func_021C16AC(JumpWork *work);

/*
 * Tries to start the boulder drop for the tile the player faces.
 */
int func_021C0CA4(FieldPlayer *player, int unused, int keyDir, int flags)
{
    FieldPlayerCore *core;
    int dir;
    int result;

    core = func_021A5728(player);
    func_021A572C(player);
    dir = func_021A3AB8(core, keyDir);
    if (func_021A44BC(player, dir) == 0)
        return 0;
    result = func_021C0CE4(player, dir, flags);
    if (result == 0)
        return 0;
    return result;
}

/*
 * Runs the boulder drop check when bit 0 of the flags is set.
 */
int func_021C0CE4(FieldPlayer *player, u32 dir, u32 flags)
{
    int result = 0;
    int hitResult = func_021A448C(player, dir);
    if (flags & 1)
        result = func_021C0DDC(player, dir, hitResult);
    return result;
}

/*
 * Classifies the tiles under the boulder destination: 1 when a tile
 * blocks it, 0 when no tile is a hole, 3 when all tiles are holes and 2
 * when only some are.
 */
int func_021C0D08(Mmdl *boulder, u32 dir, G3dMapper *map)
{
    MmdlVec pos;
    MmdlVec cur;
    int hasOtherTile;
    int hasHoleTile;
    u8 row;
    u8 depth;
    u8 width;
    u8 col;
    u32 attr;
    u16 id;

    func_0216D88C(boulder, &pos);
    func_02164208(dir, &pos, 0x10000);
    width = func_0216D91C(boulder);
    depth = func_0216D924(boulder);
    hasOtherTile = 0;
    hasHoleTile = 0;
    for (row = 0; row < depth; row++, pos.z -= 0x10000) {
        cur = pos;
        for (col = 0; col < width; col++, cur.x += 0x10000) {
            attr = func_021AB0D4(map, &cur);
            id = func_021AB0F0(attr);
            if (func_021AB11C(attr)) {
                if (func_021AB2DC(id) == 0)
                    return 1;
                hasHoleTile = 1;
            } else {
                hasOtherTile = 1;
            }
        }
    }
    if (hasHoleTile == 1) {
        if (hasOtherTile == 0)
            return 3;
        return 2;
    }
    return 0;
}

int func_021C0DDC(FieldPlayer *player, u32 dir, int hitResult)
{
    Mmdl *boulder;
    u32 coverage;
    u32 moveHit;

    if (hitResult == 1) {
        boulder = func_021C19B4(player, dir);
        if (boulder != 0) {
            if (func_0216E5FC(func_0216D598(boulder)) == 1) {
                coverage = func_021C0D08(boulder, dir, func_02188C98(func_021A395C(func_021A5728(player))));
                moveHit = func_021639C0(boulder, dir);
                moveHit &= ~1;
                if ((moveHit & 2) && coverage - 2 <= 1)
                    moveHit &= ~2;
                if (moveHit == 0) {
                    int fillsHole = 0;
                    if (coverage == 3)
                        fillsHole = 1;
                    return (int)func_021C0E4C(player, dir, boulder, fillsHole);
                }
            }
        }
    }
    return 0;
}

GameEvent *func_021C0E4C(FieldPlayer *player, u32 dir, Mmdl *boulder, u32 fillsHole)
{
    FieldPlayerCore *core;
    GameEvent *event;
    BoulderDropWork *work;

    core = func_021A5728(player);
    event = func_020122C0(func_021A3990(core), 0, func_021C0E98, sizeof(BoulderDropWork));
    work = func_020124E8(event);
    func_02082BCC(work, 0, sizeof(BoulderDropWork));
    work->player = player;
    work->dir = dir;
    work->fillsHole = fillsHole;
    work->boulder = boulder;
    work->playerMmdl = func_021A3960(core);
    return event;
}

int func_021C0E98(GameEvent *event, int *seq, BoulderDropWork *work)
{
    MmdlVec boulderPos;
    MmdlVec sinkPos;
    MmdlVec settlePos;

    switch (*seq) {
    case 0:
        if (func_0216D3CC(work->boulder) == 0)
            break;
        if (func_0216D3CC(work->playerMmdl) == 0 && func_021A5408(work->player) == 0)
            break;
        func_0216D410(work->boulder, func_02197E7C(work->dir, 8));
        func_0216D410(work->playerMmdl, func_02197E7C(work->dir, 0x20));
        func_020061E4(0x674);
        (*seq)++;
        break;
    case 1:
        if (func_0216D454(work->boulder) == 0)
            break;
        if (func_0216D454(work->playerMmdl) == 0)
            break;
        if (work->fillsHole == 0) {
            *seq = 4;
            break;
        }
        func_0216D88C(work->boulder, &boulderPos);
        func_02163E58(work->boulder, &boulderPos, &work->targetY);
        if (func_0216D598(work->boulder) == 0x6d)
            work->targetY -= 14 << 12;
        else
            work->targetY -= 26 << 12;
        func_0216DB4C(work->boulder, 1);
        func_0216DAE0(work->boulder, 0);
        func_020061E4(0x675);
        (*seq)++;
        break;
    case 2:
        func_0216D88C(work->boulder, &sinkPos);
        if (work->targetY < sinkPos.y) {
            sinkPos.y -= 0x4000;
            if (work->targetY > sinkPos.y)
                sinkPos.y = work->targetY;
        } else if (work->targetY > sinkPos.y) {
            sinkPos.y += 0x4000;
            if (work->targetY < sinkPos.y)
                sinkPos.y = work->targetY;
        }
        func_0216D89C(work->boulder, &sinkPos);
        if (work->targetY == sinkPos.y) {
            work->drawOffset.y = 0x2000;
            (*seq)++;
        }
        break;
    case 3:
        func_0216D8E0(work->boulder, &work->drawOffset);
        work->drawOffset.y = -work->drawOffset.y;
        work->frame = work->frame + 1;
        if (work->frame & 4) {
            if (work->drawOffset.y < 0)
                work->drawOffset.y += 0x1000;
            else if (work->drawOffset.y > 0)
                work->drawOffset.y -= 0x1000;
        }
        if (work->drawOffset.y == 0) {
            func_0216D88C(work->boulder, &settlePos);
            func_0216E014(work->boulder, &settlePos, work->dir);
            func_0216D8E0(work->boulder, &work->drawOffset);
            func_0216E57C(work->boulder);
            (*seq)++;
        }
        break;
    case 4:
        return 1;
    }
    return 0;
}

void func_021C1024(FieldPlayer *player, u16 dir, u32 attr, u32 heapId)
{
    HopWork *work;

    work = func_02030734((u16)(0x8000 | (heapId & 0x7fff)), sizeof(HopWork), 1, (const char *)&d_021DE3AC, 0x1e6);
    work->fieldMap = func_021A3068(player);
    work->startDir = dir;
    work->player = player;
    work->gameSystem = func_021A36E0(player);
    if (func_021AB2E8(func_021AB0F0(attr)) == 1)
        work->isLong = 1;
    func_02030DA8(func_02188D30(work->fieldMap), func_021C10B4, work, 0);
}

int func_021C1094(TcblTask *task)
{
    return ((HopWork *)func_02030EE8(task))->done;
}

int func_021C10A0(TcblTask *task)
{
    func_020307B0(func_02030EE8(task));
    return func_02030EAC(task);
}

void func_021C10B4(TcblTask *task, HopWork *work)
{
    Mmdl *mmdl;
    u16 dir;
    u32 acmd;
    int gridX;
    int gridZ;
    MmdlVec pos;
    int mapHeight;
    short tile[3];
    EncountSys *encount;
    int stepDist;

    mmdl = func_021A3074(work->player);
    switch (work->state) {
    case 0:
        dir = func_0216D5F8(mmdl);
        gridX = func_0216D83C(mmdl);
        gridZ = func_0216D86C(mmdl);
        func_0216D88C(mmdl, &pos);
        func_02164280(gridX, gridZ, &pos);
        stepDist = 0x10000;
        if (work->isLong == 1)
            stepDist = 0x20000;
        func_02164208(dir, &pos, stepDist);
        mapHeight = 0;
        func_02163E58(mmdl, &pos, &mapHeight);
        pos.y = mapHeight;
        func_021A2F8C(work->player, func_021ACB38(func_02188CD0(work->fieldMap), dir, &pos, mmdl, 0));
        encount = func_02188CE8(work->fieldMap);
        tile[0] = (pos.x >> 4) / 0x1000;
        tile[1] = (pos.y >> 4) / 0x1000;
        tile[2] = (pos.z >> 4) / 0x1000;
        if (func_021AA900(encount, tile))
            func_021AAB1C(encount, 1);
        work->state++;
        break;
    case 1:
        work->frame++;
        if (work->frame > 15)
            work->state++;
        break;
    case 2:
        dir = func_0216D5F8(mmdl);
        acmd = func_02197E7C(dir, 0x34);
        if (work->isLong == 1)
            acmd = func_02197E7C(dir, 0x38);
        func_0216D410(mmdl, acmd);
        work->state++;
        break;
    case 3:
        if (func_0216D454(mmdl) == 0)
            break;
        func_0216D480(mmdl);
        func_021ACBB8(func_021A2F98(work->player), 1);
        func_021A2F48(work->player, 4);
        work->state++;
    case 4:
        if (func_021A2F54(work->player) == 1) {
            func_021A35A0(work->player, 1);
            work->done = 1;
            work->state++;
        }
        break;
    case 5:
        break;
    }
}

void func_021C1228(FieldPlayer *player, u16 dir, u32 attr, u32 heapId)
{
    JumpWork *work;
    Mmdl *mmdl;
    MmdlVec start;
    MmdlVec ahead;
    int aheadHeight;

    work = func_02030734((u16)(0x8000 | (heapId & 0x7fff)), sizeof(JumpWork), 1, (const char *)&d_021DE3AC, 0x2b3);
    work->dir = dir;
    work->player = player;
    work->fieldMap = func_021A3068(player);
    mmdl = func_021A3074(player);
    func_0216D88C(mmdl, &start);
    ahead = start;
    func_02164208(work->dir, &ahead, 0x20000);
    func_02163E58(mmdl, &ahead, &aheadHeight);
    if (aheadHeight > start.y)
        work->targetHigher = 1;
    work->gameSystem = func_021A36E0(work->player);
    func_02030DA8(func_02188D30(work->fieldMap), func_021C1988, work, 0);
}

int func_021C12C4(TcblTask *task)
{
    return ((JumpWork *)func_02030EE8(task))->done;
}

void func_021C12D0(TcblTask *task)
{
    func_020307B0(func_02030EE8(task));
    func_02030EAC(task);
}

/*
 * Offsets a draw offset by (0, 1.0, 5.0) fx32 and applies it.
 */
void func_021C12E4(Mmdl *mmdl, const MmdlVec *offset)
{
    MmdlVec shifted = *offset;
    shifted.y += 0x1000;
    shifted.z += 0x5000;
    func_0216D8E0(mmdl, &shifted);
}

int func_021C1318(JumpWork *work)
{
    u32 effectKind;
    Mmdl *mmdl;
    FieldPlayerAnim *playerAnim;
    FieldEffectSys *effects;
    MmdlVec pos;
    MmdlVec nearPos;
    MmdlVec farPos;
    MmdlVec origin;
    int effectId;

    mmdl = func_021A3074(work->player);
    effectKind = 1;
    func_0216DB4C(mmdl, 1);
    func_0216D88C(mmdl, &pos);
    origin = pos;
    nearPos = origin;
    farPos = origin;
    func_02164208(work->dir, &nearPos, 0x10000);
    func_02164208(work->dir, &farPos, 0x20000);
    func_02164280((s16)((nearPos.x >> 4) / 0x1000), (s16)((nearPos.z >> 4) / 0x1000), &nearPos);
    func_02164280((s16)((farPos.x >> 4) / 0x1000), (s16)((farPos.z >> 4) / 0x1000), &work->target);
    work->target = farPos;
    func_02163E58(mmdl, &farPos, &work->target.y);
    work->stepX = (nearPos.x - pos.x) / 2 / 16;
    work->stepZ = (nearPos.z - pos.z) / 2 / 16;
    work->velocityY = 0x6000;
    work->drawOffset.y = 0x1000;
    playerAnim = func_021A2F98(work->player);
    func_021ACBB8(playerAnim, 2);
    if ((u16)(work->dir + 0xfffe) <= 1)
        effectKind = 3;
    effects = func_02188CD0(work->fieldMap);
    effectId = 9;
    func_021ABE30(effects, &effectId, 1);
    work->effectHandle = func_021AD564(effects, effectKind, playerAnim);
    func_021C6B18(work->fieldMap, 0x10, 0x20000);
    func_020061E4(0x6e0);
    work->state = work->state + 1;
    return 1;
}

int func_021C146C(JumpWork *work)
{
    MmdlVec pos;
    Mmdl *mmdl;
    FieldPlayerAnim *playerAnim;

    mmdl = func_021A3074(work->player);
    func_0216D88C(mmdl, &pos);
    pos.x += work->stepX;
    pos.z += work->stepZ;
    func_0216D89C(mmdl, &pos);
    work->drawOffset.y = -work->drawOffset.y;
    work->frame += 1;
    if (work->frame >= 0x10) {
        work->frame = 0;
        work->drawOffset.y = 0;
        work->state = work->state + 1;
        func_021AC154(work->effectHandle);
        playerAnim = func_021A2F98(work->player);
        {
            /* both branches give 2 */
            u32 effectKind = 2;
            if ((u16)(work->dir + 0xfffe) <= 1)
                effectKind = 2;
            work->effectHandle = func_021AD564(func_02188CD0(work->fieldMap), effectKind, playerAnim);
        }
    }
    func_021C12E4(mmdl, &work->drawOffset);
    return 0;
}

int func_021C14F8(JumpWork *work)
{
    MmdlVec pos;
    Mmdl *mmdl;

    mmdl = func_021A3074(work->player);
    func_0216D88C(mmdl, &pos);
    pos.y += work->velocityY;
    if (pos.y >= work->target.y) {
        pos.y = work->target.y;
        work->state = work->state + 1;
        work->stepX = (work->target.x - pos.x) / 16;
        work->stepZ = (work->target.z - pos.z) / 16;
        work->gravity = -0x8000;
        work->velocityY = 0x6000;
        work->gravity = func_0209C0A4(-0x8000, 0xb);
        func_021C6B18(work->fieldMap, 0x10, (u32)-0x8000 << 2);
        func_021AC154(work->effectHandle);
    }
    func_0216D89C(mmdl, &pos);
    return 0;
}

int func_021C157C(JumpWork *work)
{
    MmdlVec pos;
    Mmdl *mmdl;

    mmdl = func_021A3074(work->player);
    func_0216D88C(mmdl, &pos);
    if (pos.x < work->target.x) {
        pos.x += work->stepX;
        if (pos.x > work->target.x)
            pos.x = work->target.x;
    } else {
        pos.x += work->stepX;
        if (pos.x < work->target.x)
            pos.x = work->target.x;
    }
    if (pos.z < work->target.z) {
        pos.z += work->stepZ;
        if (pos.z > work->target.z)
            pos.z = work->target.z;
    } else {
        pos.z += work->stepZ;
        if (pos.z < work->target.z)
            pos.z = work->target.z;
    }
    pos.y += work->velocityY;
    work->velocityY += work->gravity;
    work->frame += 1;
    if (work->frame >= 0x10) {
        pos = work->target;
        work->drawOffset.x = 0;
        work->drawOffset.y = 0;
        work->drawOffset.z = 0;
        work->state = work->state + 1;
    }
    func_0216D89C(mmdl, &pos);
    func_021C12E4(mmdl, &work->drawOffset);
    return 0;
}

int func_021C161C(JumpWork *work)
{
    Mmdl *mmdl;
    FieldPlayerAnim *playerAnim;

    mmdl = func_021A3074(work->player);
    func_0216DB4C(mmdl, 0);
    func_0216E014(mmdl, &work->target, work->dir);
    playerAnim = func_021A2F98(work->player);
    func_021ACBB8(playerAnim, 1);
    work->effectHandle = func_021AD564(func_02188CD0(work->fieldMap), 0, playerAnim);
    func_020061E4(0x6e2);
    work->state = work->state + 1;
    return 0;
}

int func_021C1670(JumpWork *work)
{
    FieldEffectSys *effects;

    if (work->effectHandle != 0 && func_021AD5CC(work->effectHandle) == 1) {
        effects = func_02188CD0(work->fieldMap);
        func_021AC154(work->effectHandle);
        func_021ABE64(effects, 9);
        func_021A35A0(work->player, 1);
        work->effectHandle = 0;
        work->done = 1;
    }
    return 0;
}

void func_021C16AC(JumpWork *work)
{
    Mmdl *mmdl;
    u32 effectKind;
    FieldPlayerAnim *playerAnim;
    FieldEffectSys *effects;
    MmdlVec nowPos;
    MmdlVec pos;
    MmdlVec nearPos;
    MmdlVec farPos;
    MmdlVec origin;
    int effectId;

    mmdl = func_021A3074(work->player);
    switch (work->state) {
    case 0:
        effectKind = 1;
        func_0216DB4C(mmdl, 1);
        func_0216D88C(mmdl, &pos);
        origin = pos;
        nearPos = origin;
        farPos = origin;
        func_02164208(work->dir, &nearPos, 0x10000);
        func_02164208(work->dir, &farPos, 0x20000);
        func_02164280((s16)((nearPos.x >> 4) / 0x1000), (s16)((nearPos.z >> 4) / 0x1000), &nearPos);
        func_02164208(work->dir, &nearPos, 0x4000);
        func_02164280((s16)((farPos.x >> 4) / 0x1000), (s16)((farPos.z >> 4) / 0x1000), &farPos);
        work->target = farPos;
        func_02163E58(mmdl, &farPos, &work->target.y);
        work->stepX = (nearPos.x - pos.x) / 16;
        work->stepZ = (nearPos.z - pos.z) / 16;
        work->velocityY = -0x6000;
        work->drawOffset.y = 0x1000;
        playerAnim = func_021A2F98(work->player);
        func_021ACBB8(playerAnim, 2);
        if ((u16)(work->dir + 0xfffe) <= 1)
            effectKind = 3;
        effects = func_02188CD0(work->fieldMap);
        effectId = 9;
        func_021ABE30(effects, &effectId, 1);
        work->effectHandle = func_021AD564(effects, effectKind, playerAnim);
        func_021C6B18(work->fieldMap, 0x10, 0x20000);
        func_020061E4(0x6e1);
        work->state = work->state + 1;
    case 1:
        func_0216D88C(mmdl, &nowPos);
        nowPos.x += work->stepX;
        nowPos.z += work->stepZ;
        func_0216D89C(mmdl, &nowPos);
        work->drawOffset.y = -work->drawOffset.y;
        work->frame += 1;
        if (work->frame >= 0x10) {
            work->frame = 0;
            work->drawOffset.y = 0;
            work->state = work->state + 1;
            func_021AC154(work->effectHandle);
            playerAnim = func_021A2F98(work->player);
            {
                /* both branches give 2 */
                u32 landKind = 2;
                if ((u16)(work->dir + 0xfffe) <= 1)
                    landKind = 2;
                work->effectHandle = func_021AD564(func_02188CD0(work->fieldMap), landKind, playerAnim);
            }
        }
        func_021C12E4(mmdl, &work->drawOffset);
        break;
    case 2:
        func_0216D88C(mmdl, &nowPos);
        nowPos.y += work->velocityY;
        if (nowPos.y <= work->target.y) {
            nowPos.y = work->target.y;
            work->state = work->state + 1;
            work->stepX = (work->target.x - nowPos.x) / 16;
            work->stepZ = (work->target.z - nowPos.z) / 16;
            func_021C6B18(work->fieldMap, 0x10, -0x20000);
            func_021AC154(work->effectHandle);
            playerAnim = func_021A2F98(work->player);
            func_021ACBB8(playerAnim, 1);
            work->effectHandle = func_021AD564(func_02188CD0(work->fieldMap), 0, playerAnim);
        }
        func_0216D89C(mmdl, &nowPos);
        break;
    case 3:
        func_0216D88C(mmdl, &nowPos);
        nowPos.x += work->stepX;
        nowPos.z += work->stepZ;
        func_0216D89C(mmdl, &nowPos);
        work->frame += 1;
        if (work->frame >= 0x10) {
            effects = func_02188CD0(work->fieldMap);
            func_0216DB4C(mmdl, 0);
            func_0216E014(mmdl, &work->target, work->dir);
            func_021AC154(work->effectHandle);
            func_021ABE64(effects, 9);
            func_021A35A0(work->player, 1);
            work->effectHandle = 0;
            work->done = 1;
            func_020061E4(0x6e2);
            work->state = work->state + 1;
        }
        break;
    }
}
