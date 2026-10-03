/*
 * function: func_021BB290
 * address: 0x021BB290
 * packet: pkt_ov110_021BB290
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_021BF6D4 0x021BF6D4 thumb ov110
 *   d_021C3C44 0x021C3C44 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02030734(u32,u32,int,const char *,u16); extern u8 *func_021BF6D4(u8 *); extern const char d_021C3C44[];
u8 *func_021BB290(u32 a,u8 *b,u32 c) { u8 *p; p=func_02030734(42,164,0,d_021C3C44,220); *(u32 *)p=a; *(u8 **)(p+4)=b; *(u32 *)(p+8)=c; *(u32 *)(p+12)=0; *(u32 *)(p+20)=0; *(u32 *)(p+84)=0; *(u32 *)(p+88)=0; *(u8 **)(p+92)=func_021BF6D4(b); return p; }
