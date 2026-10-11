/*
 * file:     unit_021E9920.c
 * unit:     yes
 * function: func_021E9920, func_021E9928
 * address:  0x021E9920
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0689A028  0x0689A028  thumb
 *   func_021F8A78  0x021F8A78  thumb  ov094
 *   func_021E9730  0x021E9730  thumb  ov093
 */
#include "../../matched/include/Obj21556.h"

struct QU;
typedef unsigned int u32;

extern void func_021F8A78(void);
extern void func_0689A028(void *p);
extern void func_021E9730(struct QU *p);
void func_021E9920(void *p);
void func_021E9928(char *p);

/*
 * leaf: only-blocker of ov093 021CEA94; parent expanded scope.
 * interface: eight-byte ldr-r3/bx-r3 stub forwards only live r0;
 * target body reads only r0. Original caller does not read result.
 */
void func_021E9920(void *p)
{
    func_021E9928(p);
}


void func_021E9928(char *p)
{
    func_021F8A78();
    func_0689A028(((struct Obj21556 *)p)->f180);
    func_021E9730((struct QU *)p);
}
