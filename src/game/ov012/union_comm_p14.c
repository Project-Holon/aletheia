/*
 * file:     union_comm_p14.c
 * unit:     yes
 * function: func_02173E1C, func_02173E40, func_02173E68, func_02173E90, func_02173EC8, func_02173EEC
 * address:  0x02173E1C
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
 *   func_0203D3F8  0x0203D3F8  arm
 *   func_02034714  0x02034714  arm
 *   func_02183F7C  0x02183F7C  thumb ov022
 *   func_0203D378  0x0203D378  arm
 *   func_02183F88  0x02183F88  thumb ov022
 *   func_02183F98  0x02183F98  thumb ov022
 */
#include "../../matched/include/Obj19265.h"
#include "../../matched/include/Obj19266.h"
#include "../../matched/include/Obj19267.h"

struct Entry;
typedef unsigned char u8;

typedef unsigned int u32;

extern struct Entry *func_020399A8(void);
extern u32 func_0203D3F8(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_02183F7C(u8 *p);
extern u32 func_0203D378(void);
extern void func_02183F88(u8 *p, u8 a);
extern void func_02183F98(void *p, const void *value);
u32 func_02173E1C(void);
void func_02173E40(int a, int b, int c, u8 *p);
u32 func_02173E68(u32 a);
void func_02173E90(int a, int b, int c, u8 *p);
int func_02173EC8(void);
void func_02173EEC(int a, int b, void *value, u8 *p);


u32 func_02173E1C(void)
{
    return func_0203D3F8((u32)func_020399A8(), 0, 0x140D, 0, 0, 1, 0, 0);
}


/*
 * lever:    Nested null recheck retains the original dead second bne.
 */
void func_02173E40(int a, int b, int c, u8 *p)
{
    u8 *q;
    q = *(u8 * *)&((struct Obj19265 *)p)->f3528;
    if (q == 0) {
        if (q == 0) {
            func_02034714((void *)0x02175624, 0, (void *)0x02175624);
            return;
        }
    } else {
        func_02183F7C(q);
    }
}


u32 func_02173E68(u32 a)
{
    return func_0203D3F8((u32)func_020399A8(), a, 0x140E, 0, 0, 1, 0, 0);
}


void func_02173E90(int a, int b, int c, u8 *p)
{
    u8 *q;
    if (func_0203D378() != 0) {
        q = *(u8 * *)&((struct Obj19266 *)p)->f3528;
        if (q == 0) {
            if (q == 0) {
                func_02034714((void *)0x02175624, 0, (void *)0x02175624);
                return;
            }
        } else {
            func_02183F88(q, (u8)a);
        }
    }
}


int func_02173EC8(void)
{
    return func_0203D3F8((u32)func_020399A8(), 0, 0x140F, 0, 0, 1, 0, 0);
}


void func_02173EEC(int a, int b, void *value, u8 *p)
{
    u8 *q;
    if (func_0203D378() != 1) {
        q = *(u8 * *)&((struct Obj19267 *)p)->f3528;
        if (q == 0) {
            func_02034714((void *)0x02175624, 0, (void *)0x02175624);
            return;
        }
        func_02183F98(q, value);
    }
}
