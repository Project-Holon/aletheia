/*
 * function: BTLV_MCSS_Create
 * address:  0x021FEAC0
 * packet:   pkt_ov094_021FEAC0
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
 * Lever: `u16 a2` (the strh of the heap id makes the parameter 16-bit; it
 * is spilled at entry and reloaded, as the image does).
 *
 * Blocker: two unlabelled arm9 Thumb leaves (relocation wildcards, no
 * witness outside the range): MCSS_SetDepthStep (0x020163B0) and MCSS_SetNearDepthRange
 * (0x020163B4).  Both are the integrator's; verified C (one --thumb, no --region,
 * EXACT each):
 *     void MCSS_SetDepthStep(char *p, int v) { *(int *)(p + 0x48) = v; }
 *     typedef struct { char pad[0x2c]; unsigned int b0 : 1; unsigned int b1 : 1; } Obj;
 *     void MCSS_SetNearDepthRange(Obj *p, int v) { p->b1 = v; }
 * Re-run this file once layout/matched/arm9 shards for both exist.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   MCSS_Init  0x02014B08  thumb
 *   MCSS_SetDepthStep  0x020163B0  thumb
 *   MCSS_SetNearDepthRange  0x020163B4  thumb
 *   gBtlvMcssSourceFileName     0x0220AE7C  data   ov094
 */
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    void *h;
    char pad04[0x44];
    int k48;
    unsigned int f0 : 1;
    unsigned int f1 : 1;
    unsigned int flip : 1;
    char pad50[0x0c];
} Entry;
typedef struct {
    unsigned int b0 : 1;
    unsigned int b1 : 1;
} Flags;
typedef struct {
    int *cb;                /* 0x000 */
    void *obj;              /* 0x004 */
    Entry e[14];            /* 0x008 */
    Flags flags;            /* 0x510 */
    char pad514[0x534 - 0x514];
    int active;             /* 0x534 */
    int scaleEven;          /* 0x538 */
    int scaleOdd;           /* 0x53c */
    u16 heap;               /* 0x540 */
} Work;

extern char gBtlvMcssSourceFileName[];
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *MCSS_Init(u32 id, void *heap);
extern void MCSS_SetDepthStep(char *p, int v);
extern void MCSS_SetNearDepthRange(void *o, int v);

Work *BTLV_MCSS_Create(int mode, int a1, u16 a2)
{
    Work *w;
    int v = 0xe;
    int i;

    w = func_02030734(a2, 0x5b4, 1, gBtlvMcssSourceFileName, 0x184);
    w->obj = MCSS_Init(v, (void *)a2);
    w->cb = (int *)a1;
    w->heap = a2;
    v += 0xf2;
    MCSS_SetDepthStep(w->obj, v);
    MCSS_SetNearDepthRange(w->obj, 1);
    w->active = 1;
    w->scaleEven = 0x1000;
    w->scaleOdd = 0x1000;
    w->flags.b0 = (mode == 2);
    w->flags.b1 = (mode == 3);
    for (i = 0; i < 14; i++)
        w->e[i].k48 = 0xff;
    return w;
}
