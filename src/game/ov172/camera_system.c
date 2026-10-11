/*
 * file:     camera_system.c
 * unit:     yes
 * function: func_021B6100, func_021B6338, func_021B63B8, func_021B644C, func_021B64AC, func_021B657C, func_021B65C4, func_021B65D8, func_021B6620, func_021B662C, func_021B66B0, func_021B6744, func_021B674C, func_021B67BC, func_021B6814, func_021B6868, func_021B688C, func_021B68A0, func_021B6938, func_021B6944, func_021B6950, func_021B697C, func_021B699C, func_021B69BC, func_021B69D0, func_021B69D8, func_021B69E0, func_021B69F0
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
 *   d_021C71C0 0x021C71C0 data a4
 *   g_021C88E0 0x021C88E0 data a4
 *   func_02085A38 0x02085A38 arm
 *   func_02700B34  0x02700B34  arm
 *   func_02700BD0  0x02700BD0  arm
 *   func_02700DB8  0x02700DB8  arm
 *   func_02700FE4  0x02700FE4  arm
 *   func_027020F0  0x027020F0  arm
 *   func_02702108  0x02702108  arm
 *   func_0270212C  0x0270212C  arm
 *   func_02702158  0x02702158  arm
 *   func_027021E4  0x027021E4  arm
 *   func_0270229C  0x0270229C  arm
 *   func_027022F8  0x027022F8  arm
 *   func_0270234C  0x0270234C  arm
 *   func_02706174  0x02706174  arm
 *   func_027062C8  0x027062C8  arm
 *   func_02706324  0x02706324  arm
 *   func_027072E0  0x027072E0  arm
 *   func_0272FC90  0x0272FC90  arm
 *   func_0272FCE0  0x0272FCE0  arm
 *   func_0272FE54  0x0272FE54  arm
 *   func_02034FB8 0x02034FB8 arm
 *   func_020307B0 0x020307B0 arm
 *   func_020490A8 0x020490A8 arm
 *   func_0203D7C8 0x0203D7C8 arm
 *   func_02048F4C 0x02048F4C arm
 *   func_020862F0 0x020862F0 arm
 *   func_0203D7FC  0x0203D7FC  arm
 *   func_02702364  0x02702364  arm
 *   func_027023CC  0x027023CC  arm
 *   d_021C88E4 0x021C88E4 data a4 ov172
 *   g_021C88E4  0x021C88E4  data  ov172
 */
#include "../../matched/include/Obj00917.h"
#include "../../matched/include/Obj01264.h"
#include "../../matched/include/Obj01559.h"
#include "../../matched/include/Obj02504.h"
#include "../../matched/include/Obj14292.h"
#include "../../matched/include/Obj03311.h"
#include "../../matched/include/Obj02879.h"
#include "../../matched/include/Obj14293.h"
#include "../../matched/include/Obj08253.h"
#include "../../matched/include/Obj24060.h"
#include "../../matched/include/Obj24061.h"
#include "../../matched/include/Obj24062.h"
#include "../../matched/include/Obj08254.h"
#include "../../matched/include/Obj24063.h"
#include "../../matched/include/Obj24064.h"
#include "../../matched/include/Obj14294.h"

typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char u8;

typedef signed int     s32;

struct D021C88E4 {
    u8 pad0[4];
    u16 h4;
    u8 b6;
};

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02034F84(int);
extern int func_02085D3C(void);
extern void func_02088234(void);
extern void func_02084968(int);
extern void func_020351F8(u32 a, u32 b);
extern void func_02085A38(u32 msec);
extern int func_02706324(void);
extern void func_027072E0(void);
extern void func_02700BD0(void);
extern void func_0272FCE0(int);
extern void func_02700B34(void);
int func_02700938(void);
int func_02700CB4(int);
void func_02701248(int, int, int);
void func_027017DC(int, int);
void func_02701908(int, int);
u32 func_02700DB8(u32 a0);
void func_027000F8(void *);
void func_02700108(void *);
void func_02700118(void *);
void func_0270218C(int);
void func_02730B04(int, int);
void func_02730FBC(int, int);
void func_0270723C(void *);
int func_02707278(void *, int, int);
extern void func_02034FB8(u32 v);
extern u32 func_020307B0(void *p);
extern u32 func_020490A8(u32 a, u32 b);
extern void *func_0203D7C8(u32, u32, const char *, u16);
extern void func_02048F4C(void *dst, u32 archive_id, u32 member);
extern void func_020862F0(void *, u32);
extern void func_0203D7FC(void *p);
extern u32 func_02700FE4(u32 a, u32 b, u32 c);
void func_027062C8(void);
u32 func_0270234C(u32 a0);
void func_0272FE54(u32 a0, u32 a1, u32 a2, u32 a3, int s0, void (*s1)(void), int s2);
void func_02706174(int, int);
void func_0270212C(void);
void func_027021E4(void);
void func_02702108(void);
int func_027020F0(void);
int func_0272FC90(int ch);
void func_02702158(int);
int func_027022F8(u32, u32);
void func_0270229C(int);
int func_02702364(u32 v);
int func_027023CC(void *v);
char *func_021B6100(int id);
void func_021B6338(char *p);
void func_021B63B8(char *p);
void func_021B644C(char *p);
void func_021B64AC(char *p);
void func_021B657C(char *obj, int mode);
void func_021B65C4(void *p);
void func_021B65D8(void);
void func_021B6620(int x);
void func_021B662C(void);
void func_021B66B0(void);
void func_021B6744(void *p, u32 a, u32 b);
void func_021B674C(char *p, int count, u16 heap);
void func_021B67BC(char *p);
void func_021B6814(void *a0);
void func_021B6868(char *p);
int func_021B688C(void *p);
void func_021B68A0(char *p);
u16 func_021B6938(void *p);
u16 func_021B6944(void *p);
void func_021B6950(char *p, int v);
int func_021B697C(void *p);
int func_021B699C(void *p);
void func_021B69BC(void *p, u32 v);
void func_021B69D0(void *p);
void func_021B69D8(void *p);
void func_021B69E0(void);
void func_021B69F0(void);
extern const char d_021C71C0[];
extern char *g_021C88E0;
extern struct D021C88E4 d_021C88E4;



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
    /* stand-in: the goto into the loop body gives the original block order; while/for forms differ */
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



void func_021B63B8(char *p)
{
    func_020351F8(0, 0);
    if (func_02085D3C() != 0) func_027062C8();
    if (func_02085D3C() != 0) func_027072E0();
    func_021B6868(p);
    if (func_02085D3C() == 1) func_02700BD0();
    func_0272FCE0(1);
    if (func_02085D3C() == 1) func_02700B34();
    func_021B65C4(p);
    func_021B67BC(p);
    func_02034FB8(0x40);
    func_020307B0(p);
    g_021C88E0 = 0;
}



void func_021B644C(char *p)
{
    u32 width = func_021B6938(p);
    u32 height = func_021B6944(p);
    u32 offset = func_02085D3C() == 1 ? func_0270234C(width) : 0;
    width *= 2;
    func_0272FE54(1, (*(u32 **)(p + 4))[((struct Obj01264 *)p)->f18], offset >> 2,
                 width * height, 0, func_021B66B0, 0);
}




void func_021B64AC(char *p)
{
    int b;
    int a;
    int d;
    int c;
    int r;
    switch (((struct Obj01559 *)p)->f44) {
    case 1:
        func_021B657C(p, 1);
        a = *(int *)&((struct Obj01559 *)p)->f4C;
        b = *(int *)&((struct Obj01559 *)p)->f48;
        if (func_02085D3C() != 0) func_02706174(b, a);
        ((struct Obj01559 *)p)->f44 = 2;
        break;
    case 2:
        r = 0;
        if (func_02085D3C() != 0) r = func_02706324();
        if (r == 0) {
            func_021B65C4(p);
            ((struct Obj01559 *)p)->f44 = 3;
        }
        break;
    case 4:
        func_021B657C(p, 0);
        c = *(int *)&((struct Obj01559 *)p)->f4C;
        d = *(int *)&((struct Obj01559 *)p)->f48;
        if (func_02085D3C() != 0) func_02706174(d, c);
        ((struct Obj01559 *)p)->f44 = 5;
        break;
    case 5:
        r = 0;
        if (func_02085D3C() != 0) r = func_02706324();
        if (r == 0) {
            func_021B65C4(p);
            ((struct Obj01559 *)p)->f44 = 6;
        }
        break;
    case 0:
    case 3:
    case 6:
    default:
        break;
    }
}



void func_021B657C(char *obj, int mode)
{
    char *p = obj;
    int which = 0;
    u32 size;
    if (mode != 1) which = 1;
    func_021B65C4(p);
    which = (u16)which;
    size = func_020490A8(0xD4, which);
    ((struct Obj01559 *)p)->f4C = size;
    ((struct Obj01559 *)p)->f48 = func_0203D7C8(((struct Obj01559 *)p)->f0, size, d_021C71C0, 0x13B);
    func_02048F4C(((struct Obj01559 *)p)->f48, 0xD4, which);
    func_020862F0(((struct Obj01559 *)p)->f48, ((struct Obj01559 *)p)->f4C);
}



/*
 * Release the word at +0x48 through 0x0203D7FC and clear it.
 *
 * Addresses are Black-image addresses.
 */
void func_021B65C4(void *p)
{
    u32 v = ((struct Obj02504 *)p)->f48;
    if (v != 0) {
        func_0203D7FC((void *)v);
        ((struct Obj02504 *)p)->f48 = 0;
    }
}



void func_021B65D8(void)
{
    u32 *p = (u32 *)g_021C88E0;

    if (func_02085D3C() == 1)
        func_0270212C();
    func_0272FCE0(1);
    if (func_02085D3C() == 1)
        func_027021E4();
    ((struct Obj14292 *)p)->f24 = 1;
    ((struct Obj14292 *)p)->f1C = 1;
}



/*
 * Delegate to func_021B65D8 unless the argument is 7.
 *
 * Addresses are Black-image addresses.
 */
void func_021B6620(int x)
{
    if (x != 7) {
        func_021B65D8();
    }
}



void func_021B662C(void)
{
    char *p = g_021C88E0;
    u32 v;
    if (((struct Obj03311 *)p)->f10 != 0) {
        if (((struct Obj03311 *)p)->f28 <= 30) ++((struct Obj03311 *)p)->f28;
        if (((struct Obj03311 *)p)->f20 != 0) {
            v = ((struct Obj03311 *)p)->f2C;
            if ((func_02085D3C() == 1 ? func_02700DB8(v) : 7) == 7)
                func_02088234();
            ((struct Obj03311 *)p)->f28 = 0;
            ((struct Obj03311 *)p)->f20 = 0;
        }
        if (((struct Obj03311 *)p)->f1C != 0) {
            func_021B644C(p);
            if (func_02085D3C() == 1) func_027021E4();
            if (func_02085D3C() == 1) func_02702108();
            ((struct Obj03311 *)p)->f1C = 0;
        }
    }
}



void func_021B66B0(void)
{
    char *p = g_021C88E0;
    int one;
    func_0272FCE0(1);
    if ((func_02085D3C() == 1 ? func_027020F0() : 0) == 1) {
        one = 1;
        if (func_0272FC90(one) != 0) func_0272FCE0(one);
        if (((struct Obj02879 *)p)->f24 != 0) {
            ((struct Obj02879 *)p)->f24 = 0;
        } else if (((struct Obj02879 *)p)->f28 > 4) {
            if (*(void (**)(u32, u32))(p + 0x3C) != 0)
                (*(void (**)(u32, u32))(p + 0x3C))((*(u32 **)(p + 4))[((struct Obj02879 *)p)->f18], ((struct Obj02879 *)p)->f40);
            ((struct Obj02879 *)p)->f18 = (((struct Obj02879 *)p)->f18 + 1) % ((struct Obj02879 *)p)->f8;
        }
        if (((struct Obj02879 *)p)->f10 == 1) func_021B644C(p);
    }
}



void func_021B6744(void *p, u32 a, u32 b)
{
    ((struct Obj14293 *)p)->f3C = a;
    ((struct Obj14293 *)p)->f40 = b;
}



void func_021B674C(char *p, int count, u16 heap)
{
    u32 width = func_021B6938(p);
    u32 height = func_021B6944(p);
    u8 i;
    if (*(u32 *)&((struct Obj01264 *)p)->f4 == 0) {
        ((struct Obj01264 *)p)->f4 = func_02030734(((struct Obj01264 *)p)->f0, count * 4, 0, d_021C71C0, 0x1D7);
        ((struct Obj01264 *)p)->f8 = count;
        for (i = 0; i < count; i++)
            (*(void ***)(p + 4))[i] = func_0203D7C8(heap, height * (width * 2), d_021C71C0, 0x1DC);
        ((struct Obj01264 *)p)->fC = 1;
    }
}



void func_021B67BC(char *p)
{
    u8 i;
    if (((struct Obj02504 *)p)->f10 != 0) return;
    if ((func_02085D3C() == 1 ? func_027020F0() : 0) != 0) return;
    if (((struct Obj02504 *)p)->fC == 1) {
        for (i = 0; i < ((struct Obj02504 *)p)->f8; i++)
            func_0203D7FC((void *)(*(u32 **)(p + 4))[i]);
    }
    func_020307B0(((struct Obj02504 *)p)->f4);
    ((struct Obj02504 *)p)->f8 = 0;
    *(u32 *)&((struct Obj02504 *)p)->f4 = 0;
}



void func_021B6814(void *a0)
{
    char *p = (char *)a0;
    int one = 1;

    if (((struct Obj08253 *)p)->f10 != 0)
        return;
    if ((func_02085D3C() == 1 ? func_027020F0() : 0) != 0)
        return;
    if (func_0272FC90(one) == 1)
        func_0272FCE0(one);
    ((struct Obj08253 *)p)->f10 = one;
    ((struct Obj08253 *)p)->f1C = one;
    ((struct Obj08253 *)p)->f28 = 0;
}



void func_021B6868(char *p)
{
    if (((struct Obj02504 *)p)->f10 == 1) {
        ((struct Obj02504 *)p)->f10 = 0;
        ((struct Obj02504 *)p)->f1C = 0;
        if (func_02085D3C() == 1) {
            func_0270212C();
        }
    }
}



int func_021B688C(void *p)
{
    u8 v = ((struct Obj24060 *)p)->f44;
    return v == 6 || v == 0;
}



void func_021B68A0(char *p)
{
    int result;
    u32 width;
    u32 height;
    if (((struct Obj01264 *)p)->f10 != 0) return;
    if ((func_02085D3C() == 1 ? func_027020F0() : 0) != 0) return;
    if (func_02085D3C() == 1) func_02702158(0);
    result = 0;
    ((struct Obj01264 *)p)->f34 = 0;
    ((struct Obj01264 *)p)->f36 = func_021B697C(p);
    ((struct Obj01264 *)p)->f38 = 0;
    ((struct Obj01264 *)p)->f3A = func_021B699C(p);
    width = func_021B6938(p);
    height = func_021B6944(p);
    if (func_02085D3C() == 1) result = func_027022F8(width, height);
    if (func_02085D3C() == 1) func_0270229C(result);
    ((struct Obj01264 *)p)->f14 = 0;
}



u16 func_021B6938(void *p)
{
    return (u16)(((struct Obj01264 *)p)->f36 - ((struct Obj01264 *)p)->f34);
}



/*
 * Width of the u16 pair at +0x38/+0x3a, zero extended.
 *
 * Addresses are Black-image addresses.
 */
u16 func_021B6944(void *p)
{
    return (u16)(((struct Obj01264 *)p)->f3A - ((struct Obj01264 *)p)->f38);
}



void func_021B6950(char *p, int v)
{
    if (func_02085D3C() == 1) func_02700FE4(3, 3, v);
    ((struct Obj01264 *)p)->f30 = v;
    func_021B68A0(p);
}



/*
 * Guard on 0x02085D3C then an arm veneer call with the field at +0x30.
 *
 * Addresses are Black-image addresses.
 */
int func_021B697C(void *p)
{
    u32 f = ((struct Obj24061 *)p)->f30;
    if (func_02085D3C() == 1) {
        return func_02702364(f);
    }
    return 0;
}



int func_021B699C(void *p)
{
    void *v = ((struct Obj24062 *)p)->f30;
    if (func_02085D3C() == 1) {
        return func_027023CC(v);
    }
    return 0;
}



void func_021B69BC(void *p, u32 v)
{
    if (((struct Obj08254 *)p)->f2C == v) {
        return;
    }
    if (((struct Obj08254 *)p)->f20 != 0) {
        return;
    }
    ((struct Obj08254 *)p)->f2C = v;
    ((struct Obj08254 *)p)->f20 = 1;
}



void func_021B69D0(void *p)
{
    ((struct Obj24063 *)p)->f44 = 1;
}



void func_021B69D8(void *p)
{
    ((struct Obj24064 *)p)->f44 = 4;
}



/*
 * Clear the halfword at +4 and the byte at +6 of the ov172 state block. Filed
 * as the call witness for ov172 func_021B97AC.
 */
void func_021B69E0(void)
{
    d_021C88E4.h4 = 0;
    d_021C88E4.b6 = 0;
}



/*
 * Clear the 3-byte counter at g_021C88E4.
 *
 * Addresses are Black-image addresses.
 */
void func_021B69F0(void)
{
    u8 *p = (u8 *)0x021C88E4;
    ((struct Obj14294 *)p)->f0 = 0;
    ((struct Obj14294 *)p)->f2 = 0;
}
