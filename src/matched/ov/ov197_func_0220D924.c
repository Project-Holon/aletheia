/*
 * function: func_0220D924
 * address: 0x0220D924
 * packet: pkt_ov197_0220D924
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: an outer switch preserves the unconditional default-arm branch.
 * symbols:
 *   func_0220D914 0x0220D914 thumb ov197
 *   func_0220D8C4 0x0220D8C4 thumb ov197
 */
typedef unsigned char u8;
typedef signed short s16;
extern unsigned int func_0220D914(u8 *);
extern void func_0220D8C4(u8 *, int, int);
void func_0220D924(u8 *p, int state, int value)
{
    switch (*(int *)(p + 0x598)) {
    case 0: value = 0; break;
    default:
        switch (state) {
        case 0: value = p[0x533]; break;
        case 1: value = *(s16 *)(*(char **)p + p[0x533] * 2 + 0x30); break;
        case 2: value = 0; break;
        }
        break;
    }
    func_0220D914(p);
    func_0220D8C4(p, state, value);
}
