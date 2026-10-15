/*
 * function: INTRUDE_COMM_SetWordSetPlayerName
 * address:  0x02176280
 * packet:   pkt_ov011_02176280
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   STRBUF_Create  0x020457B0  arm
 *   STRBUF_SetStringN  0x02045994  arm
 *   WORDSET_SetSlotTag  0x0201EE0C  thumb
 *   STRBUF_Delete  0x02045808  arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct Strbuf;
struct U16Vec;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void STRBUF_SetStringN(struct Strbuf *o, const u16 *src, u32 len);
struct WordSet;
extern void WORDSET_SetSlotTag(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void STRBUF_Delete(struct U16Vec *vec);

void INTRUDE_COMM_SetWordSetPlayerName(void *win, u32 slot, void *src, u32 size, u16 heap, u32 a)
{
    void *buf;

    buf = STRBUF_Create(size, heap);
    STRBUF_SetStringN(buf, src, size);
    WORDSET_SetSlotTag(win, slot, buf, a, 1, 2);
    STRBUF_Delete(buf);
}
