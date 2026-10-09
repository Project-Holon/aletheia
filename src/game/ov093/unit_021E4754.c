/*
 * file:     unit_021E4754.c
 * unit:     yes
 * function: func_021E4754, func_021E47C0, func_021E47CC, func_021E481C, func_021E4828, func_021E48B4
 * address:  0x021E4754
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021D5BB0  0x021D5BB0  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021D7D78  0x021D7D78  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021E89C0  0x021E89C0  thumb  ov093
 *   d_021F28A8     0x021F28A8  data   ov093  a4
 *   func_021D67B8  0x021D67B8  thumb  ov093
 *   func_021D5750  0x021D5750  thumb  ov093
 *   func_021E896C  0x021E896C  thumb  ov093
 *   d_021F2764     0x021F2764  data   ov093  a4
 *   d_021F2534     0x021F2534  data   ov093  a4
 */
#include "../../matched/include/Obj10090.h"

struct Unk021D62A8;
struct UtilWork;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct Word { u32 v; } Word;

typedef enum { K_0 } KType;

struct Rec { u32 f0; u32 f4; Word f8; u8 fc; u8 fd; u8 fe; u8 ff; };

extern int func_021D775C(int key);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern int func_021D5BB0(struct UtilWork *p, u32 n);
extern void *func_021C88A4(char *p, int a, int b);
extern Word func_021D7D78(int c);
extern void func_021C88C8(void *a, void *b);
extern int func_021E89C0(void);
extern u16 func_021D67B8(u8 *q);
extern int func_021D5750(u8 *q, int w);
extern Word func_021E896C(int a, int b);
void func_021E4754(int a0, u8 *s, int k);
int *func_021E47C0(int *p);
void func_021E47CC(int a0, u8 *s, int k);
int *func_021E481C(int *p);
void func_021E4828(int a0, u8 *s, int k);
int *func_021E48B4(int *p);
extern int d_021F28A8[];
extern int d_021F2764[];
extern int d_021F2534[];



void func_021E4754(int a0, u8 *s, int k)
{
    KType c = 3;
    u8 v;
    u8 *q;
    struct Rec *e;

    if (k == func_021D775C(3)) {
        v = func_021D775C(6);
        q = func_021C7CF4((int *)s, v);
        if (func_021D62C4((struct Unk021D62A8 *)q, 0xb) == 0) {
            if (func_021D5BB0((struct UtilWork *)q, 1) != 0)
                c = (u8)(c + 1);
            e = (struct Rec *)func_021C88A4((char *)s, 12, k);
            e->f4 = 0xb;
            e->f8 = func_021D7D78(c);
            e->ff = v;
            func_021C88C8(s, (u8 *)e);
        }
    }
}



int *func_021E47C0(int *p)
{
    *p = 2;
    return d_021F28A8;
}



void func_021E47CC(int a0, u8 *s, int k)
{
    u8 v;
    u8 *q;
    u8 *e;

    if (k == func_021D775C(3)) {
        v = func_021D775C(6);
        q = func_021C7CF4((int *)s, v);
        if (func_021D62C4((struct Unk021D62A8 *)q, 12) == 0) {
            e = func_021C88A4((char *)s, 12, k);
            ((struct Obj10090 *)e)->f4 = 12;
            ((struct Obj10090 *)e)->f8 = func_021E89C0();
            e[0xf] = v;
            func_021C88C8(s, e);
        }
    }
}


int *func_021E481C(int *p)
{
    *p = 1;
    return d_021F2764;
}


void func_021E4828(int a0, u8 *s, int k)
{
    KType c;
    u8 v;
    u8 *q;
    int w;
    struct Rec *e;

    if (k == func_021D775C(3)) {
        v = func_021D775C(6);
        q = func_021C7CF4((int *)s, v);
        if (func_021D62C4((struct Unk021D62A8 *)q, 0xd) == 0) {
            w = func_021D67B8(q);
            if (w != 0 && w != 0xa5 && func_021D5750(q, w) != 0) {
                c = 4;
                if (func_021D5BB0((struct UtilWork *)q, 1) != 0)
                    c = (u8)(c + 1);
                e = (struct Rec *)func_021C88A4((char *)s, 12, k);
                e->f4 = 0xd;
                e->f8 = func_021E896C(c, w);
                e->ff = v;
                func_021C88C8(s, (u8 *)e);
            }
        }
    }
}


int *func_021E48B4(int *p)
{
    *p = 1;
    return d_021F2534;
}
