/*
 * file:     camera_system_p01.c
 * unit:     yes
 * function: func_021B6100, func_021B6338
 * address:  0x021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02034F84 0x02034F84 arm
 *   func_02085D3C 0x02085D3C arm
 *   func_02088234 0x02088234 arm
 *   func_02084968 0x02084968 arm
 *   func_020351F8 0x020351F8 arm
 *   func_021B68A0 0x021B68A0 thumb ov172
 *   func_021B65D8 0x021B65D8 thumb ov172
 *   func_021B6620 0x021B6620 thumb ov172
 *   func_021B662C 0x021B662C thumb ov172
 *   d_021C71C0 0x021C71C0 data a4
 *   g_021C88E0 0x021C88E0 data a4
 *   func_02085A38 0x02085A38 arm
 *   func_021B6868 0x021B6868 thumb ov172
 */
#include "../../matched/include/Obj00917.h"

typedef unsigned short u16;

typedef unsigned int   u32;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02034F84(int);
extern int func_02085D3C();
extern void func_02088234(void);
extern void func_02084968(int);
extern void func_020351F8(u32 a, u32 b);
extern void func_021B68A0(char *);
extern void func_021B65D8(void);
extern void func_021B6620(int x);
extern void func_021B662C(void);
extern void func_02085A38(u32 msec);
extern int func_02706324(void);
extern void func_027072E0(void);
extern void func_02700BD0(void);
extern void func_0272FCE0(int);
extern void func_02700B34(void);
extern void func_021B6868(char *);
char *func_021B6100(int id);
int func_02700938(void);
int func_02700CB4(int);
void func_02701248(int, int, int);
void func_027017DC(int, int);
void func_02701908(int, int);
int func_02700DB8(int);
void func_027000F8(void *);
void func_02700108(void *);
void func_02700118(void *);
void func_0270218C(int);
void func_02730B04(int, int);
void func_02730FBC(int, int);
void func_0270723C(void *);
int func_02707278(void *, int, int);
void func_021B6338(char *p);
extern const char d_021C71C0[];
extern char *g_021C88E0;


char *func_021B6100(int id)
{
    char *p;
    int r;
    int z;
    char buf[0x48];

    z = 0;
    p = func_02030734(id, 0x50, 0, d_021C71C0, 0x6F);
    g_021C88E0 = p;
    ((struct Obj00917 *)p)->f0 = id;
    ((struct Obj00917 *)p)->f4 = z;
    ((struct Obj00917 *)p)->f18 = z;
    ((struct Obj00917 *)p)->f8 = z;
    ((struct Obj00917 *)p)->fC = z;
    ((struct Obj00917 *)p)->f10 = z;
    ((struct Obj00917 *)p)->f14 = z;
    ((struct Obj00917 *)p)->f2C = 1;
    ((struct Obj00917 *)p)->f30 = 5;
    ((struct Obj00917 *)p)->f1C = z;
    ((struct Obj00917 *)p)->f20 = z;
    ((struct Obj00917 *)p)->f24 = z;
    ((struct Obj00917 *)p)->f3C = z;
    ((struct Obj00917 *)p)->f40 = z;
    func_02034F84(0x40);
    if (func_02085D3C() == 1) {
        r = func_02700938();
        if (r == 0) r = func_02700CB4(3);
    } else {
        r = 7;
    }
    if (r == 7) func_02088234();
    if (r == 6) return 0;
    r = ((struct Obj00917 *)p)->f2C;
    if (func_02085D3C() == 1) func_02701248(r, 3, 0);
    r = ((struct Obj00917 *)p)->f2C;
    if (func_02085D3C() == 1) func_027017DC(r, 1);
    r = ((struct Obj00917 *)p)->f2C;
    if (func_02085D3C() == 1) func_02701908(r, 1);
    r = ((struct Obj00917 *)p)->f2C;
    if (func_02085D3C() == 1) r = func_02700DB8(r);
    else r = 7;
    if (r == 7) func_02088234();
    if (r == 6) return 0;
    ((struct Obj00917 *)p)->f28 = 0;
    func_02084968(0x20000000);
    if (func_02085D3C() == 1) func_027000F8((void *)func_021B662C);
    if (func_02085D3C() == 1) func_02700108((void *)func_021B65D8);
    if (func_02085D3C() == 1) func_02700118((void *)func_021B6620);
    func_021B68A0(p);
    if (func_02085D3C() == 1) func_0270218C(1);
    ((struct Obj00917 *)p)->f48 = 0;
    ((struct Obj00917 *)p)->f44 = 0;
    func_02730B04(1, 0);
    func_02730FBC(1, 0);
    func_02730FBC(1, 1);
    func_02730B04(2, 0);
    func_02730FBC(2, 0);
    func_02730FBC(2, 1);
    if (func_02085D3C() != 0) func_0270723C(buf);
    if (func_02085D3C() != 0) r = func_02707278(buf, 0xFF, 0xFF);
    else r = 0;
    if (r == 0) func_02088234();
    func_020351F8((u32)((void *)func_021B6338), (u32)p);
    return p;
}


void func_021B6338(char *p)
{
    int result;
    goto test;
    do {
        func_02085A38(10);
test:
        result = 0;
        if (func_02085D3C() != 0) result = func_02706324();
    } while (result == 1);
    if (func_02085D3C() != 0) func_027072E0();
    func_021B6868(p);
    if (func_02085D3C() == 1) func_02700BD0();
    func_0272FCE0(1);
    if (func_02085D3C() == 1) func_02700B34();
}
