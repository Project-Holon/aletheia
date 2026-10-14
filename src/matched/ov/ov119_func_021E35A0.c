/*
 * function: POKETRADE_3D_AddPokemonMcss
 * address: 0x021E35A0
 * packet: pkt_ov119_021E35A0
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   POKE_PERSONAL_Create 0x0201ADE4 thumb
 *   POKE_PERSONAL_GetParam 0x0201AE1C thumb
 *   POKE_PERSONAL_Delete 0x0201AE14 thumb
 *   DWC_RAP_SetVchatTalkLock 0x0215642C thumb ov009
 *   MCSS_TOOL_AddPokeMcss 0x02017270 thumb
 *   MCSS_TOOL_SetAnimeStopCallback 0x020173B4 thumb
 *   MCSS_SetScale 0x02015CAC thumb
 *   MCSS_SetShadowVanishFlag 0x02015FF0 thumb
 *   POKETRADE_3D_SetMcssOffsetForSpecies 0x021E33FC thumb ov119
 *   data_021E7B00 0x021E7B00 data a4
 *   data_021E7B0C 0x021E7B0C data a4
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int x, y, z; } Vec;
typedef struct { u32 v[4]; } Table;
typedef struct {
    char pad0[0x5f4];
    u16 heap;
    char pad5f6[0x840 - 0x5f6];
    void *res;
    void *obj[4];
    char pad854[0x118c - 0x854];
    int mode;
} Work;
extern const Vec data_021E7B00;
extern const Table data_021E7B0C;
extern u32 POKE_TOOL_GetPartyValue(void *mon, u32 id, u32 v);
extern void *POKE_PERSONAL_Create(unsigned int species, int form, unsigned int heap);
struct Personal;
extern u32 POKE_PERSONAL_GetParam(const struct Personal *p, u32 field);
extern void POKE_PERSONAL_Delete(void *h);
extern void DWC_RAP_SetVchatTalkLock(int);
extern void *MCSS_TOOL_AddPokeMcss(void *a0, void *a1, u32 a2, u32 a3, u32 a4, u32 a5);
extern int MCSS_TOOL_SetAnimeStopCallback(int a0);
extern void MCSS_SetScale(void *p, u32 *src);
extern void MCSS_SetShadowVanishFlag(char *p, int v);
extern void POKETRADE_3D_SetMcssOffsetForSpecies(void *p0, int *dir, int p2, void *mon);
void POKETRADE_3D_AddPokemonMcss(Work *p, int idx, int side, void *mon, int flag)
{
    Vec v = data_021E7B00;
    Table t = data_021E7B0C;
    if (flag) {
        u16 species = POKE_TOOL_GetPartyValue(mon, 5, 0);
        u16 form = POKE_TOOL_GetPartyValue(mon, 0x6f, 0);
        void *h = POKE_PERSONAL_Create(species, form, p->heap);
        u32 r = POKE_PERSONAL_GetParam(h, 0x22);
        POKE_PERSONAL_Delete(h);
        if (r == 0)
            v.x = -v.x;
    }
    if (p->mode == 2)
        DWC_RAP_SetVchatTalkLock(1);
    if (side)
        p->obj[idx] = MCSS_TOOL_AddPokeMcss(p->res, mon, 0, t.v[idx], -0x1C000, 0);
    else
        p->obj[idx] = MCSS_TOOL_AddPokeMcss(p->res, mon, 1, t.v[idx], -0x1C000, 0);
    if (p->mode == 2)
        DWC_RAP_SetVchatTalkLock(0);
    MCSS_TOOL_SetAnimeStopCallback((int)p->obj[idx]);
    MCSS_SetScale(p->obj[idx], (u32 *)(&v));
    MCSS_SetShadowVanishFlag(p->obj[idx], 1);
    POKETRADE_3D_SetMcssOffsetForSpecies(p->obj[idx], (int *)(&v), side, mon);
}
