/*
 * function: WORLDTRADE_ADAPTER_PrintNumber
 * address:  0x02202A50
 * packet:   pkt_02202A50
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   STRBUF_Create  0x020457B0  arm
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   func_02034714  0x02034714  arm
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    void *win;
    u8 shown;
    u8 pad5[3];
} Slot;

typedef struct {
    void *font;
    void *print;
    void *words;
    void *bank;
    Slot slot[8];
    u32 used[8];
    u16 heap;
} Ctx;

struct Descriptor;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void func_02034714(const char *expr, u32 line, const char *file);

void WORLDTRADE_ADAPTER_PrintNumber(Ctx *ctx, u32 num, u32 digits, u32 mode, void *win, int x, int y)
{
    void *str;
    void *fmt;
    void *print;
    int i;

    str = STRBUF_Create(0x20, ctx->heap);
    fmt = STRBUF_Create(0x20, ctx->heap);
    MSGDATA_ReadString(ctx->bank, 0xFD, fmt);
    WORDSET_SetSlotNumber(ctx->words, 0, num, digits, mode, 1);
    WORDSET_CopyTaggedText(ctx->words, str, fmt);
    for (i = 0; i < 8; i++) {
        if (ctx->used[i] == 0) {
            ctx->slot[i].win = win;
            ctx->slot[i].shown = 0;
            print = ctx->print;
            PRINTSYS_PrintQueColor(print, (u32)BMP_WIN_GetBmp(ctx->slot[i].win), (s16)x, (s16)y, (u32)str, (u32)ctx->font, 0x3DC8);
            ctx->slot[i].shown = 1;
            ctx->used[i] = 1;
            STRBUF_Delete(fmt);
            STRBUF_Delete(str);
            return;
        }
    }
    func_02034714((void *)0x02203F74, 0, (void *)0x02203F74);
}
