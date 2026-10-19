/*
 * function: FIELD_PLACE_NAME_SetupWindow
 * address:  0x021BC5E4
 * packet:   pkt_ov021_021BC5E4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLACE_NAME_TransferPalette  0x021BC6D0  thumb  ov021
 *   FIELD_PLACE_NAME_AllocBgChars  0x021BC6E8  thumb  ov021
 *   FIELD_PLACE_NAME_CreateBmpWin  0x021BD01C  thumb  ov021
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 *   BG_SYS_SetPriority  0x0204047C  arm
 *   func_02040588  0x02040588  arm
 *   func_0207D63C  0x0207D63C  arm
 */

extern void FIELD_PLACE_NAME_TransferPalette(int a);
extern void FIELD_PLACE_NAME_AllocBgChars(int a);
extern void FIELD_PLACE_NAME_CreateBmpWin(int a);
struct Descriptor;
extern void BMP_WIN_TransferChars(struct Descriptor *d);
struct Cfg;
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern unsigned char BMP_WIN_GetBgLayer(struct Descriptor *d);
extern void BG_SYS_PushTile(unsigned int index);
typedef unsigned int   u32;
extern void BG_SYS_SetPriority(int idx, unsigned short val);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0207D63C(int a, int b, int c, int d, int e);

void FIELD_PLACE_NAME_SetupWindow(int *p)
{
    int r4;

    FIELD_PLACE_NAME_TransferPalette((int)p);
    FIELD_PLACE_NAME_AllocBgChars((int)p);
    FIELD_PLACE_NAME_CreateBmpWin((int)p);
    r4 = p[9];
    BMP_WIN_TransferChars((struct Descriptor *)r4);
    BMP_WIN_MakeScreen((struct Cfg *)r4);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct Descriptor *)r4));
    BG_SYS_SetPriority(3, 1);
    func_02040588(3, 0);
    func_0207D63C(0x04000050, 8, 0x11, 0x10, 4);
}
