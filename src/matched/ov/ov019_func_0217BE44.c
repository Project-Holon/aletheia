/*
 * function: func_0217BE44
 * address: 0x0217BE44
 * packet: pkt_ov019_0217BE44
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020061E4 0x020061E4 thumb
 *   func_0217F210 0x0217F210 thumb ov019
 */
typedef unsigned int u32;
extern void func_020061E4(u32 id);
extern void func_0217F210(void *ctx, int a, int msg);
int func_0217BE44(void *ctx, void *unused, int a)
{
    func_020061E4(0x547);
    func_0217F210(ctx, a, 0xE2);
    return 1;
}
