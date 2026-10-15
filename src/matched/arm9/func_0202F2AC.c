/*
 * function: SAVE_EVENT_WriteWithDate
 * address:  0x0202F2AC
 * packet:   pkt_0202EF98
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02017E88   0x02017E88  thumb
 *   SAVE_EVENT_StoreVariant   0x0202F358  thumb
 *   SAVE_EVENT_CopyDoneFlag   0x0202F464  thumb
 *   POKE_TOOL_SetBoxValue   0x02017E64  thumb
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SAVE_EVENT_WriteWithDate.c \
 *       --func SAVE_EVENT_WriteWithDate --addr 0x0202F2AC --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

extern u32  func_02017E88(void *p, u32 id, u32 v);
extern void SAVE_EVENT_StoreVariant(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5);
extern int SAVE_EVENT_CopyDoneFlag(int a0);
extern void POKE_TOOL_SetBoxValue(void *p, u32 id, u32 v);

void SAVE_EVENT_WriteWithDate(void *a0, u32 a1, u32 a2, u32 a3, u32 a4)
{
    if (func_02017E88(a0, 0xAA, 0) == 1)
        SAVE_EVENT_StoreVariant(a0, a1, a2, a3, a4, 0);
    else
        SAVE_EVENT_StoreVariant(a0, a1, a2, a3, a4, 1);
    SAVE_EVENT_CopyDoneFlag((int)a0);
    POKE_TOOL_SetBoxValue(a0, 0x6D, 1);
}
