/*
 * function: WORLDTRADE_BOX_MonMatchesRequest
 * address:  0x021F6CDC
 * packet:   pkt_021F6CDC
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
  *
 * symbols:
 *   WORLDTRADE_BOX_TagMatchesRequest  0x021F6C80  thumb
 *   POKE_TOOL_CalcBoxLevel  0x02018438  thumb  arm9
 *   POKE_TOOL_GetBoxValue  0x02017E88  thumb  arm9
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u16 species;
    u8 form;
    u8 gender;
} MonTag;

extern u32 POKE_TOOL_GetBoxValue(void *p, u32 id, u32 v);
extern u32 POKE_TOOL_CalcBoxLevel(void *p);
extern int WORLDTRADE_BOX_TagMatchesRequest(void *pa, void *pb);

int WORLDTRADE_BOX_MonMatchesRequest(void *mon, void *want)
{
    MonTag t;

    t.species = POKE_TOOL_GetBoxValue(mon, 5, 0);
    t.form = POKE_TOOL_GetBoxValue(mon, 0x6E, 0) + 1;
    t.gender = POKE_TOOL_CalcBoxLevel(mon);
    return WORLDTRADE_BOX_TagMatchesRequest(&t, want);
}
