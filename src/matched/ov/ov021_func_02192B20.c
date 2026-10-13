/*
 * function: FIELD_MSGBG_CreateSysFrameWindow
 * address:  0x02192B20
 * packet:   pkt_ov021_02192B20
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
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   FIELD_MSGBG_DrawSysWindowFrame  0x02192A04  thumb  ov021
 */

typedef unsigned int u32;

extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, unsigned char c, unsigned char d, unsigned char slot);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
typedef unsigned char  u8;
struct Cfg;
struct CharBuf;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void BMP_WIN_TransferChars(struct Descriptor *a);
extern void FIELD_MSGBG_DrawSysWindowFrame(u32 a);

u32 FIELD_MSGBG_CreateSysFrameWindow(u8 a, u8 b, u8 c, u8 d, u32 e)
{
    u32 w;

    w = BMP_WIN_Create(2, a, b, c, d, 0xE, 1);
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)w)), 0xFF);
    BMP_WIN_MakeScreen((struct Cfg *)w);
    BMP_WIN_TransferChars((struct Descriptor *)w);
    FIELD_MSGBG_DrawSysWindowFrame(w);
    return w;
}
