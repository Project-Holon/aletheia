/*
 * function: func_02064100
 * address:  0x02064100
 * packet:   pkt_020640DC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O1
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The rotation setter of the three-function NNS G2D SRT family
 * (func_020640DC translate / func_02064100 rotate / func_02064120 scale).
 * At the default -O4,p this front end if-converts the four-instruction
 * guarded block (ldrheq/orreq/strheq/strheq) and drops the original's
 * `bxne lr`, four bytes short; the predication threshold is five
 * instructions (see docs/notes/g2d_srt_setters.c.txt and
 * docs/idioms/an-arm-guard-block-of-five-instructions-or-fewer-is-predicated.md).
 * At -O1 the compiler keeps the branch and the function is byte-exact.
 * This is the same configuration already filed for this range as
 * src/matched/unit_020640DC.c, which covers func_02064100 as its middle
 * section.
 */

typedef unsigned int u32;
typedef unsigned short u16;

typedef struct Obj02064100 {
    u32 state;      /* +0x00, 1 = SRT enabled */
    u32 arg1;       /* +0x04 */
    u32 arg2;       /* +0x08 */
    u16 field0c;    /* +0x0C */
    u16 field0e;    /* +0x0E */
    u16 field10;    /* +0x10 rotation */
    u16 flags;      /* +0x12 dirty: bit1 scale, bit2 rotation, bit3 translation */
} Obj02064100;

void func_02064100(Obj02064100 *obj, u16 val)
{
    if (obj->state != 1) return;
    obj->flags |= 4;
    obj->field10 = val;
}
