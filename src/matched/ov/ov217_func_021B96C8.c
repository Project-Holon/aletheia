/*
 * function: func_021B96C8
 * address:  0x021B96C8
 * packet:   pkt_ov217_021B96C8
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 2026-10-05 (wD5 lane01): EXACT. func_021B970C takes (a, p) (its listing reads r0 and r1);
 *   the argless call was the cause of the p/c register swap. Older notes below.
 * Note 2026-10-04 (wD2 lane12): also tried p typed int with (int *) cast at the deref and int-typed callee param. Same 5 bytes (p r6, c r4; original p r4, c r6, a r5).
 *
 * blocker:  5 concrete bytes, all home-register assignment for the 2nd/3rd
 *           parameters. Original homes param1 (the int* p) in r4 and param2
 *           (int c) in r6, in plain declaration order; this front end
 *           consistently homes the pointer param in r6 and the int param in
 *           r4 whenever the two types differ. With both params typed int the
 *           home order is right but then the pointer use forces the same
 *           r1/r2 swap. Every other byte matches.
 *
 * symbols:
 *   func_021B970C  0x021B970C  thumb  ov217
 *   func_021B9774  0x021B9774  thumb  ov217
 *   func_021C09BC  0x021C09BC  thumb  ov217
 *
 * Note 2026-10-04 (wD1 lane06): Retried: void-pointer, u32, u8, s16 and const types for p and c, local v = *p, if-chains, char* a. Still 5 bytes: p lands in r6 and c in r4 (original p r4, c r6).
 *
 * note 2026-10-05 (wD4 lane13): tried c as void * with a void * callee parameter, a q = p alias, and locals a/p/c copied from the parameters in three declaration orders (h1-h3). All give the same 5 bytes. Observation: the original colours c, a, p in that order into r6, r5, r4; ours colours p, a, c into r6, r5, r4 (exact reverse).
 */

extern void func_021B970C(void *, int *);
extern void func_021B9774(void *, int *, int);
extern void func_021C09BC(int, int);

void func_021B96C8(void *a, int *p, int c)
{
    func_021B970C(a, p);
    func_021B9774(a, p, c);
    switch (*p) {
    case 1:
        func_021C09BC(*(int *)((char *)a + 0xc), 1);
        break;
    case 2:
        func_021C09BC(*(int *)((char *)a + 0xc), 2);
        break;
    case 3:
        func_021C09BC(*(int *)((char *)a + 0xc), 3);
        break;
    }
}