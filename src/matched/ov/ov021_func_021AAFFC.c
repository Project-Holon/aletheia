/*
 * function: EFFECT_ENCOUNT_DeleteEffectObj
 * address:  0x021AAFFC
 * packet:   pkt_ov021_021AAFFC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_EFFECT_DeleteObject  0x021AC154  thumb
 */

typedef struct {
    char pad[0x5b4];
    int f5b4;
} D;

extern void FIELD_EFFECT_DeleteObject(int a);

void EFFECT_ENCOUNT_DeleteEffectObj(D *d)
{
    if (d->f5b4 != 0) {
        FIELD_EFFECT_DeleteObject(d->f5b4);
        d->f5b4 = 0;
    }
}
