/*
 * function: func_021EABA0
 * address:  0x021EABA0
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045374  0x02045374  arm  arm9
 *   func_02045730  0x02045730  arm  arm9
 *   func_02041B6C  0x02041B6C  arm  arm9
 *
 * Release both children of the object and then a global one.
 */

extern void func_02045374(void *);
extern void func_02045730(void *);
extern void func_02041B6C(void);

void func_021EABA0(void **p)
{
    func_02045374(*p);
    func_02045730(*p);
    func_02041B6C();
}

