/*
 * function: func_020649D4
 * address:  0x020649D4
 * packet:   pkt_020640DC
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The tick-driven form of func_02064AB4: steps the multi-cell animation by a
 * fx32 tick through func_02062D4C and, when that reports no advance, hands the
 * whole walk block at +0x34 to func_02064934 instead.  From the header test
 * down the body is func_02064AB4's verbatim.
 *
 * PIN ../2.0/sp2, inherited from the sibling src/matched/func_02064AB4.c: the
 * same case-2 cross-jump.  1.1p1 -O4,p shares case 2's
 * `add r0, r4, #0x48` / `bl func_020640DC` tail with the default arm's
 * identical pair at 0x02064A88/0x02064A8C and lands at 220 bytes against the
 * original's 224 (docs/notes/pkt_02064934.func_020649D4.c.txt).
 *
 * THREE C LEVERS, all needed and all found in this pass:
 *  1. func_02062D4C IS ARITY TWO, not three.  The note's body declared a third
 *     parameter and passed the latched halfword `t`; that costs a `mov r2, r5`
 *     at 0x020649E8 and the compile is 228 bytes.  The image sets only r0/r1.
 *  2. THE MISS ARM MUST BE A `goto` TO THE FUNCTION'S TAIL.  Written inline as
 *     `{ func_02064934(...); return; }` the compiler emits it in place under a
 *     `bne` where the image emits `beq #0x2064aa4` over the whole body to an
 *     arm placed AFTER the main epilogue.  Size-exact either way; the inline
 *     form is 140 concrete bytes out because everything after +0x1C is shifted
 *     by one instruction.
 *  3. `int kind;` MUST BE DECLARED BEFORE `int r7;`.  Declaration order is
 *     stack/colour order here: the reverse puts the masked kind in r7 and the
 *     descriptor in r6, where the image has kind in r6 and the descriptor in
 *     r7 (docs/idioms/declaration-order-decides-which-register-a-local-gets.md).
 *
 * The +0x2C PC24 to func_02064934 resolves by `sole-ref/code`: 0x02064934 is a
 * traced function start and this `bl` is its only branch image-wide, which is
 * exactly the single-caller shape `label` cannot reach.
 *
 * symbols:
 *   func_02062D4C  0x02062D4C  arm
 *   func_02064934  0x02064934  arm
 *   func_02062D40  0x02062D40  arm
 *   func_020629E8  0x020629E8  arm
 *   func_02064140  0x02064140  arm
 *   func_020640DC  0x020640DC  arm
 *   func_02064120  0x02064120  arm
 *   func_02064100  0x02064100  arm
 *   func_020643CC  0x020643CC  arm
 */
#include "../include/Obj03474.h"
#include "../include/Obj04783.h"

extern int func_02062D4C(char *self, int a1);
struct CellAnim;
struct Root;
extern void func_02064934(struct Root *p, int arg);
extern void *func_02062D40(struct CellAnim *anim);
typedef unsigned short u16;
typedef unsigned int   u32;
struct MCInstance;
struct MultiCellBank;
struct MultiCellData;
extern struct MultiCellData *func_020629E8(struct MultiCellBank *bank, u32 idx);
extern void func_02064140(char *self, int v);
extern void func_020640DC(char *self, int a, int b);
extern void func_02064120(char *self, int a, int b);
extern void func_02064100(char *self, int a);
extern void func_020643CC(struct MCInstance *pMCInst, const struct MultiCellData *pMcData, u16 mcTotalFrame);

void func_020649D4(char *self, int a1)
{
    unsigned short t = *(unsigned short *)(((struct Obj04783 *)self)->f0 + 4);
    char *p;
    int kind;
    int r7;

    if (func_02062D4C(self, a1) == 0) {
        goto miss;
    }
    ((struct Obj04783 *)self)->f30 += t;
    if (*(unsigned short *)(((struct Obj04783 *)self)->f4 + 4) == 0)
        return;
    p = func_02062D40((struct CellAnim *)self);
    r7 = (int)func_020629E8((struct MultiCellBank *)(((struct Obj04783 *)self)->f44), ((struct Obj03474 *)p)->f0);
    kind = *(int *)(((struct Obj04783 *)self)->f1C + 4) & 0xff;
    func_02064140(self + 0x48, 1);
    switch (kind) {
    case 0:
        break;
    case 2:
        func_020640DC(self + 0x48, *(short *)&((struct Obj03474 *)p)->f4, *(short *)(p + 6));
        break;
    default:
        func_02064120(self + 0x48, ((struct Obj03474 *)p)->f4, ((struct Obj03474 *)p)->f8);
        func_02064100(self + 0x48, ((struct Obj03474 *)p)->f2);
        func_020640DC(self + 0x48, ((struct Obj03474 *)p)->fC, ((struct Obj03474 *)p)->fE);
        break;
    }
    func_020643CC((struct MCInstance *)(self + 0x34), (const struct MultiCellData *)r7, ((struct Obj04783 *)self)->f30);
    return;
miss:
    func_02064934((struct Root *)(self + 0x34), a1);
}
