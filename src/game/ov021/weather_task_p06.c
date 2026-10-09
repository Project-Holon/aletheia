/*
 * file:     weather_task_p06.c
 * unit:     yes
 * function: func_021A2A84, func_021A2AAC, func_021A2AB8, func_021A2B8C, func_021A2BB8, func_021A2BC4, func_021A2BD4, func_021A2C10, func_021A2C24, func_021A2C28, func_021A2C2C, func_021A2C30, func_021A2C6C, func_021A2C98, func_021A2CC8, func_021A2CEC, func_021A2CF8, func_021A2D04, func_021A2D30, func_021A2D88, func_021A2DE4, func_021A2DF0, func_021A2E34, func_021A2E44, func_021A2E50, func_021A2E90, func_021A2EB8, func_021A2F20, func_021A2F48, func_021A2F54, func_021A2F60, func_021A2F6C, func_021A2F8C, func_021A2F98, func_021A2FA4, func_021A2FB0, func_021A2FD0, func_021A2FE4, func_021A3038, func_021A3044, func_021A3050, func_021A305C, func_021A3068, func_021A3074, func_021A3080, func_021A308C, func_021A3098, func_021A30A4, func_021A30B0, func_021A30BC, func_021A30C8, func_021A3128, func_021A3190, func_021A31A4
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
 *   func_0207C768  0x0207C768  arm
 *   func_02030734  0x02030734  arm
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_021A35E0  0x021A35E0  thumb  ov021
 *   func_0216D888  0x0216D888  thumb  ov010
 *   func_02188D40  0x02188D40  thumb  ov021
 *   func_02188CAC  0x02188CAC  thumb  ov021
 *   d_021DDE90     0x021DDE90  data  a4
 *   func_02188CA4  0x02188CA4  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   func_020362DC  0x020362DC  arm
 *   func_0203630C  0x0203630C  arm
 *   func_021A35BC  0x021A35BC  thumb
 *   func_021A35F0  0x021A35F0  thumb
 *   func_021A36E4  0x021A36E4  thumb  ov021
 *   d_021DDEA8     0x021DDEA8  data  a4
 *   func_021A41A8  0x021A41A8  thumb  ov021
 *   func_021A5920  0x021A5920  thumb  ov021
 *   func_021A3810  0x021A3810  thumb  ov021
 *   func_021A3994  0x021A3994  thumb
 *   func_021A3960  0x021A3960  thumb
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_02012A90  0x02012A90  thumb
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_02012AD4  0x02012AD4  thumb
 *   func_02188CFC  0x02188CFC  thumb
 *   func_02012ABC  0x02012ABC  thumb
 *   func_0219E2F4  0x0219E2F4  thumb
 *   func_02012AA4  0x02012AA4  thumb
 *   func_021C0CA4  0x021C0CA4  thumb  ov021
 *   func_021A3CB0  0x021A3CB0  thumb
 *   func_021A3CC0  0x021A3CC0  thumb
 *   func_021A3CE8  0x021A3CE8  thumb
 *   func_021A53D0  0x021A53D0  thumb  ov021
 *   func_021A5A34  0x021A5A34  thumb  ov021
 *   func_021A3AD0  0x021A3AD0  thumb  ov021
 *   func_021A3AD4  0x021A3AD4  thumb
 *   func_021A3AB8  0x021A3AB8  thumb
 *   func_021A5778  0x021A5778  thumb  ov021
 *   func_021A59DC  0x021A59DC  thumb  ov021
 *   func_021A548C  0x021A548C  thumb
 *   func_021A54A0  0x021A54A0  thumb
 *   func_021A59EC  0x021A59EC  thumb
 *   func_021A396C  0x021A396C  thumb
 *   func_021A3818  0x021A3818  thumb
 *   func_021A3898  0x021A3898  thumb
 *   func_021A38A4  0x021A38A4  thumb
 *   func_021A3920  0x021A3920  thumb
 *   func_021A392C  0x021A392C  thumb  ov021
 *   func_021A395C  0x021A395C  thumb
 *   func_021A3968  0x021A3968  thumb  ov021
 *   func_021A3970  0x021A3970  thumb  ov021
 *   func_021A3974  0x021A3974  thumb
 *   func_021A3980  0x021A3980  thumb
 *   func_021A398C  0x021A398C  thumb
 *   func_021A3990  0x021A3990  thumb
 *   func_02188C5C  0x02188C5C  thumb
 *   func_02188C98  0x02188C98  thumb
 *   func_021AB0D4  0x021AB0D4  thumb
 *   func_021BB3C4  0x021BB3C4  thumb
 *   func_021A3364  0x021A3364  thumb
 *   func_0219E664  0x0219E664  thumb
 *   data_021D890C  0x021D890C  data
 */
#include "../../matched/include/Obj02344.h"
#include "../../matched/include/Obj07494.h"
#include "../../matched/include/Obj18004.h"
#include "../../matched/include/Obj12086.h"
#include "../../matched/include/Obj18005.h"
#include "../../matched/include/Obj18006.h"
#include "../../matched/include/Obj12722.h"
#include "../../matched/include/Obj19760.h"
#include "../../matched/include/Obj19761.h"
#include "../../matched/include/Obj05861.h"
#include "../../matched/include/Obj18007.h"
#include "../../matched/include/Obj18008.h"
#include "../../matched/include/Obj19763.h"
#include "../../matched/include/Obj18009.h"
#include "../../matched/include/Obj18010.h"
#include "../../matched/include/Obj09180.h"
#include "../../matched/include/Obj00614.h"
#include "../../matched/include/Obj18011.h"
#include "../../matched/include/Obj18012.h"
#include "../../matched/include/Obj18013.h"
#include "../../matched/include/Obj19764.h"
#include "../../matched/include/Obj18014.h"
#include "../../matched/include/Obj18015.h"
#include "../../matched/include/Obj18016.h"
#include "../../matched/include/Obj18017.h"
#include "../../matched/include/Obj19765.h"
#include "../../matched/include/Obj19766.h"
#include "../../matched/include/Obj18018.h"

struct Obj_021A2AB8;
struct Actor;
struct SoundSys2;
struct Obj00020;
struct H4;
struct Rec44;
struct Vec12;
struct V3;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short s16;

typedef signed char s8;

typedef signed int s32;

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
} Obj_021A2AB8;

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

typedef struct V3 { int x, y, z; } V3;

typedef struct {
    int f0;
    int pad4[4];
    int f14;
} Obj_021A2D30;

typedef struct { s32 a, b; } Pair_021A2D30;

typedef struct {
    u16 a;
    u16 b;
} Pair_021A3190;

typedef struct {
    Pair_021A3190 e[10];
} Row;

extern void func_02082BCC();
extern struct Obj_021A2AB8 *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
void func_0204B3DC(struct Obj_021A2AB8 *h, unsigned int v);
void func_0204BA20(struct Actor *a, u32 v);
extern void func_0204B3B4(struct Obj_021A2AB8 *p);
int func_02005C64(void);
void func_02028A7C(struct SoundSys2 *s, u32 id);
void func_020061E4(u32 a);
void func_02028B50(u8 *p, int a0);
int func_02006148(u32 a0);
void func_020061F8(int h);
void func_021A0224(u8 *p, u32 a, u32 b, u32 c, u32 d, u16 e);
u32 func_0207C768(u32 a, u32 b);
void *func_02030734(unsigned int a, unsigned int b, int c, const char *d, u16 e);
u16 func_02188C84(u8 *p);
void *func_02188CB4(struct Obj00020 *p);
void func_0216D5E0(int a0, int a1);
void func_021A35E0(u32 *p, u32 heap);
void *func_0216D888(void *a);
void func_02188D40(u8 *p, u32 v);
void func_02188CAC(u8 *p, u32 v);
extern u32 func_020307B0(void *p);
extern u32 func_02188CA4(u8 *p);
extern u32 func_020362DC(void);
extern unsigned int func_0203630C(void);
extern int func_021A35BC(int a);
extern int func_021A35F0(u32 a, u32 b, u32 c, u32 d);
u32 func_021A36E4(int a, u32 b, int c, int d, u16 heap);
extern void func_021A3810(u32 a0);
extern void func_021A41A8(void);
extern void func_021A5920(void);
extern u32 func_021A3994(u8 *p);
extern void *func_021A3960(unsigned char *p);
extern void func_0216D88C(const struct Actor *, struct V3 *);
extern void func_02012A90(struct Rec44 *p, const struct Vec12 *src);
extern u16 func_0216D5F8(void *p);
extern void func_02012AD4(u8 *p, int i);
extern u32 func_02188CFC(u8 *p);
extern void func_02012ABC(struct Rec44 *p, u8 v);
extern void func_0219E2F4(void *o, void *out);
extern void func_02012AA4(struct Rec44 *p, const struct H4 *src);
int func_021C0CA4(u8 *a, int b, int c, int d);
extern int func_021A3CB0(u32 a, u32 b);
extern int func_021A3CC0(void *p);
extern u32 func_021A3CE8(int a);
void func_021A53D0(u32 *p);
void func_021A5A34(u32 *p);
extern void func_021A3AD0(u8 *p, u32 v);
extern u32 func_021A3AD4(u8 *p);
extern u16 func_021A3AB8(u32 a, u32 v);
extern int func_021A5778(u32 a);
extern int func_021A59DC(u32 a);
extern int func_021A548C();
extern int func_021A54A0(u32 a);
extern u32 func_021A59EC(u32 p);
extern void func_021A396C(u8 *p, u32 v);
extern void func_021A3818(u32 *p);
extern void func_021A3898(u8 *p, struct V3 *out);
extern void func_021A38A4(u8 *p, void *v);
extern u16 func_021A3920(u8 *p);
void func_021A392C(void *p, int b);
extern u32 func_021A395C(u8 *p);
extern u32 func_021A3968(u32 *p);
extern u32 func_021A3970(u32 *p);
extern u32 func_021A3974(u8 *p);
extern void func_021A3980(u8 *p, u32 a1);
extern u32 func_021A398C(u8 *p);
extern u32 func_021A3990(u8 *p);
extern u16 func_02188C98(void *p);
extern int func_021AB0D4(void *a, void *b);
extern u32 func_02188C5C(u8 *p);
extern u32 func_021BB3C4(u8 *p, char *a1);
extern void func_021A3364(u32 *a, int b, int *out);
extern int func_0219E664(void *o, u32 k, void *buf);
int func_021A2A84(u32 a, u32 b, u32 c, u32 d, u32 e0, u32 e1, u32 e2, u32 e3, u32 e4, u32 e5);
void func_021A2AAC(char *p, int a, int b, int c, int d);
s32 func_021A2AB8(Obj_021A2AB8 *o, u32 arg);
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
void func_021A2D30(Obj_021A2D30 *o, int v, int *out2, int *out1);
void func_021A2D88(int obj, int unused, int y);
int func_021A2DE4(u32 a, u32 b, u32 c, u32 d);
void func_021A2DF0(u32 a);
int func_021A2E34(u32 a, u32 b, u32 c, u32 d);
void func_021A2E44(int a, u32 v);
u32 *func_021A2E50(int a, u32 b, int c, int d, u16 heap);
int func_021A2E90(void *a);
void func_021A2EB8(u32 *a);
int func_021A2F20(u32 *p, int a, int b, int c);
void func_021A2F48(u8 *p, u32 a1);
int func_021A2F54(u8 *p);
void func_021A2F60(int *p);
void func_021A2F6C(u32 *p);
void func_021A2F8C(u8 *p, u32 b);
u32 func_021A2F98(u8 *p);
u16 func_021A2FA4(u8 *p, u32 a1);
u32 func_021A2FB0(u32 a);
int func_021A2FD0(void *a);
void func_021A2FE4(u32 *p);
void func_021A3038(u8 *p, struct V3 *out);
void func_021A3044(u8 *p, void *v);
u16 func_021A3050(u8 *p);
void func_021A305C(char *p, u32 b);
u32 func_021A3068(u8 *p);
void *func_021A3074(u8 *p);
u32 func_021A3080(u8 *p);
u32 func_021A308C(u8 *p);
u32 func_021A3098(u8 *p);
void func_021A30A4(u8 *p, u32 b);
u32 func_021A30B0(u8 *p);
int func_021A30BC(u8 *p);
u32 func_021A30C8(void **ctx);
u32 func_021A3128(u32 *a, u32 b);
u16 func_021A3190(int i, int j);
int func_021A31A4(int i, int v);
extern u32 data_021D88E0[];
extern int d_021DDE90;
extern int d_021DDEA8;
extern const Row data_021D890C[];







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
s32 func_021A2AB8(Obj_021A2AB8 *o, u32 arg)
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
    func_0204B3DC((struct Obj_021A2AB8 *)p[1], 0);
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
        func_0204B3B4((struct Obj_021A2AB8 *)v);
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









void func_021A2D30(Obj_021A2D30 *o, int v, int *out2, int *out1)
{
    *out1 = (int)(((long long)(int)func_0207C768((int)v, (int)o->f14) * 0x2000 + 0x800) >> 12);
    *out2 = (int)(((long long)(int)func_0207C768((int)v, (int)o->f0) * 0x2000 + 0x800) >> 12);
}









void func_021A2D88(int obj, int unused, int y)
{
    int h;
    void *a;
    void *b;
    char *p;

    h = func_02188C84((u8 *)obj);
    p = (char *)func_02030734(h, 0x10, 1, (const char *)&d_021DDE90, 0x68);
    ((struct Obj12722 *)p)->f0 = h;
    ((struct Obj12722 *)p)->f4 = obj;
    a = func_02188CB4((void *)obj);
    b = func_021A3074((void *)a);
    func_0216D5E0((int)b, y);
    func_021A35E0(a, h);
    func_02188D40((u8 *)obj, (u32)func_0216D888(b));
    func_02188CAC((u8 *)obj, (u32)p);
}









/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A2DE4(u32 a, u32 b, u32 c, u32 d)
{
return func_020307B0((void *)func_02188CA4((u8 *)a));
}









/*
 * Addresses are Black-image addresses.
 */
void func_021A2DF0(u32 a)
{
    u8 *p = (u8 *)func_02188CA4((u8 *)a);
    void *q = func_02188CB4((void *)a);

    if (((struct Obj19760 *)p)->fC == 0) {
        u32 x = func_020362DC();
        u32 y = func_0203630C();
        u32 f = 0;

        if (func_021A35BC((int)q) == 1)
            f |= 1;
        func_021A35F0((u32)q, x, y, f);
    }
}









int func_021A2E34(u32 a, u32 b, u32 c, u32 d)
{
return (int)func_0216D888(func_021A3074(func_02188CB4((struct Obj00020 *)a)));
}









void func_021A2E44(int a, u32 v)
{
    ((struct Obj19761 *)((char *)func_02188CA4((u8 *)a)))->fC = v;
}









u32 *func_021A2E50(int a, u32 b, int c, int d, u16 heap)
{
    u32 *o = (u32 *)func_02030734(heap, 0x10, 1, (const char *)&d_021DDEA8, 0x4C);

    o[0] = b;
    o[1] = func_021A36E4(a, b, c, d, heap);
    return o;
}









int func_021A2E90(void *a)
{
if (((struct Obj05861 *)((u8 *)(a)))->f8 != 0) {
    func_021A41A8();
}
if (((struct Obj05861 *)((u8 *)(a)))->fC != 0) {
    func_021A5920();
}
func_021A3810(((struct Obj05861 *)((u8 *)(a)))->f4);
return func_020307B0(a);
}









/*
 * Ilias's) has no witness outside this range. Leaf C, verified EXACT
 * with match.py one --thumb --region arm9 (symbols: data_0209DFA8
 * 0x0209DFA8 data a2):
 *   extern const u16 data_0209DFA8[];
 *   void func_02012AD4(u8 *p, int i) { *(u16 *)(p + 0x18) = data_0209DFA8[i]; }
 *
 * Addresses are Black-image addresses.
 */
void func_021A2EB8(u32 *a)
{
    u8 b[12];
    u8 c[8];
    u32 d = func_021A3994((u8 *)a[1]);
    void *e = func_021A3960((u8 *)a[1]);

    func_0216D88C(e, (struct V3 *)b);
    func_02012A90((struct Rec44 *)d, (const struct Vec12 *)b);
    func_02012AD4((u8 *)d, func_0216D5F8(e));
    if (func_02188CFC((u8 *)a[0]) == 0) {
        func_02012ABC((struct Rec44 *)d, 0);
        return;
    }
    func_0219E2F4(e, c);
    func_02012AA4((struct Rec44 *)d, (const struct H4 *)c);
    func_02012ABC((struct Rec44 *)d, 1);
}









int func_021A2F20(u32 *p, int a, int b, int c)
{
    int r = 0;

    if (func_02188CFC((u8 *)p[0]) == 0)
        r = func_021C0CA4((u8 *)p[2], a, b, c);
    return r;
}









/*
 * Tail-call thunk: the object's word at +0x4.
 *
 * Addresses are Black-image addresses.
 */
void func_021A2F48(u8 *p, u32 a1)
{
    func_021A3CB0(((struct Obj18007 *)p)->f4, a1);
}









int func_021A2F54(u8 *p)
{
    return func_021A3CC0(((struct Obj18008 *)p)->f4);
}









/*
 * Unlabelled leaf (a .word run in the ov021 listing): tail-calls
 * func_021A3CE8 with the word at offset 4.  Callee of func_0218B32C.
 *
 * Addresses are Black-image addresses.
 */
void func_021A2F60(int *p)
{
    func_021A3CE8(p[1]);
}









void func_021A2F6C(u32 *p)
{
    if (func_02188CFC((u8 *)p[0]) == 0)
        func_021A53D0((u32 *)p[2]);
    else
        func_021A5A34((u32 *)p[3]);
}









/*
 * Tail-call thunk: the object's word at +0x4, second argument forwarded.
 * Unlabelled leaf; its only blocker-caller is func_021C10B4.
 *
 * Addresses are Black-image addresses.
 */
void func_021A2F8C(u8 *p, u32 b)
{
    func_021A3AD0((u8 *)(((struct Obj19763 *)p)->f4), b);
}








u32 func_021A2F98(u8 *p)
{
    return func_021A3AD4((u8 *)(((struct Obj18009 *)p)->f4));
}








u16 func_021A2FA4(u8 *p, u32 a1)
{
    return func_021A3AB8(((struct Obj18010 *)p)->f4, a1);
}








u32 func_021A2FB0(u32 a)
{
if (func_02188CFC((u8 *)(((struct Obj09180 *)((u8 *)(a)))->f0)) == 0) {
    return func_021A5778(((struct Obj09180 *)((u8 *)(a)))->f8);
}
return func_021A59DC(((struct Obj09180 *)((u8 *)(a)))->fC);
}








int func_021A2FD0(void *a)
{
func_021A3CB0(*(u32 *)&((struct Obj00614 *)((u8 *)(a)))->f4, 1);
return func_021A3CE8(*(u32 *)&((struct Obj00614 *)((u8 *)(a)))->f4);
}








void func_021A2FE4(u32 *p)
{
    if (func_02188CFC((u8 *)p[0]) == 0) {
        if (func_021A548C(p[2]) == 1) {
            func_021A396C((u8 *)p[1], 2);
            return;
        }
        if (func_021A54A0(p[2]) == 1) {
            func_021A396C((u8 *)p[1], 2);
            return;
        }
    } else {
        if (func_021A59EC(p[3]) == 1) {
            func_021A396C((u8 *)p[1], 2);
            return;
        }
    }
    func_021A3818((u32 *)p[1]);
}








void func_021A3038(u8 *p, struct V3 *out)
{
    func_021A3898((u8 *)((struct Obj18011 *)p)->f4, out);
}








void func_021A3044(u8 *p, void *v)
{
    func_021A38A4((u8 *)((struct Obj18012 *)p)->f4, v);
}







u16 func_021A3050(u8 *p)
{
    return func_021A3920((u8 *)(((struct Obj18013 *)p)->f4));
}







/*
 *          (ov009/ov021 overlap; the ov021 hint does not locate a func_ label).
 *
 * UNBLOCKED: func_021A392C is now an EXACT entry in layout/matched/ov021;
 * the call site resolves as matched, verdict promoted to EXACT.
 */
void func_021A305C(char *p, u32 b)
{
    func_021A392C((void *)(((struct Obj19764 *)p)->f4), b);
}







u32 func_021A3068(u8 *p)
{
    return func_021A395C((u8 *)(((struct Obj18014 *)p)->f4));
}







void *func_021A3074(u8 *p)
{
    return func_021A3960(*(u8 * *)&((struct Obj00614 *)p)->f4);
}







u32 func_021A3080(u8 *p)
{
    return func_021A3968((u32 *)(((struct Obj18015 *)p)->f4));
}







u32 func_021A308C(u8 *p)
{
    return func_021A3970((u32 *)(((struct Obj18016 *)p)->f4));
}







u32 func_021A3098(u8 *p)
{
    return func_021A3974((u8 *)(((struct Obj18017 *)p)->f4));
}






/*
 * Unlabelled leaf: tail-calls 0x021A3980 with the +4 member and the second argument.
 *
 * Addresses are Black-image addresses.
 */
void func_021A30A4(u8 *p, u32 b)
{
    func_021A3980((u8 *)(((struct Obj19765 *)p)->f4), b);
}






/*
 * Forwards the +4 member to 0x021A398C (unlabelled start).
 *
 * Addresses are Black-image addresses.
 */
u32 func_021A30B0(u8 *p)
{
    return func_021A398C((u8 *)(((struct Obj19766 *)p)->f4));
}






int func_021A30BC(u8 *p)
{
    return func_021A3990((u8 *)(((struct Obj18018 *)p)->f4));
}





u32 func_021A30C8(void **ctx)
{
    u32 r;

    if (func_02188CFC(ctx[0]) == 0) {
        V3 pos;
        u16 z = func_02188C98(ctx[0]);
        func_021A3038((unsigned char *)ctx, (struct V3 *)&pos);
        r = func_021AB0D4((void *)z, &pos);
    } else if (func_02188CFC(ctx[0]) == 1) {
        Pair_021A2D30 v;
        void *o = func_021A3074((u8 *)ctx);
        void *w = (void *)func_02188C5C(ctx[0]);
        func_0219E2F4(o, &v);
        r = func_021BB3C4(w, (char *)(&v));
    }
    return r;
}





u32 func_021A3128(u32 *a, u32 b)
{
    u32 r;
    u8 d[12];
    u8 c[8];

    if (func_02188CFC((u8 *)a[0]) == 0) {
        u32 h = func_02188C98((u8 *)a[0]);

        func_021A3364(a, b, (int *)d);
        r = func_021AB0D4((void *)h, d);
    } else if (func_02188CFC((u8 *)a[0]) == 1) {
        void *t = func_021A3074((u8 *)a);
        u32 h = func_02188C5C((u8 *)a[0]);

        func_0219E664(t, b, c);
        r = func_021BB3C4((u8 *)h, (char *)c);
    }
    return r;
}




/*
 * Halfword a of entry j in row i of the 10-entry table at 0x021D890C.
 *
 * Addresses are Black-image addresses.
 */
u16 func_021A3190(int i, int j)
{
    return data_021D890C[i].e[j].a;
}




/*
 * Looks up v in the b column of row i and returns the matching a, else 1.
 *
 * Addresses are Black-image addresses.
 */
int func_021A31A4(int i, int v)
{
    const Pair_021A3190 *e;
    int k;

    k = 0;
    e = data_021D890C[i].e;
    for (; k < 10; k++, e++) {
        if (e->b == v)
            return e->a;
    }
    return 1;
}
