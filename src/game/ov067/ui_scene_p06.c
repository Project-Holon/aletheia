/*
 * file:     ui_scene_p06.c
 * unit:     yes
 * function: func_021B6A10, func_021B6A1C, func_021B6A28, func_021B6A44, func_021B6A68, func_021B6A98, func_021B6AE4
 * address:  0x021B6A10
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
 *   func_0204B800  0x0204B800  arm
 *   func_0204B84C  0x0204B84C  arm
 *   func_0204B878 0x0204B878 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_021B69F8  0x021B69F8  thumb
 *   func_021B69D8  0x021B69D8  thumb
 *   func_021B6C4C  0x021B6C4C  thumb  ov067
 *   func_02045770  0x02045770  arm
 *   func_0201C724  0x0201C724  thumb
 */
#include "../../matched/include/Obj20614.h"
#include "../../matched/include/Obj20615.h"
#include "../../matched/include/Obj05146.h"
#include "../../matched/include/Obj13132.h"
#include "../../matched/include/Obj05378.h"

struct Node;
struct Obj;
struct S;
struct StrObj;
struct Descriptor;
typedef unsigned int   u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct S_021B6A68 {
    void *f00;
    u32 f04;
    u32 f08;
    u8 pad0c[0x26 - 0x0c];
    u16 f26;
    u16 f28;
    u16 f2a;
} S_021B6A68;

typedef struct S_021B6A98 {
    void *f00;
    u32 f04;
    u32 f08;
    u8 pad0c[0x26 - 0x0c];
    u16 f26;
    u16 f28;
    u16 f2a;
    u16 f2c;
} S_021B6A98;

typedef short s16;

extern void func_0204B878(struct Obj *p, u16 value);
extern void func_020061E4(u32 a);
extern u32 func_021B69F8(u32 p);
extern void func_021B69D8(struct S *p, u32 v);
extern u16 func_021B6C4C(struct StrObj *s, u32 a, u32 mode);
extern void *func_02045770(struct Descriptor *p);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
void func_021B6A10(void *p, unsigned int v);
void func_021B6A1C(void *p, unsigned int v);
void func_021B6A28(u8 *p);
void func_021B6A44(u8 *p);
void func_021B6A68(S_021B6A68 *p, u32 flag);
void func_021B6A98(S_021B6A98 *p, u32 flag);
void func_021B6AE4(u8 *p, void *a, u16 b, u16 c, u32 s0, u32 s1, u16 s2, u32 s3);

void func_021B6A10(void *p, unsigned int v)
{
    void func_0204B800(struct Node *node, u32 val);
    func_0204B800(((struct Obj20614 *)p)->f0, v);
}


/*
 * Two ARM9 tail calls on the pointer loaded from offset 0.
 */
void func_021B6A1C(void *p, unsigned int v)
{
    void func_0204B84C(void *, unsigned int);
    func_0204B84C(((struct Obj20615 *)p)->f0, v);
}

/*
 * extent: trailing two-byte alignment padding at 0x021B6A42.
 */
void func_021B6A28(u8 *p)
{
    ((struct Obj05146 *)p)->f8 = ((struct Obj05146 *)p)->f2A;
    func_0204B878(((struct Obj05146 *)p)->f0, ((struct Obj05146 *)p)->f8);
    if (((struct Obj05146 *)p)->f34) func_020061E4((u32)(((struct Obj05146 *)p)->f34));
}


void func_021B6A44(u8 *p)
{
    u32 a = func_021B69F8((u32)p);
    int b = 1;

    if (a != 0) {
        b = 0;
    }
    func_021B69D8((struct S *)p, b);
    if (((struct Obj13132 *)p)->f34 != 0) {
        func_020061E4(((struct Obj13132 *)p)->f34);
    }
}

/*
 * extent: trailing two-byte alignment padding at 0x021B6A96.
 */
void func_021B6A68(S_021B6A68 *p, u32 flag)
{
    p->f04 = flag;
    if (flag) {
        if (p->f08 == p->f2a) p->f08 = p->f26;
        func_0204B878(p->f00, p->f08);
    } else {
        func_0204B878(p->f00, p->f28);
    }
}


void func_021B6A98(S_021B6A98 *p, u32 flag)
{
    p->f04 = flag;
    if (flag) {
        if (p->f08 == p->f2a) {
            p->f08 = p->f2c;
        } else if (p->f08 == p->f28) {
            p->f08 = p->f26;
        }
        func_0204B878(p->f00, p->f08);
    } else {
        if (p->f08 == p->f2c) {
            p->f08 = p->f2a;
        } else if (p->f08 == p->f26) {
            p->f08 = p->f28;
        }
        func_0204B878(p->f00, p->f28);
    }
}


/*
 * note:     b and c are u16 as the matched caller ov067_func_021B6B2C passes
 *           them; the difference is written back into the parameter
 *           (`b = b - f()`): a separate u16 local y swapped p and b between
 *           r4/r5, and `b -= f()` truncates the call result first (worse).
 */
void func_021B6AE4(u8 *p, void *a, u16 b, u16 c, u32 s0, u32 s1, u16 s2, u32 s3)
{
    b = b - func_021B6C4C((struct StrObj *)s0, s1, s3);
    func_0201C724(a, (u32)func_02045770((struct Descriptor *)*(u32 *)&((struct Obj05378 *)p)->f0), (s16)b, (s16)c, s0, s1, s2);
    p[4] = 1;
}
