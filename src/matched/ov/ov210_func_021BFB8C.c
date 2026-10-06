/*
 * function: func_021BFB8C
 * address: 0x021BFB8C
 * packet: pkt_ov210_021BFB8C
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: unsigned long slot keeps updates in its home; enum y keeps the wide updated value and repeats s16 call truncation. int/short variants sank or cached updates (110–118 B); check3b EXACT 108 B.
 * symbols:
 *   func_021BEDF0 0x021BEDF0 thumb ov210
 *   func_021BEE38 0x021BEE38 thumb ov210
 */
extern void func_021BEDF0(int p, int i, int v);
extern void func_021BEE38(char *p, int idx, int a, short b, unsigned short c);
typedef enum Y { YMin = -2147483647, YMax = 2147483647 } Y;
void func_021BFB8C(char *ctx, unsigned long slot, Y y, int flag)
{
    unsigned long second;
    if (flag == 1) {
        slot += 15;
        func_021BEDF0((int)ctx, (unsigned)slot, (unsigned)1);
        y += 20;
        func_021BEE38(ctx, (unsigned)slot, (unsigned short)204, y, 0);
    } else {
        second = slot + 29;
        func_021BEDF0((int)ctx, (unsigned)second, (unsigned)1);
        y += 20;
        func_021BEE38(ctx, (unsigned)second, (unsigned short)204, y, 1);
        slot += 43;
        func_021BEDF0((int)ctx, (unsigned)slot, (unsigned)1);
        func_021BEE38(ctx, (unsigned)slot, (unsigned short)204, y, 1);
    }
}
