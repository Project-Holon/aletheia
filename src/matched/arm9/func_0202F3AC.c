/*
 * function: SAVE_EVENT_CopyVariant
 * address:  0x0202F3AC
 * packet:   pkt_0202F30C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   POKE_TOOL_GetBoxValue   0x02017E88  thumb
 *   SAVE_EVENT_StoreVariant   0x0202F358  thumb
 *
 * Reads the four resource slots of one variant and hands them, with the
 * opposite flag, to SAVE_EVENT_StoreVariant.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SAVE_EVENT_CopyVariant.c \
 *       --func SAVE_EVENT_CopyVariant --addr 0x0202F3AC --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32  POKE_TOOL_GetBoxValue(void *p, u32 id, u32 v);
extern void SAVE_EVENT_StoreVariant(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5);

void SAVE_EVENT_CopyVariant(void *a0, u32 a1)
{
    u8 base = (a1 == 1);
    u32 x, y, z, flag, w;

    x = POKE_TOOL_GetBoxValue(a0, base + 0x95, 0);
    base = (u8)(base * 3);
    y = POKE_TOOL_GetBoxValue(a0, base + 0x8F, 0);
    z = POKE_TOOL_GetBoxValue(a0, base + 0x90, 0);
    w = POKE_TOOL_GetBoxValue(a0, base + 0x91, 0);

    flag = (a1 == 0);
    SAVE_EVENT_StoreVariant(a0, x, y, z, w, flag);
}
