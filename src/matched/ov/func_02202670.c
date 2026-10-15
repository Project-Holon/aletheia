/*
 * function: WORLDTRADE_ADAPTER_CreateString
 * address:  0x02202670
 * packet:   pkt_02202670
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   STRBUF_Create  0x020457B0  arm  arm9
 *   STRBUF_Delete  0x02045808  arm  arm9
 *   WORDSET_CopyTaggedText  0x0201F250  thumb  arm9
 *

 *
 * Encode one record through the two stage helpers and flush it to the writer.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void STRBUF_Delete(struct U16Vec *vec);

u32 WORLDTRADE_ADAPTER_CreateString(u32 a, u32 b, u32 c, u32 d)
{
    u32 t1 = (u32)func_02045EC0((struct MsgBank *)b, c);
    u32 t2 = (u32)STRBUF_Create(0x200, d);

    WORDSET_CopyTaggedText((struct WordSet *)a, (void *)t2, (void *)t1);
    STRBUF_Delete((struct U16Vec *)t1);
    return t2;
}
