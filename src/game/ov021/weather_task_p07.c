/*
 * file:     weather_task_p07.c
 * unit:     yes
 * function: func_021A2A84, func_021A2AAC, func_021A2AB8, func_021A2B8C, func_021A2BB8, func_021A2BC4, func_021A2BD4, func_021A2C10, func_021A2C24, func_021A2C28, func_021A2C2C, func_021A2C30, func_021A2C6C, func_021A2C98, func_021A2CC8, func_021A2CEC, func_021A2CF8, func_021A2D04
 * address:  0x021A2A84
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
 *   func_02082BCC  0x02082BCC  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204BA20  0x0204BA20  arm
 *   data_021D88E0  0x021D88E0  data  a4
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_02005C64  0x02005C64  thumb
 *   func_02028A7C  0x02028A7C  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_02028B50  0x02028B50  thumb
 *   func_02006148  0x02006148  thumb
 *   func_020061F8  0x020061F8  thumb
 *   func_021A0224  0x021A0224  thumb  ov021
 */
#include "../../matched/include/Obj02344.h"
#include "../../matched/include/Obj07494.h"
#include "../../matched/include/Obj18004.h"
#include "../../matched/include/Obj12086.h"
#include "../../matched/include/Obj18005.h"
#include "../../matched/include/Obj18006.h"

struct Obj;
struct Actor;
struct SoundSys2;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef signed int     s32;

typedef struct {
    u32 f0;
    s16 f4;
    s16 f6;
    s16 f8;
    s16 fA;
    s16 fC;
    s16 fE;
    s16 f10;
    s16 f12;
    s32 f14;
    void (*f18)(u32 a, s32 b, u32 c);
} Obj;

typedef struct {
    u32 arg;
    short x4;
    short timer;
    short reload;
    u8 padA[0xE];
    void (*cb)(u32 arg, int x, int a);
} Obj021A2B8C;

typedef struct { u16 id; u16 x, y, z; } Q;

typedef struct {
    u16 state;
    u16 id;
    u32 pad4;
    u32 flag;
} Snd021A2C30;

typedef struct {
    u16 state;
    u16 id;
    u32 pad4;
    u32 flag;
} Snd021A2C6C;

typedef struct {
    u16 state;
    u16 id;
    u32 pad4;
    u32 flag;
} Snd021A2C98;

typedef struct {
    u8 pad[0x77C];
    u8 active;
    u8 mode;
    u8 half;
    u8 pad77F;
    u32 value;
} Obj021A2CC8;

typedef struct {
    u32 pad0;
    u32 handle;
    u8 pad8[0x774];
    u8 active;
    u8 mode;
    u8 half;
    u8 pad77F;
    u32 value;
} Obj021A2D04;

extern void func_02082BCC();
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
void func_0204B3DC(struct Obj *h, unsigned int v);
void func_0204BA20(struct Actor *a, u32 v);
extern void func_0204B3B4(struct Obj *p);
int func_02005C64(void);
void func_02028A7C(struct SoundSys2 *s, u32 id);
void func_020061E4(u32 a);
void func_02028B50(u8 *p, int a0);
int func_02006148(u32 a0);
void func_020061F8(int h);
void func_021A0224(u8 *p, u32 a, u32 b, u32 c, u32 d, u16 e);
int func_021A2A84(u32 a, u32 b, u32 c, u32 d, u32 e0, u32 e1, u32 e2, u32 e3, u32 e4, u32 e5);
void func_021A2AAC(char *p, int a, int b, int c, int d);
s32 func_021A2AB8(Obj *o, u32 arg);
int func_021A2B8C(Obj021A2B8C *p, int a);
void func_021A2BB8(u32 a);
int func_021A2BC4(u32 a);
void func_021A2BD4(u32 *p, u32 a, const Q *q, int b, u16 e);
void func_021A2C10(u8 *p);
unsigned char *func_021A2C24(unsigned char *o);
u32 func_021A2C28(u8 *p);
void func_021A2C2C(u8 *p, u32 v);
void func_021A2C30(Snd021A2C30 *p, int a, u16 id);
void func_021A2C6C(Snd021A2C6C *p, int a);
void func_021A2C98(Snd021A2C98 *p, int a);
void func_021A2CC8(Obj021A2CC8 *p, u8 mode, u32 value, int n);
void func_021A2CEC(char *p);
u8 func_021A2CF8(char *p);
void func_021A2D04(Obj021A2D04 *p);
extern u32 data_021D88E0[];






/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A2A84(u32 a, u32 b, u32 c, u32 d, u32 e0, u32 e1, u32 e2, u32 e3, u32 e4, u32 e5)
{
((struct Obj02344 *)((u8 *)(a)))->f0 = b;
((struct Obj02344 *)((u8 *)(a)))->f6 = 0;
((struct Obj02344 *)((u8 *)(a)))->fA = 0;
((struct Obj02344 *)((u8 *)(a)))->f4 = d;
((struct Obj02344 *)((u8 *)(a)))->fC = e0;
((struct Obj02344 *)((u8 *)(a)))->f8 = c;
((struct Obj02344 *)((u8 *)(a)))->fE = e1;
((struct Obj02344 *)((u8 *)(a)))->f10 = e2;
((struct Obj02344 *)((u8 *)(a)))->f12 = e3;
((struct Obj02344 *)((u8 *)(a)))->f14 = e4;
((struct Obj02344 *)((u8 *)(a)))->f18 = e5;
return a;
}






void func_021A2AAC(char *p, int a, int b, int c, int d)
{
    ((struct Obj07494 *)p)->fC = a;
    ((struct Obj07494 *)p)->fE = b;
    ((struct Obj07494 *)p)->f10 = c;
    ((struct Obj07494 *)p)->f14 = d;
}






/*
 * Addresses are Black-image addresses.
 */
s32 func_021A2AB8(Obj *o, u32 arg)
{
    u32 flags;
    s32 neg;

    flags = 0;
    if (o->f10 == 0) {
        flags |= 1;
    } else {
        neg = o->f10 > 0 ? 0 : 1;
        if ((o->f8 >= o->fE && neg == 0) || (o->f8 <= o->fE && neg == 1)) {
            flags |= 1;
            o->f8 = o->fE;
        }
    }
    if (o->f14 == 0) {
        flags |= 2;
    } else {
        neg = o->f14 > 0 ? 0 : 1;
        if ((o->f4 >= o->fC && neg == 0) || (o->f4 <= o->fC && neg == 1)) {
            flags |= 2;
            o->f4 = o->fC;
        }
    }
    o->f6--;
    if (o->f6 <= 0) {
        o->f18(o->f0, o->f4, arg);
        o->f6 = o->f8;
        if (!(flags & 1)) {
            o->f8 += o->f10;
        }
        if (!(flags & 2)) {
            o->fA++;
            if (o->fA >= o->f12) {
                o->fA = 0;
                o->f4 += (s16)o->f14;
            }
        }
    }
    return (flags & 1) ? 1 : 0;
}






int func_021A2B8C(Obj021A2B8C *p, int a)
{
    p->timer--;
    if (p->timer <= 0) {
        p->cb(p->arg, p->x4, a);
        p->timer = p->reload;
        return 1;
    }
    return 0;
}






/*
 * Tail-call thunk: pins arguments 2 and 3 to 0 and 56.
 *
 * Addresses are Black-image addresses.
 */
void func_021A2BB8(u32 a)
{
    func_02082BCC(a, 0, 56);
}






int func_021A2BC4(u32 a)
{
if (((struct Obj18004 *)((u8 *)(a)))->f30 != 0) {
    return 1;
}
return 0;
}





void func_021A2BD4(u32 *p, u32 a, const Q *q, int b, u16 e)
{
    p[0] = a;
    p[1] = (u32)func_0204B294((void *)b, q->x, q->y, q->z, data_021D88E0, 0, e);
    func_0204B3DC((struct Obj *)p[1], 0);
    func_0204BA20((struct Actor *)p[1], 0);
}






/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021A2C10(u8 *p)
{
    u32 v = ((struct Obj12086 *)p)->f4;
    if (v != 0) {
        func_0204B3B4((struct Obj *)v);
        ((struct Obj12086 *)p)->f4 = 0;
    }
}





/*
 * Unlabelled leaf (adds r0,#8; bx lr), filed for the ov026 lane.
 */
unsigned char *func_021A2C24(unsigned char *o)
{
    return o + 8;
}






/*
 * Loads the 32-bit word at byte +0x4 of the object.
 */
u32 func_021A2C28(u8 *p)
{
    return ((struct Obj18005 *)p)->f4;
}






/*
 * Field setter at +0x8.
 *
 * Addresses are Black-image addresses.
 */
void func_021A2C2C(u8 *p, u32 v)
{
    ((struct Obj18006 *)p)->f8 = v;
}




void func_021A2C30(Snd021A2C30 *p, int a, u16 id)
{
    func_021A2C6C((Snd021A2C6C *)p, a);
    if (func_02005C64() == 0) {
        p->state = 1;
        p->id = id;
        if (p->flag != 0)
            func_02028A7C((struct SoundSys2 *)a, p->id);
        else
            func_020061E4(p->id);
    } else {
        p->state = 2;
        p->id = id;
    }
}




void func_021A2C6C(Snd021A2C6C *p, int a)
{
    if (p->state == 1) {
        p->state = 0;
        if (p->flag != 0)
            func_02028B50((u8 *)a, p->id);
        else
            func_020061F8(func_02006148(p->id));
    }
}




void func_021A2C98(Snd021A2C98 *p, int a)
{
    if (p->state == 2 && func_02005C64() == 0) {
        p->state = 1;
        if (p->flag != 0)
            func_02028A7C((struct SoundSys2 *)a, p->id);
        else
            func_020061E4(p->id);
    }
}



void func_021A2CC8(Obj021A2CC8 *p, u8 mode, u32 value, int n)
{
    p->active = 1;
    p->mode = mode;
    p->value = value;
    p->half = n / 2;
}


void func_021A2CEC(char *p)
{
    p[0x77c] = 0;
}



u8 func_021A2CF8(char *p)
{
    return p[0x77c];
}



void func_021A2D04(Obj021A2D04 *p)
{
    func_021A0224((u8 *)p->handle, 0x7FDF, p->value, p->mode, p->mode, p->half);
}
