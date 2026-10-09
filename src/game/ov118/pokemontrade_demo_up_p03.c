/*
 * file:     pokemontrade_demo_up_p03.c
 * unit:     yes
 * function: func_021D5748, func_021D5888, func_021D58F0, func_021D5930, func_021D5950, func_021D5990, func_021D59B0, func_021D5A60
 * address:  0x021D5748
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
 *   func_021D8AA8  0x021D8AA8  thumb  ov119
 *   func_021D8FA4  0x021D8FA4  thumb  ov119
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02006984  0x02006984  thumb
 *   func_02015C30  0x02015C30  thumb
 *   func_021DFD24  0x021DFD24  thumb  ov119
 *   func_021DFBB4  0x021DFBB4  thumb  ov119
 *   d_021D7CB4     0x021D7CB4  data
 *   d_021D7FEC     0x021D7FEC  data
 *   d_021D80C4     0x021D80C4  data
 *   d_021D8790     0x021D8790  data
 *   func_02015EB0  0x02015EB0  thumb
 *   func_02015C48  0x02015C48  thumb
 *   func_02015E04  0x02015E04  thumb
 *   func_02015C94  0x02015C94  thumb
 *   func_02015CAC  0x02015CAC  thumb
 *   func_02051A34  0x02051A34  arm
 *   func_02011610  0x02011610  thumb
 *   func_02051838  0x02051838  arm
 *   func_021D56F0  0x021D56F0  thumb  ov118
 *   func_02016028  0x02016028  thumb
 *   func_02015EA0  0x02015EA0  thumb
 *   func_021E71F0  0x021E71F0  thumb  ov119
 *   func_021E7208  0x021E7208  thumb  ov119
 *   func_021D54F0  0x021D54F0  thumb  ov118
 *   func_021D8E84  0x021D8E84  thumb  ov119
 *   d_021D7CA8     0x021D7CA8  data
 *   func_021DC720  0x021DC720  thumb
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_021E3E40  0x021E3E40  thumb
 *   func_0204B100  0x0204B100  arm
 *   func_02030734  0x02030734  arm
 *   func_021E5284  0x021E5284  thumb
 *   func_021E3208  0x021E3208  thumb
 *   func_021E36C8  0x021E36C8  thumb  ov119
 *   func_021E2F34  0x021E2F34  thumb
 *   func_021E2D70  0x021E2D70  thumb
 *   func_021E2FB0  0x021E2FB0  thumb ov119
 *   func_021D56E4  0x021D56E4  thumb
 *   func_021DFA60  0x021DFA60  thumb ov119
 *   func_021D5B74  0x021D5B74  thumb
 *   func_020435F4  0x020435F4  arm
 *   d_021D82A4  0x021D82A4  data
 */
#include "../../matched/include/Obj00672.h"
#include "../../matched/include/Obj13876.h"
#include "../../matched/include/Obj22675.h"
#include "../../matched/include/Obj22676.h"
#include "../../matched/include/Obj13877.h"
#include "../../matched/include/Obj22677.h"
#include "../../matched/include/Obj22678.h"
#include "../../matched/include/Obj03770.h"
#include "../../matched/include/Obj13878.h"

#define HEAP (*(u16 *)(p + 0x5F4))
#define OBJ(i) (((void **)(p + 0x844))[i])
#define WORK (*(u8 **)(p + 0xc))
struct IcaAnime;
struct Rec12;
struct Bank;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef struct {
    u32 v[4];
} Quad;

typedef int s32;

typedef struct {
    s32 x, y, z;
} Vec;

extern int func_021D8AA8(void *);
extern void *func_021D8FA4(void *, int);
extern u32 func_02017E1C(void *, u32, u32);
extern u32 func_02006984(u32, u32, u32, u32, u32, u32, u32, u32);
extern void func_02015C30(void *p, u32 *out);
extern void func_021DFD24(u32 *p);
extern void *func_021DFBB4(void *a0, void *a1, void *a2, void *a3, u16 heapId);
extern void func_02015EB0(void *p);
extern void func_02015C48(void *p, u32 *src);
extern void func_02015E04(void *p);
extern void func_02015C94(void *p, u32 *out);
extern void func_02015CAC(void *p, u32 *src);
extern int func_02051A34(void *p);
extern unsigned int func_02011610(struct IcaAnime *, struct Rec12 *);
extern void func_02051838(void *, Vec *);
extern u32 func_02051774(void);
extern void func_02051A2C(void *p, int v);
extern void func_02051A24(void *p, int v);
extern void func_021D56F0(u8 *p);
extern void func_02016028(void *a, u32 flag);
extern void func_02015EA0(void *p);
extern void func_021E71F0(void *p, int a);
extern void func_021E7208(void *p, int a);
extern void func_021D54F0(u8 *p, u8 *outSame, u8 *outFlag, u32 key, int enemy);
extern void func_021D8E84(void *p, int next);
extern void func_021DC720(void *p);
extern void func_0204A5AC(void);
extern void func_021E3E40(void *p);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_021E5284(void *p, int a);
extern void func_021E3208(void *p, int a);
extern void func_021E36C8(void *p, int a, int b, void *mon, int c);
extern void func_021E2F34(void *w);
extern void func_021E2D70(void *w, int a);
extern void func_021E2FB0(char *p);
extern void func_021D56E4(u8 *p, u32 v);
extern void func_021DFA60(u32 a);
extern void func_021D5B74(u8 *p);
extern void func_020435F4(u32 planes);
void func_021D5748(u8 *p, int idx);
void func_021D5888(u8 *p, int idx);
void func_021D58F0(void *obj, int on);
void func_021D5930(void *p);
void func_021D5950(void *obj, int on);
void func_021D5990(void *p);
void func_021D59B0(u8 *p);
void func_021D5A60(u8 *p);
extern const Quad d_021D7CB4;
extern const u8 d_021D7FEC[];
extern const u8 d_021D80C4[];
extern u8 d_021D8790[];
extern const Vec d_021D7CA8;
extern const char d_021D82A4[];



/*
 * Addresses are Black-image addresses.
 */
void func_021D5748(u8 *p, int idx)
{
    void *x;
    u32 buf[3];

    x = func_021D8FA4(p, 1 - func_021D8AA8(p));
    func_02017E1C(x, 7, 0);
    if (func_02017E1C(x, 0x4c, 0) == 0) {
        func_02006984(func_02017E1C(x, 0xab, 0), func_02017E1C(x, 0x6f, 0), 0x40, 0, 0, 0, 0, 0);
    }
    if (((struct Obj00672 *)p)->f11EE == 0) {
        func_02015C30((void *)(((u32 *)(p + 0x844))[idx]), buf);
        func_021DFD24((u32 *)(*(u32 *)&((struct Obj00672 *)p)->f868));
        if (((struct Obj00672 *)p)->f11F0 != 0) {
            *(u32 *)&((struct Obj00672 *)p)->f868 = (u32)func_021DFBB4((void *)(((u32 *)(p + 0x844))[idx]), (void *)0x14, buf, d_021D8790, ((struct Obj00672 *)p)->f5F4);
        } else {
            *(u32 *)&((struct Obj00672 *)p)->f868 = (u32)func_021DFBB4((void *)(((u32 *)(p + 0x844))[idx]), (void *)0x28, buf, (void *)d_021D80C4, ((struct Obj00672 *)p)->f5F4);
        }
    } else {
        Quad t = d_021D7CB4;
        u32 obj = ((u32 *)(p + 0x844))[t.v[idx]];
        func_02015C30((void *)(((u32 *)(p + 0x844))[idx]), buf);
        func_021DFD24((u32 *)(*(u32 *)&((struct Obj00672 *)p)->f868));
        if (((struct Obj00672 *)p)->f11F0 != 0) {
            *(u32 *)&((struct Obj00672 *)p)->f868 = (u32)func_021DFBB4((void *)obj, (void *)0x14, buf, d_021D8790, ((struct Obj00672 *)p)->f5F4);
        } else {
            *(u32 *)&((struct Obj00672 *)p)->f868 = (u32)func_021DFBB4((void *)obj, (void *)0x12, buf, (void *)d_021D7FEC, ((struct Obj00672 *)p)->f5F4);
        }
    }
}



void func_021D5888(u8 *p, int idx)
{
    u32 *obj = (u32 *)(p + 0x844);
    Vec v;

    func_02015EB0((void *)obj[idx]);
    v.x = 0;
    v.y = -0x17000;
    v.z = 0xA000;
    func_02015C48((void *)obj[idx], (u32 *)(&v));
    func_02015E04((void *)obj[idx]);
    func_02015C94((void *)obj[idx], (u32 *)(&v));
    if (v.x < 0) {
        v.x = -0x10000;
    } else {
        v.x = 0x10000;
    }
    v.y = 0x10000;
    v.z = 0x1000;
    func_02015CAC((void *)obj[idx], (u32 *)(&v));
}



void func_021D58F0(void *obj, int on)
{
    s32 buf[3];
    Vec *v;
    void *w;

    if (on != 0 && obj != 0) {
        w = (void *)func_02051A34(obj);
        if (((struct Obj22675 *)(*(char * *)&((struct Obj13876 *)w)->fC))->f98 != 0) {
            v = (Vec *)buf;
            v->x = 0;
            v->y = 0;
            v->z = 0;
            func_02011610(((struct Obj22676 *)(*(char * *)&((struct Obj13876 *)w)->fC))->f98, (struct Rec12 *)v);
            func_02051838(obj, v);
        }
    }
}



void func_021D5930(void *p)
{
    func_02051A2C(p, func_02051774());
    func_02051A24(p, (int)func_021D58F0);
}



void func_021D5950(void *obj, int on)
{
    s32 buf[3];
    Vec *v;
    void *w;

    if (on != 0 && obj != 0) {
        w = (void *)func_02051A34(obj);
        if (((struct Obj22677 *)(*(char * *)&((struct Obj13877 *)w)->fC))->f9C != 0) {
            v = (Vec *)buf;
            v->x = 0;
            v->y = 0;
            v->z = 0;
            func_02011610(((struct Obj22678 *)(*(char * *)&((struct Obj13877 *)w)->fC))->f9C, (struct Rec12 *)v);
            func_02051838(obj, v);
        }
    }
}



void func_021D5990(void *p)
{
    func_02051A2C(p, func_02051774());
    func_02051A24(p, (int)func_021D5950);
}



void func_021D59B0(u8 *p)
{
    func_021D56F0(p);
    ((struct Obj03770 *)p)->f854 = 1;
    func_02016028((void *)(((struct Obj03770 *)p)->f844), 0);
    func_02015EA0((void *)(((struct Obj03770 *)p)->f844));
    func_02015EA0((void *)(((struct Obj03770 *)p)->f848));
    if (((struct Obj03770 *)p)->f118C == 6) {
        Vec v = d_021D7CA8;
        func_02015C48((void *)(((struct Obj03770 *)p)->f844), (u32 *)(&v));
    }
    func_021E71F0(p, 0x11);
    func_021E7208(p, 0);
    func_021D54F0(p, p + 0x11ED, p + 0x11EF, ((struct Obj03770 *)p)->f834, 1);
    func_021D54F0(p, p + 0x11EE, p + 0x11F0, ((struct Obj03770 *)p)->f830, 0);
    func_021D8E84(p, (int)func_021D5A60);
}



void func_021D5A60(u8 *p)
{
    func_021DC720(p);
    func_0204A5AC();
    func_021E3E40(p);
    ((struct Obj13878 *)p)->f9C4 = (int)func_0204B100(3, 0, HEAP);
    WORK = func_02030734(HEAP, 0xBC, 1, d_021D82A4, 0xA8);
    *(u16 *)(WORK + 0xBA) = HEAP;
    func_021E5284(p, 0);
    *(volatile u16 *)0x04001050 = 0;
    *(volatile u16 *)0x04000050 = 0;
    func_021E3208(p, 5);
    func_021E36C8(p, 1, 0, func_021D8FA4(p, 1), 1);
    func_021E36C8(p, 2, 0, func_021D8FA4(p, 0), 1);
    func_021E36C8(p, 3, 1, func_021D8FA4(p, 1), 1);
    func_02015EA0(OBJ(0));
    func_02015EA0(OBJ(1));
    func_02015EA0(OBJ(2));
    func_02015EA0(OBJ(3));
    func_021E2F34(WORK);
    func_021E2D70(WORK, 3);
    func_021E2FB0((char *)WORK);
    func_021D56E4(p, 0x2B5);
    func_021DFA60(((struct Obj13878 *)p)->fF2C);
    func_021D8E84(p, (int)func_021D5B74);
    func_020435F4(0x18);
}
