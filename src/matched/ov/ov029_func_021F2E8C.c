/*
 * function: C_GEAR_StepFadeFx
 * address:  0x021F2E8C
 * packet:   pkt_ov029_021F2E8C
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_IsActorAnimActive  0x0204B98C  arm
 *   CLACT_GetActorAnimSeqCount  0x0204B918  arm
 *   PALANM_RequestFade  0x0202173C  thumb
 *   gCGearFadeSteps     0x021F3224  data  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;

typedef unsigned int   u32;
struct Actor;
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
struct Obj;
extern u16 CLACT_GetActorAnimSeqCount(struct Obj *p);
extern int PALANM_RequestFade(void *p, u16 mask, u16 col, s16 step, u8 b, u8 c, u16 d, void *ctx);
extern const unsigned int gCGearFadeSteps[];

int C_GEAR_StepFadeFx(char *p)
{
    if (*(int *)(p + 0) == 0)
        return 1;
    if (CLACT_IsActorAnimActive(*(void **)(p + 8)) == 0) {
        *(int *)(p + 0) = 0;
        return 1;
    }
    PALANM_RequestFade(*(void **)(p + 0xC), 8, *(int *)(p + 4), -0x78, 0,
                  (u8)gCGearFadeSteps[CLACT_GetActorAnimSeqCount(*(void **)(p + 8))], 0,
                  *(void **)(p + 0x10));
    return 0;
}
