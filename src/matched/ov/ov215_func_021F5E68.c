/*
 * unit:     yes
 * function: EGG_DEMO_MAIN_StartActorAnims, EGG_DEMO_MAIN_AreActorAnimsDone
 * address:  0x021F5E68
 * packet:   pkt_021F5E68
 * region:   ov215
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_SetActorAnimIndex 0x0204B908 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 */

struct S021F5E68
{
    char pad[0x38];
    void *slots[6];
};

extern void CLACT_SetActorAnimIndex(int a0, int a1);
typedef unsigned int   u32;
struct Actor;
struct Obj;
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern u32 CLACT_IsActorAnimActive(struct Actor *a);

void EGG_DEMO_MAIN_StartActorAnims(int unused, struct S021F5E68 *p)
{
    unsigned char i;
    for (i = 0; i < 6; i++)
    {
        CLACT_SetActorAnimIndex((int)p->slots[i], 0);
        CLACT_SetActorAutoAnim(p->slots[i], 1);
    }
}

int EGG_DEMO_MAIN_AreActorAnimsDone(int unused, struct S021F5E68 *p)
{
    unsigned char i;
    int r = 1;
    for (i = 0; i < 6; i++)
    {
        if (CLACT_IsActorAnimActive(p->slots[i]) != 0)
        {
            r = 0;
            break;
        }
    }
    return r;
}
