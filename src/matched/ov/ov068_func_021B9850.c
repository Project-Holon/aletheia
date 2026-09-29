/*
 * function: func_021B9850
 * address:  0x021B9850
 * packet:   pkt_ov068_021B9850
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_0204335C  0x0204335C  arm
 *   func_020433E0  0x020433E0  arm
 *   func_0204363C  0x0204363C  arm
 *   func_0204361C  0x0204361C  arm
 *   func_020434CC  0x020434CC  arm
 *   func_02043588  0x02043588  arm
 *   func_0201DD60  0x0201DD60  thumb
 *   func_0201DD78  0x0201DD78  thumb
 *   func_021B9980  0x021B9980  thumb
 *   func_021B9E28  0x021B9E28  thumb
 *   func_021B996C  0x021B996C  thumb
 *   func_020056A0  0x020056A0  thumb
 *   d_021BB598     0x021BB598  data  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_02082BCC(void *p, u32 a, u32 b);
extern void func_0204335C(int v);
extern void func_020433E0(void *p);
extern void func_0204363C(u32 v);
extern void func_0204361C(void);
extern void func_020434CC(void);
extern void func_02043588(void);
extern void func_0201DD60(void);
extern void func_0201DD78(u32 r, u32 g, u32 b);
extern void func_021B9980(void *p, u32 a);
extern void func_021B9E28(void *p, void *q, u32 a);
extern void func_021B996C(void);
extern u32 func_020056A0(void (*fn)(void), void *arg, u32 z);
extern int d_021BB598[];

void func_021B9850(u8 *p, u32 a)
{
    func_02082BCC(p, 0, 0xd4);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    *(volatile u32 *)0x04000000 &= 0xFFFF1FFF;
    *(volatile u32 *)0x04001000 &= 0xFFFF1FFF;
    func_0204335C(0);
    func_020433E0(d_021BB598);
    func_0204363C(0);
    func_0204361C();
    func_020434CC();
    func_02043588();
    func_0201DD60();
    func_0201DD78(0xf, 0xe, 0);
    func_021B9980(p, a);
    func_021B9E28(p + 0x7c, d_021BB598, a);
    *(u32 *)(p + 0xd0) = func_020056A0(func_021B996C, p, 0);
}
