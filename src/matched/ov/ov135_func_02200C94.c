/*
 * function: func_02200C94
 * address: 0x02200C94
 * packet: pkt_ov135_02200C94
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0207D55C 0x0207D55C arm
 *   func_021FFD74 0x021FFD74 thumb ov135
 *   func_02200EC8 0x02200EC8 thumb ov135
 *   func_02200E94 0x02200E94 thumb ov135
 *   func_02200DB8 0x02200DB8 thumb ov135
 *   func_022000E4 0x022000E4 thumb ov135
 *   func_021F4EC8 0x021F4EC8 thumb ov135
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_0207D55C(u16 *);
extern void func_021FFD74(u8 *),func_02200EC8(u8 *),func_02200E94(u8 *),func_02200DB8(void),func_022000E4(u8 *),func_021F4EC8(u8 *);
int func_02200C94(u8 *p) { if(func_0207D55C((u16 *)0x0400106c)) func_021FFD74(p); func_02200EC8(p); func_02200E94(p); func_02200DB8(); func_022000E4(p); func_021F4EC8(p); return 0; }
