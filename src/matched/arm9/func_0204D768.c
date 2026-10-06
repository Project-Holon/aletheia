/*
 * function: func_0204D768
 * address:  0x0204D768
 * packet:   pkt_0204D768
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0204D410  0x0204D410  arm
 *   func_02063000  0x02063000  arm
 *   func_02063018  0x02063018  arm
 *
 * Apply one animation command record to the handle behind the cell actor's
 * +0x68 sub-object.  The opcode is the u16 at +0 of the record; 0 and 2 both
 * call func_02063000 with a different mode, 1 calls func_02063018 with the
 * record's own u16 at +2 as its last argument.
 *
 * Three cases dense from zero, yet no halfword table: the compiler emits a
 * compare chain because the arms are all tail calls with no shared code, so
 * the table would cost more than the three compares
 * (docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md is the case
 * where it does build one).  The compare chain runs 0, 1, 2 in case-label
 * order whatever the source does, but the arm *blocks* are laid out in source
 * order, so the cases have to be written 0, 2, 1 to put case 1's block last.
 * That is the only thing separating this from the image: with the arms in
 * numeric order the two `beq` displacements swap and fourteen bytes differ.
 *
 * `ldmib r4, {r2, r3}` is not a struct copy, it is the compiler merging the
 * two consecutive word loads at +4 and +8 that feed argument registers three
 * and four.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204D768.c \
 *       --func func_0204D768 --addr 0x0204D768 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctl {
    u8 pad_00[4];
};

struct Cmd {
    u16 op;     /* 0x00 */
    u16 arg0;   /* 0x02 */
    u32 arg1;   /* 0x04 */
    u32 arg2;   /* 0x08 */
};

struct Obj;
struct Rec;
extern struct Rec *func_0204D410(struct Obj *o);
extern void func_02063000(int p0, int p1, int p2, int p3);
struct CellAnim;
extern void func_02063018(struct CellAnim *anim, u32 a, u32 b, u16 tag);

void func_0204D768(struct Ctl *c, const struct Cmd *cmd)
{
    void *h = func_0204D410((struct Obj *)c);

    switch (cmd->op) {
    case 0:
        func_02063000((int)h, 1, cmd->arg1, cmd->arg2);
        break;
    case 2:
        func_02063000((int)h, 3, cmd->arg1, cmd->arg2);
        break;
    case 1:
        func_02063018(h, cmd->arg1, cmd->arg2, cmd->arg0);
        break;
    }
}
