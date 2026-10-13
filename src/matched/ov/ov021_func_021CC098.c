/*
 * function: FLD_TRADE_BuildPokemon
 * address:  0x021CC098
 * packet:   pkt_ov021_021CC098
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Builds a mon from a spec record: create with a fresh personality, then
 * copy the spec's fields in, pick one of three abilities by spec +0x28,
 * set the two nickname strings and the trainer info, recalc.
 *
 * symbols:
 *   POKE_TOOL_AdjustPersonalRnd  0x0201862C  thumb
 *   POKE_TOOL_SetupPartyParamEx  0x02017588  thumb
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 *   FLD_TRADE_DumpPokemonParams  0x021CC23C  thumb  ov021
 *   FLD_TRADE_GetMessageString  0x021CC070  thumb  ov021
 *   STRBUF_Delete  0x02045808  arm
 *   POKE_PERSONAL_Create  0x0201ADE4  thumb
 *   POKE_PERSONAL_GetParam  0x0201AE1C  thumb
 *   POKE_PERSONAL_Delete  0x0201AE14  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   func_0202F190  0x0202F190  thumb
 *   POKE_TOOL_RecalcParam  0x020185C4  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef unsigned long long u64;

typedef struct {
    u32 f00;
    u32 species;    /* 0x04 */
    u32 level;      /* 0x08 */
    u32 f0C;
    u32 f10[6];     /* 0x10..0x24: fields 0x46..0x4b */
    u32 sel;        /* 0x28 */
    u32 f2C;
    u32 f30;
    u32 id;         /* 0x34 */
    u32 f38[5];     /* 0x38..0x48: fields 0x13..0x17 */
    u32 f4C;
    u32 f50;
    u32 f54;
    u32 f58;
    u32 f5C;
    u32 f60;
    u32 f64;
    u32 f68;
} Spec;

extern u32 POKE_TOOL_AdjustPersonalRnd(u32 id, u16 species, u16 level, u8 a3, u8 a4, int a5);
struct Mon;
extern void POKE_TOOL_SetupPartyParamEx(struct Mon *p, u16 species, u16 level, unsigned long long id, u32 pow, unsigned long long rnd);
extern void POKE_TOOL_SetPartyValue(void *mon, u32 field, u32 v);
struct Personal;
struct U16Vec;
extern void FLD_TRADE_DumpPokemonParams(int obj);
extern void *FLD_TRADE_GetMessageString(u32 file, u32 index);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void *POKE_PERSONAL_Create(unsigned int species, int form, unsigned int heap);
extern u32 POKE_PERSONAL_GetParam(const struct Personal *p, u32 field);
extern void POKE_PERSONAL_Delete(void *p);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern void func_0202F190(void *mon, u32 a1, u32 a2, u32 a3, u16 a4);
extern void POKE_TOOL_RecalcParam(void *mon);

void FLD_TRADE_BuildPokemon(void *sys, u16 b, void *mon, Spec *d)
{
    u32 pid;
    u32 s;
    u32 x;
    u32 v[3];

    pid = POKE_TOOL_AdjustPersonalRnd(d->id, d->species, d->level, d->f30, 0, 0);
    POKE_TOOL_SetupPartyParamEx(mon, d->species, d->f0C, d->id, 0xFFFFFFFF, pid);
    POKE_TOOL_SetPartyValue(mon, 0x6F, d->level);
    FLD_TRADE_DumpPokemonParams((int)mon);
    s = (u32)FLD_TRADE_GetMessageString(b, d->f64);
    POKE_TOOL_SetPartyValue(mon, 0x73, s);
    STRBUF_Delete((struct U16Vec *)s);
    POKE_TOOL_SetPartyValue(mon, 0x46, d->f10[0]);
    POKE_TOOL_SetPartyValue(mon, 0x47, d->f10[1]);
    POKE_TOOL_SetPartyValue(mon, 0x48, d->f10[2]);
    POKE_TOOL_SetPartyValue(mon, 0x49, d->f10[3]);
    POKE_TOOL_SetPartyValue(mon, 0x4A, d->f10[4]);
    POKE_TOOL_SetPartyValue(mon, 0x4B, d->f10[5]);
    x = (u32)POKE_PERSONAL_Create((u16)d->species, (u16)d->level, b);
    v[0] = POKE_PERSONAL_GetParam((const struct Personal *)x, 0x1A);
    v[1] = POKE_PERSONAL_GetParam((const struct Personal *)x, 0x1B);
    v[2] = POKE_PERSONAL_GetParam((const struct Personal *)x, 0x1C);
    POKE_PERSONAL_Delete((void *)x);
    switch (d->sel) {
    case 0:
        break;
    case 1:
        v[0] = v[1];
        break;
    case 2:
        v[0] = v[2];
        break;
    }
    POKE_TOOL_SetPartyValue(mon, 0xA, v[0]);
    POKE_TOOL_SetPartyValue(mon, 0x70, d->f2C);
    POKE_TOOL_SetPartyValue(mon, 0x13, d->f38[0]);
    POKE_TOOL_SetPartyValue(mon, 0x14, d->f38[1]);
    POKE_TOOL_SetPartyValue(mon, 0x15, d->f38[2]);
    POKE_TOOL_SetPartyValue(mon, 0x16, d->f38[3]);
    POKE_TOOL_SetPartyValue(mon, 0x17, d->f38[4]);
    POKE_TOOL_SetPartyValue(mon, 0x6, d->f4C);
    s = (u32)FLD_TRADE_GetMessageString(b, d->f68);
    POKE_TOOL_SetPartyValue(mon, 0x8D, s);
    STRBUF_Delete((struct U16Vec *)s);
    POKE_TOOL_SetPartyValue(mon, 0x9A, d->f50);
    POKE_TOOL_SetPartyValue(mon, 0xC, d->f58);
    func_0202F190(mon, 1, (u32)GAME_DATA_GetMyStatus(sys), 0x7532, b);
    FLD_TRADE_DumpPokemonParams((int)mon);
    POKE_TOOL_RecalcParam(mon);
}
