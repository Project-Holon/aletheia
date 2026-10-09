/*
 * file:     btl_server_p45.c
 * unit:     yes
 * function: func_021C2AB0, func_021C2AF0, func_021C2B3C, func_021C2BA4, func_021C2BF0, func_021C2C50, func_021C2CA8, func_021C2CD8, func_021C2D10, func_021C2DC4
 * address:  0x021C2AB0
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
 *   func_021D74F8  0x021D74F8  thumb  ov093
 *   func_021D7630  0x021D7630  thumb  ov093
 *   func_021D70F0  0x021D70F0  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D7540  0x021D7540  thumb  ov093
 *   func_021EF884  0x021EF884  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D75EC  0x021D75EC  thumb  ov093
 *   func_021D7674  0x021D7674  thumb  ov093
 *   func_021D75A8  0x021D75A8  thumb  ov093
 *   func_021D70E4 0x021D70E4 thumb ov093
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_021C2E64 0x021C2E64 thumb ov093
 *   sub_0201BD28  0x0201BD28  thumb
 *   func_021D78AC  0x021D78AC  thumb  ov093
 *   func_021B911C  0x021B911C  thumb  ov093
 *   func_021C2E1C  0x021C2E1C  thumb  ov093
 *   func_021C2E2C  0x021C2E2C  thumb  ov093
 *   func_021C2E3C  0x021C2E3C  thumb  ov093
 */
#include "../../matched/include/Obj21084.h"
#include "../../matched/include/Obj21085.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct { u8 pad[5]; u8 f : 1; } BF;

extern void func_021D74F8(int line);
extern void func_021D7630(int key, u32 val);
extern void func_021D70F0(void *a, int id);
extern int func_021D775C(int key);
extern void func_021D7540(int line);
extern int func_021EF884(void);
extern u8 func_021D5440(u8 *p);
extern void func_021D75EC(int key, u32 val);
extern void func_021D7674(int a, u32 b, u32 c, u32 d);
extern void func_021D75A8(int key, u32 val);
extern void func_021D70E4(void *a, int id);
extern int func_021D5B68(void *);
extern int func_021C2E64(u8 *, const u16 *, u8 *, u8 *, int);
extern u32 sub_0201BD28(u16 id, u32 field);
extern u32 func_021D78AC(u32 range);
extern int func_021B911C(u32 a, u32 b);
extern void func_021C2E1C(u32 c);
extern u32 func_021C2E2C(u32 c);
extern u32 func_021C2E3C(u32 c);
int func_021C2AB0(u8 *p);
int func_021C2AF0(u8 *p, u8 *a);
int func_021C2B3C(u8 *p, u8 *a, u8 *b, u32 c);
void func_021C2BA4(u8 *p, u8 *a, u8 *b, u32 c);
void func_021C2BF0(u8 *p, u8 *a, u8 *b, u32 c, u32 d);
void func_021C2C50(u8 *p, u8 *a, u8 *b, u32 c);
void func_021C2CA8(u8 *p, u8 *a);
void func_021C2CD8(u8 *p, u16 *q, u8 *a, u8 *b);
int func_021C2D10(u8 *p, u16 *q, u8 *b, u8 *c);
void func_021C2DC4(u8 *p, u32 a, u32 b, u32 c);




int func_021C2AB0(u8 *p)
{
    int r;
    int t;
    func_021D74F8(7971);
    func_021D7630(0x41, 0);
    r = 0;
    func_021D70F0(p, 0x7a);
    t = func_021D775C(0x41);
    func_021D7540(7975);
    if (t == 0)
        r = func_021EF884();
    return r;
}




int func_021C2AF0(u8 *p, u8 *a)
{
    int r;
    func_021D74F8(7997);
    func_021D75EC(2, func_021D5440(a));
    func_021D7674(0x35, 2 << 11, 410, 2 << 16);
    func_021D70F0(p, 0x7B);
    r = func_021D775C(0x35);
    func_021D7540(8002);
    return r;
}




int func_021C2B3C(u8 *p, u8 *a, u8 *b, u32 c)
{
    int r;
    func_021D74F8(8021);
    func_021D75EC(3, a ? func_021D5440(a) : 0x1F);
    func_021D75EC(4, func_021D5440(b));
    func_021D75EC(0x1D, c);
    func_021D7630(0x41, 0);
    func_021D70F0(p, 0x65);
    r = func_021D775C(0x41);
    func_021D7540(8028);
    return r;
}




void func_021C2BA4(u8 *p, u8 *a, u8 *b, u32 c)
{
    func_021D74F8(8042);
    func_021D75A8(4, func_021D5440(a));
    func_021D75A8(3, func_021D5440(b));
    func_021D75A8(0x1D, c);
    func_021D70F0(p, 0x67);
    func_021D7540(8047);
}




void func_021C2BF0(u8 *p, u8 *a, u8 *b, u32 c, u32 d)
{
    func_021D74F8(8062);
    func_021D75EC(4, func_021D5440(a));
    func_021D75EC(3, (u8)(b ? func_021D5440(b) : 0x1F));
    func_021D75EC(0x1D, c);
    func_021D75EC(0x1E, d);
    func_021D70F0(p, 0x68);
    func_021D7540(8071);
}




void func_021C2C50(u8 *p, u8 *a, u8 *b, u32 c)
{
    func_021D74F8(8085);
    func_021D75EC(4, func_021D5440(a));
    func_021D75EC(3, (u8)(b ? func_021D5440(b) : 0x1F));
    func_021D75EC(0x1D, c);
    func_021D70F0(p, 0x69);
    func_021D7540(8093);
}



void func_021C2CA8(u8 *p, u8 *a)
{
    func_021D74F8(8105);
    func_021D75EC(2, func_021D5440(a));
    func_021D70E4(p, 0x6a);
    func_021D7540(8108);
}



/*
 * extent: two bytes of zero alignment padding at 0x021C2D0E.
 */
void func_021C2CD8(u8 *p, u16 *q, u8 *a, u8 *b)
{
    if (func_021D5B68(b) == 0) {
        if (func_021C2D10(p, q, a, b) != 0)
            func_021C2E64(p, q, a, b, 0);
    }
}



int func_021C2D10(u8 *p, u16 *q, u8 *b, u8 *c)
{
    u8 s, x, y;
    u32 t;
    s = sub_0201BD28(*q, 0x12);
    func_021D74F8(8142);
    func_021D75EC(3, func_021D5440(b));
    func_021D75EC(4, func_021D5440(c));
    func_021D75EC(0x12, *q);
    t = 0;
    func_021D7630(0x41, 0);
    func_021D75A8(0x26, s);
    func_021D70F0(p, 0x51);
    x = func_021D775C(0x41);
    y = func_021D775C(0x26);
    func_021D7540(8152);
    if (x == 0) {
        if (func_021D78AC(100) < y)
            t = 1;
        if (t)
            return 1;
        if (func_021B911C(((struct Obj21084 *)p)->f4, 0) != 0)
            return 1;
    }
    return 0;
}


void func_021C2DC4(u8 *p, u32 a, u32 b, u32 c)
{
    u32 t;
    func_021C2E1C(c);
    for (t = func_021C2E2C(c); t != 0; t = func_021C2E3C(c)) {
        if (func_021C2E64(p, (const u16 *)a, (u8 *)b, (u8 *)t, 1) != 0) {
            BF *f = *(BF * *)&((struct Obj21085 *)p)->f4A8;
            if (!f->f)
                f->f = 1;
        }
    }
}
