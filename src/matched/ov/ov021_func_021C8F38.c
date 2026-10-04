/*
 * function: func_021C8F38
 * address:  0x021C8F38
 * packet:   pkt_ov021_021C8F38
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0204762C  0x0204762C  arm
 *   func_02047738  0x02047738  arm
 *   func_02047504  0x02047504  arm
 *   func_020470D0  0x020470D0  arm
 *   func_02046EFC  0x02046EFC  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09714.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

struct Rec;
struct Tagged;
extern void func_0204762C(struct Rec *p);
extern void func_02047738(struct Rec *p);
extern void func_02047504(struct Rec *p);
extern int func_020470D0(u32 *p);
extern void func_02046EFC(struct Tagged *p);

void func_021C8F38(u8 *p)
{
    u32 i;

    func_0204762C((struct Rec *)(((struct Obj09714 *)p)->f28));
    func_02047738((struct Rec *)(((struct Obj09714 *)p)->f30));
    func_02047504((struct Rec *)(((struct Obj09714 *)p)->f2C));
    for (i = 0; i < 4; i++) {
        func_020470D0((u32 *)(*(u32 *)(p + i * 4 + 4)));
        func_02046EFC((struct Tagged *)(*(u32 *)(p + i * 4 + 4)));
    }
    for (i = 0; i < 5; i++) {
        func_02046EFC((struct Tagged *)(*(u32 *)(p + i * 4 + 0x14)));
    }
}
