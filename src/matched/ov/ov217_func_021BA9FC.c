/*
 * function: func_021BA9FC
 * address:  0x021BA9FC
 * packet:   pkt_ov217_021BA9FC
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021C2ED2  0x021C2ED2  data  a4
 *   d_021C2ED0  0x021C2ED0  data  a4
 */
#include "../include/Obj25835.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Bank;
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern u16 d_021C2ED2[];
extern u8 d_021C2ED0[];

void func_021BA9FC(char *self)
{
    int i = 0;
    do {
        *(u32 *)(self + i * 4 + 0x74) = (u32)func_0204B100(d_021C2ED2[i], d_021C2ED0[i], ((struct Obj25835 *)self)->f4);
        i++;
    } while (i < 2);
}
