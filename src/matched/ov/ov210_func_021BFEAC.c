/*
 * function: func_021BFEAC
 * address: 0x021BFEAC
 * packet: pkt_ov210_021BFEAC
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020355C4 0x020355C4 arm
 *   func_02025CD0 0x02025CD0 thumb
 *   func_021BFF30 0x021BFF30 thumb ov210
 *   func_02025D1C 0x02025D1C thumb
 *   d_021C0B60 0x021C0B60 data a4
 *   d_021C0B14 0x021C0B14 data a4
 */
extern const unsigned d_021C0B60[], d_021C0B14[];
extern unsigned char func_020355C4(void);
extern void *func_02025CD0(unsigned, unsigned, unsigned, unsigned, unsigned char, unsigned short);
extern void func_021BFF30(int, unsigned, unsigned);
extern void func_02025D1C(void *);
void func_021BFEAC(char *ctx, int index)
{
    if (func_020355C4() == 1) {
        *(void **)(ctx + 0x2b0) = func_02025CD0((unsigned)d_021C0B60, (unsigned)d_021C0B14, (unsigned)ctx, 0, index, 123);
    } else {
        *(void **)(ctx + 0x2b0) = func_02025CD0((unsigned)d_021C0B60, (unsigned)d_021C0B14, (unsigned)ctx, 1, index, 123);
        func_021BFF30((int)ctx, index, 3);
    }
    func_02025D1C(*(void **)(ctx + 0x2b0));
}
