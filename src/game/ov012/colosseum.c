/*
 * file:     colosseum.c
 * unit:     yes
 * function: func_02174B58, func_02174B80, func_02174BB8, func_02174BEC, func_02174C34, func_02174C60, func_02174C90, func_02174CB8, func_02174CE4, func_02174D10, func_02174D2C, func_02174D64, func_02174D98, func_02174DC8, func_02174DF0, func_02174E20, func_02174E44, func_02174E64, func_02174E9C, func_02174ED8, func_02174EFC, func_02174F18, func_02174F34, func_02174F4C, func_0217505C, func_02175094, func_021750B0, func_021750C0, func_021750C8, func_021750D0, func_021750D8, func_02175110, func_02175144, func_021751B4, func_021751DC, func_02175208, func_02175214, func_02175240, func_02175280, func_0217534C
 * address:  0x02174B58
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02034714 0x02034714 arm
 *   d_0217562C 0x0217562C data a4
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_02082D44 0x02082D44 arm
 *   func_0203D3F8 0x0203D3F8 arm
 *   func_0203D378 0x0203D378 arm
 *   func_0201A918 0x0201A918 thumb
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_02030734  0x02030734  arm
 *   func_02167518  0x02167518  thumb
 *   func_0201A920  0x0201A920  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201AC2C  0x0201AC2C  thumb
 *   func_02008494  0x02008494  thumb
 *   func_02087C6C  0x02087C6C  arm
 *   func_0216F40C  0x0216F40C  thumb
 *   str_02175630   0x02175630  data  ov012
 *   func_020307B0  0x020307B0  arm
 *   func_0216754C  0x0216754C  thumb  ov010
 *   func_0203D1B4  0x0203D1B4  arm
 *   func_0201A948  0x0201A948  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_02175358  0x02175358  thumb  ov012
 *   func_020120F4  0x020120F4  thumb
 *   func_02012F2C  0x02012F2C  thumb
 */
#include "../../matched/include/Obj19276.h"
#include "../../matched/include/Obj19277.h"
#include "../../matched/include/Obj19278.h"
#include "../../matched/include/Obj19279.h"
#include "../../matched/include/Obj19280.h"
#include "../../matched/include/Obj19281.h"
#include "../../matched/include/Obj19283.h"
#include "../../matched/include/Obj19284.h"
#include "../../matched/include/Obj19286.h"
#include "../../matched/include/Obj19287.h"
#include "../../matched/include/Obj19288.h"
#include "../../matched/include/Obj19289.h"
#include "../../matched/include/Obj19291.h"
#include "../../matched/include/Obj19292.h"
#include "../../matched/include/Obj19294.h"
#include "../../matched/include/Obj07341.h"

struct Entry;
struct Link;
struct Obj;
struct Party;
struct BigObj;
struct Rec534;
struct O;
struct Ctx;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef struct {
    void *f000;
    u8 pad004[0x18 - 4];
    u8 slot[4][0x2c];
    u8 pad0c4[0xcc - 0x18 - 4 * 0x2c];
    u8 fcc[4];
    u8 fd0[4];
    u8 pad0d4[0xdc - 0xd4];
    u8 fdc;
    u8 fdd;
    u8 pad0de[0x134 - 0xde];
    void *f134[4];
    u8 f144[4];
    void *f148[4];
    u8 pad158[0x170 - 0x158];
} Work;

typedef struct {
    u8 pad00[0xc8];
    u8 bc8 : 1;
} Obj;

typedef struct { int w[5]; } E;

extern void func_02034714(const char *,u32,const char *);
extern struct Entry *func_020399A8(void);
extern u32 func_0203D1A4(struct Link *p);
extern void func_02082D44(void *,void *,u32);
extern u32 func_0203D3F8(u32,u32,u32,u32,u32,u32,u32,u32);
extern u32 func_0203D378(void);
extern int func_0201A918(void);
extern int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_02167518(u32 a, u32 b, u32 c, u32 d);
extern struct Party *func_0201A920(u32 heap);
extern void *func_02012934(const struct BigObj *p);
extern void func_0201AC2C(const struct Rec534 *src, struct Rec534 *dst);
extern void func_02008494(void *src, void *dst);
extern void func_02087C6C(void *p);
extern void func_0216F40C(void *a, u32 b, u32 c, u32 d, u32 e);
extern u32 func_020307B0(void *p);
extern void func_0216754C(int a, struct O *o);
extern int func_0203D1B4(void);
extern void func_0201A948(struct Party *p);
extern void func_02082BCC(void *p, int v, int n);
extern void func_02175358(u8 *a, u8 *slot, u8 i, int d);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012F2C(int *p);
u8 *func_02174B58(int a, u8 *b, int c);
void func_02174B7C(void);
void func_02174B80(u32 a, u32 b, void *c, u8 *d);
u32 func_02174BB8(u32 a, u32 b);
void func_02174BEC(u32 a, u32 b, void *c, u8 *d);
int func_02174C34(u32 a);
void func_02174C60(u32 a, u32 b, void *c, u8 *d);
u32 func_02174C90(u32 a);
void func_02174CB8(u32 a, u32 b, u8 *c, u8 *d);
u32 func_02174CE4(char *p);
void func_02174D10(u32 a, u32 b, u32 *c, u8 *d);
int func_02174D2C(char *a, u32 b, u32 c);
void func_02174D64(u32 a, u32 b, void *c, u8 *d);
u32 func_02174D98(u32 p);
void func_02174DC8(int unused, u32 n, void *src, u8 *ctx);
int func_02174DF0(u32 v);
void func_02174E08(int index,int unused1,int unused2,u8 *ctx);
u32 func_02174E20(void);
void func_02174E44(int n, int b, int c, u8 *p);
u32 func_02174E64(void);
void func_02174E88(int unused0,int unused1,int unused2,u8 *ctx);
u32 func_02174E9C(int v);
void func_02174EC4(int unused0,int unused1,int unused2,u8 *ctx);
u32 func_02174ED8(void);
void func_02174EFC(int a, int b, int c, u8 *p);
void func_02174F18(int n, int b, int c, u8 *p);
int func_02174F34(void);
Work *func_02174F4C(const struct Obj *obj, u32 a1, u32 a2, u32 a3);
void func_0217505C(int *p, int x);
void func_02175094(Obj *p, int v);
void func_021750B0(u8 *p, int v);
u8 func_021750C0(char *p);
void func_021750C8(u8 *p, int v);
u8 func_021750D0(u8 *p);
int func_021750D8(u8 *p, int slot, int value);
void func_02175110(u8 *p);
void func_02175144(u8 *p);
void func_021751B4(u8 *p, int i, const E *src);
int func_021751DC(char *a0, int a1, E *out);
void func_02175208(u8 *p);
int func_02175214(u8 *p);
void func_02175240(u8 *a, int b);
void func_02175280(u8 *a, void *b, u8 *out, int d);
void func_0217534C(void *p);
extern const char d_0217562C[];
extern char str_02175630[];





u8 *func_02174B58(int a, u8 *b, int c)
{
    if (c > 0x800) func_02034714(d_0217562C, 0, d_0217562C);
    return b + 4 + (a << 11);
}






void func_02174B7C(void)
{
}





void func_02174B80(u32 a, u32 b, void *c, u8 *d)
{
    u8 *w = *(u8 * *)&((struct Obj19276 *)d)->f355C;
    if (a == func_0203D1A4((struct Link *)((u32)func_020399A8()))) return;
    if (w == 0 || ((struct Obj19277 *)w)->f0 == 0) return;
    func_02082D44(c, w + 0x18 + a * 44, b);
}





u32 func_02174BB8(u32 a, u32 b)
{
    u32 v = 0;
    if (b != 1) v = 255;
    return func_0203D3F8((u32)func_020399A8(),(u8)v,0x1501,44,a,1,0,1);
}






void func_02174BEC(u32 a, u32 b, void *c, u8 *d)
{
    u8 *w = *(u8 * *)&((struct Obj19278 *)d)->f355C;

    if (a == func_0203D1A4((struct Link *)((u32)func_020399A8()))) {
        return;
    }
    if (w == 0 || ((struct Obj19279 *)w)->f0 == 0) {
        return;
    }
    if (*(void **)(w + a * 4 + 0x134) == 0) {
        return;
    }
    func_02082D44(c, *(void **)(w + a * 4 + 0x134), b);
    (w + a)[0x144] = 1;
}





int func_02174C34(u32 a)
{
    return func_0203D3F8((u32)func_020399A8(),255,0x1502,0x678,a,1,0,1);
}





void func_02174C60(u32 a, u32 b, void *c, u8 *d)
{
    u8 *w = *(u8 * *)&((struct Obj19280 *)d)->f355C;
    if (a == func_0203D1A4((struct Link *)((u32)func_020399A8()))) return;
    if (w == 0 || ((struct Obj19281 *)w)->f0 == 0) return;
    func_021751B4(w,a,c);
}





u32 func_02174C90(u32 a)
{
    return func_0203D3F8((u32)func_020399A8(),255,0x1503,20,a,0,1,1);
}





void func_02174CB8(u32 a, u32 b, u8 *c, u8 *d)
{
    u8 *w = *(u8 * *)&((struct Obj19283 *)d)->f355C;
    if (w == 0 || ((struct Obj19284 *)w)->f0 == 0) return;
    if (func_0203D378() == 0) return;
    func_021750D8(w,a,*c);
}





u32 func_02174CE4(char *p)
{
    u8 v = func_021750C0(p);
    return func_0203D3F8((u32)func_020399A8(),0,0x1504,1,(u32)&v,1,0,0);
}





void func_02174D10(u32 a, u32 b, u32 *c, u8 *d)
{
    u8 *w = *(u8 * *)&((struct Obj19286 *)d)->f355C;
    if (w == 0 || ((struct Obj19287 *)w)->f0 == 0) return;
    func_021750C8(w, *c);
}





/*
 * lever: The address-taken payload is the third parameter: sp+0x20
 *        after the 16-byte home area, 8-byte save and 16-byte call frame.
 *        Taking the first parameter's address added a reload and gave DIFF.
 */
int func_02174D2C(char *a, u32 b, u32 c)
{
    func_021750C0(a);
    return func_0203D3F8((u32)func_020399A8(),(u8)b,0x1505,4,(u32)&c,1,0,0);
}





/*
 * lever: (w+a)[0x158] preserves the base-plus-index store address;
 *        w[a+0x158] produced an 8-byte concrete scheduling/addressing DIFF.
 */
void func_02174D64(u32 a, u32 b, void *c, u8 *d)
{
    u8 *w = *(u8 * *)&((struct Obj19288 *)d)->f355C;
    if (w == 0) return;
    if (*(void **)(w + a * 4 + 0x148) == 0) return;
    func_02082D44(c, *(void **)(w + a * 4 + 0x148), b);
    (w + a)[0x158] = 1;
}





/*
 * Caller consumes 020399A8's live r0 despite its filed void return.
 */
u32 func_02174D98(u32 p)
{
    u32 a = (u32)func_020399A8();
    return func_0203D3F8(a,255,0x1506,func_0201A918(),p,1,0,1);
}




void func_02174DC8(int unused, u32 n, void *src, u8 *ctx)
{
    u8 *p = *(u8 * *)&((struct Obj19289 *)ctx)->f355C;
    if (p) {
        func_02082D44(src,p+0x15c,n);
        p[0x160] = 1;
    }
}




int func_02174DF0(u32 v) { return func_0203D3A8(func_020399A8(),0x1507,4,v); }




void func_02174E08(int index,int unused1,int unused2,u8 *ctx)
{
    u8 *p = *(u8 * *)&((struct Obj19291 *)ctx)->f355C;
    if (p) (p+index)[0xd4] = 1;
}



u32 func_02174E20(void)
{
    return func_0203D3F8((u32)func_020399A8(), 0, 0x1508, 0, 0, 1, 0, 0);
}


void func_02174E44(int n, int b, int c, u8 *p)
{
    u8 *w = *(u8 **)(p + 0x355c);
    if (w != 0) {
        u8 *q = w + n;
        q[0xd8] = 1;
        q[0xd4] = 0;
    }
}



u32 func_02174E64(void) { return func_0203D3F8((u32)func_020399A8(),0,0x1509,0,0,1,0,0); }



void func_02174E88(int unused0,int unused1,int unused2,u8 *ctx)
{
    u8 *p = *(u8 * *)&((struct Obj19292 *)ctx)->f355C;
    if (p) p[0xdf] = 0;
}



u32 func_02174E9C(int v) { return func_0203D3F8((u32)func_020399A8(),(u8)v,0x150a,0,0,1,0,0); }



void func_02174EC4(int unused0,int unused1,int unused2,u8 *ctx)
{
    u8 *p = *(u8 * *)&((struct Obj19294 *)ctx)->f355C;
    if (p) p[0xcb] = 1;
}



u32 func_02174ED8(void)
{
    return func_0203D3F8((u32)func_020399A8(), 0xff, 0x150b, 0, 0, 1, 0, 0);
}


void func_02174EFC(int a, int b, int c, u8 *p)
{
    u8 *w = *(u8 **)(p + 0x355c);
    if (w != 0)
        w[0x161]++;
}


void func_02174F18(int n, int b, int c, u8 *p)
{
    u8 *w = *(u8 **)(p + 0x355c);
    if (w != 0) {
        u8 *q = w + n;
        q[0x162] = 1;
    }
}




int func_02174F34(void) { return func_0203D3A8(func_020399A8(), 0x150d, 0, 0); }






Work *func_02174F4C(const struct Obj *obj, u32 a1, u32 a2, u32 a3)
{
    Work *w;
    u32 idx;
    int i;
    u8 *s;
    u32 v;

    idx = func_0203D1A4((struct Link *)func_020399A8());
    w = func_02030734(0x41, 0x170, 1, str_02175630, 0x35);
    w->f000 = func_02167518(4, a1, 0x41, 0);
    for (i = 0; i < 4; i++) {
        w->f134[i] = func_02030734(0x41, 0x678, 1, str_02175630, 0x38);
        w->f148[i] = func_0201A920(0x41);
    }
    for (i = 0; i < 4; i++) {
        w->fcc[i] = 0xff;
        w->fd0[i] = 0xff;
    }
    w->fdc = 0xff;
    w->fdd = 0xff;
    func_0201AC2C(func_02012934((const struct BigObj *)obj), w->f148[idx]);
    s = w->slot[idx];
    func_02008494((void *)a2, s);
    func_02087C6C(s + 0x20);
    s[0x26] = 1;
    v = 1;
    if (a3 == 1) {
        v = 0;
    }
    s[0x27] = v;
    s[0x28] = 0x64;
    func_0216F40C(w->f134[idx], (u32)obj, 1, 0, 0x41);
    w->f144[idx] = 1;
    return w;
}






void func_0217505C(int *p, int x)
{
    int i;

    for (i = 0; i < 4; i++) {
        func_020307B0(*(void **)((char *)p + i * 4 + 0x134));
        func_020307B0(*(void **)((char *)p + i * 4 + 0x148));
    }
    func_0216754C(x, (struct O *)(*p));
    func_020307B0(p);
}





void func_02175094(Obj *p, int v)
{
    p->bc8 = (u8)v;
}





void func_021750B0(u8 *p, int v)
{
    p[0xdc] = v;
    p[0xdd] = 0xff;
}





u8 func_021750C0(char *p)
{
    return p[0xdc];
}




/*
 * Extent follower 021750D0 is already filed separately.
 */
void func_021750C8(u8 *p, int v) { p[0xdd] = v; }





u8 func_021750D0(u8 *p)
{
    return p[0xdd];
}



/*
 * Two trailing alignment bytes. Duplicated store arms preserve the branch stub.
 */
int func_021750D8(u8 *p, int slot, int value)
{
    int i;
    int result;
    if (value == 255) {
        (p+slot)[0xcc] = value;
        result = 1;
    } else {
        for (i = 0; i < 4; i++) {
            if ((p+i)[0xcc] == value) { result = 0; break; }
        }
    if (i == 4) {
        (p+slot)[0xcc] = value;
        result = 1;
    }
    }
    (p+slot)[0xd0] = result;
    return result;
}



void func_02175110(u8 *p)
{
    int i;
    if (func_0203D378()) {
        for (i=0;i<4;i++) {
            if ((p+i)[0xd0] != 255 && func_02174D2C((char *)p,i,(p+i)[0xd0]) == 1)
                (p+i)[0xd0] = 255;
        }
    }
}




void func_02175144(u8 *p)
{
    int cnt;
    int i;
    int z;

    if (func_0203D378() == 0) {
        return;
    }
    cnt = 0;
    for (i = 0; i < 4; i++) {
        if (p[0xd4 + i] == 1) {
            cnt++;
        }
    }
    if (cnt == func_0203D1B4()) {
        if (func_02174ED8() == 1) {
            z = 0;
            for (i = 0; i < 4; i++) {
                p[0xd4 + i] = z;
                p[0xd8 + i] = z;
            }
        }
    } else {
        z = 0;
        for (i = 0; i < 4; i++) {
            if (p[0xd8 + i] == 1 && func_02174E9C(i) == 1) {
                p[0xd8 + i] = z;
            }
        }
    }
}



/*
 * The flag address groups base plus index before the constant offset.
 */
void func_021751B4(u8 *p, int i, const E *src)
{
    *(E *)(p + 0xe0 + i * 20) = *src;
    (p + i)[0x130] = 1;
}




/*
 * Recursive MATCH unblocker: callee of func_0217FF78 (ov019) +0024. Only ov012
 * has a function start here (ov011 holds the interior of a larger function,
 * ov009 ARM data), so the ov012 shard makes that site attest as `matched`.
 * The caller's scratch buffer is u32[5] and this leaf copies exactly 0x14
 * bytes into it.
 */
int func_021751DC(char *a0, int a1, E *out)
{
    E *e = (E *)(a0 + 0xE0 + a1 * 0x14);
    u8 old;

    *out = *e;
    old = *(u8 *)(a0 + 0x130 + a1);
    *(u8 *)(a0 + 0x130 + a1) = 0;
    return old;
}




/*
 * note:     unlabelled leaf (prints as .word in ov012.s); called from
 *           ov019 func_0217E440.
 */
void func_02175208(u8 *p)
{
    p[0x161] = 0;
}



/*
 * Two trailing alignment bytes.
 * Caller consumes 0203D1B4's live r0 despite its filed void return.
 */
int func_02175214(u8 *p)
{
    int n = 0;
    int i;
    for (i = 0; i < 4; i++) if (p[0x158 + i] == 1) n++;
    if (n >= func_0203D1B4()) return 1;
    return 0;
}




void func_02175240(u8 *a, int b)
{
    int self;
    int i;

    self = func_0203D1A4((struct Link *)((u32)func_020399A8()));
    for (i = 0; i < 4; i++) {
        if (b == 0 || self != i) {
            func_0201A948(*(void **)(a + i * 4 + 0x148));
        }
        a[i + 0x158] = 0;
    }
}




void func_02175280(u8 *a, void *b, u8 *out, int d)
{
    int count;
    int i;
    int v;
    int self;
    int base;
    int y;

    count = 0;
    func_02082BCC(out, 0, 0x58);
    ((struct Obj07341 *)out)->f44 = 3;
    for (i = 0; i < 4; i++) {
        if (a[0x158 + i] == 0) {
            ((struct Obj07341 *)out)->f44 = 1;
            break;
        }
        count++;
    }
    if (count != 2 && count != 4) {
        func_02034714((void *)0x0217563C, 0, (void *)0x0217563C);
    }
    self = (a + func_0203D1A4((struct Link *)((u32)func_020399A8())))[0x15C];
    for (i = 0; i < count; i++) {
        y = a[0x15C + i];
        if ((y & 1) == (self & 1)) {
            base = 0;
        } else if (((struct Obj07341 *)out)->f44 == 1) {
            base = 1;
        } else {
            base = 2;
        }
        v = base + (y >> 1);
        if (v >= count) {
            func_02034714((void *)0x0217563C, 0, (void *)0x0217563C);
        }
        func_02175358(a, out + v * 16, (u8)i, d);
    }
    ((struct Obj07341 *)out)->f54 = (int)func_02012F2C(func_020120F4(b));
}




/*
 * evidence: unlabelled Thumb tail-call leaf (ldr r3,=func_02082BCC; bx r3) after
 * func_02175280; called by the bl at 0x02174A94 in func_02174744.
 */
void func_0217534C(void *p)
{
    func_02082BCC(p, 0, 0x58);
}
