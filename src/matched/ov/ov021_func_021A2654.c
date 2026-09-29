/*
 * function: func_021A2654
 * address:  0x021A2654
 * packet:   pkt_ov021_021A2654
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A2C28  0x021A2C28  thumb  ov021
 *   func_0204B404  0x0204B404  arm
 *   _s32_div_f     0x0209C0A4  arm
 */

typedef short Pt;

int func_021A2C28(int a);
void func_0204B404(int a, Pt *p, int c);

void func_021A2654(int obj, unsigned short *src)
{
    Pt pt[2];

    pt[0] = src[0];
    pt[1] = src[1];
    if (pt[0] > 320) {
        pt[0] = pt[0] % 320;
    } else if (pt[0] < -64) {
        pt[0] = pt[0] + 320;
    }
    if (pt[1] > 256) {
        Pt *py;
        py = &pt[1];
        *py = *py % 256;
    } else if (pt[1] < -64) {
        pt[1] = pt[1] + 256;
    }
    func_0204B404(func_021A2C28(obj), pt, 0);
}
