/*
 * function: func_021BDC20
 * address: 0x021BDC20
 * packet: pkt_ov203_021BDC20
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BE948 0x021BE948 thumb ov203
 *   func_02022268 0x02022268 thumb
 *   func_0204E6E0 0x0204E6E0 arm
 *   func_0202208C 0x0202208C thumb
 */
extern void func_021BE948(void *, unsigned char, unsigned char *, unsigned char *);
extern void func_02022268(unsigned);
extern unsigned func_0204E6E0(void);
extern void func_0202208C(void *, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
int func_021BDC20(void *ctx, unsigned mode, unsigned heap)
{
    unsigned char width, height;
    unsigned char factor;
    int color;
    func_021BE948(ctx, mode == 0, &width, &height);
    color = 0;
    if (width) color = 32767;
    func_02022268(color);
    if (height) {
        factor = func_0204E6E0();
        func_0202208C(0, mode, mode, color, height * factor, 1, heap);
        return 0;
    }
    return 1;
}
