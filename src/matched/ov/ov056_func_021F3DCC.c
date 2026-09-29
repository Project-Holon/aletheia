/*
 * function: func_021F3DCC
 * address:  0x021F3DCC
 * packet:   pkt_ov056_021F3DCC
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_0218DC6C  0x0218DC6C  thumb  ov021
 *   func_0218C654  0x0218C654  thumb  ov021
 *   func_0218C6F4  0x0218C6F4  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012A30  0x02012A30  thumb
 *   func_02028A7C  0x02028A7C  thumb
 *   d_021F4278  0x021F4278  data  ov056  a4
 *   d_021F4258  0x021F4258  data  ov056  a4
 */

typedef unsigned int u32;

typedef struct { u32 a, b, c; } Ent;

extern int func_02188C98(int a);
extern int func_0218DC6C(int a);
extern u32 func_0218C654(u32 a, u32 b, Ent *e);
extern int func_0218C6F4(u32 a, u32 b, int c);
extern int func_02188C80(int a);
extern int func_020120F4(int a);
extern int func_02012A30(int a);
extern void func_02028A7C(int a, int b);
extern Ent d_021F4278;
extern int d_021F4258[];

void func_021F3DCC(int unused, int b, u32 *c)
{
    int r7;
    u32 i;
    int r;

    r7 = func_0218DC6C(func_02188C98(b));
    i = 0;
    c[1] = func_0218C654(r7, 0, &d_021F4278);
    c[0] = r7;
    r = func_0218C6F4(r7, c[1], 1);
    c[2] = 0x6000;
    c[3] = i;
    for (; i < 1; i++) {
        if (r < d_021F4258[i]) {
            c[2] = d_021F4258[i];
            c[3] = i;
            break;
        }
    }
    func_02028A7C(func_02012A30(func_020120F4(func_02188C80(b))), 0x746);
}
