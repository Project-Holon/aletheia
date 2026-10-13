/*
 * function: BTL_CLIENT_CmdPpMinusWorking
 * address: 0x021D3734
 * packet: pkt_ov093_021D3734
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_SIDE_GetPokeByIdThunk 0x021B9934 thumb ov093
 *   BTL_POKEPARAM_DecrementRealMovePP 0x021D5640 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
struct Work;
extern void BTL_POKEPARAM_DecrementRealMovePP(struct Work *p, u32 i, u32 n);
int BTL_CLIENT_CmdPpMinusWorking(u32 *a, int b, u32 *c)
{
    u8 *m;
    u8 k, n;
    k = c[1];
    n = c[2];
    m = BTL_SIDE_GetPokeByIdThunk((char *)a[1], (u8)c[0]);
    BTL_POKEPARAM_DecrementRealMovePP((struct Work *)m, k, n);
    return 1;
}
