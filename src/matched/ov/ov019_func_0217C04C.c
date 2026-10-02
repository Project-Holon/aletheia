/*
 * function: func_0217C04C
 * address: 0x0217C04C
 * packet: pkt_ov019_0217C04C
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020061E4 0x020061E4 thumb
 *   func_0217F210 0x0217F210 thumb ov019
 *   func_0217BAF0 0x0217BAF0 thumb ov019
 */
typedef unsigned int u32;
extern void func_020061E4(u32 id);
extern void func_0217F210(void *ctx, int a, int msg);
extern void func_0217BAF0(void *ctx, int a, int v);
int func_0217C04C(void *ctx, void *unused, int a)
{
    func_020061E4(0x806);
    func_0217F210(ctx, a, 7);
    func_0217BAF0(ctx, a, 1);
    return 1;
}
