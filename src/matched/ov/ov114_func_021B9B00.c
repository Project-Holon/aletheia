/*
 * function: func_021B9B00
 * address:  0x021B9B00
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * Fills the 0x64-byte header: type 0x15, sub-type 2, the four date fields from `a`, an 8-byte owner string and the three zero slots.
 */
#include "../include/Obj03764.h"

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;
extern void func_02082BCC(int, int, int);
struct Sub0200852CObj;
extern u8 func_0200856C(const struct Sub0200852CObj *obj);
extern u8 func_02008570(const struct Sub0200852CObj *obj);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern int func_020084F4(int);
extern void func_0201F41C(const u16 *src, u16 *dst, u32 n);

void func_021B9B00(u8 *p, int a)
{
    func_02082BCC((int)p, 0, 0x64);
    p[0] = 0x15;
    p[1] = 2;
    p[2] = func_0200856C((const struct Sub0200852CObj *)a);
    p[3] = func_02008570((const struct Sub0200852CObj *)a);
    ((struct Obj03764 *)p)->f4 = func_02008530((const struct Sub0200852CObj *)a);
    func_0201F41C((const u16 *)func_020084F4(a), (u16 *)(p + 8), 8);
    ((struct Obj03764 *)p)->f18 = 0;
    ((struct Obj03764 *)p)->f24 = 0;
    ((struct Obj03764 *)p)->f5C = 0;
}
