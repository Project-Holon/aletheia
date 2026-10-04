/*
 * function: func_021B7460
 * address: 0x021B7460
 * packet: pkt_ov173_021B7460
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_021B7378 0x021B7378 thumb ov173
 *   func_02012FFC 0x02012FFC thumb
 *   func_0201CD10 0x0201CD10 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_021B74F8 0x021B74F8 thumb ov173
 */
#include "../include/Obj03858.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int     s32;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct Rec;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201F73C(void *, int, int, int);
extern void func_021B7378(char *, u32);
extern signed char func_02012FFC(void);
extern struct Rec *func_0201CD10(u32 a0, s16 a1, s16 a2, u32 a3, u32 a4, s32 a5, u32 a6, u32 a7, u32 a8, u16 a9, u32 a10);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32);
extern int func_021B74F8(u32);
void func_021B7460(char *p, u32 kind)
{
    u32 zero;
    int speed;
    void *q;
    func_02043B5C(func_02045770(((struct Obj03858 *)p)->f20), 15);
    zero = 0;
    func_0201F73C(((struct Obj03858 *)p)->f20, 0, 1, 13);
    func_021B7378(p, kind);
    speed = func_02012FFC();
    ((struct Obj03858 *)p)->f6C = func_0201CD10(*(u32 *)&((struct Obj03858 *)p)->f20, 0, 0, ((struct Obj03858 *)p)->f4C, ((struct Obj03858 *)p)->f60, speed, ((struct Obj03858 *)p)->f64, zero, 0x4f, 0xffff, (u32)func_021B74F8);
    q = ((struct Obj03858 *)p)->f20;
    func_02045334(q);
    func_02045374(q);
    func_020409B4(func_02045730(q));
}
