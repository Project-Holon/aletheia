/*
 * function: func_021A1AAC
 * address:  0x021A1AAC
 * packet:   pkt_ov021_021A1AAC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02030EAC  0x02030EAC  arm
 *   func_021A1DF8  0x021A1DF8  thumb  ov021
 *   func_021A1C04  0x021A1C04  thumb  ov021
 *   func_0204B084  0x0204B084  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_021A15D4  0x021A15D4  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj07491.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Bank;
struct Node;
extern void func_02030EAC(struct Node *n);
extern void func_021A1DF8(u8 *p);
extern void func_021A1C04(u8 *p);
extern void func_0204B084(u32 v);
extern void func_0204B1CC(struct Bank *bank);
extern int func_021A15D4(u32 a);
extern void func_020307B0(void *p);

void func_021A1AAC(u8 *p)
{
    int i;

    func_02030EAC((struct Node *)(((struct Obj07491 *)p)->f2C));
    for (i = 0; i < 2; i++) {
        func_021A1DF8((u8 *)(*(u32 *)(p + 0x20 + i * 4)));
    }
    func_021A1C04(p);
    func_0204B084(((struct Obj07491 *)p)->f1C);
    func_0204B1CC((struct Bank *)(((struct Obj07491 *)p)->f18));
    for (i = 0; i < 2; i++) {
        func_021A15D4(((u32 *)p)[i]);
    }
    func_020307B0(p);
}
