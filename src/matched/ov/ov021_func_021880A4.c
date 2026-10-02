/*
 * function: func_021880A4
 * address:  0x021880A4
 * packet:   pkt_ov021_021880A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020140B4  0x020140B4  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02012110  0x02012110  thumb
 *   func_020371AC  0x020371AC  arm
 */

void func_020140B4(int h);
void func_020307B0(void *p);
void func_02012110(void *p, void *v);
void func_020371AC(int a, int b);

void func_021880A4(int *p)
{
    int q = p[1];
    func_020140B4(p[3]);
    func_020307B0(p);
    func_02012110((void *)q, 0);
    func_020371AC(0, 0);
}
