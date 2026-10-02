/*
 * function: func_021C334C
 * address: 0x021C334C
 * packet: pkt_ov093_021C334C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C3394 0x021C3394 thumb ov093
 *   func_021C33E8 0x021C33E8 thumb ov093
 */
typedef unsigned char u8;
extern int func_021C3394(u8 *, u8 *, int);
extern void func_021C33E8(int, int, int);
int func_021C334C(u8 *p, u8 *q, int a, int b)
{
    if (func_021C3394(p, q, b) == 0) {
        func_021C33E8((int)p, (int)q, a);
        return 1;
    }
    return 0;
}
