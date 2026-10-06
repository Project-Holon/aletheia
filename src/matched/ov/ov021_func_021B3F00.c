/*
 * function: func_021B3F00
 * address:  0x021B3F00
 * packet:   pkt_ov021_021B3F00
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_0204B100  0x0204B100  arm
 *   func_0204B22C  0x0204B22C  arm
 *   func_021B3C78  0x021B3C78  thumb  ov021
 *   func_021B3CFC  0x021B3CFC  thumb  ov021
 *   func_021B3DEC  0x021B3DEC  thumb  ov021
 */
#include "../include/Obj00037.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Bank;
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0204B22C(struct Bank *bank, u32 mode);
extern void func_021B3C78(char *p);
extern void *func_020490F4(unsigned int id, u16 heap);
extern void func_021B3CFC(char *w);
extern void func_021B3DEC(char *w);

void func_021B3F00(u8 *w)
{
    ((struct Obj00037 *)w)->f1BC = (u32)func_0204B100(5, 1, ((struct Obj00037 *)w)->f4);
    func_0204B22C((struct Bank *)(((struct Obj00037 *)w)->f1BC), 1);
    func_021B3C78((char *)w);
    ((struct Obj00037 *)w)->f1F8 = func_020490F4(0x19, ((struct Obj00037 *)w)->f4);
    func_021B3CFC((char *)w);
    func_021B3DEC((char *)w);
}
