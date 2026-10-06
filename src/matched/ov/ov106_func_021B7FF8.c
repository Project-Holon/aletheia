/*
 * function: func_021B7FF8
 * address: 0x021B7FF8
 * packet: pkt_ov106_021B7FF8
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_0204335C 0x0204335C arm
 *   func_020433E0 0x020433E0 arm
 *   func_0204363C 0x0204363C arm
 *   func_0204361C 0x0204361C arm
 *   func_020434CC 0x020434CC arm
 *   func_0201DD60 0x0201DD60 thumb
 *   func_021B7D14 0x021B7D14 thumb ov106
 *   func_021B7F88 0x021B7F88 thumb ov106
 *   func_021B80BC 0x021B80BC thumb ov106
 *   func_020056A0 0x020056A0 thumb
 *   d_021B94F4 0x021B94F4 data a4
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_02082BCC(void *,int,int);
extern void func_0204335C(u32);
struct DispVram;
extern void func_020433E0(const struct DispVram *c);
extern void func_0204363C(u32);
extern void func_0204361C(void);
extern void func_020434CC(void);
extern void func_0201DD60(void);
extern void func_021B7D14(u32 *, void *, u32);
extern void func_021B7F88(void **, int, int);
extern void func_021B80BC(void *, u8 *);
extern void *func_020056A0(void (*)(void *, u8 *), void *, int);
extern const u8 d_021B94F4[];
void func_021B7FF8(u8 *p, void *a, u32 b) {
 func_02082BCC(p,0,0x28);
 *(volatile unsigned short *)0x04000050=0;
 *(volatile unsigned short *)0x04001050=0;
 *(volatile unsigned *)0x04000000 &= ~0xe000;
 *(volatile unsigned *)0x04001000 &= ~0xe000;
 func_0204335C(0);
 func_020433E0((const struct DispVram *)d_021B94F4);
 func_0204363C(1);
 func_0204361C();
 func_020434CC();
 func_0201DD60();
 func_021B7D14((u32 *)p,a,b);
 func_021B7F88((void **)(p+0x10),(int)d_021B94F4,b);
 *(void **)(p+0x24)=func_020056A0(func_021B80BC,p,0);
}
