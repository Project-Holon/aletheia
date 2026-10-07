/*
 * file:     pokemontrade_ircdemo.c
 * unit:     yes
 * function: func_021D4664, func_021D4820, func_021D48F0, func_021D49C4, func_021D49F4, func_021D4A48, func_021D4B88, func_021D4BF4
 * address:  0x021D4664
 * region:   ov117
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D4240  0x021D4240  thumb  ov117
 *   func_021DFC68  0x021DFC68  thumb  ov119
 *   func_021D4480  0x021D4480  thumb  ov117
 *   func_021E71F0  0x021E71F0  thumb  ov119
 *   func_021E7208  0x021E7208  thumb  ov119
 *   func_021E64B8  0x021E64B8  thumb  ov119
 *   func_021E4888  0x021E4888  thumb  ov119
 *   func_021E2680  0x021E2680  thumb  ov119
 *   func_021D4484  0x021D4484  thumb  ov117
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
 *   d_021D5220     0x021D5220  data
 *   d_021D53D0     0x021D53D0  data
 *   d_021D5600     0x021D5600  data
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
 *   func_021D4434  0x021D4434  thumb  ov117
 *   func_021E3034  0x021E3034  thumb  ov119
 *   func_021E2F2C  0x021E2F2C  thumb  ov119
 *   func_021DFDA0  0x021DFDA0  thumb  ov119
 *   func_02015FBC  0x02015FBC  thumb
 *   func_02015CAC  0x02015CAC  thumb
 *   func_02015F50  0x02015F50  thumb
 *   d_021D5200     0x021D5200  data
 *   d_021D52F8     0x021D52F8  data
 *   func_021D4490  0x021D4490  thumb  ov117
 *   func_02016028  0x02016028  thumb
 *   func_021D449C  0x021D449C  thumb  ov117
 *   d_021D51DC     0x021D51DC  data
 *   func_021DC720  0x021DC720  thumb  ov119
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_021E3E40  0x021E3E40  thumb  ov119
 *   func_0204B100  0x0204B100  arm
 *   func_02030734  0x02030734  arm
 *   func_021E5284  0x021E5284  thumb  ov119
 *   func_021E3208  0x021E3208  thumb  ov119
 *   func_02015C94  0x02015C94  thumb
 *   func_021E3070  0x021E3070  thumb  ov119
 *   func_021E2EFC  0x021E2EFC  thumb  ov119
 *   func_021D4CE8  0x021D4CE8  thumb  ov117
 *   d_021D55CC     0x021D55CC  data
 */
#include "../../matched/include/Obj05323.h"
#include "../../matched/include/Obj00982.h"
#include "../../matched/include/Obj01722.h"
#include "../../matched/include/Obj22645.h"
#include "../../matched/include/Obj00342.h"
#include "../../matched/include/Obj06419.h"
#include "../../matched/include/Obj02829.h"

#define FRAME (*(s32 *)(p + 0xF2C))
#define OBJ(i) (((u32 *)(p + 0x844))[i])
#define HEAP (*(u16 *)(p + 0x5F4))
#define SLOT0 (*(u32 *)(p + 0x85C))
#define WORK (*(u8 **)(p + 0xc))
struct WordSet;
struct MsgBank;
struct McssFade;
struct Bank;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef signed char s8;

typedef int s32;

typedef struct {
    s32 x, y, z;
} Vec;

typedef struct {
    u32 v[4];
} Quad;

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
extern void func_02015FBC(char *p, int v);
extern void func_02015CAC(void *p, u32 *src);
extern void func_02015F50(struct McssFade *w, u32 cur, u32 target, s32 step, u32 e);
extern void func_021D4490(u8 *p);
extern void func_02016028(void *a, u32 flag);
extern void func_021D449C(u8 *p);
extern void func_021DC720(char *p);
extern void func_0204A5AC(void);
extern void func_021E3E40(char *p);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_021E5284(char *p, int mode);
extern void func_021E3208(void *p, int a);
extern void func_02015C94(void *p, u32 *out);
extern void func_021E3070(void *w);
extern void func_021E2EFC(char *p);
extern void func_021D4CE8(u8 *p);
void func_021D4664(u8 *p);
void func_021D4820(u8 *p);
void func_021D48F0(u8 *p);
void func_021D49C4(void *p);
void func_021D49F4(void *obj, void *p);
void func_021D4A48(u8 *p, int idx);
void func_021D4B88(u8 *p);
void func_021D4BF4(u8 *p);
extern const u8 d_021D5220[];
extern const u8 d_021D53D0[];
extern u8 d_021D5600[];
extern const Quad d_021D5200;
extern const u8 d_021D52F8[];
extern const Vec d_021D51DC;
extern const char d_021D55CC[];


void func_021D4664(u8 *p)
{
    void *mon;
    u32 a;
    u32 b;
    Vec v1;
    Vec v2;
    u32 buf;

    func_021D4240(*(s8 * *)&((struct Obj05323 *)p)->f818);
    func_021DFC68((void *)(((struct Obj05323 *)p)->f85C), (int)p);
    func_021DFC68((void *)(((struct Obj05323 *)p)->f860), (int)p);
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
        if (((struct Obj05323 *)p)->f11ED == 0) {
            func_02015C30((void *)OBJ(0), (u32 *)(&v1));
            func_021DFD24((u32 *)SLOT0);
            if (((struct Obj05323 *)p)->f11EF != 0) {
                SLOT0 = (u32)func_021DFBB4((void *)OBJ(0), (void *)0x14, &v1, d_021D5600, HEAP);
            } else {
                SLOT0 = (u32)func_021DFBB4((void *)OBJ(0), (void *)0x12, &v1, (void *)d_021D5220, HEAP);
            }
            func_021E36C8(p, 2, 0, func_021D8FA4(p, func_021D8AA8(p)), 1);
            func_02015E04((void *)OBJ(2));
            func_02015EA0((void *)OBJ(2));
        } else {
            func_02015C30((void *)OBJ(0), (u32 *)(&v2));
            func_021DFD24((u32 *)SLOT0);
            if (((struct Obj05323 *)p)->f11EF != 0) {
                SLOT0 = (u32)func_021DFBB4((void *)OBJ(0), (void *)0x14, &v2, d_021D5600, HEAP);
            } else {
                SLOT0 = (u32)func_021DFBB4((void *)OBJ(0), (void *)0x28, &v2, (void *)d_021D53D0, HEAP);
            }
        }
        func_021D8E84(p, (int)func_021D48F0);
    }
}


void func_021D4820(u8 *p)
{
    func_0203D34C(0, ((struct Obj00982 *)p)->f5F4);
    if (((struct Obj00982 *)p)->f118C == 6) {
        func_02045CAC((struct MsgBank *)(((struct Obj00982 *)p)->f720), 0x98, (void *)(((struct Obj00982 *)p)->f73C));
    } else if (((struct Obj00982 *)p)->f118C == 8) {
        func_02045CAC((struct MsgBank *)(((struct Obj00982 *)p)->f720), 0x9B, (void *)(((struct Obj00982 *)p)->f73C));
    } else if (((struct Obj00982 *)p)->f11ED != 0) {
        func_02045CAC((struct MsgBank *)(((struct Obj00982 *)p)->f720), 0x82, (void *)(((struct Obj00982 *)p)->f73C));
    } else {
        func_02045CAC((struct MsgBank *)(((struct Obj00982 *)p)->f720), 0x81, (void *)(((struct Obj00982 *)p)->f73C));
    }
    func_0201EEF4(((struct Obj00982 *)p)->f724, 0, func_021D8FA4(p, func_021D8AA8(p)));
    func_0201F02C((struct WordSet *)(*(u32 *)&((struct Obj00982 *)p)->f724), 1, (void *)(((struct Obj00982 *)p)->f834));
    func_0201F250((struct WordSet *)(*(u32 *)&((struct Obj00982 *)p)->f724), (void *)(((struct Obj00982 *)p)->f738), (void *)(((struct Obj00982 *)p)->f73C));
    func_02041300(4, 0, 0, 0, 0x20, 0x18, 0x11);
    func_021E0FF4(p, 1, 0);
    func_021E7208(p, 0x14);
    *(volatile u16 *)0x04001050 = 0;
}


void func_021D48F0(u8 *p)
{
    Vec v;

    if (FRAME == 10) {
        func_021D4820(p);
    }
    if (((struct Obj00982 *)p)->f11ED == 0 && FRAME == 6) {
        func_02015C30((void *)OBJ(0), (u32 *)(&v));
        func_02015C48((void *)OBJ(2), (u32 *)(&v));
        func_02015EB0((void *)OBJ(2));
        func_02015EA0((void *)OBJ(0));
        func_02015E4C((void *)OBJ(2));
        *(u32 *)SLOT0 = OBJ(2);
    }
    if (FRAME > 0xC8 && func_021E12AC((char *)p) != 0) {
        func_021E1098((char *)p);
        if (((struct Obj00982 *)p)->f11ED == 0) {
            func_021E36D8(p, 0);
            OBJ(0) = OBJ(2);
            OBJ(2) = 0;
        }
        if (SLOT0 != 0) {
            func_020307B0((void *)SLOT0);
            SLOT0 = 0;
        }
        func_021D8E84(p, (int)func_021D4BF4);
    }
    func_021DFC68((void *)SLOT0, (int)p);
}


void func_021D49C4(void *p)
{
    func_021D4434(p);
    func_021E3034(((struct Obj01722 *)p)->fC, 6);
    func_021E2F2C(((struct Obj01722 *)p)->fC);
    func_020307B0(((struct Obj01722 *)p)->fC);
    ((struct Obj01722 *)p)->fC = 0;
    func_021D8E84(p, (int)func_021DFDA0);
}


void func_021D49F4(void *obj, void *p)
{
    Vec v;
    func_02015FBC(obj, 0x1f);
    func_02015EB0(obj);
    v.x = 0;
    v.y = -0x17000;
    v.z = 0xa000;
    func_02015C48(obj, (u32 *)(&v));
    func_02015E04(obj);
    func_02015CAC(obj, (u32 *)((char *)((struct Obj22645 *)p)->fC + 0x48));
    func_02015F50(obj, 0x10, 0x10, 0, 0x7fff);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021D4A48(u8 *p, int idx)
{
    void *x;
    u32 buf[3];

    x = func_021D8FA4(p, 1 - func_021D8AA8(p));
    func_02017E1C(x, 7, 0);
    if (func_02017E1C(x, 0x4c, 0) == 0) {
        func_02006984(func_02017E1C(x, 0xab, 0), func_02017E1C(x, 0x6f, 0), 0x40, 0, 0, 0, 0, 0);
    }
    if (((struct Obj00342 *)p)->f11EE == 0) {
        func_02015C30((void *)(((u32 *)(p + 0x844))[idx]), buf);
        func_021DFD24((u32 *)(*(u32 *)&((struct Obj00342 *)p)->f868));
        if (((struct Obj00342 *)p)->f11F0 != 0) {
            *(u32 *)&((struct Obj00342 *)p)->f868 = (u32)func_021DFBB4((void *)(((u32 *)(p + 0x844))[idx]), (void *)0x14, buf, d_021D5600, ((struct Obj00342 *)p)->f5F4);
        } else {
            *(u32 *)&((struct Obj00342 *)p)->f868 = (u32)func_021DFBB4((void *)(((u32 *)(p + 0x844))[idx]), (void *)0x28, buf, (void *)d_021D53D0, ((struct Obj00342 *)p)->f5F4);
        }
    } else {
        Quad t = d_021D5200;
        u32 obj = ((u32 *)(p + 0x844))[t.v[idx]];
        func_02015C30((void *)(((u32 *)(p + 0x844))[idx]), buf);
        func_021DFD24((u32 *)(*(u32 *)&((struct Obj00342 *)p)->f868));
        if (((struct Obj00342 *)p)->f11F0 != 0) {
            *(u32 *)&((struct Obj00342 *)p)->f868 = (u32)func_021DFBB4((void *)obj, (void *)0x14, buf, d_021D5600, ((struct Obj00342 *)p)->f5F4);
        } else {
            *(u32 *)&((struct Obj00342 *)p)->f868 = (u32)func_021DFBB4((void *)obj, (void *)0x12, buf, (void *)d_021D52F8, ((struct Obj00342 *)p)->f5F4);
        }
    }
}


void func_021D4B88(u8 *p)
{
    func_021D4490(p);
    ((struct Obj06419 *)p)->f854 = 1;
    func_02016028((void *)(((struct Obj06419 *)p)->f844), 0);
    func_02015E04((void *)(((struct Obj06419 *)p)->f844));
    if (((struct Obj06419 *)p)->f118C == 4) {
        Vec v = d_021D51DC;
        func_02015C48((void *)(((struct Obj06419 *)p)->f844), (u32 *)(&v));
    }
    func_021D4484(p, 0);
    func_021D8E84(p, (int)func_021D449C);
}


void func_021D4BF4(u8 *p)
{
    func_021DC720((char *)p);
    func_0204A5AC();
    func_021E3E40((char *)p);
    ((struct Obj02829 *)p)->f9C4 = (int)func_0204B100(3, 0, HEAP);
    WORK = func_02030734(HEAP, 0xBC, 1, d_021D55CC, 0x65);
    *(u16 *)(WORK + 0xBA) = HEAP;
    func_021E5284((char *)p, 1);
    *(volatile u16 *)0x04001050 = 0;
    *(volatile u16 *)0x04000050 = 0;
    func_021E3208(p, 2);
    func_021E36C8(p, 1, 0, func_021D8FA4(p, 1), 1);
    func_021E36C8(p, 2, 0, func_021D8FA4(p, 0), 1);
    func_021E36C8(p, 3, 1, func_021D8FA4(p, 1), 1);
    func_02015C94((void *)OBJ(3), (u32 *)(WORK + 0x54));
    func_02015EA0((void *)OBJ(1));
    func_02015EA0((void *)OBJ(2));
    func_02015EA0((void *)OBJ(3));
    func_021E3070(WORK);
    func_021E2EFC((char *)WORK);
    func_021D4484(p, 0);
    func_021D8E84(p, (int)func_021D4CE8);
}
