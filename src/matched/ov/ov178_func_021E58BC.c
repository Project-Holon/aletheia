/*
 * function: func_021E58BC
 * address:  0x021E58BC
 * packet:   pkt_021E58BC
 * region:   ov178
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021E58F4  0x021E58F4  thumb  ov178
 *   func_021E5A90  0x021E5A90  thumb  ov178
 */
typedef unsigned int u32;

extern int func_021E58F4(char **out, u32 *ctx, u32 *state);
extern unsigned func_021E5A90(void **d, unsigned *c, unsigned *state);

int func_021E58BC(u32 a, u32 b, u32 *c, void *d)
{
    u32 r;

    switch (c[1]) {
    case 0:
        r = func_021E58F4(d, c, (u32 *)b);
        break;
    case 1:
        r = func_021E5A90(d, c, (unsigned int *)b);
        break;
    }
    return r != 0;
}
