/*
 * file:     fldeff_splash_p11.c
 * unit:     yes
 * function: func_021C5768, func_021C576C
 * address:  0x021C5768
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "../../matched/include/Obj20207.h"

struct Obj;
typedef unsigned char u8;

typedef unsigned int u32;

extern u32 func_02020350(struct Obj *obj, u32 what);
int func_021C5768(char *p);
void func_021C576C(void *a);


/*
 * Unlabelled leaf (no lr save): returns the selection func_021C553C
 * stores at +0x18. Called from func_021C5224.
 */
int func_021C5768(char *p)
{
    return ((struct Obj20207 *)p)->f18;
}


/*
 * Raises the done flag on map object 0x13 (EXACT*: pad).
 */
void func_021C576C(void *a)
{
    *(u32 *)(func_02020350(a, 0x13) + 0x44) = 1;
}
