/*
 * file:     field_place_name_p06.c
 * unit:     yes
 * function: func_021BC704, func_021BC720, func_021BC730, func_021BC748, func_021BC75C, func_021BC788, func_021BC794
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
 */
#include "../../matched/include/Obj00575.h"
#include "../../matched/include/Obj18190.h"

struct CharBuf;
struct Descriptor;
struct Obj_021BC730;
struct Bank;
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
void func_021BC704(Obj_021BC704 *p);
void func_021BC720(Obj_021BC720 *p);
void func_021BC730(Obj_021BC730 *p);
void func_021BC748(u8 *p);
void func_021BC75C(Obj_021BC75C *p);
void func_021BC788(u8 *p);
void func_021BC794(Obj_021BC794 *p);
extern int d_021D9B78;


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
