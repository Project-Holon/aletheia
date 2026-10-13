/*
 * function: func_021F6B1C
 * address: 0x021F6B1C
 * packet: pkt_ov097_021F6B1C
 * region: ov097
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020452E8 0x020452E8 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Descriptor;
extern u32 func_020452E8(struct Descriptor *d);
extern void BMP_WIN_Exit(void);
void func_021F6B1C(u8 *p) { u32 i; for(i=0; i<6; i++) { func_020452E8(*(void **)((u32)p+i*8+0x20)); } BMP_WIN_Exit(); }
