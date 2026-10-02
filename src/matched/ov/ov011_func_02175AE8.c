/*
 * function: func_02175AE8
 * address: 0x02175AE8
 * packet: pkt_ov011_02175AE8
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * prototype: func_02173FF4 trailing input omitted: full matched body neither
 * reads nor forwards d; original caller supplies no r3 value.
 * symbols:
 *   func_021758B4 0x021758B4 thumb ov011
 *   func_02173FF4 0x02173FF4 thumb ov011
 */
typedef unsigned char u8;
extern int func_021758B4(u8 *p);
extern int func_02173FF4(int a, int b, int c);
void func_02175AE8(int ctx, u8 *p)
{
    u8 mask = p[0x19E];
    if (mask != 0) {
        if (func_02173FF4(ctx, func_021758B4(p), mask) == 1) p[0x19E] = 0;
    }
}
