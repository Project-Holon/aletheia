/*
 * function: PSEL_ClearWin3
 * address: 0x021BB35C
 * packet: pkt_ov223_021BB35C
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Descriptor;struct Cfg;struct CharBuf;extern void *BMP_WIN_GetBmp(struct Descriptor *);extern void BMP_Clear(struct CharBuf *,u8);extern void BMP_WIN_TransferChars(struct Descriptor *);extern void BMP_WIN_MakeScreen(struct Cfg *);extern u8 BMP_WIN_GetBgLayer(struct Descriptor *);extern void func_02041B6C(u32);
void PSEL_ClearWin3(char *p) {struct Descriptor *d;u32 off;off=0x238;BMP_Clear(BMP_WIN_GetBmp(*(struct Descriptor **)(p+off)),0);d=*(struct Descriptor **)(p+off);BMP_WIN_TransferChars(d);BMP_WIN_MakeScreen((struct Cfg *)d);func_02041B6C(BMP_WIN_GetBgLayer(d));}
