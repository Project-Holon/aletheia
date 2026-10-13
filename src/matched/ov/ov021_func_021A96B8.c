/*
 * function: FIELD_ENCOUNT_InitWildPokemon
 * address:  0x021A96B8
 * packet:   pkt_ov021_021A96B8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * symbols:
 *   func_020084F4  0x020084F4  thumb
 *   func_02008550  0x02008550  thumb
 *   POKE_TOOL_SetupPartyParamEx  0x02017588  thumb
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 *   POKE_TOOL_RecalcParam  0x020185C4  thumb
 *   POKE_TOOL_SetAbility  0x02018A00  thumb
 *   func_0201ADE4  0x0201ADE4  thumb
 *   func_0201AE14  0x0201AE14  thumb
 *   FIELD_ENCOUNT_RollHeldItem  0x021A9CAC  thumb
 *   FIELD_ENCOUNT_CreatePersonality  0x021A9D30  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

typedef unsigned long long u64;

struct Unit {
    u8 pad00[8];
    int f08;
    u8 pad0C[0x11];
    u8 f1D;
    u8 pad1E[2];
    u32 f20;
    void *f24;
    u32 b0 : 9;
    u32 b9 : 1;
    u32 b10 : 1;
};
struct Slot14 { u16 f00; u16 f02; u8 f04; u8 f05; u8 f06; u8 f07; };

extern void *func_0201ADE4(unsigned int a, int b, unsigned int c);
extern u32 FIELD_ENCOUNT_CreatePersonality(struct Unit *u, void *src, struct Slot14 *s);
struct Mon;
struct Sub0200852CObj;
extern void POKE_TOOL_SetupPartyParamEx(struct Mon *p, u16 species, u16 level, unsigned long long id, u32 pow, unsigned long long rnd);
extern void POKE_TOOL_SetPartyValue(void *p, u32 id, u32 v);
extern void POKE_TOOL_SetAbility(void *p, u32 a, u32 b);
extern void FIELD_ENCOUNT_RollHeldItem(void *mon, void *src, int a, int b);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern const void *func_020084F4(const void *p);
extern void POKE_TOOL_RecalcParam(void *p);
extern void func_0201AE14(void *p);

void FIELD_ENCOUNT_InitWildPokemon(void *mon, const struct Unit *u, struct Slot14 *s)
{
    void *pd = func_0201ADE4(s->f00, s->f05, 4);
    u32 pid = FIELD_ENCOUNT_CreatePersonality((struct Unit *)u, pd, s);

    POKE_TOOL_SetupPartyParamEx(mon, s->f00, s->f04, u->f20, 0xFFFFFFFF, pid);
    POKE_TOOL_SetPartyValue(mon, 0x6F, s->f05);
    if (s->f07)
        POKE_TOOL_SetAbility(mon, s->f00, s->f05);
    if (s->f02 <= 0x272) {
        if (s->f02 != 0)
            POKE_TOOL_SetPartyValue(mon, 6, s->f02);
        else
            FIELD_ENCOUNT_RollHeldItem(mon, pd, u->b9, u->f08 == 1);
    }
    POKE_TOOL_SetPartyValue(mon, 0x9A, func_02008550(u->f24));
    POKE_TOOL_SetPartyValue(mon, 0x8E, (u32)func_020084F4(u->f24));
    if (u->b10)
        POKE_TOOL_SetPartyValue(mon, 0x70, u->f1D);
    POKE_TOOL_RecalcParam(mon);
    func_0201AE14(pd);
}
