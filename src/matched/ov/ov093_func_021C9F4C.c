/*
 * function: func_021C9F4C
 * address: 0x021C9F4C
 * packet: pkt_ov093_021C9F4C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021C0780 0x021C0780 thumb ov093
 */
typedef unsigned char u8;
extern int func_021B9934(char *, int);
extern void func_021C0780(u8 *, u8 *, int, u8);
int func_021C9F4C(u8 *p, u8 *q)
{
    int a = func_021B9934(*(char **)(p + 8), q[4]);
    func_021C0780(p, (u8 *)a, q[5], q[6]);
    return 1;
}
