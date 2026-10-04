/*
 * function: func_021F4510
 * address: 0x021F4510
 * packet: pkt_ov055_021F4510
 * region: ov055
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F45E0 0x021F45E0 data a1
 *   d_021F45D0 0x021F45D0 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern const u8 d_021F45E0[];
extern const u8 d_021F45D0[];
typedef struct S {
    u16 a;
    u8 b;
    u8 c;
    u16 d;
    u16 e;
} S;
void func_021F4510(S *p, int i)
{
    p->a = 0;
    p->b = d_021F45E0[i];
    p->c = d_021F45D0[i];
    p->d = i;
    p->e = 0;
}
