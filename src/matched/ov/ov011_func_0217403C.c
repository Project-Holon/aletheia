/*
 * function: func_0217403C
 * address: 0x0217403C
 * packet: pkt_ov011_0217403C
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203D378 0x0203D378 arm
 *   func_02175C88 0x02175C88 thumb ov011
 */
typedef unsigned char u8;
typedef unsigned int u32;
int func_0203D378(void);
typedef struct Rec { u32 w[13]; } Rec;
int func_02175C88(u8 *a, Rec *b, int c);

void func_0217403C(int a, int b, void *c, u8 *d)
{
    if (func_0203D378()) func_02175C88(d + 0x1ac, c, a);
}
