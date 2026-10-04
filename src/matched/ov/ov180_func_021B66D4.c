/*
 * function: func_021B66D4
 * address:  0x021B66D4
 * packet:   pkt_021B66D4
 * region:   ov180
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02047E54  0x02047E54  arm
 *   func_02046788  0x02046788  arm
 */
#include "../include/Obj24484.h"

struct Rec;
extern void func_02047E54(struct Rec *p);
extern void func_02046788(void);

void func_021B66D4(int *p)
{
    func_02047E54((struct Rec *)(((struct Obj24484 *)p)->f10));
    func_02046788();
}
