/*
 * file:     field_wfbc_p13.c
 * unit:     yes
 * function: func_02196D24, func_02196D88, func_02196D94, func_02196E04, func_02196E70, func_02196EC8
 * address:  0x02196D24
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
 *   d_021D3F9C     0x021D3F9C  data  ov021  a1
 *   func_02196CD8  0x02196CD8  thumb  ov021
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204BA00  0x0204BA00  arm
 *   func_0204B9A0  0x0204B9A0  arm
 *   func_02196034  0x02196034  thumb  ov021
 *   func_02196D20  0x02196D20  thumb  ov021
 *   func_02051C88  0x02051C88  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_0219630C  0x0219630C  thumb  ov021
 *   func_021966B0  0x021966B0  thumb  ov021
 *   func_021973A0  0x021973A0  thumb  ov021
 *   func_0219649C  0x0219649C  thumb  ov021
 *   func_02051B84  0x02051B84  arm
 *   d_021D3FD8     0x021D3FD8  data  ov021  a4
 *   d_021D4004     0x021D4004  data  ov021  a4
 *   d_021DDAF4     0x021DDAF4  data  ov021  a4
 *   func_02196A60  0x02196A60  thumb  ov021
 *   func_02196804  0x02196804  thumb  ov021
 *   func_0200BAC8  0x0200BAC8  thumb
 *   func_0200BBA8  0x0200BBA8  thumb
 */
#include "../../matched/include/Obj17948.h"
#include "../../matched/include/Obj07463.h"
#include "../../matched/include/Obj00093.h"
#include "../../matched/include/Obj12633.h"
#include "../../matched/include/Obj19636.h"

struct Actor;
struct Cmd;
struct Ctx;
struct Obj;
struct Cb;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct Obj { u32 x0; u32 x4; u32 x8; u32 xc; u8 pad[0x284]; void *objs[27]; u32 mode; } Obj;

typedef struct { u16 x0; Obj *a; void (*cb)(); } Req;

typedef struct { u8 v[3]; } Tbl3;

typedef signed int     s32;

struct Rec8 { u32 a; u32 b; };

extern void func_02196CD8(u8 *p);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204BA00(struct Actor *a, const struct Cmd *cmd);
extern void func_0204B9A0(struct Actor *a);
extern void func_02196034(Obj *, void (*)(), u32);
extern void func_02196D20();
extern s32 func_02051C88(struct Ctx *c);
extern void func_020061E4(u32 a);
extern void func_0219630C(u32 a, void *b, u8 *c, void *d, u32 e, u32 f);
extern void func_021966B0(u8 *p, u32 n);
extern void func_021973A0(u8 *p);
extern void func_0219649C(void *a, int b, struct Cb *c);
extern void *func_02051B84(u8 *a0, int a1, int a2, int a3);
extern void func_02196A60(u8 *p);
extern void func_02196804(u8 *p);
extern void *func_0200BAC8(void *p);
extern u32 func_0200BBA8(void *a);
void func_02196D24(Obj *a);
void func_02196D88(u8 *p);
int func_02196D94(u32 v, u8 *p);
void func_02196E04(u8 *p);
void func_02196E70(u8 *p);
void func_02196EC8(void);
extern const Tbl3 d_021D3F9C;
extern struct Rec8 d_021D3FD8;
extern u8 d_021D4004[];
extern u8 d_021DDAF4[];


/*
 * Addresses are Black-image addresses.
 */
void func_02196D24(Obj *a)
{
    Tbl3 t = d_021D3F9C;
    Req r;
    int i;

    i = t.v[a->xc];
    r.x0 = 0;
    r.a = a;
    r.cb = func_02196CD8;
    func_0204B92C(a->objs[i], 1);
    func_0204BA00(a->objs[i], (const struct Cmd *)(&r));
    func_0204B9A0(a->objs[i]);
    func_02196034(a, func_02196D20, 0x504);
}





/*
 * Untraced thunk: tail call on the word at +0x24 into the ARM9 image.
 *
 * Addresses are Black-image addresses.
 */
void func_02196D88(u8 *p)
{
    func_02051C88((struct Ctx *)(((struct Obj17948 *)p)->f24));
}





/*
 * Handler: stores the request at +0x300 and dispatches on it.
 *
 * Addresses are Black-image addresses.
 */
int func_02196D94(u32 v, u8 *p)
{
    int r = 0;

    ((struct Obj07463 *)p)->f300 = v;
    switch (v) {
    case 1:
        func_020061E4(0x73B);
        ((struct Obj07463 *)p)->fC = 0;
        func_02196034((Obj *)p, func_02196D24, 0x524);
        r = 1;
        break;
    case 0:
        func_020061E4(0x73B);
        r = 1;
        ((struct Obj07463 *)p)->fC = 1;
        func_02196034((Obj *)p, func_02196D24, 0x52A);
        break;
    case 2:
        func_020061E4(0x73C);
        ((struct Obj07463 *)p)->fC = 2;
        func_02196034((Obj *)p, func_02196D24, 0x530);
        break;
    }
    return r;
}





/*
 * State setup: like func_02196A60 with other handlers.
 *
 * Addresses are Black-image addresses.
 */
void func_02196E04(u8 *p)
{
    struct Rec8 loc = d_021D3FD8;

    func_021973A0(p);
    func_021966B0(p, 0xD);
    func_0219630C(2, &loc, p, d_021DDAF4, 0, 0);
    ((struct Obj00093 *)p)->f24 = func_02051B84(d_021D4004, (int)func_0219649C, (int)p, ((struct Obj00093 *)p)->f10);
    ((struct Obj00093 *)p)->f4 = func_02196D94;
    func_02196034((Obj *)p, func_02196D88, 0x54D);
}





/*
 * State step: picks the next handler from the state word and a status query.
 *
 * Addresses are Black-image addresses.
 */
void func_02196E70(u8 *p)
{
    if (((struct Obj12633 *)p)->f8 == 0xC) {
        func_02196034((Obj *)p, func_02196A60, 0x558);
    } else {
        if (func_0200BBA8(func_0200BAC8(((struct Obj19636 *)(*(u8 * *)&((struct Obj12633 *)p)->f2E4))->f4C)) != 0) {
            func_02196034((Obj *)p, func_02196E04, 0x55D);
        } else {
            func_02196034((Obj *)p, func_02196804, 0x560);
        }
    }
}



/*
 * Untraced blob: empty body (bx lr only).
 *
 * Addresses are Black-image addresses.
 */
void func_02196EC8(void)
{
}
