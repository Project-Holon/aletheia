/*
 * function: func_02193398
 * address:  0x02193398
 * packet:   pkt_ov021_02193398
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D14C4  0x021D14C4  thumb  ov021
 */

typedef struct { int w[0x41]; } B104;

struct Map021D14C4;
struct Plane021D14C4;
struct VecFx32_021D14C4;
extern void func_021D14C4(struct Plane021D14C4 *out, int idx, struct Map021D14C4 *map, struct VecFx32_021D14C4 *pos, int size, int base);

void func_02193398(B104 *dst, const int *src, void *c, int d, int e)
{
    func_021D14C4((struct Plane021D14C4 *)dst, 0, (struct Map021D14C4 *)((char *)src + src[2]), c, d, e);
    dst->w[0x40] = 1;
}
