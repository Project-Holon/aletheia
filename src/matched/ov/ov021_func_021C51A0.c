/*
 * function: func_021C51A0
 * address:  0x021C51A0
 * packet:   pkt_ov021_021C51A0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02040588  0x02040588  arm
 *   func_021C5424  0x021C5424  thumb  ov021
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_0201D83C  0x0201D83C  thumb
 *   func_02045C04  0x02045C04  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_02040DA8  0x02040DA8  arm
 *   func_020403F4  0x020403F4  arm
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned short u16;

extern void func_02040588(int a, int b);
extern void func_021C5424(int a, int b);
extern void func_0204B3B4(int a);
extern void func_0201C6EC(int a);
extern void func_0201C4C0(int a);
extern void func_0201D83C(int a);
extern void func_02045C04(int a);
extern void func_0204ADA4(int a);
extern void func_0204A8D4(int a);
extern void func_0204AFD8(int a);
extern void func_0204B1CC(int a);
extern void func_02040DA8(int a, int b, int c);
extern void func_020403F4(int a);
extern void func_020307B0(int a);

void func_021C51A0(int *a)
{
    int i = 0;

    *(volatile u16 *)0x04000050 = 0;
    func_02040588(1, 0);
    func_021C5424((int)a, a[0x7c / 4]);
    for (i = 0; i < 3; i++) {
        func_0204B3B4(a[0x58 / 4 + i]);
    }
    func_0201C6EC(a[0x6c / 4]);
    func_0201C4C0(a[0x6c / 4]);
    func_0201D83C(a[0x68 / 4]);
    func_02045C04(a[0x64 / 4]);
    func_0204ADA4(*(u16 *)((char *)a + 0x50));
    func_0204A8D4(*(u16 *)((char *)a + 0x52));
    func_0204AFD8(*(u16 *)((char *)a + 0x54));
    func_0204B1CC(a[0x4c / 4]);
    func_02040DA8(1, 1, 0);
    func_020403F4(1);
    func_020307B0((int)a);
}
