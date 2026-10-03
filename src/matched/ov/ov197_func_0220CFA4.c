/*
 * function: func_0220CFA4
 * address: 0x0220CFA4
 * packet: pkt_ov197_0220CFA4
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: narrow value load then compound add before reading maximum fixes r0/r6 swap.
 * symbols:
 *   func_0220B520 0x0220B520 thumb ov197
 *   func_0220B584 0x0220B584 thumb ov197
 */
typedef signed char s8;
typedef unsigned char u8;
extern void func_0220B520(char *);
extern void func_0220B584(char *p);
int func_0220CFA4(char *p)
{
    unsigned index = *(u8 *)(p + 0x533);
    short *values = (short *)(*(char **)p + 0x38);
    s8 value = (s8)values[index];
    u8 maximum;
    value += *(s8 *)(p + 0x534);
    maximum = *(u8 *)(p + index + 0x539);
    if (value > maximum) value = 0;
    else if (value < 0) {
        values[index] = maximum;
        goto done;
    }
    values[index] = value;
done:
    func_0220B520(p);
    func_0220B584(p);
    return 12;
}
