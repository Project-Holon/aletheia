/*
 * function: func_021FD04C
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
 *   func_021F7F1C  0x021F7F1C  thumb  ov094
 */
typedef struct {
    unsigned int bit0 : 1;
} Unit;

extern int func_021F7F1C(int i);

int func_021FD04C(Unit *s, int i)
{
    if (func_021F7F1C(i) == 1) {
        if (s->bit0)
            i ^= 1;
    } else {
        i = 0xff;
    }
    return i;
}
