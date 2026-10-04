/*
 * function: func_021552E8
 * address:  0x021552E8
 * packet:   pkt_ov009_021552E8
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02059E38  0x02059E38  arm
 *   func_0203C9AC  0x0203C9AC  arm
 *   func_0203CA98  0x0203CA98  arm
 */

int func_02059E38(int *a, int *b);
typedef unsigned int   u32;
void func_0203C9AC(int a, u32 b, u32 c, u32 d);
u32 func_0203CA98(void);

int func_021552E8(void)
{
    int a, b, r;

    r = func_02059E38(&a, &b);
    if (r != 0)
        func_0203C9AC(a, b, r, 0);
    if (r == 0)
        return 0;
    if (a == 0)
        return -10000;
    r = ((int *)func_0203CA98())[3];
    if (r == 0)
        r = a;
    return r;
}
