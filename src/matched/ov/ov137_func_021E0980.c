/*
 * function: func_021E0980
 * address: 0x021E0980
 * packet: pkt_ov137_021E0980
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two-byte alignment padding at 0x021E09BE.
 * symbols:
 *   func_021E15DC 0x021E15DC thumb ov137
 */
#include "../include/Obj23778.h"
extern void func_021E15DC(int *,int);
void func_021E0980(char *p,int amount)
{
    int count = ((struct Obj23778 *)p)->f30;
    int i = 0;
    char *base = p+0x1a0;
    for (;i<count;i++) {
        if (*(int *)(base+0x140+i*0xb4))
            func_021E15DC((int *)(base+0x15c+i*0xb4),amount);
    }
}
