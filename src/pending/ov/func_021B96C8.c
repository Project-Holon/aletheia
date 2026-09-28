/*
 * function: func_021B96C8
 * address:  0x021B96C8
 * packet:   pkt_ov217_021B96C8
 * region:   ov217
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
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
 */

extern void func_021B970C(void);
extern void func_021B9774(void *, int *, int);
extern void func_021C09BC(int, int);

void func_021B96C8(void *a, int *p, int c)
{
    func_021B970C();
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