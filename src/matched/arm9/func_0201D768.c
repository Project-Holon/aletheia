/*
 * function: GF_FONT_Copy
 * address:  0x0201D768
 * packet:   pkt_0201D6D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MI_CpuCopy8  0x02082D44  arm
 *
 * printsys.c: append `len` bytes to the byte ring at +0x18 in `unit`-sized
 * copies, wrapping the head back to 0 at ring->size, and return the address
 * the first copy landed at.  The three callers are GF_FONT_CopyStrbufD6D8's.
 *
 * Rewritten from the start in wave 20 (lane printsys_fresh; 63 bytes out for
 * the inherited source).  What closed it: the head advance is the compound
 * `pos += unit` over a u16 `unit`.  The explicit `pos = (u16)(pos + unit)`
 * gives the loaded head and the advanced head separate webs, the loaded one
 * is cheaper than the counter and is spilled; the compound form keeps both in
 * one live range (r4 in the image), so the counter is the one spilled to
 * [sp,#4].  With a u32 `unit` the compound form truncates `unit` as a loop
 * invariant (100 bytes).  The remaining slot order is the declaration order
 * start, buf, i, pos.
 *
 * note 2026-10-05: removed the redundant first store `buf = ring;` (a
 * stand-in: arm9 game code has no line table to prove it). The single
 * `buf = (u8 *)ring + 0x18;` is EXACT in --lang c99 and --lang c; so is a
 * static inline accessor RingData(ring), so the plain form is kept.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_FONT_Copy.c \
 *       --func GF_FONT_Copy --addr 0x0201D768 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ring {
    u16 head;   /* +0x00 */
    u16 tail;   /* +0x02 */
    u16 size;   /* +0x04 */
};

extern void MI_CpuCopy8(const void *src, void *dst, u32 size);

void *GF_FONT_Copy(struct Ring *ring, const u8 *src, u16 len, u16 unit)
{
    u16 start;
    u8 *buf;
    u16 i;
    u16 pos;

    i = 0;
    buf = (u8 *)ring + 0x18;
    start = ring->head;
    while (i < len) {
        pos = ring->head;
        MI_CpuCopy8(src, buf + pos, unit);
        pos += unit;
        if (pos >= ring->size) {
            pos = 0;
        }
        ring->head = pos;
        src += unit;
        i += unit;
    }
    return buf + start;
}
