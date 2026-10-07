/*
 * file:     field_place_name_p08.c
 * unit:     yes
 * function: func_021BC9AC, func_021BC9C0, func_021BC9CC, func_021BCA48, func_021BCA64, func_021BCA6C, func_021BCA74, func_021BCA78, func_021BCA80, func_021BCA88, func_021BCA8C, func_021BCAB0, func_021BCB48
 * address:  0x021BC9AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BD1DC  0x021BD1DC  thumb  ov021
 *   func_02045770  0x02045770  arm
 *   func_021BD1FC  0x021BD1FC  thumb  ov021
 *   func_021BD204  0x021BD204  thumb  ov021
 *   func_021BD1EC  0x021BD1EC  thumb  ov021
 *   func_021BD1F4  0x021BD1F4  thumb  ov021
 *   func_020439A0  0x020439A0  arm
 *   func_021BD138  0x021BD138  thumb  ov021
 *   func_021BD118  0x021BD118  thumb  ov021
 *   func_02013E4C  0x02013E4C  thumb
 *   func_021BC5BC  0x021BC5BC  thumb  ov021
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb
 *   func_0215841C  0x0215841C  thumb
 *   func_021583EC  0x021583EC  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201F158  0x0201F158  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_02045808  0x02045808  arm
 *   func_020458F8  0x020458F8  arm
 *   func_02012B38  0x02012B38  thumb
 *   func_02012B58  0x02012B58  thumb
 *   func_0201444C  0x0201444C  thumb
 *   func_02013D5C  0x02013D5C  thumb
 */
#include "../../matched/include/Obj01123.h"
#include "../../matched/include/Obj18195.h"
#include "../../matched/include/Obj18196.h"
#include "../../matched/include/Obj18197.h"
#include "../../matched/include/Obj18198.h"
#include "../../matched/include/Obj18199.h"
#include "../../matched/include/Obj18200.h"

struct Descriptor;
struct Bmp;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct Ctx;
struct BigObj;
struct Sub02014444Obj;
typedef struct {
    char pad[0x30];
    void *f30;
} Obj_021BC9AC;

typedef unsigned short u16;

typedef unsigned char u8;

typedef unsigned int   u32;

typedef struct {
    char pad[0x14A];
    u8 b14A;
} Obj_021BCA48;

typedef signed int     s32;

typedef struct {
    char pad[0x44];
    u16 h44;
    u16 h46;
} Obj_021BCA8C;

extern void func_02025588(void *a);
extern int func_021BD1DC(u8 *a0);
extern void *func_02045770(struct Descriptor *p);
extern int func_021BD1FC(int a);
extern int func_021BD204(int a);
extern int func_021BD1EC(u8 *a0);
extern int func_021BD1F4(u8 *a0);
extern void func_020439A0(struct Bmp *dst, struct Bmp *src, u32 x, u32 y, int sx, int sy, u32 w, u32 h, u32 key);
extern int func_021BD138(Obj_021BCA48 *p);
extern u32 func_02013E4C(u32 id);
extern u16 func_021BD118(u8 *p);
extern int func_021BC5BC(u8 *a);
extern unsigned int func_02012138(const struct Ctx *a);
extern int func_02158344(int a);
extern int func_0215841C(int a);
extern int func_021583EC(int a, int b);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201F158(struct WordSet *p, u32 i, u32 v);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02045808(struct U16Vec *vec);
extern u16 func_020458F8(struct U16Vec *vec);
extern void *func_02012B38(const struct BigObj *p);
extern u8 func_02012B58(const struct BigObj *p);
extern unsigned int func_0201444C(struct Sub02014444Obj *o);
extern u32 func_02013D5C(u32 id);
void func_021BC9AC(Obj_021BC9AC *p);
void func_021BC9C0(char *p);
void func_021BC9CC(char *p);
int func_021BCA48(Obj_021BCA48 *p);
void func_021BCA64(u8 *p);
u8 *func_021BCA6C(u8 *p);
u32 func_021BCA74(u8 *p);
void func_021BCA78(u8 *p);
void func_021BCA80(u8 *p);
u32 func_021BCA88(u8 *p);
int func_021BCA8C(Obj_021BCA8C *p);
void func_021BCAB0(int *p);
int func_021BCB48(int *p, int b);


void func_021BC9AC(Obj_021BC9AC *p)
{
    if (p->f30 != 0) {
        func_02025588(p->f30);
        p->f30 = 0;
    }
}

void func_021BC9C0(char *p)
{
    p[0x14a] = 0;
}


void func_021BC9CC(char *p)
{
    int r4;
    int a, b;
    u16 c, d, e, f;

    r4 = *(int *)(p + 0xc8 + 4 * ((struct Obj01123 *)p)->f14A);
    if (r4 != 0) {
        a = func_021BD1DC((u8 *)r4);
        b = (int)func_02045770((struct Descriptor *)*(int *)&((struct Obj01123 *)p)->f24);
        c = func_021BD1FC(r4);
        d = func_021BD204(r4) - 8;
        e = func_021BD1EC((u8 *)r4);
        f = func_021BD1F4((u8 *)r4);
        func_020439A0((struct Bmp *)a, (struct Bmp *)b, 0, 0, c, d, e, f, 0);
    }
    (((struct Obj01123 *)p)->f14A)++;
}


int func_021BCA48(Obj_021BCA48 *p)
{
    if (func_021BD138(p) <= p->b14A) {
        return 1;
    }
    return 0;
}


/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021BCA64(u8 *p)
{
    ((struct Obj18195 *)p)->f4C = 1;
}


u8 *func_021BCA6C(u8 *p)
{
    ((struct Obj18196 *)p)->f4C = 0;
    return p;
}


/*
 * Loads the 32-bit word at byte +0x48 of the object.
 */
u32 func_021BCA74(u8 *p)
{
    return ((struct Obj18197 *)p)->f48;
}


void func_021BCA78(u8 *p)
{
    ((struct Obj18198 *)p)->f48 = 1;
}


void func_021BCA80(u8 *p)
{
    ((struct Obj18199 *)p)->f48 = 0;
}


/*
 * Loads the 32-bit word at byte +0x4c of the object.
 */
u32 func_021BCA88(u8 *p)
{
    return ((struct Obj18200 *)p)->f4C;
}


int func_021BCA8C(Obj_021BCA8C *p)
{
    int a = func_02013E4C(p->h44);

    if (a != func_02013E4C(p->h46)) {
        return 1;
    }
    return 0;
}


void func_021BCAB0(int *p)
{
    int r6, r7;
    unsigned int r4;

    r6 = func_021BD118((u8 *)((int)p));
    r4 = func_02013E4C((unsigned int)r6);
    if (r4 >= 0x75) {
        r4 = 0;
    }
    if (r4 == 0) {
        func_021BC5BC((u8 *)p);
        return;
    }
    if (func_021BCB48((int *)((int)p), r6) != 0) {
        func_02158344((int)func_02012138((const struct Ctx *)p[0]));
        r7 = func_021583EC(p[1], func_0215841C(p[1]));
        r6 = (int)func_02045EC0((struct MsgBank *)p[5], 3);
        func_02045CAC((struct MsgBank *)p[5], r4, (void *)p[7]);
        func_0201F02C((struct WordSet *)p[2], 0, (void *)r7);
        func_0201F158((struct WordSet *)p[2], 1, r4);
        func_0201F250((struct WordSet *)p[2], (void *)p[7], (void *)r6);
        func_02045808((struct U16Vec *)r6);
    } else {
        func_02045CAC((struct MsgBank *)p[5], r4, (void *)p[7]);
    }
    *((unsigned char *)p + 0x20) = func_020458F8((struct U16Vec *)p[7]);
}


int func_021BCB48(int *p, int b)
{
    int r4, r6, t;

    r4 = func_02158344((int)func_02012138((const struct Ctx *)p[0]));
    t = (int)func_02012B38((const struct BigObj *)p[1]);
    r6 = func_02012B58((const struct BigObj *)p[1]);
    if (r4 != 0) {
        r4 = func_0215841C(p[1]);
        if (func_0201444C((struct Sub02014444Obj *)t) == 1) {
            return 1;
        }
        if (func_02013D5C(b) != 0 && r6 != r4) {
            return 1;
        }
    }
    return 0;
}
