/*
 * function: BTL_CLIENT_CmdStatStageUp
 * address: 0x021D37DC
 * packet: pkt_ov093_021D37DC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_SIDE_GetPokeByIdThunk 0x021B9934 thumb ov093
 *   BTL_POKEPARAM_RaiseStatStage 0x021D5DC0 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
typedef signed char s8;
extern u8 BTL_POKEPARAM_RaiseStatStage(s8 *, int, u8);
int BTL_CLIENT_CmdStatStageUp(u32 *a, int b, u32 *c)
{
    u8 *m;

    m = BTL_SIDE_GetPokeByIdThunk((char *)a[1], (u8)c[0]);
    BTL_POKEPARAM_RaiseStatStage((s8 *)m, c[1], c[2]);
    return 1;
}
