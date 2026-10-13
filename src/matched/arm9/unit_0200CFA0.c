/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 * unit:     yes
 * address:  0x0200CFA0
 * packet:   pkt_0200CA98
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: ZUKAN_SAVE_RegisterSeen
 *
 * symbols:
 *   POKE_TOOL_DecodePartyParam  0x02017D30  thumb
 *   POKE_TOOL_EncodePartyParam  0x02017D70  thumb
 *   POKE_TOOL_GetGender  0x02017F00  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   POKE_TOOL_IsShiny  0x02017EAC  thumb
 *   ZUKAN_SAVE_IsInvalidSpecies  0x0200C720  thumb
 *   ZUKAN_SAVE_SetSeenGenderFlag  0x0200C818  thumb
 *   ZUKAN_SAVE_SetSeenFormFlag  0x0200C914  thumb
 *   ZUKAN_SAVE_UpdateViewFlags  0x0200CA98  thumb
 *   ZUKAN_SAVE_IsSeen  0x0200D064  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Blk37 {
    u32 unk00;
    u32 f0  : 1;
    u32 f1  : 10;
    u32 f11 : 1;
    u32 f12 : 10;
    u32 f22 : 10;
    u8  unk008[0x54];
    u8  unk05C[4][0x54];
    u8  unk1AC[4][0x54];
    u8  unk2FC[4][9];
    u8  unk320[0x1B0];
    u32 unk4D0;
};

struct Sav;
extern u32 POKE_TOOL_DecodePartyParam(struct Sav *p);
extern u32 POKE_TOOL_EncodePartyParam(struct Sav *p, u32 f);
extern u32   POKE_TOOL_GetPartyValue(void *m, u32 field, u32 arg);
extern u8    POKE_TOOL_GetGender(void *m);
extern u32   POKE_TOOL_IsShiny(void *m);
extern u32 ZUKAN_SAVE_IsInvalidSpecies(u32 v);
extern u32   ZUKAN_SAVE_IsSeen(struct Blk37 *p, u16 id);
extern void  ZUKAN_SAVE_UpdateViewFlags(struct Blk37 *p, u16 id, u32 c, u32 d, u32 e);
extern void ZUKAN_SAVE_SetSeenGenderFlag(u8 *p, u32 idx, int sel, int half);
extern void ZUKAN_SAVE_SetSeenFormFlag(u8 *p, u32 id, u32 a2, u32 a3, u32 start);

void ZUKAN_SAVE_RegisterSeen(struct Blk37 *p, void *m)
{
    u32 saved;
    u32 g;
    u32 v0;
    u32 f;
    u32 v6F;
    u16 id;

    saved = POKE_TOOL_DecodePartyParam(m);
    if (POKE_TOOL_GetPartyValue(m, 0x4C, 0) == 1) {
        POKE_TOOL_EncodePartyParam(m, saved);
        return;
    }
    id = (u16)POKE_TOOL_GetPartyValue(m, 5, 0);
    v0 = POKE_TOOL_GetPartyValue(m, 0, 0);
    v6F = POKE_TOOL_GetPartyValue(m, 0x6F, 0);
    f = POKE_TOOL_GetGender(m);
    g = POKE_TOOL_IsShiny(m);
    POKE_TOOL_EncodePartyParam(m, saved);
    if (ZUKAN_SAVE_IsInvalidSpecies(id) != 0) {
        return;
    }
    if (ZUKAN_SAVE_IsSeen(p, id) == 0) {
        ZUKAN_SAVE_UpdateViewFlags(p, id, f, g, v6F);
    }
    if (id == 0x147 && p->unk4D0 == 0) {
        p->unk4D0 = v0;
    }
    ZUKAN_SAVE_SetSeenGenderFlag((u8 *)p, id, f, g);
    ZUKAN_SAVE_SetSeenFormFlag((u8 *)p, id, f, g, v6F);
}
