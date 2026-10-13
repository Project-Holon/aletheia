/*
 * function: func_022009C8
 * address:  0x022009C8
 * packet:   pkt_ov094_022009C8
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
 * symbols:
 *   MCSS_GetShadowScale  0x02015CC4  thumb
 *   MCSS_SetShadowScale  0x02015CDC  thumb
 *   func_021F89BC  0x021F89BC  thumb  ov094
 *   func_021F9260  0x021F9260  thumb  ov094
 *   func_022019F4  0x022019F4  thumb  ov094
 *
 * MATCH: bytes identical; blocked on two unfiled ARM9 Thumb leaves (the integrator's),
 * no witness outside this range. Verified C, each EXACT with `one --thumb`
 * and no --region (cc 1.1p1, -O4,p), packets pkt_02015CC4 / pkt_02015CDC:
 *
 *   typedef unsigned int u32;
 *   void MCSS_GetShadowScale(void *p, u32 *out)   // 0x02015CC4, 64 B extent
 *   {
 *       out[0] = *(u32 *)((char *)p + 0x128);
 *       out[1] = *(u32 *)((char *)p + 0x12C);
 *       out[2] = *(u32 *)((char *)p + 0x130);
 *   }
 *   void MCSS_SetShadowScale(void *p, u32 *src)  // 0x02015CDC, inverse
 *   {
 *       *(u32 *)((char *)p + 0x128) = src[0];
 *       *(u32 *)((char *)p + 0x12C) = src[1];
 *       *(u32 *)((char *)p + 0x130) = src[2];
 *   }
 *
 * Task callback, twin of func_02200A84.
 */
typedef unsigned char u8;
typedef int fx32;

typedef struct {
    fx32 x, y, z;
} VecFx32;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x58];
} Entry;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry e[14];            /* 0x008 */
    char pad[0x550 - 0x008 - 14 * 0x5c];
    u8 tag[1];              /* 0x550 */
} Work;

typedef struct {
    char body[0x3c];
} Mover;

typedef struct {
    Work *w;                /* 0x00 */
    int key;                /* 0x04 */
    char pad08[0x0c];
    Mover mv;               /* 0x14 */
    int tag;                /* 0x50 */
} Ctx;

typedef unsigned int   u32;
extern void MCSS_GetShadowScale(void *p, u32 *out);
extern void MCSS_SetShadowScale(void *p, u32 *src);
extern void func_021F89BC(void *h);
extern int func_021F9260(Mover *m, VecFx32 *out);
extern int func_022019F4(char *p, int key);

void func_022009C8(void *h, Ctx *c)
{
    Work *w = c->w;
    int i = func_022019F4((char *)w, c->key);
    VecFx32 v;
    int r;

    if (i == -1) {
        func_021F89BC(h);
        return;
    }
    if (w->e[i].h == 0) {
        func_021F89BC(h);
        return;
    }
    if (c->tag != w->tag[c->key]) {
        func_021F89BC(h);
        return;
    }
    MCSS_GetShadowScale(w->e[i].h, (u32 *)(&v));
    r = func_021F9260(&c->mv, &v);
    MCSS_SetShadowScale(w->e[i].h, (u32 *)(&v));
    if (r == 1)
        func_021F89BC(h);
}
