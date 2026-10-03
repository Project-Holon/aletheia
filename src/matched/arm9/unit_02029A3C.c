/*
 * unit:     yes
 * address:  0x02029A3C
 * packet:   pkt_020295D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_02029A3C, func_02029A74
 *
 * Part of the (task body, task spawner) family that makes up the tail of
 * field_sound_system.c.  A one shot body: it issues both commands on the first tick and reports done
 * immediately.  The second command's 1001 is a pool word because it does not
 * fit a Thumb `movs` immediate, not because it is a relocation.
 *
 * VERSION SENSITIVITY: 1001 is a content id in the same space as the other
 * command 7 arguments in this family, so it is one to re-read for a Pokemon
 * White build; nothing else in this file is version dependent.
 *
 * The pair is one file on purpose.  The spawner's only reference to the body
 * is an ABS32 pool word, and a pool word is not a branch, so the body has no
 * `label` witness anywhere in the image; with the two in separate files the
 * spawner caps at MATCH.  In one object the body is a `local` symbol and the
 * relocation needs no image evidence at all.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02029A3C.c  *       --addr 0x02029A3C --thumb
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
extern void func_020289F8(struct Sys *s, u32 a, u32 b, u16 c, u16 d);

u32 func_02029A3C(void *task, u32 *state, struct Work *work)
{
    void *sys = work->unk04;

    if (*state == 0) {
        func_020289F8(sys, 2, 0, work->unk0E, 0);
        func_020289F8(sys, 7, 1001, 0, 0);
        return 1;
    }
    return 0;
}

extern void *func_020120F4(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void *func_02012A30(void *a);

void *func_02029A74(void *a, u16 b)
{
    void *x = func_020120F4(a);
    void *task = func_020122C0(a, 0, func_02029A3C, 0x10);
    struct Work *work = func_020124E8(task);

    work->unk04 = func_02012A30(x);
    work->unk0E = b;
    return task;
}
