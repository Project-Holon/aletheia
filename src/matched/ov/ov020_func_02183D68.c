/*
 * function: func_02183D68
 * address:  0x02183D68
 * packet:   pkt_ov020_02183D68
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02014264  0x02014264  thumb
 *   func_02183C58  0x02183C58  thumb  ov020
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02008B08  0x02008B08  thumb
 *   func_02008B20  0x02008B20  thumb
 *   func_02021444  0x02021444  thumb
 *   func_02185F6C  0x02185F6C  thumb  ov020
 *   func_0208068C  0x0208068C  arm
 *   func_02082AC0  0x02082AC0  arm
 *   func_02080B98  0x02080B98  arm
 *   func_02183C9C  0x02183C9C  thumb  ov020
 */

typedef unsigned int u32;

extern int func_020122C0(int a, int b, void *fn, int c);
extern int *func_020124E8(int a);
extern int func_020120F4(int a);
extern void func_02014264(int *p);
extern void func_02183C58(int a);
extern int func_02012EBC(int a);
extern int func_02008B08(int a);
extern void func_02008B20(int a);
extern void func_02021444(void);
extern void func_02185F6C(int a);
extern void func_0208068C(int a);
extern void func_02082AC0(int v, u32 a, u32 b);
extern void func_02080B98(void);
extern void func_02183C9C(void);

int func_02183D68(int a)
{
    int r6 = func_020122C0(a, 0, func_02183C9C, 0x24);
    int *r4 = func_020124E8(r6);

    r4[0] = a;
    r4[1] = func_020120F4(a);
    func_02014264(r4 + 2);
    func_02183C58(a);
    func_02008B20(func_02008B08(func_02012EBC(r4[1])));
    func_02021444();
    func_02185F6C(r4[1]);
    func_0208068C(0x1ff);
    func_02082AC0(0, 0x1a << 22, 0x29 << 14);
    func_02080B98();
    return r6;
}
