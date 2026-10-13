/*
 * function: BTL_CLIENT_CmdStatStageDown
 * address: 0x021D37FC
 * packet: pkt_ov093_021D37FC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9934 0x021B9934 thumb ov093
 *   BTL_POKEPARAM_LowerStatStage 0x021D5E38 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 *func_021B9934(char *p, int i);
typedef signed char s8;
extern u8 BTL_POKEPARAM_LowerStatStage(s8 *, int, u8);
int BTL_CLIENT_CmdStatStageDown(u32 *a, int b, u32 *c)
{
    u8 *m;

    m = func_021B9934((char *)a[1], (u8)c[0]);
    BTL_POKEPARAM_LowerStatStage((s8 *)m, c[1], c[2]);
    return 1;
}
