/*
 * function: func_0218C9C4
 * address:  0x0218C9C4
 * packet:   pkt_ov021_0218C9C4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * `__restrict` on pos lets mwcc keep pos[2] in a register across the
 * out->a/out->b stores and sink the out->a store past the pos[0] load
 * (see docs/idioms/a-restrict-position-parameter-sinks-a-store-past-the-next-load.md).
 */

typedef struct {
    int a;
    int b;
    int c;
    int d;
} Rect;

void func_0218C9C4(Rect *out, int *__restrict pos)
{
    out->a = pos[2] - 0x30000;
    out->b = pos[2] + 0x30000;
    out->c = pos[0] - 0x20000;
    out->d = pos[0] + 0x20000;
}
