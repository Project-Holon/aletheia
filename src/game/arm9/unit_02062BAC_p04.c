/*
 * file:     unit_02062BAC_p04.c
 * unit:     yes
 * function: func_02062F00, sub_02062F1C, func_02062F38
 * address:  0x02062F00
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02062D08    0x02062D08  arm
 */
#include "../../matched/include/Obj07015.h"
#include "../../matched/include/Obj03468.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct Owner {
    u8  pad_00[0xc];
    u32 base;
};

struct Node {
    u32           cursor;
    u8            pad_04[0x18];
    struct Owner *owner;
};

extern int func_02062D08(void *p, u32 i);
int func_02062F00(void *s, u32 i);
int func_02062F38(int a0);



int func_02062F00(void *s, u32 i)
{
    u32 r = func_02062D08(s, i);

    if (r != 0) {
        ((struct Obj07015 *)s)->f10 = 0;
    }
    return r;
}



/*
 * Index-of: how far the cursor at +0 of this record sits past the array
 * base its owner (+0x1c) keeps at +0xc, in units of eight bytes.  A leaf
 * with no prologue at all, which is why disasm.py never labelled it.
 *
 * The `lsl #13; lsr #16` pair is the folded form of "shift right by three,
 * then truncate to u16"
 * (docs/idioms/unequal-shift-pair-is-a-narrowing-cast-folded-with-a-shift.md);
 * the shifts being logical is the evidence that the subtraction is done in
 * u32, not as a signed ptrdiff.
 *
 * This is the missing witness for src/pending/sub_0204B918.c, the only
 * other reference to this address in the image.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02062F1C.c \
 *       --func sub_02062F1C --addr 0x02062F1C --cc 1.1p1 --arm
 */
u16 sub_02062F1C(const struct Node *n)
{
    return (u16)((n->cursor - n->owner->base) >> 3);
}


int func_02062F38(int a0){ int t0; t0 = func_02062F78((int)(a0 + 0x20)); ((struct Obj03468 *)((char *)(a0)))->f0 = (int)0; ((struct Obj03468 *)((char *)(a0)))->f4 = (int)0; ((struct Obj03468 *)((char *)(a0)))->f8 = (int)0; ((struct Obj03468 *)((char *)(a0)))->fC = (int)1; ((struct Obj03468 *)((char *)(a0)))->f10 = (int)0; ((struct Obj03468 *)((char *)(a0)))->f14 = (int)0x1000; ((struct Obj03468 *)((char *)(a0)))->f18 = (int)0; ((struct Obj03468 *)((char *)(a0)))->f1C = (int)0; return 0x1000; }
