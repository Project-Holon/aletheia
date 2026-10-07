/*
 * file:     nhttp_rap_p07.c
 * unit:     yes
 * function: func_021B9AA8, func_021B9AF8, func_021B9B00
 * address:  0x021B9AA8
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "../../matched/include/Obj03764.h"

struct Sub0200852CObj;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char u8;

extern void func_02034714(const char *, unsigned int, const char *);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void func_02082BCC(int, int, int);
extern u8 func_0200856C(const struct Sub0200852CObj *obj);
extern u8 func_02008570(const struct Sub0200852CObj *obj);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern const void *func_020084F4(const void *p);
extern void func_0201F41C(const u16 *src, u16 *dst, u32 n);
void *func_021B9AA8(int n);
void func_021B9AF8(void *p);
void func_021B9B00(u8 *p, int a);
extern u16 d_021CE31C;
extern char d_021CE3B8[], d_021CE3A0[];

void *func_021B9AA8(int n)
{
    void *p;
    if (d_021CE31C == 0xffff)
        func_02034714(d_021CE3B8, 0, d_021CE3B8);
    p = func_02030734(d_021CE31C, n, 0, d_021CE3A0, 0xe9);
    if (p == 0)
        func_02034714(d_021CE3B8, 0, d_021CE3B8);
    return p;
}

void func_021B9AF8(void *p)
{
    func_020307B0(p);
}


void func_021B9B00(u8 *p, int a)
{
    func_02082BCC((int)p, 0, 0x64);
    p[0] = 0x15;
    p[1] = 2;
    p[2] = func_0200856C((const struct Sub0200852CObj *)a);
    p[3] = func_02008570((const struct Sub0200852CObj *)a);
    ((struct Obj03764 *)p)->f4 = func_02008530((const struct Sub0200852CObj *)a);
    func_0201F41C((const u16 *)func_020084F4((const void *)a), (u16 *)(p + 8), 8);
    ((struct Obj03764 *)p)->f18 = 0;
    ((struct Obj03764 *)p)->f24 = 0;
    ((struct Obj03764 *)p)->f5C = 0;
}
