/*
 * function: func_021DABF4
 * address: 0x021DABF4
 * packet: pkt_ov093_021DABF4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D76BC 0x021D76BC thumb ov093
 */
extern int func_021D775C(int);
extern int func_021D76BC(int, unsigned int);

void func_021DABF4(int a, int b, int c, int *d)
{
    int k;
    if (c == func_021D775C(2)) {
        k = 0x51;
        if (func_021D775C(k) == 0)
            *d = func_021D76BC(k, 1);
    }
}
