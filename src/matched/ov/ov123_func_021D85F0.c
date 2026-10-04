/*
 * function: func_021D85F0
 * address: 0x021D85F0
 * packet: pkt_ov123_021D85F0
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D706C 0x021D706C thumb ov123
 *   func_021D580C 0x021D580C thumb ov123
 *   func_020362DC 0x020362DC arm
 *   func_02035C60 0x02035C60 arm
 */
#include "../include/Obj22970.h"
extern void func_021D6EE0(char *, int, int);
extern void func_021D706C(char *);
extern int func_021D580C(char *);
extern unsigned int func_020362DC(void);
extern int func_02035C60(void);
void func_021D85F0(char *p)
{
    if (func_021D580C(*(char * *)&((struct Obj22970 *)p)->f18)) {
        if (func_020362DC() || func_02035C60()) {
            func_021D6EE0(p, (int)func_021D706C, 0x746);
        }
    }
}
