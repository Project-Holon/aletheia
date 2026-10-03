/*
 * function: func_0220AF40
 * address: 0x0220AF40
 * packet: pkt_ov196_0220AF40
 * region: ov196
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * EXACT* tail: already matched ov196_func_0220AF64.c eight-byte stub.
 * symbols:
 *   sub_02030734 0x02030734 arm
 *   d_0220B100 0x0220B100 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern u8 *sub_02030734(u32,u32,int,const char *,u16);
extern const char d_0220B100[];
u8 *func_0220AF40(u16 v) { u8 *p; p=sub_02030734(v,24,0,d_0220B100,43); *(u16 *)(p+16)=v; *(u32 *)(p+20)=1; return p; }
