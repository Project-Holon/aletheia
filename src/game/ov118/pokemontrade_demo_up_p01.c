/*
 * file:     pokemontrade_demo_up_p01.c
 * unit:     yes
 * function: func_021D4664, func_021D4820, func_021D48F0, func_021D49C4, func_021D49F4, func_021D4A34, func_021D4A54, func_021D4A94, func_021D4AB4, func_021D4B14, func_021D4C08
 * address:  0x021D4664
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
 *   func_021D4240  0x021D4240  thumb  ov118
 *   func_021DFC68  0x021DFC68  thumb  ov119
 *   func_021D4480  0x021D4480  thumb  ov118
 *   func_021E71F0  0x021E71F0  thumb  ov119
 *   func_021E7208  0x021E7208  thumb  ov119
 *   func_021E64B8  0x021E64B8  thumb  ov119
 *   func_021E4888  0x021E4888  thumb  ov119
 *   func_021E2680  0x021E2680  thumb  ov119
 *   func_021D4484  0x021D4484  thumb  ov118
 *   func_021D8AA8  0x021D8AA8  thumb  ov119
 *   func_021D8FA4  0x021D8FA4  thumb  ov119
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02006CAC  0x02006CAC  thumb
 *   func_02006984  0x02006984  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02015C30  0x02015C30  thumb
 *   func_021DFD24  0x021DFD24  thumb  ov119
 *   func_021DFBB4  0x021DFBB4  thumb  ov119
 *   func_021E36C8  0x021E36C8  thumb  ov119
 *   func_02015E04  0x02015E04  thumb
 *   func_02015EA0  0x02015EA0  thumb
 *   func_021D8E84  0x021D8E84  thumb  ov119
 *   d_021D7D00     0x021D7D00  data
 *   d_021D7DD8     0x021D7DD8  data
 *   d_021D86A0     0x021D86A0  data
 *   func_0203D34C  0x0203D34C  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201EEF4  0x0201EEF4  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_02041300  0x02041300  arm
 *   func_021E0FF4  0x021E0FF4  thumb  ov119
 *   func_02015C48  0x02015C48  thumb
 *   func_02015EB0  0x02015EB0  thumb
 *   func_02015E4C  0x02015E4C  thumb
 *   func_021E12AC  0x021E12AC  thumb  ov119
 *   func_021E1098  0x021E1098  thumb  ov119
 *   func_021E36D8  0x021E36D8  thumb  ov119
 *   func_021D4434  0x021D4434  thumb  ov118
 *   func_021E3034  0x021E3034  thumb  ov119
 *   func_021E2F2C  0x021E2F2C  thumb  ov119
 *   func_021DFDA0  0x021DFDA0  thumb  ov119
 *   func_02051A34 0x02051A34 arm
 *   func_02011610 0x02011610 thumb
 *   func_02051838 0x02051838 arm
 *   func_021D4490  0x021D4490  thumb  ov118
 *   func_02016028  0x02016028  thumb
 *   func_021D449C  0x021D449C  thumb  ov118
 *   d_021D7C90     0x021D7C90  data
 *   func_021DC720  0x021DC720  thumb
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_021E3E40  0x021E3E40  thumb
 *   func_0204B100  0x0204B100  arm
 *   func_02030734  0x02030734  arm
 *   func_021E5284  0x021E5284  thumb
 *   func_021E3208  0x021E3208  thumb
 *   func_021E2F34  0x021E2F34  thumb
 *   func_021E2FB0  0x021E2FB0  thumb ov119
 *   func_021E2D70  0x021E2D70  thumb
 *   d_021D7FD4  0x021D7FD4  data
 *   func_021E3004  0x021E3004  thumb  ov119
 *   func_021D4C20  0x021D4C20  thumb  ov118
 */
#include "../../matched/include/Obj05324.h"
#include "../../matched/include/Obj00983.h"
#include "../../matched/include/Obj01723.h"
#include "../../matched/include/Obj13873.h"
#include "../../matched/include/Obj22658.h"
#include "../../matched/include/Obj22659.h"
#include "../../matched/include/Obj13874.h"
#include "../../matched/include/Obj22660.h"
#include "../../matched/include/Obj22661.h"
#include "../../matched/include/Obj08049.h"
#include "../../matched/include/Obj22662.h"
#include "../../matched/include/Obj22663.h"

#define FRAME (*(s32 *)(p + 0xF2C))
#define OBJ(i) (((u32 *)(p + 0x844))[i])
#define HEAP (*(u16 *)(p + 0x5F4))
#define SLOT0 (*(u32 *)(p + 0x85C))
#define WORK (*(u8 **)(p + 0xc))
struct WordSet;
struct MsgBank;
struct IcaAnime;
struct Rec12;
struct Bank;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef signed char s8;

typedef int s32;

typedef struct {
    s32 x, y, z;
} Vec_021D4664;

typedef struct {
    s32 x, y, z;
} Vec_021D48F0;

typedef struct { int x,y,z; } Vec_021D49F4;

typedef struct {
    s32 x, y, z;
} Vec;

extern void func_021D4240(s8 *fade);
extern void func_021DFC68(void *p, int a1);
extern int func_021D4480(int);
extern void func_021E71F0(void *p, int a);
extern void func_021E7208(void *p, int a);
extern void func_021E64B8(void *p);
extern void func_021E4888(char *p);
extern void func_021E2680(char *p);
extern void func_021D4484(u8 *p, u32 v);
extern int func_021D8AA8(void *);
extern void *func_021D8FA4(void *, int);
extern u32 func_02017E1C(void *, u32, u32);
extern void func_02006CAC(void **out);
extern u32 func_02006984(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);
extern u32 func_020307B0(void *p);
extern void func_02015C30(void *p, u32 *out);
extern void func_021DFD24(u32 *p);
extern void *func_021DFBB4(void *a0, void *a1, void *a2, void *a3, u16 heapId);
extern void func_021E36C8(void *p, int a, int b, void *mon, int c);
extern void func_02015E04(void *p);
extern void func_02015EA0(void *p);
extern void func_021D8E84(void *p, int next);
extern void func_0203D34C(u32 a, u32 b);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201EEF4(struct WordSet *p, u32 i, void *mon);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02041300(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void func_021E0FF4(void *p, int a, int b);
extern void func_02015C48(void *p, u32 *src);
extern void func_02015EB0(void *p);
extern void func_02015E4C(void *p);
extern int func_021E12AC(char *p);
extern void func_021E1098(char *p);
extern void func_021E36D8(void *p, int a);
extern void func_021D4434(void *);
extern void func_021E3034(u32 *p, int a1);
extern void func_021E2F2C(void *);
extern void func_021DFDA0(void *p);
extern int func_02051A34(void *p);
extern unsigned int func_02011610(struct IcaAnime *p, struct Rec12 *dst);
extern void func_02051838(void *, Vec_021D49F4 *);
extern u32 func_02051774(void);
extern void func_02051A2C(void *p, int v);
extern void func_02051A24(void *p, int v);
extern void func_021D4490(u8 *p);
extern void func_02016028(void *a, u32 flag);
extern void func_021D449C(u8 *p);
extern void func_021DC720(void *p);
extern void func_0204A5AC(void);
extern void func_021E3E40(void *p);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_021E5284(void *p, int a);
extern void func_021E3208(void *p, int a);
extern void func_021E2F34(void *w);
extern void func_021E2FB0(char *p);
extern void func_021E2D70(void *w, int a);
extern void func_021E3004(char *p);
extern void func_021D4C20(u8 *p);
void func_021D4664(u8 *p);
void func_021D4820(u8 *p);
void func_021D48F0(u8 *p);
void func_021D49C4(void *p);
void func_021D49F4(void *obj, int on);
void func_021D4A34(void *p);
void func_021D4A54(void *obj, int on);
void func_021D4A94(void *p);
void func_021D4AB4(u8 *p);
void func_021D4B14(u8 *p);
void func_021D4C08(u8 *p);
extern const u8 d_021D7D00[];
extern const u8 d_021D7DD8[];
extern u8 d_021D86A0[];
extern const Vec d_021D7C90;
extern const char d_021D7FD4[];



void func_021D4664(u8 *p)
{
    void *mon;
    u32 a;
    u32 b;
    Vec_021D4664 v1;
    Vec_021D4664 v2;
    u32 buf;

    func_021D4240(*(s8 * *)&((struct Obj05324 *)p)->f818);
    func_021DFC68((void *)(((struct Obj05324 *)p)->f85C), (int)p);
    func_021DFC68((void *)(((struct Obj05324 *)p)->f860), (int)p);
    if (FRAME > func_021D4480(0x2A)) {
        func_021E71F0(p, 0x11);
        func_021E7208(p, 0);
        func_021E64B8(p);
        func_021E4888((char *)p);
        func_021E2680((char *)p);
        func_021D4484(p, 0);
        mon = func_021D8FA4(p, func_021D8AA8(p));
        func_02017E1C(mon, 7, 0);
        if (func_02017E1C(mon, 0x4C, 0) == 0) {
            a = func_02017E1C(mon, 0xAB, 0);
            b = func_02017E1C(mon, 0x6F, 0);
            func_02006CAC((void **)(&buf));
            func_02006984(a, b, 0x40, 0, 0, 0, 0, (u32)(&buf));
        }
        if (SLOT0 != 0) {
            func_020307B0((void *)SLOT0);
            SLOT0 = 0;
        }
        if (((struct Obj05324 *)p)->f11ED == 0) {
            func_02015C30((void *)OBJ(0), (u32 *)(&v1));
            func_021DFD24((u32 *)SLOT0);
            if (((struct Obj05324 *)p)->f11EF != 0) {
                SLOT0 = (u32)func_021DFBB4((void *)OBJ(0), (void *)0x14, &v1, d_021D86A0, HEAP);
            } else {
                SLOT0 = (u32)func_021DFBB4((void *)OBJ(0), (void *)0x12, &v1, (void *)d_021D7D00, HEAP);
            }
            func_021E36C8(p, 2, 0, func_021D8FA4(p, func_021D8AA8(p)), 1);
            func_02015E04((void *)OBJ(2));
            func_02015EA0((void *)OBJ(2));
        } else {
            func_02015C30((void *)OBJ(0), (u32 *)(&v2));
            func_021DFD24((u32 *)SLOT0);
            if (((struct Obj05324 *)p)->f11EF != 0) {
                SLOT0 = (u32)func_021DFBB4((void *)OBJ(0), (void *)0x14, &v2, d_021D86A0, HEAP);
            } else {
                SLOT0 = (u32)func_021DFBB4((void *)OBJ(0), (void *)0x28, &v2, (void *)d_021D7DD8, HEAP);
            }
        }
        func_021D8E84(p, (int)func_021D48F0);
    }
}



void func_021D4820(u8 *p)
{
    func_0203D34C(0, ((struct Obj00983 *)p)->f5F4);
    if (((struct Obj00983 *)p)->f118C == 6) {
        func_02045CAC((struct MsgBank *)(((struct Obj00983 *)p)->f720), 0x98, (void *)(((struct Obj00983 *)p)->f73C));
    } else if (((struct Obj00983 *)p)->f118C == 8) {
        func_02045CAC((struct MsgBank *)(((struct Obj00983 *)p)->f720), 0x9B, (void *)(((struct Obj00983 *)p)->f73C));
    } else if (((struct Obj00983 *)p)->f11ED != 0) {
        func_02045CAC((struct MsgBank *)(((struct Obj00983 *)p)->f720), 0x82, (void *)(((struct Obj00983 *)p)->f73C));
    } else {
        func_02045CAC((struct MsgBank *)(((struct Obj00983 *)p)->f720), 0x81, (void *)(((struct Obj00983 *)p)->f73C));
    }
    func_0201EEF4(((struct Obj00983 *)p)->f724, 0, func_021D8FA4(p, func_021D8AA8(p)));
    func_0201F02C((struct WordSet *)(*(u32 *)&((struct Obj00983 *)p)->f724), 1, (void *)(((struct Obj00983 *)p)->f834));
    func_0201F250((struct WordSet *)(*(u32 *)&((struct Obj00983 *)p)->f724), (void *)(((struct Obj00983 *)p)->f738), (void *)(((struct Obj00983 *)p)->f73C));
    func_02041300(4, 0, 0, 0, 0x20, 0x18, 0x11);
    func_021E0FF4(p, 1, 0);
    func_021E7208(p, 0x14);
    *(volatile u16 *)0x04001050 = 0;
}



void func_021D48F0(u8 *p)
{
    Vec_021D48F0 v;

    if (FRAME == 10) {
        func_021D4820(p);
    }
    if (((struct Obj00983 *)p)->f11ED == 0 && FRAME == 6) {
        func_02015C30((void *)OBJ(0), (u32 *)(&v));
        func_02015C48((void *)OBJ(2), (u32 *)(&v));
        func_02015EB0((void *)OBJ(2));
        func_02015EA0((void *)OBJ(0));
        func_02015E4C((void *)OBJ(2));
        *(u32 *)SLOT0 = OBJ(2);
    }
    if (FRAME > 0xC8 && func_021E12AC((char *)p) != 0) {
        func_021E1098((char *)p);
        if (((struct Obj00983 *)p)->f11ED == 0) {
            func_021E36D8(p, 0);
            OBJ(0) = OBJ(2);
            OBJ(2) = 0;
        }
        if (SLOT0 != 0) {
            func_020307B0((void *)SLOT0);
            SLOT0 = 0;
        }
        func_021D8E84(p, (int)func_021D4B14);
    }
    func_021DFC68((void *)SLOT0, (int)p);
}



void func_021D49C4(void *p)
{
    func_021D4434(p);
    func_021E3034(((struct Obj01723 *)p)->fC, 6);
    func_021E2F2C(((struct Obj01723 *)p)->fC);
    func_020307B0(((struct Obj01723 *)p)->fC);
    ((struct Obj01723 *)p)->fC = 0;
    func_021D8E84(p, (int)func_021DFDA0);
}


void func_021D49F4(void *obj, int on) {
 int buf[3]; Vec_021D49F4 *v; void *w;
 if (on != 0 && obj != 0) {
 w=(void *)func_02051A34(obj);
 if (((struct Obj22658 *)(*(char * *)&((struct Obj13873 *)w)->fC))->f98!=0) {
 v=(Vec_021D49F4 *)buf; v->x=0; v->y=0; v->z=0;
 func_02011610(((struct Obj22659 *)(*(char * *)&((struct Obj13873 *)w)->fC))->f98,(struct Rec12 *)v);
 func_02051838(obj,v);
 }
 }
}



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
            func_02051838(obj, (Vec_021D49F4 *)v);
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
