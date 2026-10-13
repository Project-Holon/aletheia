/*
 * function: OPTION_MENU_CreateLabelWindows
 * address:  0x021B9C04
 * packet:   pkt_ov068_021B9C04
 * region:   ov068
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The rounded width goes through a u8 local that is both stored to the
 * table row and passed on (the call reloading the field is 4 bytes longer).
 * func_0201D304 takes the string first and the font second.
 *
 * symbols:
 *   GF_FONT_Create  0x0201D7EC  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201D304  0x0201D304  thumb
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   PRINTSYS_Print  0x0201C7A4  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *   STRBUF_Delete  0x02045808  arm
 *   BMP_GetPixels  0x020437D4  arm
 *   func_02082A90  0x02082A90  arm
 *   BMP_WIN_GetWidth  0x02045738  arm
 *   PRINTSYS_PrintColor  0x0201C7D0  thumb
 *   MSGDATA_Delete  0x02045C04  arm
 *   GF_FONT_Delete  0x0201D83C  thumb
 *   gOptionMenuLabels     0x021BB820  data  ov068  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

typedef struct {
    u32 msg;
    u8 x;
    u8 y;
    u8 w;
    u8 h;
} Ent;

extern Ent gOptionMenuLabels[];

struct Bmp;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct GfFont;
struct MsgBank;
struct Rec;
struct StrObj;
struct U16Vec;
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void PRINTSYS_Print(void *x, s16 y, s16 z, void *s, void *w);
extern void PRINTSYS_PrintColor(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_02041B6C(u32 a);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void *BMP_GetPixels(const struct Bmp *bmp);
extern void func_02082A90(u32 a, u32 b, u32 n);
extern u8 BMP_WIN_GetWidth(struct Descriptor *p);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u32 GF_FONT_Delete(void *ptr);

void OPTION_MENU_CreateLabelWindows(u32 *p)
{
    u32 font;
    u32 msg;
    u32 str;
    u32 w;
    int i;
    int x;
    Ent *e;
    u8 wv;

    font = (u32)GF_FONT_Create(0x17, 0, 0, 0, 0x1c);
    msg = (u32)func_02045B38(0, 2, 0x1d, 0x1c);
    for (i = 0; i < 16; i++) {
        x = 0;
        switch (i) {
        case 0:
            x = 7;
            break;
        case 1:
            x = 4;
            break;
        case 2:
            x = 2;
            break;
        }
        e = &gOptionMenuLabels[i];
        str = (u32)func_02045EC0((struct MsgBank *)msg, gOptionMenuLabels[i].msg);
        wv = (x + func_0201D304((struct StrObj *)str, font, 0) + 7) >> 3;
        e->w = wv;
        p[i] = BMP_WIN_Create(1, e->x, e->y, wv, e->h, 0, 1);
        BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p[i])), 0);
        PRINTSYS_Print((void *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p[i])), x, 0, (void *)str, (void *)font);
        w = p[i];
        BMP_WIN_TransferChars((struct Descriptor *)w);
        BMP_WIN_MakeScreen((struct Cfg *)w);
        func_02041B6C(BMP_WIN_GetBgLayer((struct Descriptor *)w));
        STRBUF_Delete((struct U16Vec *)str);
    }
    w = *(u32 *)(p[22] + 0x14);
    func_02082A90(w, (u32)BMP_GetPixels((const struct Bmp *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p[16]))), 0x600);
    str = (u32)func_02045EC0((struct MsgBank *)msg, 0);
    x = BMP_WIN_GetWidth((struct Descriptor *)p[16]) * 4;
    x -= func_0201D304((struct StrObj *)str, font, 0) >> 1;
    PRINTSYS_PrintColor((void *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p[16])), x, 4, (void *)str, (void *)font, 0x3dc1);
    w = p[16];
    BMP_WIN_TransferChars((struct Descriptor *)w);
    BMP_WIN_MakeScreen((struct Cfg *)w);
    func_02041B6C(BMP_WIN_GetBgLayer((struct Descriptor *)w));
    STRBUF_Delete((struct U16Vec *)str);
    MSGDATA_Delete((struct Rec *)msg);
    GF_FONT_Delete((void *)font);
}
