/*
 * file:     unit_02064178_p01.c
 * unit:     yes
 * function: func_02064178, func_0206419C, func_0206428C
 * address:  0x02064178
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02064140  0x02064140  arm
 *   func_02066ABC  0x02066ABC  arm
 *   func_02062F38  0x02062F38  arm
 *   func_0206434C  0x0206434C  arm
 */
#include "../../matched/include/Obj07023.h"
#include "../../matched/include/Obj00260.h"
#include "../../matched/include/Obj03025.h"
#include "../../matched/include/Obj16427.h"
#include "../../matched/include/Obj16428.h"
#include "../../matched/include/Obj11539.h"

struct O02064140;
struct CellAnim;
struct CellDataBank;
struct Obj02064100;
typedef unsigned int u32;

typedef unsigned short u16;

extern void func_02064140(struct O02064140 *o, u32 a);
extern void *func_02062D40(struct CellAnim *anim);
extern void *func_0206285C(struct CellDataBank *bank, u32 idx);
extern void func_020640DC(char *p, int a, int b);
extern void func_02064120(char *p, int a, int b);
extern void func_02064100(struct Obj02064100 *obj, u16 val);
extern int func_02066ABC(int a0, int a1, int a2);
extern int func_02062F38(int a0);
extern void func_0206434C(char *self, int v);
void func_02064178(char *o, u32 a);
void func_0206419C(char *self);
void func_0206428C(char *self, int a1, char *c);



/*
 * Opens one 0x28-byte group header of the two-level cell-array shape: clears
 * the header's first word, stores the cell pointer at +0x04, sets the "in use"
 * word at +0x08 and tail-calls func_02064140 on the SRT block at +0x0c.
 * func_02064754 drives it once per group.
 *
 * PIN ../2.0/sp2: the tail-call scheduling form of the "kept constants" tell.
 * The image materialises the zero FIRST and stores it first -- `mov r2,#0` at
 * 0x02064178 / `str r2,[r0]` / `str r1,[r0,#4]` / `mov r1,#1` / `str r1,[r0,#8]`
 * -- and only then loads the tail-call pool word (`ldr ip,[pc,#4]` at
 * 0x0206418C).  1.1p1 -O4,p hoists that pool load ABOVE the three stores and
 * posts the zero store after them, which lets it drop one instruction: 32
 * bytes against the original's 36, 23 concrete out.  An earlier lane measured
 * the array spelling `((u32 *)o)[0] = 0; ...`, the named-field spelling and a
 * `(u8 *)o + 0xc` call argument and found all three byte-identical to each
 * other, i.e. the scheduling is not source-driven
 * (docs/notes/pkt_02064178.c.txt).  Under the pin this SAME C is 36 bytes, 0
 * mismatches.
 */
void func_02064178(char *o, u32 a)
{
    *(u32 *)&((struct Obj07023 *)o)->f0 = 0;
    ((struct Obj07023 *)o)->f4 = a;
    ((struct Obj07023 *)o)->f8 = 1;
    func_02064140((struct O02064140 *)(o + 0xc), 1);
}



void func_0206419C(char *self)
{
    char *p;
    char *o;
    int kind;
    int q;
    int r;
    int r2;
    if (*(unsigned short *)(*(int *)&((struct Obj00260 *)self)->f4 + 4) == 0)
        return;
    func_02062D40((struct CellAnim *)self);
    p = func_02062D40((struct CellAnim *)self);
    o = *(char * *)&((struct Obj00260 *)self)->f34;
    ((struct Obj00260 *)self)->f30 = (int)func_0206285C((struct CellDataBank *)o, ((struct Obj03025 *)p)->f0);
    kind = *(int *)(*(int *)&((struct Obj00260 *)self)->f1C + 4) & 0xff;
    func_02064140((struct O02064140 *)(self + 0x3c), 1);
    switch (kind) {
    case 0:
        break;
    case 2:
        func_020640DC(self + 0x3c, *(short *)&((struct Obj03025 *)p)->f4, *(short *)(p + 6));
        break;
    default:
        func_02064120(self + 0x3c, ((struct Obj03025 *)p)->f4, ((struct Obj03025 *)p)->f8);
        func_02064100((struct Obj02064100 *)(self + 0x3c), ((struct Obj03025 *)p)->f2);
        func_020640DC(self + 0x3c, ((struct Obj03025 *)p)->fC, ((struct Obj03025 *)p)->fE);
        break;
    }
    q = ((struct Obj16427 *)o)->fC;
    r = !!q;
    if (r == 0) return;
    if (*(volatile int *)&((struct Obj00260 *)self)->f38 != -1) r2 = 1; else r2 = 0;
    if (r2 == 0) return;
    {
        int *t = (int *)(((struct Obj16428 *)q)->f4 + ((struct Obj03025 *)p)->f0 * 8);
        func_02066ABC(((struct Obj00260 *)self)->f38, t[0], t[1]);
    }
}


/*
 * Binds one cell-bank row to an animation object: stores the row pointer at
 * +0x34, writes the "no cell bound" sentinel -1 at +0x38, opens the SRT block
 * at +0x3c through func_02064140 and finishes with the object's own two-call
 * tail.  The sibling of func_020642C8, which does the same fixups after an
 * eight-argument forward.
 *
 * PIN ../2.0/sp2: the "kept constants" tell in its allocation form.  The image
 * materialises the sentinel into r2 and stores it SECOND, between the +0x34
 * store and the `add r0, r5, #0x3c` argument setup -- `str r2,[r5,#0x34]` at
 * 0x02064298 / `mvn r2,#0` at 0x0206429C / `add r0,r5,#0x3c` / `mov r1,#1` /
 * `str r2,[r5,#0x38]` at 0x020642A8.  1.1p1 -O4,p allocates the -1 into r3
 * instead and sinks its store below the whole argument setup, giving
 * `mvn r3,#0` / `add r0,r5,#0x3c` / `mov r1,#1` / `str r2,[r5,#0x34]` /
 * `str r3,[r5,#0x38]`: the same 60 bytes, 17 concrete out.  An earlier lane
 * measured `0xffffffffu`, `(u32)-1` and a named `u32` local for the sentinel
 * and every one allocates r3 the same way (docs/notes/pkt_02064178.c.txt).
 * Under the pin this SAME C is 60 bytes, 0 mismatches, all three sites label.
 */
void func_0206428C(char *self, int a1, char *c)
{
    *(char * *)&((struct Obj11539 *)self)->f34 = c;
    ((struct Obj11539 *)self)->f38 = -1;
    func_02064140((struct O02064140 *)(self + 0x3c), 1);
    func_02062F38((int)self);
    func_0206434C(self, a1);
}
