/*
 * function: func_021B976C
 * address:  0x021B976C
 * packet:   pkt_ov021_021B976C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B9768  0x021B9768  thumb  ov021
 */

typedef struct {
    char pad[0x30];
    char f30[1];
} Obj;

extern void func_021B9768(void *a, void *b);

void func_021B976C(void *a, Obj *b)
{
    if (b != 0) {
        func_021B9768(a, b->f30);
    }
}
