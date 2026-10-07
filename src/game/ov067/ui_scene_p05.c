/*
 * file:     ui_scene_p05.c
 * unit:     yes
 * function: func_021B69A4, func_021B69B8, func_021B69BC, func_021B69C8, func_021B69D0, func_021B69D4, func_021B69D8, func_021B69F8
 * address:  0x021B69A4
 * region:   ov067
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B98C 0x0204B98C arm
 *   func_0204B3DC  0x0204B3DC  arm
 */
#include "../../matched/include/Obj20610.h"
#include "../../matched/include/Obj20611.h"
#include "../../matched/include/Obj20612.h"
#include "../../matched/include/Obj20613.h"

struct Actor;
struct Obj;
typedef unsigned int   u32;

typedef unsigned short u16;

struct S {
    struct Obj *f0;
    u32 f4;
    u32 f8;
    char pad[0x26 - 0xC];
    u16 f26;
    u16 f28;
    u16 f2a;
};

extern u32 func_0204B98C(struct Actor *a);
extern void func_0204B878(struct Obj *p, u16 value);
int func_021B69A4(void **p);
int func_021B69B8(void *p);
void func_021B69BC(void *p, unsigned int v);
int func_021B69C8(void *p, int a);
void func_021B69D0(void *p, int v);
void func_021B69D4(void *p, int v);
void func_021B69D8(struct S *p, u32 v);
u32 func_021B69F8(u32 p);

int func_021B69A4(void **p)
{
    if (func_0204B98C(*p) == 0) return 1;
    return 0;
}


/*
 * Getter, ARM9 tail call, indirect call, and two setters.  0x021B69BC is also
 * resident in ov172, so the packet id is region-qualified.
 */
int func_021B69B8(void *p)
{
    return ((struct Obj20610 *)p)->f18;
}

void func_021B69BC(void *p, unsigned int v)
{
    void func_0204B3DC(struct Obj *p, u32 v);
    func_0204B3DC(((struct Obj20611 *)p)->f0, v);
}


int func_021B69C8(void *p, int a)
{
    return (*(int (**)(void *, int))((char *)p + 0x10))(p, a);
}


void func_021B69D0(void *p, int v)
{
    ((struct Obj20612 *)p)->f34 = v;
}


void func_021B69D4(void *p, int v)
{
    ((struct Obj20613 *)p)->f30 = v;
}


void func_021B69D8(struct S *p, u32 v)
{
    if (v != 0)
        p->f8 = p->f2a;
    else
        p->f8 = p->f26;
    func_0204B878(p->f0, (u16)p->f8);
}

u32 func_021B69F8(u32 p) {
    int r = 1;
    if (*(u32 *)(p+8) != *(u16 *)(p+42) && *(u32 *)(p+8) != *(u16 *)(p+44)) r = 0;
    return r;
}
