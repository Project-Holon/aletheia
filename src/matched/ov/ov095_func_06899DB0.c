/*
 * function: func_06899DB0
 * address: 0x06899DB0
 * packet: pkt_ov095_06899DB0
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_06899DC8 0x06899DC8 thumb ov095
 */
typedef unsigned int u32;
extern int func_06899DC8(u32);
int func_06899DB0(unsigned char *p) { return func_06899DC8(*(u32 *)(p+0xb0)) == 0; }
