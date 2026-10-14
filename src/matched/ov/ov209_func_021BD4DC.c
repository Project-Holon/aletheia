/*
 * function: ZUKAN_LIST_MakeWindowScreens
 * address: 0x021BD4DC
 * packet: pkt_ov209_021BD4DC
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Cfg; struct Descriptor;extern void BMP_WIN_MakeScreen(struct Cfg *);extern u8 BMP_WIN_GetBgLayer(struct Descriptor *);extern void func_02041B6C(u32);
void ZUKAN_LIST_MakeWindowScreens(void **p) {BMP_WIN_MakeScreen(*p);func_02041B6C(BMP_WIN_GetBgLayer(*p));}
