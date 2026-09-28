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
 * promoted: seed round 9, EXACT (fresh match.py one) once the ov010 callees
 *           0x0215FA34 and 0x0215FA44 were seeded in layout/function_starts.txt
 * note:     re-verified 2026-09-20: MATCH; see verify output
 * note:     re-verified 2026-09-22 (family wave 6, field_status.c): still
 *           MATCH, 3 of 4 sites resolved, no change to the C.  The single
 *           blocker 0x0215FA34 is the same overlay-export class as the
 *           two in sub_02014488.c: ov009 and ov010 both cover it and
 *           neither labels a function there, so no region hint helps.
 * blocker:  +0024 THM_CALL func_0215FA34       : 0215FA34 (arm, from name) has no witness outside 020145CC..020145FC; 2 overlays overlap this address (ov009, ov010), none resolvable without a region hint on the symbols: line
 * symbols:
 *   func_0215FA34  0x0215FA34  thumb  ov010
 * wave15:   overlay callees are unlabelled Thumb starts: 0x0215FA34 and
 *           0x0215FA44 in ov010 (.word 0x4B024801, ldr r0/ldr r3 thunks),
 *           0x02188BD8 in ov021; need seeds in those overlays' listings.
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
