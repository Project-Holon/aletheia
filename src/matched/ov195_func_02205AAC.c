/*
 * function: func_02205AAC
 * address:  0x02205AAC
 * packet:   pkt_02205AAC
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02205B64 0x02205B64 thumb
 *   func_02205BD0 0x02205BD0 thumb
 */

extern void func_02205B64(void *);
extern void func_02205BD0(void *);

void func_02205AAC(int a, char *b)
{
    func_02205B64(b);
    func_02205BD0(b + 4);
}