/*
 * file:     union_comm_p12.c
 * unit:     yes
 * function: func_02173CCC, func_02173D38
 * address:  0x02173CCC
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02034714  0x02034714  arm
 *   func_02183BE8  0x02183BE8  thumb  ov022
 *   func_020399A8  0x020399A8  arm
 *   func_02008468  0x02008468  thumb
 *   func_02012944  0x02012944  thumb
 *   func_0203D3F8  0x0203D3F8  arm
 */
#include "../../matched/include/Obj05918.h"
#include "../../matched/include/Obj12448.h"
#include "../../matched/include/Obj19262.h"

struct Entry;
typedef unsigned char u8;

typedef unsigned int   u32;

extern void func_02034714(const char *expr, u32 line, const char *file);
extern int func_02183BE8(u8 *s, int i);
extern struct Entry *func_020399A8(void);
extern int func_02008468(void);
extern u8 *func_02012944(void *p);
extern u32 func_0203D3F8(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
void func_02173CCC(int a, int x, int y, u8 *p);
u32 func_02173D38(u8 *p);


void func_02173CCC(int a, int x, int y, u8 *p)
{
    if (((struct Obj05918 *)p)->f3528 == 0) {
        func_02034714((void *)0x02175624, 0, (void *)0x02175624);
        p[0x282D] |= (u8)(1 << a);
        return;
    }
    if (func_02183BE8((u8 *)(((struct Obj05918 *)p)->f3528), (u8)a) == 1) {
        p[0x282C] |= (u8)(1 << a);
        return;
    }
    p[0x282D] |= (u8)(1 << a);
}


u32 func_02173D38(u8 *p)
{
    p[0x282B] = 0;
    return func_0203D3F8((u32)func_020399A8(), 0, 0x140A, func_02008468(),
                  (u32)func_02012944((void *)(((struct Obj19262 *)(*(u8 * *)&((struct Obj12448 *)p)->f0))->f8)), 1, 0, 0);
}
