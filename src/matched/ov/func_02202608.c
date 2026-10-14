/*
 * function: WORLDTRADE_ADAPTER_AllocHeapBuf
 * address:  0x02202608
 * packet:   pkt_02202608
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_02203F5C  0x02203F5C  data  ov135
 *   POKE_TOOL_GetPartyParamSize  0x020173EC  thumb  arm9

 * Create the table entry and register the 0x47 callback against it.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
extern u32 POKE_TOOL_GetPartyParamSize(void);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern const char g_02203F5C[];

void *WORLDTRADE_ADAPTER_AllocHeapBuf(u32 heap)
{
    return func_02030734(heap, POKE_TOOL_GetPartyParamSize(), 0, g_02203F5C, 0x47);
}
