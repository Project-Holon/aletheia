/*
 * function: func_0218FF30
 * address:  0x0218FF30
 * packet:   pkt_ov021_0218FF30
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   d_021DDA38  0x021DDA38  data  ov021  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern const char d_021DDA38[];

void *func_0218FF30(u32 heap)
{
    return func_02030734(heap, 0x20, 0, d_021DDA38, 0xee);
}
