/*
 * function: func_0218BA04
 * address:  0x0218BA04
 * packet:   pkt_ov021_0218BA04
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * symbols:
 *   func_0218BBD0  0x0218BBD0  thumb  ov021
 *   func_0218C4A0  0x0218C4A0  thumb  ov021
 */

/*
 * 2026-10-01: 2-instruction residue. The original stores y, x, -z in that
 * order and moves d into r3 just before the call; this C stores x, -z, then
 * schedules `adds r3, r7` early and y late. Statement-order, local-k and
 * w-first variants tried; inline Vec_Set is what fixed the load order.
 */
typedef struct {
    int x;
    int y;
    int z;
    unsigned short w;
    unsigned char hi;
    unsigned char lo;
} Src;

typedef struct {
    int k;
    int x;
    int y;
    int z;
    unsigned short w;
} Args;

int func_0218BBD0(void *p, unsigned int i);
void func_0218C4A0(void *p, int a, Args *args, int d);

static inline void Args_SetPos(Args *v, int x, int y, int z)
{
    v->x = x;
    v->y = y;
    v->z = z;
}

void func_0218BA04(void *p, int a, Src *s, int d)
{
    Args args;
    args.k = func_0218BBD0(p, (unsigned short)(s->lo + (s->hi << 8)));
    Args_SetPos(&args, s->x, s->y, -s->z);
    args.w = s->w;
    func_0218C4A0(p, a, &args, d);
}
