/*
 * function: func_021DA748
 * address: 0x021DA748
 * packet: pkt_ov093_021DA748
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte alignment padding.
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D76BC 0x021D76BC thumb ov093
 *   func_021D5B48 0x021D5B48 thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 */
extern int func_021D775C(int);
extern int func_021D76BC(int, unsigned int);
extern int func_021D5B48(void *);
extern void *func_021C7CF4(int *, int);

void func_021DA748(int a, int *b, int c, int *d)
{
    int k = 4;
    if (c == func_021D775C(k)) {
        if (func_021D5B48(func_021C7CF4(b, c)) != 0) {
            *d = func_021D76BC(0x3a, k);
            return;
        }
        *d = 0;
    }
}
