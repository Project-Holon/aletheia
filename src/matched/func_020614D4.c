/*
 * function: func_020614D4
 * address:  0x020614D4
 * packet:   pkt_020611D4
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 * symbols:
 *   g_020A8150  0x020A8150  data
 *   g_020A8158  0x020A8158  data
 *   g_020A816C  0x020A816C  data
 *
 * The descriptor-bank allocator of the NNS G2D multi-cell VRAM manager
 * (docs/families/cluster_020611D4.h, subsystem B), installed into the
 * 0x020A8140 callback slot by func_020613D8.  Round the request to 16
 * (0 -> 16), refuse >= 0x7FFF0, then
 *   which != 0: walk the TWO slots at 0x020A8150; a live slot with room
 *     picks a companion by its halfword kind -- kind 0 -> &g_020A816C[1]
 *     (0x020A8184), kind 3 -> &g_020A816C[2] (0x020A819C), else null --
 *     which must have room for HALF the request; bump both cursors and
 *     answer the main slot's base + old cursor;
 *   which == 0: walk the FIVE slots at 0x020A8158 and allocate downward
 *     from the slot's end.
 * The answer packs ((n >> 4) << 16) | ((addr << 13) >> 16) | (which << 31),
 * size-high first as in func_0206216C.
 *
 * CORRECTIONS to docs/notes/pkt_020611D4.c.txt's reading: the TWO-slot
 * walk is 0x020A8150 and the FIVE-slot walk 0x020A8158 (the note had
 * them swapped), and the companions are not pointer variables but the
 * ADDRESSES 0x020A8184 / 0x020A819C, i.e. records 1 and 2 of the bank,
 * which is why they resolve through g_020A816C's own witnesses.
 *
 * What closed it, in order:
 *   1. the dispatch as a `switch` (0 / 3 / default).  Under ../2.0/sp2 it
 *      compiles to the image's chain of real branches to three
 *      one-instruction blocks; the default's null is derived from the loop
 *      counter's zero (`mov r7, r4`) with no help.
 *   2. the room checks must NOT be CSE'd into the bodies: the image reads
 *      cur/end with an `ldm` for the check and re-loads the one it needs
 *      in the body (`ldr r4, [lr]`, `ldr r2, [ip, #4]`).  Spelled through
 *      the fields, both front ends keep the check's load live and come out
 *      4 bytes short with a different allocation.  Reading the pair
 *      through a signed word view -- the ROOM() macro below -- makes the
 *      check's loads a different expression from the body's u32 field
 *      reads.  A `u32 *` view is NOT enough for the end-relative check of
 *      the downward walk (still CSE'd); the `int *` view is.
 *   3. declaration order addr, ok, n, b, a, i (a sweep of 24 orders; the
 *      field order closes only this one) puts n in r3 and addr in r2.
 *
 * Pin evidence (2.0): the same C under dsi/1.1p1 is 356 code+pool bytes
 * against 368, 145 out.  The image's push list {r3-r9, lr} and the
 * derived-zero default both come out under 2.0 only, the same pin its
 * sibling allocator func_020616CC carries.
 *
 * EXACT* (not a byte difference): the listing extent (376) runs over the
 * unlabelled 8-byte stub func_02061644 at 0x02061644, already its own
 * EXACT entry; the function is 348 code bytes plus a 20-byte pool.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020614D4.c \
 *       --func func_020614D4 --addr 0x020614D4 --arm --cc ../2.0/sp2
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Slot {
    u32 cur;      /* 0x00 */
    u32 end;      /* 0x04 */
    u32 enable;   /* 0x08 */
    u32 unk_0c;
    u16 kind;     /* 0x10 */
    u16 pad_12;
    u32 base;     /* 0x14 */
};

extern struct Slot *g_020A8150[2];
extern struct Slot *g_020A8158[5];
extern struct Slot g_020A816C[5];

/* free extent of a slot, read through a signed word view */
#define ROOM(s) ((u32)((int *)(s))[1] - (u32)((int *)(s))[0])

u32 func_020614D4(u32 size, u32 which)
{
    u32 addr;
    u32 ok;
    u32 n;
    struct Slot *b;
    struct Slot *a;
    int i;

    if (size == 0)
        n = 0x10;
    else
        n = (size + 0xf) & ~0xfu;
    if (n >= 0x7fff0u)
        return 0;

    if (which != 0) {
        for (i = 0; i < 2; i++) {
            a = g_020A8150[i];
            if (a->enable == 0)
                continue;
            if (ROOM(a) < n)
                continue;
            switch (a->kind) {
            case 0:  b = &g_020A816C[1]; break;
            case 3:  b = &g_020A816C[2]; break;
            default: b = 0; break;
            }
            if (b->enable == 0)
                continue;
            if (ROOM(b) < (n >> 1))
                continue;
            ok = 1;
            addr = a->cur;
            a->cur = addr + n;
            b->cur += n >> 1;
            addr += a->base;
            goto done;
        }
        ok = 0;
    } else {
        for (i = 0; i < 5; i++) {
            struct Slot *c = g_020A8158[i];
            if (c->enable == 0)
                continue;
            if (ROOM(c) < n)
                continue;
            ok = 1;
            c->end -= n;
            addr = c->end + c->base;
            goto done;
        }
        ok = 0;
    }
done:
    if (ok == 0)
        return 0;
    return ((n >> 4) << 16) | ((addr << 13) >> 16) | (which << 31);
}
