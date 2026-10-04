/*
 * function: func_021ECEB8
 * address:  0x021ECEB8
 * packet:   pkt_ov093_021ECEB8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02043B5C  0x02043B5C  arm
 *   func_0201DD78  0x0201DD78  thumb
 *   func_021B85DC  0x021B85DC  thumb  ov093
 *   func_0201CD10  0x0201CD10  thumb
 *   func_0201CE0C  0x0201CE0C  thumb
 */
#include "../include/Obj00027.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;

struct CharBuf;
extern void func_02043B5C(struct CharBuf *buf, u8 value);
struct Rec;
extern void func_0201DD78(u32 r, u32 g, u32 b);
extern int func_021B85DC(unsigned char *p);
extern struct Rec *func_0201CD10(u32 a0, s16 a1, s16 a2, u32 a3, u32 a4, s32 a5, u32 a6, u32 a7, u32 a8, u16 a9, u32 a10);
extern void func_0201CE0C(void *p);

void func_021ECEB8(u8 *a, u32 b, u16 s, u32 c)
{
    void *o;

    func_02043B5C((struct CharBuf *)(((struct Obj00027 *)a)->f4), 0xc);
    func_0201DD78(1, 9, 0xc);
    o = func_0201CD10(((struct Obj00027 *)a)->f0, 0, 0, b, ((struct Obj00027 *)a)->f24,
                      func_021B85DC((unsigned char *)(*(int *)&((struct Obj00027 *)a)->f134)),
                      ((struct Obj00027 *)a)->f2C, 0,
                      ((struct Obj00027 *)a)->f13C, 0xc, c);
    ((struct Obj00027 *)a)->f30 = o;
    func_0201CE0C(o);
    a[0x13f] = 0;
    a[0x13e] = 0;
    if (s == 0xff) {
        ((struct Obj00027 *)a)->f148 = 0x50;
        ((struct Obj00027 *)a)->f14C = 0;
    } else {
        ((struct Obj00027 *)a)->f148 = s;
        ((struct Obj00027 *)a)->f14C = s;
    }
    ((struct Obj00027 *)a)->f14A = ((struct Obj00027 *)a)->f148;
    a[0x141] = 0;
}
