/*
 * function: func_021D593C
 * address: 0x021D593C
 * packet: pkt_ov120_021D593C
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D6A9C 0x021D6A9C thumb ov120
 *   func_021D6988 0x021D6988 thumb ov120
 *   func_021B64D0 0x021B64D0 thumb ov067
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021D6A9C(u8 *p, u32 n); extern u8 *func_021D6988(void *); extern void func_021B64D0(u8 *,u32); extern void func_020061E4(int);
int func_021D593C(u8 *p,int n) { if (func_021D6A9C(*(void **)(p+60),n)) { func_021B64D0(func_021D6988(*(void **)(p+60)),0); func_020061E4(1356); return n; } return 9; }
