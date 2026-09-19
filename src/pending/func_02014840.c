/*
 * function: func_02014840
 * address:  0x02014840
 * packet:   pkt_02014628
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocker:  +0034 ABS32 func_020147B0          : 020147B0 (thumb, from name) has no witness outside 02014840..02014878
 */

typedef unsigned int u32;

extern void *func_020122C0(char *a0, int a1, int a2, int a3);
extern u32 *func_020124E8(void);
extern void func_020147B0(void);

void *func_02014840(char *a0, int a1, int a2, int a3, int a4, int a5, int a6)
{
    void *r = func_020122C0(a0, 0, (int)func_020147B0, 0x1c);
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
