/*
 * function: B_APP_TOOL_ShowWindow
 * address: 0x0220B07C
 * packet: pkt_ov196_0220B07C
 * region: ov196
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * EXACT* tail: two zero alignment bytes after the function.
 * symbols:
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BG_SYS_MarkTileDirty 0x02041B6C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct Descriptor;
struct Cfg;
extern void BMP_WIN_MakeScreen(struct Cfg *);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *);
extern void BG_SYS_MarkTileDirty(u32);
void B_APP_TOOL_ShowWindow(void **p) { BMP_WIN_MakeScreen((struct Cfg *)*p); BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer((struct Descriptor *)*p)); }
