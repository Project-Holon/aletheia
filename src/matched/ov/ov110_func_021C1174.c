/*
 * function: func_021C1174
 * address: 0x021C1174
 * packet: pkt_ov110_021C1174
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Extent ends with two bytes of zero padding at 0x021C11B6.
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 */
extern unsigned func_02045770(void *);
extern int func_0201C6C4(unsigned, unsigned);
typedef unsigned char  u8;
struct Cfg;
struct Descriptor;
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(unsigned);
int func_021C1174(unsigned owner, void *p, int *state) {
    unsigned q = func_02045770(p);
    if (*state == 1 && func_0201C6C4(owner, q) == 0) {
        func_02045334(p);
        func_02045374(p);
        func_02041B6C(func_02045730(p));
        *state = 0;
        return 1;
    }
    return 0;
}
