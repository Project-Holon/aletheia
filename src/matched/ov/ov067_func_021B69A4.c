/*
 * function: TOUCHBAR_IsButtonActorIdle
 * address: 0x021B69A4
 * packet: pkt_ov067_021B69A4
 * region: ov067
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 */
typedef unsigned int   u32;
struct Actor;
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
int TOUCHBAR_IsButtonActorIdle(void **p)
{
    if (CLACT_IsActorAnimActive(*p) == 0) return 1;
    return 0;
}
