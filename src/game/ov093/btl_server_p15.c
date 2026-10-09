/*
 * file:     btl_server_p15.c
 * unit:     yes
 * function: func_021BDB88, func_021BDBB8, func_021BDBEC, func_021BDC0C, func_021BDC2C, func_021BDC58, func_021BDC78, func_021BDC98, func_021BDD00, func_021BDD7C
 * address:  0x021BDB88
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D74F8 0x021D74F8 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021D75EC 0x021D75EC thumb ov093
 *   func_021D70F0 0x021D70F0 thumb ov093
 *   func_021D7540 0x021D7540 thumb ov093
 *   func_021D70FC 0x021D70FC thumb ov093
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 *   func_021B8DDC 0x021B8DDC thumb ov093
 *   func_021CD4B0 0x021CD4B0 thumb ov093
 *   func_021B8D8C  0x021B8D8C  thumb  ov093
 *   func_021B8E28  0x021B8E28  thumb  ov093
 *   func_021BD9D4  0x021BD9D4  thumb  ov093
 *   func_021C6190  0x021C6190  thumb  ov093
 *   func_021BD0C0  0x021BD0C0  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021BD1D0  0x021BD1D0  thumb  ov093
 *   func_021BDE18  0x021BDE18  thumb  ov093
 *   func_021C5108  0x021C5108  thumb  ov093
 *   func_021D64F0  0x021D64F0  thumb  ov093
 *   func_021BDE08  0x021BDE08  thumb  ov093
 */
#include "../../matched/include/Obj00003.h"
#include "../../matched/include/Obj00003.h"

typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

struct Fl { u8 f : 1; };

extern void func_021D74F8(int);
extern u8 func_021D5440(u8 *p);
extern void func_021D75EC(int, u32);
extern void func_021D70F0(void *a, int id);
extern void func_021D7540(int);
extern void func_021D70FC(int a, int b, int c);
extern u32 func_021CC8D8(void *, int);
extern void func_021CC95C(u32 *p, u32 v, int line);
extern u8 func_021B8DDC(u32 x);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern int func_021B8D8C(void *p, void *a, u32 b);
extern void func_021B8E28(u8 *p, u32 n, u8 *out, u8 *cnt_out);
extern void func_021BD9D4(u8 *p, u8 i, u8 a, u8 b, int c);
extern int func_021C6190(u8 *p, u8 *a);
extern int func_021BD0C0(u8 *p, u8 x, u32 y);
extern int func_021D5B68(void *p);
extern void func_021BD1D0(u8 *p, u32 n);
extern void func_021BDE18(u8 *p, u8 *a);
extern void func_021C5108(u8 *p, u8 *a, int z);
extern void func_021D64F0(u8 *a);
extern void func_021BDE08(u8 *p, u32 n);
void func_021BDB88(u8 *p, u8 *a);
void func_021BDBB8(u8 *p, u8 *a);
void func_021BDBEC(u8 *p);
void func_021BDC0C(u8 *p);
void func_021BDC2C(u8 *p);
void func_021BDC58(u8 *p);
void func_021BDC78(u8 *p, u8 *a);
void func_021BDC98(u8 *p, u8 *a, u8 v);
int func_021BDD00(u8 *p, u8 *a, int c);
void func_021BDD7C(u8 *p, u8 *a, u32 c);


void func_021BDB88(u8 *p, u8 *a)
{
    func_021D74F8(0xc43);
    func_021D75EC(2, func_021D5440(a));
    func_021D70F0(p, 0x55);
    func_021D7540(0xc46);
}



void func_021BDBB8(u8 *p, u8 *a)
{
    func_021D74F8(0xc55);
    func_021D75EC(2, func_021D5440(a));
    func_021D70FC((int)p, 0x55, 4);
    func_021D7540(0xc58);
}



void func_021BDBEC(u8 *p)
{
    func_021D74F8(3173);
    func_021D70F0(p, 86);
    func_021D7540(3175);
}



void func_021BDC0C(u8 *p)
{
    func_021D74F8(3187);
    func_021D70F0(p, 87);
    func_021D7540(3189);
}



void func_021BDC2C(u8 *p)
{
    u32 old;
    old = func_021CC8D8(p + 0x1d74, 0xc82);
    func_021BDC58(p);
    func_021CC95C((u32 *)(p + 0x1d74), old, 0xc84);
}



void func_021BDC58(u8 *p)
{
    func_021D74F8(3217);
    func_021D70F0(p, 88);
    func_021D7540(3219);
}



void func_021BDC78(u8 *p, u8 *a)
{
    u8 id;
    int value;
    id = func_021D5440(a);
    value = func_021B8DDC(id);
    func_021CD4B0(((struct Obj00003 *)p)->fC, 0x3b, value, id);
}




void func_021BDC98(u8 *p, u8 *a, u8 v)
{
    u8 buf[2];
    int r;
    u8 *q;
    func_021BDC78(p, a);
    if (func_021BDD00(p, a, 0)) {
        r = func_021B8D8C(((struct Obj00003 *)p)->f4, ((struct Obj00003 *)p)->f8, func_021D5440(a));
        func_021B8E28(*(u8 * *)&((struct Obj00003 *)p)->f4, r, &buf[1], &buf[0]);
        q = p + 0x7D9;
        if (q[buf[1]] < 0xFF) q[buf[1]]++;
        func_021BD9D4(p, buf[1], buf[0], v, 1);
    }
}




int func_021BDD00(u8 *p, u8 *a, int c)
{
    u32 n, i;
    if (c == 0) {
        n = func_021C6190(p, a);
        if (n != 0) {
            ((struct Fl *)(p + 0x78A))->f = 1;
            for (i = 0; i < n; i++) {
                func_021BD0C0(p, p[0x78B + i], func_021D5440(a));
                if (func_021D5B68(a)) break;
            }
            ((struct Fl *)(p + 0x78A))->f = 0;
        }
    }
    if (func_021D5B68(a) == 0) {
        func_021BDD7C(p, a, 0x26C);
        return 1;
    }
    return 0;
}


void func_021BDD7C(u8 *p, u8 *a, u32 c)
{
    u32 n = func_021D5440(a);
    u32 s;
    int r = func_021B8D8C(((struct Obj00003 *)p)->f4, ((struct Obj00003 *)p)->f8, n);
    if (r != 6) func_021CD4B0(((struct Obj00003 *)p)->fC, 0x3C, r, c);
    func_021BD1D0(p, n);
    s = func_021CC8D8(p + 0x1D74, 3327);
    func_021BDE18(p, a);
    func_021CC95C((u32 *)(p + 0x1D74), s, 3329);
    func_021C5108(p, a, 0);
    func_021D64F0(a);
    func_021CD4B0(((struct Obj00003 *)p)->fC, 0x20, func_021D5440(a));
    func_021BDE08(p + 0x1AB8, n);
}
