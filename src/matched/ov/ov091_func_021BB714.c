/*
 * function: PLIST_MESSAGE_OpenWindow
 * address:  0x021BB714
 * packet:   pkt_ov091_021BB714
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_MENUWORK_DrawWindow  0x0201F73C  thumb
 *   PLIST_MESSAGE_RedrawWindow  0x021BBA28  thumb  ov091
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void BMP_MENUWORK_DrawWindow(void *a0, int a1, int a2, int a3);
extern void PLIST_MESSAGE_RedrawWindow(int a, int b);

void PLIST_MESSAGE_OpenWindow(void *a, u32 *s, u32 k)
{
    s[0] = k;
    switch (k) {
    case 0:
        s[1] = BMP_WIN_Create(0, 1, 0x15, 0x15, 2, 0xe, 1);
        break;
    case 1:
        s[1] = BMP_WIN_Create(0, 1, 0x15, 0x14, 2, 0xe, 1);
        break;
    case 2:
        s[1] = BMP_WIN_Create(0, 2, 0x13, 0xe, 4, 0xe, 1);
        break;
    case 3:
        s[1] = BMP_WIN_Create(0, 2, 0x13, 0x1c, 4, 0xe, 1);
        break;
    }
    BMP_MENUWORK_DrawWindow((void *)s[1], 1, 1, 0xc);
    PLIST_MESSAGE_RedrawWindow((int)a, (int)s);
}
