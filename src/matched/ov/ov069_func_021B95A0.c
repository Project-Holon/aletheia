/*
 * function: func_021B95A0
 * address:  0x021B95A0
 * packet:   pkt_ov069_021B95A0
 * region:   ov069
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * func_021B97F4 is declared without a prototype: its matched source takes no
 * argument but the caller loads r4 into r0 before the call.
 *
 * symbols:
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_02082AC0  0x02082AC0  arm
 *   func_0202223C  0x0202223C  thumb
 *   func_021B96D4  0x021B96D4  thumb  ov069
 *   func_021B97D4  0x021B97D4  thumb  ov069
 *   func_021B97F4  0x021B97F4  thumb  ov069
 *   func_021B98AC  0x021B98AC  thumb  ov069
 *   func_021B9A50  0x021B9A50  thumb  ov069
 *   func_021B9B44  0x021B9B44  thumb  ov069
 *   func_021B9C44  0x021B9C44  thumb  ov069
 *   func_021B9D08  0x021B9D08  thumb  ov069
 *   func_021B9F24  0x021B9F24  thumb  ov069
 *   func_021BA384  0x021BA384  thumb  ov069
 *   func_021BA438  0x021BA438  thumb  ov069
 *   func_0202208C  0x0202208C  thumb
 *   func_0203D34C  0x0203D34C  arm
 */
#include "../include/Obj00432.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_0203064C(unsigned int a, unsigned int heap, unsigned int size);
extern void *func_0203159C(void *a, u32 size, u32 heap);
extern void  func_02082AC0(u32 val, void *dst, u32 size);
extern void  func_0202223C(u32 a, u32 color);
struct Obj;
struct WorkObj;
extern void func_021B96D4(u8 *p, u32 a);
extern void  func_021B97D4(void);
extern void  func_021B97F4();
extern void func_021B98AC(u8 *p);
extern void func_021B9A50(u8 *p);
extern void func_021B9B44(struct WorkObj *o);
extern void func_021B9C44(struct Obj *o);
extern void func_021B9D08(u8 *p);
extern void func_021B9F24(char *p);
extern void  func_021BA384(char *o, int i, int n);
extern void func_021BA438(char *p, int i);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void  func_0203D34C(u32 a, u32 b);

int func_021B95A0(void *a, u32 b, u32 c)
{
    u8 *p;

    func_0203064C(1, 0x80, 0x20000);
    p = func_0203159C(a, 0x168, 0x80);
    func_02082AC0(0, p, 0x168);
    func_0202223C(0, 0);
    func_0202223C(1, 0);
    func_021B96D4(p, c);
    func_021B97D4();
    func_021B97F4(p);
    func_021B98AC(p);
    func_021B9A50(p);
    func_021B9B44((struct WorkObj *)p);
    func_021B9C44((struct Obj *)p);
    func_021B9D08(p);
    func_021B9F24((char *)p);
    func_021BA384((char *)p, ((struct Obj00432 *)p)->f160, ((struct Obj00432 *)p)->f162);
    func_021BA438((char *)p, ((struct Obj00432 *)p)->f160);
    func_0202208C(0, 1, 1, 0, 0x10, 1, 0x80);
    func_0203D34C(1, 0x80);
    return 1;
}
