/*
 * function: func_021D4590
 * address: 0x021D4590
 * packet: pkt_ov122_021D4590
 * region: ov122
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   func_0201F7A8 0x0201F7A8 thumb
 *   BMP_WIN_Delete 0x020452E8 arm
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Descriptor;
extern void BMP_WIN_ClearScreen(struct Descriptor *d);extern void func_0201F7A8(void *,u32);extern void BMP_WIN_Delete(void *);extern void func_02041B6C(u32);
void func_021D4590(u32 i,u32 p) {if(*(void **)(p+0x10+i*4)) {BMP_WIN_ClearScreen(*(void **)(p+0x10+i*4));func_0201F7A8(*(void **)(p+0x10+i*4),2);BMP_WIN_Delete(*(void **)(p+0x10+i*4));}*(void **)(p+0x10+i*4)=0;func_02041B6C(5);}
