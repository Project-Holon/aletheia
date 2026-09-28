/*
 * function: func_02012F98
 * address:  0x02012F98
 * packet:   pkt_02012F98
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf: tail-calls func_02007B44(*(void **)p).
 *
 * symbols:
 *   func_02012F98  0x02012F98  thumb
 *   func_02007B44  0x02007B44  thumb
 */

extern void func_02007B44(void *p);

void func_02012F98(void *p)
{
    func_02007B44(*(void **)p);
}
