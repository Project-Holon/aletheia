/*
 * function: func_02176280
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
 *   func_020457B0  0x020457B0  arm
 *   func_02045994  0x02045994  arm
 *   func_0201EE0C  0x0201EE0C  thumb
 *   func_02045808  0x02045808  arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct Strbuf;
struct U16Vec;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045994(struct Strbuf *o, const u16 *src, u32 len);
struct WordSet;
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void func_02045808(struct U16Vec *vec);

void func_02176280(void *win, u32 slot, void *src, u32 size, u16 heap, u32 a)
{
    void *buf;

    buf = func_020457B0(size, heap);
    func_02045994(buf, src, size);
    func_0201EE0C(win, slot, buf, a, 1, 2);
    func_02045808(buf);
}
