/*
 * function: func_02011EAC
 * address:  0x02011EAC
 * packet:   pkt_02011D9C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02011FCC     0x02011FCC  thumb
 *
 * Only the fourth parameter is used, and it is moved straight out of r3 into
 * r0 at entry - a one-argument wrapper whose first three arguments are the
 * caller's leftovers (r0..r2 are untouched, which is what the prologue's
 * `adds r0, r3, #0` says).
 *
 * blocker:  label.  The only branch to 0x02011FCC anywhere in the image is the
 *           call inside this function (checked: `label` finds no outside
 *           branch, and no EXACT manifest entry covers 0x02011FCC, so
 *           `matched` does not reach it either).  No cut helps - shrinking
 *           the range to this function keeps the call inside it.  Writing
 *           0x02011FCC (144 bytes, packet pkt_02011F28) as an EXACT entry
 *           would close this one; nothing else will.
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02011EAC.c \
 *       --func func_02011EAC --addr 0x02011EAC --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

extern int func_02011FCC(char *p);

u32 func_02011EAC(u32 a0, u32 a1, u32 a2, u32 a3)
{
    if (func_02011FCC((char *)a3) != 0)
        return 1;
    return 0;
}
