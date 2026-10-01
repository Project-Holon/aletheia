/*
 * function: func_021BD394
 * address:  0x021BD394
 * packet:   pkt_ov021_021BD394
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BD304  0x021BD304  thumb  ov021
 *   func_021BD2D8  0x021BD2D8  thumb  ov021
 */

typedef struct {
    char pad[0x2C];
    int f;
} Inner;

extern Inner *func_021BD304(void *p);
extern int func_021BD2D8(void *p);

int func_021BD394(void *p)
{
    Inner *q = func_021BD304(p);

    if (func_021BD2D8(p) == 0) {
        return 1;
    }
    if (q->f <= 0) {
        return 1;
    }
    return 0;
}
