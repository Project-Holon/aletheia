/*
 * function: RESEARCH_TOP_UpdateBackground3
 * address:  0x021BA830
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Reconstructed from the listing (.inst decoded).
 *
 * symbols:
 *   RESEARCH_TOP_UpdateBackground3  0x021BA830  thumb  ov217
 *   BG_SYS_Init  0x02040C14  arm  arm9
 *   BG_SYS_ClearSlot  0x020414EC  arm  arm9
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void BG_SYS_Init(u32 layer, u32 value, u32 count, u32 index);
extern u32 BG_SYS_ClearSlot();
u32 RESEARCH_TOP_UpdateBackground3(void *a0)
{
    BG_SYS_Init(3, 0, 1, 0);
    return BG_SYS_ClearSlot(3);
}

