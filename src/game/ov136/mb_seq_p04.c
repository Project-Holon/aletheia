/*
 * file:     mb_seq_p04.c
 * unit:     yes
 * function: func_021C6EA4, func_021C6FA8, func_021C6FD4, func_021C7024, func_021C7048, func_021C7064, func_021C7084, func_021C7094, func_021C70C0, func_021C70EC, func_021C7110, func_021C714C, func_021C7178
 * address:  0x021C6EA4
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02008FA4 0x02008FA4 thumb
 *   func_020213AC 0x020213AC thumb
 *   func_02027974  0x02027974  thumb
 *   func_020279E8  0x020279E8  thumb
 *   func_02027A04  0x02027A04  thumb
 *   func_0202CC70  0x0202CC70  thumb
 *   func_021C5B30 0x021C5B30 thumb
 *   func_021C61CC 0x021C61CC thumb
 *   func_021C62F4 0x021C62F4 thumb
 *   func_021C630C 0x021C630C thumb
 *   func_021C66A0 0x021C66A0 thumb
 *   func_021C66B8 0x021C66B8 thumb
 *   func_021C6884 0x021C6884 thumb
 *   func_021C71A8 0x021C71A8 thumb
 *   func_021C7298 0x021C7298 thumb
 *   func_021C730C 0x021C730C thumb
 *   func_021C7350 0x021C7350 thumb
 *   func_021C7430 0x021C7430 thumb
 *   func_020061E4            0x020061E4  thumb
 *   func_021C770C 0x021C770C thumb
 *   func_021C7360 0x021C7360 thumb ov136
 *   func_021C76D0 0x021C76D0 thumb ov136
 *   func_021C61D0 0x021C61D0 thumb ov136
 *   func_021C71BC 0x021C71BC thumb ov136
 *   func_020260E0 0x020260E0 thumb
 *   func_021C62BC 0x021C62BC thumb
 *   func_021C7620 0x021C7620 thumb
 *   func_0204B98C   0x0204B98C  arm
 *   func_0202208C   0x0202208C  thumb
 */
#include "../../matched/include/Obj00127.h"
#include "../../matched/include/Obj23624.h"
#include "../../matched/include/Obj23625.h"
#include "../../matched/include/Obj23626.h"
#include "../../matched/include/Obj14196.h"
#include "../../matched/include/Obj01066.h"
#include "../../matched/include/Obj23628.h"
#include "../../matched/include/Obj10607.h"
#include "../../matched/include/Obj10608.h"
#include "../../matched/include/Obj08206.h"
#include "../../matched/include/Obj08207.h"
#include "../../matched/include/Obj23630.h"
#include "../../matched/include/Obj23631.h"
#include "../../matched/include/Obj10609.h"
#include "../../matched/include/Obj23632.h"
#include "../../matched/include/Obj23633.h"
#include "../../matched/include/Obj23635.h"
#include "../../matched/include/Obj23636.h"
#include "../../matched/include/Obj23637.h"
#include "../../matched/include/Obj23638.h"

struct WinMgr;
struct Sub02008F80Obj;
struct TaskMenu;
struct Sound;
struct Actor;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct Bf7 {
    u8 v : 7;
    u8 w : 1;
};

extern void func_02027974(void *);
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *p);
extern void func_021C5B30(u8 *);
extern void func_021C62F4(u8 *);
extern void func_021C66B8(u8 *, int, u32);
extern void func_021C61CC(u8 *);
extern void func_021C6884(u8 *);
extern void func_021C7350(u8 *);
extern void func_021C66A0(u8 *p, int i, u32 v);
extern void func_021C730C(void *p);
extern void func_021C630C(u8 *p, unsigned int i);
extern int func_021C71A8(char *p, int v, int w);
extern u8 func_02008FA4(const struct Sub02008F80Obj *obj);
extern u16 func_020213AC(u32);
extern void func_021C7430(u8 *, int, u16, u16);
extern void func_0202CC70(struct WinMgr *mgr, u32 idx);
extern void func_021C7298(void *p, int v);
extern int func_021C770C(u8 *);
extern void func_020061E4(u32);
extern void func_021C7360(u8 *);
extern u8 func_020260E0(struct Sound *obj);
extern void func_021C76D0(u8 *p, u32 v);
extern void func_021C61D0(void *);
extern int func_021C71BC(u8 *p, int v);
extern void func_021C62BC(u8 *);
extern void func_021C7620(u8 *);
extern u32 func_0204B98C(struct Actor *a);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
int func_021C6EA4(u8 *p);
int func_021C6FA8(u8 *p);
int func_021C6FD4(u8 *p);
int func_021C7018(char *p);
void func_021C7024(char *p);
int func_021C703C(char *p);
int func_021C7048(u8 *p);
void func_021C7064(u8 *p);
void func_021C7084(u8 *p);
int func_021C7094(u8 *p);
int func_021C70C0(u8 *p);
int func_021C70EC(u8 *p);
int func_021C7110(u8 *p);
int func_021C714C(u8 *p, u32 v);
int func_021C7178(u8 *p, u32 v);

int func_021C6EA4(u8 *p)
{
    func_02027974(((struct Obj23624 *)(*(u8 * *)&((struct Obj00127 *)p)->f8))->f310);
    if (func_020279E8(((struct Obj23625 *)(*(u8 * *)&((struct Obj00127 *)p)->f8))->f310) == 0) {
        return 0xE;
    }
    switch (func_02027A04(((struct Obj23626 *)(*(u8 * *)&((struct Obj00127 *)p)->f8))->f310)) {
    case 0:
        func_021C5B30(p);
        func_021C62F4(p);
        func_021C66B8(*(u8 * *)&((struct Obj00127 *)p)->f8, 2, 0);
        func_021C61CC(*(u8 * *)&((struct Obj00127 *)p)->f8);
        func_021C6884(*(u8 * *)&((struct Obj00127 *)p)->f8);
        func_021C7350(p);
        func_021C66A0(*(u8 * *)&((struct Obj00127 *)p)->f8, 7, 0xE);
        func_021C730C(*(u8 * *)&((struct Obj00127 *)p)->f8);
        return 0xF;
    case 1:
        func_021C5B30(p);
        func_021C630C(p, 0);
        return func_021C71A8((char *)p, 0, 0x11);
    case 2: {
        u8 k;
        func_021C5B30(p);
        k = p[0x1F];
        func_021C7430(p, 0xE, func_020213AC(func_02008FA4(*(void **)(*(u8 * *)&((struct Obj00127 *)p)->f8 + k * 4 + 0x298))), k);
        ((struct Obj00127 *)p)->f14 = 0;
        ((struct Obj00127 *)p)->f28 = 6;
        return func_021C7178(p, 1);
    }
    case -2:
    case 3:
        func_021C5B30(p);
        func_021C62F4(p);
        func_0202CC70(**(void ** *)&((struct Obj00127 *)p)->f8, 10);
        func_021C7298(*(u8 * *)&((struct Obj00127 *)p)->f8, 0);
        func_021C66B8(*(u8 * *)&((struct Obj00127 *)p)->f8, 2, 1);
        return 9;
    default:
        return 0xE;
    }
}

int func_021C6FA8(u8 *p)
{
    if (func_021C770C(p) == 1) {
        func_020061E4(0x551);
        func_021C66A0(*(u8 * *)&((struct Obj14196 *)p)->f8, 3, 9);
        ((struct Obj14196 *)p)->f28 = 0x10;
        return 0x18;
    }
    return 0xF;
}

int func_021C6FD4(u8 *p)
{
    func_021C7360(p);
    func_021C76D0(p, func_020260E0(((struct Obj23628 *)(*(u8 * *)&((struct Obj01066 *)p)->f8))->f294));
    func_021C61D0(((struct Obj01066 *)p)->f8);
    func_0202CC70(**(void ** *)&((struct Obj01066 *)p)->f8, 10);
    func_021C66B8(((struct Obj01066 *)p)->f8, 2, 1);
    func_021C7298(((struct Obj01066 *)p)->f8, 0);
    return 9;
}

int func_021C7018(char *p)
{
    return func_021C71BC((u8 *)p, 0);
}

/*
 * extent: stops before separately filed leaf func_021C7048.
 */
void func_021C7024(char *p)
{
    func_021C630C((unsigned char *)p, 2);
    func_021C71A8(p, 0, 0x13);
}

int func_021C703C(char *p)
{
    return func_021C71BC((u8 *)p, 1);
}

int func_021C7048(u8 *p)
{
    if (p[0x20] != 6) {
        ((struct Obj10607 *)p)->f28 = 0x15;
        return 0;
    }
    ((struct Obj10607 *)p)->f14 = 2;
    return 6;
}

void func_021C7064(u8 *p)
{
    func_021C66B8(*(u8 * *)&((struct Obj10608 *)p)->f8, 2, 0);
    func_021C7298(*(u8 * *)&((struct Obj10608 *)p)->f8, 1);
    func_021C714C(p, 0x16);
}

void func_021C7084(u8 *p)
{
    func_021C62BC(p);
    func_021C7620(p);
}

int func_021C7094(u8 *p)
{
    if (((struct Obj08206 *)p)->f24 == 0) {
        ((struct Obj08206 *)p)->f28 = 0x15;
        return 0;
    }
    func_021C7430(p, 0xB, ((struct Obj08206 *)p)->f22, ((struct Bf7 *)(p + 0x21))->v);
    ((struct Obj08206 *)p)->f14 = 3;
    return 6;
}

int func_021C70C0(u8 *p)
{
    if (func_0204B98C(((struct Obj23630 *)(*(u8 * *)&((struct Obj08207 *)p)->f8))->f1FC) == 0) {
        ((struct Obj23631 *)(*(u8 * *)&((struct Obj08207 *)p)->f4))->f4 = 0;
        func_021C66A0(*(u8 * *)&((struct Obj08207 *)p)->f8, 7, 0);
        return ((struct Obj08207 *)p)->f28;
    }
    return 0x18;
}

int func_021C70EC(u8 *p)
{
    if (func_0204B98C(((struct Obj23632 *)(*(u8 * *)&((struct Obj10609 *)p)->f8))->f20C) == 0) {
        ((struct Obj23633 *)(*(u8 * *)&((struct Obj10609 *)p)->f4))->f4 = 1;
        return ((struct Obj10609 *)p)->f28;
    }
    return 0x19;
}

int func_021C7110(u8 *p)
{
    func_021C62F4(p);
    func_0202CC70(**(void ** *)&((struct Obj01066 *)p)->f8, 10);
    func_021C76D0(p, func_020260E0(((struct Obj23635 *)(*(u8 * *)&((struct Obj01066 *)p)->f8))->f294));
    func_021C66B8(*(u8 * *)&((struct Obj01066 *)p)->f8, 2, 1);
    func_021C7298(*(u8 * *)&((struct Obj01066 *)p)->f8, 0);
    return 9;
}

int func_021C714C(u8 *p, u32 v)
{
    func_0202208C((void *)0, 1, 1, 0, 6, 1, 0x66);
    ((struct Obj23636 *)(*(u8 * *)&((struct Obj10608 *)p)->f8))->f308 = v;
    return 2;
}

int func_021C7178(u8 *p, u32 v)
{
    func_0202208C((void *)0, 0, 0, 0, 6, 1, 0x66);
    ((struct Obj23638 *)(*(u8 * *)&((struct Obj23637 *)p)->f8))->f308 = v;
    return 2;
}
