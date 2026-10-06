/*
 * function: func_02206E28
 * address:  0x02206E28
 * packet:   pkt_ov094_02206E28
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02207960  0x02207960  thumb  ov094
 *   func_0220778C  0x0220778C  thumb  ov094
 *   func_02005E9C  0x02005E9C  thumb
 *   func_02208D24  0x02208D24  thumb  ov094
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02049238  0x02049238  arm
 *   func_02030EE8  0x02030EE8  arm
 *   func_02030EAC  0x02030EAC  arm
 */
#include "../include/Obj00380.h"
typedef unsigned int u32;

typedef enum { SLOT_0, SLOT_MAX = 8 } Slot;

typedef struct {
    unsigned int lo : 2;
    unsigned int b2 : 1;
} Bf;

extern void func_02207960(char *p, int i);
extern void func_0220778C(char *p, int i);
extern int func_02005E9C(void);
extern void func_02208D24(int a);
struct Node;
extern void func_0204ADA4(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
struct Bank;
struct S02030EE8;
extern u32 func_0204B1CC(struct Bank *bank);
extern u32 func_020307B0(void *p);
extern void func_02049238(u32 h);
extern u32 func_02030EE8(struct S02030EE8 *p);
extern void func_02030EAC(struct Node *n);

void func_02206E28(char *p)
{
    Slot i;
    int j;

    for (i = SLOT_0; i < SLOT_MAX; i++) {
        func_02207960(p, i);
        func_0220778C(p, i);
    }
    if (((Bf *)(p + 0x440))->b2) {
        func_02005E9C();
        func_02208D24(0);
    }
    for (j = 0; j < 6; j++)
        func_0204ADA4(*(int *)(p + j * 4 + 0x18));
    func_0204A8D4(((struct Obj00380 *)p)->f30);
    func_0204AFD8(((struct Obj00380 *)p)->f34);
    func_0204ADA4(((struct Obj00380 *)p)->f38);
    func_0204ADA4(((struct Obj00380 *)p)->f3C);
    func_0204B1CC((struct Bank *)(((struct Obj00380 *)p)->f0));
    func_020307B0(((struct Obj00380 *)p)->f10);
    func_02049238(((struct Obj00380 *)p)->f4);
    func_020307B0((void *)func_02030EE8(((struct Obj00380 *)p)->fC));
    func_02030EAC(((struct Obj00380 *)p)->fC);
    func_020307B0(p);
}
