/*
 * function: func_021BD36C
 * address:  0x021BD36C
 * packet:   pkt_ov021_021BD36C
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
    char pad[0x28];
    int f;
} Inner;

extern Inner *func_021BD304(void *p);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_021BD2D8(u8 *p);

int func_021BD36C(void *p)
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
