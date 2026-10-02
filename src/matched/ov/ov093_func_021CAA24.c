/*
 * function: func_021CAA24
 * address: 0x021CAA24
 * packet: pkt_ov093_021CAA24
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: 021CAA56..021CAA58 is zero alignment padding.
 * symbols:
 *   func_021D80BC 0x021D80BC thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_021D80BC(void *, int, int, u16);
int func_021CAA24(u8 *p, u8 *q, int m, int n, int value)
{
    if (*(u16 *)q == 174) {
        if (*(int *)(q + 12) == 0) {
            if (n == value || value == 6)
                return func_021D80BC(*(void **)(p + 4), *(int *)(p + 8), m, 174);
        } else if (*(int *)(q + 12) == 7 && n != value) {
            value = n;
        }
    }
    return value;
}
