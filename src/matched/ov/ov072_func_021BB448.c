/*
 * function: TOWNMAP_GRH_PrintTextBoxMessage
 * address:  0x021BB448
 * packet:   pkt_ov072_021BB448
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   PRINTSYS_Print  0x0201C7A4  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 */
typedef unsigned int   u32;
typedef signed short   s16;

struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
typedef unsigned char  u8;
struct Cfg;
struct CharBuf;
struct MsgBank;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void PRINTSYS_Print(void *x, s16 y, s16 z, void *s, void *w);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_02041B6C(u32 bit);

void TOWNMAP_GRH_PrintTextBoxMessage(u32 *p, u32 a, int x, int y)
{
    u32 w;

    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p[0])), 0);
    MSGDATA_ReadString((struct MsgBank *)p[3], a, (void *)p[1]);
    PRINTSYS_Print((void *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p[0])), x, y, (void *)p[1], (void *)p[2]);
    w = p[0];
    BMP_WIN_TransferChars((struct Descriptor *)w);
    BMP_WIN_MakeScreen((struct Cfg *)w);
    func_02041B6C(BMP_WIN_GetBgLayer((struct Descriptor *)w));
}
