/*
 * function: BTLV_MCSS_HasPersonalParam10
 * address:  0x021FFF68
 * packet:   pkt_ov094_021FFF68
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   POKE_TOOL_GetPersonalParam  0x02019C90  thumb
 *   BTLV_MCSS_FindSpriteIndex  0x022019F4  thumb  ov094
 */
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x28];
    u32 a;                  /* 0x2c (w+0x34) */
    u32 b;                  /* 0x30 (w+0x38) */
    char pad34[0x28];
} Entry;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry e[14];            /* 0x008 */
} Work;

extern int BTLV_MCSS_FindSpriteIndex(char *p, int key);
extern u32 POKE_TOOL_GetPersonalParam(u16 a, u16 b, u32 k);

int BTLV_MCSS_HasPersonalParam10(Work *w, int key)
{
    int idx = BTLV_MCSS_FindSpriteIndex((char *)w, key);

    if (idx == -1)
        return 0;
    if (w->e[idx].h == 0)
        return 0;
    if (POKE_TOOL_GetPersonalParam(w->e[idx].a, w->e[idx].b, 0x10))
        return 1;
    return 0;
}
