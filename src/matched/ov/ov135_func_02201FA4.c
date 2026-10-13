/*
 * function: func_02201FA4
 * address: 0x02201FA4
 * packet: pkt_ov135_02201FA4
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02201F18 0x02201F18 thumb ov135
 *   DPW_TR_IsAsyncEnd 0x021C866C arm ov114
 *   func_021F4E98 0x021F4E98 thumb ov135
 *   func_021F4EC0 0x021F4EC0 thumb ov135
 *   func_021F4FC4 0x021F4FC4 thumb ov135
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_02201F18(u8 *p);
extern int DPW_TR_IsAsyncEnd(void);
extern void func_021F4E98(u8 *,u32,u32),func_021F4EC0(u8 *,u32,u32),func_021F4FC4(u8 *);
int func_02201FA4(u8 *p) { func_02201F18(p); if(DPW_TR_IsAsyncEnd()) func_021F4E98(p,41,48); else func_021F4E98(p,41,46); func_021F4EC0(p,0,21); func_021F4FC4(p); return 2; }
