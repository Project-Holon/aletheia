/*
 * function: func_0219D3F0
 * address:  0x0219D3F0
 * packet:   pkt_ov021_0219D3F0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0219C4AC  0x0219C4AC  thumb  ov021
 *   func_020500F0  0x020500F0  arm
 *   d_021D8064     0x021D8064  data a2
 *   d_021D75C4     0x021D75C4  data ov021 a2
 */

extern int func_0219C4AC(int, int);
extern unsigned short func_020500F0(int, void *, int);
extern unsigned short d_021D8064[];
extern unsigned short d_021D75C4[];

unsigned short func_0219D3F0(int *o, int a1, int a2, int a3, int a4, int a5)
{
    unsigned short *q;
    struct {
        int w0;
        unsigned char b4;
        unsigned char b5;
        unsigned char b6;
        unsigned char b7;
        int w2;
    } s;

    if (a5 == -1) {
        return (unsigned short)func_0219C4AC(o[1], a4);
    }
    s.w0 = a4;
    s.b4 = 0;
    s.b5 = d_021D8064[a3];
    q = d_021D75C4 + a2 * 2;
    s.b6 = q[0];
    s.b7 = q[1];
    s.w2 = a5;
    return func_020500F0(o[1], &s, 1);
}
