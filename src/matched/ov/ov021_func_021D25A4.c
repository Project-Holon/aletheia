/*
 * function: SCRCMD_POKE_ICON_InitWindow
 * address:  0x021D25A4
 * packet:   pkt_ov021_021D25A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_MENUWORK_DrawWindow  0x0201F73C  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

typedef unsigned char  u8;
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
struct Cfg;
struct CharBuf;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void BMP_MENUWORK_DrawWindow(void *a0, int a1, int a2, int a3);

void SCRCMD_POKE_ICON_InitWindow(u32 *p)
{
    p[0] = BMP_WIN_Create(1, 10, 3, 12, 12, 13, 1);
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p[0])), 17);
    BMP_WIN_TransferChars((struct Descriptor *)p[0]);
    BMP_WIN_MakeScreen((struct Cfg *)p[0]);
    BMP_MENUWORK_DrawWindow((void *)p[0], 1, 1, 13);
}
