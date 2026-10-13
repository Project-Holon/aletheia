/*
 * function: func_021E6718
 * address: 0x021E6718
 * packet: pkt_ov177_021E6718
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021E8D36 0x021E8D36 data a1
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb  arm9
 *   BMP_Clear  0x02043B5C  arm  arm9
 *   BMP_WIN_Create  0x020450F0  arm  arm9
 *   BMP_WIN_TransferChars  0x02045334  arm  arm9
 *   BMP_WIN_MakeScreen  0x02045374  arm  arm9
 *   STRBUF_Create  0x020457B0  arm  arm9
 *   STRBUF_Delete  0x02045808  arm  arm9
 *   MSGDATA_ReadString  0x02045CAC  arm  arm9
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef struct { void *win; u8 shown; u8 pad[3]; } Slot;
typedef struct {
    unsigned count;      /* 0x00 */
    void *wins[30];      /* 0x04 */
    Slot slots[11];      /* 0x7c */
} Work;
typedef struct {
    unsigned f0;
    u16 h4;
    u16 pad6;
    unsigned f8;
    unsigned fC;
    u16 h10;
    u16 h12;
} Info;
typedef struct { u8 a, b, c, d; } WinDef;
typedef struct { u16 heap; } HeapArg;
extern const WinDef d_021E8D36[];
extern unsigned int BMP_WIN_Create(unsigned int layer, unsigned int a, unsigned int b, unsigned int tiles, u8 c, u8 d, u8 slot);
typedef unsigned int   u32;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern void *func_02045770(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern void *STRBUF_Create(unsigned, u16);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void PRINTSYS_PrintQueColor(void *, void *, s16, s16, void *, int, int);
extern void STRBUF_Delete(struct U16Vec *vec);
void func_021E6718(Work *w, unsigned a1, const Info *info, void *a3, int a4, void *a5, void *a6, void *a7, int a8, HeapArg h)
{
    unsigned i;
    void *s1, *s2;
    int j;
    int draw;
    u16 color;
    w->count = 11;
    for (i = 0; i < w->count; i++) {
        void *win;
        w->wins[i] = (void *)BMP_WIN_Create(5, d_021E8D36[i].a, d_021E8D36[i].b, d_021E8D36[i].c, d_021E8D36[i].d, 0xf, 1);
        BMP_Clear(func_02045770(w->wins[i]), 0);
        win = w->wins[i];
        BMP_WIN_TransferChars(win);
        BMP_WIN_MakeScreen(win);
        func_020409B4(func_02045730(win));
        if (w->wins[i] != 0) {
            w->slots[i].win = w->wins[i];
            w->slots[i].shown = 0;
        }
    }
    s1 = STRBUF_Create(0x80, h.heap);
    s2 = STRBUF_Create(0x80, h.heap);
    for (j = 0; j < 11; j++) {
        color = (a8 == 1) ? 0x3c40 : 0x440;
        draw = 1;
        switch (j) {
        case 0:
            MSGDATA_ReadString(a6, a1, s2);
            color = 0x3c40;
            break;
        case 1:
            MSGDATA_ReadString(a6, info->f0 + 2, s2);
            color = 0x3c40;
            break;
        case 2:
            MSGDATA_ReadString(a6, 7, s1);
            func_0201F02C(a7, 0, a3);
            func_0201F250(a7, s2, s1);
            color = 0x3c40;
            break;
        case 3:
            if (a1)
                MSGDATA_ReadString(a6, 8, s2);
            else
                draw = 0;
            break;
        case 4:
            if (a1) {
                MSGDATA_ReadString(a6, 9, s1);
                func_0201EFA4(a7, 0, info->h4, 4, 1, 1);
                func_0201F250(a7, s2, s1);
            } else {
                draw = 0;
            }
            break;
        case 5:
            MSGDATA_ReadString(a6, 10, s2);
            break;
        case 6:
            MSGDATA_ReadString(a6, 11, s1);
            func_0201EFA4(a7, 0, info->fC, 6, 1, 1);
            func_0201F250(a7, s2, s1);
            break;
        case 7:
            MSGDATA_ReadString(a6, 12, s2);
            break;
        case 8:
            MSGDATA_ReadString(a6, 13, s1);
            func_0201EFA4(a7, 0, info->h10, 5, 1, 1);
            func_0201F250(a7, s2, s1);
            break;
        case 9:
            MSGDATA_ReadString(a6, 14, s2);
            break;
        case 10:
            MSGDATA_ReadString(a6, 15, s1);
            func_0201EFA4(a7, 0, info->h12, 5, 1, 1);
            func_0201F250(a7, s2, s1);
            break;
        }
        if (draw) {
            PRINTSYS_PrintQueColor(a5, func_02045770(w->slots[j].win), 0, 0, s2, a4, color);
            w->slots[j].shown = 1;
        }
    }
    STRBUF_Delete(s1);
    STRBUF_Delete(s2);
}
