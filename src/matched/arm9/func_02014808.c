/*
 * function: func_02014808
 * address:  0x02014808
 * packet:   pkt_02014628
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * promoted: from src/pending on 2026-09-19, no C change: its blocker is filed,
 *           every relocation site resolves and match.py one reports EXACT.
 * status:   EXACT
 * blocker:  +0034 ABS32 func_02014758          : 02014758 (thumb, from name) has no witness outside 02014808..02014840
 */

typedef unsigned int u32;

extern void *func_020122C0(char *a0, int a1, int a2, int a3);
extern u32 *func_020124E8(void);
extern void func_02014758(void);

void *func_02014808(char *a0, int a1, int a2, int a3, int a4, int a5, int a6)
{
    void *r = func_020122C0(a0, 0, (int)func_02014758, 0x1c);
    u32 *p = func_020124E8();

    p[0] = (u32)a0;
    p[1] = a1;
    p[2] = a2;
    p[3] = a3;
    p[4] = a4;
    p[5] = a5;
    p[6] = a6;
    return r;
}
