/*
 * function: WORLDTRADE_LIST_CreateStrings
 * address:  0x021FD270
 * packet:   pkt_021FD270
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   STRBUF_Create  0x020457B0  arm
 *   WORDSET_ClearAllSlots  0x0201F31C  thumb
 *   WORDSET_SetSlotFromMsgE7  0x0201F048  thumb
 *   WORDSET_DeleteMsgdataF094  0x0201F094  thumb
 *   WORLDTRADE_ADAPTER_CreateString  0x02202670  thumb
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad0[0x120];
    u8 lang;
    u8 ver;
    u8 pad122[0x128 - 0x122];
} Entry;

typedef struct {
    u8 pad0[0xD4];
    int cur;
    u8 padD8[0x20C - 0xD8];
    Entry arr[8];
    u8 padB4C[0xB68 - 0xB4C];
    void *words;
    void *msg;
    u8 padB70[0xB88 - 0xB70];
    void *str;
    u8 padB8C[4];
    void *name0;
    void *name1;
} Work;

struct U16Vec;
struct WordSet;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void WORDSET_ClearAllSlots(struct WordSet *p);
extern void WORDSET_SetSlotFromMsgE7(struct WordSet *p, u32 i, u32 n);
extern void WORDSET_DeleteMsgdataF094(struct WordSet *p, u32 i, u32 a, u32 n);
extern u32 WORLDTRADE_ADAPTER_CreateString(u32 a, u32 b, u32 c, u32 d);

void WORLDTRADE_LIST_CreateStrings(Work *p)
{
    Entry *e = &p->arr[p->cur];

    p->str = STRBUF_Create(0xB4, 0x48);
    WORDSET_ClearAllSlots(p->words);
    if (e->lang != 0) {
        WORDSET_SetSlotFromMsgE7(p->words, 8, e->lang);
    }
    if (e->ver != 0) {
        WORDSET_DeleteMsgdataF094(p->words, 9, e->lang, e->ver);
    }
    p->name0 = (void *)WORLDTRADE_ADAPTER_CreateString((u32)p->words, (u32)p->msg, 0x58, 0x48);
    p->name1 = (void *)WORLDTRADE_ADAPTER_CreateString((u32)p->words, (u32)p->msg, 0x59, 0x48);
}
