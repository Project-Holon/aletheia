/*
 * function: CTVT_CALL_Create
 * address:  0x021BBA6C
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Five argument call with the last word on the stack.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   g_021C7234    0x021C7234  data  ov172
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 g_021C7234[];

void *CTVT_CALL_Create(int unused, void *p)
{
    return func_02030734((u32)p, 0x408, 1, (const char *)g_021C7234, 0xd8);
}
