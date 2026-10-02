/*
 * function: func_021B17B4
 * address:  0x021B17B4
 * packet:   pkt_ov021_021B17B4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 */

typedef signed short s16;

void *func_0215A5F4(void *p);
int *func_02158F58(int a);
void *func_02188CB4(unsigned char *p);
void *func_021A3074(unsigned char *p);
s16 *func_02159AE8(void *a0, void *a1);
s16 func_0216D83C(int a);
s16 func_0216D86C(int a);

int func_021B17B4(int a, int b)
{
    void *r5;
    s16 *r6;
    s16 *r4;

    r5 = func_021A3074(func_02188CB4(func_02158F58(func_0215A5F4((void *)b))[1]));
    r6 = func_02159AE8((void *)a, (void *)b);
    r4 = func_02159AE8((void *)a, (void *)b);
    *r6 = func_0216D83C(r5);
    *r4 = func_0216D86C(r5);
    return 0;
}
