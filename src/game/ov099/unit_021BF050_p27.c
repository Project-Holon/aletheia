/*
 * file:     unit_021BF050_p27.c
 * unit:     yes
 * function: func_021C23C0, func_021C23C8, func_021C23D8, func_021C2408, func_021C2438
 * address:  0x021C23C0
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
 *   func_02156874  0x02156874  thumb  ov009
 *   func_021BA7D8  0x021BA7D8  thumb
 *   sub_0203C2B0  0x0203C2B0  arm
 *   func_021B98F8  0x021B98F8  thumb  ov099
 *   func_021BAADC  0x021BAADC  thumb  ov099
 *   func_021BA8EC  0x021BA8EC  thumb  ov099
 *   func_02005F24 0x02005F24 thumb
 */
#include "../../matched/include/Obj00008.h"
#include "../../matched/include/Obj00825.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned long  u32_021C23C0;

typedef signed char    s8;

typedef signed short   s16;

typedef signed long    s32;

typedef int BOOL;

typedef unsigned long  u32_021C23C8;

typedef unsigned long  u32_021C23D8;

typedef unsigned long  u32_021C2408;

typedef unsigned int   u32_021C2438;

extern unsigned char func_02156874(int i);
extern void func_021BA7D8(void *a);
extern int sub_0203C2B0(int a);
extern void func_021B98F8(char *p, int b);
extern void func_021BAADC(char *p, int a, int b);
extern void func_021BA8EC(char *p);
extern void func_02005F24(u32_021C2438 a0, u32_021C2438 a1);
unsigned char func_021C23C0(void *a);
int func_021C23C8(void *a, void *b);
void func_021C23D8(char *p, int v);
void func_021C2408(char *p);
int func_021C2438(char *p);


/*
 * Tail call thunk into ov009.
 */
unsigned char func_021C23C0(void *a)
{
    return func_02156874((int)a);
}


/*
 * Two arm9/overlay calls, the first on the first argument and the second on the second.
 */
int func_021C23C8(void *a, void *b)
{
    func_021BA7D8(a);
    return sub_0203C2B0((int)b);
}


/*
 * Raises the state word at +0x9B4 once, re-arms the block 0x274 bytes in, and
 * runs the six/zero setup when the selector is 1.
 */
void func_021C23D8(char *p, int v)
{
    if (((struct Obj00008 *)p)->f9B4 != 0) {
        return;
    }

    ((struct Obj00008 *)p)->f9B4 = 1;
    func_021B98F8(p + 0x274, 1);

    if (v == 1) {
        func_021BAADC(p, 6, 0);
    }
}


/*
 * When the state word at +0x9B4 is 1, clears it and tears down the two sub-objects.
 */
void func_021C2408(char *p)
{
    if (((struct Obj00008 *)p)->f9B4 != 1) {
        return;
    }

    ((struct Obj00008 *)p)->f9B4 = 0;
    func_021BA8EC(p);
    func_021B98F8(p + 0x274, 0);
    ((struct Obj00008 *)p)->f135C = 0;
}

int func_021C2438(char *p)
{
    int remaining;
    int start;
    int delta;
    if (((struct Obj00825 *)p)->f1343 != 0) {
        --((struct Obj00825 *)p)->f1343;
        remaining = ((struct Obj00825 *)p)->f1343;
        if (remaining != 0) {
            start = ((struct Obj00825 *)p)->f1342;
            delta = start - ((struct Obj00825 *)p)->f1341;
            if (delta < 0) ((struct Obj00825 *)p)->f1340 = start + (-delta / 6) * remaining;
            else ((struct Obj00825 *)p)->f1340 = start - (delta / 6) * remaining;
            func_02005F24(0xffff, ((struct Obj00825 *)p)->f1340);
            return 0;
        }
        ((struct Obj00825 *)p)->f1340 = ((struct Obj00825 *)p)->f1342;
        func_02005F24(0xffff, ((struct Obj00825 *)p)->f1342);
    }
    return 1;
}
