/*
 * file:     unit_021BF050_p19.c
 * unit:     yes
 * function: func_021C1768, func_021C17D4
 * address:  0x021C1768
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
 *   func_021BA928 0x021BA928 thumb ov099
 *   func_021BA858 0x021BA858 thumb ov099
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 *   func_021BC090 0x021BC090 thumb ov099
 *   func_021BA8EC 0x021BA8EC thumb ov099
 *   func_0203C554 0x0203C554 arm
 *   func_021BA828  0x021BA828  thumb  ov099
 */
#include "../../matched/include/Obj00008.h"

typedef unsigned int   u32_021C1768;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned long  u32_021C17D4;

typedef signed char    s8;

typedef signed short   s16;

typedef signed long    s32;

typedef int BOOL;

extern int func_021BA928(char *, int);
extern u32_021C1768 func_021BA858(char *p);
extern void func_021BAAB8(char *, int, int);
extern void func_021BC090(char *);
extern void func_021BA8EC(char *);
extern void func_0203C554(u32_021C1768 a);
extern void func_021BA828(char *p);
int func_021C1768(char *p, int ret);
int func_021C17D4(char *p, int v);

/*
 * follower: two zero alignment bytes at 0x021C17D2.
 */
int func_021C1768(char *p, int ret)
{
    int choice;
    if (func_021BA928(p, ret) == 0) return ret;
    choice = func_021BA858(p);
    if (choice == -1) return ret;
    if (choice == 0) {
        func_021BAAB8(p, 76, 0);
        func_021BC090(p);
        ((struct Obj00008 *)p)->f244 = 1;
        ((struct Obj00008 *)p)->f1CC = 41;
        ((struct Obj00008 *)p)->f1E0 = 30;
    } else {
        func_021BA8EC(p);
        func_0203C554(1);
        ((struct Obj00008 *)p)->f1E0 = 20;
        ((struct Obj00008 *)p)->f1CC = 57;
    }
    return ret;
}


int func_021C17D4(char *p, int v)
{
    if (func_021BA928(p, v) != 0) {
        func_021BA828(p);
        *(u32_021C17D4 *)&((struct Obj00008 *)p)->f1CC = 0x38;
    }

    return v;
}
