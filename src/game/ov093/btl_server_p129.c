/*
 * file:     btl_server_p129.c
 * unit:     yes
 * function: func_021CD6F0, func_021CD8E0, func_021CD914, func_021CD924, func_021CD938, func_021CD95C, func_021CD960, func_021CD978, func_021CD97C, func_021CD984, func_021CD9B0, func_021CD9C8, func_021CD9DC, func_021CD9E0, func_021CD9F4
 * address:  0x021CD6F0
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
 *   func_02030734 0x02030734 arm
 *   d_021F3A88 0x021F3A88 data a4
 *   func_021EEA58 0x021EEA58 thumb ov093
 *   func_021B9AF8 0x021B9AF8 thumb ov093
 *   func_021CDA18 0x021CDA18 thumb ov093
 *   func_021BA08C 0x021BA08C thumb ov093
 *   func_021D8230 0x021D8230 thumb ov093
 *   func_021D3F04 0x021D3F04 thumb ov093
 *   func_021D3D9C 0x021D3D9C thumb ov093
 *   func_021B9FBC 0x021B9FBC thumb ov093
 *   func_021BA820 0x021BA820 thumb ov093
 *   func_02187F00 0x02187F00 thumb ov096
 *   func_021B90F8 0x021B90F8 thumb ov093
 *   func_021EE5E4 0x021EE5E4 thumb ov093
 *   func_021EE600 0x021EE600 thumb ov093
 *   func_02188080 0x02188080 thumb ov096
 *   func_020307B0 0x020307B0 arm
 *   func_021EEAE0 0x021EEAE0 thumb ov093
 *   func_021EE63C 0x021EE63C thumb ov093
 *   func_021EE830 0x021EE830 thumb ov093
 *   func_021D3F48 0x021D3F48 thumb ov093
 *   func_021EE674 0x021EE674 thumb ov093
 *   func_021EEBDC 0x021EEBDC thumb ov093
 *   func_021D3F64 0x021D3F64 thumb ov093
 *   func_021CDA0C 0x021CDA0C thumb ov093
 *   func_021CDC0C 0x021CDC0C thumb ov093
 *   func_021D3F88 0x021D3F88 thumb ov093
 */
#include "../../matched/include/Obj05197.h"
#include "../../matched/include/Obj13352.h"
#include "../../matched/include/Obj13353.h"
#include "../../matched/include/Obj07767.h"
#include "../../matched/include/Obj18365.h"
#include "../../matched/include/Obj18367.h"

struct Q2;
struct QE;
struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u8 f0:1,f1:1,f2:1,f3:1,f4:1,f5:1,rest:2; } Flags;

struct Copy24 { int x[6]; };

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

/* 021CD95C  str r1,[r0,#0x54] */
struct QA { u8 pad[0x54]; u32 v; };

/* 021CD978  ldr r0,[r0,#0x50] */
struct QB { u8 pad[0x50]; u32 v; };

/* 021CD97C  push {r3,lr}; ldr r1,[r0,#0x28]; blx r1; pop {r3,pc} */
struct R2 { u8 pad[0x28]; void (*fn)(struct R2 *); };

/* 021CD9DC  ldrh r0,[r0,#0x22] */
struct QD { u8 pad[0x22]; u16 v; };

extern void *func_02030734(u16, u32, int, const char *, u16);
extern void *func_021EEA58(u32, int, u32, u32);
extern char *func_021B9AF8(char *, int);
extern int func_021CDA18(u8 *);
extern u32 func_021BA08C(struct Q2 *p);
extern void func_021D8230(u8 *);
extern void func_021D3F04(u8 *);
extern void func_021D3D9C(u8 *);
extern int func_021B9FBC(char *, int);
extern u32 func_021BA820(int *);
extern void *func_02187F00(void **, u32, u32, u32, u16);
extern int func_021B90F8(u8 *);
extern void *func_021EE5E4(u32);
extern void func_021EE600(void *);
extern void func_02188080(void *);
extern u32 func_020307B0(void *p);
extern void func_021EEAE0(void *);
extern u16 *func_021EE63C(u16 *, u32 *);
extern u32 func_021EE830(void *);
extern void func_021D3F48(u8 *,u32);
extern void func_021EE674(void *);
extern void func_021EEBDC(void *);
extern void func_021D3F64(u8 *,u16);
extern void func_021CDA0C(struct QE *p, u32 v);
extern int func_021CDC0C(u8 *);
extern void func_021D3F88(struct S *p);
u8 *func_021CD6F0(u8 *a, u8 *b, int c, int d, u16 idx, u16 kind, u8 e, int f, int g, struct Copy24 *h, u16 heap);
void func_021CD8E0(u8 *p);
void func_021CD914(u8 *p);
u16 *func_021CD924(u8 *p, u32 *out);
void func_021CD938(u8 *p,void *a);
void func_021CD95C(struct QA *p, u32 v);
void func_021CD960(u8 *p, u32 v);
u32 func_021CD978(struct QB *p);
void func_021CD97C(struct R2 *p);
void func_021CD984(u8 *p,u16 n);
void func_021CD9B0(u8 *p);
/* 021CD9C8 byte field 0x1a7 == 2 */ u32 func_021CD9C8(u8 *p);
u16 func_021CD9DC(struct QD *p);
/* 021CD9E0 function-pointer slot 0x28 compared with 0x021CDC0D */ u32 func_021CD9E0(u8 *p);
void func_021CD9F4(u8 *p,u8 n);
extern u8 d_021F3A88[];


u8 *func_021CD6F0(u8 *a, u8 *b, int c, int d, u16 idx, u16 kind, u8 e, int f, int g, struct Copy24 *h, u16 heap)
{
    u8 *p;
    u32 i;
    int flag, k;
    p = func_02030734(heap, 0x1b8, 1, (const char *)d_021F3A88, 0x209);
    flag = 1;
    if (c == 0 || e != 0)
        flag = 0;
    p[0x1a6] = idx;
    *(u16 *)(p + 0x19a) = heap;
    p[0x1a7] = e;
    *(void **)(p + 0x50) = func_021EEA58(d, (u8)idx, flag, heap);
    *(char **)(p + 0x118) = func_021B9AF8((char *)b, idx);
    *(u8 **)p = a;
    *(u8 **)(p + 4) = b;
    p[0x11c] = kind;
    p[0x11d] = 0;
    p[0x121] = idx;
    p[0xc4] = 0;
    *(int *)(p + 0x54) = 0;
    *(u16 *)(p + 0x19c) = 0;
    *(void **)(p + 0x134) = func_02030734(heap, 0xbc0, 1, (const char *)d_021F3A88, 0x21a);
    *(void **)(p + 0x28) = (void *)func_021CDA18;
    p[0x1a8] = 0;
    *(int *)(p + 0xa0) = 0;
    ((Flags *)(p + 0x1b2))->f3 = 0;
    p[0x1ae] = 0;
    p[0x1a9] = 0;
    p[0x1ab] = 0;
    *(u16 *)(p + 0xe4) = 0;
    *(u16 *)(p + 0xe6) = 0;
    p[0x1ad] = 0;
    ((Flags *)(p + 0x1b2))->f0 = 0;
    ((Flags *)(p + 0x1b2))->f1 = 0;
    ((Flags *)(p + 0x1b2))->f4 = 0;
    ((Flags *)(p + 0x1b2))->f5 = 0;
    *(u32 *)(p + 0x34) = func_021BA08C((struct Q2 *)a);
    p[0x1aa] = f;
    func_021D8230(p + 0x2c);
    func_021D3F04(p + 0x18);
    func_021D3D9C(p);
    *(struct Copy24 *)(p + 0xf4) = *h;
    if (p[0x1a7] == 1 && g == 0) {
        k = func_021B9FBC(*(char **)p, p[0x1a6]);
        *(void **)(p + 0xf0) = func_02187F00(*(void ***)p, func_021BA820(*(int **)p), *(u32 *)(p + 4), k, *(u16 *)(p + 0x19a));
    } else {
        *(int *)(p + 0xf0) = 0;
    }
    for (i = 0; i < 4; i++)
        p[0x112 + i] = 0;
    if (p[0x1a7] == 0 && func_021B90F8(*(u8 **)p))
        *(void **)(p + 0x10) = func_021EE5E4(heap);
    else
        *(void **)(p + 0x10) = 0;
    return p;
}

void func_021CD8E0(u8 *p) {
 if(*(void* *)&((struct Obj05197 *)p)->f10)func_021EE600(*(void* *)&((struct Obj05197 *)p)->f10);
 if(*(void* *)&((struct Obj05197 *)p)->fF0)func_02188080(*(void* *)&((struct Obj05197 *)p)->fF0);
 func_020307B0(*(void* *)&((struct Obj05197 *)p)->f134);
 func_021EEAE0(*(void* *)&((struct Obj05197 *)p)->f50);
 func_020307B0(p);
}

void func_021CD914(u8 *p) {p[0x1b2]|=2;}

u16 *func_021CD924(u8 *p, u32 *out) { if (*(u16 * *)&((struct Obj13352 *)p)->f10) return func_021EE63C(*(u16 * *)&((struct Obj13352 *)p)->f10,out); return 0; }

/*
 * Prototype: 021D3F48 stores only r1 low16; caller forwards full getter
 * result without truncation, so its extern argument is widened to u32.
 */
void func_021CD938(u8 *p,void *a) { p[0x1a7]=2; ((struct Obj13353 *)p)->f14=a; func_021D3F48(p+0x18,func_021EE830(a)); }

/*
 * Stores the second argument (a u32) into the field at #0x54.
 */
void func_021CD95C(struct QA *p, u32 v) { p->v = v; }


void func_021CD960(u8 *p, u32 v) {
    *(u32 *)(p + 0xA0) = v;
    p[0x1B2] |= 8;
}

/*
 * Reads the u32 field at #0x50 of the argument and returns it.
 */
u32 func_021CD978(struct QB *p) { return p->v; }

/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: push {r3, lr}; ldr r1, [r0, #0x28]; blx r1; pop {r3, pc}.
 */
void func_021CD97C(struct R2 *p) { p->fn(p); }

/*
 * Prototype: 021CDA0C stores its r1 payload unchanged at +0x28; caller
 * passes a callback address. Pointer replaces legacy u32 for that payload.
 */
void func_021CD984(u8 *p,u16 n) { func_021EE674(((struct Obj07767 *)p)->f14); func_021EEBDC(((struct Obj07767 *)p)->f50); func_021D3F64(p+0x18,n); func_021CDA0C((struct QE *)p,(u32)func_021CDC0C); }

void func_021CD9B0(u8 *p) { func_021D3F88((struct S *)(p+0x18)); func_021CDA0C((struct QE *)p,(u32)func_021CDA18); }


/* 021CD9C8  byte field 0x1a7 == 2 */
/*
 * 8 instructions, 16 bytes: ldr r1, pool_021CD9D8; ldrb r0, [r0, r1]; cmp r0, #2; bne loc_021CD9D4; movs r0, #1; bx lr; movs r0, #0; bx lr.
 */
u32 func_021CD9C8(u8 *p)
{
    return (((struct Obj18365 *)p)->f1A7 == 2);
}

/*
 * Reads the u16 field at #0x22 of the argument and returns it.
 */
u16 func_021CD9DC(struct QD *p) { return p->v; }


/* 021CD9E0  function-pointer slot 0x28 compared with 0x021CDC0D */
/*
 * 8 instructions, 16 bytes: ldr r1, [r0, #0x28]; ldr r0, pool_021CD9F0; cmp r1, r0; bne loc_021CD9EC; movs r0, #1; bx lr; movs r0, #0; bx lr.
 */
u32 func_021CD9E0(u8 *p)
{
    return (((struct Obj18367 *)p)->f28 == 0x021CDC0D);
}

/*
 * u8 step preserves the low-byte result for every incoming word; no
 * signed int addition overflow. Wide step emits an extra narrowing pair.
 */
void func_021CD9F4(u8 *p,u8 n) { p[0x1ab]+=n; if(p[0x1ab]>14) p[0x1ab]=14; }
