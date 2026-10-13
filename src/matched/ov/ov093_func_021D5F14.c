/*
 * function: BTL_POKEPARAM_GetCritStage
 * address: 0x021D5F14
 * packet: pkt_ov093_021D5F14
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_POKEPARAM_TestContFlag 0x021D5BDC thumb ov093
 */
typedef unsigned char u8;
struct UtilWork;
extern int BTL_POKEPARAM_TestContFlag(struct UtilWork *, unsigned int);
u8 BTL_POKEPARAM_GetCritStage(struct UtilWork *p)
{
    u8 n;
    n = *((u8 *)p + 0x142);
    if (BTL_POKEPARAM_TestContFlag(p, 9)) {
        n += 2;
        if (n > 4) n = 4;
    }
    return n;
}
