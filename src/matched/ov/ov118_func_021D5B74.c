/*
 * function: func_021D5B74
 * address:  0x021D5B74
 * packet:   pkt_ov118_021D5B74
 * region:   ov118
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D8E84  0x021D8E84  thumb  ov119
 *   func_021DFA60  0x021DFA60  thumb  ov119
 *   func_021E3004  0x021E3004  thumb  ov119
 *   func_021D5B98  0x021D5B98  thumb  ov118
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj13879.h"

typedef unsigned int u32;
typedef unsigned char u8;
typedef int s32;

extern void func_021D8E84(void *p, int next);
extern void func_021DFA60(u32 key);
extern void func_021E3004(char *p);
extern void func_021D5B98(u8 *p);

void func_021D5B74(u8 *p)
{
    func_021DFA60(((struct Obj13879 *)p)->fF2C);
    func_021E3004(((struct Obj13879 *)p)->fC);
    func_021D8E84(p, (int)func_021D5B98);
}
