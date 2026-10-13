/*
 * function: BTL_MAIN_GetViewPositionsPerClient
 * address: 0x021B99C0
 * packet: pkt_ov093_021B99C0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_MAIN_GetPositionsPerClient 0x021B6994 thumb ov093
 *   BTL_MAIN_GetRule 0x021B8588 thumb ov093
 * evidence: entry r1 is forwarded unchanged to the two-argument 021B6994.
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct S;
extern int BTL_MAIN_GetPositionsPerClient(struct S **, u32);
extern u32 BTL_MAIN_GetRule(void **p);
int BTL_MAIN_GetViewPositionsPerClient(struct S **p, u32 b)
{
    int result = BTL_MAIN_GetPositionsPerClient(p, b);
    if (BTL_MAIN_GetRule((void **)p) == 3) result = (u8)(result + 2);
    return result;
}
