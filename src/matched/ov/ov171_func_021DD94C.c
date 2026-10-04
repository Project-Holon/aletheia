/*
 * function: func_021DD94C
 * address:  0x021DD94C
 * packet:   pkt_021DD94C
 * region:   ov171
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 */
#include "../include/Obj14291.h"

typedef unsigned char u8;
typedef unsigned int u32;

struct Cfg;
struct Descriptor;
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32 bit);

void func_021DD94C(int *p)
{
    func_02045374((struct Cfg *)(((struct Obj14291 *)p)->f0));
    func_02041B6C(func_02045730((struct Descriptor *)(((struct Obj14291 *)p)->f0)));
}
