/*
 * function: func_021C6440
 * address: 0x021C6440
 * packet: pkt_ov128_021C6440
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02045838 0x02045838 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct U16Vec;
extern void func_02045838(struct U16Vec *dst, struct U16Vec *src);
void func_021C6440(u8 *p,void *a,void *b) { if(a) func_02045838(*(void **)(p+0x58),a); if(b) func_02045838(*(void **)(p+0x5c),b); }
