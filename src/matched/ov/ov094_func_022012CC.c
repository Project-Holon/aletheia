/*
 * function: func_022012CC
 * address:  0x022012CC
 * packet:   pkt_ov094_022012CC
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030EE8  0x02030EE8  arm
 *   func_021F935C  0x021F935C  thumb  ov094
 *
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
    char pad[0x530 - 0x008 - 14 * 0x5c];
    unsigned int mask;      /* 0x530 */
    char pad534[0x5a4 - 0x534];
    u8 tag[1];              /* 0x5a4 */
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

extern Ctx *func_02030EE8(void *h);
extern int func_021F935C(int x);

void func_022012CC(void *h)
{
    Ctx *c = func_02030EE8(h);

    if (c->tag == c->w->tag[c->key])
        c->w->mask &= func_021F935C(c->key) ^ 0xFFFFFFFF;
}
