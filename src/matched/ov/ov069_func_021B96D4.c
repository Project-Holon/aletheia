/*
 * function: func_021B96D4
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
 *   func_020457B0  0x020457B0  arm
 *   func_0201EC74  0x0201EC74  thumb
 *   func_020056A0  0x020056A0  thumb
 *   func_021B96C8  0x021B96C8  thumb  ov069
 *   GAME_DATA_GetSaveBlock3B  0x02012EFC  thumb
 *   func_0200DF58  0x0200DF58  thumb
 *   func_0200DF94  0x0200DF94  thumb
 *   func_021BA350  0x021BA350  thumb  ov069
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
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern struct WordSet *func_0201EC74(u32 n, u32 size, u16 heap);
extern void *func_020056A0(void *fn, void *arg, u32 c);
extern void  func_021B96C8(void);
extern void *GAME_DATA_GetSaveBlock3B(void **p);
extern struct Buf3FC *func_0200DF58(struct RecSlot *p, u32 heap);
extern u32 func_0200DF94(struct Buf3FC *b);
extern void func_021BA350(char *p);

void func_021B96D4(u8 *p, u32 a)
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
    *(void **)(p + 0xfc) = func_020457B0(0x40, 0x80);
    *(void **)(p + 0xf8) = func_0201EC74(8, 0x40, 0x80);
    *(void **)(p + 0x150) = func_020056A0((void *)func_021B96C8, p, 0);
    *(void **)(p + 8) = func_0200DF58(GAME_DATA_GetSaveBlock3B(**(void ***)(p + 0x154)), 0x80);
    *(u32 *)(p + 0x164) = func_0200DF94(*(void **)(p + 8));
    func_021BA350((char *)p);
}
