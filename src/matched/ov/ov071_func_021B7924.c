/*
 * function: MONOLITH_TOOL_SLOT_SELECT_InitMsgWindow
 * address:  0x021B7924
 * packet:   pkt_ov071_021B7924
 * region:   ov071
 * compiler: dsi/1.1p1
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

typedef unsigned int u32;

extern void BMP_MENUWORK_LoadChar(u32 a, u32 b, u32 c, u32 d);
typedef unsigned short u16;
typedef unsigned char  u8;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct PalAnmSlot;
extern u8 BMP_MENUWORK_GetPlttFileId(int i);
extern void PALANM_LoadArcPaletteToSlotAt(struct PalAnmSlot *slots, u32 arcId, u32 fileId, u32 tag, u32 idx, u32 count, u16 off, u16 srcOff);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void BMP_MENUWORK_DrawWindow(void *a0, int a1, int a2, int a3);

void MONOLITH_TOOL_SLOT_SELECT_InitMsgWindow(void **p, void **q)
{
    BMP_MENUWORK_LoadChar(5, 1, 0, 0x61);
    PALANM_LoadArcPaletteToSlotAt(q[0], 5, BMP_MENUWORK_GetPlttFileId(0), 0x61, 1, 0x20, 0xb0, 0);
    p[0] = (void *)BMP_WIN_Create(5, 1, 0x13, 0x1e, 4, 0xd, 1);
    BMP_Clear(BMP_WIN_GetBmp(p[0]), 0xff);
    BMP_WIN_MakeScreen(p[0]);
    BMP_MENUWORK_DrawWindow(p[0], 0, 1, 0xb);
}
