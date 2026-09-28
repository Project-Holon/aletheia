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
 *   func_0204D444  0x0204D444  arm
 *
 * Read the u32 at +0x0c of the record func_0204D444 selects out of the cell
 * actor's +0x68 sub-object.  The pair func_0204B95C / func_0204B974 writes the
 * same field through func_0204D410's record instead.
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

extern struct Rec *func_0204D444(struct Ctl *c);

u32 func_0204B98C(struct Actor *a)
{
    return func_0204D444(&a->ctl)->value;
}
