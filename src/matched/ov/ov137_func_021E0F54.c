/*
 * function: func_021E0F54
 * address:  0x021E0F54
 * packet:   pkt_021E0F54
 * region:   ov137
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030EAC  0x02030EAC  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj23791.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Node;
extern void func_02030EAC(struct Node *n);

void func_021E0F54(u8 *p)
{
    func_02030EAC(((struct Obj23791 *)p)->fD80);
}
