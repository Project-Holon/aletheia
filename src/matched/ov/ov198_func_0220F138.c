/*
 * function: B_PLIST_MAIN_SetActorAnimSeq
 * address:  0x0220F138
 * packet:   pkt_0220F138
 * region:   ov198
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_GetActorAnimSeq 0x0204B898 arm
 *   CLACT_SetActorAnimFrame 0x0204B8C4 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;
struct Obj;
extern u16 CLACT_GetActorAnimSeq(struct Obj *p);
extern void CLACT_SetActorAnimFrame(struct Obj *p, u32 value);
extern void CLACT_SetActorAnimSeq(void *, int);

void B_PLIST_MAIN_SetActorAnimSeq(void *a, int b)
{
    if (b != CLACT_GetActorAnimSeq(a))
    {
        CLACT_SetActorAnimFrame(a, 0);
        CLACT_SetActorAnimSeq(a, b);
    }
}
