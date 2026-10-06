/*
 * function: func_0204D7C4
 * address:  0x0204D7C4
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
 *
 * Reset the animation handle behind the cell actor's +0x68 sub-object: the
 * all-zero form of the case-0 arm of func_0204D768 next door.
 *
 * The three zero arguments are one `mov r1, #0` and two register copies, not
 * three `mov`s of an immediate
 * (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204D7C4.c \
 *       --func func_0204D7C4 --addr 0x0204D7C4 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

struct Ctl {
    u8 pad_00[4];
};

struct Obj;
struct Rec;
extern struct Rec *func_0204D410(struct Obj *o);
extern void func_02063000(int p0, int p1, int p2, int p3);

void func_0204D7C4(struct Ctl *c)
{
    func_02063000((int)func_0204D410((struct Obj *)c), 0, 0, 0);
}
