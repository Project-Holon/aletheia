/*
 * unit:     no
 * function: func_02027858
 * address:  0x02027858
 * packet:   pkt_02027778
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_020452E8  0x020452E8  arm
 *   func_020456F8  0x020456F8  arm
 *   func_02045730  0x02045730  arm
 *   func_02045770  0x02045770  arm
 *
 * Tear down a task menu: drain every queued item of every cell, destroy the
 * cells, drop the shared owner and release the three blocks.
 *
 * The item count at +0x24 is a `u8` and the two loop counters are `u8` too,
 * which is what the `lsls #24 / lsrs #24` pair after each increment says.
 * +0x24 is past the `ldrb` immediate reach of 31, so every read of it costs
 * an `adds r0, #0x24` first
 * (docs/idioms/thumb-immediate-reach-costs-an-adds.md).
 *
 * The second loop's entry test does not reload the count: it reuses the
 * register the first loop's last bottom-of-loop read left behind, which is
 * why `movs r4, #0 / cmp r0, #0` appears with no load between them.
 *
 * The inner drain is a `while` whose condition is a call, so the condition
 * is emitted twice, once as the entry guard and once as the back edge.
 *
 * EXACT*: the extent runs to 156 bytes because the next function has no
 * label.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02027858.c \
 *       --func func_02027858 --addr 0x02027858 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct TaskMenuOwner {
    u8    pad_00[0x14];
    void *unk_14;
};

struct TaskMenu {
    u8                    pad_00[0x18];
    void                **cells;
    void                 *unk_1c;
    u8                    pad_20[4];
    u8                    count;
    u8                    pad_25[0xf];
    struct TaskMenuOwner *unk_34;
};

struct Descriptor;
struct PrintSys;
extern u32 func_0201C4E4(struct PrintSys *ps);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern u32 func_020307B0(void *p);
extern void func_02041B6C(u32 bit);
extern void func_020452E8(struct Descriptor *d);
extern void func_020456F8(struct Descriptor *d);
extern u8 func_02045730(struct Descriptor *p);
extern void *func_02045770(struct Descriptor *p);

void func_02027858(struct TaskMenu *m)
{
    void *owner;
    u8 i;
    u8 j;

    owner = (void *)func_02045730(m->cells[0]);

    for (i = 0; i < m->count; i++) {
        while (func_0201C6C4(m->unk_34->unk_14,
                             func_02045770(m->cells[i])) != 0) {
            func_0201C4E4(m->unk_34->unk_14);
        }
    }

    for (j = 0; j < m->count; j++) {
        func_020456F8(m->cells[j]);
        func_020452E8(m->cells[j]);
    }

    func_02041B6C((u32)owner);
    func_020307B0(m->cells);
    func_020307B0(m->unk_1c);
    func_020307B0(m);
}
