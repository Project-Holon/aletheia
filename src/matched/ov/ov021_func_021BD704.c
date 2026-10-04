/*
 * function: func_021BD704
 * address:  0x021BD704
 * packet:   pkt_ov021_021BD704
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A7E3C  0x021A7E3C  thumb  ov021
 *   func_02012374  0x02012374  thumb
 */

typedef unsigned int   u32;

struct Args;
struct Evt;
extern void *func_021A7E3C(struct Args *a);
extern void func_02012374(struct Evt *evt, struct Evt **out);

int func_021BD704(u32 a, int *st, u32 *ctx)
{
    u32 p = ctx[2];

    switch (*st) {
    case 0:
        func_02012374((struct Evt *)a, func_021A7E3C((struct Args *)p));
        (*st)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}
