/*
 * function: BTL_POKEPARAM_CanChangeStatStage
 * address: 0x021D5D14
 * packet: pkt_ov093_021D5D14
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: final two bytes are zero alignment padding.
 * evidence: 021D5CB4 unconditionally writes both outputs before its switch.
 * symbols:
 *   BTL_POKEPARAM_GetStatStagePtr 0x021D5CB4 thumb ov093
 */
typedef signed char s8;
typedef unsigned char u8;
extern s8 *BTL_POKEPARAM_GetStatStagePtr(s8 *, int, u8 *, u8 *);
int BTL_POKEPARAM_CanChangeStatStage(s8 *p, int i, int sign)
{
    s8 a;
    s8 b;
    s8 *v;
    v = BTL_POKEPARAM_GetStatStagePtr(p, i, (u8 *)&a, (u8 *)&b);
    if (sign > 0) return *v < b;
    else return *v > a;
}
