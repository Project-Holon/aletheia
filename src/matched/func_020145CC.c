/*
 * function: func_020145CC
 * address:  0x020145CC
 * packet:   pkt_02014584
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  +0024 THM_CALL func_0215FA34       : 0215FA34 (arm, from name) has no witness outside 020145CC..020145FC; 2 overlays overlap this address (ov009, ov010), none resolvable without a region hint on the symbols: line
 */

typedef unsigned int u32;

extern void *func_020122C0(void *a0, int a1, int a2, int a3);
extern u32 *func_020124E8(void);
extern void *func_020120F4(void *a0);
extern void func_0215FA34(void);

void *func_020145CC(void *a0)
{
    void *r6 = func_020122C0(a0, 0, 0x02014585, 0x10);
    u32 *r4 = func_020124E8();

    r4[0] = (u32)a0;
    r4[1] = 0;
    r4[2] = (u32)func_020120F4(a0);
    func_0215FA34();
    return r6;
}
