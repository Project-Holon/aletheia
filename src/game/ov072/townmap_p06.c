/*
 * file:     townmap_p06.c
 * unit:     yes
 * function: func_021BA69C, func_021BA6A8
 * address:  0x021BA69C
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BA638 0x021BA638 thumb ov072
 */
#include "../../matched/include/Obj02126.h"

typedef struct {
    int a;
    int b;
} S;

extern void func_021BA638(void *p, int *in);
void func_021BA69C(char *p, int *o);
void func_021BA6A8(char *p, const int *in);


/*
 * note:     listing extent (12) runs 2 bytes past the compiled function (10);
 *           trailing alignment padding, no byte difference.  A two-word copy
 *           at a nonzero offset is a struct assignment (hoists both loads and
 *           allocates r2/r0); two locals let the stores reorder and diff.
 */
void func_021BA69C(char *p, int *o)
{
    *(S *)o = *(S *)(p + 0x10);
}

void func_021BA6A8(char *p, const int *in) { ((struct Obj02126 *)p)->f10 = in[0] + ((struct Obj02126 *)p)->f10; ((struct Obj02126 *)p)->f14 = ((struct Obj02126 *)p)->f14 + in[1]; func_021BA638(p,(int *)(p+16)); }
