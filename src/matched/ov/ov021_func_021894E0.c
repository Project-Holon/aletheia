/*
 * function: func_021894E0
 * address:  0x021894E0
 * packet:   pkt_ov021_021894E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02162744  0x02162744  thumb  ov010
 *   func_0201296C  0x0201296C  thumb
 *   func_02162740  0x02162740  thumb  ov010
 *   func_0216CEAC  0x0216CEAC  thumb  ov010
 */

int func_02162744(int c);
int func_0201296C(int a);
int func_02162740(int c);
void func_0216CEAC(int b, int x, int d, int r, int y);

void func_021894E0(int a, int b, int c, int d)
{
    int r = func_02162744(c);
    int y;
    if (r != 0) {
        y = func_0201296C(a);
        func_0216CEAC(b, func_02162740(c), d, r, y);
    }
}
