/*
 * function: func_021B1698
 * address:  0x021B1698
 * packet:   pkt_ov021_021B1698
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0201134C  0x0201134C  thumb
 *   func_021B1668  0x021B1668  thumb  ov021
 *   func_02197D3C  0x02197D3C  thumb  ov021
 *   func_0215A6DC  0x0215A6DC  thumb  ov010
 */

void *func_0215A5F4(void *p);
int func_02159B10(int *a, int b);
int func_0201134C(int *a);
int func_021B1668(int b, int c);
int func_02197D3C(int a, int b);
void func_0215A6DC(int b, int c);

int func_021B1698(int *a, int b)
{
    int r7;
    int r6;
    int r0;

    func_0215A5F4((void *)b);
    r7 = func_02159B10(a, b);
    r6 = func_0201134C(a);
    r0 = func_021B1668(b, r7);
    if (r0 == 0) {
        return 0;
    }
    func_0215A6DC(b, func_02197D3C(r0, a[5] + r6));
    return 0;
}
