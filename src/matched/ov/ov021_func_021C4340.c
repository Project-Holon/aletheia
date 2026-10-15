/*
 * function: SODATEYA_SetupEggMon
 * address:  0x021C4340
 * packet:   pkt_ov021_021C4340
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Builds the day-care egg/offspring Pokemon from the 0x8C-byte work
 * record q (the struct SODATEYA_BuildEgg fills on its stack). The bl to the
 * Thumb tail-call stub POKE_TOOL_RecoverAllPP is witnessed by
 * src/matched/arm9/POKE_TOOL_RecoverAllPP.c.
 *
 * Load-bearing: const S *q (the species/level loads rise above the zero
 * stack-argument stores), and heap u16 at both callees (func_02008510,
 * SAVE_EVENT_Write) so it is re-read from its stack slot per call.
 * symbols:
 *   POKE_TOOL_SetupPartyParamEx  0x02017588  thumb
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 *   POKE_TOOL_SetAbility  0x02018A00  thumb
 *   func_02008510  0x02008510  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   func_02045EC0  0x02045EC0  arm
 *   SAVE_EVENT_Write  0x0202F190  thumb
 *   POKE_TOOL_RecoverAllPP  0x02018198  thumb
 *   POKE_TOOL_RecalcParam  0x020185C4  thumb
 *   POKE_TOOL_HealFull  0x0201B9F0  thumb
 *   gSpeciesNameBank     0x020A7370  data
 *   sSodateyaEggIvIds     0x021DA948  data  ov021  a4
 */

typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct { u32 v[6]; } T6;
typedef struct {
    u32 species;
    u32 form;
    u32 level;
    u32 f0C;
    u32 f10;
    u32 f14;
    u32 iv[6];
    u32 f30;
    u32 f34;
    u32 f38;
    u32 mv[4];
    u32 f4C;
    u32 f50;
    u32 f54;
    u32 a[6];
    u32 b[6];
    u32 n;
} S;

struct Mon;
extern void POKE_TOOL_SetupPartyParamEx(struct Mon *p, u16 species, u16 level, unsigned long long id, u32 pow, unsigned long long rnd);
extern void POKE_TOOL_SetPartyValue(void *mon, u32 id, u32 v);
extern void POKE_TOOL_SetAbility(void *mon, u32 species, u32 form);
struct MsgBank;
struct U16Vec;
extern void *func_02008510(void *a, int tag);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void SAVE_EVENT_Write(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void POKE_TOOL_RecoverAllPP(void *mon);
extern void POKE_TOOL_RecalcParam(void *mon);
extern void POKE_TOOL_HealFull(void *mon);
extern void *gSpeciesNameBank;
extern const T6 sSodateyaEggIvIds;

void SODATEYA_SetupEggMon(void *mon, const S *q, void *my, u32 y, u16 heap)
{
    T6 t = sSodateyaEggIvIds;
    int i;
    u32 s;

    POKE_TOOL_SetupPartyParamEx(mon, q->species, q->level, q->f30, -1, q->f34);
    POKE_TOOL_SetPartyValue(mon, 0x6f, q->form);
    POKE_TOOL_SetPartyValue(mon, 0x70, q->f0C);
    POKE_TOOL_SetPartyValue(mon, 9, q->f14);
    if (q->f4C == 2)
        POKE_TOOL_SetAbility(mon, q->species, q->form);
    else
        POKE_TOOL_SetPartyValue(mon, 0xb2, q->f10);
    for (i = 0; i < 6; i++) {
        if (q->a[i] != 0 || q->b[i] != 0)
            POKE_TOOL_SetPartyValue(mon, t.v[i], q->iv[i]);
    }
    POKE_TOOL_SetPartyValue(mon, 0x36, q->mv[0]);
    POKE_TOOL_SetPartyValue(mon, 0x37, q->mv[1]);
    POKE_TOOL_SetPartyValue(mon, 0x38, q->mv[2]);
    POKE_TOOL_SetPartyValue(mon, 0x39, q->mv[3]);
    s = (u32)func_02008510(my, heap);
    POKE_TOOL_SetPartyValue(mon, 0x8d, s);
    STRBUF_Delete((struct U16Vec *)s);
    s = (u32)func_02045EC0(gSpeciesNameBank, 0x28a);
    POKE_TOOL_SetPartyValue(mon, 0x73, s);
    STRBUF_Delete((struct U16Vec *)s);
    SAVE_EVENT_Write(mon, 5, (u32)my, y, heap);
    POKE_TOOL_SetPartyValue(mon, 0x4c, 1);
    POKE_TOOL_RecoverAllPP(mon);
    POKE_TOOL_RecalcParam(mon);
    POKE_TOOL_HealFull(mon);
}
