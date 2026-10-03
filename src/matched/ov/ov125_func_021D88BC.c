/*
 * function: func_021D88BC
 * address: 0x021D88BC
 * packet: pkt_ov125_021D88BC
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
typedef struct {int a,b,c;} Triple;
extern int func_021D7A10(int, const void *, int, int);
int func_021D88BC(int a, int b, int c, int n)
{
    Triple p;
    p.a=a; p.b=b; p.c=c;
    return func_021D7A10(0x55f2, &p, n, -1);
}
