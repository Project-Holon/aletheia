/*
 * file:     pokemontrade_demo_up_p05.c
 * unit:     yes
 * function: func_021D5748, func_021D5888, func_021D58F0, func_021D5930, func_021D5950
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
 */
#include "../../matched/include/Obj00672.h"
#include "../../matched/include/Obj13876.h"
#include "../../matched/include/Obj22675.h"
#include "../../matched/include/Obj22676.h"
#include "../../matched/include/Obj13877.h"
#include "../../matched/include/Obj22677.h"
#include "../../matched/include/Obj22678.h"

struct IcaAnime;
struct Rec12;
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
void func_021D5748(u8 *p, int idx);
void func_021D5888(u8 *p, int idx);
void func_021D58F0(void *obj, int on);
void func_021D5930(void *p);
void func_021D5950(void *obj, int on);
extern const Quad d_021D7CB4;
extern const u8 d_021D7FEC[];
extern const u8 d_021D80C4[];
extern u8 d_021D8790[];


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
