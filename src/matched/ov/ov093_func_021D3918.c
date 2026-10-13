/*
 * function: BTL_CLIENT_CmdCureSick
 * address: 0x021D3918
 * packet: pkt_ov093_021D3918
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_SIDE_GetPokeByIdThunk 0x021B9934 thumb ov093
 *   BTL_POKEPARAM_CureSick 0x021D6238 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
struct UtilSlots; extern void BTL_POKEPARAM_CureSick(struct UtilSlots *, int);
int BTL_CLIENT_CmdCureSick(u32 *a, int b, u32 *c)
{
    u8 *m;

    m = BTL_SIDE_GetPokeByIdThunk((char *)a[1], (u8)c[0]);
    BTL_POKEPARAM_CureSick((struct UtilSlots *)m, c[1]);
    return 1;
}
