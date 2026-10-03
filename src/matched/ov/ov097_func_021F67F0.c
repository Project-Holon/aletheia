/*
 * function: func_021F67F0
 * address: 0x021F67F0
 * packet: pkt_ov097_021F67F0
 * region: ov097
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte zero alignment padding.
 * symbols:
 *   func_0202208C 0x0202208C thumb
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_0202208C(void *, u32, u32, u32, u32, u32, u32);
int func_021F67F0(u8 *p, int value) { func_0202208C(0,0,0,0,6,1,0x71); *(int *)(p+0x118)=value; return 2; }
