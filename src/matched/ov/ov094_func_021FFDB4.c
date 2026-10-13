/*
 * function: func_021FFDB4
 * address:  0x021FFDB4
 * packet:   pkt_ov094_021FFDB4
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MCSS_SetPaletteFade  0x02015F50  thumb
 *   func_022019F4  0x022019F4  thumb  ov094
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;

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

extern int func_022019F4(char *p, int key);
typedef signed int     s32;
struct McssFade;
extern void MCSS_SetPaletteFade(struct McssFade *w, u32 cur, u32 target, s32 step, u32 e);

void func_021FFDB4(Work *w, int key, u8 cur, u8 target, s8 step, u32 e)
{
    int idx = func_022019F4((char *)w, key);

    if (idx == -1)
        return;
    if (w->e[idx].h == 0)
        return;
    MCSS_SetPaletteFade(w->e[idx].h, cur, target, step, e);
    w->e[idx].flags |= 0x100;
}
