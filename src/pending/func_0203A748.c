/*
 * function: func_0203A748
 * address:  0x0203A748
 * packet:   pkt_0203A574
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * isa:      arm
 * status:   DIFF
 * blocker:  five instructions: same colouring residue as src/pending/func_0203A70C.c, one word further into the record
 *
 * symbols:
 *   func_0203A67C  0x0203A67C  arm
 *
 * The second accessor of the pair in src/matched/func_0203A70C.c: the second
 * word of the same eight-byte record.  The only difference in the code is that
 * the scaled index is `add`ed into the record base instead of being used as a
 * load offset.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203A748.c \
 *       --func func_0203A748 --addr 0x0203A748 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct Pair {
    u32 a;
    u32 b;
};

extern void *func_0203A67C(void);

u32 func_0203A748(u32 idx)
{
    struct Pair **q;

    q = (struct Pair **)func_0203A67C();
    if (q == 0)
        return 0;
    return (*q)[idx].b;
}
