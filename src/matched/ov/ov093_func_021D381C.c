/*
 * function: BTL_CLIENT_CmdSetStatStages
 * address:  0x021D381C
 * packet:   pkt_ov093_021D381C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_SIDE_GetPokeByIdThunk  0x021B9934  thumb  ov093
 *   BTL_POKEPARAM_SetStatStage  0x021D5EA8  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
extern void BTL_POKEPARAM_SetStatStage(u8 *p, int i, u8 n);

int BTL_CLIENT_CmdSetStatStages(u32 *a, int b, u32 *c)
{
    u8 *m;

    m = BTL_SIDE_GetPokeByIdThunk((char *)a[1], (u8)c[0]);
    BTL_POKEPARAM_SetStatStage(m, 1, c[1]);
    BTL_POKEPARAM_SetStatStage(m, 2, c[2]);
    BTL_POKEPARAM_SetStatStage(m, 3, c[3]);
    BTL_POKEPARAM_SetStatStage(m, 4, c[4]);
    BTL_POKEPARAM_SetStatStage(m, 5, c[5]);
    BTL_POKEPARAM_SetStatStage(m, 6, c[6]);
    BTL_POKEPARAM_SetStatStage(m, 7, c[7]);
    return 1;
}
