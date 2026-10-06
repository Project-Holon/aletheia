/*
 * function: func_021BB5FC
 * address: 0x021BB5FC
 * packet: pkt_ov093_021BB5FC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * output: EE8D8 has no branch or forwarding call; it stores 2 through r1
 * at 021EE8EC on every path and returns p+4 at 021EE8EE..021EE8F0.
 * symbols:
 *   func_021EE8B4 0x021EE8B4 thumb ov093
 *   func_021EE8D8 0x021EE8D8 thumb ov093
 *   func_021BB724 0x021BB724 thumb ov093
 */

typedef unsigned char u8;
extern void func_021EE8B4(u8 *, int);
typedef unsigned int   u32;
extern u8 *func_021EE8D8(u8 *p, u32 *out, int flag);
extern void func_021BB724(u8 *, int, int, int);
int func_021BB5FC(u8 *p, int b)
{
 int n;
 int r;
 func_021EE8B4(p + 0x68, 1);
 r = (int)func_021EE8D8(p + 0x68, (u32 *)(&n), b);
 func_021BB724(p, 10, r, n);
 return 1;
}
