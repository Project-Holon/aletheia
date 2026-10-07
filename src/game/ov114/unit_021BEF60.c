/*
 * file:     unit_021BEF60.c
 * unit:     yes
 * function: func_021BEF60, func_021BEF6C, func_021BEF98, func_021BEFA4
 * address:  0x021BEF60
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_021CF984  0x021CF984  data
 *   g_021CF98C  0x021CF98C  data
 *   g_021CF9C0  0x021CF9C0  data
 *   g_021CF964  0x021CF964  data
 *   func_021BEC48  0x021BEC48  arm  ov114
 *   func_021B9B4C  0x021B9B4C  arm  ov114
 */
#include "../../matched/include/G_Conn.h"

typedef unsigned char u8;

typedef unsigned int u32;

extern u32 func_021BEC48(void);
extern void func_021B9B4C(int *mutex_p);
void func_021BEF60(u8 *p, u32 v);
void func_021BEF6C(void);
void func_021BEF98(u8 *p);
void func_021BEFA4(u8 *p);
extern struct Conn *g_021CF984;

/*
 * Null-guarded word setter at +0x2c.
 */
void func_021BEF60(u8 *p, u32 v)
{
    if (p != 0)
        *(u32 *)(p + 0x2c) = v;
}


/*
 * Drains the module list, then empties the module head pointer.
 */
void func_021BEF6C(void)
{
    if ((*(u32 *)&g_021CF984) != 0)
        func_021BEC48();
    (*(u32 *)&g_021CF984) = 0;
}

void func_021BEF98(u8 *p)
{
    *(u32 *)(p + 0x18) = 0;
}


/*
 * One-shot bring-up: zeroes the +0x18 block once and latches the flag.
 */
void func_021BEFA4(u8 *p)
{
    if (*(u32 *)(p + 0x18) != 0)
        return;
    func_021B9B4C((int *)p);
    *(u32 *)(p + 0x18) = 1;
}
