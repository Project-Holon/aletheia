/*
 * file:     weather_task_p11.c
 * unit:     yes
 * function: func_021A3810, func_021A3818, func_021A3898, func_021A38A4, func_021A3920, func_021A392C, func_021A3938, func_021A394C, func_021A395C, func_021A3960, func_021A3964, func_021A3968, func_021A396C, func_021A3970, func_021A3974, func_021A3980, func_021A398C, func_021A3990, func_021A3994, func_021A3998, func_021A39AC, func_021A39E4, func_021A3A10, func_021A3A20, func_021A3A3C
 * address:  0x021A3810
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
 *   func_020307B0  0x020307B0  arm
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D80C  0x0216D80C  thumb  ov010
 *   func_0216D854  0x0216D854  thumb  ov010
 *   func_0216D818  0x0216D818  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_0216D824  0x0216D824  thumb  ov010
 *   func_0216D844  0x0216D844  thumb  ov010
 *   func_0216D85C  0x0216D85C  thumb  ov010
 *   func_0216D874  0x0216D874  thumb  ov010
 *   func_0216D89C  0x0216D89C  thumb  ov010
 *   func_0216D5F8  0x0216D5F8  thumb
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_021A3AD8  0x021A3AD8  thumb  ov021
 *   func_02012B30  0x02012B30  thumb
 *   func_02012B28  0x02012B28  thumb
 *   func_02012B2C  0x02012B2C  thumb
 *   func_021A3B3C  0x021A3B3C  thumb  ov021
 *   func_021A3190  0x021A3190  thumb  ov021
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0216D7A8  0x0216D7A8  thumb  ov010
 *   func_021A31D0  0x021A31D0  thumb  ov021
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D520  0x0216D520  thumb  ov010
 *   func_0219C9DC  0x0219C9DC  thumb
 *   func_02197C9C  0x02197C9C  thumb
 *   func_0219C648  0x0219C648  thumb
 *   func_020508EC  0x020508EC  arm
 */
#include "../../matched/include/Obj18032.h"
#include "../../matched/include/Obj19775.h"
#include "../../matched/include/Obj18033.h"
#include "../../matched/include/Obj19776.h"
#include "../../matched/include/Obj18034.h"
#include "../../matched/include/Obj19777.h"
#include "../../matched/include/Obj18035.h"
#include "../../matched/include/Obj18036.h"
#include "../../matched/include/Obj18037.h"
#include "../../matched/include/Obj18039.h"
#include "../../matched/include/Obj18041.h"
#include "../../matched/include/Obj18042.h"
#include "../../matched/include/Obj18043.h"
#include "../../matched/include/Obj18044.h"
#include "../../matched/include/Obj18045.h"
#include "../../matched/include/Obj19778.h"
#include "../../matched/include/Obj12729.h"

struct Actor;
struct VecFx32;
struct Rec44;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    int x;
    int y;
    int z;
} Vec021A38A4;

typedef signed short   s16;

typedef signed char    s8;

extern u32 func_020307B0(void *p);
extern int func_0216D3CC(int a0);
extern int func_0216D454();
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *out);
u16 func_0216D83C(u32 h);
void func_0216D80C(void *p, u16 v);
u16 func_0216D854(u32 h);
void func_0216D818(void *p, u16 v);
u16 func_0216D86C(u32 h);
void func_0216D824(void *p, u16 v);
void func_0216D844(void *p, short v);
void func_0216D85C(void *p, int v);
void func_0216D874(int a0, int a1);
void func_0216D89C(u32 h, Vec021A38A4 *v);
extern u16 func_0216D5F8(u32);
extern void func_0216D5E0(int, int);
extern u32 func_02012B30(u32, u32);
extern void func_021A3AD8(u8 *p, int a);
extern u32 func_02012B28(const struct Rec44 *p);
extern void func_02012B2C(struct Rec44 *p, u32 v);
extern u32 func_021A3B3C(u32, u32);
u16 func_021A3190(int i, int j);
u16 func_0216D598(void *p);
int func_0216D7A8(void *p, unsigned int v);
extern int func_021A31D0(u16 id);
extern void *func_0216D67C(void *a0);
extern u32 func_0216D520(void *p);
extern u32 func_0219C9DC(u8 *p);
extern int func_02197C9C(u32 a);
extern int func_0219C648(u32 a);
extern u32 func_020508EC(u8 *p, int i, u16 *out);
void func_021A3810(u32 a0);
void func_021A3818(u32 *p);
void func_021A3898(u8 *p, struct VecFx32 *out);
void func_021A38A4(u8 *p, Vec021A38A4 *v);
u16 func_021A3920(u8 *p);
void func_021A392C(void *p, int b);
int func_021A3938(u32 a, u32 b);
void func_021A394C(u8 *p);
u32 func_021A395C(u8 *p);
void *func_021A3960(u8 *p);
void func_021A3964(u8 *p, u32 v);
u32 func_021A3968(u32 *p);
void func_021A396C(u8 *p, u32 v);
u32 func_021A3970(u32 *p);
u32 func_021A3974(u8 *p);
void func_021A3980(u8 *p, u32 a1);
u32 func_021A398C(u8 *p);
u32 func_021A3990(u8 *p);
u32 func_021A3994(u8 *p);
int func_021A3998(u8 *a);
void func_021A39AC(u8 *p, int a);
int func_021A39E4(u8 *p);
int func_021A3A10(u32 a);
int func_021A3A20(u32 a);
int func_021A3A3C(u32 *p);






/*
 * Tail-call thunk: forwards to func_020307B0 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_021A3810(u32 a0)
{
    func_020307B0((void *)a0);
}






/*
 * Addresses are Black-image addresses.
 */
void func_021A3818(u32 *p)
{
    u32 h = p[7];
    u32 m;
    u32 old = p[4];

    p[4] = 0;
    m = p[5];
    if (func_0216D3CC(h) == 0) {
        switch (m) {
        case 0:
            break;
        case 1:
            if (old == 0 || old == 3)
                p[4] = 1;
            else
                p[4] = 2;
            break;
        case 2:
            p[4] = 2;
            break;
        }
    } else if (func_0216D454(h) == 1) {
        switch (m) {
        case 0:
            break;
        case 1:
            if (old == 0)
                break;
            if (old == 3)
                p[4] = 0;
            else
                p[4] = 3;
            break;
        case 2:
            if (old == 0)
                break;
            if (old == 3)
                p[4] = 0;
            else
                p[4] = 3;
            break;
        }
    }
}






/*
 * Tail-call thunk: the object's word at +0x1c.
 *
 * Addresses are Black-image addresses.
 */
void func_021A3898(u8 *p, struct VecFx32 *out)
{
    func_0216D88C((const struct Actor *)((struct Obj18032 *)p)->f1C, out);
}






void func_021A38A4(u8 *p, Vec021A38A4 *v)
{
    int x = (v->x >> 4) / 4096;
    int y = (v->y >> 4) / 4096;
    int z = (v->z >> 4) / 4096;
    u32 h = ((struct Obj19775 *)p)->f1C;

    func_0216D80C((void *)h, func_0216D83C(h));
    func_0216D818((void *)h, func_0216D854(h));
    func_0216D824((void *)h, func_0216D86C(h));
    func_0216D844((void *)h, (short)x);
    func_0216D85C((void *)h, (short)y);
    func_0216D874(h, (short)z);
    func_0216D89C(h, v);
}






u16 func_021A3920(u8 *p)
{
    return func_0216D5F8(((struct Obj18033 *)p)->f1C);
}






/*
 * Unlabelled Thumb tail-call thunk in a .word run:
 *   ldr r0,[r0,#0x1c]; ldr r3,[pc,#4]; bx r3; nop; .word 0x0216D5E1
 * The pool word carries the Thumb bit for func_0216D5E0, which is traced
 * only in ov010 (0x0216D5E0 is data in ov009), so the hint names ov010.
 */
void func_021A392C(void *p, int b)
{
    func_0216D5E0(((struct Obj19776 *)p)->f1C, b);
}






/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A3938(u32 a, u32 b)
{
func_021A3AD8((u8 *)a, b);
return func_02012B30(((struct Obj18034 *)((u8 *)(a)))->fC, b);
}





/*
 * Unlabelled leaf (no lr save, prints as .word data in the listing),
 * filed as the sole blocker of ov021 func_021A322C (itself a blocker of
 * ov018 func_0217BCDC): tail call on the object's word at +0xC.
 */
void func_021A394C(u8 *p)
{
    func_02012B30((u32)((struct Rec44 *)(((struct Obj19777 *)p)->fC)), 0xFFFF);
}





/*
 * Loads the 32-bit word at byte +0x8 of the object.
 */
u32 func_021A395C(u8 *p)
{
    return ((struct Obj18035 *)p)->f8;
}





/*
 * Loads the 32-bit word at byte +0x1c of the object.
 */
void *func_021A3960(u8 *p)
{
    return ((struct Obj18036 *)p)->f1C;
}





/*
 * Field setter at +0x14.
 *
 * Addresses are Black-image addresses.
 */
void func_021A3964(u8 *p, u32 v)
{
    ((struct Obj18037 *)p)->f14 = v;
}




/*
 * Unlabelled leaf getter at +0x14.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021A3968(u32 *p)
{
    return p[5];
}




/*
 * Field setter at +0x10.
 *
 * Addresses are Black-image addresses.
 */
void func_021A396C(u8 *p, u32 v)
{
    ((struct Obj18039 *)p)->f10 = v;
}




/*
 * Unlabelled leaf getter at +0x10.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021A3970(u32 *p)
{
    return p[4];
}




/*
 * Tail-call thunk: the object's word at +0xc.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021A3974(u8 *p)
{
    return func_02012B28((const struct Rec44 *)(((struct Obj18041 *)p)->fC));
}




void func_021A3980(u8 *p, u32 a1)
{
    func_02012B2C((struct Rec44 *)(((struct Obj18042 *)p)->fC), a1);
}




/*
 * Loads the 32-bit word at byte +0x18 of the object.
 */
u32 func_021A398C(u8 *p)
{
    return ((struct Obj18043 *)p)->f18;
}




/*
 * Loads the 32-bit word at byte +0x4 of the object.
 */
u32 func_021A3990(u8 *p)
{
    return ((struct Obj18044 *)p)->f4;
}



/*
 * Loads the 32-bit word at byte +0xc of the object.
 */
u32 func_021A3994(u8 *p)
{
    return ((struct Obj18045 *)p)->fC;
}



int func_021A3998(u8 *a)
{
    u32 b;
    u32 c;
    u32 d;
return func_021A3B3C((u32)a, func_021A3974(a));
}



void func_021A39AC(u8 *p, int a)
{
    u32 x = func_021A398C(p);
    void *h = func_021A3960(p);
    int v = func_021A3190(x, a);

    if (v != func_0216D598(h))
        func_021A3AD8(p, v);
    ((struct Obj19778 *)p)->f2C = 0;
}



int func_021A39E4(u8 *p)
{
    if (func_0216D7A8(func_021A3960(p), 0) != 0xFFFF) {
        if (((struct Obj12729 *)p)->f2C == 1)
            return 1;
        (((struct Obj12729 *)p)->f2C)++;
    }
    return 0;
}



int func_021A3A10(u32 a)
{
return func_021A31D0(func_0216D598(func_021A3960((u8 *)a)));
}



int func_021A3A20(u32 a)
{
if (func_021A31D0(func_0216D598(func_021A3960((void *)a))) != 10) {
    return 1;
}
return 0;
}



/*
 * Ilias's) has no witness outside this range. Leaf C, verified EXACT
 * with match.py one --arm --region arm9:
 *   int func_020508EC(u8 *p, int i, u16 *out)
 *   {
 *       u8 *e = *(u8 **)(p + 0x18) + i * 0x28;
 *       u16 v = *(u16 *)(e + 0x1C);
 *       *out = v;
 *       return (u16)(v + 4 + 0xC000) <= 3;
 *   }
 *
 * Addresses are Black-image addresses.
 */
int func_021A3A3C(u32 *p)
{
    u16 v;
    u32 h;
    u32 k;

    h = func_0219C9DC((u8 *)func_0216D520(func_0216D67C((void *)p[7])));
    if (func_02197C9C(p[7]) == 1 && func_0219C648(p[7]) == 1)
        return 1;
    k = func_0216D7A8((void *)p[7], 0);
    if (k != 0xFFFF && func_020508EC((u8 *)h, (u16)k, &v) != 0 && v == (0xFFFF >> 2))
        return 1;
    return 0;
}
