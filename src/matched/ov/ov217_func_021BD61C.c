/*
 * function: RESEARCH_GRAPH_Destroy
 * address:  0x021BD61C
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
 *   RESEARCH_GRAPH_Free  0x021BFB04  thumb  ov217
 *   RESEARCH_GRAPH_DestroyCommandQueue  0x021BFB24  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 RESEARCH_GRAPH_Free(void *a0);
extern void RESEARCH_GRAPH_DestroyCommandQueue(u8 *a0);
u32 RESEARCH_GRAPH_Destroy(void *a0)
{
    RESEARCH_GRAPH_DestroyCommandQueue((u8 *)a0);
    return RESEARCH_GRAPH_Free(a0);
}

