/*
 * file:     box2_ui_p05.c
 * unit:     yes
 * function: func_021EE510, func_021EE520
 * address:  0x021EE510
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
 *   func_021EE408  0x021EE408  thumb  ov170
 *   func_0202616C  0x0202616C  thumb
 *   func_021EEFA4  0x021EEFA4  thumb  ov170
 */
#include "../../matched/include/Obj00000.h"
#include "../../matched/include/Obj18528.h"

extern void func_021EE408(char *p, int v);
extern void *func_0202616C(void **obj, unsigned idx);
extern void func_021EEFA4(char *p, unsigned char x, unsigned char y, unsigned char tx, unsigned char ty);
void func_021EE510(void *a, int tag);
void func_021EE520(char *p, unsigned idx);


/*
 * Ignore the two known tags, otherwise run the update.
 */
void func_021EE510(void *a, int tag)
{
    if (tag != 0x6 && tag != 0x7)
        func_021EE408(a, tag);
}

/*
 * Hand the two tag bytes of the p+0x2c+0x70 object to the 0x54/0x10
 * emitter.
 */
void func_021EE520(char *p, unsigned idx)
{
    unsigned char *q = func_0202616C(*(void ** *)&((struct Obj18528 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f70, idx);
    func_021EEFA4((char *)(*(int *)&((struct Obj00000 *)p)->f2C), 0x54, 0x10, q[0], q[1]);
}
