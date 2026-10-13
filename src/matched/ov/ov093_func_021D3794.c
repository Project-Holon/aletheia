/*
 * function: BTL_CLIENT_CmdPpPlusOriginal
 * address: 0x021D3794
 * packet: pkt_ov093_021D3794
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_SIDE_GetPokeByIdThunk 0x021B9934 thumb ov093
 *   BTL_POKEPARAM_RestoreMovePP 0x021D5674 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
extern u16 BTL_POKEPARAM_RestoreMovePP(u8 *p, u32 i, u8 n);
int BTL_CLIENT_CmdPpPlusOriginal(u32 *a, int b, u32 *c)
{
    u8 *m;

    m = BTL_SIDE_GetPokeByIdThunk((char *)a[1], (u8)c[0]);
    BTL_POKEPARAM_RestoreMovePP(m, (u8)c[1], c[2]);
    return 1;
}
