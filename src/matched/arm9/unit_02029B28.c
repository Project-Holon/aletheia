/*
 * unit:     yes
 * address:  0x02029B28
 * packet:   pkt_020295D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: FIELD_SOUND_SYSTEM_StartFadeOutAndResetTask
 *
 * Part of the (task body, task spawner) family that makes up the tail of
 * field_sound_system.c.  The spawner for the four state body at 0x020298E0, which sits far enough
 * away in the packet that the two cannot share a translation unit.
 *
 * What capped it: the ABS32 pool word naming FIELD_SOUND_SYSTEM_FadeOutAndResetTask is the only
 * reference to that address anywhere in the image, and a pool word is not a
 * branch, so the `label` class had no witness.  Wave 26 closed the chain
 * underneath it (FIELD_SOUND_SYSTEM_DrainAndInit, RINGTONE_SYS_Start, RINGTONE_SYS_Stop ->
 * unit_02028A50 -> unit_020298E0), and the site now resolves `matched`.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02029B28.c  *       --addr 0x02029B28 --thumb
 *
 * symbols:
 *   FIELD_SOUND_SYSTEM_FadeOutAndResetTask  0x020298E0  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct Work {
    void *unk00;
    void *unk04;
    u32   unk08;
    u16   unk0C;
    u16   unk0E;
};

typedef u32 (*TaskFn)(void *task, u32 *state, struct Work *work);

extern u32 FIELD_SOUND_SYSTEM_FadeOutAndResetTask(void *task, u32 *state, struct Work *work);

struct Ctx;
struct Desc;
struct Obj;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
struct BigObj;
extern u32 GAME_DATA_GetBgmInfo(const struct BigObj *a);

void *FIELD_SOUND_SYSTEM_StartFadeOutAndResetTask(void *a, u16 b)
{
    void *x = GAMESYSTEM_GetGameData(a);
    void *task = func_020122C0(a, 0, FIELD_SOUND_SYSTEM_FadeOutAndResetTask, 0x10);
    struct Work *work = func_020124E8(task);

    work->unk00 = a;
    work->unk04 = (void *)GAME_DATA_GetBgmInfo(x);
    work->unk0E = b;
    return task;
}
