/*
 * file:     unit_021BF050_p06.c
 * unit:     yes
 * function: func_021C0274, func_021C0290, func_021C02C8, func_021C047C
 * address:  0x021C0274
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
 *   func_021BAAB8  0x021BAAB8  thumb  ov099
 *   func_021BA8BC 0x021BA8BC thumb ov099
 *   func_0202020C 0x0202020C thumb
 *   func_0201F868 0x0201F868 thumb
 *   func_021BA8EC 0x021BA8EC thumb ov099
 *   func_0201AC80 0x0201AC80 thumb
 *   func_021B9B64 0x021B9B64 thumb ov099
 *   func_021BA928 0x021BA928 thumb ov099
 *   func_020200CC 0x020200CC thumb
 *   func_021C2408 0x021C2408 thumb ov099
 *   func_021BB954 0x021BB954 thumb ov099
 *   func_021C23C8 0x021C23C8 thumb ov099
 *   func_021BDDD0 0x021BDDD0 thumb ov099
 *   func_0202EB14 0x0202EB14 thumb
 *   func_0202EB0C 0x0202EB0C thumb
 *   func_021C23D8 0x021C23D8 thumb ov099
 *   func_021C18C8  0x021C18C8  thumb  ov099
 */
#include "../../matched/include/Obj18266.h"
#include "../../matched/include/Obj00008.h"
#include "../../matched/include/Obj09203.h"

struct Obj;
struct W;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned long  u32_021C0274;

typedef signed char    s8;

typedef signed short   s16;

typedef signed long    s32;

typedef int BOOL;

typedef unsigned int   u32_021C0290;

typedef unsigned int u32_021C02C8;

typedef unsigned long  u32_021C047C;

extern void func_021BAAB8(char *p, int a, int b);
extern int func_021BA8BC(void *p);
extern void func_0202020C(struct Obj *,u16 *,u16 *);
extern u32_021C0290 func_0201F868(void *p);
extern void func_021BA8EC(char *);
extern u32_021C02C8 func_0201AC80(void *);
extern void func_021B9B64(char *);
extern int func_021BA928(struct W *);
extern int func_020200CC(struct Obj *);
extern void func_021C2408(char *);
extern void func_021BB954(char *, int);
extern int func_021C23C8(void *a, void *b);
extern int func_021BDDD0(char *);
extern int func_0202EB14(void);
extern u32_021C02C8 func_0202EB0C(void);
extern void func_021C23D8(char *, int);
extern void func_021C18C8(char *p, int a, int b);
int func_021C0274(char *p, int v);
void func_021C0290(char *p);
int func_021C02C8(char *p, int ret);
int func_021C047C(char *p, int v);


int func_021C0274(char *p, int v)
{
    func_021BAAB8(p, 5, 0);
    ((struct Obj18266 *)p)->f1CC = 0x1D;
    return v;
}

/*
 * Extent ends with two-byte alignment padding at 0x021C02C6.
 */
void func_021C0290(char *p) {
 if (((struct Obj00008 *)p)->f1A4) {
  ((struct Obj00008 *)p)->f1A4=(void *)func_021BA8BC(((struct Obj00008 *)p)->f1A4);
  func_0202020C(*(struct Obj * *)&((struct Obj00008 *)p)->fBC,0,(u16 *)(p+0x23c));
  func_0201F868(((struct Obj00008 *)p)->fB8);
  func_021BA8EC(p);
 }
}

int func_021C02C8(char *p, int ret)
{
    u32_021C02C8 choice;
    u8 *q;
    func_0201AC80(((struct Obj00008 *)p)->fC8);
    func_021B9B64(p + 0x274);
    if (!func_021BA928((struct W *)p)) return ret;
    choice = func_020200CC(*(struct Obj * *)&((struct Obj00008 *)p)->fBC);
    switch (choice) {
    case (u32_021C02C8)-1:
        return ret;
    case (u32_021C02C8)-2:
        ((struct Obj00008 *)p)->f1CC = 11;
        func_021C0290(p);
        func_021C2408(p);
        return ret;
    case 7:
        func_021C0290(p);
        q = *(u8 * *)&((struct Obj00008 *)p)->f248;
        ((struct Obj00008 *)p)->f134C = q[0x21];
        ((struct Obj00008 *)p)->f134E = q[0x22];
        q[0x48] = q[0x20];
        func_021BB954(p, 1);
        ((struct Obj00008 *)p)->f1CC = 0x54;
        return ret;
    case 4:
        if ((*(u8 **)(p + 0x248))[0x46] == 0) return ret;
        func_021C0290(p);
        func_021C23C8(p, (void *)-1);
        ((struct Obj00008 *)p)->f1CC = 0x9e;
        break;
    case 6:
        if (func_021BDDD0(p) == 0) {
            *(int *)&((struct Obj00008 *)p)->f1A4 = func_021BA8BC(((struct Obj00008 *)p)->f1A4);
            func_0202020C(*(struct Obj * *)&((struct Obj00008 *)p)->fBC, 0, (u16 *)(p + 0x23c));
            func_0201F868(((struct Obj00008 *)p)->fB8);
            func_021BA8EC(p);
            func_021BAAB8(p, 0x79, 0);
            ((struct Obj00008 *)p)->f1CC = 0x71;
            return ret;
        } else {
            func_021C0290(p);
            func_021C23C8(p, (void *)-1);
            ((struct Obj00008 *)p)->f1CC = 0x9e;
        }
        break;
    case 5:
        if ((*(u8 **)(p + 0x248))[0x46] == 0) return ret;
        if (func_0202EB14() == 0 && func_0202EB0C() != 0) {
            func_021C0290(p);
            func_021BAAB8(p, 0x95, 0);
            ((struct Obj00008 *)p)->f1CC = 0xa0;
            return ret;
        } else {
            func_021C0290(p);
            func_021C23C8(p, (void *)-1);
            ((struct Obj00008 *)p)->f1CC = 0x9e;
        }
        break;
    case 0: case 1: case 2: case 3: default:
        break;
    }
    func_021C23D8(p, 1);
    ((struct Obj00008 *)p)->f1E0 = 0;
    ((struct Obj00008 *)p)->f246 = choice;
    ((struct Obj00008 *)p)->f1CC = 0xad;
    return ret;
}


/*
 * Ages the counter at +0x1E0 and, when it underflows, hands the halfword at
 * +0x246 to func_021C18C8 with mode 2 and stamps selector 0x9E.  The image
 * branches on the subs flags themselves (bpl), so the condition is the
 * decremented value, written as a prefix -- on the dereference.
 */
int func_021C047C(char *p, int v)
{
    if (--((struct Obj09203 *)p)->f1E0 < 0) {
        func_021C18C8(p, 2, ((struct Obj09203 *)p)->f246);
        ((struct Obj09203 *)p)->f1CC = 0x9E;
    }

    return v;
}
