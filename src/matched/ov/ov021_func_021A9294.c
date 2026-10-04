/*
 * function: func_021A9294
 * address:  0x021A9294
 * packet:   pkt_ov021_021A9294
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045334  0x02045334  arm
 */

typedef struct {
    int f0;
    int f4;
} S;

struct Descriptor;
extern void func_02045334(struct Descriptor *a);

void func_021A9294(int a, S *s)
{
    if (s->f0 == 1) {
        func_02045334((struct Descriptor *)s->f4);
    }
}
