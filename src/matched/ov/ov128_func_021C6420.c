/*
 * function: func_021C6420
 * address: 0x021C6420
 * packet: pkt_ov128_021C6420
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020355D8 0x020355D8 arm
 *   func_02045808 0x02045808 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_020355D8(int);
extern void func_02045808(void *);
void func_021C6420(u8 *p) { func_020355D8(*(int *)p); func_02045808(*(void **)(p+0x58)); func_02045808(*(void **)(p+0x5c)); }
