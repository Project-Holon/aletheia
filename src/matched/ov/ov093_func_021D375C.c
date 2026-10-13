/*
 * function: BTL_CLIENT_CmdMarkMoveUsed
 * address: 0x021D375C
 * packet: pkt_ov093_021D375C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021B9934 0x021B9934 thumb ov093
 *   BTL_POKEPARAM_MarkMoveUsed 0x021D56CC thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 *func_021B9934(char *p, int i);
struct Work; extern void BTL_POKEPARAM_MarkMoveUsed(struct Work *, u8);
int BTL_CLIENT_CmdMarkMoveUsed(u32 *a, int b, u32 *c)
{
    u8 *m;
    u8 k;
    k = c[1];
    m = func_021B9934((char *)a[1], (u8)c[0]);
    BTL_POKEPARAM_MarkMoveUsed((struct Work *)m, k);
    return 1;
}
