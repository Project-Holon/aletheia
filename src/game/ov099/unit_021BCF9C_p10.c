/*
 * file:     unit_021BCF9C_p10.c
 * unit:     yes
 * function: func_021BD814, func_021BD838, func_021BD864, func_021BD888
 * address:  0x021BD814
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
 *   func_0203D7B0 0x0203D7B0 arm
 *   func_0203D7BC 0x0203D7BC arm
 *   func_021BAAB8  0x021BAAB8  thumb  ov099
 *   func_021BA928  0x021BA928  thumb  ov099
 *   func_021BA828  0x021BA828  thumb  ov099
 *   func_0201DD68 0x0201DD68 thumb
 *   func_021BA858 0x021BA858 thumb ov099
 *   func_021BA8EC 0x021BA8EC thumb ov099
 */
#include "../../matched/include/Obj13692.h"
#include "../../matched/include/Obj12117.h"
#include "../../matched/include/Obj18241.h"
#include "../../matched/include/Obj00008.h"
#include "../../matched/include/Obj13693.h"
#include "../../matched/include/Obj13694.h"

typedef unsigned char u8;

typedef unsigned int u32_021BD814;

typedef unsigned short u16;

typedef unsigned long  u32_021BD838;

typedef signed char    s8;

typedef signed short   s16;

typedef signed long    s32;

typedef unsigned long  u32_021BD864;

typedef int BOOL;

typedef unsigned int   u32_021BD888;

extern void func_0203D7B0(u8 a0);
extern void func_0203D7BC(u8 a0);
extern void func_021BAAB8(char *p, int a, int b);
extern int func_021BA928(void *p);
extern void func_021BA828(char *p);
extern void func_0201DD68(void);
extern u32_021BD888 func_021BA858(char *p);
extern void func_021BA8EC(char *);
int func_021BD814(char *p, int v);
int func_021BD838(char *p, int v);
int func_021BD864(char *p, int v);
int func_021BD888(char *p, int v);
int func_021BD8C0(char *p, int v);

int func_021BD814(char *p, int v)
{
    int zero = 0;
    func_0203D7B0(zero);
    func_0203D7BC(zero);
    ((struct Obj13692 *)p)->f1E0 = zero;
    ((struct Obj13692 *)p)->f1CC = 0x91;
    return v;
}


int func_021BD838(char *p, int v)
{
    u8 b = ((struct Obj18241 *)(*(char * *)&((struct Obj12117 *)p)->f248))->f45;
    int a;

    if (b != 0) {
        a = 0x48;
    } else {
        a = 0x49;
    }

    func_021BAAB8(p, a, 0);
    ((struct Obj12117 *)p)->f1CC = 0x7E;
    return v;
}


/*
 * Early-returns the selector when the guard is false, else runs the setup and stamps 0x7F.
 */
int func_021BD864(char *p, int v)
{
    if (func_021BA928(p) == 0) {
        return v;
    }

    func_021BA828(p);
    *(u32_021BD864 *)&((struct Obj00008 *)p)->f1CC = 0x7F;
    return v;
}

int func_021BD888(char *p, int v)
{
    int t;
    func_0201DD68();
    t = func_021BA858(p);
    if (t == -1) return v;
    if (t == 0) {
        ((struct Obj13693 *)p)->f1CC = 0x80;
    } else {
        ((struct Obj13693 *)p)->f1CC = 0x86;
    }
    func_021BA8EC(p);
    return v;
}

int func_021BD8C0(char *p, int v)
{
    ((struct Obj13694 *)p)->f1353 = 0x4a;
    ((struct Obj13694 *)p)->f1CC = 0x8a;
    return v;
}
