/*
 * unit:     yes
 * address:  0x02029AA8
 * packet:   pkt_020295D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_02029AA8, func_02029AF4
 *
 * Part of the (task body, task spawner) family that makes up the tail of
 * field_sound_system.c.  The body issues a command 3 with a literal 6 and a command 7, then waits
 * for the system to go idle before reporting done.
 *
 * The pair is one file on purpose.  The spawner's only reference to the body
 * is an ABS32 pool word, and a pool word is not a branch, so the body has no
 * `label` witness anywhere in the image; with the two in separate files the
 * spawner caps at MATCH.  In one object the body is a `local` symbol and the
 * relocation needs no image evidence at all.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02029AA8.c  *       --addr 0x02029AA8 --thumb
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

struct Ctx;
struct Desc;
struct Obj;
struct Sys;
extern void func_020289F8(struct Sys *s, u32 a, u32 b, u16 c, u16 d);
extern u32 func_020289B8(struct Sys *s);

u32 func_02029AA8(void *task, u32 *state, struct Work *work)
{
    void *sys = work->unk04;

    switch (*state) {
    case 0:
        func_020289F8(sys, 3, 0, 6, 0);
        func_020289F8(sys, 7, work->unk08, 0, 0);
        (*state)++;
        break;
    case 1:
        if (func_020289B8(sys) == 0) {
            return 1;
        }
        break;
    }
    return 0;
}

extern void *func_020120F4(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
struct BigObj;
extern u32 func_02012A30(const struct BigObj *a);

void *func_02029AF4(void *a, u32 b)
{
    void *x = func_020120F4(a);
    void *task = func_020122C0(a, 0, func_02029AA8, 0x10);
    struct Work *work = func_020124E8(task);

    work->unk04 = (void *)func_02012A30(x);
    work->unk08 = b;
    return task;
}
