/*
 * function: func_021F440C
 * address:  0x021F440C
 * packet:   pkt_ov048_021F440C
 * region:   ov048
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F3D38  0x021F3D38  thumb
 *   d_021F50C4     0x021F50C4  data  a2
 *   d_021F50EC     0x021F50EC  data  a4
 *   d_021F5108     0x021F5108  data  a4
 */

typedef unsigned short u16;

extern void func_021F3D38(int *p, int unused, int b, int *c);
extern u16 d_021F50C4[];
extern int d_021F50EC[];
extern int d_021F5108[];

void func_021F440C(int *p, int *q, int i)
{
    struct { u16 a; int b, c, d, e, f, g; } s;

    s.a = d_021F50C4[i];
    s.b = d_021F50EC[i];
    s.c = d_021F5108[i];
    s.d = 2;
    s.e = 0x26;
    s.f = q[3];
    s.g = 0;
    func_021F3D38(p, (int)&s, 8, q);
}
