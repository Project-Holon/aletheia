/*
 * function: func_02200188
 * address: 0x02200188
 * packet: pkt_ov186_02200188
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: loop-2 store written as two statements (dst[filled] = ...; filled++;) with braced
 *   loop and if bodies; the one-line dst[filled++] form left a 3-register rotation (18 B).
 * symbols:
 *   func_0200D064 0x0200D064 thumb
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   d_02200C94 0x02200C94 data a2
 *   d_02200D9C 0x02200D9C data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Blk37;
extern u32 func_0200D064(struct Blk37 *p, u16 id);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void func_02082BCC(void *, u8, u32);
extern const u16 d_02200C94[];
extern const char d_02200D9C[];
u16 *func_02200188(void *p, u32 index, const u16 *table, u32 *out, u16 heap)
{
    u32 end, start;
    u16 *dst;
    int filled;
    int count, bytes;
    end = d_02200C94[index + 1];
    count = 0;
    start = d_02200C94[index];
    for (filled = start; filled < end; filled++) {
        if (func_0200D064(p, table[filled])) {
            count++;
        }
    }
    bytes = count * 2;
    dst = func_02030734(heap, bytes, 0, d_02200D9C, 0x3c3);
    filled = 0;
    func_02082BCC(dst, 0, bytes);
    for (; start < end; start++) {
        if (func_0200D064(p, table[start])) {
            dst[filled] = table[start];
            filled++;
        }
    }
    if (out) *out = filled;
    return dst;
}
