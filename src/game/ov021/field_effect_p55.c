/*
 * file:     field_effect_p55.c
 * unit:     yes
 * function: func_021AC154, func_021AC178, func_021AC18C, func_021AC1A0, func_021AC1AC, func_021AC1B8, func_021AC1CC, func_021AC1E0
 * address:  0x021AC154
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "../../matched/include/Obj18085.h"
#include "../../matched/include/Obj18086.h"

struct Node;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct V3 { int x, y, z; } V3;

typedef struct Obj Obj;

typedef void (*ObjCb)(Obj *o, void *work);

struct Obj {
    u32 active;
    u32 f4;
    u32 f8;
    V3 pos;
    u8 work[0xa4];
    ObjCb init;
    ObjCb exit;
    ObjCb f_c4;
    ObjCb f_c8;
    u32 fcc;
    void *fd0;
};

extern void func_02030EAC(struct Node *n);
void func_021AC154(Obj *o);
void func_021AC178(Obj *o);
void func_021AC18C(Obj *o);
int func_021AC1A0(u32 a);
int func_021AC1AC(u32 a);
void func_021AC1B8(Obj *o, V3 *out);
void func_021AC1CC(Obj *o, V3 *in);
int func_021AC1E0(u32 a);


void func_021AC154(Obj *o)
{
    if (o != 0) {
        o->exit(o, o->work);
        func_02030EAC(o->fd0);
        o->active = 0;
    }
}


void func_021AC178(Obj *o)
{
    if (o != 0)
        o->f_c4(o, o->work);
}


void func_021AC18C(Obj *o)
{
    if (o != 0)
        o->f_c8(o, o->work);
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021AC1A0(u32 a)
{
if (a != 0) {
    return ((struct Obj18085 *)((u8 *)(a)))->f4;
}
return 0;
}


int func_021AC1AC(u32 a)
{
if (a != 0) {
    return ((struct Obj18086 *)((u8 *)(a)))->f8;
}
return 0;
}


void func_021AC1B8(Obj *o, V3 *out)
{
    if (o != 0)
        *out = o->pos;
}


void func_021AC1CC(Obj *o, V3 *in)
{
    if (o != 0)
        o->pos = *in;
}


int func_021AC1E0(u32 a)
{
if (a != 0) {
    return (a + 24);
}
return 0;
}
