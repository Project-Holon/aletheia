/*
 * file:     pokemontrade_demo_up_p02.c
 * unit:     yes
 * function: func_021D4A34, func_021D4A54, func_021D4A94, func_021D4AB4, func_021D4B14, func_021D4C08
 * address:  0x021D4A34
 * region:   ov118
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D49F4  0x021D49F4  thumb  ov118
 *   func_02051A34  0x02051A34  arm
 *   func_02011610  0x02011610  thumb
 *   func_02051838  0x02051838  arm
 *   func_021D4490  0x021D4490  thumb  ov118
 *   func_02016028  0x02016028  thumb
 *   func_02015C48  0x02015C48  thumb
 *   func_021D4484  0x021D4484  thumb  ov118
 *   func_021D8E84  0x021D8E84  thumb  ov119
 *   func_021D449C  0x021D449C  thumb  ov118
 *   d_021D7C90     0x021D7C90  data
 *   func_021DC720  0x021DC720  thumb
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_021E3E40  0x021E3E40  thumb
 *   func_0204B100  0x0204B100  arm
 *   func_02030734  0x02030734  arm
 *   func_021E5284  0x021E5284  thumb
 *   func_021E3208  0x021E3208  thumb
 *   func_021D8FA4  0x021D8FA4  thumb
 *   func_021E36C8  0x021E36C8  thumb  ov119
 *   func_02015EA0  0x02015EA0  thumb
 *   func_021E2F34  0x021E2F34  thumb
 *   func_021E2FB0  0x021E2FB0  thumb ov119
 *   func_021E2D70  0x021E2D70  thumb
 *   d_021D7FD4  0x021D7FD4  data
 *   func_021E3004  0x021E3004  thumb  ov119
 *   func_021D4C20  0x021D4C20  thumb  ov118
 */
#include "../../matched/include/Obj13874.h"
#include "../../matched/include/Obj22660.h"
#include "../../matched/include/Obj22661.h"
#include "../../matched/include/Obj08049.h"
#include "../../matched/include/Obj22662.h"
#include "../../matched/include/Obj22663.h"

#define HEAP (*(u16 *)(p + 0x5F4))
#define OBJ(i) (((u32 *)(p + 0x844))[i])
#define WORK (*(u8 **)(p + 0xc))
struct IcaAnime;
struct Rec12;
struct Bank;
typedef unsigned int   u32;

typedef int s32;

typedef struct {
    s32 x, y, z;
} Vec;

typedef unsigned char u8;

typedef unsigned short u16;

extern u32 func_02051774(void);
extern void func_02051A2C(void *p, int v);
extern void func_02051A24(void *p, int v);
extern void func_021D49F4(void *obj, int on);
extern int func_02051A34(void *p);
extern unsigned int func_02011610(struct IcaAnime *, struct Rec12 *);
extern void func_02051838(void *, Vec *);
extern void func_021D4490(u8 *p);
extern void func_02016028(void *a, u32 flag);
extern void func_02015C48(void *p, u32 *src);
extern void func_021D4484(u8 *p, u32 v);
extern void func_021D8E84(void *p, int next);
extern void func_021D449C(u8 *p);
extern void func_021DC720(void *p);
extern void func_0204A5AC(void);
extern void func_021E3E40(void *p);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_021E5284(void *p, int a);
extern void func_021E3208(void *p, int a);
extern void *func_021D8FA4(void *, int);
extern void func_021E36C8(void *p, int a, int b, void *mon, int c);
extern void func_02015EA0(void *p);
extern void func_021E2F34(void *w);
extern void func_021E2FB0(char *p);
extern void func_021E2D70(void *w, int a);
extern void func_021E3004(char *p);
extern void func_021D4C20(u8 *p);
void func_021D4A34(void *p);
void func_021D4A54(void *obj, int on);
void func_021D4A94(void *p);
void func_021D4AB4(u8 *p);
void func_021D4B14(u8 *p);
void func_021D4C08(u8 *p);
extern const Vec d_021D7C90;
extern const char d_021D7FD4[];


/*
 * Addresses are Black-image addresses.
 */
void func_021D4A34(void *p)
{
    func_02051A2C(p, func_02051774());
    func_02051A24(p, (int)func_021D49F4);
}


void func_021D4A54(void *obj, int on)
{
    s32 buf[3];
    Vec *v;
    void *w;

    if (on != 0 && obj != 0) {
        w = (void *)func_02051A34(obj);
        if (((struct Obj22660 *)(*(char * *)&((struct Obj13874 *)w)->fC))->f9C != 0) {
            v = (Vec *)buf;
            v->x = 0;
            v->y = 0;
            v->z = 0;
            func_02011610(((struct Obj22661 *)(*(char * *)&((struct Obj13874 *)w)->fC))->f9C, (struct Rec12 *)v);
            func_02051838(obj, v);
        }
    }
}


void func_021D4A94(void *p)
{
    func_02051A2C(p, func_02051774());
    func_02051A24(p, (int)func_021D4A54);
}


void func_021D4AB4(u8 *p)
{
    func_021D4490(p);
    ((struct Obj08049 *)p)->f854 = 1;
    func_02016028((void *)(((struct Obj08049 *)p)->f844), 0);
    if (((struct Obj08049 *)p)->f118C == 6) {
        Vec v = d_021D7C90;
        func_02015C48((void *)(((struct Obj08049 *)p)->f844), (u32 *)(&v));
    }
    func_021D4484(p, 0);
    func_021D8E84(p, (int)func_021D449C);
}


void func_021D4B14(u8 *p)
{
    func_021DC720(p);
    func_0204A5AC();
    func_021E3E40(p);
    ((struct Obj22662 *)p)->f9C4 = (int)func_0204B100(3, 0, HEAP);
    WORK = func_02030734(HEAP, 0xBC, 1, d_021D7FD4, 0x98);
    *(u16 *)(WORK + 0xBA) = HEAP;
    func_021E5284(p, 0);
    *(volatile u16 *)0x04001050 = 0;
    *(volatile u16 *)0x04000050 = 0;
    func_021E3208(p, 3);
    func_021E36C8(p, 1, 0, func_021D8FA4(p, 1), 1);
    func_021E36C8(p, 2, 0, func_021D8FA4(p, 0), 1);
    func_021E36C8(p, 3, 1, func_021D8FA4(p, 1), 1);
    func_02015EA0((void *)OBJ(1));
    func_02015EA0((void *)OBJ(2));
    func_02015EA0((void *)OBJ(3));
    func_021E2F34(WORK);
    func_021E2FB0((char *)WORK);
    func_021E2D70(WORK, 1);
    func_021D4484(p, 0);
    func_021D8E84(p, (int)func_021D4C08);
}


void func_021D4C08(u8 *p)
{
    func_021E3004(((struct Obj22663 *)p)->fC);
    func_021D8E84(p, (int)func_021D4C20);
}
