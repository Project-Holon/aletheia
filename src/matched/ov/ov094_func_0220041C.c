/*
 * function: BTLV_MCSS_SetAnimIndexIfValid
 * address:  0x0220041C
 * packet:   pkt_ov094_0220041C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * 2026-10-01: the arm9 witness leaves named below are now filed in
 * src/matched/arm9, which closes the former MATCH.
 *
 * symbols:
 *   MCSS_GetAnimSeqNumEx  0x020160CC  thumb
 *   MCSS_SetAnimeIndex   0x02016028  thumb
 *   BTLV_MCSS_FindSpriteIndex  0x022019F4  thumb  ov094
 *
 * MATCH: bytes identical (one prints MATCH*); blocked on 0x020160CC, an
 * unfiled unlabelled ARM9 Thumb leaf (the integrator's) with no witness outside this
 * range. Verified C for it (EXACT, `one --thumb`, no --region, cc 1.1p1,
 * -O4,p; packet pkt_020160CC, 64 B extent):
 *
 *   typedef unsigned short u16;
 *   typedef struct { char pad[0x28]; u16 *p28; } S;
 *   u16 MCSS_GetAnimSeqNumEx(S *s) { return *s->p28; }
 *
 * The extern here takes `int` as return type (u16 not needed at the caller).
 */
typedef unsigned int u32;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x40];
    int f44;                /* 0x44 */
    char pad48[0x14];
} Entry;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry e[14];            /* 0x008 */
} Work;

extern int BTLV_MCSS_FindSpriteIndex(char *p, int key);
extern int MCSS_GetAnimSeqNumEx(void *h);
extern void MCSS_SetAnimeIndex(void *h, u32 n);

int BTLV_MCSS_SetAnimIndexIfValid(Work *w, int key, int n)
{
    int r = 0;
    int i = BTLV_MCSS_FindSpriteIndex((char *)w, key);

    if (i == -1)
        return 0;
    if (w->e[i].h == 0)
        return 0;
    if (n < MCSS_GetAnimSeqNumEx(w->e[i].h)) {
        MCSS_SetAnimeIndex(w->e[i].h, n);
        r = 1;
        w->e[i].f44 = r;
    }
    return r;
}
