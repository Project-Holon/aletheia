/*
 * unit:     yes
 * address:  0x020299B8
 * packet:   pkt_020295D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: FIELD_SOUND_SYSTEM_FadeOutAndPlayWithFadeTask, FIELD_SOUND_SYSTEM_StartFadeOutAndPlayWithFadeTask
 *
 * Part of the (task body, task spawner) family that makes up the tail of
 * field_sound_system.c.  The same shape as unit_02029938.c with the command 2's third argument taken
 * from the work block instead of the literal 6.
 *
 * The pair is one file on purpose.  The spawner's only reference to the body
 * is an ABS32 pool word, and a pool word is not a branch, so the body has no
 * `label` witness anywhere in the image; with the two in separate files the
 * spawner caps at MATCH.  In one object the body is a `local` symbol and the
 * relocation needs no image evidence at all.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020299B8.c  *       --addr 0x020299B8 --thumb
 *
 * symbols:
 *   FIELD_SOUND_SYSTEM_PostRequest  0x020289F8  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb
 *   FIELD_SOUND_SYSTEM_IsBusy  0x020289B8  thumb
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
extern u32 FIELD_SOUND_SYSTEM_IsBusy(struct Sys *s);

u32 FIELD_SOUND_SYSTEM_FadeOutAndPlayWithFadeTask(void *task, u32 *state, struct Work *work)
{
    void *sys = work->unk04;

    switch (*state) {
    case 0:
        FIELD_SOUND_SYSTEM_PostRequest(sys, 2, 0, work->unk0E, 0);
        FIELD_SOUND_SYSTEM_PostRequest(sys, 7, work->unk08, 0, 0);
        (*state)++;
        break;
    case 1:
        if (FIELD_SOUND_SYSTEM_IsBusy(sys) == 0) {
            return 1;
        }
        break;
    }
    return 0;
}

extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
struct BigObj;
extern u32 GAME_DATA_GetBgmInfo(const struct BigObj *a);

void *FIELD_SOUND_SYSTEM_StartFadeOutAndPlayWithFadeTask(void *a, u32 b, u16 c)
{
    void *x = GAMESYSTEM_GetGameData(a);
    void *task = func_020122C0(a, 0, FIELD_SOUND_SYSTEM_FadeOutAndPlayWithFadeTask, 0x10);
    struct Work *work = func_020124E8(task);

    work->unk04 = (void *)GAME_DATA_GetBgmInfo(x);
    work->unk08 = b;
    work->unk0E = c;
    return task;
}
