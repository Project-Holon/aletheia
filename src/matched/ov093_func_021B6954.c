/*
 * function: func_021B6954
 * address:  0x021B6954
 * packet:   pkt_ov093_021B6954
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BA710  0x021BA710  thumb  ov093
 *   func_021B9E7C  0x021B9E7C  thumb  ov093
 *   func_021B9E38  0x021B9E38  thumb  ov093
 */

extern int func_021BA710(int, int);
extern void func_021B9E7C(int, int);
extern void func_021B9E38(int, int, int);

void func_021B6954(int a, int b)
{
    char *p = (char *)a;
    int base = *(int *)p;
    int idx = func_021BA710(*(unsigned char *)(p + 0x46c), b);
    char *q = (char *)(a + 0x20) + b * 0x28;
    char *e = (char *)base + idx * 4;
    int *r = (int *)*(int *)(e + 0x48);
    if (*r != 0)
        func_021B9E7C((int)q, (int)r);
    else
        func_021B9E38((int)q, *(unsigned short *)(p + 0x468), *(int *)(e + 0x34));
}
