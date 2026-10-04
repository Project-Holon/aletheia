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
 * function: func_02029B28
 *
 * Part of the (task body, task spawner) family that makes up the tail of
 * field_sound_system.c.  The spawner for the four state body at 0x020298E0, which sits far enough
 * away in the packet that the two cannot share a translation unit.
 *
 * What capped it: the ABS32 pool word naming func_020298E0 is the only
 * reference to that address anywhere in the image, and a pool word is not a
 * branch, so the `label` class had no witness.  Wave 26 closed the chain
 * underneath it (func_02028D2C, func_02029F54, func_02029F60 ->
 * unit_02028A50 -> unit_020298E0), and the site now resolves `matched`.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02029B28.c  *       --addr 0x02029B28 --thumb
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

extern u32 func_020298E0(void *task, u32 *state, struct Work *work);

struct Ctx;
struct Desc;
struct Obj;
extern void *func_020120F4(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
struct BigObj;
extern u32 func_02012A30(const struct BigObj *a);

void *func_02029B28(void *a, u16 b)
{
    void *x = func_020120F4(a);
    void *task = func_020122C0(a, 0, func_020298E0, 0x10);
    struct Work *work = func_020124E8(task);

    work->unk00 = a;
    work->unk04 = (void *)func_02012A30(x);
    work->unk0E = b;
    return task;
}
