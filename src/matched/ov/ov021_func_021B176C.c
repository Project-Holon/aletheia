/*
 * function: func_021B176C
 * address:  0x021B176C
 * packet:   pkt_ov021_021B176C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5EC  0x0215A5EC  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0216DE94  0x0216DE94  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 */

typedef signed short s16;

int func_0215A5EC(int b);
unsigned int func_02159B10(void *a0, void *a1);
int func_0216DE94(int a, int b);
s16 *func_02159AE8(void *a0, void *a1);
s16 func_0216D83C(int a);
s16 func_0216D86C(int a);

int func_021B176C(int a, int b)
{
    int r6;
    s16 *r7;
    s16 *r4;

    r6 = func_0215A5EC(b);
    r6 = func_0216DE94(r6, func_02159B10((void *)a, (void *)b));
    r7 = func_02159AE8((void *)a, (void *)b);
    r4 = func_02159AE8((void *)a, (void *)b);
    *r7 = func_0216D83C(r6);
    *r4 = func_0216D86C(r6);
    return 0;
}
