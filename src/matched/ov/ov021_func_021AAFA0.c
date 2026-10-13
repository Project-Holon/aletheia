/*
 * function: EFFECT_ENCOUNT_ClearSpot
 * address:  0x021AAFA0
 * packet:   pkt_ov021_021AAFA0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012A38  0x02012A38  thumb
 *   EFFECT_ENCOUNT_DeleteEffectObj  0x021AAFFC  thumb
 *   func_02082BCC  0x02082BCC  arm
 */

typedef unsigned char u8;

typedef struct {
    u8 b[0x10];
} Sub;

typedef struct {
    u8 pad[0x10];
    Sub sub;
} T;

typedef struct {
    int pad[2];
    int f8;
} S;

typedef struct D D;

typedef unsigned int   u32;
struct BigObj;
extern u32 func_02012A38(const struct BigObj *p);
extern void EFFECT_ENCOUNT_DeleteEffectObj(D *d);
extern void func_02082BCC(void *p, int v, int n);

void EFFECT_ENCOUNT_ClearSpot(S *s, D *d)
{
    T *t = (T *)func_02012A38((const struct BigObj *)s->f8);
    EFFECT_ENCOUNT_DeleteEffectObj(d);
    func_02082BCC(&t->sub, 0, 0x10);
}
