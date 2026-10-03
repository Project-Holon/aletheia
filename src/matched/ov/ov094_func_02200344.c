/*
 * function: func_02200344
 * address:  0x02200344
 * packet:   pkt_ov094_02200344
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
 *   func_021F896C  0x021F896C  thumb  ov094
 *   func_02201408  0x02201408  thumb  ov094
 *   func_02201700  0x02201700  thumb  ov094
 *   d_0220AE7C     0x0220AE7C  data   ov094  a1
 */
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    void *owner;            /* 0x000 */
    char pad004[0x510 - 4];
    u32 flags;              /* 0x510 */
    char pad514[0x540 - 0x514];
    u16 heap;               /* 0x540 */
} Work;

typedef struct {
    Work *w;                /* 0x00 */
    u32 a : 31;             /* 0x04 */
    u32 flag : 1;
    int f8;                 /* 0x08 */
    int fc;                 /* 0x0c */
} Obj;

extern const char d_0220AE7C[];
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_02030DA8(void *owner, void *fn, void *p, u32 a3);
extern void func_021F896C(void *h, void (*cb)(void *), int arg);
extern void func_02201408(void *h);
extern void func_02201700(void *h);

void func_02200344(Work *w, int a, int b, int flag)
{
    Obj *o = sub_02030734((u16)((w->heap & 0x7fff) | 0x8000), 0x24, 0, d_0220AE7C, 0x8f2);

    o->w = w;
    o->a = 0;
    o->flag = flag;
    o->f8 = a;
    o->fc = b;
    w->flags |= 4;
    func_021F896C(func_02030DA8(w->owner, func_02201408, o, 0), func_02201700, 2);
}
