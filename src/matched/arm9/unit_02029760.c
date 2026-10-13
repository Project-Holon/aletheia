/*
 * unit:     yes
 * address:  0x02029760
 * packet:   pkt_020295D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: FIELD_SOUND_SYSTEM_PushAndChangeTask, FIELD_SOUND_SYSTEM_StartPushAndChangeTask
 *
 * One of the (task body, task spawner) pairs that make up the tail of
 * field_sound_system.c.  The body issues a command 3 and a command 5 in the same tick.
 *
 * The pair is one file on purpose.  The spawner's only reference to the body
 * is an ABS32 pool word, and a pool word is not a branch, so the body has no
 * `label` witness anywhere in the image; with the two in separate files the
 * spawner caps at MATCH.  In one object the body is a `local` symbol and the
 * relocation needs no image evidence at all.
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02012A30  0x02012A30  thumb
 *   FIELD_SOUND_SYSTEM_PostRequest  0x020289F8  thumb
 *   FIELD_SOUND_SYSTEM_GetQueueDepth  0x020288C4  thumb
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02029760.c  *       --addr 0x02029760 --thumb
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
extern s32 FIELD_SOUND_SYSTEM_GetQueueDepth(struct Sys *s);
extern u32 func_020289B8(struct Sys *s);

extern void *func_020120F4(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
struct BigObj;
extern u32 func_02012A30(const struct BigObj *a);

u32 FIELD_SOUND_SYSTEM_PushAndChangeTask(void *task, u32 *state, struct Work *work)
{
    void *sys = work->unk04;

    switch (*state) {
    case 0:
        FIELD_SOUND_SYSTEM_PostRequest(sys, 3, 0, work->unk0E, 0);
        FIELD_SOUND_SYSTEM_PostRequest(sys, 5, work->unk08, 0, work->unk0C);
        (*state)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}

void *FIELD_SOUND_SYSTEM_StartPushAndChangeTask(void *a, u32 b, u32 c, u32 d)
{
    void *x = func_020120F4(a);
    void *task = func_020122C0(a, 0, FIELD_SOUND_SYSTEM_PushAndChangeTask, 0x10);
    struct Work *work = func_020124E8(task);

    work->unk04 = (void *)func_02012A30(x);
    work->unk08 = b;
    work->unk0C = d;
    work->unk0E = c;
    return task;
}
