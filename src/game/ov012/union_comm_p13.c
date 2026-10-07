/*
 * file:     union_comm_p13.c
 * unit:     yes
 * function: func_02173D88, func_02173DBC, func_02173DE4
 * address:  0x02173D88
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
 *   func_020399A8  0x020399A8  arm
 *   func_0203D4D0  0x0203D4D0  arm
 *   func_0203D378  0x0203D378  arm
 *   func_02034714  0x02034714  arm
 *   func_02183F6C  0x02183F6C  thumb ov022
 */
#include "../../matched/include/Obj19264.h"

struct Entry;
typedef unsigned char u8;

typedef unsigned int u32;

extern struct Entry *func_020399A8(void);
extern u32 func_0203D4D0(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
extern u32 func_0203D378(void);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_02183F6C(u8 *p, u8 a);
int func_02173D88(u32 a);
void func_02173DB0(int a, int b, int c, u8 *p);
int func_02173DBC(int a);
void func_02173DE4(int a, int b, int c, u8 *p);


int func_02173D88(u32 a)
{
    return func_0203D4D0((u32)func_020399A8(), a, 0x140B, 0, 0, 1, 0, 0);
}


void func_02173DB0(int a, int b, int c, u8 *p)
{
    p[0x282B] = 1;
}


int func_02173DBC(int a)
{
    return func_0203D4D0((u32)func_020399A8(), a, 0x140C, 0, 0, 1, 0, 0);
}


/*
 * lever:    Nested null recheck retains the original dead second bne.
 */
void func_02173DE4(int a, int b, int c, u8 *p)
{
    u8 *q;
    if (func_0203D378() != 0) {
        q = *(u8 * *)&((struct Obj19264 *)p)->f3528;
        if (q == 0) {
            if (q == 0) {
                func_02034714((void *)0x02175624, 0, (void *)0x02175624);
                return;
            }
        } else {
            func_02183F6C(q, (u8)a);
        }
    }
}
