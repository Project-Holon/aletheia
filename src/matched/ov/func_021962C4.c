/*
 * function: IRCBATTLEMENU_ClearMessageWindow
 * address:  0x021962C4
 * packet:   pkt_021962C4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   TIME_ICON_Delete  0x0202F038  thumb
 *   BMP_MENUWORK_DrawWindowBorder  0x0201F7A8  thumb
 *   BMP_WIN_ClearScreen  0x020456F8  arm
 *   func_02041B6C  0x02041B6C  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct Descriptor;
extern void BMP_MENUWORK_DrawWindowBorder(void *desc, u32 kind);
extern void TIME_ICON_Delete(u8 *p);
extern u32 func_02041B6C(u32);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);

int IRCBATTLEMENU_ClearMessageWindow(u32 a)
{
if (*(u32 *)((u8 *)(a) + ((186 << 2))) != 0) {
    TIME_ICON_Delete((u8 *)(*(u32 *)((u8 *)(a) + ((186 << 2)))));
    *(u32 *)((u8 *)(a) + ((186 << 2))) = 0;
}
BMP_MENUWORK_DrawWindowBorder((void *)(*(u32 *)((u8 *)(a) + ((43 << 4)))), 2);
BMP_WIN_ClearScreen((struct Descriptor *)(*(u32 *)((u8 *)(a) + ((43 << 4)))));
return func_02041B6C(5);
}

