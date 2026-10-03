/*
 * function: func_02202000
 * address: 0x02202000
 * packet: pkt_ov135_02202000
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02201F18 0x02201F18 thumb ov135
 *   func_021F4E98 0x021F4E98 thumb ov135
 *   func_021F4EC0 0x021F4EC0 thumb ov135
 *   func_021F4FC4 0x021F4FC4 thumb ov135
 *   func_021FFBC8 0x021FFBC8 thumb ov135
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_02201F18(u8 *p);
extern void func_021F4E98(u8 *,u32,u32),func_021F4EC0(u8 *,u32,u32),func_021F4FC4(u8 *),func_021FFBC8(u8 *);
int func_02202000(u8 *p) { func_02201F18(p); func_021F4E98(p,41,40); func_021F4EC0(p,1,0); func_021F4FC4(p); if(*(int *)(p+208)>0) func_021FFBC8(p); return 2; }
