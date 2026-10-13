/*
 * function: BTL_CLIENT_CmdPpPlusWorking
 * address: 0x021D37B8
 * packet: pkt_ov093_021D37B8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_SIDE_GetPokeByIdThunk 0x021B9934 thumb ov093
 *   BTL_POKEPARAM_RestoreRealMovePP 0x021D56A0 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
extern u16 BTL_POKEPARAM_RestoreRealMovePP(u8 *p, u32 i, u8 n);
int BTL_CLIENT_CmdPpPlusWorking(u32 *a, int b, u32 *c)
{
    u8 *m;

    m = BTL_SIDE_GetPokeByIdThunk((char *)a[1], (u8)c[0]);
    BTL_POKEPARAM_RestoreRealMovePP(m, (u8)c[1], c[2]);
    return 1;
}
