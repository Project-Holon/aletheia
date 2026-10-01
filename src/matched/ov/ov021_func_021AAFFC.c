/*
 * function: func_021AAFFC
 * address:  0x021AAFFC
 * packet:   pkt_ov021_021AAFFC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021AC154  0x021AC154  thumb
 */

typedef struct {
    char pad[0x5b4];
    int f5b4;
} D;

extern void func_021AC154(int a);

void func_021AAFFC(D *d)
{
    if (d->f5b4 != 0) {
        func_021AC154(d->f5b4);
        d->f5b4 = 0;
    }
}
