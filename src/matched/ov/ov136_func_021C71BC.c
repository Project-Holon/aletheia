/*
 * function: func_021C71BC
 * address:  0x021C71BC
 * packet:   pkt_ov136_021C71BC
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021C5974 0x021C5974 thumb
 */
#include "../include/Obj08199.h"
#include "../include/Obj23640.h"

typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021C5974(u8 *);
int func_021C71BC(u8 *p, u32 v)
{
    ((struct Obj23640 *)(*(u8 * *)&((struct Obj08199 *)p)->f8))->f1E0 = v;
    func_021C5974(p);
    return 4;
}
