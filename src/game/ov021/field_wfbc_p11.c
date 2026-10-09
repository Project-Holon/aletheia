/*
 * file:     field_wfbc_p11.c
 * unit:     yes
 * function: func_02196B94, func_02196BF8, func_02196C68, func_02196CD8, func_02196D20
 * address:  0x02196B94
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
 *   func_02196B7C  0x02196B7C  thumb  ov021
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204BA00  0x0204BA00  arm
 *   func_0204B9A0  0x0204B9A0  arm
 *   func_02196034  0x02196034  thumb  ov021
 *   func_02196B90  0x02196B90  thumb  ov021
 *   func_02196B28  0x02196B28  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_0219630C  0x0219630C  thumb  ov021
 *   func_021966B0  0x021966B0  thumb  ov021
 *   func_0219728C  0x0219728C  thumb  ov021
 *   func_0219649C  0x0219649C  thumb  ov021
 *   func_02196F44  0x02196F44  thumb  ov021
 *   func_02196FF0  0x02196FF0  thumb  ov021
 *   func_02051B84  0x02051B84  arm
 *   d_021D4080     0x021D4080  data  ov021  a4
 *   d_021D4034     0x021D4034  data  ov021  a4
 *   d_021DDB44     0x021DDB44  data  ov021  a4
 *   func_02196A60  0x02196A60  thumb  ov021
 *   func_02196804  0x02196804  thumb  ov021
 */
#include "../../matched/include/Obj09493.h"
#include "../../matched/include/Obj00093.h"
#include "../../matched/include/Obj09494.h"

struct Actor;
struct Cmd;
struct Obj;
struct Cb;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct Obj { u8 pad[0x294]; void *objs[27]; u32 mode; } Obj;

typedef struct { u16 x0; Obj *a; void (*cb)(); } Req;

typedef signed int     s32;

struct Rec16 { u32 a; u32 b; u32 c; u32 d; };

extern void func_02196B7C(u8 *p);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204BA00(struct Actor *a, const struct Cmd *cmd);
extern void func_0204B9A0(struct Actor *a);
extern void func_02196034(Obj *, void (*)(), u32);
extern void func_02196B90();
extern void func_02196B28(struct Obj *a);
extern void func_020061E4(u32 a);
extern void func_0219630C(u32 a, void *b, u8 *c, void *d, u32 e, u32 f);
extern void func_021966B0(u8 *p, u32 n);
extern void func_0219728C(u8 *p);
extern void func_0219649C(void *a, int b, struct Cb *c);
extern int func_02196F44(u32 v, u8 *p);
extern void func_02196FF0(u8 *p);
extern void *func_02051B84(u8 *a0, int a1, int a2, int a3);
extern void func_02196A60(u8 *p);
extern void func_02196804(u8 *p);
void func_02196B94(Obj *a);
int func_02196BF8(u32 v, u8 *p);
void func_02196C68(u8 *p);
void func_02196CD8(u8 *p);
void func_02196D20(void);
extern struct Rec16 d_021D4080;
extern u8 d_021D4034[];
extern u8 d_021DDB44[];


/*
 * Addresses are Black-image addresses.
 */
void func_02196B94(Obj *a)
{
    Req r;

    r.x0 = 0;
    r.a = a;
    r.cb = func_02196B7C;
    func_0204B92C(a->objs[a->mode], 1);
    func_0204BA00(a->objs[a->mode], (const struct Cmd *)(&r));
    func_0204B9A0(a->objs[a->mode]);
    func_02196034(a, func_02196B90, 0x492);
}




/*
 * Handler: stores the request at +0x300 and dispatches on it.
 *
 * Addresses are Black-image addresses.
 */
int func_02196BF8(u32 v, u8 *p)
{
    int r = 1;

    ((struct Obj09493 *)p)->f300 = v;
    switch (v) {
    case 0:
        func_020061E4(0x73B);
        func_02196034((Obj *)p, func_02196B28, 0x4A3);
        break;
    case 1:
        func_020061E4(0x73B);
        ((struct Obj09493 *)p)->f8 = 5;
        func_02196034((Obj *)p, func_02196B28, 0x4A9);
        break;
    case 2:
        func_020061E4(0x73C);
        ((struct Obj09493 *)p)->f8 = 0xC;
        func_02196034((Obj *)p, func_02196B94, 0x4AF);
        break;
    default:
        r = 1;
        break;
    }
    return r;
}




/*
 * State setup: like func_02196A60 with a 16-byte record and other handlers.
 *
 * Addresses are Black-image addresses.
 */
void func_02196C68(u8 *p)
{
    struct Rec16 loc = d_021D4080;

    func_0219728C(p);
    func_021966B0(p, 0xD);
    func_0219630C(4, &loc, p, d_021DDB44, 0, 0);
    ((struct Obj00093 *)p)->f24 = func_02051B84(d_021D4034, (int)func_0219649C, (int)p, ((struct Obj00093 *)p)->f10);
    ((struct Obj00093 *)p)->f4 = func_02196F44;
    func_02196034((Obj *)p, func_02196FF0, 0x4CC);
}




/*
 * State step: registers the next handler through func_02196034.
 *
 * Addresses are Black-image addresses.
 */
void func_02196CD8(u8 *p)
{
    if (((struct Obj09494 *)p)->fC == 2) {
        if (((struct Obj09494 *)p)->f8 == 5) {
            ((struct Obj09494 *)p)->f8 = 1;
            func_02196034((Obj *)p, func_02196A60, 0x4DD);
        } else {
            func_02196034((Obj *)p, func_02196C68, 0x4E1);
        }
    } else {
        func_02196034((Obj *)p, func_02196804, 0x4E5);
    }
}




/*
 * Untraced blob: empty body (bx lr only).
 *
 * Addresses are Black-image addresses.
 */
void func_02196D20(void)
{
}
