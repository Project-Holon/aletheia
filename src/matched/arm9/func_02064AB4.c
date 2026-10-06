/*
 * function: func_02064AB4
 * address:  0x02064AB4
 * packet:   pkt_02064934
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * PIN ../2.0/sp2: the "kept branches" tell.  The image writes the case-2
 * call tail out in its own arm -- `add r0, r4, #0x48` (0x02064B20) /
 * `bl func_020640DC` (0x02064B24) / `b 0x02064B54` (0x02064B28) -- although
 * the default arm ends in a byte-identical `add r0, r4, #0x48` /
 * `bl func_020640DC` pair at 0x02064B4C/0x02064B50.  1.1p1 -O4,p cross-jumps
 * the two, branching case 2 into the default arm's pair and giving 172 bytes
 * against the original's 180, 64 concrete bytes out.  Two independent lanes
 * measured a dozen spellings (switch arm order, if-chain, goto tail, named
 * s16 locals, nested switch) and all cross-jump.  Under the pin the same C
 * is 180 bytes, 0 mismatches.
 *
 * symbols:
 *   func_02062F00  0x02062F00  arm
 *   func_02062D40  0x02062D40  arm
 *   func_020629E8  0x020629E8  arm
 *   func_02064140  0x02064140  arm
 *   func_020640DC  0x020640DC  arm
 *   func_02064120  0x02064120  arm
 *   func_02064100  0x02064100  arm
 *   func_020643CC  0x020643CC  arm
 *
 * Same body as func_020649D4 from the header test down, but with a guard
 * that returns early instead of the missed-lookup arm, and no call to
 * func_02064934.  The early-out is ONE expression: the two tests are
 * predicated onto a single `popeq` (`ldrne`/`cmpne`/`popeq`), which is what
 * makes it a `||` inside a single `if` rather than two `if`s (two separate
 * guards would each need their own `pop`).
 */
#include "../include/Obj03475.h"
#include "../include/Obj07024.h"

typedef unsigned int   u32;
extern int func_02062F00(void *s, u32 i);
struct CellAnim;
struct O02064140;
extern void *func_02062D40(struct CellAnim *anim);
typedef unsigned short u16;
struct MCInstance;
struct MultiCellBank;
struct MultiCellData;
extern struct MultiCellData *func_020629E8(struct MultiCellBank *bank, u32 idx);
extern void func_02064140(struct O02064140 *o, u32 a);
extern void func_020640DC(char *self, int a, int b);
extern void func_02064120(char *self, int a, int b);
extern void func_02064100(char *self, int a);
extern void func_020643CC(struct MCInstance *pMCInst, const struct MultiCellData *pMcData, u16 mcTotalFrame);

void func_02064AB4(char *self, unsigned int i)
{
    char *p;
    int kind;
    int item;

    if (func_02062F00(self, i) == 0 || *(unsigned short *)(((struct Obj07024 *)self)->f4 + 4) == 0)
        return;
    p = func_02062D40((struct CellAnim *)self);
    item = (int)func_020629E8((struct MultiCellBank *)(((struct Obj07024 *)self)->f44), ((struct Obj03475 *)p)->f0);
    kind = *(int *)(((struct Obj07024 *)self)->f1C + 4) & 0xff;
    func_02064140((struct O02064140 *)(self + 0x48), 1);
    switch (kind) {
    case 0:
        break;
    case 2:
        func_020640DC(self + 0x48, *(short *)&((struct Obj03475 *)p)->f4, *(short *)(p + 6));
        break;
    default:
        func_02064120(self + 0x48, ((struct Obj03475 *)p)->f4, ((struct Obj03475 *)p)->f8);
        func_02064100(self + 0x48, ((struct Obj03475 *)p)->f2);
        func_020640DC(self + 0x48, ((struct Obj03475 *)p)->fC, ((struct Obj03475 *)p)->fE);
        break;
    }
    func_020643CC((struct MCInstance *)(self + 0x34), (const struct MultiCellData *)item, ((struct Obj07024 *)self)->f30);
}
