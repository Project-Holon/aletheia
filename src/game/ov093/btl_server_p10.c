/*
 * file:     btl_server_p10.c
 * unit:     yes
 * function: func_021BA238, func_021BA250, func_021BA2D4, func_021BA2E4, func_021BA534, func_021BA54C, func_021BA5C4, func_021BA5D0, func_021BA5D8, func_021BA618, func_021BA648, func_021BA670, func_021BA698, func_021BA6C0, func_021BA710, func_021BA73C, func_021BA7F8, func_021BA820, func_021BA82C, func_021BA878, func_021BA9C8, func_021BAA94, func_021BAACC, func_021BAB10, func_021BAB40, func_021BAB5C, func_021BAB9C, func_021BABDC, func_021BABEC, func_021BABF4
 * address:  0x021BA238
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
 *   func_021B92D4 0x021B92D4 thumb ov093
 *   func_021BB8BC 0x021BB8BC thumb ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021B9940  0x021B9940  thumb  ov093
 *   func_021D5844  0x021D5844  thumb  ov093
 *   func_021B8714  0x021B8714  thumb  ov093
 *   func_0201B7B4  0x0201B7B4  thumb
 *   func_021BB8DC 0x021BB8DC thumb ov093
 *   func_0201B818 0x0201B818 thumb
 *   func_0201AA18 0x0201AA18 thumb
 *   func_0201AB28 0x0201AB28 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_02017E40 0x02017E40 thumb
 *   func_0201AC2C 0x0201AC2C thumb
 *   func_021B97A0 0x021B97A0 thumb ov093
 *   func_021B985C 0x021B985C thumb ov093
 *   func_021BA020 0x021BA020 thumb ov093
 *   func_021D7F60 0x021D7F60 thumb ov093
 *   func_021D805C 0x021D805C thumb ov093
 *   func_021B9064 0x021B9064 thumb ov093
 *   func_021B969C 0x021B969C thumb ov093
 *   func_021B8B9C 0x021B8B9C thumb ov093
 *   func_021B9AEC 0x021B9AEC thumb ov093
 *   func_021B9B94 0x021B9B94 thumb ov093
 *   func_021B9BF0 0x021B9BF0 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_021D62A8 0x021D62A8 thumb ov093
 *   data_021EFCF0 0x021EFCF0 data ov093 a1
 *   _u32_div_f 0x0209C2B0 arm
 *   func_021B86B8 0x021B86B8 thumb ov093
 *   func_021D826C  0x021D826C  thumb  ov093
 *   func_021D8270  0x021D8270  thumb  ov093
 *   func_021CDDA0  0x021CDDA0  thumb  ov093
 *   func_021CDDCC 0x021CDDCC thumb ov093
 *   func_021B997C 0x021B997C thumb ov093
 *   func_021B90F8  0x021B90F8  thumb  ov093
 *   func_021CD924  0x021CD924  thumb  ov093
 *   func_02082D44  0x02082D44  arm
 *   func_021B6818  0x021B6818  thumb  ov093
 *   func_021D787C  0x021D787C  thumb  ov093
 *   func_021B68D8  0x021B68D8  thumb  ov093
 *   func_021B9424  0x021B9424  thumb  ov093
 *   func_021B9460  0x021B9460  thumb  ov093
 *   func_021CD984  0x021CD984  thumb  ov093
 *   func_021E9034  0x021E9034  thumb  ov093
 *   func_021E8E28  0x021E8E28  thumb  ov093
 *   func_021E8F20  0x021E8F20  thumb  ov093
 *   func_021CD95C  0x021CD95C  thumb  ov093
 *   func_021CD9B0 0x021CD9B0 thumb ov093
 *   func_021BB964  0x021BB964  thumb  ov093
 *   func_021C8138 0x021C8138 thumb ov093
 *   func_021C8140 0x021C8140 thumb ov093
 *   func_021C7CBC 0x021C7CBC thumb ov093
 *   func_021C7CC8 0x021C7CC8 thumb ov093
 *   func_021C7CD4 0x021C7CD4 thumb ov093
 *   func_021C7CDC 0x021C7CDC thumb ov093
 *   func_021C7CE8 0x021C7CE8 thumb ov093
 *   func_021B9B98 0x021B9B98 thumb ov093
 *   func_021D54B4 0x021D54B4 thumb ov093
 *   func_02030734 0x02030734 arm
 *   d_021F3A60 0x021F3A60 data a4
 *   func_020457B0 0x020457B0 arm
 *   func_021BB828 0x021BB828 thumb ov093
 *   func_021BB968 0x021BB968 thumb ov093
 *   func_021BC550 0x021BC550 thumb ov093
 *   func_021BAC04 0x021BAC04 thumb ov093
 *   func_021BB840 0x021BB840 thumb ov093
 *   func_021BB848 0x021BB848 thumb ov093
 *   func_021EEA58  0x021EEA58  thumb  ov093
 *   func_021BB7FC 0x021BB7FC thumb ov093
 *   func_021BB9D0 0x021BB9D0 thumb ov093
 *   func_02045808  0x02045808  arm
 *   func_020307B0  0x020307B0  arm
 *   func_021BBB48  0x021BBB48  thumb  ov093
 *   func_021EEAE0  0x021EEAE0  thumb  ov093
 *   func_021BB724  0x021BB724  thumb  ov093
 *   func_021BB798  0x021BB798  thumb  ov093
 *   func_021BACAC  0x021BACAC  thumb  ov093
 */
#include "../../matched/include/Obj07746.h"
#include "../../matched/include/Obj13284.h"
#include "../../matched/include/Obj13285.h"
#include "../../matched/include/Obj00324.h"
#include "../../matched/include/Obj21005.h"
#include "../../matched/include/Obj21009.h"
#include "../../matched/include/Obj21010.h"
#include "../../matched/include/Obj21012.h"
#include "../../matched/include/Obj21014.h"
#include "../../matched/include/Obj21015.h"
#include "../../matched/include/Obj18159.h"
#include "../../matched/include/Obj07748.h"
#include "../../matched/include/Obj21016.h"
#include "../../matched/include/Obj09944.h"
#include "../../matched/include/Obj21017.h"
#include "../../matched/include/Obj13286.h"
#include "../../matched/include/Obj13287.h"
#include "../../matched/include/Obj07743.h"
#include "../../matched/include/Obj21018.h"
#include "../../matched/include/Obj21019.h"
#include "../../matched/include/Obj02131.h"
#include "../../matched/include/Obj21020.h"
#include "../../matched/include/Obj21021.h"
#include "../../matched/include/Obj02132.h"
#include "../../matched/include/Obj01687.h"
#include "../../matched/include/Obj09945.h"
#include "../../matched/include/Obj01234.h"
#include "../../matched/include/Obj21023.h"
#include "../../matched/include/Obj13288.h"
#include "../../matched/include/Obj21024.h"
#include "../../matched/include/Obj21025.h"
#include "../../matched/include/Obj07749.h"
#include "../../matched/include/Obj13289.h"
#include "../../matched/include/Obj07750.h"
#include "../../matched/include/Obj21026.h"

struct Unk021D62A8;
struct Rec534;
struct Q1;
struct S2;
struct Flags;
struct T;
struct QA;
struct Scene;
struct Q5;
struct Q7;
struct Q6;
struct U16Vec;
struct Q4;
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

struct F {
    u8 b : 1;
};

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

/* 021BA5D0  movs r1,#0x11; lsls r1,#6; ldrh r0,[r0,r1] */
struct Q3 { u8 pad[0x440]; u16 v; };

struct T {
    int w[6];
};

struct Copy24 { int x[6]; };

typedef struct { unsigned int a, b; } Pair;

extern void func_021B92D4(char *, void *, int);
extern void func_021BB8BC(u8 *p, u32 *q);
extern u8 func_021D5440(u8 *p);
extern u8 *func_021B9940(char *, u8);
extern void *func_021D5844(void *);
extern char *func_021B8714(char **);
extern void func_0201B7B4(void *, int, u16, u16);
extern void func_021BB8DC(u8 *, u32 *);
extern void func_021B97A0(char *, char *, int);
extern int func_021B985C(char *, int);
extern unsigned short func_021BA020(char *p, int i);
extern int func_021D7F60(u32);
extern void func_0201B818(void *a0, int a1, int a2);
extern u32 func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void func_02017E40(void *p, u32 id, u32 v);
extern u32 func_021D805C(void *p, u32 n);
extern void func_0201AC2C(const struct Rec534 *src, struct Rec534 *dst);
extern u32 func_021B9064(u8 *p, int k, int x);
extern void func_021B969C(char *, char *, int, int);
extern int func_021B8B9C(u8 *, u8);
extern char *func_021B9AEC(char *, int);
extern u8 func_021B9B94(struct Q1 *p);
extern u32 func_021B9BF0(struct S2 *p, u32 i);
extern int func_021D59B4(u8 *p, int k);
extern int func_021D5B68(void *);
extern int func_021D62A8(struct Unk021D62A8 *p);
extern u32 _u32_div_f(u32, u32);
extern void *func_021B86B8(void ***);
extern u32 func_021D826C(u32 *p);
extern int func_021D8270(void *, int, unsigned int);
extern int func_021CDDA0(u8 *p);
extern u32 func_021CDDCC(struct Flags *p);
extern void func_02008494(void *src, void *dst);
extern int func_021B997C(u8 *p, unsigned int i);
extern int func_021B90F8(u8 *p);
extern u16 *func_021CD924(u8 *p, u32 *out);
extern void func_02082D44(void *, void *, int);
extern unsigned int func_021B6818(unsigned int *p);
extern void func_021D787C(void *);
extern void func_021B68D8(u8 *s, struct T *t);
extern void func_021B9424(char *p);
extern void func_021B9460(char *a, char *b, u8 c);
extern void func_021CD984(void *, int);
extern void func_021E9034(char *p);
extern void func_021E8E28(void *p);
extern struct Scene *func_021E8F20(void *a, void *b, u32 c, int d, u16 heap);
extern void func_021CD95C(struct QA *p, u32 v);
extern void func_021CD9B0(u8 *p);
u32 func_021BB964(struct Q5 *p);
extern u16 func_021C8138(struct Q7 *p);
extern unsigned char func_021C8140(char *p, int i);
extern u16 func_021C7CBC(u8 *p);
extern u16 func_021C7CC8(u8 *p);
extern u16 func_021C7CD4(struct Q6 *p);
extern u16 func_021C7CDC(u8 *p);
extern u16 func_021C7CE8(u8 *p);
extern u8 func_021B9B98(u8 *p);
extern u8 func_021D54B4(u8 *p);
extern void *func_02030734(unsigned int, unsigned int, int, const char *, u16);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_021BB828(u8 *p);
extern u8 *func_021BB968(void *a, void *b, void *c, void *d, int e, u16 heap);
extern u8 *func_021BC550(u8 *p);
extern int func_021BAC04(char *p, int *st);
extern void func_021BB840(struct Q4 *p, int a, int b, int c);
extern void func_021BB848(u8 *p, void *q, u8 v);
int func_021EEA58(int, int, int, int);
extern void func_021BB7FC(const u8 *p);
extern void func_021BB9D0(u8 *p);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_020307B0(void *p);
extern void func_021BBB48(u8 *p);
extern void func_021EEAE0(void *p);
extern void func_021BB724(u8 *p, int a, int b, int c);
extern int func_021BB798(unsigned char *p);
extern int func_021BACAC(u8 *p, int *s);
void func_021BA238(char *p, void *m);
void func_021BA250(char *p, u8 *a, int b);
void func_021BA2D4(u32 p, u32 *q);
void func_021BA2E4(char *p);
int func_021BA534(void ***p);
int func_021BA54C(char *p);
u16 func_021BA5C4(u8 *p);
u16 func_021BA5D0(struct Q3 *p);
int func_021BA5D8(char *p);
int func_021BA618(char *p);
void func_021BA648(char *p, u8 k, void *dst);
void func_021BA670(char *p, u8 k, void *dst);
void func_021BA698(u8 *p, int k);
void func_021BA6C0(char *p);
u8 func_021BA710(int a, int b);
void func_021BA73C(char *p, int x);
void func_021BA7F8(char *p);
u32 func_021BA820(int *p);
void func_021BA82C(char *p);
void func_021BA878(u8 *p);
u8 *func_021BA9C8(void *a, struct Copy24 *b, void *c, int d, u16 heap);
void func_021BAA94(char *p, int b, u8 c, u8 d);
void func_021BAACC(char *p, int a, int b, int c, u8 d);
void func_021BAB10(char *p, u8 c, u8 d);
void func_021BAB40(char *p);
void func_021BAB5C(int a);
int func_021BAB9C(int a);
void func_021BABDC(char *p, Pair *out);
void func_021BABEC(int *p, void *f);
void func_021BABF4(void *p);
extern const u8 data_021EFCF0[];
extern u8 d_021F3A60[];

void func_021BA238(char *p, void *m)
{
    func_021B92D4(p, m, 0);
    func_021BB8BC(((struct Obj07746 *)p)->f8, m);
}


void func_021BA250(char *p, u8 *a, int b)
{
    u8 i;
    void *x;
    void *y;
    void *xv;
    void *yv;
    char *q;

    i = func_021D5440(a);
    x = func_021B9940(p + 0x1b0, i);
    y = func_021B9940(p + 0xc8, i);
    xv = func_021D5844(x);
    yv = func_021D5844(y);
    q = func_021B8714((char **)p);
    func_0201B7B4(xv, b, ((struct Obj13285 *)q)->fA, (((struct Obj13284 *)p)->f468 & 0x7fff) | 0x8000);
    func_0201B7B4(yv, b, ((struct Obj13285 *)q)->fA, (((struct Obj13284 *)p)->f468 & 0x7fff) | 0x8000);
}

void func_021BA2D4(u32 p, u32 *q) {
    u8 *v = *(u8 **)(p + 8);
    if (v) func_021BB8DC(v, q);
}

void func_021BA2E4(char *p)
{
    void *list;
    u32 n, move, k0, i0, k, slot;
    char *group;
    u32 count, total, maximum, i, base, j, obj;
    void *old, *mon;
    u8 *m;
    u32 tmp, tmp1, tmp2;
    if (((struct Obj21005 *)(*(char * *)&((struct Obj00324 *)p)->f0))->f23 != 0) return;
    if (*(u32 *)*(char * *)&((struct Obj00324 *)p)->f0 <= 1) {
        func_021B97A0(p + 0x1b0, p, (u8)p[0x46c]);
        list = (void *)func_021B985C(p + 0x1b0, (u8)p[0x46c]);
        if (*(u32 *)*(char * *)&((struct Obj00324 *)p)->f0 == 1 && func_021D7F60((u16)(u32)func_021BA020(p, 1)))
            func_0201B818(list, *(u16 *)(func_021B8714((char **)p) + 10), (u16)((((struct Obj00324 *)p)->f468 & 0x7fff) | 0x8000));
        if (*(u32 *)*(char * *)&((struct Obj00324 *)p)->f0 == 1) {
            n = func_0201AA18(list);
            for (i0 = 0; i0 < n; i0++) {
                old = func_0201AB28(((struct Obj21009 *)(*(char * *)&((struct Obj00324 *)p)->f0))->f24, i0);
                mon = func_0201AB28(list, i0);
                move = (u16)func_02017E1C(old, 6, 0);
                if (!func_021D805C((void *)move, 0x10))
                    func_02017E40(mon, 6, move);
                else if (move != func_02017E1C(mon, 6, 0))
                    func_02017E40(mon, 6, 0);
            }
        }
        func_0201AC2C(list, ((struct Obj21010 *)(*(char * *)&((struct Obj00324 *)p)->f0))->f24);
        for (i0 = 0; i0 < (u32)func_0201AA18(list); i0++) func_0201AB28(list, i0);
    }
    if (*(u32 *)*(char * *)&((struct Obj00324 *)p)->f0 == 0) {
        k0 = (u8)func_021B9064((u8 *)p, (u8)p[0x46c], 0);
        func_021B969C(p + 0x1b0, p, k0, 1);
        func_0201AC2C((void *)func_021B985C(p + 0x1b0, k0), ((struct Obj21012 *)(*(char * *)&((struct Obj00324 *)p)->f0))->f28);
    }
    if (*(u32 *)*(char * *)&((struct Obj00324 *)p)->f0 == 4) return;
    for (k = 0; k < 4; k++) {
        slot = func_021BA710((u8)p[0x46c], (u8)k);
        for (j = 0; j < 6; j++) { obj = *(u32 *)&((struct Obj00324 *)p)->f0; tmp1 = slot * 6; *(u8 *)(j + (tmp1 + obj) + 0xc8) = 0; }
        if (func_021B8B9C((u8 *)p, (u8)slot)) {
            group = func_021B9AEC(p + 0xc8, slot);
            count = func_021B9B94((struct Q1 *)group);
            total = maximum = 0;
            base = data_021EFCF0[slot];
            for (j = 0; j < count; j++) {
                m = (u8 *)func_021B9BF0((struct S2 *)group, (u8)j);
                i = (u8)(func_021D5440(m) - base);
                total += func_021D59B4(m, 13);
                maximum += func_021D59B4(m, 14);
                if (func_021D5B68(m)) { obj = *(u32 *)&((struct Obj00324 *)p)->f0; tmp = slot * 6; *(u8 *)(i + (tmp + *(u32 *)&((struct Obj00324 *)p)->f0) + 0xc8) = 2; }
                else if (func_021D62A8((struct Unk021D62A8 *)m)) { obj = *(u32 *)&((struct Obj00324 *)p)->f0; tmp2 = slot * 6; *(u8 *)(i + (tmp2 + obj) + 0xc8) = 1; }
            }
            *(u32 *)(*(char * *)&((struct Obj00324 *)p)->f0 + slot * 4 + 0xe0) = _u32_div_f(total * 100, maximum);
        }
    }
}

int func_021BA534(void ***p)
{
    int v = (int)func_021B86B8(p);
    switch (v) {
    case 2:
    case 3: return 1;
    default: return 0;
    }
}


int func_021BA54C(char *p)
{
    int v;

    if ((int)func_021B86B8((void ***)p) == 4) {
        v = 1;
    } else if (((struct F *)(p + 0x473))->b) {
        v = 6;
    } else if (((struct Obj21014 *)(*(char * *)&((struct Obj00324 *)p)->f0))->f90 != 6) {
        v = 5;
    } else if (func_021D826C((u32 *)(p + 0x448))) {
        v = func_021D8270(p + 0x448, *(u8 *)&((struct Obj00324 *)p)->f46C, (unsigned int)func_021B86B8((void ***)p));
    } else {
        if (((struct Obj00324 *)p)->f444 == 7) {
            ((struct Obj00324 *)p)->f444 = 1;
        }
        v = ((struct Obj00324 *)p)->f444;
    }
    ((struct Obj21015 *)(*(char * *)&((struct Obj00324 *)p)->f0))->f8C = v;
    return v;
}


u16 func_021BA5C4(u8 *p)
{
    return ((struct Obj18159 *)p)->f442;
}

/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: movs r1, #0x11; lsls r1, r1, #6; ldrh r0, [r0, r1]; bx lr.
 */
u16 func_021BA5D0(struct Q3 *p) { return p->v; }


int func_021BA5D8(char *p)
{
    int *q = *(int * *)&((struct Obj07748 *)p)->f0;
    if (((struct Obj21016 *)q)->f23 == 0) {
        if (((struct Obj07748 *)p)->f440 != 0)
            return func_021CDDA0((u8 *)(*(int *)(p + (((struct Obj07748 *)p)->f46C << 2) + 0x10)));
        return 0;
    }
    return func_021CDDA0((u8 *)(*(int *)(p + (((struct Obj07748 *)p)->f46C << 2) + 0x10)));
}

int func_021BA618(char *p)
{
    int v;
    if (((struct Obj21017 *)(*(char * *)&((struct Obj09944 *)p)->f0))->f23) {
        v = func_021CDDCC(*(void **)(p + 0x10 + ((struct Obj09944 *)p)->f46C * 4));
        if (v) ((struct Obj09944 *)p)->f444 = 2;
        return v;
    }
    return 0;
}

void func_021BA648(char *p, u8 k, void *dst)
{
 int i;
 void *q;
 i = func_021BA710(((struct Obj13286 *)p)->f46C, k);
 q = *(void **)(*(char * *)&((struct Obj13286 *)p)->f0 + i * 4 + 0x24);
 if (q != 0) func_0201AC2C(dst, q);
}

void func_021BA670(char *p, u8 k, void *dst)
{
 int i;
 void *q;
 i = func_021BA710(((struct Obj13287 *)p)->f46C, k);
 q = *(void **)(*(char * *)&((struct Obj13287 *)p)->f0 + i * 4 + 0x34);
 if (q != 0) func_02008494((void *)dst, q);
}

void func_021BA698(u8 *p, int k)
{
 int i;
 i = func_021BA710(p[0x46c], k);
 *((u8 *)(*(char * *)&((struct Obj07743 *)p)->f0 + i) + 0x44) = func_021B997C(p, k);
}


void func_021BA6C0(char *p)
{
    int n;
    void *src;

    if (func_021B90F8((u8 *)p)) {
        src = func_021CD924(*(void **)(p + (u8)p[0x46c] * 4 + 0x10), (u32 *)(&n));
        if (src) {
            func_02082D44(src, ((struct Obj21018 *)(*(char * *)&((struct Obj00324 *)p)->f0))->f94, n);
            ((struct Obj21019 *)(*(char * *)&((struct Obj00324 *)p)->f0))->f98 = n;
            *(struct T *)(*(char * *)&((struct Obj00324 *)p)->f0 + 0x9c) = *(struct T *)(p + 0x3f0);
        }
    }
}

u8 func_021BA710(int a, int b)
{
 u8 x;
 u8 y;
 if (a == b) return 0;
 x = a & 1;
 y = b & 1;
 if (x == y) return 2;
 return b <= 1U ? 1 : 3;
}


/*
 * func_021CD95C takes two arguments (its own file: `p->v = v`), and the
 * value passed second is the func_021E8F20 result just stored at p + 4:
 * that is the `adds r1, r0, #0` the one-argument prototype could not
 * produce (twin: ov093_func_021B835C).
 */
void func_021BA73C(char *p, int x)
{
    unsigned int i;
    int t;

    t = func_021B6818((unsigned int *)(*(int * *)&((struct Obj02131 *)p)->f0));
    func_021D787C(p + 0x3f0);
    func_021B68D8((u8 *)p, ((struct Obj02131 *)p)->f0);
    func_021B9424(p + 0xc8);
    func_021B9424(p + 0x1b0);
    for (i = 0; i < 4; i++) {
        if (func_021B8B9C((unsigned char *)p, i)) {
            func_021B9460(p + 0x1b0, p, i);
            func_021B9460(p + 0xc8, p, i);
            func_021CD984(*(void **)(p + i * 4 + 0x10), x);
        }
    }
    func_021E9034((char *)(((struct Obj02131 *)p)->f4));
    func_021E8E28((void *)0x13);
    ((struct Obj02131 *)p)->f4 = (int)func_021E8F20(p, *(void **)(p + (((struct Obj21020 *)(*(char * *)&((struct Obj02131 *)p)->f0))->f21) * 4 + 0x10), (u32)(p + 0xc8), t, 0x13);
    func_021CD95C(*(void **)(p + (((struct Obj21021 *)(*(char * *)&((struct Obj02131 *)p)->f0))->f21) * 4 + 0x10), ((struct Obj02131 *)p)->f4);
    func_021BAB40((char *)(((struct Obj02131 *)p)->f8));
}

void func_021BA7F8(char *p)
{
 unsigned int i;
 for (i = 0; i < 4; i++) {
  if (func_021B8B9C((unsigned char *)p, i)) func_021CD9B0(*(void **)(p + i * 4 + 0x10));
 }
}


u32 func_021BA820(int *p)
{
    return func_021BB964((struct Q5 *)p[2]);
}


void func_021BA82C(char *p)
{
    p[0xb6] = 0;
    p[0xb7] = 0;
    p[0xb8] = 0;
    p[0xb9] = 0;
    p[0xba] = 0;
    p[0xbb] = 0;
    p[0xbc] = 0;
    p[0xbd] = 0;
    p[0xbe] = 0;
    p[0xbf] = 0;
    p[0xc0] = 0;
    ((struct Obj02132 *)p)->fB4 = 0;
}


void func_021BA878(u8 *p)
{
    u8 *q;
    u8 *a;
    char *list;
    u32 n;
    u32 count;
    u32 i;
    void *item;
    if (((struct Obj09945 *)p)->f8 == 0)
        return;
    a = (u8 *)func_021BB964(((struct Obj09945 *)p)->f8);
    q = *(u8 * *)&((struct Obj09945 *)p)->f0;
    q[0xb6] = func_021C8138((struct Q7 *)a);
    q[0xb7] = func_021C8140((char *)a, 0);
    q[0xb8] = func_021C7CBC(a);
    q[0xb9] = func_021C7CC8(a);
    q[0xba] = func_021C7CD4((struct Q6 *)a);
    q[0xbb] = func_021C7CDC(a);
    q[0xbc] = func_021C7CE8(a);
    if (((struct Obj01687 *)q)->f8C == 1)
        q[0xbd] = 1;
    list = func_021B9AEC((char *)p + 0x1b0, 0);
    n = func_021B9B94((struct Q1 *)list);
    count = func_021B9B98((u8 *)list);
    for (i = 0; i < n; i++) {
        item = (void *)func_021B9BF0((struct S2 *)list, (u8)i);
        q[0xc0] += func_021D54B4(item);
        ((struct Obj01687 *)q)->fB4 += (u16)func_021D59B4(item, 13);
    }
    q[0xbf] = n - count;
    list = func_021B9AEC((char *)p + 0x1b0, 1);
    n = func_021B9B94((struct Q1 *)list);
    count = func_021B9B98((u8 *)list);
    q[0xbe] = n - count;
    if (func_021B8B9C(p, 3)) {
        list = func_021B9AEC((char *)p + 0x1b0, 3);
        if (list) {
            n = func_021B9B94((struct Q1 *)list);
            count = func_021B9B98((u8 *)list);
            q[0xbe] += (u8)(n - count);
        }
    }
}


u8 *func_021BA9C8(void *a, struct Copy24 *b, void *c, int d, u16 heap)
{
    u8 *p;
    int i;
    p = func_02030734(heap, 0xcc4, 1, (const char *)d_021F3A60, 0xad);
    ((struct Obj01234 *)p)->fC = a;
    ((struct Obj01234 *)p)->f10 = c;
    ((struct Obj01234 *)p)->fCC0 = heap;
    ((struct Obj01234 *)p)->fCB0 = p + 0xf0;
    p[0xed] = 0;
    *(int *)&((struct Obj01234 *)p)->f44 = 0;
    p[0xcba] = 0;
    p[0xcbf] = 0;
    ((struct Obj01234 *)p)->f4C = d;
    *(struct Copy24 *)(p + 0x50) = *b;
    ((struct Obj01234 *)p)->fAC = (int)func_020457B0((int)0x20, (int)heap);
    func_021D787C(b);
    for (i = 0; i < 4; i++)
        func_021BB828(p + 0x14 + i * 12);
    *(u8 * *)&((struct Obj01234 *)p)->f44 = func_021BB968(p, ((struct Obj01234 *)p)->fC, ((struct Obj01234 *)p)->f10, p + 0xf0, ((struct Obj01234 *)p)->f4C, ((struct Obj01234 *)p)->fCC0);
    ((struct Obj01234 *)p)->fB0 = func_021BC550(*(u8 * *)&((struct Obj01234 *)p)->f44);
    func_021BABEC((int *)p, (void *)func_021BAC04);
    return p;
}

void func_021BAA94(char *p, int b, u8 c, u8 d)
{
 char *x;
 unsigned int q;
 unsigned int off;
 x = func_021B9AEC(*(char * *)&((struct Obj21023 *)p)->f10, c);
 q = (unsigned int)p + 0x14U;
 off = (unsigned int)c * 12U;
 func_021BB840((struct Q4 *)(q + off), c, b, 1);
 func_021BB848((u8 *)(q + off), x, d);
}


void func_021BAACC(char *p, int a, int b, int c, u8 d)
{
    char *x;
    int y;
    char *q;
    int off;

    x = func_021B9AEC(*(char * *)&((struct Obj13288 *)p)->f10, c);
    y = func_021EEA58(b, c, 1, ((struct Obj13288 *)p)->fCC0);
    q = p + 0x14;
    off = c * 12;
    func_021BB840((struct Q4 *)(q + off), c, y, 0);
    func_021BB848((u8 *)(q + off), x, d);
}

void func_021BAB10(char *p, u8 c, u8 d)
{
 char *x;
 unsigned int q;
 unsigned int off;
 x = func_021B9AEC(*(char * *)&((struct Obj21024 *)p)->f10, c);
 q = (unsigned int)p + 0x14U;
 off = (unsigned int)c * 12U;
 func_021BB840((struct Q4 *)(q + off), c, 0, 0);
 func_021BB848((u8 *)(q + off), x, d);
}

void func_021BAB40(char *p)
{
 func_021BABEC((int *)p, (void *)func_021BAC04);
 func_021BB7FC((const u8 *)p);
 func_021BB9D0(((struct Obj21025 *)p)->f44);
}


void func_021BAB5C(int a)
{
    int i;
    char *p = (char *)a;
    func_02045808((struct U16Vec *)(((struct Obj13289 *)p)->fAC));
    func_021BBB48((u8 *)(((struct Obj13289 *)p)->f44));
    for (i = 0; i < 4; i++) {
        unsigned char *e = (unsigned char *)p + i * 0xc;
        if (e[0x1f] != 0xff && ((struct Obj07749 *)e)->f14 != 0 && e[0x1e] == 0)
            func_021EEAE0((void *)(((struct Obj07749 *)e)->f14));
    }
    func_020307B0((void *)a);
}


int func_021BAB9C(int a)
{
    char *p = (char *)a;
    if (((struct Obj07750 *)p)->fED != 2) {
        int (*fp)(int, int) = *(int (**)(int, int))p;
        if (fp(a, a + 4) != 0) {
            func_021BB724((u8 *)a, 9, ((struct Obj07750 *)p)->fB0, 8);
            ((struct Obj07750 *)p)->fED = 2;
        }
    } else {
        if (func_021BB798((unsigned char *)p) != 0)
            return 1;
    }
    return 0;
}

void func_021BABDC(char *p, Pair *out)
{
 *out = **(Pair * *)&((struct Obj21026 *)p)->fB0;
}

void func_021BABEC(int *p, void *f)
{
 p[0] = (int)f;
 p[1] = 0;
}


void func_021BABF4(void *p)
{
    func_021BABEC(p, (void *)func_021BACAC);
}
