/*
 * function: func_0204B98C
 * address:  0x0204B98C
 * packet:   pkt_0204B954
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   CLACT_GetAnimObject  0x0204D444  arm
 *
 * Read the u32 at +0x0c of the record CLACT_GetAnimObject selects out of the cell
 * actor's +0x68 sub-object.  The pair CLACT_StartActorAnim / CLACT_StopActorAnim writes the
 * same field through CLACT_GetAnimCtrl's record instead.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204B98C.c \
 *       --func func_0204B98C --addr 0x0204B98C --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Rec {
    u8  pad_00[0x0c];
    u32 value;   /* 0x0c */
};

struct Ctl {
    u8 pad_00[4];
};

struct Actor {
    u8         pad_00[0x68];
    struct Ctl ctl;   /* 0x68 */
};

extern struct Rec *CLACT_GetAnimObject(struct Ctl *c);

u32 func_0204B98C(struct Actor *a)
{
    return CLACT_GetAnimObject(&a->ctl)->value;
}
