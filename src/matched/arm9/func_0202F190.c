/*
 * function: SAVE_EVENT_Write
 * address:  0x0202F190
 * packet:   pkt_0202EF98
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   POKE_TOOL_Dummy   0x020185F0  thumb
 *   SAVE_EVENT_WriteMode   0x0202F1B4  thumb
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SAVE_EVENT_Write.c \
 *       --func SAVE_EVENT_Write --addr 0x0202F190 --cc 1.1p1 --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern u32  POKE_TOOL_Dummy(void *a0);
extern void SAVE_EVENT_WriteMode(u32 a, u32 b, u32 c, u32 d, u32 e);

void SAVE_EVENT_Write(void *a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    SAVE_EVENT_WriteMode((u32)((void *)POKE_TOOL_Dummy(a0)), a1, a2, a3, a4);
}
