/*
 * function: func_021B78B8
 * address: 0x021B78B8
 * packet: pkt_ov172_021B78B8
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B792C 0x021B792C thumb ov172
 *   func_020061E4 0x020061E4 thumb
 */
typedef unsigned short u16;
extern int func_021B792C(void *, u16 *, u16 *);
extern void func_020061E4(unsigned int);
int func_021B78B8(void *p, char *q)
{
    int result, zero;
    if (*(int *)q == 1) {
        zero = 0;
        result = 0;
        result |= func_021B792C(p, (u16 *)(q + 12), (u16 *)(q + 20));
        result |= func_021B792C(p, (u16 *)(q + 14), (u16 *)(q + 22));
        result |= func_021B792C(p, (u16 *)(q + 16), (u16 *)(q + 24));
        result |= func_021B792C(p, (u16 *)(q + 18), (u16 *)(q + 26));
        if (result == 0) *(int *)q = zero;
        if (*(int *)(q + 8) == 1) {
            *(int *)(q + 8) = 0;
            func_020061E4(0x66e);
        }
        *(int *)(q + 4) = 0;
        return 1;
    }
    return 0;
}
