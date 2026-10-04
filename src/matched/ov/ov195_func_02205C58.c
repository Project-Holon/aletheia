/*
 * function: func_02205C58
 * address:  0x02205C58
 * packet:   pkt_02205C58
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02047964 0x02047964 arm
 *   func_02048AD0 0x02048AD0 arm
 *   func_020479D8 0x020479D8 arm
 */
#include "../include/Obj24957.h"

extern void func_02047964(void *);
extern int func_02048AD0(int);
extern void func_020479D8(int);

void func_02205C58(char *a)
{
    func_02047964(a);
    func_020479D8(func_02048AD0(((struct Obj24957 *)a)->f0));
}