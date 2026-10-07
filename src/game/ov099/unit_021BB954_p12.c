/*
 * file:     unit_021BB954_p12.c
 * unit:     yes
 * function: func_021BC5FC, func_021BC620, func_021BC6B0
 * address:  0x021BC5FC
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BA928  0x021BA928  thumb  ov099
 *   func_021BA828  0x021BA828  thumb  ov099
 *   func_0201DD68  0x0201DD68  thumb
 *   func_021BA858  0x021BA858  thumb  ov099
 *   func_021BDDD0  0x021BDDD0  thumb  ov099
 *   func_021BAAB8  0x021BAAB8  thumb  ov099
 *   func_0202EB14  0x0202EB14  thumb
 *   func_0202EB0C  0x0202EB0C  thumb
 *   func_021BA8EC  0x021BA8EC  thumb  ov099
 *   func_020362DC  0x020362DC  arm
 */
#include "../../matched/include/Obj00008.h"
#include "../../matched/include/Obj04413.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned long  u32_021BC5FC;

typedef signed char    s8;

typedef signed short   s16;

typedef signed long    s32;

typedef int BOOL;

typedef unsigned long  u32_021BC620;

typedef unsigned int u32_021BC6B0;

extern int func_021BA928(void *p, int v);
extern void func_021BA828(char *p);
extern void func_0201DD68(void);
extern u32_021BC620 func_021BA858(char *p);
extern int func_021BDDD0(char *p);
extern void func_021BAAB8(char *p, int a, int b);
extern int func_0202EB14(void);
extern u32_021BC620 func_0202EB0C(void);
extern void func_021BA8EC(char *p);
extern u32_021BC6B0 func_020362DC(void);
int func_021BC5FC(char *p, int v);
int func_021BC620(char *p, int v);
int func_021BC6B0(char *p, int v);


int func_021BC5FC(char *p, int v)
{
    if (func_021BA928(p, v) == 0) {
        return v;
    }

    func_021BA828(p);
    *(u32_021BC5FC *)&((struct Obj00008 *)p)->f1CC = 0x50;
    return v;
}


/*
 * Lever: the +0x1CC store is written out in each arm (no early return), so the
 * compiler cross-jumps them into one shared store block.
 */
int func_021BC620(char *p, int v)
{
    int r;

    func_0201DD68();
    r = func_021BA858(p);
    if (r == -1) {
        return v;
    }
    if (r == 0) {
        if (func_021BDDD0(p) == 0 && ((struct Obj04413 *)p)->f132C == 0x4d) {
            func_021BAAB8(p, 0x79, 0);
            ((struct Obj04413 *)p)->f1CC = 0x96;
        } else if (func_0202EB14() == 0 && func_0202EB0C() != 0
                   && ((struct Obj04413 *)p)->f132C == 0x4c) {
            func_021BAAB8(p, 0x95, 0);
            ((struct Obj04413 *)p)->f1CC = 0xa6;
        } else {
            ((struct Obj04413 *)p)->f1CC = 0x52;
            func_021BA8EC(p);
        }
    } else {
        ((struct Obj04413 *)p)->f1353 = 0x90;
        ((struct Obj04413 *)p)->f1CC = 0x8a;
    }
    return v;
}


int func_021BC6B0(char *p, int v)
{
    if (func_021BA928(p, v) == 0)
        return v;
    if (func_020362DC() == 0)
        return v;
    if (*(u32_021BC6B0 *)(p + 0x135C) - 3 <= 1u)
        *(u8 *)(p + 0x1353) = 0x90;
    else
        *(u8 *)(p + 0x1353) = 0x97;
    *(u32_021BC6B0 *)(p + 0x1CC) = 0x8A;
    return v;
}
