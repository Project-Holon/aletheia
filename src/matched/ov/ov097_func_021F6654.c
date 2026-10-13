/*
 * function: func_021F6654
 * address: 0x021F6654
 * packet: pkt_ov097_021F6654
 * region: ov097
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F69FC 0x021F69FC thumb ov097
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   func_021F75E0 0x021F75E0 thumb ov097
 *   func_021F6F3C 0x021F6F3C thumb ov097
 *   func_021F6B1C 0x021F6B1C thumb ov097
 *   func_021F69C0 0x021F69C0 thumb ov097
 *   func_021F68E0 0x021F68E0 thumb ov097
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021F69FC(u8 *);
extern void BG_SYS_SetMainPlaneVisible(u32,u32);
extern void func_021F75E0(int *);
extern void func_021F6F3C(char *p);
extern void func_021F6B1C(u8 *);
extern void func_021F69C0(u8 *);
extern void func_021F68E0(void);
int func_021F6654(u8 *p) { func_021F69FC(p); BG_SYS_SetMainPlaneVisible(0x17,0); func_021F75E0((int *)p); func_021F6F3C((char *)p); func_021F6B1C(p); func_021F69C0(p); func_021F68E0(); return 5; }
