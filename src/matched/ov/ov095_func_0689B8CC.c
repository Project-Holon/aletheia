/*
 * function: BTL_SICK_BuildDamageMessage
 * address: 0x0689B8CC
 * packet: pkt_ov095_0689B8CC
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_SICK_GetDamageStringId 0x0689B92C thumb ov095
 *   func_0689B8FC 0x0689B8FC thumb ov095
 *   func_0689B90C 0x0689B90C thumb ov095
 *   func_0689B91C 0x0689B91C thumb ov095
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern int BTL_SICK_GetDamageStringId(int);
extern void func_0689B8FC(void *, int, u16);
extern u32 func_0689B90C(u32);
extern void func_0689B91C(void *, u32);
int BTL_SICK_BuildDamageMessage(void *p, u32 b, int kind)
{
    int message;
    message = BTL_SICK_GetDamageStringId(kind);
    if (message > 0) {
        func_0689B8FC(p, 2, message);
        func_0689B91C(p, func_0689B90C(b));
    }
    return 0;
}
