/*
 * function: func_021C8784
 * address:  0x021C8784
 * packet:   pkt_021C8784
 * region:   ov128
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *
 * Addresses are Black-image addresses.
 */

extern void *func_02045770(void *);
extern void func_02043B5C(void *, int);
extern void func_02045334(void *);

void func_021C8784(char *p)
{
    func_02043B5C(func_02045770(*(void **)(p + 0x108)), 0xf);
    func_02045334(*(void **)(p + 0x108));
}
