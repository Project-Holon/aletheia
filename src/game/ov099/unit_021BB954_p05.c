/*
 * file:     unit_021BB954_p05.c
 * unit:     yes
 * function: func_021BC090, func_021BC0C4, func_021BC104
 * address:  0x021BC090
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
 *   func_0202F038  0x0202F038  thumb
 *   func_0202EE8C  0x0202EE8C  thumb
 *   func_021BBD80  0x021BBD80  thumb  ov099
 *   func_021BBC0C  0x021BBC0C  thumb  ov099
 *   func_021BA8BC  0x021BA8BC  thumb  ov099
 *   func_0202020C  0x0202020C  thumb
 *   func_0201F868  0x0201F868  thumb
 *   func_02156BC4  0x02156BC4  thumb  ov009
 *   func_02156330  0x02156330  thumb  ov009
 *   func_021563C0  0x021563C0  thumb  ov009
 *   func_021C24A4  0x021C24A4  thumb  ov099
 *   func_021C2864  0x021C2864  thumb  ov099
 */
#include "../../matched/include/Obj05261.h"
#include "../../matched/include/Obj00008.h"
#include "../../matched/include/Obj13686.h"

struct Obj;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned long  u32_021BC090;

typedef int BOOL;

typedef struct {
    char pad[0x100];
    u32_021BC090 f100;
    char pad2[0x8C];
    u32_021BC090 f190;
    char pad3[0x2C];
    u32_021BC090 f1C0;
} S;

typedef unsigned int   u32_021BC0C4;

extern void func_0202F038(u8 *p);
extern u8 *func_0202EE8C(u32_021BC090 a, void *b, u8 c, u8 d, u16 e);
extern void func_021BBD80(char *s);
extern void func_021BBC0C(void *p);
extern int func_021BA8BC(void *p);
extern void func_0202020C(struct Obj *o, u16 *a, u16 *b);
extern u32_021BC0C4 func_0201F868(void *p);
extern void func_02156BC4(int);
extern int func_02156330(void);
extern void func_021563C0(int a);
extern void func_021C24A4(void *w, int v);
extern void func_021C2864(void *a, u8 v);
void func_021BC090(S *s);
void func_021BC0C4(char *p);
void func_021BC104(char *p);


/*
 * Guarded release of the handle at +0x100, then a fresh object from the
 * five-argument factory, built from the blocks at +0x1C0 and +0x190 and stored
 * back at +0x100.  The 5th argument rides on the stack (`str r0, [sp]`).
 */
void func_021BC090(S *s)
{
    if (s->f100 != 0) {
        func_0202F038((u8 *)s->f100);
        s->f100 = 0;
    }

    s->f100 = (u32_021BC090)func_0202EE8C(s->f1C0, (void *)s->f190, 0xF, 0x10, 0x21);
}


void func_021BC0C4(char *p)
{
    if (((struct Obj05261 *)p)->f1A4 != 0) {
        func_021BBD80(p);
        func_021BBC0C(p);
        ((struct Obj05261 *)p)->f1A4 = (void *)func_021BA8BC(((struct Obj05261 *)p)->f1A4);
        func_0202020C(((struct Obj05261 *)p)->fBC, 0, 0);
        func_0201F868(((struct Obj05261 *)p)->fB8);
        ((struct Obj05261 *)p)->fB8 = 0;
    }
}


void func_021BC104(char *p)
{
    char *q = *(char * *)&((struct Obj00008 *)p)->f248;

    if (((struct Obj13686 *)q)->f44 != 0 && ((struct Obj13686 *)q)->f45 != 0) {
        func_02156BC4(1);
        func_021563C0(func_02156330());
        func_021C24A4(p, 0x2A);
        func_021C2864(((struct Obj00008 *)p)->f8, 1);
    } else {
        func_021C2864(((struct Obj00008 *)p)->f8, 0);
    }
}
