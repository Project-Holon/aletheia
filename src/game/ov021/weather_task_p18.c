/*
 * file:     weather_task_p18.c
 * unit:     yes
 * function: func_021A2BB8, func_021A2BC4, func_021A2BD4, func_021A2C10, func_021A2C24, func_021A2C28, func_021A2C2C
 * address:  0x021A2BB8
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
 */
#include "../../matched/include/Obj18004.h"
#include "../../matched/include/Obj12086.h"
#include "../../matched/include/Obj18005.h"
#include "../../matched/include/Obj18006.h"

struct Obj;
struct Actor;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct { u16 id; u16 x, y, z; } Q;

typedef signed int     s32;

extern void func_02082BCC();
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
void func_0204B3DC(struct Obj *h, unsigned int v);
void func_0204BA20(struct Actor *a, u32 v);
extern void func_0204B3B4(struct Obj *p);
void func_021A2BB8(u32 a);
int func_021A2BC4(u32 a);
void func_021A2BD4(u32 *p, u32 a, const Q *q, int b, u16 e);
void func_021A2C10(u8 *p);
unsigned char *func_021A2C24(unsigned char *o);
u32 func_021A2C28(u8 *p);
void func_021A2C2C(u8 *p, u32 v);
extern u32 data_021D88E0[];


/*
 * Tail-call thunk: pins arguments 2 and 3 to 0 and 56.
 *
 * Addresses are Black-image addresses.
 */
void func_021A2BB8(u32 a)
{
    func_02082BCC(a, 0, 56);
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
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
