/*
 * function: BTL_CLIENT_StepSetItem
 * address: 0x021D3B08
 * packet: pkt_ov093_021D3B08
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT* (two bytes alignment padding)
 * symbols:
 *   BTL_SIDE_GetPokeByIdThunk 0x021B9934 thumb ov093
 *   BTL_POKEPARAM_SetItem 0x021D5B44 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct UtilWork;
extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
struct QI;
extern void BTL_POKEPARAM_SetItem(struct QI *p, u16 v);
int BTL_CLIENT_StepSetItem(u32 *a, int *b, u32 *c)
{
    u8 *x;
    x = BTL_SIDE_GetPokeByIdThunk((char *)a[1], (u8)c[0]);
    BTL_POKEPARAM_SetItem((struct QI *)x, c[1]);
    return 1;
}
