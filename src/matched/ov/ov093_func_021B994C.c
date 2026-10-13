/*
 * function: BTL_MAIN_GetVoiceOfSlot
 * address: 0x021B994C
 * packet: pkt_ov093_021B994C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_MAIN_GetSlotFromViewPos 0x021B8ED8 thumb ov093
 *   BTL_MAIN_GetSlotClientIdThunk 0x021B8DE4 thumb ov093
 * evidence: original narrows second argument before 021B8ED8 call.
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 BTL_MAIN_GetSlotFromViewPos(u8 *p, u8 k);
extern u8 BTL_MAIN_GetSlotClientIdThunk(char *p, int i);
int BTL_MAIN_GetVoiceOfSlot(u8 *p, u32 i, void **out)
{
    void *v;
    u32 n = BTL_MAIN_GetSlotClientIdThunk((char *)p, BTL_MAIN_GetSlotFromViewPos(p, i));
    v = *(void **)(p + n * 4 + 0x3e0);
    if (v != 0) {
        *out = v;
        return 1;
    }
    return 0;
}
