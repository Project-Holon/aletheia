/*
 * function: func_021C14DC
 * address:  0x021C14DC
 * packet:   pkt_ov217_021C14DC
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_02148D8C  0x02148D8C  data  a4
 *   d_02148D98  0x02148D98  data  a4
 *   d_02148DA4  0x02148DA4  data  a4
 *   d_02148B98  0x02148B98  data  a4
 *   d_02148BCC  0x02148BCC  data  a4
 *   d_02148B54  0x02148B54  data  a4
 *   func_0207D7C4  0x0207D7C4  arm
 *   func_0207D760  0x0207D760  arm
 *   func_0206A700  0x0206A700  arm
 *   func_0207BCA0  0x0207BCA0  arm
 *   func_0207C554  0x0207C554  arm
 *   func_0206A854  0x0206A854  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct { int x, y, z; } V;

extern V d_02148D8C;
extern V d_02148D98;
extern V d_02148DA4;
extern V d_02148B98;
struct Gx {
    u8 pad[0x7C];
    u32 flags;
};

extern struct Gx d_02148BCC;
extern V d_02148B54;

extern void func_0207D7C4(V *a, V *b, V *c, int d, int e);
extern void func_0207D760(int a, int b, int c, int d, int e, int f, int g, int h, int i);
extern void func_0206A700(void);
extern void func_0207BCA0(V *a, V *b, V *c, V *d);
extern void func_0207C554(int a, int b, int c, int d, int e, int f, int g, V *h);
extern void func_0206A854(void);

void func_021C14DC(u8 *p)
{
    V a;
    V b;
    V c;

    a.x = 0;
    a.y = 0;
    a.z = 0x1000;
    b.x = 0;
    b.y = 0x1000;
    b.z = 0;
    c.x = 0;
    c.y = 0;
    c.z = 0;
    func_0207D7C4(&a, &b, &c, 1, 0);
    func_0207D760(0x1000, -0x1000, -0x1554, 0x1554, 0x19A, 0x5000, 0x1000, 1, 0);
    func_0206A700();
    d_02148D8C = a;
    d_02148D98 = b;
    d_02148DA4 = c;
    func_0207BCA0(&a, &b, &c, &d_02148B98);
    d_02148BCC.flags &= ~0xE8;
    func_0207C554(0x1000, -0x1000, -0x1554, 0x1554, 0x19A, 0x5000, 0x1000, &d_02148B54);
    d_02148BCC.flags &= ~0x50;
    func_0206A854();
}
