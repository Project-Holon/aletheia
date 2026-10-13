/*
 * function: func_021FFB04
 * address:  0x021FFB04
 * packet:   pkt_ov094_021FFB04
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_02030734   0x02030734  arm
 *   func_02030DA8  0x02030DA8  arm
 *   MCSS_GetPosition  0x02015C30  thumb
 *   func_021F896C  0x021F896C  thumb  ov094
 *   func_021F935C  0x021F935C  thumb  ov094
 *   func_022010D0  0x022010D0  thumb  ov094
 *   func_022011FC  0x022011FC  thumb  ov094
 *   func_022019F4  0x022019F4  thumb  ov094
 *   d_0220AE7C     0x0220AE7C  data   ov094  a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x5c - 4];
} Entry;

typedef struct {
    void *owner;            /* 0x000 */
    void *obj;              /* 0x004 */
    Entry e[14];            /* 0x008 */
    char pad510[0x514 - 0x510];
    int mask[6];            /* 0x514 */
    char pad52c[0x540 - 0x52c];
    u16 heap;               /* 0x540 */
    u8 cnt[6][14];          /* 0x542 */
} Work;

typedef struct {
    Work *w;                /* 0x00 */
    int key;                /* 0x04 */
    int v[3];               /* 0x08 */
    char pad14[0x14];
    int f28;                /* 0x28 */
} Obj;

extern const char d_0220AE7C[];
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_02030DA8(void *owner, void *fn, void *p, u32 a3);
extern void MCSS_GetPosition(void *p, u32 *out);
extern void func_021F896C(void *h, void (*cb)(void *), int arg);
extern int func_021F935C(int x);
extern void func_022010D0(void *task, char *q);
extern void func_022011FC(void *p);
extern int func_022019F4(char *p, int key);

void func_021FFB04(Work *w, Obj *s)
{
    Obj *o = sub_02030734((u16)((w->heap & 0x7fff) | 0x8000), 0x2c, 0, d_0220AE7C, 0x660);
    int idx = func_022019F4((char *)w, s->key);

    if (idx == -1)
        return;
    if (w->e[idx].h == 0)
        return;
    *o = *s;
    o->w = w;
    MCSS_GetPosition(w->e[idx].h, (u32 *)o->v);
    w->cnt[0][o->key]++;
    o->f28 = w->cnt[0][o->key];
    func_021F896C(func_02030DA8(w->owner, (void *)func_022010D0, o, 0), func_022011FC, 2);
    w->mask[0] |= func_021F935C(o->key);
}
