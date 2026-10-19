/*
 * unit:     yes
 * address:  0x020297EC
 * packet:   pkt_020295D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: FIELD_SOUND_SYSTEM_PushAndPlayTask, FIELD_SOUND_SYSTEM_StartPushAndPlayTask
 *
 * One of the (task body, task spawner) pairs that make up the tail of
 * field_sound_system.c.  The body issues a command 3 with a literal 6 and a command 7 in the same
 * tick.
 *
 * The pair is one file on purpose.  The spawner's only reference to the body
 * is an ABS32 pool word, and a pool word is not a branch, so the body has no
 * `label` witness anywhere in the image; with the two in separate files the
 * spawner caps at MATCH.  In one object the body is a `local` symbol and the
 * relocation needs no image evidence at all.
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb
 *   FIELD_SOUND_SYSTEM_PostRequest  0x020289F8  thumb
 *   FIELD_SOUND_SYSTEM_GetPendingBgmStackDepth  0x020288C4  thumb
 *   FIELD_SOUND_SYSTEM_IsBusy  0x020289B8  thumb
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020297EC.c  *       --addr 0x020297EC --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

struct Work {
    void *unk00;
    void *unk04;
    u32   unk08;
    u16   unk0C;
    u16   unk0E;
};

typedef u32 (*TaskFn)(void *task, u32 *state, struct Work *work);

struct Ctx;
struct Desc;
struct Obj;
struct Sys;
extern void FIELD_SOUND_SYSTEM_PostRequest(struct Sys *s, u32 a, u32 b, u16 c, u16 d);
extern s32 FIELD_SOUND_SYSTEM_GetPendingBgmStackDepth(struct Sys *s);
extern u32 FIELD_SOUND_SYSTEM_IsBusy(struct Sys *s);

extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
struct BigObj;
extern u32 GAME_DATA_GetBgmInfo(const struct BigObj *p);

u32 FIELD_SOUND_SYSTEM_PushAndPlayTask(void *task, u32 *state, struct Work *work)
{
    void *sys = work->unk04;

    switch (*state) {
    case 0:
        FIELD_SOUND_SYSTEM_PostRequest(sys, 3, 0, 6, 0);
        FIELD_SOUND_SYSTEM_PostRequest(sys, 7, work->unk08, 0, 0);
        (*state)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}

void *FIELD_SOUND_SYSTEM_StartPushAndPlayTask(void *a, u32 b)
{
    void *x = GAMESYSTEM_GetGameData(a);
    void *task = func_020122C0(a, 0, FIELD_SOUND_SYSTEM_PushAndPlayTask, 0x10);
    struct Work *work = func_020124E8(task);

    work->unk04 = (void *)GAME_DATA_GetBgmInfo(x);
    work->unk08 = b;
    work->unk0E = 0;
    return task;
}
