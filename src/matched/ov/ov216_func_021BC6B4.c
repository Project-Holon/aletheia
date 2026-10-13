/*
 * function: func_021BC6B4
 * address:  0x021BC6B4
 * packet:   pkt_021BC6B4
 * region:   ov216
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 */

struct S021BC6B4
{
    char pad[0x264];
    void *slots[2];
};

typedef unsigned int   u32;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void CLACT_DeleteActor(struct Obj *p);

void func_021BC6B4(struct S021BC6B4 *p)
{
    int i;
    for (i = 0; i < 2; i++)
    {
        CLACT_SetActorDrawEnable(p->slots[i], 0);
        CLACT_DeleteActor(p->slots[i]);
    }
}
