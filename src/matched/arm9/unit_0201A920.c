/*
 * unit:     yes
 * address:  0x0201A920
 * packet:   pkt_0201A5FC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_0201A920, sub_0201A948, sub_0201A954, sub_0201A98C,
 *           sub_0201A9C8
 *
 * pokeparty.c: the container's constructor, its initialiser, and the add and
 * remove operations.  The allocation at 0x0201A930 names the file itself, the
 * string at 0x020A7304 being "pokeparty.c"; the line numbers 65 (here) and
 * 382 (src/matched/unit_0201AB48.c) put these two ranges in one original
 * source file with about three hundred lines between them.
 *
 * The container is 0x534 bytes: a capacity at +0x00, a live count at +0x04,
 * six 0xDC byte records from +0x08, and one byte at +0x530.  Two independent
 * things say the last byte is a member rather than padding: the initialiser
 * stores zero into it, and it reaches it with `subs r0, r7, #4` off the
 * pooled 0x534, then a register-offset `strb`, because 0x530 is far past the
 * byte immediate's reach of 31
 * (docs/idioms/thumb-immediate-reach-costs-an-adds.md).  Writing
 * `sizeof(struct Party)` for the clear and the allocation is what puts that
 * one constant in the pool for both uses.
 *
 * sub_0201A948 is the six-slot spelling of sub_0201A954 and is a bare tail
 * call, three instructions and a pool word
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 *
 * sub_0201A98C's guard is an early return on the full container: the
 * conditional branch is taken into the body, so the fall-through arm is the
 * failure the source wrote first
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * sub_0201A9C8 compacts the array by copying each record down one slot, and
 * its loop bound re-reads `p->count` on every iteration rather than caching
 * it, which is visible as the `ldr`/`subs #1` pair inside the loop.
 *
 * symbols:
 *   sub_0201A920_File  0x020A7304  data
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201A920.c \
 *       --addr 0x0201A920 --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;
typedef int           s32;

struct PartyMon {
    u32 w[0x37];
};

struct Party {
    s32 capacity;
    s32 count;
    struct PartyMon mon[6];
    u8  unk530;
};

extern void *func_02030734(u32 heap, u32 size, u32 align, const char *file, u32 line);
extern void MIi_CpuClearFast(u32 value, void *dest, u32 size);
extern void func_02017528(void *rec);
extern void sub_0201ACDC(struct Party *p, s32 idx, u32 v);

extern const char sub_0201A920_File[];

void sub_0201A948(struct Party *p);
void sub_0201A954(struct Party *p, s32 capacity);

struct Party *sub_0201A920(u32 heap)
{
    struct Party *p = (struct Party *)func_02030734(heap, sizeof(struct Party), 0,
                                                   sub_0201A920_File, 65);

    sub_0201A948(p);
    return p;
}

void sub_0201A948(struct Party *p)
{
    sub_0201A954(p, 6);
}

void sub_0201A954(struct Party *p, s32 capacity)
{
    s32 i;

    MIi_CpuClearFast(0, p, sizeof(struct Party));
    p->capacity = capacity;
    p->count = 0;
    p->unk530 = 0;
    for (i = 0; i < 6; i++) {
        func_02017528(&p->mon[i]);
    }
}

u32 sub_0201A98C(struct Party *p, const struct PartyMon *src)
{
    if (p->count >= p->capacity) {
        return 0;
    }
    p->mon[p->count] = *src;
    sub_0201ACDC(p, p->count, 1);
    p->count = p->count + 1;
    return 1;
}

u32 sub_0201A9C8(struct Party *p, s32 idx)
{
    s32 i;

    for (i = idx; i < p->count - 1; i++) {
        p->mon[i] = p->mon[i + 1];
    }
    func_02017528(&p->mon[i]);
    p->count = p->count - 1;
    return 1;
}
