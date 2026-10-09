/*
 * file:     weather_task_p03.c
 * unit:     yes
 * function: func_021A1BF4, func_021A1BF8, func_021A1C04, func_021A1C1C, func_021A1C34, func_021A1C68, func_021A1D04, func_021A1D78, func_021A1DB4, func_021A1DF8, func_021A1E08, func_021A1FEC, func_021A2050, func_021A20C8, func_021A2108, func_021A2114, func_021A2120, func_021A2130, func_021A213C, func_021A2148, func_021A2154, func_021A2160, func_021A2170, func_021A2180, func_021A2190, func_021A21A0, func_021A21B0, func_021A21B8, func_021A21BC, func_021A21C8, func_021A21E0, func_021A21F8, func_021A2228, func_021A223C, func_021A2248, func_021A2254, func_021A22E0, func_021A231C, func_021A232C, func_021A2390, func_021A23B0, func_021A23D4, func_021A23E8, func_021A23F4, func_021A2400, func_021A240C, func_021A2418, func_021A2424
 * address:  0x021A1BF4
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
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_021A1670  0x021A1670  thumb  ov021
 *   d_021D886C     0x021D886C  data  ov021  a4
 *   d_021D8868     0x021D8868  data  ov021  a4
 *   func_02030734  0x02030734  arm
 *   d_021DDE80     0x021DDE80  data  ov021  a4
 *   func_020307B0  0x020307B0  arm
 *   func_021A2CF8  0x021A2CF8  thumb  ov021
 *   func_021A0244  0x021A0244  thumb  ov021
 *   func_021A2D04  0x021A2D04  thumb  ov021
 *   func_021A2CEC  0x021A2CEC  thumb  ov021
 *   func_021A282C  0x021A282C  thumb  ov021
 *   func_021A2860  0x021A2860  thumb  ov021
 *   func_021A28CC  0x021A28CC  thumb  ov021
 *   func_021A2968  0x021A2968  thumb  ov021
 *   func_021A2724  0x021A2724  thumb  ov021
 *   func_021A2C98  0x021A2C98  thumb  ov021
 *   func_021A27F8  0x021A27F8  thumb  ov021
 *   func_021A2970  0x021A2970  thumb  ov021
 *   func_021A2924  0x021A2924  thumb  ov021
 *   func_021A28A0  0x021A28A0  thumb  ov021
 *   func_021A284C  0x021A284C  thumb  ov021
 *   func_021A26D8  0x021A26D8  thumb  ov021
 *   func_021A2C2C  0x021A2C2C  thumb  ov021
 *   func_021A273C  0x021A273C  thumb  ov021
 *   func_021A0590  0x021A0590  thumb  ov021
 *   func_021A05D8  0x021A05D8  thumb  ov021
 *   func_021A0618  0x021A0618  thumb  ov021
 *   func_021A065C 0x021A065C thumb ov021
 *   func_0218E188 0x0218E188 thumb ov021
 *   func_021A063C 0x021A063C thumb ov021
 *   func_021A16D4 0x021A16D4 thumb ov021
 *   func_021A16E4 0x021A16E4 thumb ov021
 *   func_021A16E8 0x021A16E8 thumb ov021
 *   func_021A16DC 0x021A16DC thumb ov021
 *   func_021A16E0 0x021A16E0 thumb ov021
 *   func_021A274C  0x021A274C  thumb  ov021
 *   func_021A277C  0x021A277C  thumb  ov021
 *   func_021A2BC4  0x021A2BC4  thumb  ov021
 *   func_021A27B8  0x021A27B8  thumb  ov021
 *   func_021A2A84  0x021A2A84  thumb  ov021
 *   func_021A2AAC  0x021A2AAC  thumb  ov021
 *   func_021A2AB8 0x021A2AB8 thumb ov021
 *   func_021A2B8C 0x021A2B8C thumb ov021
 *   _s32_div_f     0x0209C0A4  arm
 *   func_021A01AC  0x021A01AC  thumb  ov021
 *   func_021A01CC  0x021A01CC  thumb  ov021
 *   func_021A01B4  0x021A01B4  thumb  ov021
 *   func_021A01BC  0x021A01BC  thumb  ov021
 *   func_021A01D8  0x021A01D8  thumb  ov021
 *   func_021A01A4  0x021A01A4  thumb  ov021
 *   func_021A01FC  0x021A01FC  thumb  ov021
 *   func_021A01D4  0x021A01D4  thumb  ov021
 *   func_021A2CC8  0x021A2CC8  thumb  ov021
 *   func_021A0354  0x021A0354  thumb  ov021
 *   func_021A0380  0x021A0380  thumb  ov021
 *   func_021A0390  0x021A0390  thumb  ov021
 *   func_021A03A4  0x021A03A4  thumb  ov021
 *   func_021A03B8  0x021A03B8  thumb  ov021
 *   func_021A03CC  0x021A03CC  thumb  ov021
 *   func_0218EC2C  0x0218EC2C  thumb  ov021
 *   func_02048B30  0x02048B30  arm
 */
#include "../../matched/include/Obj17998.h"
#include "../../matched/include/Obj00755.h"
#include "../../matched/include/Obj01356.h"
#include "../../matched/include/Obj03584.h"
#include "../../matched/include/Obj18000.h"
#include "../../matched/include/Obj18001.h"
#include "../../matched/include/Obj19728.h"
#include "../../matched/include/Obj00954.h"
#include "../../matched/include/Obj19729.h"
#include "../../matched/include/Obj19731.h"
#include "../../matched/include/Obj02702.h"
#include "../../matched/include/Obj12713.h"
#include "../../matched/include/Obj18002.h"
#include "../../matched/include/Obj02702.h"

struct O;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int s32;

typedef struct {
    u32 pad0;
    u32 pad4;
    u16 result;
    u16 busy;
    u16 cur;
    u16 next;
    u32 flag;
    u16 queued;
} Obj021A1C34;

typedef signed short s16;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fC;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1C;
    u32 *f20;
    u8 lo24 : 4;
    u8 hi24 : 4;
    u8 pad25;
    u8 state;
    u8 flag;
    u8 pad28[0x18];
    u8 sub40[4];
} Obj_021A1E08;

typedef struct O {
    u32 pad0[8];
    u32 f20;
    u8  lo : 4;
    u8  hi : 4;
    u8  f25;
    u8  f26;
    u8  pad27[0x19];
    u8  f40;
} O;

typedef struct O_021A2050 {
    u32 pad0[9];
    u8  lo : 4;
    u8  hi : 4;
    u8  f25;
    u8  f26;
} O_021A2050;

typedef struct O_021A20C8 {
    u32 pad0[8];
    u32 *f20;
    u8  pad24[2];
    u8  f26;
} O_021A20C8;

typedef signed char s8;

typedef struct {
    int x;
    int y;
    int z;
} Vec021A2424;

extern int func_02034AC4(s32 handle);
void func_02034A5C(int x);
void func_021A1670(u8 *p);
extern void *func_02030734(u32 a, u32 b, int c, const char *d, u16 e);
extern u32 func_020307B0(void *p);
extern u8 func_021A2CF8(char *p);
extern int func_021A0244(u8 *p);
extern void func_021A2D04(Obj_021A1E08 *o);
extern void func_021A2CEC(char *p);
extern int func_021A282C(Obj_021A1E08 *o, s32 x);
extern void func_021A2860(Obj_021A1E08 *o, s32 x);
extern void func_021A28CC(Obj_021A1E08 *o, s32 x);
extern void func_021A2968(u8 *p);
extern s32 func_021A2724(Obj_021A1E08 *o, u32 a, s32 x);
extern void func_021A2C98(void *p, u32 a);
extern void func_021A27F8(Obj_021A1E08 *o);
extern u8 func_021A2970(u8 *p);
extern void func_021A2924(Obj_021A1E08 *o);
extern void func_021A28A0(Obj_021A1E08 *o);
extern int func_021A284C(Obj_021A1E08 *o);
extern void func_021A26D8(int *p);
extern void func_021A2C2C(u8 *p, u32 v);
extern u8 func_021A273C(u8 *p);
extern u32 func_021A0590(u32, u32, u32, u32);
void func_021A05D8(u8 *a);
extern void func_021A0618(u8 *p, u32 a, u32 b, u32 c);
extern int func_021A065C(u8 *p);
int func_0218E188(unsigned char *o);
extern void func_021A063C(u8 *p, u32 b, u32 c);
extern void func_021A16D4(unsigned char *p, unsigned int v);
extern void func_021A16E4(unsigned char *p, unsigned int v);
extern void func_021A16E8(unsigned char *p, unsigned int v);
extern void func_021A16DC(unsigned char *p, unsigned int v);
extern void func_021A16E0(unsigned char *p, unsigned int v);
void *func_021A274C(void *p);
void func_021A277C(void *p, void *q);
int func_021A2BC4(u32 a);
void func_021A27B8(u32 x, u32 *p);
int func_021A2A84(u32 a, u32 b, u32 c, u32 d, u32 e0, u32 e1, u32 e2, u32 e3, u32 e4, u32 e5);
void func_021A2AAC(char *p, int a, int b, int c, int d);
extern int func_021A2AB8(unsigned char *o, int arg);
extern int func_021A2B8C(unsigned char *o, int arg);
int func_021A01AC(u32 a, u32 b);
int func_021A01CC(u32 a, u32 b);
int func_021A01B4(u32 a, u32 b);
int func_021A01BC(u32 a, u32 b);
void func_021A01D8(u8 *p);
int func_021A01A4(u32 a, u32 b);
extern void func_021A01FC(u8 *p, u32 a, u32 b, u32 c);
extern u32 func_021A01D4(u8 *p);
extern void func_021A2CC8(void *p, int a, int b, int c);
u8 func_021A0354(u8 *p);
int func_021A0380(int *p);
int func_021A0390(int *p);
int func_021A03A4(int *p);
int func_021A03B8(int *p);
int func_021A03CC(int *p);
u32 func_0218EC2C(u8 *p);
void func_02048B30(u32 x, Vec021A2424 *out);
u16 func_021A1BF4(u8 *p);
void func_021A1BF8(u32 *p, u32 v);
void func_021A1C04(u8 *p);
void func_021A1C1C(int a, u32 *p);
int func_021A1C34(Obj021A1C34 *p, u16 x);
void func_021A1C68(u8 *p, int x);
void func_021A1D04(u8 *p, int x);
int func_021A1D78(u16 a, u16 b);
u32 *func_021A1DB4(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u16 h, u16 i);
void func_021A1DF8(u8 *p);
void func_021A1E08(Obj_021A1E08 *o, s32 x);
void func_021A1FEC(O *p, u32 v, u8 b, u32 c, u32 d, u32 e, u32 g);
void func_021A2050(O_021A2050 *p, u32 a, u32 b);
void func_021A20C8(O_021A20C8 *p);
int func_021A2108(u32 a, int b, int c);
int func_021A2114(u32 a, int b, u32 c);
void func_021A2120(u32 *p, int x);
void func_021A2130(u8 *p, u32 b, u32 c, u32 d);
int func_021A213C(u8 *p);
int func_021A2148(unsigned char *o);
void func_021A2154(u8 *p, u32 b, u32 c);
void func_021A2160(unsigned char *o, unsigned int v, int i);
void func_021A2170(unsigned char *o, unsigned int v, int i);
void func_021A2180(unsigned char *o, unsigned int v, int i);
void func_021A2190(unsigned char *o, unsigned int v, int i);
void func_021A21A0(unsigned char *o, unsigned int v, int i);
int func_021A21B0(u8 *a0);
int *func_021A21B8(int *p);
int func_021A21BC(unsigned char *o);
void *func_021A21C8(void *p, int a1);
void func_021A21E0(u32 *p);
void func_021A21F8(u8 *p, int a, int b, int c, int d, int e, int f, int g, int h);
void func_021A2228(u8 *p, int a, int b, int c, int d);
int func_021A223C(unsigned char *o, int arg);
int func_021A2248(unsigned char *o, int arg);
void func_021A2254(u8 *p, void (*fn)(u8 *, int, u32), int n, int m, int k, u16 w);
void func_021A22E0(u32 *p, int a, int b, int c);
void func_021A231C(u32 *p, int x);
void func_021A232C(u8 *p, int a, int b, int c, int d);
void func_021A2390(u32 *p, int a, int b, int c);
int func_021A23B0(u32 a);
int func_021A23D4(int *p);
int func_021A23E8(int *p);
int func_021A23F4(int *p);
int func_021A2400(int *p);
int func_021A240C(int *p);
int func_021A2418(int *p);
void func_021A2424(u8 *p);
extern const u32 d_021D886C[];
extern const u32 d_021D8868[];
extern u8 d_021DDE80[];











/*
 * Loads the 16-bit halfword at +0xc of the object.
 */
u16 func_021A1BF4(u8 *p)
{
    return ((struct Obj17998 *)p)->fC;
}











/*
 * Stores the word at +0x28, then tail calls on it.
 *
 * Addresses are Black-image addresses.
 */
void func_021A1BF8(u32 *p, u32 v)
{
    p[0xa] = v;
    func_02034AC4(v);
}











void func_021A1C04(u8 *p)
{
    if (((struct Obj00755 *)p)->f28 != -1) {
        func_02034A5C(((struct Obj00755 *)p)->f28);
        ((struct Obj00755 *)p)->f28 = -1;
    }
}











void func_021A1C1C(int a, u32 *p)
{
    int i;

    for (i = 0; i < 2; i++)
        func_021A1670((u8 *)p[i]);
}











int func_021A1C34(Obj021A1C34 *p, u16 x)
{
    if (p->busy != 0) {
        p->queued = x;
        return 0;
    }
    if (p->cur == x && x != 0)
        return 0;
    p->next = x;
    p->flag = 1;
    p->result = func_021A1D78(p->cur, p->next);
    p->busy = 1;
    return 1;
}











/*
 * Addresses are Black-image addresses.
 */
void func_021A1C68(u8 *p, int x)
{
    switch (((struct Obj00755 *)p)->fA) {
    case 0:
        break;
    case 1:
        func_021A2050((O_021A2050 *)((struct O *)(((struct Obj00755 *)p)->f20)), 1, 1);
        ((struct Obj00755 *)p)->fA = 2;
        break;
    case 2:
        if (func_021A21B0((u8 *)(((struct Obj00755 *)p)->f20)) == 0) {
            func_021A1C04(p);
            ((struct Obj00755 *)p)->fA = 3;
        }
        break;
    case 3:
        func_021A1BF8((u32 *)p, d_021D886C[((struct Obj00755 *)p)->fE * 2]);
        ((struct Obj00755 *)p)->fA = 4;
        break;
    case 4:
        func_021A1FEC((O *)((struct O *)(((struct Obj00755 *)p)->f20)), d_021D8868[((struct Obj00755 *)p)->fE * 2], 1, 1, 1, ((struct Obj00755 *)p)->f10, x);
        ((struct Obj00755 *)p)->f10 = 1;
        ((struct Obj00755 *)p)->fC = ((struct Obj00755 *)p)->fE;
        ((struct Obj00755 *)p)->fE = 0xFFFF;
        ((struct Obj00755 *)p)->fA = 0;
        break;
    }
}











void func_021A1D04(u8 *p, int x)
{
    u32 t;

    switch (((struct Obj01356 *)p)->fA) {
    case 0:
        break;
    case 1:
        func_021A1FEC((O *)((struct O *)(((struct Obj01356 *)p)->f24)), d_021D8868[((struct Obj01356 *)p)->fE * 2], 1, 1, 2, ((struct Obj01356 *)p)->f10, x);
        func_021A2050((O_021A2050 *)((struct O *)(((struct Obj01356 *)p)->f20)), 1, 2);
        ((struct Obj01356 *)p)->fA = 2;
        break;
    case 2:
        if (func_021A21B0((u8 *)(((struct Obj01356 *)p)->f20)) == 0) {
            t = ((struct Obj01356 *)p)->f20;
            ((struct Obj01356 *)p)->f20 = ((struct Obj01356 *)p)->f24;
            ((struct Obj01356 *)p)->f24 = t;
            ((struct Obj01356 *)p)->fC = ((struct Obj01356 *)p)->fE;
            ((struct Obj01356 *)p)->fE = 0xFFFF;
            ((struct Obj01356 *)p)->f10 = 1;
            ((struct Obj01356 *)p)->fA = 0;
        }
        break;
    }
}











int func_021A1D78(u16 a, u16 b)
{
    int r = 0;

    switch (a) {
    case 1:
        if ((u16)(b + 0xFFFC) <= 1)
            r = 1;
        break;
    case 4:
        if (b == 1 || b == 5)
            r = 1;
        break;
    case 5:
        if (b == 4 || b == 1)
            r = 1;
        break;
    }
    return r;
}











u32 *func_021A1DB4(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u16 h, u16 i)
{
    u32 *o;

    o = func_02030734(i, 0x784, 1, (const char *)d_021DDE80, 0x17E);
    o[0] = a;
    o[5] = b;
    o[1] = d;
    o[2] = c;
    o[4] = e;
    o[6] = f;
    o[3] = g;
    ((struct Obj03584 *)o)->f1C = h;
    return o;
}











/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021A1DF8(u8 *p)
{
    func_021A20C8((O_021A20C8 *)((struct O *)p));
    func_020307B0(p);
}










void func_021A1E08(Obj_021A1E08 *o, s32 x)
{
    if (func_021A2CF8((char *)o) != 0 && func_021A0244((u8 *)o->f4) == 0) {
        func_021A2D04(o);
        func_021A2CEC((char *)o);
    }
    switch (((u8 *)o)[0x26]) {
    case 0:
        break;
    case 1:
        func_021A282C(o, x);
        func_021A2860(o, x);
        func_021A28CC(o, x);
        func_021A2968((u8 *)o);
        ((u8 *)o)[0x26] = 5;
        break;
    case 2:
        func_021A282C(o, x);
        ((u8 *)o)[0x26] = 3;
        break;
    case 3:
        func_021A2860(o, x);
        ((u8 *)o)[0x26] = 4;
        break;
    case 4:
        func_021A28CC(o, x);
        ((u8 *)o)[0x26] = 5;
        break;
    case 5:
        if (func_021A2724(o, o->f20[11], x) != 0) {
            ((u8 *)o)[0x26] = o->hi24 != 0 ? 6 : 7;
        }
        func_021A2C98(o->sub40, o->fC);
        func_021A2968((u8 *)o);
        break;
    case 6:
        if (func_021A2724(o, o->f20[12], x) != 0) {
            ((u8 *)o)[0x26] = 8;
        }
        func_021A27F8(o);
        func_021A2C98(o->sub40, o->fC);
        break;
    case 7:
        if (func_021A2724(o, o->f20[13], x) != 0) {
            ((u8 *)o)[0x26] = 8;
        }
        func_021A2C98(o->sub40, o->fC);
        break;
    case 8:
        func_021A2724(o, o->f20[14], x);
        func_021A27F8(o);
        func_021A2C98(o->sub40, o->fC);
        break;
    case 9:
        if (func_021A2724(o, o->f20[15], x) != 0) {
            ((u8 *)o)[0x26] = 10;
        }
        func_021A27F8(o);
        func_021A2C98(o->sub40, o->fC);
        break;
    case 10:
        if (func_021A2724(o, o->f20[16], x) != 0) {
            ((u8 *)o)[0x26] = 11;
        }
        func_021A27F8(o);
        func_021A2C98(o->sub40, o->fC);
        break;
    case 11:
        if (func_021A2970((u8 *)o) != 0) {
            func_021A2724(o, o->f20[17], x);
        }
        ((u8 *)o)[0x26] = 12;
        break;
    case 12:
        func_021A2924(o);
        func_021A28A0(o);
        func_021A284C(o);
        func_021A26D8((int *)o);
        ((u8 *)o)[0x26] = 0;
        break;
    }
}










void func_021A1FEC(O *p, u32 v, u8 b, u32 c, u32 d, u32 e, u32 g)
{
    p->f20 = v;
    p->lo = (u8)d;
    p->hi = (u8)c;
    p->f25 = b;
    if (p->f25 == 0) {
        p->f26 = 1;
    } else if (p->f25 == 1) {
        p->f26 = 2;
    }
    func_021A2C2C(&p->f40, e);
}









void func_021A2050(O_021A2050 *p, u32 a, u32 b)
{
    u32 r;
    u32 s;

    r = func_021A273C((u8 *)p);
    s = p->f26;
    if (s == 0) {
        return;
    }
    if (r - 4 <= 1) {
        return;
    }
    p->hi = (u8)a;
    p->lo = (u8)b;
    if (s <= 5) {
        p->f26 = 0xb;
        return;
    }
    if (p->hi != 0) {
        p->f26 = 9;
        return;
    }
    p->f26 = 0xb;
}









void func_021A20C8(O_021A20C8 *p)
{
    if (p->f26 == 0) {
        return;
    }
    if (p->f26 <= 0xb) {
        func_021A2724((Obj_021A1E08 *)p, p->f20[0x11], 0);
    }
    if (p->f26 <= 0xc) {
        func_021A2924((Obj_021A1E08 *)p);
        func_021A28A0((Obj_021A1E08 *)p);
        func_021A284C((Obj_021A1E08 *)p);
    }
    func_021A26D8((int *)p);
}








/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A2108(u32 a, int b, int c)
{
return func_021A0590(((struct Obj18000 *)((u8 *)(a)))->f8, b, c, 60);
}








int func_021A2114(u32 a, int b, u32 c)
{
return func_021A0590(((struct Obj18001 *)((u8 *)(a)))->f8, b, c, 1);
}








void func_021A2120(u32 *p, int x)
{
    if (x == 1)
        func_021A05D8((u8 *)p[2]);
}








void func_021A2130(u8 *p, u32 b, u32 c, u32 d)
{
    func_021A0618((u8 *)(((struct Obj19728 *)p)->f8), b, c, d);
}








/*
 * Unlabelled tail-call stub, filed for the ov026 lane.
 */
int func_021A213C(u8 *p)
{
    return func_021A065C(*(u8 * *)&((struct Obj00954 *)p)->f8);
}








/*
 * Unlabelled tail-call leaf (ldr r0,[r0,#0x14]; ldr r3,[pc]; bx r3), filed
 * for lane S30 (callee of ov028 functions).
 */
int func_021A2148(unsigned char *o)
{
    return func_0218E188((unsigned char *)(((struct Obj19729 *)o)->f14));
}








void func_021A2154(u8 *p, u32 b, u32 c)
{
    func_021A063C(*(u8 * *)&((struct Obj00954 *)p)->f8, b, c);
}







void func_021A2160(unsigned char *o, unsigned int v, int i)
{
    func_021A16D4((*(unsigned char ***)(o + 0x18))[i], v);
}







void func_021A2170(unsigned char *o, unsigned int v, int i)
{
    func_021A16E4((*(unsigned char ***)(o + 0x18))[i], v);
}







void func_021A2180(unsigned char *o, unsigned int v, int i)
{
    func_021A16E8((*(unsigned char ***)(o + 0x18))[i], v);
}







void func_021A2190(unsigned char *o, unsigned int v, int i)
{
    func_021A16DC((*(unsigned char ***)(o + 0x18))[i], v);
}







void func_021A21A0(unsigned char *o, unsigned int v, int i)
{
    func_021A16E0((*(unsigned char ***)(o + 0x18))[i], v);
}







/*
 * Tail-call thunk: forwards to func_021A273C with no argument change.
 *
 * Addresses are Black-image addresses.
 */
int func_021A21B0(u8 *a0)
{
    return func_021A273C(a0);
}






/*
 * Unlabelled 4-byte leaf: returns field 0x3c (ldr r0,[r0,#0x3c]).
 */
int *func_021A21B8(int *p)
{
    return (int *)p[15];
}







/*
 * Unlabelled leaf (ldr r1,[pc]; ldr r0,[r0,r1]; bx lr; pool 0x778), filed
 * for lane S30 (callee of ov027/ov028 functions).
 */
int func_021A21BC(unsigned char *o)
{
    return ((struct Obj19731 *)o)->f778;
}







void *func_021A21C8(void *p, int a1)
{
    void *r = func_021A274C(p);

    if (r != 0)
        func_021A277C(p, r);
    return r;
}







void func_021A21E0(u32 *p)
{
    if (func_021A2BC4((u32)p) != 0)
        func_021A27B8(p[0], p);
}







void func_021A21F8(u8 *p, int a, int b, int c, int d, int e, int f, int g, int h)
{
    func_021A2A84((u32)(p + 0x4C), (u32)p, b, a, c, d, e, f, g, h);
}







void func_021A2228(u8 *p, int a, int b, int c, int d)
{
    func_021A2AAC((char *)(p + 0x4C), a, b, c, d);
}







int func_021A223C(unsigned char *o, int arg)
{
    return func_021A2AB8(o + 0x4C, arg);
}







/*
 * Unlabelled tail-call stub, filed for lane S30 (callee of ov027 functions).
 */
int func_021A2248(unsigned char *o, int arg)
{
    return func_021A2B8C(o + 0x4C, arg);
}






void func_021A2254(u8 *p, void (*fn)(u8 *, int, u32), int n, int m, int k, u16 w)
{
    int j;
    u8 *cur;
    int cnt;
    int i;
    u8 *next;

    fn(p, n, w);
    cnt = 0;
    cur = *(u8 * *)&((struct Obj02702 *)p)->f774;
    if (cur == 0) {
        return;
    }
    next = *(u8 * *)&((struct Obj12713 *)cur)->f34;
    i = 0;
    if (n <= 0) {
        return;
    }
    do {
        j = 0;
        if (cnt > 0) {
            do {
                ((void (*)(u8 *))(*(u32 *)(*(u32 *)(p + 0x20) + 0x48)))(cur);
                if (func_021A2BC4((u32)cur) == 0) {
                    break;
                }
                j++;
            } while (j < cnt);
        }
        cur = next;
        next = *(u8 * *)&((struct Obj12713 *)cur)->f34;
        if (i >= m) {
            if (i % m == 0) {
                cnt += k;
            }
        }
        if (cur == *(u8 * *)&((struct Obj02702 *)p)->f774) {
            break;
        }
        i++;
    } while (i < n);
}






void func_021A22E0(u32 *p, int a, int b, int c)
{
    if (c == 1) {
        func_021A01AC(p[1], 0);
        func_021A01CC(p[1], 0x1F);
        func_021A01B4(p[1], a);
        func_021A01BC(p[1], b);
        func_021A01D8((u8 *)p[1]);
        func_021A01A4(p[1], 1);
    }
}






void func_021A231C(u32 *p, int x)
{
    if (x == 1)
        func_021A01A4(p[1], 0);
}






void func_021A232C(u8 *p, int a, int b, int c, int d)
{
    int h;

    if (d == 1) {
        func_021A01FC((u8 *)(((struct Obj00954 *)p)->f4), b, a, c);
        return;
    }
    if (d == 2) {
        if (a == func_021A01D4((u8 *)(((struct Obj00954 *)p)->f4))) {
            func_021A01FC((u8 *)(((struct Obj00954 *)p)->f4), b, a, c);
            return;
        }
        h = c / 2;
        func_021A01FC((u8 *)(((struct Obj00954 *)p)->f4), 0x7FDF, func_021A01D4((u8 *)(((struct Obj00954 *)p)->f4)), h);
        func_021A2CC8(p, a, b, h);
    }
}






void func_021A2390(u32 *p, int a, int b, int c)
{
    if (c == 1)
        func_021A01FC((u8 *)p[1], a, func_021A01D4((u8 *)p[1]), b);
}






int func_021A23B0(u32 a)
{
if (func_021A0244((u8 *)(((struct Obj18002 *)((u8 *)(a)))->f4)) != 0) {
    return 0;
}
if (func_021A2CF8((char *)a) == 0) {
    return 1;
}
return 0;
}






int func_021A23D4(int *p)
{
    if (func_021A0354((u8 *)p[4]) == 1) {
        return 1;
    }
    return 0;
}





/*
 * Unlabelled tail-call stub, filed as a blocker of the ov024 lane S26.
 */
int func_021A23E8(int *p)
{
    return func_021A0380((int *)p[4]);
}





int func_021A23F4(int *p)
{
    return func_021A0390((int *)p[4]);
}





int func_021A2400(int *p)
{
    return func_021A03A4((int *)p[4]);
}




int func_021A240C(int *p)
{
    return func_021A03B8((int *)p[4]);
}




int func_021A2418(int *p)
{
    return func_021A03CC((int *)p[4]);
}


void func_021A2424(u8 *p)
{
    Vec021A2424 v;

    if (((struct Obj02702 *)p)->f14 != 0) {
        func_02048B30(func_0218EC2C((u8 *)(((struct Obj02702 *)p)->f14)), &v);
        *(Vec021A2424 *)(p + 0x68) = v;
    }
}
