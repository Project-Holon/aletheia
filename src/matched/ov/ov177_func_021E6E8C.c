/*
 * function: func_021E6E8C
 * address: 0x021E6E8C
 * packet: pkt_ov177_021E6E8C
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * lever: signed inner index cast keeps cleanup address apart from unsigned polling address.
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045334 0x02045334 arm
 */
extern unsigned func_02045770(void *);
extern int func_0201C6C4(void *, unsigned);
extern void func_02045334(void *);
int func_021E6E8C(unsigned char *p, void *mgr)
{
    unsigned i;
    int result = 1;
    for (i = 0; i < *(unsigned *)p; i++) {
        if (*(void **)(p + i * 4 + 4)) {
            unsigned char *e = p + i * 8;
            if (e[0x80] != 0) {
                if (func_0201C6C4(mgr, func_02045770(*(void **)(e + 0x7c))) == 0) {
                    func_02045334(*(void **)((unsigned)p + (int)i * 8 + 0x7c));
                    *(unsigned char *)((unsigned)p + (int)i * 8 + 0x80) = 0;
                }
            }
            result &= e[0x80] == 0;
        }
    }
    return result;
}
