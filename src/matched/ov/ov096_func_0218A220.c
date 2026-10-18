/*
 * function: TR_AI_GetAbility
 * address: 0x0218A220
 * packet: pkt_ov096_0218A220
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * 2026-10-04 (wave D2 lane 08): re-tested, still MATCH: 11 of 12 relocations resolve; the only open site is BTLV_EFFECT_GetPokeEffectValue (+002E). The symbols line already carries 'thumb ov094', but the sole witness src/matched/ov/BTLV_EFFECT_SetPokeEffectValue.c lists four 'function:' keys and the parser keeps only the last, so 0x021F8AFC has no witness. Fix belongs in that unit's header or the parser (outside this lane's write set); bytes are correct.
 * blocker: existing BTLV_EFFECT_SetPokeEffectValue.c unit omits BTLV_EFFECT_GetPokeEffectValue from
 * its parsed function list: four repeated keys leave only BTLV_EFFECT_ResumeVmWait.
 * Concrete bytes correct; caller-only tu suggest-split has no viable cut.
 * lever: advance p itself before indexed store; random draw helper owns
 * its u64 temporary and returns u32 (random-below-n existing idiom).
 * symbols:
 *   TR_AI_GetPoke 0x0218A2FC thumb ov096
 *   BTL_POKEPARAM_HasSick 0x021D62C4 thumb ov093
 *   BTLV_EFFECT_GetPokeEffectValue 0x021F8AFC thumb ov094
 *   BTL_POKEPARAM_GetValue 0x021D59B4 thumb ov093
 *   BTL_POKEPARAM_GetSpecies 0x021D5444 thumb ov093
 *   POKE_TOOL_GetPersonalParam 0x02019C90 thumb
 *   GF_STANDARD_Rand 0x0203F0A8 arm
 *   _ull_mul 0x0209C054 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
extern int TR_AI_GetPoke(u8 *, int);
struct QF;
struct Unk021D62A8;
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern int BTLV_EFFECT_GetPokeEffectValue(int);
extern int BTL_POKEPARAM_GetValue(u8 *p, int k);
extern u16 BTL_POKEPARAM_GetSpecies(struct QF *p);
extern u32 POKE_TOOL_GetPersonalParam(u16, u16, u32);
extern u32 GF_STANDARD_Rand(void);
static inline u32 draw_below(u32 n)
{
    u64 draw = GF_STANDARD_Rand();
    if (n != 0) draw = (draw * n) >> 32;
    return draw;
}
int TR_AI_GetAbility(u8 *p, int k, int slot)
{
    void *mon;
    int a, b;
    u32 x, y, z, n;
    u32 values[3];
    mon = (void *)TR_AI_GetPoke(p, slot);
    if (BTL_POKEPARAM_HasSick(mon, 0x10) != 0)
        return 0;
    if (k == 0 || k == 2) {
        p += 0x7c;
        p[slot] = BTLV_EFFECT_GetPokeEffectValue(slot);
        if (p[slot] != 0)
            return p[slot];
        a = BTL_POKEPARAM_GetValue(mon, 0x10);
        if (a == 0x17 || a == 0x2a || a == 0x47)
            return a;
        a = BTL_POKEPARAM_GetSpecies(mon);
        b = BTL_POKEPARAM_GetValue(mon, 0x13);
        n = 0;
        x = POKE_TOOL_GetPersonalParam(a, b, 0x1a);
        y = POKE_TOOL_GetPersonalParam(a, b, 0x1b);
        z = POKE_TOOL_GetPersonalParam(a, b, 0x1c);
        if (x != 0) values[n++] = x;
        if (y != 0) values[n++] = y;
        if (z != 0) values[n++] = z;
        return values[draw_below(n)];
    }
    return BTL_POKEPARAM_GetValue(mon, 0x10);
}
