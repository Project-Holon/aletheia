/*
 * function: MCSS_TOOL_AddPokeMcss
 * address:  0x02017270
 * packet:   pkt_02017270
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MCSS_TOOL_AddPokeMcss.c \
 *       --func MCSS_TOOL_AddPokeMcss --addr 0x02017270 --cc 1.1p1 --thumb
 *
 * symbols:
 *   MCSS_Add  0x020159C8  thumb
 *   MCSS_TOOL_MakeAddWorkFromPP  0x02017100  thumb
 *   MCSS_TOOL_SetSpindaSpotHook  0x020172AC  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed char s8;

extern u32  POKE_TOOL_GetPartyValue(void *p, u32 a, u32 b);
extern void MCSS_TOOL_SetSpindaSpotHook(int a0, int a1);
struct Obj;
struct Rec;
struct Stats;
struct Sub150;
extern void MCSS_TOOL_MakeAddWorkFromPP(void *p, struct Stats *out, u32 lvl);
extern struct Rec *MCSS_Add(struct Obj *obj, u32 a1, u32 a2, u32 a3, const struct Sub150 *src);

void *MCSS_TOOL_AddPokeMcss(void *a0, void *a1, u32 a2, u32 a3, u32 a4, u32 a5)
{
    u8 buf[0x24];

    MCSS_TOOL_SetSpindaSpotHook((int)a0, POKE_TOOL_GetPartyValue(a1, 0, 0));
    MCSS_TOOL_MakeAddWorkFromPP(a1, (struct Stats *)buf, a2);
    return MCSS_Add(a0, a3, a4, a5, (const struct Sub150 *)buf);
}
