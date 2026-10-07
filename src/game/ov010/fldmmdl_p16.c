/*
 * file:     fldmmdl_p16.c
 * unit:     yes
 * function: func_0216D480, func_0216D4B4, func_0216D4D4, func_0216D4DC
 * address:  0x0216D480
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0216D57C 0x0216D57C thumb ov010
 *   func_0216D570 0x0216D570 thumb ov010
 *   func_0216D7C0 0x0216D7C0 thumb ov010
 *   func_0216D7C8 0x0216D7C8 thumb ov010
 */
#include "../../matched/include/Obj17773.h"
#include "../../matched/include/Obj12057.h"

typedef unsigned int   u32;

typedef unsigned short u16;

typedef unsigned char u8;

extern u32 func_0216D57C(void *p, u32 v);
extern char *func_0216D570(char *p, u32 v);
extern void func_0216D7C0(void *p, u16 v);
extern void *func_0216D7C8(void *p, u16 v);
int func_0216D480(char *p);
void *func_0216D4B4(char *p);
int func_0216D4D4(int a0, int a1);
int func_0216D4DC(int a0, int a1, int a2);

int func_0216D480(char *p)
{
    if (func_0216D57C(p, 0x200) == 0) return 1;
    if (func_0216D57C(p, 0x400) == 0) return 0;
    func_0216D570(p, 0x600);
    return 1;
}

void *func_0216D4B4(char *p)
{
    func_0216D570(p, 0x600);
    func_0216D7C0(p, 0xff);
    return func_0216D7C8(p, 0);
}




int func_0216D4D4(int a0, int a1)
{

a0 = ((struct Obj17773 *)((char *)a0))->f0;
a0 = a0 & a1;
    return a0;}




int func_0216D4DC(int a0, int a1, int a2)
{

a2 = ((struct Obj12057 *)((char *)a0))->f0;
a1 = a1 | a2;
((struct Obj12057 *)((char *)a0))->f0 = a1;
    return a0;}
