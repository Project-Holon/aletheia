/*
 * function: func_02036670
 * address:  0x02036670
 * packet:   pkt_02036670
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Finds the first of `p->unk1C` records (stride 0x14) whose halfword at +0x0E
 * is zero and returns a pointer to it, or NULL when the count is not positive
 * or no record matches.  The found case is a bare `bxeq lr` with the moving
 * pointer still in r0, which is what makes the return type a pointer rather
 * than a boolean: the function returns the record it found, not 1.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02036670.c \
 *       --func func_02036670 --addr 0x02036670 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed int     s32;
typedef unsigned int   u32;

u8 *func_02036670(u32 *p)
{
    u8  *q;
    s32  i;
    s32  n;

    q = (u8 *)p[6];
    n = (s32)p[7];
    for (i = 0; i < n; i++) {
        if (*(u16 *)(q + 0x0E) == 0)
            return q;
        q += 0x14;
    }
    return 0;
}
