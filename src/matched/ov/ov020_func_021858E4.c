/*
 * function: func_021858E4
 * address:  0x021858E4
 * packet:   pkt_ov020_021858E4
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012844  0x02012844  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_02012964  0x02012964  thumb
 *   func_02162744  0x02162744  thumb  ov010
 *   func_02162740  0x02162740  thumb  ov010
 *   func_0216CEAC  0x0216CEAC  thumb  ov010
 */

int func_02012844(int a);
int func_0201296C(int a);
int func_02012964(int a);
int func_02162744(int a);
int func_02162740(int a);
void func_0216CEAC(int a, int b, int c, int d, int e);

void func_021858E4(int a, const short *p)
{
    int t = func_02012844(a);
    int v = func_02162744(t);

    if (v != 0) {
        int r6 = func_0201296C(a);
        int r5 = func_02012964(a);
        int r1 = func_02162740(t);
        int s = p[2];
        func_0216CEAC(r5, r1, s, v, r6);
    }
}
