/*
 * file:     unit_0217AE20.c
 * unit:     yes
 * function: func_0217AE20, func_0217AE38, func_0217AE40, func_0217AED4, func_0217AEE8, func_0217AEFC, func_0217AF04, func_0217AF38, func_0217AF4C, func_0217AFB0, func_0217AFE4, func_0217B054, func_0217B098, func_0217B158, func_0217B1D0, func_0217B264, func_0217B370, func_0217B3EC, func_0217B440, func_0217B4C4, func_0217B5E0, func_0217B66C, func_0217B6B4, func_0217B75C, func_0217B798, func_0217B80C, func_0217B83C, func_0217B840, func_0217B8E4, func_0217B8F0, func_0217B908, func_0217B974, func_0217B9BC, func_0217B9CC, func_0217B9F4, func_0217BA10, func_0217BA48, func_0217BA6C, func_0217BAA8, func_0217BAF0, func_0217BB04, func_0217BB20, func_0217BB3C, func_0217BB70, func_0217BCDC
 * address:  0x0217AE20
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_02012964  0x02012964  thumb
 *   func_02025C74  0x02025C74  thumb
 *   func_0216E618  0x0216E618  thumb  ov010
 *   func_0216CE60  0x0216CE60  thumb  ov010
 *   d_0217FFF8     0x0217FFF8  data  ov019  a4
 *   d_0218001C     0x0218001C  data  ov019  a2
 *   d_0217FFE4     0x0217FFE4  data  ov019  a2
 *   func_0216DE94 0x0216DE94 thumb ov010
 *   func_02034714 0x02034714 arm
 *   d_021807E0 0x021807E0 data a1
 *   func_0216DAC8  0x0216DAC8  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02188CE0  0x02188CE0  thumb  ov021
 *   func_0217F958  0x0217F958  thumb  ov019
 *   func_0216CF2C  0x0216CF2C  thumb  ov010
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_02087C6C  0x02087C6C  arm
 *   func_0203EFC8  0x0203EFC8  arm
 *   func_0217F894  0x0217F894  thumb  ov019
 *   func_0200EDC4  0x0200EDC4  thumb
 *   func_0217F948  0x0217F948  thumb  ov019
 *   memcmp  0x0203EFC8  arm
 *   memset        0x02082BCC  arm
 *   func_02012114 0x02012114  thumb
 *   func_0217F93C 0x0217F93C  thumb  ov019
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200ED48  0x0200ED48  thumb
 *   func_0201283C  0x0201283C  thumb
 *   d_02180044  0x02180044  data  a4
 *   d_02180048  0x02180048  data  a4
 *   d_0218004C  0x0218004C  data  a4
 *   func_0217F060  0x0217F060  thumb  ov019
 *   func_0217F858  0x0217F858  thumb  ov019
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_0216D5A0  0x0216D5A0  thumb  ov010
 *   func_0216E0E8  0x0216E0E8  thumb  ov010
 *   func_0216D828  0x0216D828  thumb  ov010
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_0216D480  0x0216D480  thumb  ov010
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D5F8 0x0216D5F8  thumb  ov010
 *   func_0216D548 0x0216D548  thumb  ov010
 *   func_0216D550 0x0216D550  thumb  ov010
 *   func_021BBA70 0x021BBA70  thumb  ov021
 *   func_021734A8 0x021734A8  thumb  ov012
 *   func_02012138 0x02012138 thumb
 *   func_02026474 0x02026474 thumb
 *   func_0217413C 0x0217413C thumb ov012
 *   d_02180074  0x02180074  data  a4
 *   d_02180078  0x02180078  data  a4
 *   d_0218007C  0x0218007C  data  a4
 *   func_0200BAC8 0x0200BAC8 thumb
 *   func_0200BBA8 0x0200BBA8 thumb
 *   func_0200BAF4 0x0200BAF4 thumb
 *   func_020307B0 0x020307B0 arm
 *   d_021807E4 0x021807E4 data a1
 *   func_0201A364 0x0201A364 thumb
 *   func_0200AEE8 0x0200AEE8 thumb
 *   func_02012934 0x02012934 thumb
 *   func_0201A090 0x0201A090 thumb
 *   func_021A2E44 0x021A2E44 thumb ov021
 *   func_0200FB24 0x0200FB24 thumb
 *   func_02173524 0x02173524 thumb ov012
 *   func_0217F074 0x0217F074 thumb ov019
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_021A3460  0x021A3460  thumb  ov021
 *   func_02172D20  0x02172D20  thumb  ov012
 *   func_02172D68  0x02172D68  thumb  ov012
 *   func_0216D588  0x0216D588  thumb  ov010
 *   func_0216DDC0  0x0216DDC0  thumb  ov010
 *   func_0203D1B4  0x0203D1B4  arm
 *   func_020362DC  0x020362DC  arm
 *   func_0217F7E4  0x0217F7E4  thumb  ov019
 *   func_0217F1EC  0x0217F1EC  thumb  ov019
 *   func_02012124  0x02012124  thumb
 *   func_02172D38  0x02172D38  thumb  ov012
 *   func_02173420  0x02173420  thumb  ov012
 *   func_02172D50  0x02172D50  thumb  ov012
 */
#include "../../matched/include/Obj19389.h"
#include "../../matched/include/Obj19390.h"
#include "../../matched/include/Obj07379.h"
#include "../../matched/include/Obj07380.h"
#include "../../matched/include/Obj12518.h"
#include "../../matched/include/Obj07381.h"
#include "../../matched/include/Obj12521.h"
#include "../../matched/include/Obj19401.h"
#include "../../matched/include/Obj19402.h"
#include "../../matched/include/Obj09409.h"
#include "../../matched/include/Obj19403.h"
#include "../../matched/include/Obj07382.h"
#include "../../matched/include/Obj12522.h"

struct BigObj;
struct Ctx;
struct ent_0217AE20;
struct L0200EDC4;
struct Big;
struct obj;
struct Obj00020;
struct Src;
struct Reg;
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef unsigned int u32;

typedef union { u32 w[9]; u16 h[18]; } Tmpl;

typedef struct { s16 x, y; } Pt;

typedef enum { FALSE, TRUE } BOOL;

typedef struct { u8 *p; u8 f4,f5,f6,f7; u8 pad[4]; } Ent_0217AF04;

typedef struct {
    u8 pad[0x6b];
    u8 f6b;
    u16 f6c;
} Obj_0217AE20;

typedef struct {
    Obj_0217AE20 *f0;
    u8 pad4[2];
    u8 f6, f7, f8, f9;
    u8 pad[2];
} Ent_0217AF4C;

typedef struct {
    int f0;
    u8 f4, f5, f6, f7, f8, f9;
    u8 pad[2];
} Ent_0217AFE4;

typedef struct {
    u8 pad[6];
    u8 f6;
    u8 f7 : 1;
} Src;

typedef struct {
    u8 mac[6];
    u8 pad;
    u8 f0 : 1;
    u8 f1 : 1;
} Ent8;

typedef struct {
    u8 pad[0x28];
    Ent8 tab[5];
    u8 pad2[0x5c - 0x50];
    int f5c;
    u8 pad3[0x6c - 0x60];
    u16 f6c;
    u8 pad4[2];
    u8 *slot[5];
} Obj_0217B054;

typedef signed int     s32;

struct sub {
    u8 mac[6];
    u8 pad;
    u8 : 1;
    u8 f : 1;
    u8 : 6;
};

struct ent_0217AE20 {
    u8 pad0[7];
    u8 : 4;
    u8 on : 1;
    u8 : 3;
    u8 pad1[0x20];
    struct sub s[5];
    u8 pad2[0x1c];
    u16 cnt;
    u8 pad3[0x1e];
};

struct ent_0217B1D0 {
    u8 pad0[0x28];
    struct sub s[5];
    u8 pad1[0x20];
    int p[5];
};

struct inner {
    int pad0[2];
    int f8;
    int fc;
};

struct obj {
    struct inner *in;
};

typedef struct Entry_0217B1D0 {
    u8   pad0[7];
    u8   f7_lo : 4;
    u8   active : 1;
    u8   f7_hi : 3;
    u8   pad8[0x6C - 8];
    u16  h6C;
    u16  pad6E;
    void *slots[5];
    u8   pad84[8];
} Entry_0217B1D0;

typedef int (*fn_t)(char *, unsigned char *, int, unsigned char *);

struct ent_0217B370 { fn_t f; int a; int b; };

struct ent_0217B440 {
    u8 pad0[7];
    u8 : 4;
    u8 on : 1;
    u8 : 3;
    u8 pad1[0x54];
    int f5c;
    u8 pad2[0x10];
    int *p70;
    u8 pad3[0x18];
};

typedef struct Rec {
    u8 pad0[6];
    u8 b6;
    u8 f7_lo : 1;
    u8 valid : 1;
    u8 f7_hi : 6;
} Rec;

typedef struct Entry_0217B370 {
    u8   pad0[6];
    u8   n : 3;
    u8   f6_hi : 5;
    u8   f7_lo : 5;
    u8   kind : 3;
    u8   pad8[3];
    u8   bB;
    u8   padC[0x28 - 0xC];
    Rec  recs[8];
    u8   pad68[4];
    u16  h6C;
} Entry_0217B370;

typedef struct Msg {
    Entry_0217B370 *e;
    u8     b4;
    u8     b5;
    u8     idx;
} Msg;

struct S {
    char pad[0x58];
    u16 f58;
};

typedef struct {
    u8 pad[7];
    unsigned char low : 4;
    unsigned char flag : 1;
    unsigned char high : 3;
} Flags;

struct ent { fn_t f; int a; int b; };

typedef struct { struct { void *f0; } *head; } Work_0217AE20;

typedef struct Entry {
    u8 pad0[0xB];
    u8 bB;
    u8 padC[0x8C - 0xC];
} Entry;

typedef struct Work_0217BB70 {
    u8    pad0[0x2910];
    Entry entries[10];
} Work_0217BB70;

void func_02082BCC(void *p, int v, int n);
extern u32 func_02012964(const struct BigObj *p);
extern u32 func_02025C74(u32 x);
extern void func_0216E618(void *, u32, u32, int);
extern int func_0216CE60(int, void *, int);
extern void *func_0216DE94(void *,unsigned int);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_0216DAC8(unsigned int *p, unsigned int v);
extern void *func_0201210C(const struct Ctx *p);
extern u32 func_02188CE0(u8 *p);
extern void func_0217F958(char *p, u32 key);
extern void func_0216CF2C(void *);
extern void MI_CpuFill8(void *dstp, u8 data, u32 size);
extern void func_02087C6C(void *);
extern s32 func_0203EFC8(const u8 *a, const u8 *b, unsigned int n);
extern int func_0217F894(void *p, char *q);
extern int func_0200EDC4(struct L0200EDC4 *l, u32 val);
extern void func_0217F948(char *p, u32 a, u32 b);
extern int memcmp(const void *a, const void *b, int n);
extern void memset(void *p, int v, int n);
extern unsigned int func_02012114(const struct Ctx *p);
extern void func_0217F93C(int, int);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200ED48(void *p);
extern u32 func_0201283C(const struct BigObj *p);
extern int func_0217F060(int i);
extern int func_0217F858(int a);
extern int func_0216D3CC(int a0);
extern void func_0216D410(void *a0, u16 a1);
extern u16 func_0216D5A0(void *p);
extern int func_0216E0E8(int a0, int a1);
extern void func_0216D828(int, s16 *);
extern int func_0216D454(int);
extern int func_0216D480(char *p);
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_021A3074(unsigned char *p);
extern u16 func_0216D5F8(void *p);
extern u32 *func_0216D548(u32 *p, u32 v);
extern u32 *func_0216D550(u32 *p, u32 v);
extern void func_021BBA70(struct Ctx *ctx, struct Src *src, u16 *v, u8 kind);
extern void func_021734A8(u8 *self, u32 id, u32 v);
extern unsigned int func_02012138(const struct Ctx *p);
extern u32 func_02026474(void *obj);
extern int func_0217413C(int, int, unsigned char *);
extern void *func_0200BAC8(void *);
extern unsigned int func_0200BBA8(void *);
extern void *func_0200BAF4(int, int);
extern u32 func_020307B0(void *p);
extern void func_0201A364(int a, unsigned int b);
extern void func_0200AEE8(struct Reg *p, u32 id, s32 value);
extern void *func_02012934(const struct BigObj *p);
extern int func_0201A090(void *, void *, unsigned int *);
extern void func_021A2E44(int, unsigned int);
extern unsigned int func_0200FB24(void);
extern void func_02173524(Work_0217AE20 *w, u8 *p);
extern void func_0217F074(void *ctx);
extern void *func_02188C7C(u8 *p);
extern int func_021A3460(u32 a, u32 b, u32 c, u32 d);
extern void  func_02172D20(u8 *w);
extern int   func_02172D68(u8 *w);
extern u16   func_0216D588(void *p);
extern void *func_0216DDC0(u32 a, u32 b, u32 c, u32 d);
extern int   func_0203D1B4(void);
extern u32   func_020362DC(void);
extern int func_0217F7E4(u32 arg);
extern unsigned int func_0217F1EC(u8 *p);
extern void func_02012124(struct Ctx *p, u32 v);
extern void func_02172D38(u8 *p);
extern void func_02173420(int *a);
extern void func_02172D50(u8 *p);
void func_0217AE20(u8 *w);
int func_0217AE38(char *p, char v);
int func_0217AE40(void *a, int b, u16 c, int d);
u16 func_0217AED4(u8 *a, u8 *b);
BOOL func_0217AEE8(u16 a);
u16 func_0217AEFC(unsigned int x);
int func_0217AF04(u8 *a, u16 key);
int func_0217AF38(u16 a);
int func_0217AF4C(char *a, u16 key);
void *func_0217AFB0(void **a,u8 *b,u8 *c);
Ent_0217AFE4 *func_0217AFE4(char *a, int b, Src *c, int d, int e, int *f);
void func_0217B054(u8 *w, Entry_0217B1D0 *ent_0217AE20, void *c);
void func_0217B098(u8 *w, u32 a, u32 b, u32 c, Entry_0217B1D0 *ent_0217AE20);
int func_0217B158(char *base, struct ent_0217AE20 *excl, u8 *mac);
int func_0217B1D0(struct obj *o, struct ent_0217B1D0 *e);
void func_0217B264(u8 *w, void *sys, void *q);
int func_0217B370(char *base, unsigned char *p, int r2);
int func_0217B3EC(char *base, char *p);
void func_0217B440(char *base, int x, void *y);
int func_0217B4C4(u8 *w, Msg *m);
int func_0217B5E0(char *base, int *p, int r2, unsigned char *state);
int func_0217B66C(char *base, int *p, int r2, unsigned char *state);
int func_0217B6B4(char *base, int *p, int r2, unsigned char *state);
void func_0217B75C(char *p);
void func_0217B798(char *base, u8 *p);
int func_0217B80C(int a, int b);
int func_0217B83C(void *sys, void *pos);
int func_0217B840(char *base, int r1);
int func_0217B8E4(char *p, int v);
int func_0217B8F0(char *p, char v);
int func_0217B908(int x);
int func_0217B974(int x);
int func_0217B9BC(unsigned int x);
void *func_0217B9CC(char *p);
void func_0217B9F4(void *p);
void func_0217BA10(char *p, int x);
int func_0217BA48(char *p, unsigned int *mask);
int func_0217BA6C(char *p, unsigned int *mask);
int func_0217BAA8(int a, int b, int *p, int *q);
void func_0217BAF0(char *p, int x, unsigned int v);
int func_0217BB04(char *p);
int func_0217BB20(char *p);
int func_0217BB3C(u8 *ctx, u8 *obj, int a);
int func_0217BB70(u8 *w, u8 *obj, void *q);
int func_0217BCDC(int *a, u8 *b, int c, u8 *d);
extern const Tmpl d_0217FFF8;
extern const Pt d_0218001C[];
extern const Pt d_0217FFE4[];
extern const char d_021807E0[];
extern struct ent_0217B370 d_02180044[];
extern struct ent_0217B370 d_02180048[];
extern struct ent_0217B370 d_0218004C[];
extern struct ent d_02180074[];
extern struct ent d_02180078[];
extern struct ent d_0218007C[];
extern const char d_021807E4[];






void func_0217AE20(u8 *w)
{
    func_02082BCC(w + 0x2e88, 0, 0x258);
}





int func_0217AE38(char *p, char v)
{
    p[9] = v;
    return 1;
}






/*
 * What closed it: the spilled third parameter is u16, not u32. As u32 the
 * scheduler hoists its reload (`ldr r0,[sp]`) above the `strh` of d into
 * the local; as u16 the reload stays after it (see
 * docs/notes/pkt_ov019_0217AE40.c.txt for the earlier near miss).
 */
int func_0217AE40(void *a, int b, u16 c, int d)
{
    int t;
    u16 hi, lo;
    Tmpl l;

    t = func_02012964((const struct BigObj *)b);
    hi = (u16)(d >> 8);
    lo = (u16)((d & 0xff) - 0x20);
    l = d_0217FFF8;
    l.h[0] = d;
    l.h[1] = func_02025C74(c);
    if (lo != 0)
        l.h[2] = 15;
    func_0216E618(&l, (u16)(d_0218001C[hi].x + d_0217FFE4[lo].x),
                  (u16)(d_0218001C[hi].y + d_0217FFE4[lo].y), 0);
    return func_0216CE60(t, &l, 422);
}





u16 func_0217AED4(u8 *a, u8 *b) { return (a[0x6b] << 8) | (b[6] + 0x20); }





BOOL func_0217AEE8(u16 a) { if ((u16)((unsigned char)a - 0x20) == 0) return FALSE; else return TRUE; }






u16 func_0217AEFC(unsigned int x)
{
    return (u16)(x >> 8);
}





int func_0217AF04(u8 *a, u16 key) { int i; Ent_0217AF04 *p; p = (Ent_0217AF04 *)(a+0x2e88); for(i=0;i<50;i++,p++) { if(p->f7 == 1 && p->p != 0 && key == func_0217AED4(p->p,(u8 *)p)) return p->f5; } return 0; }





int func_0217AF38(u16 a) { unsigned int v; v = (unsigned char)a; if ((u16)v >= 0x20) return 1; else return 0; }






int func_0217AF4C(char *a, u16 key)
{
    Ent_0217AF4C *p;
    int i;

    p = (Ent_0217AF4C *)(a + 0x2E88);
    for (i = 0; i < 50; i++, p++) {
        if (p->f7 == 1 && p->f0 != 0 && p->f0->f6c != 0
            && key == ((p->f0->f6b << 8) | (p->f6 + 0x20))) {
            if (p->f8 == 2 || p->f8 == 1 || (u8)(p->f9 + 0xff) <= 1)
                return 0;
            return 1;
        }
    }
    return 0;
}





void *func_0217AFB0(void **a,u8 *b,u8 *c) { u16 key; void *p; key = func_0217AED4(b,c); p = func_0216DE94((void *)func_02012964(((struct Obj19389 *)((u8 *)*a))->f8),key); if(p == 0) func_02034714(d_021807E0,0,d_021807E0); return p; }






Ent_0217AFE4 *func_0217AFE4(char *a, int b, Src *c, int d, int e, int *f)
{
    Ent_0217AFE4 *p;
    int i;
    int r;

    p = (Ent_0217AFE4 *)(a + 0x2E88);
    for (i = 0; i < 50; i++, p++) {
        if (p->f7 == 0) {
            p->f0 = b;
            p->f4 = c->f6;
            p->f5 = c->f7;
            p->f6 = d;
            p->f7 = 1;
            r = func_0217AED4((u8 *)b, (u8 *)p);
            r = func_0217AE40(a, ((int *)((struct Obj19390 *)a)->f0)[2], c->f6, r);
            if (e == 0)
                func_0216DAC8((unsigned int *)r, 1);
            *f = r;
            return p;
        }
    }
    func_02034714(d_021807E0, 0, d_021807E0);
    return 0;
}







void func_0217B054(u8 *w, Entry_0217B1D0 *ent_0217AE20, void *c)
{
    void **a = (void **)w;
    int b = (int)ent_0217AE20;
    void *h;
    void *r;

    h = func_0201210C(((void **)a[0])[3]);
    r = func_0217AFB0(a, (u8 *)b, c);
    if (h != 0 && r != 0)
        func_0217F958((char *)func_02188CE0(h), (u32)r);
    func_0216CF2C(r);
    MI_CpuFill8(c, 0, 12);
}







void func_0217B098(u8 *w, u32 a, u32 b, u32 c, Entry_0217B1D0 *ent_0217AE20)
{
    Obj_0217B054 *e = (Obj_0217B054 *)ent_0217AE20;
    int out;
    u8 buf[8];
    int i;

    if (e->f6c == 0)
        return;
    func_02087C6C(buf);
    for (i = 0; i < 5; i++) {
        if (e->slot[i] == 0 && e->tab[i].f1 == 1
            && func_0203EFC8(buf, (const u8 *)(&e->tab[i]), 6) != 0
            && func_0217B158((char *)w, (struct ent_0217AE20 *)e, (u8 *)(&e->tab[i])) != 0) {
            e->slot[i] = (u8 *)func_0217AFE4((char *)w, (int)e, (Src *)&e->tab[i], i, 0, &out);
            e->slot[i][8] = 1;
            func_0217AE38((char *)e->slot[i], 0);
            if (i == 0) {
                if (func_0217F894((void *)b, (char *)e) == 1)
                    func_0217F948((char *)c, out, 0);
                else if (func_0200EDC4((struct L0200EDC4 *)a, e->f5c) == 1)
                    func_0217F948((char *)c, out, 1);
            }
        }
    }
}






int func_0217B158(char *base, struct ent_0217AE20 *excl, u8 *mac)
{
    struct ent_0217AE20 *q = (struct ent_0217AE20 *)(base + 0x2910);
    int i;
    int j;

    for (i = 0; i < 10; i++, q++) {
        if (q == excl || q->on != 1) {
            continue;
        }
        for (j = 0; j < 5; j++) {
            if (q->s[j].f == 1 && memcmp(mac, q->s[j].mac, 6) == 0) {
                if (q->cnt != 0) {
                    q->cnt = 1;
                }
                return 0;
            }
        }
    }
    return 1;
}






int func_0217B1D0(struct obj *o, struct ent_0217B1D0 *e)
{
    int i;
    int v;
    int t;
    int r;

    for (i = 0; i < 5; i++) {
        v = e->p[i];
        if (v == 0 || e->s[i].f != 1) {
            continue;
        }
        if (memcmp(e->s[i].mac, (char *)o + 0x28a4, 6) != 0) {
            continue;
        }
        if (func_02012114((const struct Ctx *)o->in->fc) == 1) {
            t = func_02188CE0(func_0201210C((void *)o->in->fc));
            if (t != 0) {
                r = func_0217AED4((u8 *)e, (u8 *)v);
                r = (int)func_0216DE94((void *)func_02012964((const struct BigObj *)o->in->f8), r);
                if (r != 0) {
                    func_0217F93C(t, r);
                }
            }
        }
        memset((char *)o + 0x28a4, 0, 6);
        return 1;
    }
    return 0;
}






/*
 * Addresses are Black-image addresses.
 */
void func_0217B264(u8 *w, void *sys, void *q)
{
    int i;
    int flag;
    u32 a;
    u32 b;
    u32 c;
    Entry_0217B1D0 *e;
    u8 buf[6] = {0, 0, 0, 0, 0, 0};

    flag = 0;
    a = (u32)func_0200ED48(func_02012EBC(sys));
    b = func_0201283C(sys);
    c = func_02188CE0(q);
    func_02012964(sys);
    if (memcmp(buf, w + 0x28A4, 6) != 0) {
        flag = 1;
    }
    e = (Entry_0217B1D0 *)(w + 0x2910);
    for (i = 0; i < 10; i++, e++) {
        if (e->active == 1) {
            int cnt;
            int j;
            void *p;

            func_0217B3EC((char *)w, (char *)e);
            func_0217B098(w, a, b, c, e);
            if (flag == 1) {
                if (func_0217B1D0((struct obj *)w, (struct ent_0217B1D0 *)e) == 1) {
                    flag = 0;
                }
            }
            cnt = 0;
            for (j = 0; j < 5; j++) {
                p = e->slots[j];
                if (p != 0) {
                    if (func_0217B370((char *)w, p, (int)q) == 0) {
                        func_0217B054(w, e, p);
                        e->slots[j] = 0;
                        cnt++;
                    }
                } else {
                    cnt++;
                }
            }
            if (cnt >= 5 && e->h6C == 0) {
                MI_CpuFill8(e, 0, sizeof(Entry_0217B1D0));
            }
        }
    }
    MI_CpuFill8(w + 0x28A4, 0, 6);
}






int func_0217B370(char *base, unsigned char *p, int r2)
{
    int res = 1;
    fn_t fn;

    switch (p[0xa]) {
    case 0:
        fn = d_02180044[p[8]].f;
        break;
    case 1:
        fn = d_02180048[p[8]].f;
        break;
    case 2:
        fn = d_0218004C[p[8]].f;
        break;
    }
    if (fn != 0) {
        res = fn(base, p, r2, p + 0xb);
    }
    if (res == 1) {
        p[0xb] = 0;
        p[0xa] = p[0xa] + 1;
        if (p[0xa] > 2) {
            if (p[8] == 2) {
                return 0;
            }
            p[0xa] = 0;
            p[8] = p[9];
            p[9] = 0;
        }
    }
    return 1;
}






int func_0217B3EC(char *base, char *p)
{
    char *q = base + 0x2830;
    if (*(char * *)&((struct Obj07380 *)q)->f14 == p || *(char * *)&((struct Obj07380 *)q)->f18 == p ||
        *(char * *)&((struct Obj07380 *)q)->f1C == p || *(char * *)&((struct Obj07380 *)q)->f20 == p) {
        if (((struct Obj07379 *)p)->f6C == 0) {
            ((struct Obj07379 *)p)->f6C = 1;
        }
        return 1;
    }
    if (((struct Obj07379 *)p)->f6C == 0) {
        return 0;
    }
    ((struct Obj07379 *)p)->f6C -= 1;
    return 1;
}






void func_0217B440(char *base, int x, void *y)
{
    struct ent_0217B440 *q;
    int a;
    int b;
    int c;
    int r;
    int i;

    a = (int)func_0200ED48(func_02012EBC((struct Big *)x));
    b = func_0201283C((const struct BigObj *)x);
    c = func_02188CE0((u8 *)y);
    q = (struct ent_0217B440 *)(base + 0x2910);
    for (i = 0; i < 10; i++, q++) {
        if (q->on == 1 && q->p70 != 0) {
            r = (int)func_0217AFB0((void **)base, (u8 *)(*q->p70), (u8 *)q->p70);
            if (r != 0) {
                if (func_0217F894((void *)b, (char *)q) == 1) {
                    func_0217F948((char *)c, r, 0);
                } else if (func_0200EDC4((struct L0200EDC4 *)a, q->f5c) == 1) {
                    func_0217F948((char *)c, r, 1);
                }
            }
        }
    }
}






int func_0217B4C4(u8 *w, Msg *m)
{
    Entry_0217B370 *e;
    u8 *s;
    int t;
    int v;
    void *r;

    s = w + 0x2830;
    e = m->e;
    if (e->h6C == 0) {
        func_0217AE38((char *)m, 2);
        return 1;
    }
    if (!e->recs[m->idx].valid || m->b4 != e->recs[m->idx].b6) {
        func_0217AE38((char *)m, 2);
        return 1;
    }
    t = func_0217F858(e->bB);
    if (((struct Obj12518 *)s)->f58 == func_0217AED4((u8 *)m->e, (u8 *)m)) {
        func_0217AE38((char *)m, 3);
        return 1;
    }
    v = s[2];
    if (v != 0 && (v == t || (t == 0 && v == e->kind)) && m->idx == 0
        && func_0217F060(e->bB) > e->n) {
        r = func_0217AFB0((void **)w, (u8 *)m->e, (u8 *)m);
        if (func_0216D3CC((int)r) == 1) {
            func_0216D410(r, 0x31);
        }
    } else if (m->idx == 0 && e->n > 1) {
        r = func_0217AFB0((void **)w, (u8 *)m->e, (u8 *)m);
        if (func_0216D5A0(r) == 2) {
            func_0216E0E8((int)r, 0xF);
        }
    } else if (m->idx == 0 && e->n <= 1) {
        r = func_0217AFB0((void **)w, (u8 *)m->e, (u8 *)m);
        if (func_0216D5A0(r) == 0xF) {
            func_0216E0E8((int)r, 2);
        }
    }
    return 0;
}






int func_0217B5E0(char *base, int *p, int r2, unsigned char *state)
{
    s16 a[8];
    int h = (int)func_0217AFB0((void **)base, (u8 *)(*p), (u8 *)p);
    switch (*state) {
    case 0:
        if (func_0216D3CC(h) == 1) {
            func_0216D828((int)func_021A3074(func_02188CB4((void *)r2)), a);
            func_0216D828(h, a + 4);
            if (a[4] != a[0] || a[6] != a[2]) {
                func_0216D410((void *)h, 0x44);
                func_0216DAC8((unsigned int *)h, 0);
                *state = *state + 1;
            }
        }
        break;
    case 1:
        if (func_0216D454(h) == 1) { func_0216D480((char *)h); return 1; }
        break;
    }
    return 0;
}






int func_0217B66C(char *base, int *p, int r2, unsigned char *state)
{
    int h = (int)func_0217AFB0((void **)base, (u8 *)(*p), (u8 *)p);
    switch (*state) {
    case 0:
        if (func_0216D3CC(h) == 1) { func_0216D410((void *)h, 0x43); *state = *state + 1; }
        break;
    case 1:
        if (func_0216D454(h) == 1) { func_0216D480((char *)h); return 1; }
        break;
    }
    return 0;
}







int func_0217B6B4(char *base, int *p, int r2, unsigned char *state)
{
    struct S *q = (struct S *)(base + 0x2830);
    int h;
    u16 k;

    h = (int)func_0217AFB0((void **)base, (u8 *)(*p), (u8 *)p);
    switch (*state) {
    case 0:
        if (func_0216D3CC(h) == 1) {
            switch (func_0216D5F8(func_021A3074(func_02188CB4((void *)r2)))) {
            case 0:
                k = 1;
                break;
            case 1:
                k = 0;
                break;
            case 2:
                k = 3;
                break;
            case 3:
            default:
                k = 2;
                break;
            }
            func_0216D410((void *)h, k);
            *state = *state + 1;
        }
        break;
    case 1:
        if (func_0216D480((char *)h) == 1) {
            func_0216D548((u32 *)h, 8);
            *state = *state + 1;
        }
        break;
    case 2:
        if (q->f58 != func_0217AED4((u8 *)(*p), (u8 *)p)) {
            func_0216D550((u32 *)h, 8);
            return 1;
        }
        break;
    }
    return 0;
}






/*
 * lever: the bit at byte 7, bit 4 is a one-bit unsigned char field;
 * integer masks instead produce asrs/movs/ands and grow the body by 4 bytes.
 */
void func_0217B75C(char *p)
{
    int i;
    u8 *q;
    q = (u8 *)p + 0x2910;
    for (i = 0; i < 10; i++, q += 0x8c) {
        if (((Flags *)q)->flag == 1 && q[0x6a] != 0) {
            func_0217B798(p, q);
            q[0x6a] = 0;
        }
    }
}







void func_0217B798(char *base, u8 *p)
{
    u8 *q = (u8 *)base + 0x2830;
    u8 buf[6];

    func_021BBA70((struct Ctx *)base, (struct Src *)p, 0, 0);
    if (q[1] == 0 && q[0x71] == 0 && p[0xa] == 5 && ((struct Obj07381 *)p)->f6C != 0) {
        func_02087C6C(buf);
        if (memcmp(p, buf, 6) == 0 && func_0217B8F0(base, 6) == 1) {
            func_021734A8((u8 *)base, 2, (u32)p);
            func_021734A8((u8 *)base, 0, (u32)p);
        }
    }
}






/*
 * extent: follower 0217B83C already has its own source and shard.
 */
int func_0217B80C(int a, int b)
{
    char *p;
    char *q;
    int result;
    p = (char *)func_02026474((void *)func_02012138((const struct Ctx *)a));
    result = 0;
    q = p + 0x3548;
    if (((struct Obj12521 *)q)->f4 != 0 && ((struct Obj12521 *)q)->f0 == 0) result = func_0217413C(a, b, (unsigned char *)p);
    return result;
}






/*
 * Unlabelled leaf (a .word after a pool in the ov019 listing): returns 0.
 * Callee of ov021 func_0218A0E4, which passes (sys, pos).
 * Addresses are Black-image addresses.
 */
int func_0217B83C(void *sys, void *pos)
{
    return 0;
}







int func_0217B840(char *base, int r1)
{
    unsigned char *q = (unsigned char *)base + 0x2830;
    int res = 1;
    fn_t fn;

    switch (q[0x72]) {
    case 0:
        fn = d_02180074[q[1]].f;
        break;
    case 1:
        fn = d_02180078[q[1]].f;
        break;
    case 2:
        fn = d_0218007C[q[1]].f;
        break;
    }
    if (fn != 0) {
        res = fn(base, q, r1, q + 0x73);
    }
    if (res == 1) {
        q[0x73] = 0;
        q[0x72] = q[0x72] + 1;
        if (q[0x72] > 2) {
            q[0x72] = 0;
            q[0x70] = q[1];
            q[1] = q[0x71];
            q[0x71] = 0;
        }
    }
    return q[1];
}






int func_0217B8E4(char *p, int v)
{
    p[0x28a1] = v;
    return 1;
}






int func_0217B8F0(char *p, char v)
{
    if ((unsigned char)p[0x28a2] == 1) return func_0217B8E4(p, v);
    return 0;
}






int func_0217B908(int x)
{
    switch (x) {
    case 0: case 1: case 2: case 3:
        break;
    case 4: case 5:
        return 5;
    case 6: case 7:
        return 0x18;
    case 8: case 9:
        return 6;
    case 10: case 11:
        return 0x19;
    case 12: case 13:
        return 7;
    case 14: case 15:
        return 0x1a;
    case 16: case 17:
        return 8;
    case 18: case 19:
        return 0x1b;
    case 20: case 21:
        return 9;
    case 22: case 23:
        return 0x1c;
    }
    return 5;
}






int func_0217B974(int x)
{
    switch (x) {
    case 0: case 1: case 2: case 3:
    case 5: case 7: case 9: case 11: case 13: case 15:
    case 17: case 19: case 21:
        break;
    case 4: case 6: case 8: case 10: case 12: case 14:
    case 16: case 18: case 20: case 22:
        return 1;
    }
    return 0;
}






int func_0217B9BC(unsigned int x)
{
    if (x < 4 || x > 23) return 0;
    return 1;
}






/*
 * Return from the legacy void tail forwarder 0200BAC8 is used by this caller.
 */
void *func_0217B9CC(char *p)
{
    void *a;
    a = func_0200BAC8(func_02012EBC(((struct Obj19402 *)(*(char * *)&((struct Obj19401 *)p)->f0))->f8));
    if (func_0200BBA8(a) == 0) return 0;
    return func_0200BAF4((int)a, 65);
}






void func_0217B9F4(void *p)
{
    if (!p) func_02034714(d_021807E4, 0, d_021807E4);
    func_020307B0(p);
}






/*
 * Interface evidence: stub at 0201A364 moves r0 to r2, r1 to r0,
 * sets r1=0x69, then jumps through pool 02048F4C. Ilias owns it.
 */
void func_0217BA10(char *p, int x)
{
    func_0201A364(func_0217B908(x), (unsigned int)(*(void **)(p + 0x352c)));
    if (func_0217B974(x) == 1) func_0200AEE8(*(void **)(p + 0x352c), 13, 1);
    else func_0200AEE8(*(void **)(p + 0x352c), 13, 0);
}






int func_0217BA48(char *p, unsigned int *mask)
{
    void *party;
    *mask = 0;
    party = func_02012934(((struct Obj19403 *)(*(char * *)&((struct Obj09409 *)p)->f0))->f8);
    return func_0201A090(((struct Obj09409 *)p)->f352C, party, mask);
}






int func_0217BA6C(char *p, unsigned int *mask)
{
    void *party;
    int result;
    party = func_0217B9CC(p);
    *mask = 0;
    if (party != 0) {
        result = func_0201A090(((struct Obj09409 *)p)->f352C, party, mask);
        func_0217B9F4(party);
    } else {
        *mask = -1;
        result = 5;
    }
    return result;
}







int func_0217BAA8(int a, int b, int *p, int *q)
{
    int r, t;
    *p = 0;
    *q = 0;
    if (func_0217B9BC(b) == 0)
        return 1;
    func_0217BA10((char *)a, b);
    r = func_0217BA48((char *)a, (unsigned int *)p);
    t = func_0217BA6C((char *)a, (unsigned int *)q);
    if (r == 0 || t == 0)
        return 1;
    return 0;
}





void func_0217BAF0(char *p, int x, unsigned int v)
{
    p[0x3563] = v;
    func_021A2E44(x, v);
}





int func_0217BB04(char *p)
{
    if (func_0200FB24() != 0) {
        func_0217B8E4(p, 1);
        return 1;
    }
    return 0;
}





int func_0217BB20(char *p)
{
    if (func_0217BB04(p) == 1) {
        func_0217B8E4(p, 50);
        return 1;
    }
    return 0;
}



int func_0217BB3C(u8 *ctx, u8 *obj, int a)
{
    func_02173524((Work_0217AE20 *)ctx, obj + 0x14);
    func_021734A8(ctx, 4, 0);
    func_0217F074(ctx);
    func_0217BAF0((char *)ctx, a, 0);
    ctx[0x282E] = 0;
    return 1;
}



int func_0217BB70(u8 *w, u8 *obj, void *q)
{
    void *a;
    void *b;
    void *r;
    u16 t;
    u16 n;
    s16 x;
    s16 y;
    s16 z;

    a = func_02188CB4(q);
    b = func_02188C7C(q);
    if (func_0217BB04((char *)w) == 1) {
        return 1;
    }
    if (func_02172D68(w) == 1) {
        return 0;
    }
    if (obj[0x71] != 0) {
        return 1;
    }
    if (func_0203D1B4() > 1) {
        func_02172D20(w);
        return 0;
    }
    if (func_020362DC() & 1) {
        func_021A3460((u32)a, (u32)(&x), (u32)(&y), (u32)(&z));
        r = func_0216DDC0((u32)b, x, z, 0);
        if (r == 0) {
            return 0;
        }
        t = func_0216D588(r);
        if (func_0217AF38(t) == 0 || func_0217AF4C((char *)w, t) == 0) {
            return 0;
        }
        ((struct Obj12522 *)obj)->f58 = t;
        n = func_0217AEFC(t);
        func_021734A8(w, 0, (u32)(&((Work_0217BB70 *)w)->entries[n]));
        if (func_0217AEE8(t) == 0) {
            if (((Work_0217BB70 *)w)->entries[n].bB == 0) {
                func_021734A8(w, 1, (u32)(&((Work_0217BB70 *)w)->entries[n]));
                func_0217B8E4((char *)w, 5);
            } else {
                func_0217B8E4((char *)w, 0xB);
            }
        } else {
            func_0217B8E4((char *)w, 0xC);
        }
        func_0217BAF0((char *)w, (int)q, 1);
        return 1;
    }
    if (w[0x282E] == 1) {
        func_0217B8E4((char *)w, 4);
        return 1;
    }
    if (func_0217F7E4((u32)q) == 1) {
        if (((struct Obj07382 *)w)->f3564 == 1) {
            func_0217BAF0((char *)w, (int)q, 1);
            func_0217B8E4((char *)w, 3);
        }
    } else {
        ((struct Obj07382 *)w)->f3564 = 1;
    }
    return 0;
}



int func_0217BCDC(int *a, u8 *b, int c, u8 *d)
{
    switch (*d) {
    case 0:
        func_0217BAF0((char *)a, c, 1);
        (*d)++;
        break;
    case 1:
        if (func_0217F1EC((u8 *)a) == 1) {
            func_0217F074(a);
            (*d)++;
        }
        break;
    case 2:
        if (func_0200FB24() != 0) {
            func_02012124((struct Ctx *)(*(int *)(a[0] + 0xc)), 1);
            return 0;
        }
        func_02172D38((u8 *)a);
        (*d)++;
        break;
    case 3:
        if (func_02172D68((u8 *)a) == 0)
            (*d)++;
        break;
    case 4:
        func_02173420(a);
        func_02173524((void *)a, b + 0x14);
        func_02172D50((u8 *)a);
        (*d)++;
        break;
    case 5:
        if (func_02172D68((u8 *)a) == 0)
            (*d)++;
        break;
    default:
        func_0217B8E4((char *)a, 0);
        return 1;
    }
    return 0;
}
