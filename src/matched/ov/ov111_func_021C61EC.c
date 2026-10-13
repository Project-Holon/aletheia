/*
 * function: func_021C61EC
 * address:  0x021C61EC
 * packet:   pkt_ov111_021C61EC
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * closed:   blocking arm9 callees labelled and matched by seeds_3 (2026-09-28)
 *
 * symbols:
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   PRINTSYS_Print  0x0201C7A4  thumb
 *   func_0201D304  0x0201D304  thumb
 *   BMP_Clear  0x02043B5C  arm
 *   func_02045EC0  0x02045EC0  arm
 *   STRBUF_Delete  0x02045808  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_02045B38  0x02045B38  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   GAME_DATA_GetSaveBlock21  0x02012F5C  thumb
 *   func_020089F4  0x020089F4  thumb
 *   func_02025C9C  0x02025C9C  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

typedef struct {
    u8 pad0[4];
    void *f4;
} Sub24;

typedef struct {
    u16 heap;
    u8 pad2[2];
    void *bg[7];
    u8 pad20[4];
    Sub24 *f24;
    u8 pad28[0x31FC - 0x28];
    void *f31FC;
    void *f3200;
    u8 pad3204[0x3234 - 0x3204];
    void *f3234;
} Work;

struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct Rec;
struct Sub020089A8Obj;
struct U16Vec;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void PRINTSYS_Print(void *x, s16 y, s16 z, void *s, void *w);
struct StrObj;
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void func_02041B6C(u32 bit);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void *GAME_DATA_GetSaveBlock21(void **h);
extern u8 func_020089F4(const struct Sub020089A8Obj *obj);
extern u32 func_02025C9C(u32 x);

void func_021C61EC(Work *p, int k, int flush)
{
    void *bank;
    void *str;
    u32 w;

    bank = func_02045B38(0, 2, 0xBF, p->heap);
    if (func_020089F4(GAME_DATA_GetSaveBlock21(p->f24->f4))) {
        str = func_02045EC0(bank, func_02025C9C(k));
    } else {
        str = func_02045EC0(bank, 0);
    }
    w = func_0201D304(str, (u32)p->f31FC, 0);
    BMP_Clear(BMP_WIN_GetBmp(p->bg[1]), 0);
    PRINTSYS_Print(BMP_WIN_GetBmp(p->bg[1]), 0x80 - w, 0, str, p->f31FC);
    STRBUF_Delete(str);
    MSGDATA_Delete(bank);
    if (flush) {
        BMP_WIN_MakeScreen(p->bg[1]);
        BMP_WIN_TransferChars(p->bg[1]);
        func_02041B6C(7);
    }
}
