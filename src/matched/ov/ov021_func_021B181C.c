/*
 * function: func_021B181C
 * address:  0x021B181C
 * packet:   pkt_ov021_021B181C
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
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_0215A5EC  0x0215A5EC  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0201296C  0x0201296C  thumb
 *   func_0216E3D0  0x0216E3D0  thumb  ov010
 *   func_0216CE6C  0x0216CE6C  thumb  ov010
 *   func_0216DAF8  0x0216DAF8  thumb  ov010
 */

typedef signed short s16;

void *func_0215A5F4(void *p);
int *func_02158F58(void *a);
int func_02159B10(int a, int b);
int func_02188C9C(int a);
int func_0215A5EC(int b);
void *func_0215A5E4(void *a0);
int func_0201296C(void *a);
int func_0216E3D0(int a, int b);
int func_0216CE6C(int a, s16 b, s16 c, int d, int e, int f, int g, int h);
void func_0216DAF8(int a);

int func_021B181C(int a, int b)
{
    int r6;
    int v0;
    int v1;
    int v2;
    int v3;
    int v4;
    int r7;
    int r5;
    int r0;

    r6 = (int)func_02158F58(func_0215A5F4((void *)b));
    v0 = func_02159B10(a, b);
    v1 = func_02159B10(a, b);
    v2 = func_02159B10(a, b);
    v3 = func_02159B10(a, b);
    v4 = func_02159B10(a, b);
    r7 = func_02159B10(a, b);
    r5 = func_02188C9C(((int *)r6)[1]);
    r6 = func_0215A5EC(b);
    r0 = func_0216E3D0(func_0201296C(func_0215A5E4((void *)b)), v4);
    r0 = func_0216CE6C(r6, v0, v1, v2, v3, r0, r7, r5);
    if (r0 != 0) {
        func_0216DAF8(r0);
    }
    return 0;
}
