/*
 * function: func_021B965C
 * address:  0x021B965C
 * packet:   pkt_ov088_021B965C
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020362DC  0x020362DC  arm
 *   func_0203630C  0x0203630C  arm
 *   func_0204E720  0x0204E720  arm
 *   func_0204363C  0x0204363C  arm
 *   func_02040588  0x02040588  arm
 *   func_02043598  0x02043598  arm
 *   func_02006984  0x02006984  thumb
 *   func_02005E30  0x02005E30  thumb
 *   func_021B9E7C  0x021B9E7C  thumb  ov088
 *   func_021B9A14  0x021B9A14  thumb  ov088
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern u32   func_020362DC(void);
extern u32   func_0203630C(void);
extern void  func_0204E720(int a, int b, int c, int d);
extern void  func_0204363C(int a);
extern void  func_02040588(int a, int b);
extern void  func_02043598(int a, int b);
extern void *func_02006984(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, void *h);
extern void  func_02005E30(int x);
extern void  func_021B9E7C(void *a, int b);
extern void  func_021B9A14(u16 *p, u16 a, u16 b);

void func_021B965C(char *p)
{
    if ((func_020362DC() & 0xB) && *(u32 *)(p + 0x94) == 1) {
        func_0204363C(0);
        func_02040588(6, 1);
        func_02040588(3, 1);
        func_02043598(0x10, 1);
        func_021B9E7C(p + 0x40, 0x14B5);
        *(u32 *)(p + 0x94) = 2;
        return;
    }
    if (func_020362DC() & 9) {
        *(u32 *)(p + 4) = 0;
        *(u16 *)p = 4;
        *(void **)(p + 0x90) = func_02006984(0x283, 0, 0x40, 0, 0, 0, 0, 0);
        func_021B9E7C(p + 0x40, 0x1389);
        func_0204363C(0);
        func_02040588(6, 1);
        func_02043598(0x10, 0);
        func_0204E720(0xC, 0x10, 0, 3);
        func_02005E30(4);
        func_021B9A14((u16 *)(p + 8), 8, 8);
        return;
    }
    if (func_0203630C() == 0x46) {
        *(u32 *)(p + 4) = 2;
        *(u16 *)p = 5;
    } else if (func_0203630C() == 0xC80) {
        *(u32 *)(p + 4) = 3;
        *(u16 *)p = 5;
    }
}
