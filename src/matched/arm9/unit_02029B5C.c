/*
 * unit:     yes
 * address:  0x02029B5C
 * packet:   pkt_020295D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: FIELD_SOUND_SYSTEM_PushOrFadeOutAndPlayTask, FIELD_SOUND_SYSTEM_StartPushOrFadeOutAndPlayTask
 *
 * Part of the (task body, task spawner) family that makes up the tail of
 * field_sound_system.c.  A four state body whose first state picks command 2 or command 3 by asking
 * the queue depth.  Both arms of that choice write out the whole call and the
 * compiler cross-jumps all of it but the `movs r3, #6`
 * (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md).
 *
 * The pair is one file on purpose.  The spawner's only reference to the body
 * is an ABS32 pool word, and a pool word is not a branch, so the body has no
 * `label` witness anywhere in the image; with the two in separate files the
 * spawner caps at MATCH.  In one object the body is a `local` symbol and the
 * relocation needs no image evidence at all.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02029B5C.c  *       --addr 0x02029B5C --thumb
 *
 * symbols:
 *   FIELD_SOUND_SYSTEM_GetQueueDepth  0x020288C4  thumb
 *   FIELD_SOUND_SYSTEM_PostRequest  0x020289F8  thumb
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

typedef signed int     s32;
struct Ctx;
struct Desc;
struct Obj;
struct Sys;
extern void FIELD_SOUND_SYSTEM_PostRequest(struct Sys *s, u32 a, u32 b, u16 c, u16 d);
extern u32 func_020289B8(struct Sys *s);
extern s32 FIELD_SOUND_SYSTEM_GetQueueDepth(struct Sys *s);

u32 FIELD_SOUND_SYSTEM_PushOrFadeOutAndPlayTask(void *task, u32 *state, struct Work *work)
{
    void *sys = work->unk04;

    switch (*state) {
    case 0:
        if (FIELD_SOUND_SYSTEM_GetQueueDepth(sys) == 0) {
            FIELD_SOUND_SYSTEM_PostRequest(sys, 3, 0, 6, 0);
        } else {
            FIELD_SOUND_SYSTEM_PostRequest(sys, 2, 0, 6, 0);
        }
        (*state)++;
        break;
    case 1:
        if (func_020289B8(sys) == 0) {
            (*state)++;
        }
        break;
    case 2:
        FIELD_SOUND_SYSTEM_PostRequest(sys, 7, work->unk08, 0, 0);
        (*state)++;
        break;
    case 3:
        return 1;
    }
    return 0;
}

extern void *func_020120F4(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
struct BigObj;
extern unsigned int func_02012A30(const struct BigObj *p);

void *FIELD_SOUND_SYSTEM_StartPushOrFadeOutAndPlayTask(void *a, u32 b)
{
    void *x = func_020120F4(a);
    void *task = func_020122C0(a, 0, FIELD_SOUND_SYSTEM_PushOrFadeOutAndPlayTask, 0x10);
    struct Work *work = func_020124E8(task);

    work->unk04 = (void *)func_02012A30(x);
    work->unk08 = b;
    return task;
}
