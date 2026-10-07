/*
 * file:     pokemontrade_proc_p08.c
 * unit:     yes
 * function: func_021D9154, func_021D916C, func_021D9190, func_021D91BC, func_021D91D8, func_021D921C, func_021D9248
 * address:  0x021D9154
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D90E8  0x021D90E8  thumb  ov119
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02009470  0x02009470  thumb
 *   func_02082D44  0x02082D44  arm
 *   func_0200856C  0x0200856C  thumb
 *   func_02008570  0x02008570  thumb
 *   func_02008564  0x02008564  thumb
 *   func_02008574  0x02008574  thumb
 *   func_02025C1C  0x02025C1C  thumb
 *   func_02025C30  0x02025C30  thumb
 *   func_0202EB7C  0x0202EB7C  thumb
 */
#include "../../matched/include/Obj22710.h"
#include "../../matched/include/Obj08051.h"
#include "../../matched/include/Obj22714.h"

struct Entry;
struct Link;
struct Big;
struct Sub02009470Obj;
struct Sub0200852CObj;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

extern int func_021D90E8(int a, int b, int c, int d, int e);
extern struct Entry *func_020399A8(void);
extern u32 func_0203D1A4(struct Link *p);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02009470Obj *func_02009470(void *sys);
extern void func_02082D44(void *dst, const void *src, int n);
extern u8 func_0200856C(const struct Sub0200852CObj *obj);
extern u8 func_02008570(const struct Sub0200852CObj *obj);
extern u8 func_02008564(const struct Sub0200852CObj *obj);
extern void func_02008574(struct Sub0200852CObj *obj, u8 a, u8 b);
extern u32 func_02025C1C(u32 a, u32 b, u32 c);
extern u32 func_02025C30(u32 a, u32 b, u32 c);
extern u32 func_0202EB7C(u32 a0, u32 a1);
int func_021D9154(int a, int b, int c, int d, int e);
void func_021D916C(u32 a, u32 b, u8 *src, u8 *base, void *e);
void func_021D9190(u32 a, u32 b, u32 c, u8 *base, void *e);
void func_021D91BC(u32 a, u32 b, u32 c, u32 d, void *e);
void func_021D91D8(int a,int b,const u8 *c,u8 *p,int e);
void func_021D921C(u32 a, u32 b, u8 *src, u8 *base, void *e);
void func_021D9248(void *p, int a1, void *a2, char *a3, int a4);


int func_021D9154(int a, int b, int c, int d, int e)
{
    return func_021D90E8(((struct Obj22710 *)c)->f0, 2, a, d, e);
}

void func_021D916C(u32 a, u32 b, u8 *src, u8 *base, void *e)
{
    if (e == func_020399A8())
        *(u32 *)(base + a * 4 + 0x5e4) = *src;
}

void func_021D9190(u32 a, u32 b, u32 c, u8 *base, void *e)
{
    if (e == func_020399A8()) {
        if (a != func_0203D1A4((struct Link *)func_020399A8()))
            base[0x11fb] = base[0x11fb] & ~0xf;
    }
}

void func_021D91BC(u32 a, u32 b, u32 c, u32 d, void *e)
{
    if (e == func_020399A8()) {
        if (a == func_0203D1A4((struct Link *)func_020399A8()))
            return;
    }
}

void func_021D91D8(int a,int b,const u8 *c,u8 *p,int e) {
 if(e==(int)func_020399A8()) {
  if(a!=func_0203D1A4((struct Link *)((int)func_020399A8()))) {
   p[0x11f2]=c[0]; p[0x11f4]=c[1];
   ((struct Obj08051 *)p)->f107E=p[0x11f2]*160+16;
  }
 }
}

void func_021D921C(u32 a, u32 b, u8 *src, u8 *base, void *e)
{
    if (e == func_020399A8()) {
        if (a != func_0203D1A4((struct Link *)func_020399A8()))
            base[0x11e7] = *src;
    }
}


void func_021D9248(void *p, int a1, void *a2, char *a3, int a4)
{
    u8 buf[0x28];
    u8 x, y;
    u32 r1, r2;
    void *saved;

    if (a4 != (int)func_020399A8())
        return;
    if (p == (void *)func_0203D1A4((struct Link *)((u32)func_020399A8())))
        return;
    saved = func_02009470(func_02012EBC(((struct Obj22714 *)a3)->f82C));
    func_02082D44(a2, buf, 0x28);
    x = func_0200856C((const struct Sub0200852CObj *)buf);
    y = func_02008570((const struct Sub0200852CObj *)buf);
    r1 = func_02025C1C(x, y, func_02008564((const struct Sub0200852CObj *)buf));
    r2 = func_02025C30(x, y, func_02008564((const struct Sub0200852CObj *)buf));
    if (x == r1 && y == r2)
        func_02008574((struct Sub0200852CObj *)buf, x, y);
    else
        func_02008574((struct Sub0200852CObj *)buf, 0, 0);
    func_0202EB7C((u32)saved, (u32)buf);
}
