/*
 * function: BTL_CLIENT_StepClearContFlag
 * address: 0x021D3A98
 * packet: pkt_ov093_021D3A98
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT* (two bytes alignment padding)
 * symbols:
 *   BTL_SIDE_GetPokeByIdThunk 0x021B9934 thumb ov093
 *   BTL_POKEPARAM_ClearContFlag 0x021D6008 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct UtilWork;
extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
extern void BTL_POKEPARAM_ClearContFlag(u8 *, u32);
int BTL_CLIENT_StepClearContFlag(u32 *a, int *b, u32 *c)
{
    u8 *x;
    x = BTL_SIDE_GetPokeByIdThunk((char *)a[1], (u8)c[0]);
    BTL_POKEPARAM_ClearContFlag(x, c[1]);
    return 1;
}
