/*
 * function: func_022058F8
 * address:  0x022058F8
 * packet:   pkt_022058F8
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_02208F50 0x02208F50 data a4
 *   d_02208CEC 0x02208CEC data a4
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0204335C 0x0204335C arm
 *   func_020433E0 0x020433E0 arm
 *   func_0204363C 0x0204363C arm
 *   func_0204361C 0x0204361C arm
 *   func_020434CC 0x020434CC arm
 *   func_02043588 0x02043588 arm
 *   func_0201DD60 0x0201DD60 thumb
 *   func_02205AC0 0x02205AC0 thumb ov195
 *   func_02205B6C 0x02205B6C thumb ov195
 *   func_02205BDC 0x02205BDC thumb ov195
 *   func_02205AAC 0x02205AAC thumb ov195
 *   func_020056A0 0x020056A0 thumb
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern u32 d_02208F50[];
extern u32 d_02208CEC[];
extern char *func_02030734(u32, int, int, void *, int);
extern void func_02082BCC(void *, int, int);
extern void func_0204335C(u32 keep);
extern void func_020433E0(void *);
extern void func_0204363C(u32);
extern void func_0204361C(void);
extern void func_020434CC(void);
extern void func_02043588(void);
extern void func_0201DD60(void);
extern void func_02205AC0(void *, u32);
extern void func_02205B6C(void *, void *, u32);
extern void func_02205BDC(void *, u32);
extern void func_02205AAC(int a, char *b);
extern u32 func_020056A0(void *, void *, int);

char *func_022058F8(u32 a, u32 b)
{
    char *p = func_02030734(b, 0x10, 0, d_02208F50, 0x1df);

    func_02082BCC(p, 0, 0x10);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    *(volatile u32 *)0x04000000 &= 0xffff1fff;
    *(volatile u32 *)0x04001000 &= 0xffff1fff;
    func_0204335C(0);
    func_020433E0(d_02208CEC);
    func_0204363C(a);
    func_0204361C();
    func_020434CC();
    func_02043588();
    func_0201DD60();
    func_02205AC0(p, b);
    func_02205B6C(p + 4, d_02208CEC, b);
    func_02205BDC(p + 8, b);
    *(u32 *)(p + 0xc) = func_020056A0(func_02205AAC, p, 0);
    return p;
}
