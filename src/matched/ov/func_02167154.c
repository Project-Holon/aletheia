/*
 * function: func_02167154
 * address:  0x02167154
 * packet:   pkt_02167154
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045B38  0x02045B38  arm
 */
#include "../include/Obj00565.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct MsgBank;

extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);

struct MsgBank *func_02167154(int a0, int a1, int a2, int a3)
{
    int t4;
    struct MsgBank *bank;

t4 = a0 + 0;
a3 = ((struct Obj00565 *)((char *)t4))->f0;
a0 = 0;
a1 = 3;
a2 = 0x2f;
    bank = func_02045B38(a0, a1, a2, a3);
loc_02167164:
*(struct MsgBank * *)&((struct Obj00565 *)t4)->f18 = bank;
    return bank;}
