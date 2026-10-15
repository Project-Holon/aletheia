/*
 * function: STARTMENU_LogoInit
 * address:  0x021B9A1C
 * packet:   pkt_ov088_021B9A1C
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * d_021BD450 carries no ov088 token: with it the hint is contested (another
 * overlay starts an object there); without it it resolves as sole-ref/data.
 *
 * symbols:
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm
 *   ARC_UTIL_UploadBgCharFromArchive  0x02049624  arm
 *   func_0204989C  0x0204989C  arm
 *   func_02049B40  0x02049B40  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 *   func_02040588  0x02040588  arm
 *   BG_SYS_Init  0x02040C14  arm
 *   BG_SYS_SetTileEntry  0x02041300  arm
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   GF_FONT_Create  0x0201D7EC  thumb
 *   PRINTSYS_QUE_Create  0x0201C440  thumb
 *   func_02045B38  0x02045B38  arm
 *   STRBUF_Create  0x020457B0  arm
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   func_0201D304  0x0201D304  thumb
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb
 *   d_021BD470     0x021BD470  data  ov088  a4
 *   d_021BD490     0x021BD490  data  ov088  a4
 *   d_021BD430     0x021BD430  data  ov088  a4
 *   d_021BD450     0x021BD450  data  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

typedef struct {
    u32 win;
    u32 bmp;
    u32 win2;
    u8  fC;
    u8  padD[3];
    u32 f10;
    u32 font;
    u32 print;
    u32 f1C;
    u32 msg;
    u32 buf;
} Work;

typedef struct BgTemplate {
    u32 w[8];
} BgTemplate;

extern const BgTemplate d_021BD470;
extern const BgTemplate d_021BD490;
extern const BgTemplate d_021BD430;
extern const BgTemplate d_021BD450;

extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void ARC_UTIL_UploadBgCharFromArchive(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void func_0204989C(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern void BG_SYS_PushTile(u32 layer);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void BG_SYS_Init(u32 layer, u32 value, u32 count, u32 index);
extern void BG_SYS_SetTileEntry(u32 layer, int a1, int a2, int a3, u8 a4, u8 a5, u8 a6);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
struct Cfg;
struct CharBuf;
struct GfFont;
struct MsgBank;
struct StrObj;
struct U16Vec;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 PRINTSYS_QUE_Create(void *p);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);

void STARTMENU_LogoInit(Work *p, u32 heap)
{
    int w;

    BG_SYS_InitBgLayer(3, &d_021BD470, 0);
    BG_SYS_InitBgLayer(5, &d_021BD490, 0);
    BG_SYS_InitBgLayer(7, &d_021BD430, 0);
    BG_SYS_InitBgLayer(6, &d_021BD450, 0);
    ARC_UTIL_UploadBgCharFromArchive(0x1A, 9, 3, 0, 0, 1, heap);
    func_0204989C(0x1A, 10, 3, 0, 0, 1, heap);
    func_02049B40(0x1A, 8, 0, 0, 0, heap);
    BG_SYS_PushTile(3);
    func_02040588(3, 1);
    ARC_UTIL_UploadBgCharFromArchive(0x1A, 0, 7, 0, 0x8000, 1, heap);
    func_0204989C(0x1A, 1, 7, 0, 0, 1, heap);
    func_02049B40(0x1A, 2, 4, 0, 0, heap);
    BG_SYS_PushTile(7);
    func_02040588(7, 1);
    func_0204989C(0x1A, 3, 6, 0, 0, 1, heap);
    func_02040588(6, 1);
    BG_SYS_Init(5, 0, 1, 0);
    BG_SYS_SetTileEntry(5, 0, 0, 0, 0x20, 0x20, 0x11);
    p->win = BMP_WIN_Create(5, 0, 0x13, 0x20, 2, 0xA, 0);
    p->bmp = (u32)BMP_WIN_GetBmp((struct Descriptor *)p->win);
    BMP_Clear((struct CharBuf *)p->bmp, 0);
    BMP_WIN_MakeScreen((struct Cfg *)p->win);
    BMP_WIN_TransferChars((struct Descriptor *)p->win);
    p->fC = 0;
    p->win2 = p->win;
    BG_SYS_PushTile(5);
    p->font = (u32)GF_FONT_Create(0x17, 0, 0, 0, heap);
    p->print = PRINTSYS_QUE_Create((void *)heap);
    p->msg = (u32)func_02045B38(0, 2, 0xB5, heap);
    p->buf = (u32)STRBUF_Create(0x40, heap);
    MSGDATA_ReadString((struct MsgBank *)p->msg, 1, (void *)p->buf);
    w = func_0201D304((struct StrObj *)p->buf, p->font, 0);
    PRINTSYS_PrintQueColor((void *)p->print, p->bmp, (s16)(0x80 - w / 2), (s16)0, p->buf, p->font, 0x440);
    p->f10 = 1;
}
