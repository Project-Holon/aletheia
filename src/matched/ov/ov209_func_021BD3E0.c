/*
 * function: func_021BD3E0
 * address: 0x021BD3E0
 * packet: pkt_ov209_021BD3E0
 * region: ov209
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
typedef unsigned short u16;
typedef unsigned int u32;
struct Descriptor;
extern u32 func_020452E8(struct Descriptor *d);
extern void BMP_WIN_Exit(void);
void func_021BD3E0(char *p) { u32 i;for(i=0;i<3;i++)func_020452E8(*(struct Descriptor **)((u32)p+i*8+32));BMP_WIN_Exit(); }
