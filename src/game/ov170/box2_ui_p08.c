/*
 * file:     box2_ui_p08.c
 * unit:     yes
 * function: func_021EEC38, func_021EEC50, func_021EEC6C, func_021EECB0, func_021EECE4, func_021EEDB8, func_021EEDD0, func_021EEDE0, func_021EEE7C, func_021EEE94, func_021EEEA4, func_021EEF50, func_021EEF68, func_021EEF74, func_021EEFA4, func_021EF048, func_021EF0A8, func_021EF108, func_021EF170, func_021EF180, func_021EF194, func_021EF1A4, func_021EF1B4, func_021EF1C4, func_021EF1D4, func_021EF1FC, func_021EF224, func_021EF248, func_021EF264, func_021EF274, func_021EF310, func_021EF31C, func_021EF32C, func_021EF33C, func_021EF34C, func_021EF35C, func_021EF36C, func_021EF3A0, func_021EF3D8, func_021EF3EC, func_021EF400, func_021EF45C, func_021EF480, func_021EF4A4, func_021EF4C0, func_021EF4E4, func_021EF508, func_021EF534, func_021EF57C, func_021EF5C4, func_021EF5E8, func_021EF60C, func_021EF630, func_021EF660, func_021EF670, func_021EF680, func_021EF68C, func_021EF69C, func_021EF6A8, func_021EF6CC, func_021EF6E0, func_021EF738, func_021EF75C
 * address:  0x021EEC38
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021DC9B4  0x021DC9B4  thumb  ov170
 *   func_021E066C  0x021E066C  thumb  ov170
 *   func_021EE408  0x021EE408  thumb  ov170
 *   func_021EE008 0x021EE008 thumb ov170
 *   func_020260E0 0x020260E0 thumb
 *   func_02025DE8 0x02025DE8 thumb
 *   func_020260E4 0x020260E4 thumb
 *   func_020362DC 0x020362DC arm
 *   func_020355D8 0x020355D8 arm
 *   func_0203633C 0x0203633C arm
 *   func_021DD238 0x021DD238 thumb
 *   func_0202616C  0x0202616C  thumb
 *   func_02030734 0x02030734 arm
 *   d_021F1418 0x021F1418 data a1
 *   _u32_div_f 0x0209C2B0 arm
 *   d_021F0020 0x021F0020 data a4
 *   func_02035C08 0x02035C08 arm
 *   func_02035BA4 0x02035BA4 arm
 *   func_02035D40 0x02035D40 arm
 *   g_021F0DCC  0x021F0DCC  data  ov170
 *   d_021F0F40 0x021F0F40 data
 *   d_021F0040 0x021F0040 data
 *   func_02035CB8 0x02035CB8 arm
 *   d_021F0034 0x021F0034 data a1
 *   d_021F0024 0x021F0024 data a1
 *   d_021F002C 0x021F002C data a4
 *   d_021F0F58 0x021F0F58 data
 *   func_021EB744 0x021EB744 thumb ov170
 *   func_021EB79C 0x021EB79C thumb ov170
 *   func_021EB7C8 0x021EB7C8 thumb ov170
 *   func_021EB95C 0x021EB95C thumb ov170
 *   func_0202C9B4 0x0202C9B4 thumb
 *   func_0202CA3C 0x0202CA3C thumb
 *   func_0202CA0C  0x0202CA0C  thumb  ov170
 *   func_0202CF98 0x0202CF98 thumb
 *   func_0202CDD4 0x0202CDD4 thumb
 *   func_021EC8E4 0x021EC8E4 thumb
 *   func_0202CC70 0x0202CC70 thumb
 *   func_0202CB4C 0x0202CB4C thumb
 *   func_0202CD64 0x0202CD64 thumb
 *   func_021ED8A4 0x021ED8A4 thumb ov170
 */
#include "../../matched/include/Obj12185.h"
#include "../../matched/include/Obj18532.h"
#include "../../matched/include/Obj07241.h"
#include "../../matched/include/Obj12186.h"
#include "../../matched/include/Obj12187.h"
#include "../../matched/include/Obj12188.h"
#include "../../matched/include/Obj12189.h"
#include "../../matched/include/Obj24041.h"
#include "../../matched/include/Obj01558.h"
#include "../../matched/include/Obj24042.h"
#include "../../matched/include/Obj18533.h"
#include "../../matched/include/Obj00000.h"
#include "../../matched/include/Obj24043.h"
#include "../../matched/include/Obj24044.h"
#include "../../matched/include/Obj24045.h"
#include "../../matched/include/Obj18534.h"
#include "../../matched/include/Obj18535.h"
#include "../../matched/include/Obj18536.h"
#include "../../matched/include/Obj18537.h"

struct Sound;
struct WinMgr;
struct Ctx;
typedef unsigned char  u8;

typedef unsigned int u32;

typedef struct {
    unsigned char x,y,dx,dy;
    unsigned negx:1;
    unsigned negy:1;
    unsigned steps:30;
} Motion;

typedef unsigned short u16;

typedef struct { unsigned char a,b,c,d; } Bytes;

typedef struct { Bytes first, second; } Object;

typedef signed char s8;

extern void func_021DC9B4(char *p, int v);
extern int func_021E066C(char *p);
extern void func_020260E4(struct Sound *obj, u8 sel);
extern void func_021EE408(char *, int);
extern void func_021EE008(char *, int, int);
extern u8 func_020260E0(struct Sound *obj);
extern int func_02025DE8(struct Sound *obj);
extern u32 func_020362DC(void);
extern void func_020355D8(u8 v);
extern unsigned int func_0203633C(void);
extern void func_021DD238(char *p);
extern void *func_0202616C(void **obj, u32 idx);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int func_02035C08(const void *);
extern int func_02035BA4(const void *);
extern u32 func_02035D40(struct Ctx *ctx, u32 a, u32 b);
extern unsigned func_02035CB8(unsigned *outA, unsigned *outB);
extern struct WinMgr *func_0202C9B4(u32 a0, u32 a1, u32 heap);
extern void func_0202CA3C(struct WinMgr *mgr, u32 idx, u32 bg, u32 w, u32 h);
extern void func_021EB744(char *);
extern void func_021EB79C(unsigned char *p);
extern void func_021EB7C8(char *);
extern void func_021EB95C(char *);
extern void func_0202CA0C(struct WinMgr *mgr);
extern void func_0202CAE4(struct WinMgr *mgr, u32 idx, u32 arc, u32 member, u32 alloc);
extern void func_0202CB4C(struct WinMgr *mgr, u32 idx, s8 x, s8 y);
extern void func_0202CF98(struct WinMgr *mgr, u32 idx, s8 *x, s8 *y);
extern void func_0202CD64(struct WinMgr *mgr, u32 idx, s8 dx, s8 dy, u8 frames);
extern u32 func_0202CDD4(struct WinMgr *mgr, u32 idx);
extern void func_021EC8E4(char *p);
extern void func_0202CC70(struct WinMgr *mgr, u32 idx);
extern u32 func_0204162C(int channel);
extern void func_0202CAC4(struct WinMgr *mgr, u32 idx, const void *src);
extern void func_021ED8A4(char *);
void func_021EEC38(char *p, int a, int b);
void func_021EEC50(char *p, unsigned int a);
void func_021EEC6C(char *p, int k, int v);
void func_021EECB0(char *p, int a);
unsigned func_021EECE4(char *p);
void func_021EEDB8(char *p, int a, int b);
void func_021EEDD0(void *a, int tag);
unsigned func_021EEDE0(char *p);
void func_021EEE7C(char *p, int a, int b);
void func_021EEE94(void *a, int tag);
unsigned func_021EEEA4(char *p);
void func_021EEF50(char *p, int a, int b);
void func_021EEF68(char *a, int b);
void func_021EEF74(char *q, int a, int b);
void func_021EEFA4(char *p, unsigned char x, unsigned char y, unsigned char tx, unsigned char ty);
int func_021EF048(const char *p, unsigned n);
int func_021EF0A8(const char *p, unsigned n);
int func_021EF108(const char *p, unsigned n, int a, int b);
u32 func_021EF170(void);
int func_021EF180(int a, int b);
u32 func_021EF194(void);
u32 func_021EF1A4(void);
int func_021EF1B4(void);
int func_021EF1C4(void);
int func_021EF1D4(unsigned *a, unsigned *b);
int func_021EF1FC(unsigned*a,unsigned*b);
int func_021EF224(int a, int b);
int func_021EF248(void);
int func_021EF264(void);
void func_021EF274(char *p);
void func_021EF310(char *p);
void func_021EF31C(struct WinMgr *mgr, int a1, int a2);
void func_021EF32C(struct WinMgr *mgr);
void func_021EF33C(struct WinMgr *mgr);
void func_021EF34C(struct WinMgr *mgr);
void func_021EF35C(struct WinMgr *mgr);
void func_021EF36C(struct WinMgr *mgr);
void func_021EF3A0(struct WinMgr *mgr);
void func_021EF3D8(struct WinMgr *mgr);
void func_021EF3EC(struct WinMgr *mgr);
int func_021EF400(unsigned char *p);
int func_021EF45C(struct WinMgr *mgr);
int func_021EF480(struct WinMgr *mgr);
int func_021EF4A4(struct WinMgr *mgr);
void func_021EF4C0(struct WinMgr *mgr);
void func_021EF4E4(struct WinMgr *mgr);
void func_021EF508(struct WinMgr *mgr);
void func_021EF534(struct WinMgr *mgr);
void func_021EF57C(struct WinMgr *mgr);
int func_021EF5C4(struct WinMgr *mgr);
int func_021EF5E8(struct WinMgr *mgr);
int func_021EF60C(struct WinMgr *mgr);
void func_021EF630(char *p);
void func_021EF660(struct WinMgr *mgr);
void func_021EF670(char *p);
void func_021EF680(char *p);
void func_021EF68C(char *p);
void func_021EF69C(char *p);
void func_021EF6A8(struct WinMgr *mgr);
void func_021EF6CC(struct WinMgr *mgr);
unsigned func_021EF6E0(char *p);
void func_021EF738(struct WinMgr *mgr);
void func_021EF75C(struct WinMgr *mgr);
extern const char d_021F1418[];
extern const Bytes d_021F0020;
extern const unsigned char d_021F0F40[];
extern const unsigned char d_021F0040[];
extern const unsigned char d_021F0034[];
extern const u8 d_021F0024[];
extern const unsigned char d_021F002C[];
extern const unsigned char d_021F0F58[];


/*
 * Release the child at +0x2c and reset its field +0x5c to the handler.
 */
void func_021EEC38(char *p, int a, int b)
{
    func_021EEF74(*(char * *)&((struct Obj12185 *)p)->f2C, a, b);
    func_021DC9B4(((struct Obj12185 *)p)->f2C, (int)((void *)&func_021E066C));
}

/*
 * Twin of func_021EEC1C.
 */
void func_021EEC50(char *p, unsigned int a)
{
    func_020260E4((struct Sound *)(*(int *)(((struct Obj18532 *)p)->f2C + 0x70)), (unsigned char)a);
    func_021EE408(p, a);
}

#define WORK(p) (*(char **)((p)+0x2c))

void func_021EEC6C(char *p, int k, int v)
{
    if (k >= 1 && k <= 4) func_021EE008(p, k-1, 1);
    else func_021EE008(p, 0, 0);
    func_021EEF74(WORK(p), k, v);
    func_021DC9B4(WORK(p), (int)func_021E066C);
    *(int *)(WORK(p)+0xa168) = k;
}

void func_021EECB0(char *p, int a)
{
    int v;
    if (a == 0 || (unsigned)(a - 5) <= 1) {
        func_020260E4((struct Sound *)(*(int *)(((struct Obj07241 *)p)->f2C + 0x70)),
                      *(int *)(((struct Obj07241 *)p)->f2C + 0xA168) & 0xff);
        v = *(int *)(((struct Obj07241 *)p)->f2C + 0xA168);
    } else {
        func_021EE408(p, a);
        v = a;
    }
    *(int *)(((struct Obj07241 *)p)->f2C + 0xA168) = v;
}

#undef WORK

#define WORK(p) (*(char **)((p) + 0x2C))

#define OBJ(p) (*(void **)(WORK(p) + 0x70))


unsigned func_021EECE4(char *p)
{
    unsigned char sel = func_020260E0(OBJ(p));
    unsigned r = func_02025DE8(OBJ(p));
    if (func_021EF5E8(*(struct WinMgr **)(WORK(p) + 0x74)) == 0) {
        if (r >= 0x24 && r <= 0x27) {
            func_020260E4(OBJ(p), sel);
            func_021EE408(p, sel);
            return -1;
        }
        if (func_020362DC() & 0x400) {
            func_020355D8(0);
            return 0x22;
        }
        if (r == 0x22) {
            func_020355D8(1);
            return 0x22;
        }
        if (r == 0x23) {
            func_020260E4(OBJ(p), sel);
            return 0x23;
        }
    } else if (r == 0x1E || r - 0x21 <= 2) {
        func_020260E4(OBJ(p), sel);
        func_021EE408(p, sel);
        return -1;
    }
    if (r == -1) {
        if (func_0203633C() & 0x200) {
            func_021DD238(p);
            return 0x1F;
        }
        if (func_0203633C() & 0x100) {
            func_021DD238(p);
            return 0x20;
        }
    }
    return r;
}


void func_021EEDB8(char *p, int a, int b)
{
    func_021EEF74(*(char * *)&((struct Obj12186 *)p)->f2C, a, b);
    func_021DC9B4(((struct Obj12186 *)p)->f2C, (int)((void *)&func_021E066C));
}


/*
 * Ignore the two known tags, otherwise run the update.
 */
void func_021EEDD0(void *a, int tag)
{
    if (tag != 0x22 && tag != 0x23)
        func_021EE408(a, tag);
}

#undef WORK

#define WORK(p) (*(char **)((p) + 0x2C))


unsigned func_021EEDE0(char *p)
{
    unsigned char sel = func_020260E0(*(void **)(WORK(p) + 0x70));
    unsigned r = func_02025DE8(*(void **)(WORK(p) + 0x70));

    if (func_021EF5E8(*(struct WinMgr **)(WORK(p) + 0x74)) == 0) {
        if (r >= 9 && r <= 12) {
            func_020260E4(*(void **)(WORK(p) + 0x70), sel);
            func_021EE408(p, sel);
            return -1;
        }
        if (func_020362DC() & 0x400) {
            func_020355D8(0);
            return 7;
        }
        if (r == 7) {
            func_020355D8(1);
            return 7;
        }
        if (r == 8) {
            func_020260E4(*(void **)(WORK(p) + 0x70), sel);
            return 8;
        }
    } else if (r - 6 <= 2) {
        func_020260E4(*(void **)(WORK(p) + 0x70), sel);
        func_021EE408(p, sel);
        return -1;
    }
    return r;
}

/*
 * Detach the sub-object and seat the reset handler.
 */
void func_021EEE7C(char *p, int a, int b)
{
    func_021EEF74(*(char * *)&((struct Obj12187 *)p)->f2C, a, b);
    func_021DC9B4(*(char * *)&((struct Obj12187 *)p)->f2C, (int)func_021E066C);
}


void func_021EEE94(void *a, int tag)
{
    if (tag != 0x7 && tag != 0x8)
        func_021EE408(a, tag);
}

#undef WORK
#define WORK(p) (*(char **)((p)+0x2c))

#undef OBJ
#define OBJ(p) (*(void **)(WORK(p)+0x70))

unsigned func_021EEEA4(char *p)
{
    unsigned char sel=func_020260E0(OBJ(p));
    unsigned r=func_02025DE8(OBJ(p));
    if(func_021EF5E8(*(struct WinMgr **)(WORK(p)+0x74))==0) {
        if(r>=0x22 && r<=0x23) {
            func_020260E4(OBJ(p),sel);
            func_021EE408(p,sel);
            return -1;
        }
        if(r==0x21) {
            func_020260E4(OBJ(p),sel);
            return 0x21;
        }
    } else if(r==0x1e || r==0x21) {
        func_020260E4(OBJ(p),sel);
        func_021EE408(p,sel);
        return -1;
    }
    if(r==-1) {
        if(func_0203633C()&0x200) { func_021DD238(p); return 0x1f; }
        if(func_0203633C()&0x100) { func_021DD238(p); return 0x20; }
    }
    return r;
}

void func_021EEF50(char *p, int a, int b)
{
    func_021EEF74(*(char * *)&((struct Obj12188 *)p)->f2C, a, b);
    func_021DC9B4(*(char * *)&((struct Obj12188 *)p)->f2C, (int)func_021E066C);
}

/*
 * Run the attached handler unless the key is 0x21.
 */
void func_021EEF68(char *a, int b)
{
    if (b != 0x21)
        func_021EE408(a, b);
}

/*
 * Pull the two tag records through the p+0x70 lookup and hand both
 * pairs to the 0x54/0x10 emitter.
 */
void func_021EEF74(char *q, int a, int b)
{
    unsigned char *x = func_0202616C((void **)(((struct Obj12189 *)q)->f70), a);
    unsigned char *y = func_0202616C((void **)(((struct Obj12189 *)q)->f70), b);
    func_021EEFA4(q, x[0], x[1], y[0], y[1]);
}

void func_021EEFA4(char *p, unsigned char x, unsigned char y, unsigned char tx, unsigned char ty)
{
    Motion *s;
    s=func_02030734(0x4c,8,0,d_021F1418,0x98f);
    s->steps=4;
    s->x=x;
    s->y=y;
    if(x>=tx) { s->dx=x-tx; s->negx=0; }
    else { s->dx=tx-x; s->negx=1; }
    if(y>=ty) { s->dy=y-ty; s->negy=0; }
    else { s->dy=ty-y; s->negy=1; }
    s->dx=((unsigned)(s->dx<<8)/(unsigned)s->steps)>>8;
    s->dy=((unsigned)(s->dy<<8)/(unsigned)s->steps)>>8;
    *(Motion * *)&((struct Obj24041 *)p)->f60=s;
}

int func_021EF048(const char *p, unsigned n)
{
    Object obj;
    unsigned i;
    obj.second=d_021F0020;
    for(i=0;i<n;i++) {
        obj.first=*(Bytes *)(p+i*12+8);
        if(func_02035C08(&obj)!=-1) return i;
    }
    return -1;
}

int func_021EF0A8(const char *p, unsigned n)
{
    Object obj;
    unsigned i;
    obj.second=d_021F0020;
    for(i=0;i<n;i++) {
        obj.first=*(Bytes *)(p+i*12+8);
        if(func_02035BA4(&obj)!=-1) return i;
    }
    return -1;
}

int func_021EF108(const char *p, unsigned n, int a, int b)
{
    Object obj;
    unsigned i;
    obj.second=d_021F0020;
    for(i=0;i<n;i++) {
        obj.first=*(Bytes *)(p+i*12+8);
        if(func_02035D40((struct Ctx *)(&obj),a,b)!=-1) return i;
    }
    return -1;
}

/*
 * Register a table with the loader.
 */
u32 func_021EF170(void)
{
    return func_021EF048((void *)0x021F0DCC, 0x1e);
}

int func_021EF180(int a, int b)
{
    return func_021EF108((char *)0x021F0DCC, 0x1e, a, b);
}

u32 func_021EF194(void)
{
    return func_021EF048((void *)0x021F0574, 6);
}

u32 func_021EF1A4(void)
{
    return func_021EF048((void *)0x021F1354, 6);
}


int func_021EF1B4(void)
{
    return func_021EF0A8((const char *)d_021F0F40, 2);
}


int func_021EF1C4(void)
{
    return func_02035BA4(d_021F0040);
}


int func_021EF1D4(unsigned *a, unsigned *b)
{
    if (func_02035BA4(d_021F0034) != -1) {
        func_02035CB8(a, b);
        return 1;
    }
    return 0;
}

int func_021EF1FC(unsigned*a,unsigned*b){if(func_02035BA4(d_021F0024)!=-1){func_02035CB8(a,b);return 1;}return 0;}

/*
 * Query the 0x021F1174 table with index 4; -1 becomes 0xff,
 *   otherwise the answer plus 0x24.  The -1 arm must be the branch target.
 */
int func_021EF224(int a, int b)
{
    int v = func_021EF108((char *)0x021F1174, 4, a, b);
    if (v != -1)
        return v + 0x24;
    return 0xff;
}


int func_021EF248(void)
{
    if (func_02035BA4(d_021F002C) != -1)
        return 1;
    return 0;
}


int func_021EF264(void)
{
    return func_021EF0A8((const char *)d_021F0F58, 1);
}

#define MGR(w) (*(struct WinMgr **)((w)+0x74))

/*
 * trailing: two zero alignment bytes at 0x021EF30E.
 */
void func_021EF274(char *p)
{
    char *w=*(char * *)&((struct Obj01558 *)p)->f2C;
    MGR(w)=func_0202C9B4(2,12,0x4c);
    func_021EB744(w);
    func_021EF630(p);
    func_021EB79C((unsigned char *)p);
    func_021EB7C8(p);
    func_0202CA3C(MGR(w),8,1,11,15);
    if(((struct Obj24042 *)(*(char * *)&((struct Obj01558 *)p)->f0))->f24==4) func_021EF31C(MGR(w),8,8);
    else func_021EF31C(MGR(w),8,9);
    func_0202CA3C(MGR(w),7,1,11,15);
    func_021EF31C(MGR(w),7,10);
    func_021EB95C(p);
    func_0202CA3C(MGR(w),9,1,11,21);
    func_021EF31C(MGR(w),9,11);
    func_021EF4C0(MGR(w));
}


/*
 * Forward the word at +0x74.
 */
void func_021EF310(char *p)
{
    func_0202CA0C(*(struct WinMgr * *)&((struct Obj18533 *)p)->f74);
}


/*
 * Forward the three arguments with a literal third argument, in place of the fourth.
 */
void func_021EF31C(struct WinMgr *mgr, int a1, int a2)
{
    func_0202CAE4(mgr, a1, 0x74, a2, 1);
}


/*
 * Forward a plus constants to func_0202CB4C.
 */
void func_021EF32C(struct WinMgr *mgr)
{
    func_0202CB4C(mgr, 8, 2, 6);
}


void func_021EF33C(struct WinMgr *mgr)
{
    func_0202CB4C(mgr, 8, 0x15, 6);
}


void func_021EF34C(struct WinMgr *mgr)
{
    func_0202CB4C(mgr, 8, 2, 0x18);
}


void func_021EF35C(struct WinMgr *mgr)
{
    func_0202CB4C(mgr, 8, 0x15, 0x18);
}

/*
 * Probe the 8-byte tag; unless the tag byte is 6, patch the row
 *   with (tag - 6) through channel 8.
 */
void func_021EF36C(struct WinMgr *mgr)
{
    s8 buf[4];
    func_0202CF98(mgr, 8, buf + 1, buf);
    if ((signed char)buf[0] != 6)
        func_0202CD64(mgr, 8, 0, -1, (unsigned char)(buf[0] - 6));
}

/*
 * Probe the 8-byte tag; unless the tag byte is 0x18, patch the row
 *   with (0x18 - tag) as a flagged close.
 */
void func_021EF3A0(struct WinMgr *mgr)
{
    s8 buf[4];
    func_0202CF98(mgr, 8, buf + 1, buf);
    if ((signed char)buf[0] != 0x18)
        func_0202CD64(mgr, 8, 0, 1, (unsigned char)(0x18 - buf[0]));
}


/*
 * Forward a plus constants to func_0202CD64.
 */
void func_021EF3D8(struct WinMgr *mgr)
{
    func_0202CD64(mgr, 8, 1, 0, 0x13);
}


void func_021EF3EC(struct WinMgr *mgr)
{
    func_0202CD64(mgr, 8, -1, 0, 0x13);
}


int func_021EF400(unsigned char *p)
{
    signed char a[2];
    signed char b[2];
    unsigned r;
    func_0202CF98(*(struct WinMgr * *)&((struct Obj24043 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f74, 8, &a[1], &a[0]);
    r = func_0202CDD4(*(struct WinMgr * *)&((struct Obj24044 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f74, 8);
    func_0202CF98(*(struct WinMgr * *)&((struct Obj24045 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f74, 8, &b[1], &b[0]);
    if (a[1] != b[1] || a[0] != b[0])
        func_021EC8E4((char *)p);
    {
        int ret = 0;
        if (r != 0)
            ret = 1;
        return ret;
    }
}

/*
 * Read the 8-byte tag at the top of the frame; 1 when byte 1 is
 *   0x15 and byte 0 is 6.
 */
int func_021EF45C(struct WinMgr *mgr)
{
    s8 buf[4];
    func_0202CF98(mgr, 8, buf + 1, buf);
    return buf[1] == 0x15 && buf[0] == 6;
}

/*
 * Same probe as func_021EF45C with tag byte 1 compared to 2.
 */
int func_021EF480(struct WinMgr *mgr)
{
    s8 buf[4];
    func_0202CF98(mgr, 8, buf + 1, buf);
    return buf[1] == 0x2 && buf[0] == 6;
}

/*
 * Probe the 8-byte tag at the top of the frame; 1 when its first
 *   byte is 6.
 */
int func_021EF4A4(struct WinMgr *mgr)
{
    s8 buf[4];
    func_0202CF98(mgr, 8, buf + 1, buf);
    return buf[0] == 6;
}

/*
 * Push tag rows 0x20 for six entries; element (i*3+2) is a
 *   signed char.  The counter is UNSIGNED or the image's blo becomes blt.
 */
void func_021EF4C0(struct WinMgr *mgr)
{
    unsigned i;
    for (i = 0; i < 6; i++)
        func_0202CB4C(mgr, i, 0x20, (signed char)(i * 3 + 2));
}

void func_021EF4E4(struct WinMgr *mgr)
{
    unsigned i;
    for (i = 0; i < 6; i++)
        func_0202CB4C(mgr, i, 0x15, (signed char)(i * 3 + 2));
}


void func_021EF508(struct WinMgr *mgr)
{
    unsigned i;
    for (i = 0; i < 6; i++) {
        func_0202CC70(mgr, i);
        func_0202CB4C(mgr, i, 0x20, i * 3 + 2);
    }
}


void func_021EF534(struct WinMgr *mgr)
{
    signed char buf[2];
    unsigned short i = 0;
    func_0202CF98(mgr, 0, &buf[1], &buf[0]);
    if (buf[1] == 0x15)
        return;
    for (; i < 6; i++)
        func_0202CD64(mgr, i, -1, 0, buf[1] - 0x15);
}


void func_021EF57C(struct WinMgr *mgr)
{
    signed char buf[2];
    unsigned short i = 0;
    func_0202CF98(mgr, 0, &buf[1], &buf[0]);
    if (buf[1] == 0x20)
        return;
    for (; i < 6; i++)
        func_0202CD64(mgr, i, 1, 0, 0x20 - buf[1]);
}

/*
 * 1 when probe 1..6 reports 1.
 */
int func_021EF5C4(struct WinMgr *mgr)
{
    unsigned i;
    int found = 0;
    for (i = 0; i < 6; i++) {
        if (func_0202CDD4(mgr, i) == 1)
            found = 1;
    }
    return found;
}

int func_021EF5E8(struct WinMgr *mgr)
{
    s8 buf[4];
    func_0202CF98(mgr, 0, buf + 1, buf);
    return buf[1] != 0x20;
}

/*
 * 1 when the tag's byte 1 is 0x15.
 */
int func_021EF60C(struct WinMgr *mgr)
{
    s8 buf[4];
    func_0202CF98(mgr, 0, buf + 1, buf);
    return buf[1] == 0x15;
}

/*
 * Spin up the 0x0204162C resource, arm channel 6 with tag 0x20,
 *   then hand row 6 of the 0x540 span.
 */
void func_021EF630(char *p)
{
    int x = func_0204162C(0);
    func_0202CA3C(*(struct WinMgr **)(*(int *)&((struct Obj01558 *)p)->f2C + 0x74), 6, 0, 0x20, 3);
    func_0202CAC4(*(struct WinMgr **)(*(int *)&((struct Obj01558 *)p)->f2C + 0x74), 6, (const void *)(x + 0x540));
}


void func_021EF660(struct WinMgr *mgr)
{
    func_0202CB4C(mgr, 6, 0, 0x15);
}


/*
 * Forward the word at +0x74 plus constants to func_0202CB4C.
 */
void func_021EF670(char *p)
{
    func_0202CB4C(*(struct WinMgr * *)&((struct Obj18534 *)p)->f74, 0xa, 0, 0x15);
}


/*
 * Forward the word at +0x74 with index 10.
 */
void func_021EF680(char *p)
{
    func_0202CC70(*(struct WinMgr * *)&((struct Obj18535 *)p)->f74, 0xa);
}


void func_021EF68C(char *p)
{
    func_0202CB4C(*(struct WinMgr * *)&((struct Obj18536 *)p)->f74, 0xb, 0, 0x15);
}


/*
 * Forward the word at +0x74 with index 11.
 */
void func_021EF69C(char *p)
{
    func_0202CC70(*(struct WinMgr * *)&((struct Obj18537 *)p)->f74, 0xb);
}

void func_021EF6A8(struct WinMgr *mgr)
{
    func_0202CB4C(mgr, 7, 0x15, 0x18);
    func_0202CD64(mgr, 7, 0, -1, 0x13);
}


void func_021EF6CC(struct WinMgr *mgr)
{
    func_0202CD64(mgr, 7, 0, 1, 0x13);
}

#undef MGR
#define MGR(p) (*(struct WinMgr **)(*(char **)((p)+0x2c)+0x74))

/*
 * trailing: two zero alignment bytes at 0x021EF736.
 */
unsigned func_021EF6E0(char *p)
{
    signed char a[2], b[2];
    unsigned r;
    func_0202CF98(MGR(p),7,&a[1],&a[0]);
    r=func_0202CDD4(MGR(p),7);
    func_0202CF98(MGR(p),7,&b[1],&b[0]);
    if(a[1]!=b[1] || a[0]!=b[0]) func_021ED8A4(p);
    return r;
}

/*
 * Stage row 0x20 at channel 9 then patch with -1.
 */
void func_021EF738(struct WinMgr *mgr)
{
    func_0202CB4C(mgr, 9, 0x20, 0);
    func_0202CD64(mgr, 9, -1, 0, 0xb);
}


void func_021EF75C(struct WinMgr *mgr)
{
    func_0202CD64(mgr, 9, 1, 0, 0xb);
}
