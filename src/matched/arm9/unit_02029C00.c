/*
 * unit:     yes
 * address:  0x02029C00
 * packet:   pkt_020295D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_02029C00
 *
 * Part of the (task body, task spawner) family that makes up the tail of
 * field_sound_system.c.  A second spawner for the body at 0x02029658, this one with the two command
 * parameters fixed at 60 and 30 instead of taken from its caller.
 *
 * It is a file of its own because the body it parks, func_02029658, already
 * has a manifest entry of its own (src/matched/unit_02029658.c), so the ABS32
 * pool word here is carried by the `matched` class and needs no merge.
 *
 * VERSION SENSITIVITY: 60 and 30 are frame counts rather than content ids, so
 * they are structure for porting purposes; nothing here is version dependent.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02029C00.c  *       --addr 0x02029C00 --thumb
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

extern u32 func_02029658(void *task, u32 *state, struct Work *work);

struct Ctx;
struct Desc;
struct Obj;
extern void *func_020120F4(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
struct BigObj;
extern u32 func_02012A30(const struct BigObj *p);

void *func_02029C00(void *a)
{
    void *x = func_020120F4(a);
    void *task = func_020122C0(a, 0, func_02029658, 0x10);
    struct Work *work = func_020124E8(task);

    work->unk04 = (void *)func_02012A30(x);
    work->unk0C = 0x3C;
    work->unk0E = 0x1E;
    return task;
}
