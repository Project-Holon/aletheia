/*
 * function: C_GEAR_IsTileActorIdle
 * address: 0x021F0064
 * packet: pkt_ov029_021F0064
 * region: ov029
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
int C_GEAR_IsTileActorIdle(unsigned char *p, int a, int b)
{
    int i;
    for (i = 0; i < 20; i++) {
        if (*(int *)(p + i * 12 + 0x3c) != 0 && *(int *)(p + i * 12 + 0x40) == a && *(int *)(p + i * 12 + 0x44) == b) {
            if (CLACT_IsActorAnimActive((struct Actor *)(*(int *)(p + i * 12 + 0x3c))) != 0) return 0;
        }
    }
    return 1;
}
