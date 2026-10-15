/*
 * function: BSUBWAY_RECORD_LIST_ShowRecordDetails
 * address:  0x021B9FF0
 * packet:   pkt_ov069_021B9FF0
 * region:   ov069
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * note 2026-10-05 (wave P2 Q9b, pengy share): the record is addressed with the
 * struct subscript &tbl[idx] for the fields, while the memcpy source is written
 * as (char *)tbl + off with a separate int off = idx * 0x22. Written that way the
 * compiler keeps tbl in r6 and off in r7 and spills a, b, rec (declaration order
 * a, b, rec, name, off). Two spellings of one address, as a person would write.
 *
 * symbols:
 *   STRBUF_Create  0x020457B0  arm
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb
 *   WORDSET_SetSlotFromMsgE7  0x0201F048  thumb
 *   WORDSET_DeleteMsgdataF094  0x0201F094  thumb
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   STRBUF_SetStringN  0x02045994  arm
 *   PMSI_PARAM_ToString  0x0202435C  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct WordSet; struct U16Vec; struct Descriptor; struct CharBuf; struct Cfg; struct Strbuf;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void WORDSET_SetSlotNumber(struct WordSet *, u32, u32, u32, u32, u32);
extern void WORDSET_SetSlotFromMsgE7(struct WordSet *p, u32 i, u32 n);
extern void WORDSET_DeleteMsgdataF094(struct WordSet *p, u32 i, u32 a, u32 n);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void STRBUF_SetStringN(struct Strbuf *o, const u16 *src, u32 len);
extern void *PMSI_PARAM_ToString(void *slots, unsigned int heap);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern void BMP_WIN_MakeScreen(struct Cfg *);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *);
extern void func_02041B6C(u32);

struct Rec { u8 pad0[0x12]; u8 a; u8 b; u8 pad1[4]; u16 name[5]; };
void BSUBWAY_RECORD_LIST_ShowRecordDetails(char *p, struct Rec *tbl, int idx)
{
    u32 a;
    u32 b;
    struct Rec *rec;
    char *name;
    int off;
    struct U16Vec *vec;
    struct Descriptor *d;
    int n;
    off = idx * 0x22;
    rec = &tbl[idx];
    a = rec->a;
    b = rec->b;
    name = (char *)rec + 0x18;
    vec = STRBUF_Create(0x10, 0x80);
    WORDSET_SetSlotNumber(*(struct WordSet **)(p + 0xF8), 0, *(u32 *)(*(char **)(p + 0x154) + 4), 2, 0, 1);
    WORDSET_SetSlotNumber(*(struct WordSet **)(p + 0xF8), 1, *(u32 *)(*(char **)(p + 0x154) + 8), 3, 0, 1);
    WORDSET_SetSlotFromMsgE7(*(struct WordSet **)(p + 0xF8), 2, a);
    WORDSET_DeleteMsgdataF094(*(struct WordSet **)(p + 0xF8), 3, a, b);
    BMP_Clear(BMP_WIN_GetBmp(*(struct Descriptor **)(p + 0x3C)), 0);
    BMP_Clear(BMP_WIN_GetBmp(*(struct Descriptor **)(p + 0x40)), 0);
    BMP_Clear(BMP_WIN_GetBmp(*(struct Descriptor **)(p + 0x44)), 0);
    BMP_Clear(BMP_WIN_GetBmp(*(struct Descriptor **)(p + 0x4C)), 0);
    BMP_Clear(BMP_WIN_GetBmp(*(struct Descriptor **)(p + 0x54)), 0);
    if (idx < *(int *)(p + 0x164)) {
        void *ws;
        void *str;
        n = 8;
        STRBUF_SetStringN((struct Strbuf *)vec, (const u16 *)((char *)tbl + off), n);
        ws = *(void **)(p + 0xE8);
        PRINTSYS_PrintQueColor(ws, (u32)BMP_WIN_GetBmp(*(struct Descriptor **)(p + 0xC0)), 0, 0, (u32)vec, (u32)(*(void **)(p + 0xC)), 0x3DC0);
        *(u8 *)(p + 0xC4) = 1;
        WORDSET_CopyTaggedText(*(struct WordSet **)(p + 0xF8), *(void **)(p + 0xFC), *(void **)(p + n + 0xFC));
        ws = *(void **)(p + 0xE8);
        PRINTSYS_PrintQueColor(ws, (u32)BMP_WIN_GetBmp(*(struct Descriptor **)(p + 0xB0)), 0, 0, (u32)(*(void **)(p + 0xFC)), (u32)(*(void **)(p + 0xC)), 0x3DC0);
        *(u8 *)(p + 0xB4) = 1;
        WORDSET_CopyTaggedText(*(struct WordSet **)(p + 0xF8), *(void **)(p + 0xFC), *(void **)(p + 0x108));
        ws = *(void **)(p + 0xE8);
        PRINTSYS_PrintQueColor(ws, (u32)BMP_WIN_GetBmp(*(struct Descriptor **)(p + 0xB8)), 0, 0, (u32)(*(void **)(p + 0xFC)), (u32)(*(void **)(p + 0xC)), 0x3DC0);
        *(u8 *)(p + 0xBC) = 1;
        WORDSET_CopyTaggedText(*(struct WordSet **)(p + 0xF8), *(void **)(p + 0xFC), *(void **)(p + 0x110));
        ws = *(void **)(p + 0xE8);
        PRINTSYS_PrintQueColor(ws, (u32)BMP_WIN_GetBmp(*(struct Descriptor **)(p + 0xD0)), 0, 0, (u32)(*(void **)(p + 0xFC)), (u32)(*(void **)(p + 0xC)), 0x3DC0);
        *(u8 *)(p + 0xD4) = 1;
        WORDSET_CopyTaggedText(*(struct WordSet **)(p + 0xF8), *(void **)(p + 0xFC), *(void **)(p + 0x114));
        ws = *(void **)(p + 0xE8);
        PRINTSYS_PrintQueColor(ws, (u32)BMP_WIN_GetBmp(*(struct Descriptor **)(p + 0xD0)), 0, 0x10, (u32)(*(void **)(p + 0xFC)), (u32)(*(void **)(p + 0xC)), 0x3DC0);
        *(u8 *)(p + 0xD4) = 1;
        str = PMSI_PARAM_ToString((void *)name, 0x80);
        ws = *(void **)(p + 0xE8);
        PRINTSYS_PrintQueColor(ws, (u32)BMP_WIN_GetBmp(*(struct Descriptor **)(p + 0xE0)), 0, 0, (u32)str, (u32)(*(void **)(p + 0xC)), 0x3DC0);
        *(u8 *)(p + 0xE4) = 1;
        STRBUF_Delete((struct U16Vec *)str);
    } else {
        d = *(struct Descriptor **)(p + 0x44);
        BMP_WIN_TransferChars(d); BMP_WIN_MakeScreen((struct Cfg *)d); func_02041B6C(BMP_WIN_GetBgLayer(d));
        d = *(struct Descriptor **)(p + 0x4C);
        BMP_WIN_TransferChars(d); BMP_WIN_MakeScreen((struct Cfg *)d); func_02041B6C(BMP_WIN_GetBgLayer(d));
        d = *(struct Descriptor **)(p + 0x54);
        BMP_WIN_TransferChars(d); BMP_WIN_MakeScreen((struct Cfg *)d); func_02041B6C(BMP_WIN_GetBgLayer(d));
    }
    STRBUF_Delete(vec);
}
