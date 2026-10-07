/*
 * file:     unit_0689B514.c
 * unit:     yes
 * function: func_0689B514, func_0689B524
 * address:  0x0689B514
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0220270C 0x0220270C thumb ov094
 *   func_0689B548 0x0689B548 thumb ov095
 */
#include "../../matched/include/Obj21895.h"
#include "../../matched/include/Obj21896.h"

typedef unsigned char u8;

extern void func_0220270C(char *s, int mode, void *arg);
extern int func_0689B548(void *, int, int);
void func_0689B514(void *p, void *q);
int func_0689B524(void *p, u8 *q);

/*
 * Unlabelled C follower after the non-C veneer at 0689B504.
 */
void func_0689B514(void *p, void *q)
{
    func_0220270C(((struct Obj21895 *)p)->fB0, 5, q);
}

/*
 * Trailing 0689B546..0689B548 is Thumb alignment padding.
 */
int func_0689B524(void *p, u8 *q)
{
    int zero = 0;
    int value;
    value = func_0689B548(((struct Obj21896 *)p)->fB0, 0, 0);
    if (value != zero - 1) {
        *q = value;
        return 1;
    }
    return zero;
}
