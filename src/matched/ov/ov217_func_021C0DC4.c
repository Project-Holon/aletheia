/*
 * function: ListViewState_Create
 * address:  0x021C0DC4
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reconstructed from the listing (.inst decoded).
 *
 * symbols:
 *   ListViewState_Create  0x021C0DC4  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void *func_02030734(u32 heap, u32 size, int clear, const char *site, u16 tag);
u32 ListViewState_Create(u32 a0)
{
    return (u32)func_02030734(a0, 12, 1, (const char *)0x21C4034, 32);
}

