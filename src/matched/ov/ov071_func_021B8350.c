/*
 * function: func_021B8350
 * address:  0x021B8350
 * packet:   pkt_ov071_021B8350
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BMP_MENUWORK_LoadChar  0x0201F554  thumb
 *   BMP_MENUWORK_GetPlttFileId  0x0201F548  thumb
 *   PALANM_LoadArcPaletteToSlotAt  0x020215EC  thumb
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_MENUWORK_DrawWindow  0x0201F73C  thumb
 */

typedef struct {
    char pad[0x3c];
    int f3c;
} W;

typedef unsigned int   u32;
typedef unsigned char  u8;
struct Descriptor;
typedef unsigned short u16;
struct Cfg;
struct CharBuf;
struct PalAnmSlot;
void func_021B8350(W *w, int *b)
{
    extern void BMP_MENUWORK_LoadChar(u32 a, u32 b, u32 c, u32 d);
    extern u8 BMP_MENUWORK_GetPlttFileId(int i);
    extern void PALANM_LoadArcPaletteToSlotAt(struct PalAnmSlot *slots, u32 arcId, u32 fileId, u32 tag, u32 idx, u32 count, u16 off, u16 srcOff);
    extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
    extern void *BMP_WIN_GetBmp(struct Descriptor *p);
    extern void BMP_Clear(struct CharBuf *buf, u8 value);
    extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
    extern void BMP_MENUWORK_DrawWindow(void *a0, int a1, int a2, int a3);

    BMP_MENUWORK_LoadChar(5, 1, 0, 0x61);
    PALANM_LoadArcPaletteToSlotAt((struct PalAnmSlot *)(*b), 5, BMP_MENUWORK_GetPlttFileId(0), 0x61, 1, 0x20, 0xb0, 0);
    w->f3c = BMP_WIN_Create(5, 1, 0x13, 0x1e, 4, 0xd, 1);
    BMP_Clear((struct CharBuf *)((int)BMP_WIN_GetBmp((struct Descriptor *)w->f3c)), 0xff);
    BMP_WIN_MakeScreen((struct Cfg *)w->f3c);
    BMP_MENUWORK_DrawWindow((void *)w->f3c, 0, 1, 0xb);
}
