/*
 * file:     unit_021F5260.c
 * unit:     yes
 * function: func_021F5260, func_021F529C, func_021F52D8, func_021F536C, func_021F54A0, func_021F54C0, func_021F54E0
 * address:  0x021F5260
 * region:   ov075
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_021F5518 0x021F5518 thumb ov075
 *   func_0207D704  0x0207D704  arm
 *   func_0207DA8C  0x0207DA8C  arm
 *   func_0207D7C4  0x0207D7C4  arm
 *   d_020A1EB8     0x020A1EB8  data  a4
 *   d_021F55F8     0x021F55F8  data  ov075  a4
 *   func_020124E4  0x020124E4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_0204047C  0x0204047C  arm
 *   func_021899F0  0x021899F0  thumb  ov021
 *   func_02080C44  0x02080C44  arm
 *   func_02080B98  0x02080B98  arm
 *   func_02080294  0x02080294  arm
 *   func_02040588  0x02040588  arm
 *   func_021899F8  0x021899F8  thumb  ov021
 *   func_02189A08  0x02189A08  thumb  ov021
 *   func_021CF560  0x021CF560  thumb  ov021
 *   func_02012374  0x02012374  thumb
 *   func_0204E720  0x0204E720  arm
 *   func_0204E804  0x0204E804  arm
 *   func_0208068C 0x0208068C arm
 *   func_020056A0 0x020056A0 thumb
 *   func_02030EAC 0x02030EAC arm
 */
#include "../../matched/include/Obj13214.h"
#include "../../matched/include/Obj20793.h"

struct Desc;
struct Obj;
struct Work;
struct Ctx;
struct Evt;
struct Node;
typedef unsigned int u32;

typedef struct Vec { int x,y,z; } Vec;

typedef unsigned short u16;

typedef short          s16;

struct V { int x; int y; int z; };

typedef unsigned char  u8;

typedef struct Work {
    int f0;
    u32 f4;
    int f8;
    u32 fC;
    int f10;
    u32 f14;
    u8 pad18[0xC];
    u32 f24;
    int (*f28)(void *sys);
} Work;

typedef signed int     s32;

typedef enum { BANK_NONE, BANK_A=1, BANK_B=2, BANK_C=4 } Bank;

extern struct Desc *func_020122C0(void *, void *, void *, u32);
extern void *func_020124E8(struct Obj *);
extern void func_02082BCC(void *,int,u32);
extern int func_021F5518(void *task, int *st, struct Work *w);
extern void func_0207D704(int a, int b, int c, int d, int e, int f, int g, int h);
extern void func_0207DA8C(void);
extern void func_0207D7C4(struct V *a, struct V *b, struct V *c, int d, int e);
extern void *func_020124E4(struct Obj *p);
extern void *func_0201210C(const struct Ctx *p);
extern void func_0204047C(int idx, u16 val);
extern u32 func_021899F0(u8 *p);
extern u16 func_02080C44(void);
extern void func_02080B98(void);
extern void func_02080294(u32 bank);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_021899F8(u8 *p, u32 v);
extern int func_02189A08(unsigned char *p);
extern u32 func_021CF560(u32 *p);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern int func_0204E804(void);
extern void func_0208068C(int);
extern void *func_020056A0(u32,u32,u32);
extern void func_02030EAC(struct Node *n);
void *func_021F5260(void *a, Vec *src, u32 b, u32 c);
void *func_021F529C(void *a,Vec *src,u32 b,u32 c);
void func_021F52D8(u32 *p);
int func_021F536C(void *task, int *st, Work *w);
void func_021F54A0(char *p);
void func_021F54C0(void *p,int *flag);
u32 func_021F54E0(void);
extern const s16 d_020A1EB8[];
extern struct V d_021F55F8;

void *func_021F5260(void *a, Vec *src, u32 b, u32 c) {
    struct Desc *h;
    char *w;
    h = func_020122C0(a,0,(void *)func_021F536C,48);
    w = func_020124E8((struct Obj *)h);
    func_02082BCC(w,0,48);
    *(Vec *)(w+24) = *src;
    *(u32 *)(w+40) = b;
    *(u32 *)(w+44) = c;
    return h;
}

void *func_021F529C(void *a,Vec *src,u32 b,u32 c) {
    void *h;
    char *w;
    h=func_020122C0(a,0,(void *)func_021F5518,0x30);
    w=func_020124E8(h);
    func_02082BCC(w,0,0x30);
    *(Vec *)(w+24)=*src;
    ((struct Obj13214 *)w)->f28=b;
    ((struct Obj13214 *)w)->f2C=c;
    return h;
}


static inline void G3_Perspective(int fs, int fc, int aspect, int n, int f, void *mtx)
{
    func_0207D704(fs, fc, aspect, n, f, 0x1000, 1, (int)mtx);
}


void func_021F52D8(u32 *p)
{
    struct V a;

    G3_Perspective(d_020A1EB8[6], d_020A1EB8[7], 0x1555, 0x1000, 0x400000, 0);
    func_0207DA8C();
    a = d_021F55F8;
    {
        struct V c = {0, 0, 0};
        struct V b;

        b = *(struct V *)(p + 6);
        func_0207D7C4(&b, &a, &c, 1, 0);
    }
    *(volatile u32 *)0x040004A8 = ((u16)p[5] & 0x1FFFFFFF) | 0x5ED00000;
    ((void (*)(u32))p[11])(p[9]);
}


/*
 * Seven-state proc: ov073 func_021F53C8's fade states 0-2, then the same
 * states as func_021F5518 (its 0-3 are states 3-6 here).  EXACT* only
 * because the listing extent holds the 2-byte alignment pad at 0x021F549E.
 */
int func_021F536C(void *task, int *st, Work *w)
{
    void *t;
    void *v;
    u32 bank;
    int r;

    t = func_020124E4(task);
    v = func_0201210C(t);
    switch (*st) {
    case 0:
        func_0204E720(4, 0, 0x10, 0);
        *st = *st + 1;
    case 1:
        if (func_0204E804() == 0) {
            func_0204E720(4, 0x10, 0, 0);
            *st = *st + 1;
        }
        break;
    case 2:
        if (func_0204E804() == 0) {
            w->f0 = w->f0 + 1;
            if (w->f0 < 2) {
                func_0204E720(4, 0, 0x10, 0);
                *st = 1;
            } else {
                *st = *st + 1;
            }
        }
        break;
    case 3:
        func_021F54A0((char *)w);
        *st = *st + 1;
        break;
    case 4:
        if (w->f10 != 0) {
            func_0204047C(0, 0);
            func_0204047C(2, 3);
            w->fC = func_021899F0((u8 *)v);
            bank = func_02080C44();
            w->f4 = bank;
            w->f8 = 0;
            if ((bank & 8) == 0) {
                w->f4 = bank | 8;
                w->f8 = 1;
            }
            func_02080B98();
            func_02080294(w->f4);
            w->f14 = func_021F54E0();
            *st = *st + 1;
        }
        break;
    case 5:
        func_02040588(2, 1);
        func_02040588(0, 1);
        func_021899F8((u8 *)v, 2);
        r = w->f28(t);
        w->f24 = func_021CF560((u32 *)func_02189A08((unsigned char *)((int)v)));
        func_02012374(task, (struct Evt **)r);
        *st = *st + 1;
        break;
    case 6:
        if (w->f8 == 1) {
            w->f4 &= ~8;
            func_02080294(w->f4);
        }
        func_021899F8((u8 *)v, w->fC);
        return 1;
    }
    return 0;
}

void func_021F54A0(char *p) { ((struct Obj20793 *)p)->f10=0; func_0208068C(8); func_020056A0((u32)func_021F54C0,(u32)(p+16),0); }

void func_021F54C0(void *p,int *flag) { *(unsigned int *)0x04000064=0x81330010; func_02030EAC(p); if(flag) *flag=1; }

/*
 * lever: enum Bank preserves the cumulative OR tests; u32 folds the final test.
 */
u32 func_021F54E0(void) {
    Bank v;
    u32 n;
    v=func_02080C44(); n=0;
    v |= 4; if(v) n+=0x20000;
    v |= 2; if(v) n+=0x20000;
    v |= 1; if(v) n+=0x20000;
    return 0x20000000 | ((u16)(n>>3));
}
