/*
 * file:     field_wfbc_p10.c
 * unit:     yes
 * function: func_021966B0, func_021966F0, func_02196768, func_021967BC, func_02196804, func_0219686C, func_021968D8, func_021968DC, func_02196944, func_02196974, func_02196A4C, func_02196A60, func_02196ACC
 * address:  0x021966B0
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
 *   func_020490F4  0x020490F4  arm
 *   func_02049990  0x02049990  arm
 *   func_02049238  0x02049238  arm
 *   func_02040588  0x02040588  arm
 *   func_0219707C  0x0219707C  thumb  ov021
 *   func_0219630C  0x0219630C  thumb  ov021
 *   func_02051B84  0x02051B84  arm
 *   func_02196034  0x02196034  thumb  ov021
 *   func_0219649C  0x0219649C  thumb  ov021
 *   d_021D4070     0x021D4070  data  a4
 *   d_021D4014     0x021D4014  data  a4
 *   d_021D4024     0x021D4024  data  a4
 *   d_021D404C     0x021D404C  data  a4
 *   d_021DDB84     0x021DDB84  data  a4
 *   func_0201DD68  0x0201DD68  thumb
 *   func_02196454  0x02196454  thumb  ov021
 *   func_02040DA8  0x02040DA8  arm
 *   func_0203FB44  0x0203FB44  arm
 *   func_020403F4  0x020403F4  arm
 *   func_02045C04  0x02045C04  arm
 *   func_0201D83C  0x0201D83C  thumb
 *   func_02045808  0x02045808  arm
 *   func_020221A4  0x020221A4  thumb
 *   func_02155A90  0x02155A90  thumb  ov010
 *   func_02012138  0x02012138  thumb
 *   func_02026454  0x02026454  thumb
 *   func_0202208C  0x0202208C  thumb
 *   func_02026400  0x02026400  thumb
 *   func_02155A94  0x02155A94  thumb  ov010
 *   func_0200873C  0x0200873C  thumb
 *   func_02008428  0x02008428  thumb
 *   func_02197700  0x02197700  thumb  ov021
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204BA00  0x0204BA00  arm
 *   func_0204B9A0  0x0204B9A0  arm
 *   func_021975D0  0x021975D0  thumb  ov021
 *   func_02035C60  0x02035C60  arm
 *   func_021962F4  0x021962F4  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201AA1C  0x0201AA1C  thumb
 *   func_02045CAC  0x02045CAC  arm
 *   func_02197644  0x02197644  thumb  ov021
 *   func_02051C88  0x02051C88  arm
 *   func_02197190  0x02197190  thumb  ov021
 *   func_02196BF8  0x02196BF8  thumb  ov021
 *   func_02196FF0  0x02196FF0  thumb  ov021
 *   d_021D3FE0     0x021D3FE0  data  ov021  a4
 *   d_021D3FF4     0x021D3FF4  data  ov021  a4
 *   d_021DDAF4     0x021DDAF4  data  ov021  a4
 *   func_02196E04  0x02196E04  thumb  ov021
 *   func_02196C68  0x02196C68  thumb  ov021
 *   func_0200BAC8  0x0200BAC8  thumb
 *   func_0200BBA8  0x0200BBA8  thumb
 */
#include "../../matched/include/Obj00093.h"
#include "../../matched/include/Obj03578.h"
#include "../../matched/include/Obj12631.h"
#include "../../matched/include/Obj05988.h"
#include "../../matched/include/Obj09492.h"
#include "../../matched/include/Obj03115.h"
#include "../../matched/include/Obj19634.h"
#include "../../matched/include/Obj12632.h"
#include "../../matched/include/Obj19635.h"

struct Cb;
struct Rec;
struct U16Vec;
struct Ctx;
struct Comm;
struct Sub02008700Obj;
struct Actor;
struct Cmd;
struct BigObj;
struct Obj;
struct MsgBank;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct { u32 w[4]; } Blk;

typedef signed int     s32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct Obj { u8 pad[0x294]; void *objs[27]; u32 mode; } Obj;

typedef struct { u16 x0; Obj *a; void (*cb)(); } Req;

struct Rec8 { u32 a; u32 b; };

extern void *func_020490F4(u32 id, u32 heap);
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void func_02049238(void *h);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0219707C(u8 *p);
extern void func_0219630C(u32 a, void *b, void *c, void *d, void *e, void *f);
extern void *func_02051B84(u8 *a0, int a1, int a2, int a3);
extern void func_02196034(void *p, void *fn, u32 n);
extern void func_0219649C(void *a, int b, struct Cb *c);
extern void func_0201DD68(void);
extern void func_02196454(u8 *p);
extern void func_02040DA8(u32 a, u32 b, u32 c);
extern void func_0203FB44(u32 a, u32 b, u32 c);
extern void func_020403F4(u32 a);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201D83C(void *ptr);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_020221A4();
extern u32 func_02155A90(u8 *p);
extern u32 func_02012138(const struct Ctx *p);
extern u32 func_02026454(void *obj);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void func_02026400(struct Comm *p);
extern u32 func_02155A94(u8 *p);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern int func_02008428(unsigned short *p);
extern void func_02197700(u8 *a);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204BA00(struct Actor *a, const struct Cmd *cmd);
extern void func_0204B9A0(struct Actor *a);
extern int func_021975D0(u8 *p);
extern int func_02035C60(void);
extern void func_021962F4(u8 *);
extern void func_020061E4(u32 a);
extern void *func_02012934(const struct BigObj *p);
extern u32 func_0201AA1C(void *p);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_02197644(u8 *p, u32 b);
extern s32 func_02051C88(struct Ctx *c);
extern void func_02197190(u8 *p);
extern int func_02196BF8(u32 v, u8 *p);
extern void func_02196FF0(u8 *p);
extern void func_02196E04(u8 *p);
extern void func_02196C68(u8 *p);
extern void *func_0200BAC8(void *p);
extern u32 func_0200BBA8(void *a);
void func_021966B0(u8 *p, u32 a);
void func_021966F0(u8 *p);
void func_02196768(u8 *p);
void func_021967BC(u8 *p);
void func_02196804(u8 *p);
void func_0219686C(u8 *p);
void func_021968D8(void);
void func_021968DC(Obj *a);
void func_02196944(u8 *a);
int func_02196974(u32 s, u8 *p);
void func_02196A4C(u8 *a);
void func_02196A60(u8 *p);
void func_02196ACC(u8 *p);
extern Blk d_021D4070;
extern u8 d_021D4014[];
extern u8 d_021D4024[];
extern u8 d_021D404C[];
extern u8 d_021DDB84[];
extern struct Rec8 d_021D3FE0;
extern u8 d_021D3FF4[];
extern u8 d_021DDAF4[];





void func_021966B0(u8 *p, u32 a)
{
    void *h;

    h = func_020490F4(0x1D, ((struct Obj00093 *)p)->f10);
    func_02049990(h, a, 6, 0, (u16)((struct Obj00093 *)p)->f40, 0, 0, ((struct Obj00093 *)p)->f10);
    func_02049238(h);
    func_02040588(6, 1);
}





void func_021966F0(u8 *p)
{
    Blk t = d_021D4070;

    func_021966B0(p, 0xB);
    func_0219707C(p);
    func_0219630C(4, &t, p, d_021DDB84, d_021D4014, d_021D4024);
    *(u32 *)&((struct Obj00093 *)p)->f24 = (u32)func_02051B84(d_021D404C, (int)((void *)func_0219649C), (int)p, ((struct Obj00093 *)p)->f10);
    ((struct Obj00093 *)p)->f4 = (void *)func_02196974;
    func_02196034(p, (void *)func_02196A4C, 0x340);
}





void func_02196768(u8 *p)
{
    u32 v;

    func_0201DD68();
    func_02196454(p);
    func_02040DA8(5, 1, 0);
    v = ((struct Obj03578 *)p)->f3C;
    func_0203FB44(5, (u16)v, (u16)(v >> 16));
    func_020403F4(5);
    func_020403F4(4);
    func_02045C04((struct Rec *)(((struct Obj03578 *)p)->f28));
    func_0201D83C((void *)(((struct Obj03578 *)p)->f2C));
    func_02045808((struct U16Vec *)(((struct Obj03578 *)p)->f38));
    func_02040588(5, 0);
}





void func_021967BC(u8 *p)
{
    if (func_020221A4()) {
        if (((struct Obj12631 *)p)->f8 != 0xC) {
            if (func_02026454((void *)func_02012138((const struct Ctx *)
                    func_02155A90((u8 *)((struct Obj12631 *)p)->f2E4))) == 0)
                func_02196034(p, 0, 0x361);
        } else {
            func_02196034(p, 0, 0x365);
        }
    }
}





void func_02196804(u8 *p)
{
    p[0x306] = 1;
    func_0202208C(0, 0, 0, 0, 6, 1, ((struct Obj05988 *)p)->f10);
    if (((struct Obj05988 *)p)->f8 != 0xC) {
        if (func_02026454((void *)func_02012138((const struct Ctx *)func_02155A90((u8 *)((struct Obj05988 *)p)->f2E4))) != 0) {
            func_02026400((struct Comm *)func_02012138((const struct Ctx *)func_02155A90((u8 *)((struct Obj05988 *)p)->f2E4)));
        }
    }
    func_02196034(p, (void *)func_021967BC, 0x37C);
}





void func_0219686C(u8 *p)
{
    if (((struct Obj09492 *)p)->f8 == 0xC) {
        func_02196034(p, (void *)func_02196804, 0x38C);
        return;
    }
    if (func_02008428((unsigned short *)func_0200873C((void *)func_02155A94((u8 *)(((struct Obj09492 *)p)->f2E4)))) == 1) {
        func_02196034(p, (void *)func_02197700, 0x38F);
        return;
    }
    if (((struct Obj09492 *)p)->f8 - 6 <= 2) {
        func_02196034(p, (void *)func_02196804, 0x394);
        return;
    }
    func_02196034(p, (void *)func_02196A60, 0x397);
}





/*
 * Untraced blob: empty body (bx lr only).
 *
 * Addresses are Black-image addresses.
 */
void func_021968D8(void)
{
}





/*
 * Addresses are Black-image addresses.
 */
void func_021968DC(Obj *a)
{
    Req r;
    u32 i;

    i = a->mode;
    r.x0 = 0;
    r.a = a;
    r.cb = func_0219686C;
    if (i == 5) {
        i = 0;
    } else if (i == 6) {
        i = 1;
    } else if (i == 7) {
        i = 3;
    }
    func_0204B92C(a->objs[i], 1);
    func_0204BA00(a->objs[i], (const struct Cmd *)(&r));
    func_0204B9A0(a->objs[i]);
    func_02196034(a, func_021968D8, 0x3BF);
}





void func_02196944(u8 *a)
{
    if (func_021975D0(a) != 0 && func_02035C60() != 0) {
        func_021962F4(a);
        func_02196034(a, func_02196A4C, 0x3CB);
    }
}





int func_02196974(u32 s, u8 *p)
{
    int r = 0;

    ((struct Obj03115 *)p)->f300 = s;
    switch (s) {
    case 0:
    case 5:
        func_020061E4(0x73B);
        func_02196034(p, (void *)func_021968DC, 0x3DE);
        r = 1;
        ((struct Obj03115 *)p)->f8 = 1;
        break;
    case 1:
    case 6:
        if ((int)func_0201AA1C(func_02012934(((struct Obj03115 *)p)->f30)) < 2) {
            func_02045CAC((struct MsgBank *)(((struct Obj03115 *)p)->f28), 0x2C, (void *)(((struct Obj03115 *)p)->f38));
            func_02197644(p, 0);
            func_02196034(p, (void *)func_02196944, 0x3EA);
        } else {
            func_020061E4(0x73B);
            ((struct Obj03115 *)p)->f8 = 6;
            func_02196034(p, (void *)func_021968DC, 0x3F0);
            r = 1;
        }
        break;
    case 2:
        func_020061E4(0x73B);
        ((struct Obj03115 *)p)->f8 = 8;
        func_02196034(p, (void *)func_021968DC, 0x3F6);
        r = 1;
        break;
    case 3:
    case 7:
        func_020061E4(0x73B);
        ((struct Obj03115 *)p)->f8 = 7;
        func_02196034(p, (void *)func_021968DC, 0x3FD);
        r = 1;
        break;
    case 4:
        func_020061E4(0x73C);
        ((struct Obj03115 *)p)->f8 = 0xC;
        func_02196034(p, (void *)func_021968DC, 0x404);
        break;
    }
    return r;
}




void func_02196A4C(u8 *a)
{
    if (func_020221A4() != 0) {
        func_02051C88((struct Ctx *)(((struct Obj19634 *)a)->f24));
    }
}




/*
 * State setup: copies an 8-byte record, calls the setup helpers, installs
 * the per-frame handler at +4 and registers the next step.
 *
 * Addresses are Black-image addresses.
 */
void func_02196A60(u8 *p)
{
    struct Rec8 loc = d_021D3FE0;

    func_02197190(p);
    func_021966B0(p, 0xC);
    func_0219630C(2, &loc, p, d_021DDAF4, 0, 0);
    ((struct Obj00093 *)p)->f24 = func_02051B84(d_021D3FF4, (int)func_0219649C, (int)p, ((struct Obj00093 *)p)->f10);
    ((struct Obj00093 *)p)->f4 = func_02196BF8;
    func_02196034(p, func_02196FF0, 0x432);
}


/*
 * State step: picks the next handler from the state word and a status query.
 *
 * Addresses are Black-image addresses.
 */
void func_02196ACC(u8 *p)
{
    if (((struct Obj12632 *)p)->f8 == 5) {
        if (func_0200BBA8(func_0200BAC8(((struct Obj19635 *)(*(u8 * *)&((struct Obj12632 *)p)->f2E4))->f4C)) != 0) {
            func_02196034(p, func_02196E04, 0x443);
        } else {
            func_02196034(p, func_02196804, 0x446);
        }
    } else {
        func_02196034(p, func_02196C68, 0x44D);
    }
}
