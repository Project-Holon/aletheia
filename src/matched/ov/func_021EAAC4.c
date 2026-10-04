/*
 * function: func_021EAAC4
 * address:  0x021EAAC4
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *
 * Walk 0x1c 8-byte records at p+0x2c+0x94, release each, then
 *   release the pool.  Unsigned counter for the image's blo.
 */


struct Descriptor;
extern void func_020452E8(struct Descriptor *d);
extern void func_020450C8(void);
void func_021EAAC4(char *p)
{
    unsigned i;
    for (i = 0; i < 0x1c; i++)
        func_020452E8((struct Descriptor *)(*(int *)(*(int *)(p + 0x2c) + i * 8 + 0x94)));
    func_020450C8();
}
