/*
 * function: func_02211378
 * address:  0x02211378
 * packet:   pkt_02211378
 * region:   ov198
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_0220C688 0x0220C688 thumb
 *   func_0220E27C 0x0220E27C thumb
 */
#include "../include/Obj25281.h"

typedef unsigned int   u32;
extern void func_0201F7A8(void *desc, u32 kind);
extern void func_0220C688(char *p);
extern void func_0220E27C(void *);

int func_02211378(char *p)
{
    func_0201F7A8(((struct Obj25281 *)p)->f1F68, 0);
    func_0220C688(p);
    func_0220E27C(p);
    return 8;
}
