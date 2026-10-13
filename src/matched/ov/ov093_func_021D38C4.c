/*
 * function: BTL_CLIENT_CmdAddCritStage
 * address: 0x021D38C4
 * packet: pkt_ov093_021D38C4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021B9934 0x021B9934 thumb ov093
 *   BTL_POKEPARAM_AddCritStage 0x021D5F38 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 *func_021B9934(char *p, int i);
struct S; extern int BTL_POKEPARAM_AddCritStage(struct S *, int);
int BTL_CLIENT_CmdAddCritStage(u32 *a, int b, u32 *c)
{
    u8 *m;

    m = func_021B9934((char *)a[1], (u8)c[0]);
    BTL_POKEPARAM_AddCritStage((struct S *)m, c[1]);
    return 1;
}
