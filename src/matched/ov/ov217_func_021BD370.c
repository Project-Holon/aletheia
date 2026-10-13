/*
 * function: func_021BD370
 * address:  0x021BD370
 * packet:   pkt_021BD370
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_Delete  0x020437AC  arm
 *
 * Addresses are Black-image addresses.
 */

struct Obj020437AC;
extern void BMP_Delete(struct Obj020437AC *p);

void func_021BD370(int *p)
{
    int i;
    for (i = 0; i < 4; i++)
        BMP_Delete((struct Obj020437AC *)p[i + 0x50]);
}
