/*
 * function: C_GEAR_IsSplashDone
 * address: 0x021F1BE4
 * packet: pkt_ov029_021F1BE4
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 */
typedef unsigned int   u32;
struct Actor;
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
int C_GEAR_IsSplashDone(char *p)
{
    int i;
    for (i = 0; i < 18; i++) {
        if (CLACT_IsActorAnimActive((struct Actor *)(*(int *)(p + i * 4 + 0x170))) == 1)
            return 0;
    }
    return 1;
}
