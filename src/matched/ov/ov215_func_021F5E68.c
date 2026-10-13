/*
 * unit:     yes
 * function: func_021F5E68, func_021F5E90
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
 *   func_0204B92C 0x0204B92C arm
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
extern void func_0204B92C(struct Obj *p, u32 v);
extern u32 CLACT_IsActorAnimActive(struct Actor *a);

void func_021F5E68(int unused, struct S021F5E68 *p)
{
    unsigned char i;
    for (i = 0; i < 6; i++)
    {
        CLACT_SetActorAnimIndex((int)p->slots[i], 0);
        func_0204B92C(p->slots[i], 1);
    }
}

int func_021F5E90(int unused, struct S021F5E68 *p)
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
