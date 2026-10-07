/*
 * file:     unit_021BF050_p20.c
 * unit:     yes
 * function: func_021C17F4, func_021C18B4, func_021C18C8, func_021C1908, func_021C1968
 * address:  0x021C17F4
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
 *   func_021B97F4 0x021B97F4 thumb ov099
 *   func_021BE2A8 0x021BE2A8 thumb ov099
 *   func_0201DD68 0x0201DD68 thumb
 *   func_021BA858 0x021BA858 thumb ov099
 *   func_021C27E0 0x021C27E0 thumb ov099
 *   func_021C27E8 0x021C27E8 thumb ov099
 *   func_021C2864 0x021C2864 thumb ov099
 *   func_021B9AE0 0x021B9AE0 thumb ov099
 *   func_021C19A8 0x021C19A8 thumb ov099
 *   func_021BAEDC 0x021BAEDC thumb ov099
 *   func_021BA8EC 0x021BA8EC thumb ov099
 *   sub_0203CD98  0x0203CD98  arm
 *   func_021C282C 0x021C282C thumb ov099
 *   func_02156A3C 0x02156A3C thumb ov009
 *   func_02009B80 0x02009B80 thumb
 *   func_021BE6E4 0x021BE6E4 thumb ov099
 *   func_021BDD48 0x021BDD48 thumb ov099
 *   func_021BDD54 0x021BDD54 thumb ov099
 *   func_021BDE30 0x021BDE30 thumb ov099
 *   func_021C27D4 0x021C27D4 thumb ov099
 *   func_021C27DC 0x021C27DC thumb ov099
 *   func_021C24A4 0x021C24A4 thumb ov099
 */
#include "../../matched/include/Obj02803.h"
#include "../../matched/include/Obj22058.h"
#include "../../matched/include/Obj00008.h"

struct Sub020097BCObj;
typedef unsigned char u8;

typedef unsigned int   u32_021C17F4;

typedef unsigned short u16;

typedef unsigned long  u32_021C18B4;

typedef signed char    s8;

typedef signed short   s16;

typedef signed long    s32;

typedef int BOOL;

typedef struct {
    char pad[0x46];
    u8 f46;                 /* 0x46 */
} Sub;

typedef struct {
    char pad[8];
    void *f8;               /* 0x008 */
    char pad0c[0x23c];
    Sub *f248;              /* 0x248 */
} Work;

extern int func_021B97F4(char *);
extern void *func_021BE2A8(char *, int);
extern void func_0201DD68(void);
extern u32_021C17F4 func_021BA858(char *p);
extern u8 func_021C27E0(void *);
extern void func_021C27E8(void *, u8);
extern void func_021C2864(void *, u8);
extern void func_021B9AE0(void *w, u8 *s);
extern void func_021C19A8(char *);
extern void func_021BAEDC(char *);
extern void func_021BA8EC(char *);
extern int sub_0203CD98(void);
extern int func_021C282C(u8 *);
extern int func_02156A3C(void);
extern void func_02009B80(struct Sub020097BCObj *obj, int i);
extern void func_021BE6E4(char *);
extern u8 func_021BDD48(char *, void *);
extern int func_021BDD54(char *, void *);
extern void func_021BDE30(void *, int, int);
extern void func_021C27D4(void *, u8);
extern void func_021C27DC(void *, u8);
extern void func_021C24A4(char *, int);
int func_021C17F4(char *p, int state);
int func_021C18B4(int a, int b);
void func_021C18C8(char *p, int kind, int value);
void func_021C1908(char *p, int kind, int value);
void func_021C1968(Work *w);

/*
 * lever: func_021C27E0 returns u8, eliminating the redundant narrowing at 021C1848.
 */
int func_021C17F4(char *p, int state)
{
    void *selection;
    int result;
    selection = func_021BE2A8(p, func_021B97F4(p + 0x274));
    func_0201DD68();
    result = func_021BA858(p);
    if (result == -1) return state;
    if (result == 0) {
        func_021C27E8(((struct Obj02803 *)p)->f8, 1 - func_021C27E0(((struct Obj02803 *)p)->f8));
        func_021C2864(((struct Obj02803 *)p)->f8, func_021C27E0(((struct Obj02803 *)p)->f8));
        ((struct Obj02803 *)p)->f1356 = 2 - ((struct Obj22058 *)(*(char * *)&((struct Obj02803 *)p)->f248))->f46;
        ((struct Obj02803 *)p)->f1CC = 118;
    } else {
        ((struct Obj02803 *)p)->f135C = 0;
        func_021C18C8(p, 1, 2);
        ((struct Obj02803 *)p)->f1F0 = -1;
        if (selection != 0) func_021B9AE0(p + 0x274, selection);
        func_021C19A8(p);
        func_021BAEDC(p);
        ((struct Obj02803 *)p)->f1CC = 11;
    }
    func_021BA8EC(p);
    return state;
}


/*
 * Returns the second argument, or 2 when sub_0203CD98 reports 0.
 */
int func_021C18B4(int a, int b)
{
    int r = b;

    if (sub_0203CD98() == 0) {
        r = 2;
    }

    return r;
}

void func_021C18C8(char *p, int kind, int value)
{
    if (*(u8 * *)&((struct Obj00008 *)p)->f8 != 0) {
        if (kind == 1 && value == 2) func_021C282C(*(u8 * *)&((struct Obj00008 *)p)->f8);
        if (kind == 4 && value < 3) func_02009B80(((struct Obj00008 *)p)->f4, func_02156A3C());
        func_021C1908(p, kind, value);
        func_021BE6E4(p);
    }
}

void func_021C1908(char *p, int kind, int value)
{
    int old;
    int oldvalue;
    if (((struct Obj00008 *)p)->f8 != 0) {
        old = func_021BDD48(p, ((struct Obj00008 *)p)->f8);
        oldvalue = func_021BDD54(p, ((struct Obj00008 *)p)->f8);
        if (old != kind || oldvalue != value) {
            func_021BDE30(p, kind, value);
            func_021C27D4(((struct Obj00008 *)p)->f8, kind);
            func_021C27DC(((struct Obj00008 *)p)->f8, value);
            if (!(value == 5 && kind == 4)) {
                if (kind != 4) func_021C24A4(p, 127);
            }
        }
        func_021BAEDC(p);
    }
}


void func_021C1968(Work *w)
{
    w->f248->f46 = 1 - w->f248->f46;
    func_021C27E8(w->f8, w->f248->f46);
    func_021C2864(w->f8, w->f248->f46);
    func_021BE6E4((char *)w);
    func_021C27E0(w->f8);
}
