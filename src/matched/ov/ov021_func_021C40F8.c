/*
 * function: SODATEYA_AddEggMoves
 * address:  0x021C40F8
 * packet:   pkt_ov021_021C40F8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * r2 is never touched before the ARC_TOOL_LoadMember call: the function takes a
 * third parameter and forwards it as the heap argument. With two
 * parameters the table copy takes r3/r2 instead of r4/r3 (7 bytes).
 * symbols:
 *   ARC_TOOL_LoadMember  0x02048F60  arm
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   SODATEYA_AddMove  0x021C42F4  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   sSodateyaEggMoveSlotIds     0x021DA908  data  ov021  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned short u16;

typedef struct { u32 v[4]; } T;

extern void *ARC_TOOL_LoadMember(u32 archive, u32 member, u32 heap);
extern u32 POKE_TOOL_GetPartyValue(void *a, u32 b, u32 c);
extern void SODATEYA_AddMove(u32 *p, u32 v);
extern u32 func_020307B0(void *p);
extern T sSodateyaEggMoveSlotIds;

void SODATEYA_AddEggMoves(u32 *p, u32 *q, u32 heap)
{
    T t = sSodateyaEggMoveSlotIds;
    u32 *pt = t.v;
    u16 *buf = ARC_TOOL_LoadMember(0x7b, q[0], heap);
    int n = buf[0];
    int i;

    for (i = 0; i < 4; i++) {
        u32 v = POKE_TOOL_GetPartyValue((void *)p[0], pt[i], 0);
        int j;

        for (j = 1; j <= n; j++) {
            if (v == buf[j]) {
                SODATEYA_AddMove(q, v);
                break;
            }
        }
    }
    func_020307B0(buf);
}
