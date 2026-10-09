/*
 * file:     field_place_name_p02.c
 * unit:     yes
 * function: func_021BC704, func_021BC720, func_021BC730, func_021BC748, func_021BC75C, func_021BC788, func_021BC794, func_021BC7B0, func_021BC7BC, func_021BC7D4, func_021BC7F8, func_021BC810, func_021BC824, func_021BC838, func_021BC848, func_021BC910, func_021BC92C, func_021BC948, func_021BC970, func_021BC998, func_021BC9AC, func_021BC9C0, func_021BC9CC, func_021BCA48, func_021BCA64, func_021BCA6C, func_021BCA74, func_021BCA78, func_021BCA80, func_021BCA88, func_021BCA8C, func_021BCAB0, func_021BCB48, func_021BCB9C, func_021BCBC8, func_021BCC3C, func_021BCC80, func_021BCD34, func_021BCD70, func_021BCD84, func_021BCDD8, func_021BCE88, func_021BCEAC, func_021BCEB0, func_021BCEB4, func_021BCF18
 * address:  0x021BC704
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
 *   d_021D9B78     0x021D9B78  data  a4
 *   func_0204B084  0x0204B084  arm
 *   func_021BD090  0x021BD090  thumb  ov021
 *   func_021BD094  0x021BD094  thumb  ov021
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_021BD148  0x021BD148  thumb  ov021
 *   func_021BD184  0x021BD184  thumb  ov021
 *   func_02049238  0x02049238  arm
 *   func_021BD134  0x021BD134  thumb  ov021
 *   func_021BD1EC  0x021BD1EC  thumb  ov021
 *   func_021BD19C  0x021BD19C  thumb  ov021
 *   func_02045A38  0x02045A38  arm
 *   sub_0201DC6C   0x0201DC6C  thumb
 *   d_021D9B88     0x021D9B88  data  a4
 *   _ffltu         0x0209BE04  arm
 *   _fflt          0x0209BDBC  arm
 *   _fadd          0x0209C95C  arm
 *   func_021BD138  0x021BD138  thumb  ov021
 *   func_021BD1E4  0x021BD1E4  thumb  ov021
 *   func_021BD1D4  0x021BD1D4  thumb  ov021
 *   func_021BD1CC  0x021BD1CC  thumb  ov021
 *   func_021BD1DC  0x021BD1DC  thumb  ov021
 *   func_02045770  0x02045770  arm
 *   func_021BD1FC  0x021BD1FC  thumb  ov021
 *   func_021BD204  0x021BD204  thumb  ov021
 *   func_021BD1F4  0x021BD1F4  thumb  ov021
 *   func_020439A0  0x020439A0  arm
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
 *   func_021BD0A0  0x021BD0A0  thumb  ov021
 *   func_021BD0A8  0x021BD0A8  thumb  ov021
 *   func_021BD0C8  0x021BD0C8  thumb  ov021
 *   func_02040588  0x02040588  arm
 *   _fdiv          0x0209CE10  arm
 *   _fmul          0x0209C77C  arm
 *   _ffix          0x0209C494  arm
 *   _fsub          0x0209CB8C  arm
 *   func_021BD0C0  0x021BD0C0  thumb  ov021
 *   func_021BD0D0  0x021BD0D0  thumb  ov021
 *   func_020414C4  0x020414C4  arm
 *   func_020414EC  0x020414EC  arm
 *   func_021BC6D0  0x021BC6D0  thumb  ov021
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   func_0204047C  0x0204047C  arm
 *   func_0207D63C  0x0207D63C  arm
 *   func_021BD20C  0x021BD20C  thumb  ov021
 */
#include "../../matched/include/Obj00575.h"
#include "../../matched/include/Obj18190.h"
#include "../../matched/include/Obj18191.h"
#include "../../matched/include/Obj01123.h"
#include "../../matched/include/Obj18195.h"
#include "../../matched/include/Obj18196.h"
#include "../../matched/include/Obj18197.h"
#include "../../matched/include/Obj18198.h"
#include "../../matched/include/Obj18199.h"
#include "../../matched/include/Obj18200.h"
#include "../../matched/include/Obj05061.h"
#include "../../matched/include/Obj00183.h"
#include "../../matched/include/Obj20118.h"

struct CharBuf;
struct Descriptor;
struct Obj_021BC730;
struct Bank;
struct U16Vec;
struct Font;
struct Bmp;
struct MsgBank;
struct WordSet;
struct Ctx;
struct BigObj;
struct Sub02014444Obj;
struct Cfg;
typedef struct {
    char pad[0x28];
    int f28;
} Obj_021BC704;

typedef unsigned int   u32;

typedef struct {
    char pad[0x24];
    void *f24;
} Obj_021BC720;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef struct {
    char pad[0xC];
    u16 hC;
    char pad2[0x2A];
    void *f38;
} Obj_021BC730;

typedef signed int     s32;

typedef struct {
    char pad[0x2C];
    void *f2C;
} Obj_021BC75C;

typedef struct {
    char pad[0x34];
    void *f34;
} Obj_021BC794;

typedef struct {
    char pad[0x34];
    void *f34[1];
    void *f38;
} Obj_021BC7BC;

typedef struct {
    char pad[0xC];
    u16 hC;
    char pad2[0x1E];
    void *f2C;
    void *f30;
    char pad3[0x1C];
    void *f50[0x1E];
} Obj_021BC7D4;

typedef struct {
    char pad[0x50];
    void *f50[0x1E];
} Obj_021BC7F8;

typedef struct {
    char pad[0x10];
    void *f10;
} Obj_021BC810;

typedef struct {
    float f0;
    float f4;
    float f8;
    float fC;
    float x;
    float f14;
    float f18;
    float f1C;
    u32 f20;
    u16 ch;
    u16 pad;
} Params;

typedef struct {
    u8 pad0[0x18];
    u32 f18;
    u8 pad1C[0x50 - 0x1C];
    u32 f50[30];
    u32 fC8[32];
    u8 count;
    u8 pad149[2];
    u8 skip;
} Obj_021BC848;

typedef struct {
    char pad[0x148];
    u8 b148;
} Obj_021BC910;

typedef struct {
    char pad[0x50];
    void *f50[0x1E];
} Obj_021BC92C;

typedef struct {
    char pad[0xC8];
    void *fC8[0x20];
    char pad2[0x149 - 0xC8 - 0x80];
    u8 b149;
} Obj_021BC948;

typedef struct {
    char pad[0xC8];
    void *fC8[0x20];
} Obj_021BC970;

typedef struct {
    char pad[0x30];
    void *f30;
    void *f34;
} Obj_021BC998;

typedef struct {
    char pad[0x30];
    void *f30;
} Obj_021BC9AC;

typedef struct {
    char pad[0x14A];
    u8 b14A;
} Obj_021BCA48;

typedef struct {
    char pad[0x44];
    u16 h44;
    u16 h46;
} Obj_021BCA8C;

typedef struct {
    char pad[0x3C];
    int f3C;
} Obj_021BD0A0;

typedef struct {
    char pad[0x40];
    u8 b40;
} Obj_021BD0D0;

typedef struct {
    char pad[0xC];
    int fC;
} Inner;

typedef struct {
    char pad[0x150];
    Inner *f150;
} Obj_021BC6D0;

typedef struct {
    char pad[0x42];
    u16 h42;
} Obj;

extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern struct Obj_021BC730 *func_0204B034(u8 *a0, u32 a1, u32 heap);
extern void func_0204B084(u32 v);
extern u16 func_021BD090(u8 *p);
extern u16 func_021BD094(Obj_021BC75C *p);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern void func_0204ADA4(u32 i);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0204B22C(struct Bank *bank, u32 mode);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204B258(struct Bank *bank, void *p);
extern void *func_021BD148(int a0, int a1, int a2, int a3);
extern void func_021BD184(void *a);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049238(u32 v);
extern u32 func_021BD134(u8 *p);
extern int func_021BD1EC(u8 *a0);
extern int func_021BD19C(u32 a, u32 b);
extern void func_02045A38(struct U16Vec *vec, u16 *out, u32 n);
extern u32 sub_0201DC6C(struct Font *p, u16 ch);
extern u8 func_021BD138(u8 *p);
extern void func_021BD1E4(void *a, unsigned int b);
extern void func_021BD1D4(void *a);
extern void func_021BD1CC(void *a);
extern void *func_02025538(unsigned int a0, void *a1);
extern void func_02025588(void *a);
extern int func_021BD1DC(u8 *a0);
extern int func_021BD1FC(int a);
extern int func_021BD204(int a);
extern int func_021BD1F4(u8 *a0);
extern void func_020439A0(struct Bmp *dst, struct Bmp *src, u32 x, u32 y, int sx, int sy, u32 w, u32 h, u32 key);
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
void func_021BD0A0(Obj_021BD0A0 *p, int v);
void func_021BD0A8(char *p);
void func_021BD0C8(char *p);
extern void func_02040588(unsigned char which, unsigned char enable);
extern u8 func_021BD0C0(u8 *p);
extern void func_021BD0D0(Obj_021BD0D0 *p);
extern void func_020414C4(u32 idx);
extern void func_020414EC(u32 i);
extern void func_021BC6D0(Obj_021BC6D0 *p);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern unsigned char func_02045730(struct Descriptor *d);
extern void func_020409B4(unsigned int index);
extern void func_0204047C(int idx, unsigned short val);
extern void func_0207D63C(int, int, int, int, int);
extern unsigned int func_021BD20C(char *p);
void func_021BC704(Obj_021BC704 *p);
void func_021BC720(Obj_021BC720 *p);
void func_021BC730(Obj_021BC730 *p);
void func_021BC748(u8 *p);
void func_021BC75C(Obj_021BC75C *p);
void func_021BC788(u8 *p);
void func_021BC794(Obj_021BC794 *p);
void func_021BC7B0(u8 *p);
void func_021BC7BC(Obj_021BC7BC *p, int i);
void func_021BC7D4(Obj_021BC7D4 *p);
void func_021BC7F8(Obj_021BC7F8 *p);
void func_021BC810(Obj_021BC810 *p);
void func_021BC824(u8 *p);
void func_021BC838(char *p);
void func_021BC848(Obj_021BC848 *p);
int func_021BC910(Obj_021BC910 *p);
void func_021BC92C(Obj_021BC92C *p);
void func_021BC948(Obj_021BC948 *p);
void func_021BC970(Obj_021BC970 *p);
void func_021BC998(Obj_021BC998 *p);
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
void func_021BCB9C(void *p, int keep);
void func_021BCBC8(char *p);
void func_021BCC3C(void *p);
void func_021BCC80(char *p);
void func_021BCD34(Obj *p);
void func_021BCD70(Obj *p);
void func_021BCD84(char *p);
void func_021BCDD8(char *p);
void func_021BCE88(char *p);
void func_021BCEAC(int a);
void func_021BCEB0(int a);
void func_021BCEB4(char *p);
void func_021BCF18(int a);
extern int d_021D9B78;
extern const Params d_021D9B88;






void func_021BC704(Obj_021BC704 *p)
{
    if (p->f28 != -1) {
        func_0203FB44(3, p->f28, 0x20);
        p->f28 = -1;
    }
}






void func_021BC720(Obj_021BC720 *p)
{
    func_02043B5C(func_02045770(p->f24), 3);
}






void func_021BC730(Obj_021BC730 *p)
{
    p->f38 = func_0204B034((u8 *)(&d_021D9B78), 1, p->hC);
}






/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021BC748(u8 *p)
{
    u32 v = ((struct Obj00575 *)p)->f38;
    if (v != 0) {
        func_0204B084(v);
        ((struct Obj00575 *)p)->f38 = 0;
    }
}






void func_021BC75C(Obj_021BC75C *p)
{
    u16 a = func_021BD090((u8 *)p);
    u16 b = func_021BD094(p);

    p->f2C = (void *)func_0204AC18((void *)b, 3, 0, 0x20, 0, 1, a);
}






/*
 * Tail-call thunk: the object's word at +0x2c.
 *
 * Addresses are Black-image addresses.
 */
void func_021BC788(u8 *p)
{
    func_0204ADA4(((struct Obj18190 *)p)->f2C);
}






void func_021BC794(Obj_021BC794 *p)
{
    p->f34 = func_0204B100(0x1E, 1, func_021BD090((unsigned char *)p));
    func_0204B22C(p->f34, 1);
}






/*
 * Tail-call thunk: the object's word at +0x34.
 *
 * Addresses are Black-image addresses.
 */
void func_021BC7B0(u8 *p)
{
    func_0204B1CC((struct Bank *)(((struct Obj18191 *)p)->f34));
}






void func_021BC7BC(Obj_021BC7BC *p, int i)
{
    if (p->f38 != 0) {
        func_0204B258(p->f34[i], p->f38);
    }
}






void func_021BC7D4(Obj_021BC7D4 *p)
{
    int i;

    for (i = 0; i < 0x1E; i++) {
        p->f50[i] = func_021BD148(p->hC, (int)p->f30, 0, (int)p->f2C);
    }
}






void func_021BC7F8(Obj_021BC7F8 *p)
{
    int i;

    for (i = 0; i < 0x1E; i++) {
        func_021BD184(p->f50[i]);
    }
}






void func_021BC810(Obj_021BC810 *p)
{
    p->f10 = func_020490F4(0x54, func_021BD090((u8 *)p));
}






void func_021BC824(u8 *p)
{
    u32 v = ((struct Obj00575 *)p)->f10;
    if (v != 0) {
        func_02049238(v);
        ((struct Obj00575 *)p)->f10 = 0;
    }
}





/*
 * Unlabelled leaf: clears bytes +0x148 and +0x14B.
 */
void func_021BC838(char *p)
{
    p[0x148] = 0;
    p[0x14b] = 0;
}






/*
 * The x accumulation is a compound add inside each if/else arm (the two arms
 * cross-jump into one shared `ldr x; _fadd; str x` tail), then `+= 1.0f`
 * after the join, which is why the original re-loads x it has just stored:
 * a single `x += w` after the if/else forwards the value instead.
 * The call argument is the assignment itself: `f(p->fC8[n] = v, &prm)`
 * gives the `str r0, [r2, r1]` with the fC8 base hoisted.
 */
void func_021BC848(Obj_021BC848 *p)
{
    int n;
    int i;
    u16 buf[32];
    Params prm;

    n = p->count;
    func_02045A38((struct U16Vec *)func_021BD134((u8 *)p), buf, 32);
    prm = d_021D9B88;
    prm.f20 = p->f18;
    prm.ch = buf[n];
    for (i = 0; i < n; i++) {
        if (p->fC8[i] == 0) {
            prm.x += sub_0201DC6C((struct Font *)p->f18, 0x20);
        } else {
            prm.x += func_021BD1EC((u8 *)p->fC8[i]);
        }
        prm.x += 1.0f;
    }
    if (prm.ch == 0x20) {
        p->fC8[n] = 0;
        p->skip++;
    } else {
        func_021BD19C(p->fC8[n] = p->f50[n - p->skip], (u32)(&prm));
    }
    p->count++;
}






int func_021BC910(Obj_021BC910 *p)
{
    if (func_021BD138((u8 *)p) <= p->b148) {
        return 1;
    }
    return 0;
}






void func_021BC92C(Obj_021BC92C *p)
{
    int i;

    for (i = 0; i < 0x1E; i++) {
        func_021BD1E4(p->f50[i], 0);
    }
}






void func_021BC948(Obj_021BC948 *p)
{
    u8 i = p->b149++;

    if (p->fC8[i] != 0) {
        func_021BD1D4(p->fC8[i]);
        func_021BD1E4(p->fC8[i], 1);
    }
}






void func_021BC970(Obj_021BC970 *p)
{
    int n = func_021BD138((u8 *)p);
    int i;

    for (i = 0; i < n; i++) {
        if (p->fC8[i] != 0) {
            func_021BD1CC(p->fC8[i]);
        }
    }
}






void func_021BC998(Obj_021BC998 *p)
{
    p->f30 = func_02025538(func_021BD090((u8 *)p), p->f34);
}







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
    if ((int)func_021BD138((u8 *)p) <= p->b14A) {
        return 1;
    }
    return 0;
}







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







void func_021BCB9C(void *p, int keep)
{
    func_021BD0A0((Obj_021BD0A0 *)p, keep);
    func_021BD0A8(p);
    func_021BD0C8(p);
    if (keep == 0) {
        func_02040588(3, 0);
        func_021BC92C((Obj_021BC92C *)p);
    }
}







void func_021BCBC8(char *p)
{
    int r6;
    int r5;

    switch (((struct Obj05061 *)p)->f3C) {
    case 0:
    case 4:
    case 6:
        return;
    case 3:
    case 5:
        r6 = 5;
        r5 = 30;
        break;
    case 2:
        r6 = 6;
        r5 = (int)(20.0f * (1.0f - (float)(u32)((struct Obj05061 *)p)->f42 / 10.0f));
        break;
    case 1:
        r6 = 0;
        r5 = 0;
        break;
    }
    func_021BCB9C(p, r6);
    ((struct Obj05061 *)p)->f42 = r5;
}







void func_021BCC3C(void *p)
{
    int r = 0;

    if (func_021BCA88(p)) {
        r = 1;
        func_021BCA6C(p);
    } else if (func_021BCA74(p)) {
        if (func_021BCA8C(p)) {
            r = 1;
        }
        func_021BCA80(p);
    }
    if (r) {
        func_021BCB9C(p, 1);
    }
}





void func_021BCC80(char *p)
{
    u32 w;

    switch (func_021BD0C0((u8 *)p)) {
    case 0:
        func_021BCAB0((int *)p);
        func_021BD0D0((Obj_021BD0D0 *)p);
        break;
    case 1:
        func_020414C4(3);
        func_020414EC(3);
        func_021BC6D0((Obj_021BC6D0 *)p);
        func_021BD0D0((Obj_021BD0D0 *)p);
        break;
    case 2:
        func_021BC720((Obj_021BC720 *)p);
        w = *(u32 *)&((struct Obj00183 *)p)->f24;
        func_02045334((struct Descriptor *)w);
        func_02045374((struct Cfg *)w);
        func_020409B4(func_02045730((struct Descriptor *)w));
        func_0204047C(3, 1);
        func_02040588(3, 0);
        func_0207D63C(0x04000050, 8, 0x11, 0x10, 4);
        func_021BC838(p);
        func_021BD0D0((Obj_021BD0D0 *)p);
        break;
    case 3:
        func_021BC848((Obj_021BC848 *)p);
        if (func_021BC910((Obj_021BC910 *)p)) {
            func_021BCB9C(p, 2);
        }
        break;
    }
}




void func_021BCD34(Obj *p)
{
    switch (func_021BD0C0((u8 *)p)) {
    case 0:
        func_021BCEB4((char *)p);
        func_02040588(3, 1);
        func_021BD0D0((Obj_021BD0D0 *)p);
        break;
    case 1:
        if (p->h42 > 10) {
            func_021BCB9C(p, 3);
        }
        break;
    }
}




void func_021BCD70(Obj *p)
{
    if (p->h42 > 10) {
        func_021BCB9C(p, 4);
    }
}



void func_021BCD84(char *p)
{
    switch (func_021BD0C0((u8 *)p)) {
    case 0:
        p[0x149] = 0;
        func_021BD0D0((Obj_021BD0D0 *)p);
        break;
    case 1:
        if (((struct Obj01123 *)p)->f42 % 3 == 0) {
            func_021BC948((Obj_021BC948 *)p);
            if (((struct Obj01123 *)p)->f20 <= ((struct Obj01123 *)p)->f149) {
                func_021BCB9C(p, 5);
            }
        }
        break;
    }
}



void func_021BCDD8(char *p)
{
    int r6 = 1;
    int i;

    switch (func_021BD0C0((u8 *)p)) {
    case 0:
        for (i = 0; i < ((struct Obj01123 *)p)->f20; i++) {
            u32 v = *(u32 *)(p + 0xc8 + i * 4);
            if (v != 0 && func_021BD20C((char *)v) != 0) {
                r6 = 0;
                break;
            }
        }
        if (r6 != 0) {
            func_021BC9C0(p);
            func_021BD0D0((Obj_021BD0D0 *)p);
        }
        break;
    case 1:
        func_021BC9CC(p);
        if (func_021BCA48((Obj_021BCA48 *)p) != 0) {
            func_021BD0D0((Obj_021BD0D0 *)p);
        }
        break;
    case 2:
        func_02045334((struct Descriptor *)((struct Obj01123 *)p)->f24);
        func_021BD0D0((Obj_021BD0D0 *)p);
        break;
    case 3:
        func_021BC92C((Obj_021BC92C *)p);
        func_021BD0D0((Obj_021BD0D0 *)p);
        break;
    case 4:
        if (((struct Obj01123 *)p)->f42 > 0x1e) {
            func_021BCB9C(p, 6);
        }
        break;
    }
}



void func_021BCE88(char *p)
{
    if (((struct Obj01123 *)p)->f42 > 0x14) {
        func_021BCB9C(p, 0);
        func_02040588(3, 0);
        func_021BC92C((Obj_021BC92C *)p);
    }
}


void func_021BCEAC(int a)
{
}


/*
 * Unlabelled leaf (bx lr stub) filed as the blocker of func_021BC4F0.
 */
void func_021BCEB0(int a)
{
}



void func_021BCEB4(char *p)
{
    float t;
    int a;

    t = (float)(u32)((struct Obj20118 *)p)->f42 / 10.0f;
    a = (int)(16.0f * t);
    func_0207D63C(0x04000050, 8, 0x11, a, (int)(4.0f + 12.0f * (1.0f - t)));
}


void func_021BCF18(int a)
{
}
