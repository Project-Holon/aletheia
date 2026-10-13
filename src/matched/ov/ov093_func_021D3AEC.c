/*
 * function: func_021D3AEC
 * address: 0x021D3AEC
 * packet: pkt_ov093_021D3AEC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT* (two bytes alignment padding)
 * symbols:
 *   func_021B9934 0x021B9934 thumb ov093
 *   BTL_POKEPARAM_SetAbility 0x021D66D0 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct UtilWork;
extern u8 *func_021B9934(char *p, int i);
struct QJ;
extern void BTL_POKEPARAM_SetAbility(struct QJ *p, u32 v);
int func_021D3AEC(u32 *a, int *b, u32 *c)
{
    u8 *x;
    x = func_021B9934((char *)a[1], (u8)c[0]);
    BTL_POKEPARAM_SetAbility((struct QJ *)x, c[1]);
    return 1;
}
