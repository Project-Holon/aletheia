/*
 * file:     btl_net_p01.c
 * unit:     yes
 * function: func_021D3A20, func_021D3A40, func_021D3A7C, func_021D3A98, func_021D3AB4, func_021D3AD0, func_021D3AEC, func_021D3B08, func_021D3B28, func_021D3B5C, func_021D3B74, func_021D3B88, func_021D3B9C, func_021D3BB0, func_021D3BC0, func_021D3BE0, func_021D3C0C, func_021D3C2C, func_021D3C44, func_021D3C70, func_021D3C90, func_021D3CA8, func_021D3CC8, func_021D3CFC, func_021D3D1C, func_021D3D2C, func_021D3D50, func_021D3D70, func_021D3D7C, func_021D3D90, func_021D3D9C, func_021D3DC4, func_021D3E70, func_021D3EC8, func_021D3F04, func_021D3F48, func_021D3F4C, func_021D3F54, func_021D3F60, func_021D3F64, func_021D3F88
 * address:  0x021D3A20
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
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021D6730 0x021D6730 thumb ov093
 *   func_021D6744 0x021D6744 thumb ov093
 *   func_021D5FE4 0x021D5FE4 thumb ov093
 *   func_021D6008 0x021D6008 thumb ov093
 *   func_021D5FC0 0x021D5FC0 thumb ov093
 *   func_021D6440 0x021D6440 thumb ov093
 *   func_021D66D0 0x021D66D0 thumb ov093
 *   func_021D5B44 0x021D5B44 thumb ov093
 *   func_021D5734 0x021D5734 thumb ov093
 *   func_021D64F0   0x021D64F0  thumb
 *   func_021EF9F4 0x021EF9F4 thumb ov093
 *   func_021EFAD8 0x021EFAD8 thumb ov093
 *   func_021EFB34 0x021EFB34 thumb ov093
 *   func_021EFA94 0x021EFA94 thumb ov093
 *   func_021D69A0 0x021D69A0 thumb ov093
 *   func_021D65C8 0x021D65C8 thumb ov093
 *   func_021D6D5C 0x021D6D5C thumb ov093
 *   func_021D6D70   0x021D6D70  thumb
 *   func_021CD9F4 0x021CD9F4 thumb ov093
 *   func_021B9B10 0x021B9B10 thumb ov093
 *   func_021B9AEC 0x021B9AEC thumb ov093
 *   func_021B9D10 0x021B9D10 thumb ov093
 *   func_021D6738   0x021D6738  thumb
 *   func_021D6264 0x021D6264 thumb ov093
 *   func_021D6848 0x021D6848 thumb ov093
 *   func_021D6408 0x021D6408 thumb ov093
 *   func_021D6E88 0x021D6E88 thumb ov093
 *   func_021EFC78   0x021EFC78  thumb
 *   func_021D5970 0x021D5970 thumb ov093
 *   func_021D67D8 0x021D67D8 thumb ov093
 *   func_021EF9A8 0x021EF9A8 thumb ov093
 *   func_021B9F84 0x021B9F84 thumb ov093
 *   d_021EFF74  0x021EFF74  data  a1
 *   func_021B9B94  0x021B9B94  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021D805C  0x021D805C  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021D7B60  0x021D7B60  thumb  ov093
 *   d_021EFF94  0x021EFF94  data  ov093  a1
 *   func_021D5D14  0x021D5D14  thumb  ov093
 *   func_021D5F14  0x021D5F14  thumb  ov093
 *   d_021EFFA0 0x021EFFA0 data a1
 */
#include "../../matched/include/Obj18389.h"
#include "../../matched/include/Obj21193.h"
#include "../../matched/include/Obj21195.h"
#include "../../matched/include/Obj21197.h"
#include "../../matched/include/Obj13422.h"
#include "../../matched/include/Obj21198.h"
#include "../../matched/include/Obj18391.h"
#include "../../matched/include/Obj06231.h"
#include "../../matched/include/Obj13426.h"
#include "../../matched/include/Obj18393.h"
#include "../../matched/include/Obj21200.h"
#include "../../matched/include/Obj21201.h"
#include "../../matched/include/Obj21202.h"
#include "../../matched/include/Obj18395.h"
#include "../../matched/include/Obj21204.h"
#include "../../matched/include/Obj21205.h"
#include "../../matched/include/Obj18396.h"
#include "../../matched/include/Obj21206.h"
#include "../../matched/include/Obj21207.h"
#include "../../matched/include/Obj18397.h"
#include "../../matched/include/Obj13429.h"

struct UtilWork;
struct QK;
struct QJ;
struct QI;
struct S;
struct Work;
struct Arr;
struct UtilSlots;
struct Q1;
struct Unk021D62A8;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct { u32 v; } Slot;

struct Rec { u16 a, b; u8 c, d, e; };

struct HalfRec { u16 a, b, c, d; };

typedef struct {
    u8 a;
    u8 b;
} Pair_021D3E70;

typedef struct { u8 a,b; } Pair_021D3EC8;

typedef struct {
    u8 b0;
    u8 b1;
    u8 f0 : 1;
    u8 f1 : 1;
    u8 f2 : 1;
    u8 f3 : 1;
    u8 f4 : 1;
    u8 f5 : 1;
    u8 pad3;
    u16 h4;
    u16 h6;
    u16 h8;
    u16 h10;
    u16 h12;
} S_021D3F04;

typedef struct { u8 pad[2]; unsigned char f0:2; unsigned char flag:1; unsigned char rest:5; } Flags;

typedef struct {
    u8 b0;
    u8 b1;
    u8 f0 : 1;
    u8 f1 : 1;
    u8 f2 : 1;
    u8 pad3;
    u16 h4;
    u16 h6;
    u16 h8;
    u16 h10;
    u16 h12;
} S_021D3F64;

struct S_021D3F88 { u8 a,b; u8 bit:1; u8 rest:7; };

extern u8 *func_021B9934(char *p, int i);
extern void func_021D6730(struct QK *p, u16 v);
extern void func_021D6744(u8 *p, u8 a, int f, u8 b, u16 c, u16 d);
extern void func_021D5FE4(u8 *, u32);
extern void func_021D6008(u8 *, u32);
extern void func_021D5FC0(struct UtilWork *, u32);
extern void func_021D6440(u8 *, u32);
extern void func_021D66D0(struct QJ *p, u32 v);
extern void func_021D5B44(struct QI *p, u16 v);
extern void func_021D5734(u8 *p, u8 i, u16 a, u8 b, u32 c);
extern void func_021D64F0(void *p);
extern int func_021EF9F4(void *, u32, Slot, int);
extern int func_021EFAD8(char *a, u32 b, u32 c);
extern void func_021EFB34(struct S *, u8);
extern int func_021EFA94(void *, int);
extern void func_021D69A0(u8 *, int, u8);
extern void func_021D65C8(struct Work *, struct Work *);
extern void func_021D6D5C(u8 *, u16);
extern void func_021D6D70(unsigned char *p);
extern void func_021CD9F4(u8 *p, u8 n);
extern void func_021B9B10(u8 *, u8, int);
extern char *func_021B9AEC(char *, int);
extern void func_021B9D10(char *, struct Arr *, int);
extern void func_021D6738(u8 *p);
extern void func_021D6264(struct UtilSlots *p, int v);
extern void func_021D6848(u8 *p, struct Rec *r);
extern void func_021D6408(u8 *);
extern void func_021D6E88(u8 *);
extern void func_021D5970(u8 *, int, u16);
extern void func_021D67D8(u8 *p, u32 n);
extern u8 func_021EF9A8(u32 *);
extern u16 func_021B9F84(char *p, int i, unsigned int j);
extern u8 func_021B9B94(struct Q1 *p);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern u32 func_021D805C(void *p, u32 n);
extern int func_021D59B4(u8 *p, int k);
extern u32 func_021D7B60(void *p, u32 b);
extern int func_021D5D14(s8 *p, int i, int sign);
extern u8 func_021D5F14(struct UtilWork *p);
int func_021D3A20(u32 *a, int *b, u32 *c);
int func_021D3A40(u32 *a, int *b, const u32 *c);
int func_021D3A7C(u32 *a, int *b, u32 *c);
int func_021D3A98(u32 *a, int *b, u32 *c);
int func_021D3AB4(u32 *a, int *b, u32 *c);
int func_021D3AD0(u32 *a, int *b, u32 *c);
int func_021D3AEC(u32 *a, int *b, u32 *c);
int func_021D3B08(u32 *a, int *b, u32 *c);
int func_021D3B28(u32 *a, int *b, const u32 *c);
int func_021D3B5C(u8 *p, int b, u32 *q);
int func_021D3B74(u32 *a, int *b, u32 *c);
int func_021D3B88(u32 *a, int *b, u32 *c);
int func_021D3B9C(char *p, int unused, unsigned int *a);
int func_021D3BB0(char *p, int unused, unsigned int *a);
int func_021D3BC0(char *p, int unused, unsigned int *a);
int func_021D3BE0(char *p, int unused, unsigned int *a);
int func_021D3C0C(char *p, int unused, unsigned int *a);
int func_021D3C2C(u8 *p, int b, u32 *q);
int func_021D3C44(u8 *p, int unused, unsigned int *a);
int func_021D3C70(char *p, int unused, unsigned int *a);
int func_021D3C90(u8 *p, int b, u32 *q);
int func_021D3CA8(char *p, int unused, unsigned int *a);
int func_021D3CC8(char *p, int unused, const unsigned int *a);
int func_021D3CFC(char *p, int unused, unsigned int *a);
/* 021D3D1C 3-arg call on field 0x34, then returns 1 */ int func_021D3D1C(u8 *p);
int func_021D3D2C(char *p, int unused, unsigned int *a);
int func_021D3D50(char *p, int unused, unsigned int *a);
u8 func_021D3D70(u8 *p);
u32 func_021D3D7C(u8 *p);
u8 func_021D3D84(u8 *p);
u8 func_021D3D90(u8 *p);
void func_021D3D9C(u8 *p);
u32 func_021D3DC4(u8 *a, void *b, void *c);
int func_021D3E70(void *s, void *m);
int func_021D3EC8(void *s,struct Unk021D62A8 *m);
void func_021D3F04(S_021D3F04 *p);
void func_021D3F48(u8 *p, u32 v);
int func_021D3F4C(Flags *p);
void func_021D3F54(u8 *p);
u8 func_021D3F60(u8 *p);
void func_021D3F64(S_021D3F64 *p, u16 v);
void func_021D3F88(struct S_021D3F88 *p);
extern u8 d_021EFF74[];
extern Pair_021D3E70 d_021EFF94[];
extern Pair_021D3EC8 d_021EFFA0[];

int func_021D3A20(u32 *a, int *b, u32 *c)
{
    u8 *x;
    x = func_021B9934((char *)a[1], (u8)c[0]);
    func_021D6730((struct QK *)x, c[1]);
    return 1;
}

int func_021D3A40(u32 *a, int *b, const u32 *c)
{
    u8 *x;
    x = func_021B9934((char *)a[1], (u8)c[0]);
    func_021D6744(x, c[1], c[2], c[3], c[4], c[5]);
    return 1;
}

int func_021D3A7C(u32 *a, int *b, u32 *c)
{
    u8 *x;
    x = func_021B9934((char *)a[1], (u8)c[0]);
    func_021D5FE4(x, c[1]);
    return 1;
}

int func_021D3A98(u32 *a, int *b, u32 *c)
{
    u8 *x;
    x = func_021B9934((char *)a[1], (u8)c[0]);
    func_021D6008(x, c[1]);
    return 1;
}

int func_021D3AB4(u32 *a, int *b, u32 *c)
{
    u8 *x;
    x = func_021B9934((char *)a[1], (u8)c[0]);
    func_021D5FC0((struct UtilWork *)x, c[1]);
    return 1;
}

int func_021D3AD0(u32 *a, int *b, u32 *c)
{
    u8 *x;
    x = func_021B9934((char *)a[1], (u8)c[0]);
    func_021D6440(x, c[1]);
    return 1;
}

int func_021D3AEC(u32 *a, int *b, u32 *c)
{
    u8 *x;
    x = func_021B9934((char *)a[1], (u8)c[0]);
    func_021D66D0((struct QJ *)x, c[1]);
    return 1;
}

int func_021D3B08(u32 *a, int *b, u32 *c)
{
    u8 *x;
    x = func_021B9934((char *)a[1], (u8)c[0]);
    func_021D5B44((struct QI *)x, c[1]);
    return 1;
}

int func_021D3B28(u32 *a, int *b, const u32 *c)
{
    u8 *x;
    x = func_021B9934((char *)a[1], (u8)c[0]);
    func_021D5734(x, c[1], c[4], c[2], c[3]);
    return 1;
}


/*
 * Leaf with no calls and no pool; 9 instructions, 22 bytes: push {r3, lr}; ldr r1, [r2]; ldr r0, [r0, #4]; lsls r1, r1, #0x18; lsrs r1, r1, #0x18; bl func_021B9934; bl func_021D64F0; movs r0, #1; pop {r3, pc}.
 */
int func_021D3B5C(u8 *p, int b, u32 *q)
{
    func_021D64F0(func_021B9934(*(char * *)&((struct Obj18389 *)p)->f4, (u8)*q));
    return 1;
}

int func_021D3B74(u32 *a, int *b, u32 *c)
{
    Slot s;
    s.v = c[1];
    func_021EF9F4((void *)a[13], c[0], s, 0);
    return 1;
}

int func_021D3B88(u32 *a, int *b, u32 *c)
{
    func_021EFAD8((char *)a[13], c[0], (u8)c[1]);
    return 1;
}

/*
 * extent: trailing 2-byte alignment padding.
 * ABI: narrow extern arguments follow explicit caller truncation.
 */
int func_021D3B9C(char *p, int unused, unsigned int *a)
{
    func_021EFB34(*(struct S * *)&((struct Obj21193 *)p)->f34, a[0]);
    return 1;
}

/*
 * extent: compiled 14 bytes followed by 2-byte alignment padding.
 * ABI: narrow extern arguments follow explicit caller truncation.
 */
int func_021D3BB0(char *p, int unused, unsigned int *a)
{
    func_021EFA94(((struct Obj21195 *)p)->f34, a[0]);
    return 1;
}

/*
 * ABI: narrow extern arguments follow explicit caller truncation.
 */
int func_021D3BC0(char *p, int unused, unsigned int *a)
{
    u8 *obj = func_021B9934(*(char * *)&((struct Obj21197 *)p)->f4, (u8)a[0]);
    func_021D69A0(obj, a[1], a[2]);
    return 1;
}

int func_021D3BE0(char *p, int unused, unsigned int *a)
{
    u8 *first = func_021B9934(*(char * *)&((struct Obj13422 *)p)->f4, (u8)a[0]);
    u8 *second = func_021B9934(*(char * *)&((struct Obj13422 *)p)->f4, (u8)a[1]);
    func_021D65C8((struct Work *)second, (struct Work *)first);
    return 1;
}

int func_021D3C0C(char *p, int unused, unsigned int *a)
{
    u8 *obj = func_021B9934(*(char * *)&((struct Obj21198 *)p)->f4, (u8)a[0]);
    func_021D6D5C(obj, a[1]);
    return 1;
}


/*
 * Leaf with no calls and no pool; 9 instructions, 22 bytes: push {r3, lr}; ldr r1, [r2]; ldr r0, [r0, #4]; lsls r1, r1, #0x18; lsrs r1, r1, #0x18; bl func_021B9934; bl func_021D6D70; movs r0, #1; pop {r3, pc}.
 */
int func_021D3C2C(u8 *p, int b, u32 *q)
{
    func_021D6D70(func_021B9934(*(char * *)&((struct Obj18391 *)p)->f4, (u8)*q));
    return 1;
}

int func_021D3C44(u8 *p, int unused, unsigned int *a)
{
    u8 index = a[0];
    u8 value = a[1];
    if (index == p[0x1a6]) func_021CD9F4(p, value);
    else func_021B9B10(*(u8 * *)&((struct Obj06231 *)p)->f0, index, value);
    return 1;
}

int func_021D3C70(char *p, int unused, unsigned int *a)
{
    u8 index = a[0];
    struct Arr *obj = (struct Arr *)func_021B9AEC(*(char * *)&((struct Obj13426 *)p)->f4, index);
    func_021B9D10(*(char * *)&((struct Obj13426 *)p)->f0, obj, index);
    return 1;
}


/*
 * Leaf with no calls and no pool; 9 instructions, 22 bytes: push {r3, lr}; ldr r1, [r2]; ldr r0, [r0, #4]; lsls r1, r1, #0x18; lsrs r1, r1, #0x18; bl func_021B9934; bl func_021D6738; movs r0, #1; pop {r3, pc}.
 */
int func_021D3C90(u8 *p, int b, u32 *q)
{
    func_021D6738(func_021B9934(*(char * *)&((struct Obj18393 *)p)->f4, (u8)*q));
    return 1;
}

int func_021D3CA8(char *p, int unused, unsigned int *a)
{
    u8 *obj = func_021B9934(*(char * *)&((struct Obj21200 *)p)->f4, (u8)a[0]);
    func_021D6264((struct UtilSlots *)obj, (u8)a[1]);
    return 1;
}

/*
 * lever: const source pointer restores the five-load acquisition order.
 * ABI: narrow extern arguments follow explicit caller truncation.
 * Record byte 7 is uninitialized padding, preserved as in the listing.
 */
int func_021D3CC8(char *p, int unused, const unsigned int *a)
{
    struct Rec r;
    u8 *obj;
    u16 x, y;
    u8 z, w, v;
    obj = func_021B9934(*(char * *)&((struct Obj21201 *)p)->f4, (u8)a[0]);
    x = a[4]; y = a[5]; z = a[3]; w = a[2]; v = a[1];
    r.a = x; r.b = y; r.c = z; r.d = v; r.e = w;
    func_021D6848(obj, (struct Rec *)((struct HalfRec *)&r));
    return 1;
}

int func_021D3CFC(char *p, int unused, unsigned int *a)
{
    u8 *obj = func_021B9934(*(char * *)&((struct Obj21202 *)p)->f4, (u8)a[0]);
    func_021D6408(obj);
    func_021D6E88(obj);
    return 1;
}


/* 021D3D1C  3-arg call on field 0x34, then returns 1 */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, lr}; ldr r0, [r0, #0x34]; movs r1, #0; movs r2, #0; bl func_021EFC78; movs r0, #1; pop {r3, pc}.
 */
int func_021D3D1C(u8 *p)
{
    func_021EFC78(((struct Obj18395 *)p)->f34, 0, 0);
    return 1;
}

int func_021D3D2C(char *p, int unused, unsigned int *a)
{
    int index = a[1];
    u8 *obj = func_021B9934(*(char * *)&((struct Obj21204 *)p)->f4, (u8)a[0]);
    func_021D5970(obj, index, a[2]);
    return 1;
}

int func_021D3D50(char *p, int unused, unsigned int *a)
{
    u8 *obj = func_021B9934(*(char * *)&((struct Obj21205 *)p)->f4, (u8)a[0]);
    func_021D67D8(obj, (u16)a[1]);
    return 1;
}


/*
 * ldrb at #0x1a6 (pool constant)
 */
u8 func_021D3D70(u8 *p)
{
    return ((struct Obj18396 *)p)->f1A6;
}

/*
 * Claimed follower 021D3D84 is included; target byte accessor has a verified shard.
 */
u32 func_021D3D7C(u8 *p) { return ((struct Obj21206 *)p)->f118; }

u8 func_021D3D84(u8 *p) { return func_021EF9A8(*(u32 * *)&((struct Obj21207 *)p)->f34); }


/*
 * ldrb at #0x1ab (pool constant)
 */
u8 func_021D3D90(u8 *p)
{
    return ((struct Obj18397 *)p)->f1AB;
}

/*
 * Byte narrowing before call proves u8 third argument despite wide callee definition.
 */
void func_021D3D9C(u8 *p) {
    u32 i;
    for(i=0;i<4;i++) *(u16 *)(p+i*2+0xe8)=func_021B9F84(*(char * *)&((struct Obj13429 *)p)->f0,p[0x1a6],(u8)i);
}


u32 func_021D3DC4(u8 *a, void *b, void *c)
{
    u32 i;
    u32 r;
    u32 v;
    u32 lim;
    u32 off;
    u8 *t;

    lim = func_021B9B94(c);
    if (func_021D62C4(b, 0x13) != 0)
        return 0;
    for (i = 0; i < 4; i++) {
        if (d_021EFF74[i] < lim)
            break;
        off = i * 2;
        if (*(u16 *)(a + off + 0xe8) != 0) {
            r = 0;
            if (func_021D805C((void *)(u32)*(u16 *)(a + off + 0xe8), 0x29) != 0) {
                r = func_021D59B4(b, 0xd);
                if (r > func_021D7B60(b, 4))
                    continue;
                r = 1;
            } else {
                if (func_021D3E70((void *)(u32)*(u16 *)(a + off + 0xe8), b) != 0)
                    r = 1;
                else if (func_021D3EC8((void *)(u32)*(u16 *)(a + off + 0xe8), b) != 0)
                    r = 1;
            }
            if (r != 0) {
                t = a + 0xe8;
                v = *(u16 *)(t + off);
                *(u16 *)(t + off) = 0;
                return v;
            }
        }
    }
    return 0;
}


int func_021D3E70(void *s, void *m)
{
    u32 i;

    for (i = 0; i < 6; i++) {
        if (func_021D805C(s, d_021EFF94[i].a) != 0 && func_021D5D14(m, d_021EFF94[i].b, 1) != 0)
            return 1;
    }
    if (func_021D805C(s, 0x24) != 0 && func_021D5F14(m) == 0)
        return 1;
    return 0;
}

int func_021D3EC8(void *s,struct Unk021D62A8 *m) { u32 i; for(i=0;i<7;i++) if(func_021D805C(s,d_021EFFA0[i].a) && func_021D62C4(m,d_021EFFA0[i].b)) return 1; return 0; }


void func_021D3F04(S_021D3F04 *p)
{
    p->b1 = 0;
    p->f3 = 0;
    p->b0 = 0;
    p->f1 = 0;
    p->h6 = 0;
    p->f2 = 0;
    p->h8 = 0;
    p->f0 = 0;
    p->h10 = 0;
    p->f4 = 0;
    p->f5 = 0;
    p->h12 = 0;
    p->h4 = 0;
}


/*
 * strh v at #0xa
 */
void func_021D3F48(u8 *p, u32 v)
{
    *(u16 *)&p[0xa] = v;
}

int func_021D3F4C(Flags *p)
{
    return p->flag;
}

/*
 * Extent follower 021D3F60 is already filed separately.
 */
void func_021D3F54(u8 *p) { p[2] |= 8; }

/*
 * extent: Parent approved only the bounded four-byte accessor. Unapproved
 * followers 021D3F64 and 021D3F88, matched 021D3F98 and code 021D3FA8 follow;
 * no follower is included in this source.
 */
u8 func_021D3F60(u8 *p)
{
    return p[1];
}

/*
 * note 2026-10-05: object is the same 14-byte record as func_021D3F04 (bit flags in byte 2).
 *   Sets h8 = v, bit0 = 1, h12 = 0, clears bits 1 and 2. Source order h12 = 0 before h8 = v:
 *   the scheduler hoists the strh, and r1 (v) stays live so the zero takes r2.
 */
void func_021D3F64(S_021D3F64 *p, u16 v)
{
    p->f0 = 1;
    p->h12 = 0;
    p->h8 = v;
    p->f1 = 0;
    p->f2 = 0;
}

/*
 * Extent follower 021D3F98 is already filed separately; bitfield clear produces bics.
 */
void func_021D3F88(struct S_021D3F88 *p) { p->a=0; p->bit=0; }
