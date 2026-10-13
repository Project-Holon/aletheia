/*
 * file:     field_comm_actor.c
 * unit:     yes
 * function: func_02194284, func_021942C8, func_02194300, func_02194354, func_02194384, func_021943EC, func_02194418, func_02194434, func_021944BC, func_021944C8, func_021944D8, func_02194588, func_021945A0, func_021945A4, func_021945E0
 * address:  0x02194284
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from field_wfbc.c at 0x02194284 (lane CL120, __FILE__ anchors).
 *
 * symbols:
 *   func_02030734  0x02030734  arm  arm9
 *   func_020307B0  0x020307B0  arm
 *   func_02082BCC  0x02082BCC  arm
 *   sFieldCommActorFileName 0x021DDA70  data  a4
 *   func_0216D684  0x0216D684  thumb  ov010
 *   func_0216D854  0x0216D854  thumb  ov010
 *   func_02163C04  0x02163C04  thumb  ov010
 *   func_0216CF2C  0x0216CF2C  thumb  ov010
 *   sCommActorMmdlHeader 0x021D3F68  data  ov021  a4
 *   func_0216CE60  0x0216CE60  thumb  ov010
 *   func_0216E014  0x0216E014  thumb  ov010
 *   func_0216DB4C  0x0216DB4C  thumb  ov010
 *   func_0216DC98  0x0216DC98  thumb  ov010
 *   func_0216DB80  0x0216DB80  thumb  ov010
 *   func_0216DAE0  0x0216DAE0  thumb  ov010
 *   func_0216DC64  0x0216DC64  thumb  ov010
 *   func_0216DCCC  0x0216DCCC  thumb  ov010
 *   func_0216D69C  0x0216D69C  thumb  ov010
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_0216DAC8  0x0216DAC8  thumb  ov010
 *   func_02188CCC  0x02188CCC  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_021A0ED4  0x021A0ED4  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_020124E4  0x020124E4  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_020129D0  0x020129D0  thumb
 *   func_021A0F30  0x021A0F30  thumb  ov021
 *   func_020129B8  0x020129B8  thumb
 *   func_0216D9E4  0x0216D9E4  thumb  ov010
 */
#include "../ov010/fldmmdl_types.h"

struct GameEvent;
struct GameSystem;
struct GameData;
struct FieldMap;
struct FieldSubscreen;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short s16;

/* One actor of a connected player (0xC bytes). */
typedef struct FieldCommActor {
    u32 id;
    u16 isMmdlDeleted;   /* set by the move remove procedure */
    u16 useRunAnime;
    Mmdl *mmdl;
} FieldCommActor;

/* Actor control of the connected players (0xC bytes). */
typedef struct FieldCommActorCtrl {
    u16 actorMax;
    u16 useRunAnime;
    MmdlSys *mmdlSys;
    FieldCommActor *actors;
} FieldCommActorCtrl;

/* Move procedure work of an actor model (0x10 bytes): pointers into the comm player entry. */
typedef struct FieldCommActorMoveWork {
    const u16 *dir;
    const MmdlVec *pos;
    const int *vanish;
    FieldCommActor *actor;
} FieldCommActorMoveWork;

/* Work of the subscreen change event (0x14 bytes). */
typedef struct SubscreenChangeEventWork {
    struct GameEvent *event;
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap;
    u32 mode;
    u8 seq;
} SubscreenChangeEventWork;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern u32 func_02082BCC(void *dst, int value, int size);
extern int func_0216D854(Mmdl *mmdl);
extern int func_02163C04(Mmdl *mmdl, int gridX, int gridZ, int flag);
extern int func_0216CF2C(Mmdl *mmdl);
extern Mmdl *func_0216CE60(MmdlSys *mmdlSys, const MmdlHeader *header, int zoneId);
extern void func_0216E014(Mmdl *mmdl, const MmdlVec *pos, int dir);
extern int func_0216DB4C(Mmdl *mmdl, int flag);
extern int func_0216DC98(Mmdl *mmdl, int flag);
extern void func_0216DB80(Mmdl *mmdl, int flag);
extern void func_0216DAE0(Mmdl *mmdl, int flag);
extern int func_0216DC64(Mmdl *mmdl, int flag);
extern int func_0216DCCC(Mmdl *mmdl, int flag);
extern void *func_0216D684(Mmdl *mmdl, int size);
extern void *func_0216D69C(Mmdl *mmdl);
extern void func_0216D5E0(Mmdl *mmdl, int dir);
extern void func_0216D88C(const Mmdl *mmdl, MmdlVec *out);
extern u16 func_0216D5F8(Mmdl *mmdl);
extern u16 func_0216D598(Mmdl *mmdl);
extern void func_0216D674(Mmdl *mmdl, int status);
extern void func_0216DAC8(Mmdl *mmdl, int flag);
extern struct FieldSubscreen *func_02188CCC(struct FieldMap *fieldMap);
extern struct GameEvent *func_020122C0(struct GameSystem *gameSystem, struct GameEvent *parent, int (*callback)(struct GameEvent *, int *, void *), u32 workSize);
extern void *func_020124E8(struct GameEvent *event);
extern int func_021A0ED4(struct FieldSubscreen *subscreen);
extern MmdlSys *func_02188C7C(struct FieldMap *fieldMap);
extern struct GameSystem *func_020124E4(struct GameEvent *event);
extern struct GameData *func_020120F4(struct GameSystem *gameSystem);
extern void func_0216D9A0(MmdlSys *mmdlSys);
extern void func_020129D0(struct GameData *gameData, u8 flag);
extern int func_021A0F30(struct FieldSubscreen *subscreen, u32 mode);
extern void func_020129B8(struct GameData *gameData, u32 mode);
extern void func_0216D9E4(MmdlSys *mmdlSys);
FieldCommActorCtrl *func_02194284(int actorMax, MmdlSys *mmdlSys, int heapId, int useRunAnime);
void func_021942C8(FieldCommActorCtrl *ctrl);
void func_02194300(FieldCommActorCtrl *ctrl, int id, int objCode, const u16 *dir, const MmdlVec *pos, const int *vanish);
void func_02194354(FieldCommActorCtrl *ctrl, u32 id);
int func_02194384(FieldCommActorCtrl *ctrl, s16 gridX, int gridY, s16 gridZ, int *outId, unsigned *index);
Mmdl *func_021943EC(FieldCommActorCtrl *ctrl, u32 id);
int func_02194418(FieldCommActor *actor);
Mmdl *func_02194434(FieldCommActorCtrl *ctrl, int objCode, const u16 *dir, const MmdlVec *pos, const int *vanish, FieldCommActor *actor);
void func_021944BC(Mmdl *mmdl);
void func_021944C8(Mmdl *mmdl);
void func_021944D8(Mmdl *mmdl);
void func_02194588(Mmdl *mmdl, const u16 *dir, const MmdlVec *pos, const int *vanish, FieldCommActor *actor);
int func_021945A0(int dir);
struct GameEvent *func_021945A4(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u32 mode);
int func_021945E0(struct GameEvent *event, int *seq, void *work);
extern char sFieldCommActorFileName[];
extern MmdlHeader sCommActorMmdlHeader;

FieldCommActorCtrl *func_02194284(int actorMax, MmdlSys *mmdlSys, int heapId, int useRunAnime)
{
    int size = sizeof(FieldCommActor);
    FieldCommActorCtrl *ctrl = func_02030734(heapId, size, 1, sFieldCommActorFileName, 0x5d);
    ctrl->actorMax = actorMax;
    ctrl->useRunAnime = useRunAnime;
    ctrl->mmdlSys = mmdlSys;
    ctrl->actors = func_02030734(heapId, size * actorMax, 1, sFieldCommActorFileName, 0x63);
    return ctrl;
}

void func_021942C8(FieldCommActorCtrl *ctrl)
{
    u16 i;
    FieldCommActor *actor;
    i = 0;
    actor = ctrl->actors;
    if (i < ctrl->actorMax) {
        for (; i < ctrl->actorMax; i++) {
            if (actor->mmdl != 0) {
                func_02194418(actor);
            }
            actor++;
        }
    }
    func_020307B0(ctrl->actors);
    func_020307B0(ctrl);
}

void func_02194300(FieldCommActorCtrl *ctrl, int id, int objCode, const u16 *dir, const MmdlVec *pos, const int *vanish)
{
    u16 i;
    FieldCommActor *actor = ctrl->actors;
    func_021945A0(*dir);
    for (i = 0; i < ctrl->actorMax; i++) {
        if (actor->mmdl == 0) {
            actor->mmdl = func_02194434(ctrl, objCode, dir, pos, vanish, actor);
            actor->id = id;
            actor->useRunAnime = ctrl->useRunAnime;
            return;
        }
        actor++;
    }
}

void func_02194354(FieldCommActorCtrl *ctrl, u32 id)
{
    FieldCommActor *actor;
    u16 i;
    actor = ctrl->actors;
    for (i = 0; i < ctrl->actorMax; i++) {
        if (actor->mmdl != 0 && actor->id == id) {
            func_02194418(actor);
            return;
        }
        actor++;
    }
}

/*
 * The actor pointer only advances past actors that have a model; the
 * search resumes from *index on the next call.
 */
int func_02194384(FieldCommActorCtrl *ctrl, s16 gridX, int gridY, s16 gridZ, int *outId, unsigned *index)
{
    unsigned actorMax = ctrl->actorMax;
    FieldCommActor *actor;
    short diff;
    if (*index < actorMax) {
        actor = ctrl->actors + *index;
        do {
            (*index)++;
            if (actor->mmdl != 0) {
                diff = func_0216D854(actor->mmdl) - gridY;
                if (diff < 0)
                    diff = -diff;
                if (diff < 1) {
                    if (func_02163C04(actor->mmdl, gridX, gridZ, 1)) {
                        *outId = actor->id;
                        return 1;
                    }
                }
                actor++;
            }
        } while (*index < actorMax);
    }
    return 0;
}

Mmdl *func_021943EC(FieldCommActorCtrl *ctrl, u32 id)
{
    u16 i;
    FieldCommActor *actor;
    u16 actorMax;
    actorMax = ctrl->actorMax;
    i = 0;
    actor = ctrl->actors;
    for (; i < actorMax; i++, actor++) {
        if (actor->mmdl != 0 && actor->id == id)
            return actor->mmdl;
    }
    return 0;
}

int func_02194418(FieldCommActor *actor)
{
    if (actor->isMmdlDeleted == 0) {
        func_0216CF2C(actor->mmdl);
    }
    return func_02082BCC(actor, 0, sizeof(FieldCommActor));
}

Mmdl *func_02194434(FieldCommActorCtrl *ctrl, int objCode, const u16 *dir, const MmdlVec *pos, const int *vanish, FieldCommActor *actor)
{
    MmdlSys *mmdlSys = ctrl->mmdlSys;
    MmdlHeader header = sCommActorMmdlHeader;
    Mmdl *mmdl;
    header.objCode = objCode;
    mmdl = func_0216CE60(mmdlSys, &header, 0);
    func_02194588(mmdl, dir, pos, vanish, actor);
    func_0216E014(mmdl, pos, func_021945A0(*dir));
    func_0216DB4C(mmdl, 1);
    func_0216DC98(mmdl, 1);
    func_0216DB80(mmdl, 1);
    func_0216DAE0(mmdl, 0);
    func_0216DC64(mmdl, 1);
    func_0216DCCC(mmdl, 1);
    return mmdl;
}

void func_021944BC(Mmdl *mmdl)
{
    func_0216D684(mmdl, sizeof(FieldCommActorMoveWork));
}

void func_021944C8(Mmdl *mmdl)
{
    ((FieldCommActorMoveWork *)func_0216D69C(mmdl))->actor->isMmdlDeleted = 1;
}

void func_021944D8(Mmdl *mmdl)
{
    MmdlVec nowPos;
    FieldCommActorMoveWork *work;
    int drawStatus;
    const MmdlVec *pos;
    int objCode;
    int diff;
    work = func_0216D69C(mmdl);
    func_0216D5E0(mmdl, func_021945A0(*work->dir));
    drawStatus = 0;
    func_0216D88C(mmdl, &nowPos);
    pos = work->pos;
    if (nowPos.x != pos->x || nowPos.y != pos->y || nowPos.z != pos->z) {
        func_0216E014(mmdl, work->pos, func_0216D5F8(mmdl));
        drawStatus = 3;
        if (work->actor->useRunAnime != 0) {
            objCode = func_0216D598(mmdl);
            if (objCode == 1 || objCode == 4) {
                int distance = 0;
                pos = work->pos;
                diff = nowPos.x - pos->x;
                if (diff < 0)
                    diff = -diff;
                distance += diff;
                diff = nowPos.z - pos->z;
                if (diff < 0)
                    diff = -diff;
                distance += diff;
                if (distance >= 0x4000)
                    drawStatus = 10;
            }
        }
    }
    func_0216D674(mmdl, drawStatus);
    if (work->vanish != 0)
    {
        int vanish = 0;
        if (*work->vanish == 1)
            vanish = 1;
        func_0216DAC8(mmdl, vanish);
    }
}

void func_02194588(Mmdl *mmdl, const u16 *dir, const MmdlVec *pos, const int *vanish, FieldCommActor *actor)
{
    FieldCommActorMoveWork *work;
    work = func_0216D69C(mmdl);
    work->dir = dir;
    work->pos = pos;
    work->vanish = vanish;
    work->actor = actor;
}

/* Returns the direction unchanged (a conversion that does nothing in this version). */
int func_021945A0(int dir)
{
    return dir;
}

struct GameEvent *func_021945A4(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u32 mode)
{
    struct GameEvent *event;
    SubscreenChangeEventWork *work;
    func_02188CCC(fieldMap);
    event = func_020122C0(gameSystem, 0, func_021945E0, sizeof(SubscreenChangeEventWork));
    work = func_020124E8(event);
    func_02082BCC(work, 0, sizeof(SubscreenChangeEventWork));
    work->gameSystem = gameSystem;
    work->event = event;
    work->fieldMap = fieldMap;
    work->mode = mode;
    return event;
}

int func_021945E0(struct GameEvent *event, int *seq, void *work)
{
    SubscreenChangeEventWork *evWork = work;
    MmdlSys *mmdlSys;
    struct GameData *gameData;
    switch (evWork->seq) {
    case 0:
        if (func_021A0ED4(func_02188CCC(evWork->fieldMap)) == 1) {
            mmdlSys = func_02188C7C(evWork->fieldMap);
            gameData = func_020120F4(func_020124E4(event));
            func_0216D9A0(mmdlSys);
            func_020129D0(gameData, 1);
            func_021A0F30(func_02188CCC(evWork->fieldMap), evWork->mode);
            evWork->seq++;
        }
        break;
    case 1:
        if (func_021A0ED4(func_02188CCC(evWork->fieldMap)) == 1) {
            func_020129B8(func_020120F4(func_020124E4(event)), evWork->mode & 0xff);
            evWork->seq++;
        }
        break;
    case 2:
        func_0216D9E4(func_02188C7C(evWork->fieldMap));
        return 1;
    }
    return 0;
}
