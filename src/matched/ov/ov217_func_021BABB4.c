/*
 * function: RESEARCH_LIST_Destroy
 * address:  0x021BABB4
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
 *   RESEARCH_LIST_Free  0x021BC818  thumb  ov217
 *   RESEARCH_LIST_DestroyCommandQueue  0x021BC954  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 RESEARCH_LIST_Free(void *a0);
extern void RESEARCH_LIST_DestroyCommandQueue(u8 *a0);
u32 RESEARCH_LIST_Destroy(void *a0)
{
    RESEARCH_LIST_DestroyCommandQueue((u8 *)a0);
    return RESEARCH_LIST_Free(a0);
}

