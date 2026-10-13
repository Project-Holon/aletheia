/*
 * function: WIFICLUB_PrintTalkMessage
 * address:  0x021BA978
 * packet:   pkt_ov099_021BA978
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012FFC  0x02012FFC  thumb
 *   WIFICLUB_DeleteTimeIcon  0x021BA8D4  thumb  ov099
 *   WIFICLUB_DeleteWindow  0x021BA8BC  thumb  ov099
 *   PRINTSYS_QUE_IsFinished  0x0201C6B4  thumb
 *   PRINTSYS_QUE_Clear  0x0201C6EC  thumb
 *   PRINTSYS_PrintStreamDelete  0x0201CE48  thumb
 *   BMP_WIN_Create  0x020450F0  arm
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   func_0201F250  0x0201F250  thumb
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   PRINTSYS_Print  0x0201C7A4  thumb
 *   PRINTSYS_PrintStream  0x0201CCE4  thumb
 *   func_02028470  0x02028470  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   func_02041B6C  0x02041B6C  arm
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short   s16;
typedef unsigned char  u8;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct PrintSys;
struct Rec3;
struct WordSet;
extern signed char func_02012FFC(void);
extern void WIFICLUB_DeleteTimeIcon(char *p);
extern int WIFICLUB_DeleteWindow(void *p);
extern u32 PRINTSYS_QUE_IsFinished(const struct PrintSys *p);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void PRINTSYS_Print(void *x, s16 y, s16 z, void *s, void *w);
extern u32 PRINTSYS_PrintStream(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 i, u32 j);
extern void func_02028470(u8 *p, u32 v);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void func_02041B6C(u32 a);

void WIFICLUB_PrintTalkMessage(char *p, int a1, int a2, int a3)
{
    int k, e;
    func_02012FFC();
    WIFICLUB_DeleteTimeIcon(p);
    *(u32 *)(p + 0x190) = (u32)WIFICLUB_DeleteWindow((void *)(*(u32 *)(p + 0x190)));
    if ((int)PRINTSYS_QUE_IsFinished((const struct PrintSys *)(*(u32 *)(p + 0x1B8))) == 0)
        PRINTSYS_QUE_Clear((struct PrintSys *)(*(u32 *)(p + 0x1B8)));
    if (*(u32 *)(p + 0x1BC) != 0) {
        PRINTSYS_PrintStreamDelete((struct Rec3 *)(*(u32 *)(p + 0x1BC)));
        *(u32 *)(p + 0x1BC) = 0;
    }
    *(u32 *)(p + 0x190) = BMP_WIN_Create(2, 2, 0x13, 0x1B, (u32)4, (u32)0xF, (u32)1);
    if (a2)
        MSGDATA_ReadString((struct MsgBank *)(*(u32 *)(p + 0xE4)), a1, (void *)(*(u32 *)(p + 0xF0)));
    else
        MSGDATA_ReadString((struct MsgBank *)(*(u32 *)(p + 0xE0)), a1, (void *)(*(u32 *)(p + 0xF0)));
    func_0201F250((struct WordSet *)(*(u32 *)(p + 0xDC)), (void *)(*(u32 *)(p + 0xF4)), (void *)(*(u32 *)(p + 0xF0)));
    k = 0xFF;
    BMP_Clear(BMP_WIN_GetBmp((struct Descriptor *)(*(u32 *)(p + 0x190))), (u32)k);
    e = 0xE;
    func_0201F73C((void *)(*(u32 *)(p + 0x190)), (u32)1, (u16)(*(u32 *)(p + 0x1334)), (u32)e);
    if (a3 == 0) {
        PRINTSYS_Print(BMP_WIN_GetBmp((struct Descriptor *)(*(u32 *)(p + 0x190))), (u32)0, (u32)0, (void *)(*(u32 *)(p + 0xF4)), (void *)(*(u32 *)(p + 0xE8)));
    } else {
        u32 t = func_02012FFC();
        *(u32 *)(p + (k + 0xBD)) = PRINTSYS_PrintStream(*(u32 *)(p + 0x190), 0, 0, *(u32 *)(p + 0xF4), *(u32 *)(p + 0xE8), t, *(u32 *)(p + e * 0x20), 2, 0x21, 0xF);
        func_02028470((u8 *)(p + 0x26C), 2);
    }
    BMP_WIN_TransferChars((struct Descriptor *)(*(u32 *)(p + 0x190)));
    BMP_WIN_MakeScreen((struct Cfg *)(*(u32 *)(p + 0x190)));
    func_02041B6C(2);
}
