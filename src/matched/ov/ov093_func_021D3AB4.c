/*
 * function: func_021D3AB4
 * address: 0x021D3AB4
 * packet: pkt_ov093_021D3AB4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT* (two bytes alignment padding)
 * symbols:
 *   func_021B9934 0x021B9934 thumb ov093
 *   BTL_POKEPARAM_SetTurnFlag 0x021D5FC0 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct UtilWork;
extern u8 *func_021B9934(char *p, int i);
extern void BTL_POKEPARAM_SetTurnFlag(struct UtilWork *, u32);
int func_021D3AB4(u32 *a, int *b, u32 *c)
{
    u8 *x;
    x = func_021B9934((char *)a[1], (u8)c[0]);
    BTL_POKEPARAM_SetTurnFlag((struct UtilWork *)x, c[1]);
    return 1;
}
