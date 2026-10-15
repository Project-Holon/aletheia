/*
 * function: MB_UTIL_MSG_PrintStream
 * address:  0x021F1704
 * packet:   pkt_ov107_021F1704
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   PRINTSYS_PrintStreamDelete  0x0201CE48  thumb
 *   TIME_ICON_Delete  0x0202F038  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   func_02045EC0  0x02045EC0  arm
 *   STRBUF_Create  0x020457B0  arm
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   PRINTSYS_PrintStream  0x0201CCE4  thumb
 *   TALKMSGWIN_DrawWindowFrame  0x02194A24  thumb
 *   BMP_MENUWORK_DrawWindow  0x0201F73C  thumb
 *   PRINTSYS_CTRL_Init  0x02028470  thumb
 */

typedef struct {
    unsigned short f00;
    unsigned char f02;
    unsigned char f03;
    int f04;
    int f08;
    void *f0C;
    void *f10;
    void *f14;
    void *f18;
    void *f1C;
    void *f20;
    void *f24;
    unsigned char f28[8];
    void *f30;
    int f34;
    int f38;
    unsigned char pad3C[0x18];
    void *f54;
    int f58;
    void *f5C;
} Ov107Ctx;

typedef unsigned int   u32;
typedef unsigned char  u8;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct Rec3;
struct U16Vec;
struct WordSet;
void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
void TIME_ICON_Delete(u8 *p);
void STRBUF_Delete(struct U16Vec *vec);
void *BMP_WIN_GetBmp(struct Descriptor *p);
void BMP_Clear(struct CharBuf *buf, u8 value);
void *func_02045EC0(struct MsgBank *bank, u32 index);
struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
int TALKMSGWIN_DrawWindowFrame(void *, void *, int);
void BMP_MENUWORK_DrawWindow(void *, int, int, int);
void *PRINTSYS_PrintStream(void *, int, int, void *, void *, int, void *, int, int, int);
void PRINTSYS_CTRL_Init(u8 *p, u32 v);

void MB_UTIL_MSG_PrintStream(Ov107Ctx *p, int a, int b)
{
    void *s;

    if (p->f18 != 0) {
        PRINTSYS_PrintStreamDelete(p->f18);
        p->f18 = 0;
    }
    if (p->f5C != 0) {
        TIME_ICON_Delete(p->f5C);
        p->f5C = 0;
    }
    p->f38 = 0;
    p->f58 = 0;
    if (p->f20 != 0) {
        STRBUF_Delete(p->f20);
        p->f20 = 0;
    }
    BMP_Clear(BMP_WIN_GetBmp(p->f10), 0xF);
    p->f20 = func_02045EC0(p->f1C, a);
    if (p->f24 != 0) {
        s = STRBUF_Create(0x17B, p->f00);
        WORDSET_CopyTaggedText(p->f24, s, p->f20);
        STRBUF_Delete(p->f20);
        p->f20 = s;
    }
    p->f18 = PRINTSYS_PrintStream(p->f10, 0, 0, p->f20, p->f14, b, p->f0C, 2, p->f00, 0xF);
    if (p->f04 == 8) {
        TALKMSGWIN_DrawWindowFrame(p->f54, p->f10, 0);
    } else {
        BMP_MENUWORK_DrawWindow(p->f10, 1, 1, 0xD);
    }
    if (p->f08 == 1) {
        PRINTSYS_CTRL_Init(p->f28, 6);
    } else {
        PRINTSYS_CTRL_Init(p->f28, 4);
    }
}
