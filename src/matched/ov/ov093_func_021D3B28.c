/*
 * function: BTL_CLIENT_StepReplaceMove
 * address: 0x021D3B28
 * packet: pkt_ov093_021D3B28
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT* (two bytes alignment padding)
 * symbols:
 *   BTL_SIDE_GetPokeByIdThunk 0x021B9934 thumb ov093
 *   BTL_POKEPARAM_ReplaceMove 0x021D5734 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct UtilWork;
extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
extern void BTL_POKEPARAM_ReplaceMove(u8 *p, u8 i, u16 a, u8 b, u32 c);
int BTL_CLIENT_StepReplaceMove(u32 *a, int *b, const u32 *c)
{
    u8 *x;
    x = BTL_SIDE_GetPokeByIdThunk((char *)a[1], (u8)c[0]);
    BTL_POKEPARAM_ReplaceMove(x, c[1], c[4], c[2], c[3]);
    return 1;
}
