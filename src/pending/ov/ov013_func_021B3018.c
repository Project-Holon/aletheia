/*
 * function: func_021B3018
 * address: 0x021B3018
 * packet: pkt_ov013_021B3018
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: DIFF
 * residual: 6 bytes differ of 76. Original: ldr r1(4C2C), mov r2,#0, str [r1,#4], ldr r0(3C50), str [r1]...
 *   Ours: the ldr of the 3C50 pool word comes before the first store.
 * note 2026-10-05 (wave P21 L6): extent 76 B (64 B code + 3 pool words), no calls, ARM. No twin: the
 *   3C50 pool word is used by ov013 021B3064 and 021B3250 only (no init twin). Older draft in
 *   docs/notes/pkt_ov013_021B3018.c.txt re-read: constants, store order and argument order match the
 *   listing, so the residue is only the pool-load slot. Tried (all 6 B unless noted, 19 compiles):
 *   plain int arrays; full structs for 4C2C and 3C50; chained zero `a[0]=a[1]=0` (6 B) and
 *   `a[1]=a[0]=0` (7 B); natural store order 4C2C[0..2] then 3C50 (12 B); 3C50 stored between 4C2C
 *   stores (8 B); do-while loop; named pointer locals for 4C2C and 3C50 (assigned mid-function);
 *   static inline clear helper for 3C50 (8 B) and for 4C2C (11 B); six per-function pragmas
 *   (scheduling, peephole, opt_lifetimes, opt_common_subs, opt_dead_assignments off all 6 B;
 *   opt_propagation off 62 B). scheduling off gives the same slot, so the IR, not the scheduler,
 *   places the load. Observed rule: with 2 stores before the first 3C50 use the load goes above
 *   both; with 3 stores before it, after the second. The original has it after the first store of
 *   two, which no source ordering tried reproduces. Only a dead extra store would shift it; that is
 *   a stand-in, not filed.
 * symbols:
 *   d_021B4C38 0x021B4C38 data a4
 *   d_021B4C2C 0x021B4C2C data a4
 *   d_021B3C50 0x021B3C50 data a4
 */
extern int d_021B4C38[4];
extern int d_021B4C2C[3];
extern int d_021B3C50[2];
void func_021B3018(void)
{
    int i;
    for (i = 0; i < 4; i++) d_021B4C38[i] = 0x1000000;
    d_021B4C2C[1] = 0;
    d_021B4C2C[0] = 0;
    d_021B3C50[0] = 0;
    d_021B3C50[1] = 0;
    d_021B4C2C[2] = 0;
}
