/*
 * function: BTLV_EFFVM_ResolveSide
 * address:  0x021FD04C
 * packet:   pkt_021FD1CC
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_EFFECT_IsPokeSpriteLoaded  0x021F7F1C  thumb  ov094
 */
typedef struct {
    unsigned int bit0 : 1;
} Unit;

extern int BTLV_EFFECT_IsPokeSpriteLoaded(int i);

int BTLV_EFFVM_ResolveSide(Unit *s, int i)
{
    if (BTLV_EFFECT_IsPokeSpriteLoaded(i) == 1) {
        if (s->bit0)
            i ^= 1;
    } else {
        i = 0xff;
    }
    return i;
}
