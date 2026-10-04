/*
 * function: func_021BAF4C
 * address: 0x021BAF4C
 * packet: pkt_ov100_021BAF4C
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021BB688 0x021BB688 data a4
 *   func_02049B40 0x02049B40 arm
 *   func_021BA3A4 0x021BA3A4 thumb ov100
 *   func_021BA1D0 0x021BA1D0 thumb ov100
 *   func_0201DD68 0x0201DD68 thumb
 *   func_021B95B8 0x021B95B8 thumb ov100
 *   func_021BAE5C 0x021BAE5C thumb ov100
 */
#include "../include/Obj00060.h"
struct Word { int x; };
extern const struct Word d_021BB688;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_021BA3A4(struct Word *,int);
extern void func_021BA1D0(int),func_0201DD68(void);
typedef unsigned char  u8;
extern void func_021B95B8(u8 *p, u32 v);
extern void func_021BAE5C(int a);
void func_021BAF4C(int a) {
 struct Word x=d_021BB688;
 int v=((struct Obj00060 *)a)->fCB0;
 func_02049B40(23,5,4,0x180,32,((struct Obj00060 *)a)->f278);
 func_021BA3A4(&x,a);
 ((struct Obj00060 *)a)->fCB0=v;
 func_021BA1D0(a);
 func_0201DD68();
 func_021B95B8((u8 *)a,(u32)func_021BAE5C);
}
