/*
 * function: func_0217E0B0
 * address: 0x0217E0B0
 * packet: pkt_ov176_0217E0B0
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203CBAC 0x0203CBAC arm
 *   func_0203CD98 0x0203CD98 arm
 *   func_0203A574 0x0203A574 arm
 *   func_021799C0 0x021799C0 thumb ov015
 *   func_0203D0DC 0x0203D0DC arm
 *   func_0203D1B4 0x0203D1B4 arm
 *   d_0217E564 0x0217E564 data a4
 *   d_0217E630 0x0217E630 data a4
 *   d_0217E544 0x0217E544 data a4
 *   func_0217E524 0x0217E524 thumb ov176
 */
struct Req;
extern void func_0203CBAC(struct Req *req, unsigned int a2, unsigned int a3);
extern int func_0203CD98(void);
typedef unsigned int   u32;
extern void func_0203A574(u32 a, u32 b, u32 c, u32 d);
extern void func_021799C0(int);
extern int func_0203D0DC(int a0);
extern int func_0203D1B4(void);
extern const unsigned d_0217E564[];
extern int d_0217E630;
extern const unsigned d_0217E544[];
extern int func_0217E524(int a, int b);
int func_0217E0B0(unsigned *p)
{
    switch (*p) {
    case 0:
        func_0203CBAC((struct Req *)d_0217E564, 0, 0);
        d_0217E630 = 1;
        *p = 1;
        break;
    case 1:
        if (func_0203CD98())
            *p = 2;
        break;
    case 2:
        func_0203A574(0x1F00, (u32)d_0217E544, 4, (u32)p);
        func_021799C0((int)func_0217E524);
        *p = 3;
        break;
    case 3:
        func_0203D0DC(0);
        *p = 4;
        break;
    case 4:
        if (func_0203D1B4() > 1)
            *p = 5;
        if (d_0217E630 == 0)
            *p = 6;
        break;
    case 5:
        func_021799C0(0);
        return 1;
    case 6:
        func_021799C0(0);
        return 2;
    }
    return 0;
}
