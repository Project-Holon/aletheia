/*
 * function: func_02015F40
 * address:  0x02015F40
 * packet:   pkt_02015F40
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02064D70  0x02064D70  arm
 */
extern void func_02064D70(void *, void *, unsigned);

void func_02015F40(char *p, unsigned flags, void *callback)
{
    func_02064D70(p + 0x68, callback, flags);
}
