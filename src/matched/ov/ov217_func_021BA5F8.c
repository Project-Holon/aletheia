/*
 * function: func_021BA5F8
 * address:  0x021BA5F8
 * packet:   pkt_ov217_021BA5F8
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021C2ED8  0x021C2ED8  data  a4
 */
#include "../include/Obj25830.h"

typedef unsigned short u16;
typedef unsigned int u32;

struct MsgBank;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 d_021C2ED8[];

void func_021BA5F8(char *self)
{
    int i = 0;
    do {
        int o = i * 4;
        *(u32 *)(self + o + 0xc) = (u32)func_02045B38((int)0, (int)2, (u16)(*(u32 *)((char *)d_021C2ED8 + o)), (u16)(((struct Obj25830 *)self)->f4));
        i++;
    } while (i < 2);
}
