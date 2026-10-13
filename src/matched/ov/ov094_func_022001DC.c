/*
 * function: func_022001DC
 * address:  0x022001DC
 * packet:   pkt_ov094_022001DC
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_022019F4  0x022019F4  thumb  ov094
 *   MCSS_TOOL_SetSpindaSpotHook  0x020172AC  thumb
 *   MCSS_ReloadResource  0x02014CF8  thumb
 */

typedef struct {
    int w[9];
} Rec;

typedef struct {
    void *h;                /* 0x00 */
    Rec rec;                /* 0x04 */
    char pad28[0x0c];
    int k34;                /* 0x34 */
    char pad38[0x24];
} Entry;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry e[14];            /* 0x008 */
} Work;

struct Sub02014CF8Ctx;
struct Sub02014CF8Rec;
extern int func_022019F4(char *p, int key);
extern void MCSS_TOOL_SetSpindaSpotHook(int a0, int a1);
extern void MCSS_ReloadResource(void *a, struct Sub02014CF8Ctx *b, const struct Sub02014CF8Rec *c);

void func_022001DC(Work *w, int key, Rec *r)
{
    int idx = func_022019F4((char *)w, key);

    w->e[idx].rec = *r;
    MCSS_TOOL_SetSpindaSpotHook((int)w->obj, w->e[idx].k34);
    MCSS_ReloadResource(w->obj, w->e[idx].h, (const struct Sub02014CF8Rec *)(&w->e[idx].rec));
}
