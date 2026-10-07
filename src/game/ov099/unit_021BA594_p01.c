/*
 * file:     unit_021BA594_p01.c
 * unit:     yes
 * function: func_021BA594, func_021BA5B4, func_021BA5DC, func_021BA5F0
 * address:  0x021BA594
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
 *   func_021C5F44  0x021C5F44  thumb  ov127
 *   func_021C49A4 0x021C49A4 thumb ov127
 *   func_021BA2D4  0x021BA2D4  thumb
 *   func_021BA264  0x021BA264  thumb  ov099
 *   func_021BA2A4  0x021BA2A4  thumb  ov099
 */
#include "../../matched/include/Obj13682.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned long  u32;

typedef signed char    s8;

typedef signed short   s16;

typedef signed long    s32;

typedef int BOOL;

typedef struct {
    char pad[0x18];
    void *f18;
} S;

extern void func_021C5F44(void *a, void *b);
extern int func_021C49A4(u8 *, unsigned int);
extern void func_021BA2D4(void);
extern void func_021BA264(void *a, void *b);
extern void func_021BA2A4(void *w, u8 *s);
void func_021BA594(char *p, int a, int b, int c);
void func_021BA5B4(void *a, int b, u8 **p);
BOOL func_021BA5DC(S *s);
void func_021BA5F0(void *a, char *b, u8 c);


void func_021BA594(char *p, int a, int b, int c)
{
    struct S { u16 a; u8 b; u8 c; } s;

    s.a = a;
    s.b = b;
    s.c = c;
    func_021C5F44(((struct Obj13682 *)p)->f59C, &s);
}

void func_021BA5B4(void *a, int b, u8 **p) {
    int c = func_021C49A4(*p, 6);
    int d = func_021C49A4(*p, 4);
    func_021BA594(a,b,c,d);
}


/*
 * True unless the pointer at +0x18 is func_021BA2D4 itself.
 */
BOOL func_021BA5DC(S *s)
{
    if (s->f18 != (void *)func_021BA2D4) {
        return 1;
    }

    return 0;
}


/*
 * Dispatches on the class byte: case 0 runs func_021BA264, case 1 runs
 * func_021BA2A4, then the class is recorded at +0x0B of the object.  The pair
 * is a switch, not an if/else-if chain: only the switch form lays the case
 * bodies out of line the way the image does.
 */
void func_021BA5F0(void *a, char *b, u8 c)
{
    switch (c) {
    case 0:
        func_021BA264(a, b);
        break;
    case 1:
        func_021BA2A4(a, (u8 *)b);
        break;
    }

    b[0xB] = c;
}
