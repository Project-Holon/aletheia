/*
 * function: func_021F3AE0
 * address: 0x021F3AE0
 * packet: pkt_ov112_021F3AE0
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void CLACT_ExitSystem(void);
extern void BMP_WIN_Exit(void);
extern void func_0203F9B4(void);
void func_021F3AE0(void *a0) { CLACT_ExitSystem(); BMP_WIN_Exit(); func_0203F9B4(); }
