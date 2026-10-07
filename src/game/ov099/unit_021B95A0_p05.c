/*
 * file:     unit_021B95A0_p05.c
 * unit:     yes
 * function: func_021B9B80, func_021B9BA8, func_021B9BC4, func_021B9C4C, func_021B9C9C, func_021B9CD0, func_021B9CF8, func_021B9D30, func_021B9D5C
 * address:  0x021B9B80
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
 *   func_021B9A34  0x021B9A34  thumb  ov099
 *   func_021C49A4  0x021C49A4  thumb  ov127
 *   func_021C4AC4  0x021C4AC4  thumb  ov127
 *   func_021C4A54  0x021C4A54  thumb  ov127
 *   func_021C4864  0x021C4864  thumb  ov127
 *   func_021C48D4  0x021C48D4  thumb  ov127
 *   func_021C5370  0x021C5370  thumb  ov127
 *   func_021C5F80  0x021C5F80  thumb  ov127
 *   func_021C4BA4  0x021C4BA4  thumb  ov127
 *   func_021C5590 0x021C5590 thumb ov127
 *   func_021C5664 0x021C5664 thumb ov127
 *   func_021C5608  0x021C5608  thumb  ov127
 */
#include "../../matched/include/Obj18150.h"
#include "../../matched/include/Obj18152.h"
#include "../../matched/include/Obj13679.h"
#include "../../matched/include/Obj18154.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned long  u32_021B9B80;

typedef signed char    s8;

typedef signed short   s16;

typedef signed long    s32;

typedef int BOOL;

typedef unsigned long  u32_021B9BA8;

typedef struct {
    short x, y;
} Pos;

typedef struct {
    char pad[0x570];
    void **f570;
    char pad574[0x14];
    void *f588;
} Work_021B9BC4;

typedef unsigned int   u32_021B9BC4;

typedef struct {
    char pad[0x588];
    void *f588;             /* 0x588 */
    void *f58c;             /* 0x58c */
    char pad590[0xc];
    void *f59c;             /* 0x59c */
} Work_021B9C4C;

typedef unsigned int u32_021B9C9C;

typedef unsigned long  u32_021B9CD0;

typedef unsigned long  u32_021B9CF8;

typedef unsigned int u32_021B9D30;

typedef unsigned long  u32_021B9D5C;

extern void func_021B9A34(void *p);
extern int func_021C49A4(u8 *p, unsigned int i);
extern Pos func_021C4AC4(void *v);
extern Pos func_021C4A54(Pos p, int n);
extern u32_021B9BC4 func_021C4864(u8 *p, u16 x, u16 y);
extern int func_021C5F80(void *q, int *out);
extern int func_021C5370(void *a, void *b, const u8 *desc, int *out);
extern void func_021C48D4(void *a, u8 *q);
extern u8 *func_021C4BA4(u8 *p, void *list, int n);
extern void *func_021C5590(void *,void *,u32_021B9D30,void *,int,u32_021B9D30,u32_021B9D30);
extern void func_021C5664(char *,int,int);
extern void func_021C5608(u8 *p);
void func_021B9B80(char *p);
BOOL func_021B9BA8(char *p);
int func_021B9BC4(Work_021B9BC4 *w);
void func_021B9C4C(Work_021B9C4C *w);
void func_021B9C9C(u8 *p);
void func_021B9CD0(char *p);
void *func_021B9CF8(char *p, u32_021B9CF8 *q, int c);
void func_021B9D30(u8 *p,void *q,u32_021B9D30 heap);
void func_021B9D5C(char *p);


void func_021B9B80(char *p)
{
    int i;

    for (i = 0; i < 0x30; i++) {
        if (*(u32_021B9B80 *)(p + i * 0x1C + 0x30) != 0) {
            func_021B9A34(p + 0x30 + i * 0x1C);
        }
    }
}


/*
 * True when the object 0x570 bytes in is not of class 5.
 */
BOOL func_021B9BA8(char *p)
{
    if (func_021C49A4(*(void **)((struct Obj18150 *)p)->f570, 5) == 0) {
        return 1;
    }

    return 0;
}


int func_021B9BC4(Work_021B9BC4 *w)
{
    Pos b;
    Pos d;
    int n;
    int r;

    b = func_021C4AC4(*w->f570);
    n = func_021C49A4(*w->f570, 6);
    d = func_021C4A54(b, n);
    r = func_021C4864(w->f588, d.x / 16, d.y / 16);
    if (n == 0 && r == 2)
        return 1;
    return 0;
}


void func_021B9C4C(Work_021B9C4C *w)
{
    int a;
    int b[2];

    while (func_021C5F80(w->f59c, &a) == 1) {
        if (func_021C5370(w->f588, w->f58c, (const u8 *)(&a), b) == 1)
            func_021C48D4(w->f58c, (u8 *)b);
    }
}

void func_021B9C9C(u8 *p) { int i; int offset; u8 *base; i=0; base=p+48; for(;i<48;i++) { offset=i*28; if (*(u32_021B9C9C *)(p+offset+48)) { if ((*(int (**)(void *,void *))(p+offset+64))(p,base+offset)==1) func_021B9A34(base+offset); } } }


/*
 * Walks the 0x30 records of 0x1C bytes at +0x30 and calls the handler stored
 * at +0x48 of each occupied one with (p, record).
 */
void func_021B9CD0(char *p)
{
    int i;

    for (i = 0; i < 0x30; i++) {
        if (*(u32_021B9CD0 *)(p + i * 0x1C + 0x30) != 0) {
            void (*f)(char *, char *) = *(void (**)(char *, char *))(p + i * 0x1C + 0x48);

            f(p, p + 0x30 + i * 0x1C);
        }
    }
}


/*
 * Asks the ov127 routine at 0x021C4BA4 for a handle (the word the caller
 * points at, plus the pointer at +0x58C) and then walks the 0x30 records of
 * 0x1C bytes at +0x30 looking for it; returns the record address or zero.
 * The record expression is written field-constant-first on the return
 * (`p + 0x30 + i * 0x1C`), which is the spelling whose register choice the
 * image has.
 */
void *func_021B9CF8(char *p, u32_021B9CF8 *q, int c)
{
    void *v = func_021C4BA4((void *)*q, ((struct Obj18152 *)p)->f58C, c);
    int i;

    if (v != 0) {
        for (i = 0; i < 0x30; i++) {
            if (*(void **)(p + i * 0x1C + 0x30) == v) {
                return (char *)(p + 0x30) + i * 0x1C;
            }
        }
    }
    return 0;
}

void func_021B9D30(u8 *p,void *q,u32_021B9D30 heap) { void *r; r=func_021C5590(((struct Obj13679 *)p)->f14,0,48,q,0,0,heap); ((struct Obj13679 *)p)->f590=r; func_021C5664(r,2,heap); }


/*
 * Tail call into ov127 on the pointer 0x590 bytes into the block.
 */
void func_021B9D5C(char *p)
{
    func_021C5608(((struct Obj18154 *)p)->f590);
}
