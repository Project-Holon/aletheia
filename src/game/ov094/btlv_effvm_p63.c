/*
 * file:     btlv_effvm_p63.c
 * unit:     yes
 * function: func_021FF468, func_021FF470, func_021FF498, func_021FF4C0
 * address:  0x021FF468
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02201934  0x02201934  thumb  ov094
 *   func_02015FF0  0x02015FF0  thumb
 *   func_022019F4  0x022019F4  thumb  ov094
 *   func_020160C4  0x020160C4  thumb
 *   func_02015C30 0x02015C30 thumb
 *   func_02015C48 0x02015C48 thumb
 *   func_022018A8 0x022018A8 thumb ov094
 *   func_0220074C 0x0220074C thumb ov094
 *   func_021F935C 0x021F935C thumb ov094
 *   func_02200904 0x02200904 thumb ov094
 *   func_02200990 0x02200990 thumb ov094
 */
#include "../../matched/include/Obj12219.h"
#include "../../matched/include/Obj12220.h"
#include "../../matched/include/Obj06309.h"

typedef unsigned char u8;

typedef unsigned int u32;

typedef struct { int x, y, z; } Vec;

int func_02201934(void *u, int i, int mode);
extern int  func_022019F4(char *p, int key);
extern void func_02015FF0(char *p, int v);
extern void func_020160C4(char *p, int v);
extern void func_02015C30(void *p, u32 *out);
extern void func_02015C48(void *p, u32 *src);
extern void func_022018A8(void *, Vec *, int);
extern void func_0220074C(void *, int, int, Vec *, Vec *, int, int, int, void *, void (*)(void *), int, u8);
extern int func_021F935C(int x);
extern void func_02200904(void);
extern void func_02200990(void *p);
int func_021FF468(void *u, int i, int mode);
void func_021FF470(char *p, int key, void *v);
void func_021FF498(char *p, int key, void *v);
void func_021FF4C0(char *w, int key, int kind, Vec *q, int a, int b, int c);


int func_021FF468(void *u, int i, int mode)
{
    return func_02201934(u, i, mode);
}


/*
 * Byte-identical to the original; parked because the +0014 call to 0x02015FF0
 * (an unlabelled ARM9 leaf, no traced label) has no witness outside the
 * compared range.  The +0006 call to 0x022019F4 is an ov094 Thumb function.
 */
void func_021FF470(char *p, int key, void *v)
{
    int i = func_022019F4(p, key);
    char *e;

    if (i == -1)
        return;
    e = p + i * 0x5c;
    if (((struct Obj12219 *)e)->f8 == 0)
        return;
    func_02015FF0((char *)(((struct Obj12219 *)e)->f8), (int)v);
}


/*
 * Byte-identical to the original; parked because the call to 0x020160C4
 * (an unlabelled ARM9 leaf, no traced label) has no witness outside the
 * compared range.  The call to 0x022019F4 is an ov094 Thumb function.
 */
void func_021FF498(char *p, int key, void *v)
{
    int i = func_022019F4(p, key);
    char *e;

    if (i == -1)
        return;
    e = p + i * 0x5c;
    if (((struct Obj12220 *)e)->f8 == 0)
        return;
    func_020160C4((char *)(((struct Obj12220 *)e)->f8), (int)v);
}

void func_021FF4C0(char *w, int key, int kind, Vec *q, int a, int b, int c)
{
    int idx = func_022019F4(w, key);
    char *e;
    int off;
    Vec start;
    if (idx == -1)
        return;
    e = w + 8;
    off = idx * 0x5c;
    if (*(void **)(e + off) == 0)
        return;
    func_02015C30(*(void **)(e + off), (u32 *)&start);
    if (kind == 1) {
        if (key & 1)
            q->x = start.x - q->x;
        else
            q->x += start.x;
        q->y += start.y;
        q->z += start.z;
    }
    if (kind == 5) {
        func_022018A8(w, q, key);
        kind = 1;
    }
    if (kind == 6) {
        func_022018A8(w, q, key);
        kind = 0;
    }
    if (kind == 0) {
        func_02015C48(*(void **)(e + off), (u32 *)q);
        return;
    }
    (*(u8 *)(w + 0x542 + key))++;
    func_0220074C(w, key, kind, &start, q, a, b, c, (void *)func_02200904, func_02200990, 1, *(u8 *)(w + 0x542 + key));
    ((struct Obj06309 *)w)->f514 |= func_021F935C(key);
}
