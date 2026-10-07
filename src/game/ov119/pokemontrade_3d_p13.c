/*
 * file:     pokemontrade_3d_p13.c
 * unit:     yes
 * function: func_021E3BB0, func_021E3C20, func_021E3D04, func_021E3D88, func_021E3DBC, func_021E3E00, func_021E3E40
 * address:  0x021E3BB0
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
 *   func_0207FA0C 0x0207FA0C arm
 *   func_0207FA40 0x0207FA40 arm
 *   func_0207FADC 0x0207FADC arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021B62E0 0x021B62E0 thumb ov067
 *   func_021B6558 0x021B6558 thumb ov067
 *   func_021B6520 0x021B6520 thumb ov067
 *   d_021E7C0C 0x021E7C0C data a4
 *   func_02007A18  0x02007A18  thumb
 *   func_0204A48C  0x0204A48C  arm
 *   d_021E7CE4     0x021E7CE4  data  ov119
 *   d_021E7D40     0x021E7D40  data  ov119
 */
#include "../../matched/include/Obj10377.h"
#include "../../matched/include/Obj00252.h"
#include "../../matched/include/Obj13914.h"
#include "../../matched/include/Obj22798.h"
#include "../../matched/include/Obj10378.h"
#include "../../matched/include/Obj22799.h"

struct Personal;
struct Sav;
struct Sub020079BCEntry;
struct Cfg;
typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u32 f0, f4; u16 f8, fA, fC, fE, f10, f12; u32 f14, f18, f1C; } Element;

typedef struct { Element e[4]; } Template;

typedef struct { void *f0; u32 f4; int f8; u32 fC, f10, f14; int f18, f1C; } Config;

typedef unsigned char  u8;

extern void func_0207FA0C(void);
extern void func_0207FA40(const void *, int, int);
extern void func_0207FADC(void);
extern void func_02082BCC(void *, int, int);
extern void *func_021B62E0(Config *, int);
extern void func_021B6558(unsigned char *p, unsigned int id, unsigned int v);
extern void func_021B6520(u8 *p, u32 v);
extern u32 func_02017DBC(struct Sav *p);
extern u32 func_02017DE4(struct Sav *p, u32 f);
extern u32 func_02017E88(void *p, u32 id, u32 v);
extern void *func_0201ADE4(unsigned int, int, unsigned int);
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern void func_0201AE14(void *);
extern struct Sub020079BCEntry *func_02007A18(void **save, u32 box, u32 slot);
extern u32 func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern void *func_020185F0(void *);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
void func_021E3BB0(char *p);
void func_021E3C20(char *p);
unsigned char func_021E3D04(void *mon, unsigned int heap);
void func_021E3D88(char *p, int box, unsigned char *out);
void func_021E3DBC(char *p, void *party, unsigned char *out);
int func_021E3E00(char *p, int i);
void func_021E3E40(char *p);
extern const Template d_021E7C0C;
extern const char d_021E7CE4[];
extern const char d_021E7D40[];

void func_021E3BB0(char *p)
{
    int i;
    int j;
    int component;
    int shift;
    char *q;
    for (i = 0; i < 16; i++) {
        q = p + i * 2;
        ((struct Obj10377 *)q)->f1154 = 0;
        for (j = 0; j < 3; j++) {
            shift = j * 5;
            component = (((struct Obj10377 *)q)->f1134 >> shift) & 31;
            if (component)
                component--;
            ((struct Obj10377 *)q)->f1154 |= (unsigned short)((component & 31) << shift);
        }
    }
    func_0207FA0C();
    func_0207FA40(p + 0x1154, 0x2000, 32);
    func_0207FADC();
}

void func_021E3C20(char *p)
{
    Template t = d_021E7C0C;
    Config c;
    u16 a, b, d;
    func_02082BCC(&c, 0, 32);
    c.f0 = &t;
    c.f4 = 4;
    c.f8 = *(int *)&((struct Obj00252 *)p)->f9C4;
    c.fC = 4;
    c.f1C = 1;
    c.f10 = 7;
    c.f14 = 0;
    c.f18 = 2;
    a = *(u32 *)&((struct Obj00252 *)p)->f894;
    t.e[1].f8 = a;
    b = *(u32 *)&((struct Obj00252 *)p)->f880;
    t.e[1].fA = b;
    d = *(u32 *)&((struct Obj00252 *)p)->f8B0;
    t.e[1].fC = d;
    t.e[1].fE = 6; t.e[1].f10 = 5; t.e[1].f12 = 4;
    t.e[1].f18 = 0; t.e[1].f1C = 0x54C;
    t.e[2].f8 = a; t.e[2].fA = b; t.e[2].fC = d;
    t.e[2].fE = 9; t.e[2].f10 = 8; t.e[2].f12 = 7;
    t.e[2].f18 = 8; t.e[2].f1C = 0x54C;
    t.e[3].f8 = a; t.e[3].fA = b; t.e[3].fC = d;
    t.e[3].fE = 22; t.e[3].f10 = 21; t.e[3].f12 = 20;
    t.e[3].f18 = 48; t.e[3].f1C = 0x54C;
    ((struct Obj00252 *)p)->f9C0 = func_021B62E0(&c, ((struct Obj00252 *)p)->f5F4);
    func_021B6558(((struct Obj00252 *)p)->f9C0, 9, 0);
    func_021B6558(((struct Obj00252 *)p)->f9C0, 8, 0);
    func_021B6520(((struct Obj00252 *)p)->f9C0, 2);
}

unsigned char func_021E3D04(void *mon, unsigned int heap)
{
    int old;
    unsigned short result;
    int species;
    void *data;
    result = 0;
    old = func_02017DBC(mon);
    species = func_02017E88(mon, 5, 0);
    if (func_02017E88(mon, 0xA9, 0)) {
        if (!func_02017E88(mon, 0x4C, 0)) {
            unsigned short form = func_02017E88(mon, 0x6F, 0);
            data = func_0201ADE4((unsigned short)species, form, heap);
            result = func_0201AE1C(data, 0x21);
            func_0201AE14(data);
        } else {
            result = 1;
            if (species != 0x1EA)
                result = 8;
        }
        result++;
    }
    func_02017DE4(mon, old);
    return result;
}


void func_021E3D88(char *p, int box, unsigned char *out)
{
    unsigned char i;

    for (i = 0; i < 30; i++)
        out[i] = func_021E3D04(func_02007A18(((struct Obj13914 *)p)->f828, box, i), ((struct Obj13914 *)p)->f5F4);
}

void func_021E3DBC(char *p, void *party, unsigned char *out)
{
    int count;
    unsigned char i;
    count = func_0201AA18(party);
    for (i = 0; i < 6; i++) {
        if (count > i)
            out[i] = func_021E3D04(func_020185F0(func_0201AB28(party, i)), ((struct Obj22798 *)p)->f5F4);
        else
            out[i] = 0;
    }
}

int func_021E3E00(char *p, int i)
{
    while (i < ((struct Obj10378 *)p)->f630 + 1) {
        if (i == ((struct Obj10378 *)p)->f630) {
            func_021E3DBC(p, ((struct Obj10378 *)p)->f838, (unsigned char *)(p + 0x2E0));
            return 1;
        }
        func_021E3D88(p, i, (unsigned char *)(p + 0x10 + i * 30));
        break;
    }
    return 0;
}


/*
 * Unlabelled Thumb tail-call wrapper after pool_021E3E3C, seeded so that
 * ov117 func_021D4BF4 has a witness: forwards the two ov119 tables and the
 * u16 heap id held at +0x5F4 to the ARM function 0x0204A48C.
 *
 * Addresses are Black-image addresses.
 */
void func_021E3E40(char *p)
{
    func_0204A48C((const struct Cfg *)d_021E7CE4, (u32)d_021E7D40, ((struct Obj22799 *)p)->f5F4);
}
