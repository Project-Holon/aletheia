/*
 * file:     eventdata_system_p03.c
 * unit:     yes
 * function: func_0216208C, func_0216209C, func_021620A0, func_021620B0, func_0216210C, func_02162120, func_02162198, func_021621C0
 * address:  0x0216208C
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
 *   func_02162358  0x02162358  thumb  ov010
 *   func_021622F4  0x021622F4  thumb  ov010
 *   func_02161ECC  0x02161ECC  thumb
 *   func_02161E78  0x02161E78  thumb
 *   func_02082D44  0x02082D44  arm
 *   func_0200FB24  0x0200FB24  thumb
 *   func_0216230C  0x0216230C  thumb
 *   func_02162254  0x02162254  thumb
 *   func_02162278  0x02162278  thumb
 *   d_02172990     0x02172990  data  ov010  a4
 *   func_02161DC4 0x02161DC4 thumb ov010
 */
#include "../../matched/include/Obj18951.h"
#include "../../matched/include/Obj18952.h"

typedef unsigned short u16;

typedef unsigned char u8;

typedef unsigned int u32;

typedef int (*Fn)(int, int, u16 *, u16 *);

typedef struct { unsigned x; u16 b; u16 t; } S;

extern int func_02162358();
extern int func_021622F4();
extern int func_02161ECC(char *);
extern void func_02161E78(void *a0);
extern void func_02082D44(char *, char *, int);
extern u32 func_0200FB24(void);
extern void func_0216230C(char *p, unsigned i);
extern int func_02162254(char *p, u16 index, u16 *out);
extern void func_02162278(char *p, int index, u16 a, u16 b);
extern char *func_02161DC4(char *, int, unsigned);
/* * Unlabelled Thumb leaf (no lr save, prints as .word data in the listing), * called from ov020 func_021871F8. */ int func_0216208C(char *p, int unused);
u16 func_0216209C(char *p);
int func_021620A0(int a0);
/* * pass 3 2026-10-06 P3L07: EXACT. The list is compacted: each empty 0x18-byte entry takes the next * used entry after it. The copy destination is written through a second base name dst (= p) under * pragma opt_propagation off, so `i * 0x18` is a common subexpression of two different bases. The * front end then makes the offset its own temporary local, which takes the stack slot below the * named counter i (sp+0 under sp+4), as in the image. With one base name the offset was a back-end * spill temporary above i (7 B, 92/92); without the pragma dst folds into p (7 B). */ void func_021620B0(char *p);
int func_0216210C(int a0);
void func_02162120(int a, int b, int c);
int func_02162198(int unused, char *p, const S *s, S *out);
int func_021621C0(int unused, char *p, const S *s, S *out);
extern Fn d_02172990[];



/*
 * Unlabelled Thumb leaf (no lr save, prints as .word data in the listing),
 * called from ov020 func_021871F8.
 */
int func_0216208C(char *p, int unused)
{
    if (((struct Obj18951 *)p)->f2 & 8)
        return 1;
    return 0;
}



u16 func_0216209C(char *p)
{
    return ((struct Obj18952 *)p)->f26;
}



int func_021620A0(int a0)
{
    int t4;

t4 = a0 + 0;
    a0 = func_02162358(a0);
loc_021620A8:
a0 = t4 + 0;
    a0 = func_021622F4(a0);
loc_021620AE:
    return a0;}



#pragma opt_propagation off


/*
 * pass 3 2026-10-06 P3L07: EXACT. The list is compacted: each empty 0x18-byte entry takes the next
 * used entry after it. The copy destination is written through a second base name dst (= p) under
 * pragma opt_propagation off, so `i * 0x18` is a common subexpression of two different bases. The
 * front end then makes the offset its own temporary local, which takes the stack slot below the
 * named counter i (sp+0 under sp+4), as in the image. With one base name the offset was a back-end
 * spill temporary above i (7 B, 92/92); without the pragma dst folds into p (7 B).
 */
void func_021620B0(char *p)
{
    int i;
    int j;
    char *dst;

    dst = p;
    i = 0;
    do {
        if (func_02161ECC(p + i * 0x18) == 0) {
            for (j = i + 1; j < 10; j++) {
                if (func_02161ECC(p + j * 0x18) != 0) {
                    func_02082D44(p + j * 0x18, dst + i * 0x18, 0x18);
                    func_02161E78(p + j * 0x18);
                    break;
                }
            }
        }
        i++;
    } while (i < 10);
}


#pragma opt_propagation reset



int func_0216210C(int a0)
{

    a0 = func_0200FB24();
loc_02162112:
    if (a0 == 0) goto loc_0216211A;
loc_02162116:
a0 = 1;
    return a0;
loc_0216211A:
a0 = 0;
    return a0;}



void func_02162120(int a, int b, int c)
{
    u16 t[4];
    u16 s[4];
    int i;
    int r;

    for (i = 0; i < 3; i++) {
        if ((c & (1 << i)) == 0) {
            func_0216230C((char *)a, (u16)i);
        } else if (func_02162254((char *)a, i, s) != 0) {
            r = d_02172990[s[3]](a, b, s, t);
            func_0216230C((char *)a, (u16)i);
            if (r != 0)
                func_02162278((char *)a, (u16)i, t[2], t[3]);
        }
    }
}


int func_02162198(int unused, char *p, const S *s, S *out)
{
    out->x = s->x;
    out->b = s->b;
    if (func_02161DC4(p, s->b, 1) != 0) out->t = 0;
    else out->t = 1;
    return 1;
}


int func_021621C0(int unused, char *p, const S *s, S *out)
{
    out->x = s->x;
    out->b = s->b;
    if (func_02161DC4(p, s->b, 1) != 0) out->t = 2;
    else out->t = 3;
    return 1;
}
