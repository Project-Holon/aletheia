/*
 * file:     field_wfbc_p31.c
 * unit:     yes
 * function: func_0219686C, func_021968D8, func_021968DC, func_02196944, func_02196974
 * address:  0x0219686C
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
 *   func_02155A94  0x02155A94  thumb  ov010
 *   func_0200873C  0x0200873C  thumb
 *   func_02008428  0x02008428  thumb
 *   func_02196034  0x02196034  thumb  ov021
 *   func_02196804  0x02196804  thumb  ov021
 *   func_02197700  0x02197700  thumb  ov021
 *   func_02196A60  0x02196A60  thumb  ov021
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204BA00  0x0204BA00  arm
 *   func_0204B9A0  0x0204B9A0  arm
 *   func_021975D0  0x021975D0  thumb  ov021
 *   func_02035C60  0x02035C60  arm
 *   func_021962F4  0x021962F4  thumb  ov021
 *   func_02196A4C  0x02196A4C  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201AA1C  0x0201AA1C  thumb
 *   func_02045CAC  0x02045CAC  arm
 *   func_02197644  0x02197644  thumb  ov021
 */
#include "../../matched/include/Obj09492.h"
#include "../../matched/include/Obj03115.h"

struct Sub02008700Obj;
struct Actor;
struct Cmd;
struct BigObj;
struct Obj;
struct MsgBank;
typedef unsigned char  u8;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef signed int     s32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct Obj { u8 pad[0x294]; void *objs[27]; u32 mode; } Obj;

typedef struct { u16 x0; Obj *a; void (*cb)(); } Req;

extern u32 func_02155A94(u8 *p);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern int func_02008428(unsigned short *p);
extern void func_02196034(void *p, void *fn, u32 n);
extern void func_02196804(u8 *p);
extern void func_02197700(u8 *a);
extern void func_02196A60(u8 *p);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204BA00(struct Actor *a, const struct Cmd *cmd);
extern void func_0204B9A0(struct Actor *a);
extern int func_021975D0(u8 *p);
extern int func_02035C60(void);
extern void func_021962F4(u8 *);
extern void func_02196A4C(u8 *a);
extern void func_020061E4(u32 a);
extern void *func_02012934(const struct BigObj *p);
extern u32 func_0201AA1C(void *p);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_02197644(u8 *p, u32 b);
void func_0219686C(u8 *p);
void func_021968D8(void);
void func_021968DC(Obj *a);
void func_02196944(u8 *a);
int func_02196974(u32 s, u8 *p);


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
