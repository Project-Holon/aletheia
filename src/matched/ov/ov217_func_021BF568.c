/*
 * function: RESEARCH_GRAPH_EnableOamsA
 * address:  0x021BF568
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: forwards arg(s) a0, 0, 1 to RESEARCH_GRAPH_SetOamEnabled.
 *
 * symbols:
 *   RESEARCH_GRAPH_SetOamEnabled  0x021BF580  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void RESEARCH_GRAPH_SetOamEnabled(u8 *p, u32 i, u32 j);

void RESEARCH_GRAPH_EnableOamsA(void *a0)
{
    RESEARCH_GRAPH_SetOamEnabled((u8 *)a0, 0, 1);
}

