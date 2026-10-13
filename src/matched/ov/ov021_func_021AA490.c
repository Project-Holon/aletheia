/*
 * function: FIELD_ENCOUNT_SetupWildBattle
 * address:  0x021AA490
 * packet:   pkt_ov021_021AA490
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * symbols:
 *   sFieldEncountFileName  0x021DDFA4  data
 *   BTL_SETUP_SetStatusFlag  0x02013144  thumb
 *   BTL_SETUP_SetupWild  0x0201347C  thumb
 *   POKE_TOOL_GetPartyParamSize  0x020173EC  thumb
 *   func_0201A920  0x0201A920  thumb
 *   func_0201A98C  0x0201A98C  thumb
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   FIELD_ENCOUNT_InitWildPokemon  0x021A96B8  thumb
 *   FIELD_ENCOUNT_SetFieldSituation  0x021AA304  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct Ctx { void *f00; u8 pad04[4]; void *f08; };
struct Unit {
    u8 pad00[8];
    int f08;
    u8 pad0C[0x1C];
    u32 b0 : 5;
    u32 b5 : 1;
};
struct Info { u32 f00; u32 f04; u8 f08; u8 f09; u16 f0A; u8 f0C; u8 f0D; u8 pad0E[2]; };

struct Party;
struct PartyMon;
struct Slot14;
extern struct Party *func_0201A920(u32 heap);
extern u32 POKE_TOOL_GetPartyParamSize(void);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern void FIELD_ENCOUNT_SetFieldSituation(struct Info *out, void *a1, void *a2);
extern void BTL_SETUP_SetupWild(u8 *a0, void *a1, u32 a2, u32 a3, u32 a4, u16 a5);
extern void BTL_SETUP_SetStatusFlag(char *p, int v);
extern u32 func_020307B0(void *p);
extern const char sFieldEncountFileName[];
struct Slot14 { u8 raw[0x14]; };
extern void FIELD_ENCOUNT_InitWildPokemon(void *mon, const struct Unit *u, struct Slot14 *s);

void FIELD_ENCOUNT_SetupWildBattle(struct Ctx *ctx, struct Unit *u, void *a2, u16 heap, struct Slot14 *slots)
{
    struct Info info;
    void *party = func_0201A920(heap);
    void *mon = func_02030734(heap, POKE_TOOL_GetPartyParamSize(), 1, sFieldEncountFileName, 0x285);
    int i;

    for (i = 0; i < (u8)u->b5 + 1; i++) {
        FIELD_ENCOUNT_InitWildPokemon(mon, u, &slots[i]);
        func_0201A98C(party, mon);
    }
    FIELD_ENCOUNT_SetFieldSituation(&info, ctx->f08, ctx->f00);
    BTL_SETUP_SetupWild(a2, ctx->f08, (u32)party, (u32)(&info), u->b5, heap);
    if (u->f08 == 1)
        BTL_SETUP_SetStatusFlag(a2, 0x20);
    func_020307B0(mon);
    func_020307B0(party);
}
