/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * unit:     yes
 * address:  0x02029B28
 * packet:   pkt_020295D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH, every concrete byte right
 * function: func_02029B28
 *
 * Part of the (task body, task spawner) family that makes up the tail of
 * field_sound_system.c.  The spawner for the four state body at 0x020298E0, which sits far enough
 * away in the packet that the two cannot share a translation unit.
 *
 * Why it is capped: the ABS32 pool word naming func_020298E0 is the only
 * reference to that address anywhere in the image, and a pool word is not a
 * branch, so the `label` class has no witness.  func_020298E0 is byte-correct
 * in src/pending/unit_020298E0.c but MATCH-capped itself (on func_02028A50,
 * see that file), so the `matched` class cannot carry it either, and the two
 * cannot be merged because seven other functions lie between them.  The chain
 * closes at func_02028D2C, func_02029F54 and func_02029F60; see
 * src/pending/unit_02028A50.c.
 *
 * Verified with:
 *   python tools/match.py tu --src src/pending/unit_02029B28.c  *       --addr 0x02029B28 --thumb
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

extern void *func_020120F4(void *a);
extern void *func_020122C0(void *a, u32 b, TaskFn fn, u32 size);
extern struct Work *func_020124E8(void *task);
extern void *func_02012A30(void *a);

void *func_02029B28(void *a, u16 b)
{
    void *x = func_020120F4(a);
    void *task = func_020122C0(a, 0, func_020298E0, 0x10);
    struct Work *work = func_020124E8(task);

    work->unk00 = a;
    work->unk04 = func_02012A30(x);
    work->unk0E = b;
    return task;
}
