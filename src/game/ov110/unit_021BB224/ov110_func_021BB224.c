/*
 * function: func_021BB224
 * address: 0x021BB224
 * packet: pkt_ov110_021BB224
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021C37AA 0x021C37AA data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 a,b; } Pair;
extern Pair d_021C37AA;
void func_021BB224(u32 i,int *a,int *b) { *a=*(u8 *)((u32)&d_021C37AA.a+i*10); *b=*(u8 *)((u32)&d_021C37AA.b+i*10); }
