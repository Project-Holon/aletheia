/*
 * function: func_0221320C
 * address: 0x0221320C
 * packet: pkt_ov199_0221320C
 * region: ov199
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   func_02213808 0x02213808 thumb ov199
 */
#include "../include/Obj14576.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
extern void func_02213808(char *, int);
int func_0221320C(char *p, char *q, char *work)
{
    func_020307B0(q);
    if (((struct Obj14576 *)work)->f1C == 1) func_02213808(p, 0);
    else {
        ((struct Obj14576 *)work)->f20 = 3;
        func_02213808(p, 1);
    }
    return 1;
}
