/*
 * function: sub_0204ADEC
 * address:  0x0204ADEC
 * packet:   pkt_0204ADEC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 *
 * status:   EXACT
 *
 * symbols:
 *   g_02146A74     0x02146A74  data
 *   func_0206380C  0x0206380C  arm
 *   func_02063800  0x02063800  arm
 *   func_020862F0  0x020862F0  arm
 *   func_0207E51C  0x0207E51C  arm
 *   func_0207E5D0  0x0207E5D0  arm
 *
 * Flush both halves of one slot of the 0x18-byte-stride table at +0x110 of
 * the singleton behind 0x02146A74 into the destination the caller supplies.
 * Each half is guarded by func_0206380C, fetched with func_02063800 and
 * written through func_0207E51C (selector 1) or func_0207E5D0 (selector 2),
 * with func_020862F0 invalidating the destination first.
 *
 * `count` is in 32-byte units; zero means "use the length the destination
 * already records at +8" instead.  The shift happens unconditionally and is
 * overwritten by the predicated `ldreq`, so the guard has to be written as
 * a plain `if` after the shift, not as a ternary around it.
 *
 * `size` has to be spelled as a fourth parameter that the body immediately
 * overwrites, not as a local: as a local it takes r4 and the `idx * 0x18`
 * temporary takes r5, which is the original's assignment exactly swapped
 * and the only difference in the whole function.  The image says the
 * fourth argument is not actually passed: the one call site, the `blx` at
 * 0x0202DAD2, sets r0, r1 and r2 and leaves r3 alone.  So read the fourth
 * parameter as a register-allocation device for this rewrite, not as
 * evidence about the function's real arity.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Slot {
    u8 pad_00[0x18];
};

struct Ctx {
    u8           pad_00[0x110];
    struct Slot *slots;
};

struct Dest {
    u8    pad_00[8];
    u32   unk_08;
    void *unk_0c;
};

extern struct Ctx *g_02146A74;

extern u32 func_0206380C(struct Slot *slot, u32 selector);
extern int func_02063800(char *p, int i);
extern void func_020862F0(void *dest, u32 size);
extern void func_0207E51C(void *dest, void *src, u32 size);
extern void func_0207E5D0(void *dest, void *src, u32 size);

void sub_0204ADEC(u32 idx, struct Dest *dest, u32 count, u32 size)
{
    size = count << 5;

    if (count == 0) {
        size = dest->unk_08;
    }

    if (func_0206380C(&g_02146A74->slots[idx], 1) != 0) {
        void *src = (void *)func_02063800((char *)(&g_02146A74->slots[idx]), 1);

        func_020862F0(dest->unk_0c, size);
        func_0207E51C(dest->unk_0c, src, size);
    }

    if (func_0206380C(&g_02146A74->slots[idx], 2) != 0) {
        void *src = (void *)func_02063800((char *)(&g_02146A74->slots[idx]), 2);

        func_020862F0(dest->unk_0c, size);
        func_0207E5D0(dest->unk_0c, src, size);
    }
}
