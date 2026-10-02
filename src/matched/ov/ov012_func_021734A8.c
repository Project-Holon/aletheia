/*
 * function: func_021734A8
 * address: 0x021734A8
 * packet: pkt_ov012_021734A8
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
typedef unsigned int u32;
void func_021734A8(u8 *self, u32 id, u32 v) { u8 *p; p=self+0x2830; switch(id) { case 0: *(u32 *)(p+0x14)=v; return; case 1: *(u32 *)(p+0x18)=v; return; case 2: *(u32 *)(p+0x1c)=v; return; case 3: *(u32 *)(p+0x20)=v; return; case 4: *p=v; } }
