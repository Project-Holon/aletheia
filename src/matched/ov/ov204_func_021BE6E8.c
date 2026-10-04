/*
 * function: func_021BE6E8
 * address:  0x021BE6E8
 * packet:   pkt_021BE6E8
 * region:   ov204
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BD374 0x021BD374 thumb ov088
 *
 * UNBLOCKED: 0x021BD374 is now an EXACT entry in layout/matched/ov088 (the
 * only overlay in the window that does not overlap the caller's ov204), so
 * the bl site resolves as matched and the verdict promoted to EXACT.
 */

extern void func_021BD374(unsigned char *p);

int func_021BE6E8(char *a)
{
    func_021BD374((unsigned char *)(*(int *)(a + 0xa4)));
    return 1;
}
