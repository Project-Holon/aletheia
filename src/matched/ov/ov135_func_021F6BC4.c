/*
 * function: WORLDTRADE_BOX_GetBoxCount
 * address:  0x021F6BC4
 * packet:   pkt_021F6BC4
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
  *
 * symbols:
 *   tbl_02202C58  0x02202C58  data  a4
 *   POKE_TOOL_DecodeBoxParam  0x02017DBC  thumb  arm9
 *   POKE_TOOL_EncodeBoxParam  0x02017DE4  thumb  arm9
 *   POKE_TOOL_GetBoxValue  0x02017E88  thumb  arm9
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

struct Sav;
extern u32 POKE_TOOL_DecodeBoxParam(struct Sav *p);
extern u32 POKE_TOOL_GetBoxValue(void *p, u32 id, u32 v);
extern u32 POKE_TOOL_EncodeBoxParam(struct Sav *p, u32 f);
extern const u32 tbl_02202C58[];

u32 WORLDTRADE_BOX_GetBoxCount(void *sav)
{
    u32 f = POKE_TOOL_DecodeBoxParam(sav);
    u32 i;
    u32 r;

    for (i = 0; i < 15; i++) {
        r = POKE_TOOL_GetBoxValue(sav, tbl_02202C58[i], 0);
        if (r == 1) {
            break;
        }
    }
    POKE_TOOL_EncodeBoxParam(sav, f);
    return r;
}
