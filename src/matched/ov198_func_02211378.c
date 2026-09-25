/*
 * function: func_02211378
 * address:  0x02211378
 * packet:   pkt_02211378
 * region:   ov198
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_0220C688 0x0220C688 thumb
 *   func_0220E27C 0x0220E27C thumb
 */

extern void func_0201F7A8(void *, int);
extern void func_0220C688(void *);
extern void func_0220E27C(void *);

int func_02211378(char *p)
{
    func_0201F7A8(*(void **)(p + 0x1f68), 0);
    func_0220C688(p);
    func_0220E27C(p);
    return 8;
}
