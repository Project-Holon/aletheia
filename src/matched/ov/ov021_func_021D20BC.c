/*
 * function: EVENT_PERAP_RECORD_SetupWindow
 * address:  0x021D20BC
 * packet:   pkt_ov021_021D20BC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201F548  0x0201F548  thumb
 *   ARC_UTIL_UploadPaletteFromArchive  0x02049B90  arm
 *   BMP_WIN_Create  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   EVENT_PERAP_RECORD_CreatePokeIcon  0x021D1F78  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

typedef unsigned short u16;
typedef unsigned char  u8;
extern u8 func_0201F548(int i);
extern void ARC_UTIL_UploadPaletteFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
struct Cfg;
struct CharBuf;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void EVENT_PERAP_RECORD_CreatePokeIcon(u32 *w);

void EVENT_PERAP_RECORD_SetupWindow(u32 *w)
{
    ARC_UTIL_UploadPaletteFromArchive(5, func_0201F548(0), 0, 0, 0, 0x20, 0x15);
    w[0x30 / 4] = BMP_WIN_Create(1, 10, 3, 12, 12, 0, 1);
    BMP_Clear((struct CharBuf *)((u32)func_02045770((struct Descriptor *)w[0x30 / 4])), 0x11);
    BMP_WIN_TransferChars((struct Descriptor *)w[0x30 / 4]);
    BMP_WIN_MakeScreen((struct Cfg *)w[0x30 / 4]);
    func_0201F73C((void *)w[0x30 / 4], 1, 1, 0);
    EVENT_PERAP_RECORD_CreatePokeIcon(w);
}
