/*
 * function: BTLV_MCSS_ResetSpritePosition
 * address:  0x022004BC
 * packet:   pkt_ov094_022004BC
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 2026-10-01: the arm9 witness leaves named below are now filed in
 * src/matched/arm9, which closes the former MATCH.
 *
 * MATCH: bytes identical; blocked on 0x02015C60, an unfiled unlabelled ARM9
 * Thumb leaf (the integrator's) with no witness outside this range. Verified C for it
 * (EXACT, `one --thumb`, no --region, cc 1.1p1, -O4,p; packet pkt_02015C60,
 * 64 B extent, out-direction twin of MCSS_SetOfsPosition):
 *
 *   typedef unsigned int u32;
 *   void MCSS_GetOfsPosition(void *p, u32 *out)
 *   {
 *       out[0] = *(u32 *)((char *)p + 0x11C);
 *       out[1] = *(u32 *)((char *)p + 0x120);
 *       out[2] = *(u32 *)((char *)p + 0x124);
 *   }
 *
 * symbols:
 *   MCSS_GetPosition  0x02015C30  thumb
 *   MCSS_SetPosition  0x02015C48  thumb
 *   MCSS_GetOfsPosition  0x02015C60  thumb
 *   MCSS_SetOfsPosition  0x02015C78  thumb
 *   MCSS_SetVanishFlag  0x02015EA0  thumb
 *   BTLV_MCSS_CalcSlotPosition  0x022018A8  thumb  ov094
 *   BTLV_MCSS_FindSpriteIndex  0x022019F4  thumb  ov094
 */
typedef unsigned int u32;

typedef struct {
    int x, y, z;
} Vec;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x48];
    u32 flags;              /* 0x4c */
    char pad50[0x0c];
} Entry;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry e[14];            /* 0x008 */
} Work;

extern int BTLV_MCSS_FindSpriteIndex(char *p, int key);
extern void BTLV_MCSS_CalcSlotPosition(Work *w, Vec *out, int key);
extern void MCSS_GetPosition(void *p, u32 *out);
extern void MCSS_GetOfsPosition(void *p, u32 *out);
extern void MCSS_SetPosition(void *p, u32 *src);
extern void MCSS_SetOfsPosition(void *p, u32 *src);
extern void MCSS_SetVanishFlag(void *h);

void BTLV_MCSS_ResetSpritePosition(Work *w, int key)
{
    Vec want;
    Vec cur;
    Vec off;
    int i = BTLV_MCSS_FindSpriteIndex((char *)w, key);

    if (i == -1)
        return;
    if (w->e[i].h == 0)
        return;
    BTLV_MCSS_CalcSlotPosition(w, &want, key);
    MCSS_GetPosition(w->e[i].h, (u32 *)(&cur));
    MCSS_GetOfsPosition(w->e[i].h, (u32 *)(&off));
    w->e[i].flags &= ~0x40;
    if (want.x == cur.x && want.y == cur.y && want.z == cur.z
        && off.x == 0 && off.y == 0 && off.z == 0)
        return;
    w->e[i].flags |= 0x40;
    off.x = 0;
    off.y = 0;
    off.z = 0;
    MCSS_SetPosition(w->e[i].h, (u32 *)(&want));
    MCSS_SetOfsPosition(w->e[i].h, (u32 *)(&off));
    MCSS_SetVanishFlag(w->e[i].h);
}
