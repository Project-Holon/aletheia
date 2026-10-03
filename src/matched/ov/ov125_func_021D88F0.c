/*
 * function: func_021D88F0
 * address: 0x021D88F0
 * packet: pkt_ov125_021D88F0
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: EXACT
 * symbols:
 *   func_021D7A10 0x021D7A10 arm ov125
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct {int a,b;} Pair;
extern int func_021D7A10(int, const void *, int, int);
int func_021D88F0(int a, int b, int n)
{
    Pair p;
    p.a=a; p.b=b;
    return func_021D7A10(0x55f3, &p, n, -1);
}
