/*
 * function: func_021FF92C
 * address: 0x021FF92C
 * packet: pkt_ov135_021FF92C
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FF914 0x021FF914 thumb ov135
 *   func_021FFAEC 0x021FFAEC thumb ov135
 *   func_0204B98C 0x0204B98C arm
 *   func_020307B0 0x020307B0 arm
 *   func_02030EAC 0x02030EAC arm
 */
#include "../include/Obj10589.h"
#include "../include/Obj23436.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int state; int y; u8 *p; } Anim;
extern void func_021FF914(Anim *, int);
extern void func_021FFAEC(u32, int, int);
struct Actor;
extern u32 func_0204B98C(struct Actor *a);
extern void func_020307B0(void *);
struct Node;
extern void func_02030EAC(struct Node *n);
extern void func_020061E4(u32 a);
void func_021FF92C(void *task, Anim *a)
{
    u8 *p;
    p = a->p;
    switch (a->state) {
    case 0:
        if (a->y > 160) {
            a->y = 160;
            a->state = 1;
            func_021FF914(a, 1);
        }
        a->y += 2;
        func_021FFAEC(((struct Obj10589 *)p)->fD0C, 128, a->y);
        break;
    case 1:
        if (func_0204B98C((struct Actor *)(((struct Obj10589 *)p)->fD0C)) == 0) {
            func_021FF914(a, 2);
            a->state = 2;
        }
        break;
    case 2:
        if (a->y <= 138) {
            a->y = 138;
            a->state = 3;
            func_021FF914(a, 3);
        } else {
            a->y--;
        }
        func_021FFAEC(((struct Obj10589 *)p)->fD0C, 128, a->y);
        break;
    case 3:
        func_020061E4(0x55C);
        ((struct Obj23436 *)(a->p))->fE18 = 1;
        func_020307B0(a);
        func_02030EAC(task);
        break;
    }
}
