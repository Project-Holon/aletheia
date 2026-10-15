/*
 * function: SODATEYA_AddTmMoves
 * address:  0x021C4238
 * packet:   pkt_ov021_021C4238
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   FILE_UTIL_Get_12B0  0x020212B0  thumb
 *   SODATEYA_CanLearnTm  0x021C447C  thumb  ov021
 *   SODATEYA_AddMove  0x021C42F4  thumb  ov021
 *   sSodateyaTmMoveSlotIds     0x021DA8E8  data  ov021  a4
 */

typedef unsigned int u32;
typedef unsigned short u16;

typedef struct { u32 v[4]; } T;

extern u32 POKE_TOOL_GetPartyValue(void *a, u32 b, u32 c);
extern u16 FILE_UTIL_Get_12B0(u16 id);
extern int SODATEYA_CanLearnTm(u32 a, u32 b, u32 c, u32 d);
extern void SODATEYA_AddMove(u32 *p, u32 v);
extern T sSodateyaTmMoveSlotIds;

void SODATEYA_AddTmMoves(u32 *a, u32 *b, u32 *c)
{
    T t = sSodateyaTmMoveSlotIds;
    int i;

    for (i = 0; i < 4; i++) {
        u32 v = POKE_TOOL_GetPartyValue((void *)a[0], t.v[i], 0);
        int k;

        for (k = 0x148; k <= 0x272; k++) {
            if (v == FILE_UTIL_Get_12B0(k)) {
                if (SODATEYA_CanLearnTm((u32)c, (u16)b[0], (u16)b[1], (u16)k)) {
                    SODATEYA_AddMove(b, v);
                    break;
                }
            }
        }
    }
}
