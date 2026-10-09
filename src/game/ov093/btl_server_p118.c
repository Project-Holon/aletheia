/*
 * file:     btl_server_p118.c
 * unit:     yes
 * function: func_021CD5E0, func_021CD63C, func_021CD644, func_021CD64C, func_021CD6AC, func_021CD6EC, func_021CD6F0, func_021CD8E0, func_021CD914, func_021CD924, func_021CD938, func_021CD95C, func_021CD960, func_021CD978, func_021CD97C, func_021CD984, func_021CD9B0, func_021CD9C8, func_021CD9DC, func_021CD9E0, func_021CD9F4, func_021CDA0C, func_021CDA18, func_021CDC0C, func_021CDD34, func_021CDD50, func_021CDD94, func_021CDDA0, func_021CDDCC, func_021CDDDC, func_021CDE8C, func_021CDECC, func_021CDEE8, func_021CDF1C, func_021CDF58, func_021CDFE4, func_021CE040, func_021CE044, func_021CE068, func_021CE08C, func_021CE0BC, func_021CE0E0, func_021CE0F8, func_021CE150, func_021CE160
 * address:  0x021CD5E0
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
 *   func_021CCB18  0x021CCB18  thumb  ov093
 *   func_021CCAD4  0x021CCAD4  thumb  ov093
 *   func_021CD0F0  0x021CD0F0  thumb  ov093
 *   data_021EFF14  0x021EFF14  data
 *   func_021CCAA8   0x021CCAA8  thumb ov093
 *   func_021CCAE0  0x021CCAE0  thumb  ov093
 *   func_021CCB98  0x021CCB98  thumb  ov093
 *   func_021CCBE8  0x021CCBE8  thumb  ov093
 *   func_02030734 0x02030734 arm
 *   d_021F3A88 0x021F3A88 data a4
 *   func_021EEA58 0x021EEA58 thumb ov093
 *   func_021B9AF8 0x021B9AF8 thumb ov093
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
 *   func_021D3F88 0x021D3F88 thumb ov093
 *   func_021D3FDC 0x021D3FDC thumb ov093
 *   func_021EEBE8 0x021EEBE8 thumb ov093
 *   func_021EEC20 0x021EEC20 thumb ov093
 *   func_021D3FAC 0x021D3FAC thumb ov093
 *   func_021D3FC4 0x021D3FC4 thumb ov093
 *   func_021D3F4C 0x021D3F4C thumb ov093
 *   func_021EEC4C 0x021EEC4C thumb ov093
 *   func_021D3F60 0x021D3F60 thumb ov093
 *   func_02005CA4 0x02005CA4 thumb
 *   func_02006740 0x02006740 thumb
 *   func_02005E50 0x02005E50 thumb
 *   func_021D3FA8 0x021D3FA8 thumb ov093
 *   func_021BA73C 0x021BA73C thumb ov093
 *   func_02006734 0x02006734 thumb
 *   func_021D3F98 0x021D3F98 thumb ov093
 *   func_021EAE24 0x021EAE24 thumb ov093
 *   func_02005DF8 0x02005DF8 thumb
 *   func_021F88BC 0x021F88BC thumb ov094
 *   func_021F8678 0x021F8678 thumb ov094
 *   func_021EAE34 0x021EAE34 thumb ov093
 *   func_021EAE74 0x021EAE74 thumb ov093
 *   func_021BA7F8 0x021BA7F8 thumb ov093
 *   d_021EFFEC 0x021EFFEC data a4
 *   func_021F8524 0x021F8524 thumb ov094
 *   func_021B86B8  0x021B86B8  thumb  ov093
 *   func_021E90A0  0x021E90A0  thumb  ov093
 *   func_021E90D0  0x021E90D0  thumb  ov093
 *   func_021BA5C4  0x021BA5C4  thumb  ov093
 *   func_021BA5D0  0x021BA5D0  thumb  ov093
 *   func_021F84E8  0x021F84E8  thumb  ov094
 *   func_021F8504  0x021F8504  thumb  ov094
 *   func_021EAEA8  0x021EAEA8  thumb  ov093
 *   func_021EE688  0x021EE688  thumb  ov093
 *   func_021D3F54  0x021D3F54  thumb  ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   _u32_div_f 0x0209C2B0 arm
 *   func_021B8588 0x021B8588 thumb ov093
 *   func_021B86C0 0x021B86C0 thumb ov093
 *   func_021B9064 0x021B9064 thumb ov093
 *   func_021B9920 0x021B9920 thumb ov093
 *   func_021EAA00  0x021EAA00  thumb  ov093
 *   func_021EAA5C  0x021EAA5C  thumb  ov093
 *   func_021EAA34  0x021EAA34  thumb  ov093
 *   func_0203F0A8  0x0203F0A8  arm
 *   _ull_mul       0x0209C054  arm
 *   func_021EAF18  0x021EAF18  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021EAF50  0x021EAF50  thumb  ov093
 *   func_021EAF78  0x021EAF78  thumb  ov093
 */
#include "../../matched/include/Obj05197.h"
#include "../../matched/include/Obj13352.h"
#include "../../matched/include/Obj13353.h"
#include "../../matched/include/Obj07767.h"
#include "../../matched/include/Obj18365.h"
#include "../../matched/include/Obj18367.h"
#include "../../matched/include/Obj00463.h"
#include "../../matched/include/Obj00818.h"
#include "../../matched/include/Obj09986.h"
#include "../../matched/include/Obj01689.h"
#include "../../matched/include/Obj06232.h"
#include "../../matched/include/Obj04362.h"
#include "../../matched/include/Obj01892.h"
#include "../../matched/include/Obj07768.h"
#include "../../matched/include/Obj21134.h"
#include "../../matched/include/Obj13355.h"

#define va_start(v, l) ((v) = (char *)(((unsigned int)&(l) & ~3u) + 4))
#define va_arg(ap, t) (*(t *)((ap += 4) - 4))
struct Q2;
struct QE;
struct S;
struct Q;
struct Q3;
struct L;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct {
    u32 wpos;
    u32 rpos;
} Buf;

typedef char *va_list;

typedef struct { u8 f0:1,f1:1,f2:1,f3:1,f4:1,f5:1,rest:2; } Flags;

struct Copy24 { int x[6]; };

/* 021CD95C  str r1,[r0,#0x54] */
struct QA { u8 pad[0x54]; u32 v; };

/* 021CD978  ldr r0,[r0,#0x50] */
struct QB { u8 pad[0x50]; u32 v; };

/* 021CD97C  push {r3,lr}; ldr r1,[r0,#0x28]; blx r1; pop {r3,pc} */
struct R2 { u8 pad[0x28]; void (*fn)(struct R2 *); };

/* 021CD9DC  ldrh r0,[r0,#0x22] */
struct QD { u8 pad[0x22]; u16 v; };

/* 021CDA0C  str r1,[r0,#0x28]; movs r1,#0x6a; movs r2,#0; lsls r1,#2;
 *           strb r2,[r0,r1] */
struct QE { u8 pad[0x28]; u32 v; u8 rest[0x1a8 - 0x2c]; u8 z; };

typedef int (*Callback)(u8 *,int *);

typedef struct { u8 f0:1,f1:1,f2:1,f3:1,f4:1,f5:1,rest:2; } Flags_021CDA18;

typedef struct { u8 id; u8 flag; u16 pad; Callback callbacks[3]; } Entry;

typedef struct {
    int a;
    int b;
} S;

struct Flags_021CDDA0 { u8 pad[0x1b2]; u8 low:4; u8 flag:1; u8 high:3; };

struct Flags_021CDDCC { u8 pad[0x1b2]; u8 low:5; u8 flag:1; u8 high:2; };

typedef unsigned long long u64;

extern u16 func_021CCB18(void *r);
extern u8 func_021CCAD4(u8 *p);
extern void func_021CD0F0(void *r, int cmd, s32 *a);
extern void func_021CCAA8(void *p, int v);
extern void func_021CCAE0(void *w, u16 v);
extern void func_021CCB98(void *w, s32 v);
extern s32 func_021CCBE8(void *r);
extern void *func_02030734(u16, u32, int, const char *, u16);
extern void *func_021EEA58(u32, int, u32, u32);
extern char *func_021B9AF8(char *, int);
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
extern void func_021D3F88(struct S *p);
extern void func_021D3FDC(u8 *p, struct Q *q);
extern u8 func_021EEBE8(void *);
extern int func_021EEC20(int,u32 **);
extern int func_021D3FAC(u8 *);
extern void func_021D3FC4(u8 *);
extern int func_021D3F4C(void *);
extern int func_021EEC4C(void *,void *,u32);
extern u8 func_021D3F60(u8 *);
extern void func_02005CA4(int,u32);
extern void func_02006740(void);
extern int func_02005E50(void);
extern u16 func_021D3FA8(u8 *p);
extern void func_021BA73C(char *,int);
extern void func_02006734(u8);
extern int func_021D3F98(u8 *);
extern void func_021EAE24(u8 *p);
extern void func_02005DF8(u32 a);
extern void func_021F88BC(int);
extern void *func_021F8678(void);
extern int func_021EAE34(u8 *p);
extern void func_021EAE74(char *p, u32 a, u32 b);
extern void func_021BA7F8(char *p);
extern int func_021F8524(int);
extern void *func_021B86B8(void ***p);
extern void func_021E90A0(unsigned int *o, unsigned int key);
extern int func_021E90D0(struct S *s);
extern u16 func_021BA5C4(u8 *p);
extern u16 func_021BA5D0(struct Q3 *p);
extern void func_021F84E8(int a, int b);
extern void func_021F8504(u32 a, u32 b, u32 c);
extern void func_021EAEA8(u8 *p, int v);
extern int func_021EE688(int, int);
extern void func_021D3F54(u8 *p);
extern int func_021D59B4(u8 *p, int k);
extern u32 _u32_div_f(u32,u32);
extern u32 func_021B8588(void **);
extern u8 func_021B86C0(u8 **);
extern u32 func_021B9064(u8 *p, int k, int x);
extern u8 *func_021B9920(void *p, u32 i, u8 j);
extern void func_021EAA00(u8 *p, u8 v);
extern void func_021EAA5C(u8 *o);
extern int func_021EAA34(u8 *o, u8 *out);
extern u32 func_0203F0A8(void);
extern void func_021EAF18(struct L *p, int kind, int id);
extern u8 func_021D5440(u8 *p);
extern void func_021EAF50(struct L *p, u32 val);
extern void func_021EAF78(u8 *o, u8 v);
int func_021CD5E0(Buf *r, s32 *a);
void func_021CD63C(void *p, int v);
u8 func_021CD644(u8 *p);
void func_021CD64C(void *w, u8 id, ...);
void func_021CD6AC(void *r, u8 cmd, s32 *out);
void func_021CD6EC(void);
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
u32 func_021CD9C8(u8 *p);
u16 func_021CD9DC(struct QD *p);
u32 func_021CD9E0(u8 *p);
void func_021CD9F4(u8 *p,u8 n);
void func_021CDA0C(struct QE *p, u32 v);
int func_021CDA18(u8 *p);
int func_021CDC0C(u8 *p);
void func_021CDD34(u8 *p);
Callback func_021CDD50(u8 *p,u32 id,int *out);
void func_021CDD94(char *p, int *o);
int func_021CDDA0(u8 *p);
u32 func_021CDDCC(struct Flags_021CDDCC *p);
int func_021CDDDC(u8 *p, int *st);
int func_021CDE8C(int a, int b);
void func_021CDECC(u8 *p);
u32 func_021CDEE8(u8 *p);
void *func_021CDF1C(u8 *p);
int func_021CDF58(u8 *p, int *st);
u32 func_021CDFE4(u32 mode);
int func_021CE040(void);
void func_021CE044(u8 *p);
void func_021CE068(u8 *p);
int func_021CE08C(u8 *p);
int func_021CE0BC(u8 *p,void *q);
void func_021CE0E0(u8 *p);
void func_021CE0F8(u8 *p, u8 *q, u8 *o);
void func_021CE150(u8 *p, void *q);
void func_021CE160(u8 *p);
extern const u8 data_021EFF14[];
extern u8 d_021F3A88[];
extern const Entry d_021EFFEC[15];









int func_021CD5E0(Buf *r, s32 *a)
{
    int c;
    u8 k;

    c = func_021CCB18(r);
    while (c == 0x5f) {
        r->rpos += func_021CCAD4((u8 *)r);
        if (r->rpos >= r->wpos) {
            return 0x5e;
        }
        c = func_021CCB18(r);
    }
    k = data_021EFF14[c];
    if (k != 0 && k != 0x10) {
        func_021CD0F0(r, k, a);
    } else {
        func_021CD6AC(r, c, a);
    }
    return c;
}









/*
 * tail-call thunk to func_021CCAA8
 */
void func_021CD63C(void *p, int v)
{
    func_021CCAA8(p, v);
}









/*
 * tail-call thunk to func_021CCAD4
 */
u8 func_021CD644(u8 *p)
{
    return func_021CCAD4(p);
}









void func_021CD64C(void *w, u8 id, ...)
{
    va_list ap;
    u16 v;
    s32 x;

    va_start(ap, id);
    v = va_arg(ap, s32);
    func_021CCAE0(w, id);
    func_021CCAE0(w, v);
    if (id == 0x5C) {
        func_021CCAE0(w, va_arg(ap, s32));
    }
    do {
        x = va_arg(ap, s32);
        func_021CCB98(w, x);
    } while (x != (s32)0xFFFF0000);
}









void func_021CD6AC(void *r, u8 cmd, s32 *out)
{
    int i;

    i = 1;
    out[0] = func_021CCB18(r);
    if (cmd == 0x5c) {
        out[1] = func_021CCB18(r);
        i++;
    }
    for (; i < 16; i++) {
        out[i] = func_021CCBE8(r);
        if (out[i] == 0xFFFF0000) {
            break;
        }
    }
}









/*
 * empty function: bx lr
 */
void func_021CD6EC(void)
{
}








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






void func_021CDA0C(struct QE *p, u32 v)
{
    p->v = v;
    p->z = 0;
}






int func_021CDA18(u8 *p)
{
    u32 id, *pair, x, y;
    int flag, n;
    func_021D3FDC(p,(struct Q *)(p+0x18));
    switch (p[0x1a8]) {
    case 0:
        id = func_021EEBE8(((struct Obj00463 *)p)->f50);
        if (p[0x1a7] == 2 && (((Flags_021CDA18 *)(p+0x1b2))->f4 || ((Flags_021CDA18 *)(p+0x1b2))->f5) && !id) return 0;
        func_021CDD34(p);
        if (id == 9) {
            func_021EEC20(*(int *)&((struct Obj00463 *)p)->f50,&pair);
            x = pair[0]; y = pair[1];
            ((struct Obj00463 *)p)->f30 = y;
            ((struct Obj00463 *)p)->f2C = x;
            ((struct Obj00463 *)p)->fCC = 0;
            p[0x1a8] = 3;
        } else if (id) {
            *(Callback *)&((struct Obj00463 *)p)->fC8 = func_021CDD50(p,id,&flag);
            if (flag) {
                if (!func_021D3FAC(p+0x18)) { p[0x1a8] = 6; break; }
            } else func_021D3FC4(p+0x18);
            if (*(Callback *)&((struct Obj00463 *)p)->fC8) {
                p[0x1a8] = 1;
                ((struct Obj00463 *)p)->fCC = 0;
            } else {
                ((struct Obj00463 *)p)->fCC = 0;
                p[0x1a8] = 2;
            }
        } else if (((Flags_021CDA18 *)(p+0x1b2))->f1) return 1;
        break;
    case 1:
        if ((*(Callback *)(p+0xc8))(p,(int *)(p+0xcc))) {
            if (((Flags_021CDA18 *)(p+0x1b2))->f1) return 1;
            if (func_021D3F4C(p+0x18)) p[0x1a8] = 4;
            else p[0x1a8] = 2;
        }
        break;
    case 2:
        if (func_021EEC4C(((struct Obj00463 *)p)->f50,((struct Obj00463 *)p)->fD8,((struct Obj00463 *)p)->fDC)) p[0x1a8] = 0;
        if (((Flags_021CDA18 *)(p+0x1b2))->f1) return 1;
        break;
    case 3:
        if (func_021EEC4C(((struct Obj00463 *)p)->f50,((struct Obj00463 *)p)->fD8,((struct Obj00463 *)p)->fDC)) p[0x1a8] = 7;
        if (((Flags_021CDA18 *)(p+0x1b2))->f1) return 1;
        break;
    case 6:
        if (func_021D3F4C(p+0x18)) p[0x1a8] = 4;
        break;
    case 4:
        if (func_021D3F60(p+0x18) == 1) p[0x1a8] = 7;
        else {
            if (((struct Obj00463 *)p)->f54) { func_02005CA4(1,62); func_02006740(); }
            p[0x1a8] = 5;
        }
        break;
    case 5:
        if (!func_02005E50()) {
            n = func_021D3FA8(p+0x18);
            func_02005CA4(0,1);
            func_021BA73C(*(char * *)&((struct Obj00463 *)p)->f0,n);
            func_02006734(0);
        }
        break;
    case 7:
        return 1;
    }
    return 0;
}






/*
 * extent: The store-and-return follower at 0x021CDD34 is included here;
 * the larger lookup follower at 0x021CDD50 has its own verified shard.
 */
int func_021CDC0C(u8 *p)
{
    u32 id;
    u16 n;
    int zero;
    func_021D3FDC(p,(struct Q *)(p+0x18));
    switch (p[0x1a8]) {
    case 0:
        p[0x1a8] = 1;
    case 1:
        if (!func_021D3F98(p+0x18)) {
            id = func_021EEBE8(((struct Obj00818 *)p)->f50);
            if (id) {
                zero = 0;
                *(Callback *)&((struct Obj00818 *)p)->fC8 = func_021CDD50(p,id,0);
                if (*(Callback *)&((struct Obj00818 *)p)->fC8) {
                    p[0x1a8] = 2;
                    ((struct Obj00818 *)p)->fCC = zero;
                }
                else {
                    func_021CDD34(p);
                    p[0x1a8] = 3;
                    ((struct Obj00818 *)p)->fCC = zero;
                }
            }
        } else {
            if (((struct Obj00818 *)p)->f54) {
                func_02005CA4(1,1);
                func_021EAE24(((struct Obj00818 *)p)->f54);
                func_02005DF8(30);
                func_021F88BC(0);
                func_02006740();
            }
            p[0x1a8] = 4;
        }
        break;
    case 2:
        if ((*(Callback *)(p+0xc8))(p,(int *)(p+0xcc))) {
            p[0x1a8] = 3;
            ((struct Obj00818 *)p)->fCC = 0;
            if (func_021F8678()) func_021F88BC(1);
        }
        break;
    case 3:
        if (func_021EEC4C(((struct Obj00818 *)p)->f50,((struct Obj00818 *)p)->fD8,((struct Obj00818 *)p)->fDC)) p[0x1a8] = 1;
        break;
    case 4:
        if (((struct Obj00818 *)p)->f54) {
            if (func_021EAE34(((struct Obj00818 *)p)->f54)) {
                if (!func_02005E50()) {
                    n = (int)func_021D3FA8(p+0x18);
                    func_021EAE74(((struct Obj00818 *)p)->f54,n,n);
                    func_021BA7F8(((struct Obj00818 *)p)->f0);
                }
            }
        }
        break;
    case 5: return 1;
    }
    return 0;
}






void func_021CDD34(u8 *p)
{
    ((struct Obj09986 *)p)->fE0 = 0;
    *(u8 * *)&((struct Obj09986 *)p)->fD8 = p+0xe0;
    ((struct Obj09986 *)p)->fDC = 4;
}






Callback func_021CDD50(u8 *p,u32 id,int *out)
{
    u32 i;
    for (i=0; i<15; i++) {
        if (d_021EFFEC[i].id == id) {
            if (out) *out = d_021EFFEC[i].flag;
            return d_021EFFEC[i].callbacks[p[0x1a7]];
        }
    }
    return 0;
}







void func_021CDD94(char *p, int *o)
{
    *(S *)o = *(S *)(p + 0x2c);
}






/*
 * unresolved THM_CALL at +0x14. Region hint ov094 does not supply a witness.
 * note 2026-10-05 (D8 lane16): re-verified MATCH. Callee 0x021F8524 is an ov094 Thumb wrapper (pool-based tail), other overlay, not filed here (ov094 owner Ilias). Integrator: seed label.
 */
int func_021CDDA0(u8 *p) { if(p[0x1a7]!=2) { if(*(u16 *)(p+0xe6)) return func_021F8524(0); return 0; } return ((struct Flags_021CDDA0 *)p)->flag; }






u32 func_021CDDCC(struct Flags_021CDDCC *p) { return p->flag; }






/*
 * Levers (from the DIFF note): case 0 is the call written in each arm, `!= 4` arm first
 * (a-boolean-argument-is-a-call-in-each-arm.md; a flag value hoists `movs r1,#1`);
 * func_021F84E8 takes two arguments as its own file says, the second being the 0xe4
 * halfword still live in r1 from the || test; func_021D3FA8 is declared u32 here because
 * the original narrows its result before the u16 parameter of func_021EAEA8.
 */
int func_021CDDDC(u8 *p, int *st)
{
    switch (*st) {
    case 0:
        if ((int)func_021B86B8(*(void *** *)&((struct Obj01689 *)p)->f0) != 4) {
            func_021E90A0(((struct Obj01689 *)p)->f54, 0);
        } else {
            func_021E90A0(((struct Obj01689 *)p)->f54, 1);
        }
        *st = *st + 1;
        break;
    case 1:
        if (func_021E90D0(((struct Obj01689 *)p)->f54) == 0) {
            break;
        }
        ((struct Obj01689 *)p)->fE4 = func_021BA5C4(((struct Obj01689 *)p)->f0);
        ((struct Obj01689 *)p)->fE6 = func_021BA5D0(((struct Obj01689 *)p)->f0);
        if (((struct Obj01689 *)p)->fE4 != 0 || ((struct Obj01689 *)p)->fE6 != 0) {
            func_021F84E8(((struct Obj01689 *)p)->fE6, ((struct Obj01689 *)p)->fE4);
            if (((struct Obj01689 *)p)->fE6 != 0) {
                func_021F8504(0, 1, 1);
            }
        }
        func_021CDECC(p);
        if (func_021CD9E0(p) != 0) {
            func_021EAEA8(((struct Obj01689 *)p)->f54, (u16)((u32)func_021D3FA8(p + 0x18)));
        }
        return 1;
    }
    return 0;
}






int func_021CDE8C(int a, int b)
{
    int r4;
    if (((struct Obj06232 *)a)->f54 != 0) {
        r4 = func_021CDDDC((u8 *)a, (int *)b);
        if (r4 != 0) {
            if (func_021EE688(((struct Obj06232 *)a)->f14, ((struct Obj06232 *)a)->f1A6) != 0)
                func_021D3F54((u8 *)(a + 0x18));
        }
        return r4;
    }
    func_021EE688(((struct Obj06232 *)a)->f14, ((struct Obj06232 *)a)->f1A6);
    return 1;
}





void func_021CDECC(u8 *p) { void *a; a=func_021CDF1C(p); if(a) ((struct Obj04362 *)p)->f19C=func_021D59B4(a,13); }





u32 func_021CDEE8(u8 *p) { void *a; u32 now,old; a=func_021CDF1C(p); if(a) { now=func_021D59B4(a,13); old=((struct Obj04362 *)p)->f19C; if(now>=old) return 0; return _u32_div_f((old-now)*100,now); } return 0; }




/*
 * Prototype: original narrows getter result to u8 before 021B9920;
 * caller extern has u8 second argument; named u8 local keeps shift in r0.
 */
void *func_021CDF1C(u8 *p) { u8 side; if(func_021B8588(*(void ** *)&((struct Obj04362 *)p)->f0)==0 && func_021B86C0(*(u8 ** *)&((struct Obj04362 *)p)->f0)==0) { side=func_021B9064(*(u8 * *)&((struct Obj04362 *)p)->f0,p[0x1a6],0); return func_021B9920(*(char * *)&((struct Obj04362 *)p)->f4,side,0); } return 0; }





int func_021CDF58(u8 *p, int *st)
{
    u8 buf;

    switch (*st) {
    case 0:
        func_021EAA00(((struct Obj01892 *)p)->f54, p[0xc4]);
        func_021CE068(p);
        *st = *st + 1;
        break;
    case 1:
        if (func_021CE08C(p) != 0) {
            func_021EAA5C(((struct Obj01892 *)p)->f54);
            *st = 2;
        } else if (func_021EAA34(((struct Obj01892 *)p)->f54, &buf) != 0) {
            p[0xc4] = buf;
            *st = 3;
        }
        break;
    case 2:
        p[0xc4] = func_021CDFE4(p[0xc4]);
        *st = *st + 1;
        break;
    case 3:
        func_021CE0E0(p);
        *st = *st + 1;
        break;
    case 4:
        *(u8 * *)&((struct Obj01892 *)p)->fD8 = p + 0xc4;
        ((struct Obj01892 *)p)->fDC = 1;
        return 1;
    }
    return 0;
}



/*
 * Lever: each switch arm writes its own `mode = (u8)t;` before `break`. The copies are
 * cross-jumped into `b join` after branch threading, so each arm's `blo` keeps landing on
 * its own hop (a-conditional-branch-onto-an-unconditional-b-is-a-cross-jumped-tail-copy.md).
 * One shared `mode = (u8)t;` after the switch threads the hops away (4 bytes short).
 */
u32 func_021CDFE4(u32 mode)
{
    u32 v;
    int t;

    v = (u32)(((u64)func_0203F0A8() * 100) >> 32);
    if (mode == 0) {
        if (v < 0x1e) {
            mode = 3;
        } else if (v < 0x3c) {
            mode = 2;
        } else {
            mode = 1;
        }
    } else {
        switch (mode) {
        case 1:
        default:
            t = (v < 0x32) ? 2 : 3;
            mode = (u8)t;
            break;
        case 3:
            t = (v < 0x28) ? 2 : 1;
            mode = (u8)t;
            break;
        case 2:
            t = (v < 0x28) ? 3 : 1;
            mode = (u8)t;
            break;
        }
    }
    return mode;
}


int func_021CE040(void)
{
    return 1;
}


void func_021CE044(u8 *p) { p[0xc4]=func_021CDFE4(p[0xc4]); *(u8 * *)&((struct Obj07768 *)p)->fD8=p+0xc4; ((struct Obj07768 *)p)->fDC=1; }



void func_021CE068(u8 *p) { if(((struct Obj01892 *)p)->fE4) { func_021F8504(1,1,1); p[0x1ad]=0; } }



/*
 * note 2026-10-05 (D8 lane16): re-verified MATCH. Same blocker as 021CDDA0: ov094 0x021F8524 needs a label/witness.
 */
int func_021CE08C(u8 *p) { if(*(u16 *)(p+0xe4)!=0) { if(p[0x1ad]==0) { if(func_021F8524(1)) p[0x1ad]=1; } return p[0x1ad]; } return 0; }



int func_021CE0BC(u8 *p,void *q) { if(func_021CE08C(p)) { if(q) func_021CE150(p,q); return 1; } return 0; }



void func_021CE0E0(u8 *p) { if(((struct Obj21134 *)p)->fE4!=0) func_021F8504(1,0,0); }




void func_021CE0F8(u8 *p, u8 *q, u8 *o)
{
    if (func_021B8588(*(void ** *)&((struct Obj13355 *)p)->f0) != 3) {
        func_021EAF18((struct L *)o, 1, 0x45);
        func_021EAF50((struct L *)o, func_021D5440(q));
        func_021EAF78(o, 0);
    } else {
        func_021EAF18((struct L *)o, 1, 0x46);
        func_021EAF50((struct L *)o, p[0x1a6]);
        func_021EAF78(o, 0);
    }
}



void func_021CE150(u8 *p, void *q) { ((struct Obj01892 *)p)->fD0=q; ((struct Obj01892 *)p)->fD4=0; }




/* 021CE160  the receiver pointer is also the FIRST argument: the image keeps
 * r0 = p, puts p+0xd4 in r1 and the slot from [p+0xd0] in r2. */
/*
 * Leaf with no calls and no pool; 8 instructions, 16 bytes: push {r3, lr}; adds r2, r0, #0; adds r2, #0xd0; adds r1, r0, #0; ldr r2, [r2]; adds r1, #0xd4; blx r2; pop {r3, pc}.
 */
void func_021CE160(u8 *p)
{
    ((void (*)(u8 *, u8 *)) * (u32 *)(p + 0xd0))(p, p + 0xd4);
}
