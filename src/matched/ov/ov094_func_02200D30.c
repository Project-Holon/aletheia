/*
 * function: BTLV_MCSS_BlinkTaskEnd
 * address:  0x02200D30
 * packet:   pkt_ov094_02200D30
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TCBL_IsDeletePending  0x02030EE8  arm
 *   BTLV_EFFECT_GetBitMask  0x021F935C  thumb  ov094
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
    char pad[0x528 - 0x008 - 14 * 0x5c];
    unsigned int mask;      /* 0x528 */
    char pad52c[0x588 - 0x52c];
    u8 tag[1];              /* 0x588 */
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
struct S02030EE8;
extern u32 TCBL_IsDeletePending(struct S02030EE8 *p);
extern int BTLV_EFFECT_GetBitMask(int x);

void BTLV_MCSS_BlinkTaskEnd(void *h)
{
    Ctx *c = (Ctx *)TCBL_IsDeletePending(h);

    if (c->tag == c->w->tag[c->key])
        c->w->mask &= BTLV_EFFECT_GetBitMask(c->key) ^ 0xFFFFFFFF;
}
