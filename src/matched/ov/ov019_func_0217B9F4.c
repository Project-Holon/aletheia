/*
 * function: UNION_ONESELF_DeleteParty
 * address: 0x0217B9F4
 * packet: pkt_ov019_0217B9F4
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02034714 0x02034714 arm
 *   func_020307B0 0x020307B0 arm
 *   gUnionEmptyString1 0x021807E4 data a1
 */
typedef unsigned int   u32;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern u32 func_020307B0(void *p);
extern const char gUnionEmptyString1[];
void UNION_ONESELF_DeleteParty(void *p)
{
    if (!p) func_02034714(gUnionEmptyString1, 0, gUnionEmptyString1);
    func_020307B0(p);
}
