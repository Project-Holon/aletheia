/*
 * function: BTLV_MCSS_RefreshSpriteFromParty
 * address:  0x021FFE48
 * packet:   pkt_ov094_021FFE48
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   POKE_TOOL_IsShiny  0x02017EAC  thumb
 *   func_02019C90  0x02019C90  thumb
 *   func_0202D034  0x0202D034  thumb
 *   BTLV_MCSS_FindSpriteIndex  0x022019F4  thumb  ov094
 */
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x28];
    u32 a;                  /* 0x2c (w+0x34) */
    u32 b;                  /* 0x30 (w+0x38) */
    u32 c;                  /* 0x34 (w+0x3c) */
    u16 d;                  /* 0x38 (w+0x40) */
    u16 e;                  /* 0x3a (w+0x42) */
    u32 f;                  /* 0x3c (w+0x44) */
    u32 flags0;             /* 0x40 (w+0x48) */
    char pad44[0x08];
    u32 flags;              /* 0x4c (w+0x54) */
    char pad50[0x0c];
} Entry;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry e[14];            /* 0x008 */
} Work;

extern int BTLV_MCSS_FindSpriteIndex(char *p, int key);
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern u32 POKE_TOOL_IsShiny(void *p);
extern u32 func_02019C90(u16 a, u16 b, u32 k);
extern int func_0202D034(u32 a, u32 b);

void BTLV_MCSS_RefreshSpriteFromParty(Work *w, int key, void *p)
{
    int idx = BTLV_MCSS_FindSpriteIndex((char *)w, key);

    if (idx == -1)
        return;
    if (w->e[idx].h == 0)
        return;
    w->e[idx].a = POKE_TOOL_GetPartyValue(p, 5, 0);
    w->e[idx].b = POKE_TOOL_GetPartyValue(p, 0x6f, 0);
    w->e[idx].d = func_02019C90(w->e[idx].a, w->e[idx].b, 0x26);
    w->e[idx].c = POKE_TOOL_GetPartyValue(p, 0, 0);
    w->e[idx].f = POKE_TOOL_GetPartyValue(p, 0x98, 0);
    if (POKE_TOOL_IsShiny(p) == 1)
        w->e[idx].flags0 |= 2;
    w->e[idx].e = func_0202D034(POKE_TOOL_GetPartyValue(p, 0xa0, 0), POKE_TOOL_GetPartyValue(p, 0xa1, 0));
    w->e[idx].flags |= 0x200;
}
