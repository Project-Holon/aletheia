/*
 * function: func_02156914
 * address:  0x02156914
 * packet:   pkt_02156914
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02045C44  0x02045C44  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045C04  0x02045C04  arm
 */
#include "../include/Obj12026.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct MsgBank;
extern struct MsgBank *func_02045C44(const void *file, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern int func_02045C04();

void *func_02156914(int a0, int a1)
{
    void *t4;
    struct MsgBank *t5;

a0 = ((struct Obj12026 *)a0)->f24;
a0 = ((struct Obj12026 *)a0)->f8;
    t5 = func_02045C44((const void *)a0, a1);
loc_0215691E:
a1 = 0;
    t4 = func_02045EC0(t5, a1);
loc_02156926:
    a0 = func_02045C04(t5);
loc_0215692E:
    return t4;}
