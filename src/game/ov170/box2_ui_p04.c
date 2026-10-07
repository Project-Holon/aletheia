/*
 * file:     box2_ui_p04.c
 * unit:     yes
 * function: func_021EE3E4, func_021EE408
 * address:  0x021EE3E4
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0202616C 0x0202616C thumb
 *   func_021EC08C 0x021EC08C thumb
 *   func_021ECC1C  0x021ECC1C  thumb  ov170
 */
#include "../../matched/include/Obj24035.h"

typedef unsigned int   u32;

extern void *func_0202616C(void **obj, u32 idx);
extern void func_021EC08C(char *p, int i, int a, int b, unsigned short c);
extern void func_021ECC1C(unsigned char *p);
void func_021EE3E4(char **p, unsigned idx);
void func_021EE408(char *p, int v);


void func_021EE3E4(char **p, unsigned idx)
{
    unsigned char *c = func_0202616C(((struct Obj24035 *)(p[11]))->f70, idx);
    func_021EC08C(p[11], 4, c[0], c[1], 0);
}

/*
 * Update the sub-object, then rebuild the panel.
 */
void func_021EE408(char *p, int v)
{
    func_021EE3E4((char **)p, v);
    func_021ECC1C((unsigned char *)p);
}
