/*
 * PARKED AT DIFF.  Ten or more concrete bytes, all of them colouring: the
 * pinned front end puts the record count in r3, the array pointer in r2, the
 * index in r0 and the counter in ip, where the original has the count in ip,
 * the counter in r3, the index in r2 and the array in r1.  All 24 declaration
 * orders of the four locals were compiled (with the assignments fixed) and the
 * best is ten bytes off; the two body shapes - the counter incremented in an
 * `if` versus assigned from a comparison - land on the same residue.
 *
 * The sibling that works is src/matched/func_02036670.c, the same loop
 * returning the first matching record instead of counting them: it needed only
 * `i` declared before `n`, so the colouring here is driven by the extra
 * counter rather than by the loop itself.
 *
 * function: func_020366C0
 * address:  0x020366C0
 * packet:   pkt_020366C0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * blocker:  four locals colour into different registers than the original; invariant across all 24 declaration orders
 *
 * Counts how many of the p->unk1C records (stride 0x14) at p->unk18 have a
 * non-zero halfword at +0x0E.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_020366C0.c \
 *       --func func_020366C0 --addr 0x020366C0 --cc 1.1p1 --arm --diff
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed int     s32;
typedef unsigned int   u32;

u32 func_020366C0(u32 *p)
{
    u8  *q;
    s32  n;
    s32  i;
    u32  count;

    q = (u8 *)p[6];
    n = (s32)p[7];
    count = 0;
    for (i = 0; i < n; i++) {
        if (*(u16 *)(q + 0x0E) != 0)
            count++;
        q += 0x14;
    }
    return count;
}
