/*
 * function: SAVE_EVENT_ClearVariant
 * address:  0x0202F2F4
 * packet:   pkt_0202EF98
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   SAVE_EVENT_StoreVariant  0x0202F358  thumb
 *   GF_STANDARD_GetCachedDate  0x0203F4E4  arm
 *   POKE_TOOL_SetBoxValue  0x02017E64  thumb
 */
typedef unsigned int  u32;
typedef unsigned short u16;

void SAVE_EVENT_ClearVariant(void *a0, u32 a1)
{
    SAVE_EVENT_StoreVariant(a0, 0, 0, 0, 0, a1);
}
