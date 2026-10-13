/*
 * function: CLACT_StopActorAnim
 * address:  0x0204B974
 * packet:   pkt_0204B954
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   CLACT_GetAnimCtrl  0x0204D410  arm
 *
 * Set the flag at +0x0c of the animation record CLACT_GetAnimCtrl selects out of
 * the cell actor's +0x68 sub-object.  CLACT_StartActorAnim next door is the same
 * function storing 1 instead of 0.
 *
 * The store goes through the callee's return value, not through the actor, so
 * the actor pointer is dead after the call and nothing is saved across it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_StopActorAnim.c \
 *       --func CLACT_StopActorAnim --addr 0x0204B974 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Anim {
    u8  pad_00[0x0c];
    u32 flag;   /* 0x0c */
};

struct Ctl {
    u8 pad_00[4];
};

struct Actor {
    u8         pad_00[0x68];
    struct Ctl ctl;   /* 0x68 */
};

extern struct Anim *CLACT_GetAnimCtrl(struct Ctl *c);

void CLACT_StopActorAnim(struct Actor *a)
{
    CLACT_GetAnimCtrl(&a->ctl)->flag = 0;
}
