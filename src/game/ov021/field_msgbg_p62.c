/*
 * file:     field_msgbg_p62.c
 * unit:     yes
 * function: func_02190A14, func_02190A20
 * address:  0x02190A14
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02020234  0x02020234  thumb
 *   func_0201F81C  0x0201F81C  thumb
 */
#include "../../matched/include/Obj19590.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

extern void func_02020234(u8 *p);
extern void func_0201F81C();
void func_02190A14(u8 *p);
void func_02190A20(void);


/*
 * Unlabelled leaf (no lr save): forwards p->f10 to func_02020234.
 *
 * Addresses are Black-image addresses.
 */
void func_02190A14(u8 *p)
{
    func_02020234((u8 *)(((struct Obj19590 *)p)->f10));
}


/*
 * Tail-call thunk: forwards to func_0201F81C with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_02190A20(void)
{
    func_0201F81C();
}
