/*
 * unit:     yes
 * address:  0x020295D8
 * packet:   pkt_020295D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_020295D8, func_02029620
 *
 * One of the sixteen (task body, task spawner) pairs that make up the tail of
 * field_sound_system.c.  Every pair has the same shape: a small state machine
 * driven by the counter the task system hands it, and a spawner that allocates
 * the 0x10 byte work block, parks the body's address in it and fills in the
 * parameters the body will read.
 *
 * The pair is one file on purpose.  The spawner's only reference to the body
 * is the ABS32 pool word at 0x02029654, and a pool word is not a branch, so
 * the body has no `label` witness anywhere in the image; with the two in
 * separate files the spawner caps at MATCH.  In one object the body is a
 * `local` symbol and the relocation needs no image evidence at all.
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02012A30  0x02012A30  thumb
 *   func_020289B8  0x020289B8  thumb
 *   func_020289F8  0x020289F8  thumb
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020295D8.c \
 *       --addr 0x020295D8 --thumb
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

u32 func_020295D8(void *task, u32 *state, struct Work *work)
{
    void *sys = work->unk04;

    switch (*state) {
    case 0:
        func_020289F8(sys, 4, 0, work->unk0E, work->unk0C);
        (*state)++;
        break;
    case 1:
        if (func_020289B8(sys) == 0) {
            (*state)++;
        }
        break;
    case 2:
        return 1;
    }
    return 0;
}

extern void *func_020120F4(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
struct BigObj;
extern u32 func_02012A30(const struct BigObj *p);

void *func_02029620(void *a, u16 b, u16 c)
{
    void *x = func_020120F4(a);
    void *task = func_020122C0(a, 0, func_020295D8, 0x10);
    struct Work *work = func_020124E8(task);

    work->unk04 = (void *)func_02012A30(x);
    work->unk0C = c;
    work->unk0E = b;
    return task;
}
