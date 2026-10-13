/*
 * function: SODATEYA_LearnMove
 * address:  0x021C360C
 * packet:   pkt_ov021_021C360C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   SODATEYA_MonKnowsMove  0x021C3670  thumb  ov021
 *   POKE_TOOL_SetMoveSlot  0x020181F4  thumb
 *   POKE_TOOL_PushMove  0x020180F4  thumb
 *   d_021DA8C8     0x021DA8C8  data  ov021  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef struct { u32 v[4]; } T4;

extern u32 POKE_TOOL_GetPartyValue(void *, u32, u32);
extern int SODATEYA_MonKnowsMove(void *, u32);
extern void POKE_TOOL_SetMoveSlot(void *p, u16 move, u32 slot);
extern void POKE_TOOL_PushMove(void *p, int move);
extern const T4 d_021DA8C8;

void SODATEYA_LearnMove(void *a, u32 b)
{
    T4 t = d_021DA8C8;
    int i;

    if (b != 0 && SODATEYA_MonKnowsMove(a, b) == 0) {
        for (i = 0; i < 4; i++) {
            if (POKE_TOOL_GetPartyValue(a, t.v[i], 0) == 0) {
                POKE_TOOL_SetMoveSlot(a, b, (u8)i);
                return;
            }
        }
        POKE_TOOL_PushMove(a, (u16)b);
    }
}
