/*
 * function: func_021FBD78
 * address: 0x021FBD78
 * packet: pkt_ov132_021FBD78
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * note: inferred extent ends with two zero padding bytes before the next labelled function.
 * symbols:
 *   func_0201134C 0x0201134C thumb
 */
typedef unsigned char u8;
extern int func_0201134C(void *);
int func_021FBD78(int unused, char *p)
{
    int a, b, c, d;
    a = func_0201134C(*(void **)(p + 4));
    b = func_0201134C(*(void **)(p + 4));
    c = func_0201134C(*(void **)(p + 4));
    d = func_0201134C(*(void **)(p + 4));
    *(u8 *)(p + 0x18) = 0;
    if (a == 1) *(u8 *)(p + 0x18) += 1;
    if (b == 1) *(u8 *)(p + 0x18) += 2;
    if (c == 1) *(u8 *)(p + 0x18) += 4;
    if (d == 1) *(u8 *)(p + 0x18) += 8;
    return 0;
}
