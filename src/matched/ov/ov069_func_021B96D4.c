/*
 * function: BSUBWAY_RECORD_LIST_InitWork
 * address:  0x021B96D4
 * packet:   pkt_ov069_021B96D4
 * region:   ov069
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Byte-correct; blocked by one unwitnessed arm9 leaf (the integrator's), no outside
 * caller: GAME_DATA_GetSaveBlock3B at 0x02012EFC (unlabelled tail-call stub), verified EXACT as
 *   extern void *func_020071CC(void *a, int b);   // symbols: func_020071CC 0x020071CC thumb
 *   void *GAME_DATA_GetSaveBlock3B(void **p) { return func_020071CC(*p, 0x3b); }
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_02045B38  0x02045B38  arm
 *   func_02045EC0  0x02045EC0  arm
 *   STRBUF_GetChars  0x02045A90  arm
 *   STRBUF_Create  0x020457B0  arm
 *   WORDSET_Create  0x0201EC74  thumb
 *   func_020056A0  0x020056A0  thumb
 *   BSUBWAY_RECORD_LIST_VBlankTask  0x021B96C8  thumb  ov069
 *   GAME_DATA_GetSaveBlock3B  0x02012EFC  thumb
 *   BSUBWAY_SAVEDATA_AllocHistoryCopy  0x0200DF58  thumb
 *   BSUBWAY_SAVEDATA_CountHistoryEntries  0x0200DF94  thumb
 *   BSUBWAY_RECORD_LIST_InitPageCount  0x021BA350  thumb  ov069
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int  u32;

extern void *func_020490F4(u32 id, u32 heap);
struct Buf3FC;
struct MsgBank;
struct RecSlot;
struct U16Vec;
struct WordSet;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u16 *STRBUF_GetChars(struct U16Vec *vec);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern struct WordSet *WORDSET_Create(u32 n, u32 size, u16 heap);
extern void *func_020056A0(void *fn, void *arg, u32 c);
extern void  BSUBWAY_RECORD_LIST_VBlankTask(void);
extern void *GAME_DATA_GetSaveBlock3B(void **p);
extern struct Buf3FC *BSUBWAY_SAVEDATA_AllocHistoryCopy(struct RecSlot *p, u32 heap);
extern u32 BSUBWAY_SAVEDATA_CountHistoryEntries(struct Buf3FC *b);
extern void BSUBWAY_RECORD_LIST_InitPageCount(char *p);

void BSUBWAY_RECORD_LIST_InitWork(u8 *p, u32 a)
{
    int i;
    int off = 0x154;

    *(u32 *)(p + off) = a;
    *(u32 *)(p + off + 8) = 0;
    *(void **)p = func_020490F4(0xc7, 0x80);
    *(void **)(p + 0xf4) = func_02045B38(0, 2, 0x39, 0x80);
    off -= 0x54;
    for (i = 0; i < 7; i++) {
        *(void **)(p + i * 4 + off) = func_02045EC0(*(void **)(p + 0xf4), i);
        STRBUF_GetChars(*(void **)(p + i * 4 + off));
    }
    *(void **)(p + 0xfc) = STRBUF_Create(0x40, 0x80);
    *(void **)(p + 0xf8) = WORDSET_Create(8, 0x40, 0x80);
    *(void **)(p + 0x150) = func_020056A0((void *)BSUBWAY_RECORD_LIST_VBlankTask, p, 0);
    *(void **)(p + 8) = BSUBWAY_SAVEDATA_AllocHistoryCopy(GAME_DATA_GetSaveBlock3B(**(void ***)(p + 0x154)), 0x80);
    *(u32 *)(p + 0x164) = BSUBWAY_SAVEDATA_CountHistoryEntries(*(void **)(p + 8));
    BSUBWAY_RECORD_LIST_InitPageCount((char *)p);
}
