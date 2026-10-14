/*
 * function: BTLV_EFFECT_CreateSetup
 * address:  0x021F73F0
 * packet:   pkt_ov094_021F73F0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_02030734   0x02030734  arm
 *   gBtlvEffectFileName     0x0220AC90  data   ov094  a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    int w[4];
} Q;

typedef struct {
    int f0;
    int f4;
    Q q;            /* 0x08 */
    u16 h[4];       /* 0x18 */
    int f20;
    int f24;
    int f28;
} Obj;

extern const char gBtlvEffectFileName[];
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

Obj *BTLV_EFFECT_CreateSetup(int a, int b, Q *q, int c, u16 *h, int e, int f, u16 heap)
{
    Obj *o;
    int i = 0;

    o = sub_02030734((u16)((heap & 0x7fff) | 0x8000), 0x2c, 0, gBtlvEffectFileName, 0xca);
    o->f0 = a;
    o->f4 = b;
    o->q = *q;
    o->f20 = c;
    o->f24 = f;
    o->f28 = e;
    for (; i < 4; i++)
        o->h[i] = h[i];
    return o;
}
