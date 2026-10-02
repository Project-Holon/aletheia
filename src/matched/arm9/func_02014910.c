/*
 * function: func_02014910
 * address:  0x02014910
 * packet:   pkt_02014628
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  +0028 ABS32 func_02014878          : 02014878 (thumb, from name) has no witness outside 02014910..0201493C
 *           Closed at the bottom, not unfiled: no branch anywhere in the image
 *           reaches 0x02014878, so only a `matched` entry could attest it, and
 *           func_02014878 is itself capped at MATCH by two own-pool words
 *           (0x0000005B at 0x02014900, 0x00000083 at 0x02014908 - each occurs
 *           exactly once in arm9, inside its own compared range).  See
 *           docs/notes/pkt_02014808.c.txt.
 */

typedef unsigned int u32;

extern void *func_020122C0(char *a0, int a1, int a2, int a3);
extern u32 *func_020124E8(void *desc);
extern void func_02014878(void);

void *func_02014910(char *a0, int a1, int a2, int a3)
{
    void *r = func_020122C0(a0, 0, (int)func_02014878, 0x10);
    u32 *p = func_020124E8(r);

    p[0] = (u32)a0;
    p[1] = a1;
    p[2] = a2;
    p[3] = a3;
    return r;
}
