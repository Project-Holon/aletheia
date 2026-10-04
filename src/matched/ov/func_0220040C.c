/*
 * function: func_0220040C
 * address:  0x0220040C
 * packet:   pkt_0220040C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *

 * Claim the 0xb4/0x48 resource into +0xb88 and the 0x2d transfer into +0xb8c.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
struct MsgBank;
struct U16Vec;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);

void func_0220040C(u8 *p)
{
    *(u32 *)(p + 0xb88) = (u32)func_020457B0(0xb4, 0x48);
    *(u32 *)(p + 0xb8c) = (u32)func_02045EC0((struct MsgBank *)(*(u32 *)(p + 0xb6c)), 0x2d);
}
