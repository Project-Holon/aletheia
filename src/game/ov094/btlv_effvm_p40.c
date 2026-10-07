/*
 * file:     btlv_effvm_p40.c
 * unit:     yes
 * function: func_021FB3C8, func_021FB3DC, func_021FB49C, func_021FB500, func_021FB524, func_021FB550, func_021FB574, func_021FB5D4, func_021FB624, func_021FB648, func_021FB6F4, func_021FB790, func_021FB7F8, func_021FB864, func_021FB894
 * address:  0x021FB3C8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_021F8010 0x021F8010 thumb ov094
 *   func_0204047C  0x0204047C  arm
 *   func_02049624  0x02049624  arm
 *   func_0204989C  0x0204989C  arm
 *   func_020215EC  0x020215EC  thumb
 *   func_020407E8  0x020407E8  arm
 *   func_02040804  0x02040804  arm
 *   func_021F86E0  0x021F86E0  thumb  ov094
 *   func_021F8700  0x021F8700  thumb  ov094
 *   func_02209784  0x02209784  thumb  ov094
 *   func_021FCF2C  0x021FCF2C  thumb  ov094
 *   func_022097CC  0x022097CC  thumb  ov094
 *   func_0207D63C  0x0207D63C  arm
 *   func_021F8298  0x021F8298  thumb  ov094
 *   func_021F839C 0x021F839C thumb ov094
 *   func_02030734  0x02030734  arm
 *   func_02040588  0x02040588  arm
 *   func_02030DA8  0x02030DA8  arm
 *   func_021F896C  0x021F896C  thumb  ov094
 *   func_021FE79C  0x021FE79C  thumb  ov094
 *   func_021FE8AC  0x021FE8AC  thumb  ov094
 *   d_0220AE68     0x0220AE68  data   ov094  a1
 *   func_021F8694  0x021F8694  thumb  ov094
 *   func_021FF3F4  0x021FF3F4  thumb  ov094
 *   func_021F86F0  0x021F86F0  thumb  ov094
 *   func_02201AF8  0x02201AF8  thumb  ov094
 *   func_0206DF3C  0x0206DF3C  arm
 *   func_02201CD0  0x02201CD0  thumb  ov094
 *   func_02201D5C  0x02201D5C  thumb  ov094
 *   func_02201DA0 0x02201DA0 thumb ov094
 *   func_02201DB4  0x02201DB4  thumb  ov094
 */
#include "../../matched/include/Obj21662.h"
#include "../../matched/include/Obj04398.h"
#include "../../matched/include/Obj21663.h"
#include "../../matched/include/Obj21664.h"
#include "../../matched/include/Obj21665.h"
#include "../../matched/include/Obj13587.h"
#include "../../matched/include/Obj13588.h"
#include "../../matched/include/Obj21666.h"
#include "../../matched/include/Obj21667.h"
#include "../../matched/include/Obj07879.h"
#include "../../matched/include/Obj21668.h"
#include "../../matched/include/Obj21669.h"
#include "../../matched/include/Obj21670.h"
#include "../../matched/include/Obj13589.h"

struct Cursor;
struct PalAnmSlot;
typedef unsigned int   u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef short s16;

typedef signed char s8;

typedef struct {
    char pad[0xcc];
    int t[92];
    int f23c;
} State;

extern u32 func_0201134C(struct Cursor *p);
extern void func_021F8010(int);
extern void func_0204047C(int idx, unsigned short val);
extern u32 func_02049624(void *a0, void *a1, void *a2, void *a3, u32 a4, u32 a5, u16 a6);
extern void func_0204989C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 flags);
extern void func_020215EC(struct PalAnmSlot *slots, u32 arcId, u32 fileId, u32 tag, u32 idx, u32 count, u16 off, u16 srcOff);
extern u32 func_020407E8(u32 layer);
extern u32 func_02040804(u32 layer);
extern int func_021F86E0(void);
extern int func_021F8700(void);
extern void func_02209784(int a, int b, int c);
extern int func_021FCF2C(int a, int b);
extern void func_022097CC(int a, int b, int c, int d, int e, int f, int g, int h);
extern void func_0207D63C(int reg, int a, int b, int c, int d);
extern void func_021F8298(u32 a, u8 b, u8 c, u8 d, u16 e);
extern void func_021F839C(u32 a, u32 b);
extern void *func_02030734(unsigned int heap, unsigned int size, int clear, const char *file, u16 line);
extern void func_02040588(unsigned char which, unsigned char enable);
extern int func_02030DA8(int a, void (*fn)(void), int *p, int d);
extern void func_021F896C(void *h, void (*cb)(void *), int arg);
extern void func_021FE79C(void *h, int *s);
extern void func_021FE8AC(void *h);
extern int func_021F8694(void);
extern void func_021FF3F4(void *obj, void *out, int idx);
extern int func_021F86F0(void);
extern int func_02201AF8(int a, int b, int c, s16 d, s16 e, int f, int g);
extern void func_0206DF3C(int *p, int *q, int *r);
extern void func_02201CD0(char *o, int idx, int c, s16 *p, int s1, int s2, int s3);
extern void func_02201D5C(char *o, int idx, int c, void *d, int s1, int s2, int s3);
extern u32 func_02201DA0(char *p, int i, int v);
extern void func_02201DB4(char *base, int idx, u8 b, u8 c, s8 step, u16 d);
int func_021FB3C8(void *a, char *s);
int func_021FB3DC(struct Cursor *a, char *b);
int func_021FB49C(struct Cursor *a, char *b);
int func_021FB500(void *a, char *s);
int func_021FB524(void *a, char *s);
int func_021FB550(void *a, char *s);
int func_021FB574(struct Cursor *a, unsigned int *b);
int func_021FB5D4(struct Cursor *a, char *b);
int func_021FB624(void *a, char *s);
int func_021FB648(struct Cursor *a, char *b);
int func_021FB6F4(struct Cursor *a, char *b);
int func_021FB790(struct Cursor *a, char *b);
int func_021FB7F8(struct Cursor *a, char *b);
int func_021FB864(void *a, char *s);
int func_021FB894(struct Cursor *a, State *s);
extern char d_0220AE68[];


/*
 * Script command: passes one argument to func_021F8010.
 */
int func_021FB3C8(void *a, char *s)
{
    func_021F8010(func_0201134C(a));
    return ((struct Obj21662 *)s)->f23C;
}


int func_021FB3DC(struct Cursor *a, char *b)
{
    int t;

    t = func_0201134C(a);
    func_0204047C(3, 1);
    func_02049624((void *)0x5f, (void *)(t + 1), (void *)3, 0, 0, 0, (((struct Obj04398 *)b)->f238 & 0x7fff) | 0x8000);
    func_0204989C(0x5f, t, 3, 0, 0, 0, (((struct Obj04398 *)b)->f238 & 0x7fff) | 0x8000);
    func_020215EC((struct PalAnmSlot *)func_021F86E0(), (int)0x5f, (int)(t + 2), (u16)((((struct Obj04398 *)b)->f238 & 0x7fff) | 0x8000), (int)0, (int)0, (int)0x80, (int)0);
    ((struct Obj04398 *)b)->f264 = func_020407E8(3);
    ((struct Obj04398 *)b)->f268 = func_02040804(3);
    func_02209784(func_021F8700(), 0, 0);
    ((struct Obj04398 *)b)->f0 |= 0x10;
    return ((struct Obj04398 *)b)->f23C;
}


int func_021FB49C(struct Cursor *a, char *b)
{
    int t0, t1, t2, t3, t4, t5, v;

    t0 = func_0201134C(a);
    t1 = func_0201134C(a);
    t2 = func_0201134C(a);
    t3 = func_0201134C(a);
    t4 = func_0201134C(a);
    t5 = func_0201134C(a);
    v = func_021FCF2C((int)a, 14);
    func_022097CC(func_021F8700(), v, t0, t1, t2, t3, t4, t5);
    return ((struct Obj21663 *)b)->f23C;
}


/*
 * Script command: no-op that skips 4 arguments.
 */
int func_021FB500(void *a, char *s)
{
    func_0201134C(a);
    func_0201134C(a);
    func_0201134C(a);
    func_0201134C(a);
    return ((struct Obj21664 *)s)->f23C;
}


/*
 * Script command: no-op that skips 5 arguments.
 */
int func_021FB524(void *a, char *s)
{
    func_0201134C(a);
    func_0201134C(a);
    func_0201134C(a);
    func_0201134C(a);
    func_0201134C(a);
    return ((struct Obj21665 *)s)->f23C;
}


/*
 * Script command: func_0204047C(3, arg) and sets flag bit 4.
 */
int func_021FB550(void *a, char *s)
{
    func_0204047C(3, (unsigned char)func_0201134C(a));
    ((struct Obj13587 *)s)->f0 |= 0x10;
    return ((struct Obj13587 *)s)->f23C;
}


int func_021FB574(struct Cursor *a, unsigned int *b)
{
    int t2;

    func_0201134C(a);
    func_0201134C(a);
    t2 = func_0201134C(a);
    func_0201134C(a);
    func_0201134C(a);
    func_0201134C(a);
    if (t2 == 0x1f)
        func_0207D63C(0x04000050, 2, 0x3d, 0x1f, 7);
    else
        func_0207D63C(0x04000050, 10, 0x35, 0x1f, t2);
    *b |= 0x20;
    return ((struct Obj13588 *)b)->f23C;
}


int func_021FB5D4(struct Cursor *a, char *b)
{
    int t0, t1, t2, t3, t4;

    t0 = func_0201134C(a);
    t1 = func_0201134C(a);
    t2 = func_0201134C(a);
    t3 = func_0201134C(a);
    t4 = func_0201134C(a);
    func_021F8298(t0, t1, t2, t3, t4);
    return ((struct Obj21666 *)b)->f23C;
}


/*
 * Script command: passes two arguments to func_021F839C.
 */
int func_021FB624(void *a, char *s)
{
    int x = func_0201134C(a);
    func_021F839C(x, func_0201134C(a));
    return ((struct Obj21667 *)s)->f23C;
}


int func_021FB648(struct Cursor *a, char *b)
{
    int *p;

    p = func_02030734((u16)((((struct Obj07879 *)b)->f238 & 0x7fff) | 0x8000), 0x28, 1, d_0220AE68, 0xd88);
    p[0] = (int)b;
    p[2] = func_0201134C(a);
    p[3] = func_0201134C(a);
    p[4] = func_0201134C(a);
    p[5] = func_0201134C(a);
    p[6] = func_0201134C(a);
    p[8] = func_0201134C(a);
    p[9] = func_0201134C(a);
    func_02040588(1, 0);
    func_02040588(2, 0);
    func_021F896C((void *)func_02030DA8(((struct Obj07879 *)b)->f8, (void (*)(void))func_021FE79C, p, 0), func_021FE8AC, 1);
    ((struct Obj07879 *)b)->f0 |= 0x100;
    return ((struct Obj07879 *)b)->f23C;
}


/*
 * (pt is 3 words: the third is unused padding that sets the 0x30 frame)
 */
int func_021FB6F4(struct Cursor *a, char *b)
{
    int pt[3];
    int o1, o2;
    int t0, t1, t2, t3, t4, t5, t6;

    t0 = func_0201134C(a);
    t1 = func_0201134C(a);
    t2 = func_021FCF2C((int)a, func_0201134C(a));
    t3 = func_0201134C(a);
    t4 = func_0201134C(a);
    t5 = func_0201134C(a);
    t6 = func_0201134C(a);
    func_021FF3F4((void *)func_021F8694(), pt, t2);
    pt[0] += t3;
    pt[1] += t4;
    func_0206DF3C(pt, &o1, &o2);
    *(int *)(b + t0 * 4 + 0xcc) =
        func_02201AF8(func_021F86F0(), 0x5f, t1, o1, o2, t5, t6);
    return ((struct Obj21668 *)b)->f23C;
}


int func_021FB790(struct Cursor *a, char *b)
{
    s16 arr[2];
    int t0, t1, t3, t4, t5;

    t0 = func_0201134C(a);
    t1 = func_0201134C(a);
    arr[0] = func_0201134C(a);
    arr[1] = func_0201134C(a);
    t3 = func_0201134C(a);
    t4 = func_0201134C(a);
    t5 = func_0201134C(a);
    func_02201CD0((char *)func_021F86F0(), *(int *)(b + t0 * 4 + 0xcc), t1, arr, t3, t4, t5);
    return ((struct Obj21669 *)b)->f23C;
}


int func_021FB7F8(struct Cursor *a, char *b)
{
    int arr[3];
    int t0, t1, t3, t4, t5;

    t0 = func_0201134C(a);
    t1 = func_0201134C(a);
    arr[0] = func_0201134C(a);
    arr[1] = func_0201134C(a);
    arr[2] = 0x1000;
    t3 = func_0201134C(a);
    t4 = func_0201134C(a);
    t5 = func_0201134C(a);
    func_02201D5C((char *)func_021F86F0(), *(int *)(b + t0 * 4 + 0xcc), t1, arr, t3, t4, t5);
    return ((struct Obj21670 *)b)->f23C;
}


/*
 * Script command: passes slot arg of the table at 0xcc and a value to func_02201DA0.
 */
int func_021FB864(void *a, char *s)
{
    int i = func_0201134C(a);
    int x = func_0201134C(a);

    func_02201DA0((char *)func_021F86F0(), ((int *)(s + 0xcc))[i], x);
    return ((struct Obj13589 *)s)->f23C;
}


int func_021FB894(struct Cursor *a, State *s)
{
    int v0 = func_0201134C(a);
    int v1 = func_0201134C(a);
    int v2 = func_0201134C(a);
    int v3 = func_0201134C(a);
    int v4 = func_0201134C(a);

    func_02201DB4((char *)func_021F86F0(), s->t[v0], v1, v2, v3, v4);
    return s->f23c;
}
