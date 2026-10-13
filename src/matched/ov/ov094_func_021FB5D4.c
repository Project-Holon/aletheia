/*
 * function: func_021FB5D4
 * address:  0x021FB5D4
 * packet:   pkt_ov094_021FB5D4
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   func_021F8298  0x021F8298  thumb  ov094
 */
#include "../include/Obj21666.h"
typedef unsigned char u8;
typedef unsigned short u16;

struct Cursor;
extern unsigned int VM_GetU32(struct Cursor *p);
typedef unsigned int   u32;
extern void func_021F8298(u32 a, u8 b, u8 c, u8 d, u16 e);

int func_021FB5D4(struct Cursor *a, char *b)
{
    int t0, t1, t2, t3, t4;

    t0 = VM_GetU32(a);
    t1 = VM_GetU32(a);
    t2 = VM_GetU32(a);
    t3 = VM_GetU32(a);
    t4 = VM_GetU32(a);
    func_021F8298(t0, t1, t2, t3, t4);
    return ((struct Obj21666 *)b)->f23C;
}
