/*
 * function: func_021BC2C0
 * address: 0x021BC2C0
 * packet: pkt_ov099_021BC2C0
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Lever: case4/case5 guard is a switch, retaining two compares; an equality disjunction folds to a range.
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045334 0x02045334 arm
 *   func_020200CC 0x020200CC thumb
 *   func_021BA8EC 0x021BA8EC thumb ov099
 *   func_021BA8BC 0x021BA8BC thumb ov099
 *   func_0202020C 0x0202020C thumb
 *   func_0201F868 0x0201F868 thumb
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 *   func_0202EB14 0x0202EB14 thumb
 *   func_0202EB0C 0x0202EB0C thumb
 *   func_021BDDD0 0x021BDDD0 thumb ov099
 */
#include "../include/Obj00467.h"
#include "../include/Obj22023.h"
#include "../include/Obj22024.h"
#include "../include/Obj22025.h"
#include "../include/Obj22026.h"
#include "../include/Obj22027.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int     s32;
struct Descriptor;
struct Obj;
struct PrintSys;
extern void *func_02045770(struct Descriptor *p);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *d);
extern s32 func_020200CC(struct Obj *o);
extern void func_021BA8EC(char *);
extern int func_021BA8BC(void *p);
extern void func_0202020C(struct Obj *o, u16 *a, u16 *b);
extern u32 func_0201F868(void *p);
extern void func_021BAAB8(char *,int,int);
extern int func_0202EB14(void);
extern u32 func_0202EB0C(void);
extern int func_021BDDD0(char *);
int func_021BC2C0(char *p,int v)
{
    int r;
    void *q;
    q = ((struct Obj00467 *)p)->f1B8;
    if (((struct Obj00467 *)p)->f1B0 != 0) {
        if (func_0201C6C4(q,func_02045770(((struct Obj00467 *)p)->f1AC)) == 0) {
            func_02045334(((struct Obj00467 *)p)->f1AC);
            ((struct Obj00467 *)p)->f1B0=0;
        }
    }
    r=func_020200CC(((struct Obj00467 *)p)->fBC);
    switch(r) {
    case 4: case 5:
        if (((struct Obj22023 *)(*(char * *)&((struct Obj00467 *)p)->f248))->f46==0) return v;
        break;
    }
    if (r!=-1) func_021BA8EC(p);
    switch(r) {
    case -1: return v;
    case -2:
        ((struct Obj00467 *)p)->f1353=0x9b;
        ((struct Obj00467 *)p)->f1CC=0x8a;
        break;
    case 4:
        if (((struct Obj22024 *)(*(char * *)&((struct Obj00467 *)p)->f248))->f45==0) {
            func_021BAAB8(p,0x8c,0);
            ((struct Obj00467 *)p)->f1CC=0x47;
        } else {
            ((struct Obj00467 *)p)->f1353=0x4b;
            ((struct Obj00467 *)p)->f1CC=0x8a;
        }
        break;
    case 5:
        if (((struct Obj22025 *)(*(char * *)&((struct Obj00467 *)p)->f248))->f45==0) {
            func_021BAAB8(p,0x8c,0);
            ((struct Obj00467 *)p)->f1CC=0x47;
        } else if (func_0202EB14()==0 && func_0202EB0C()!=0) {
            func_021BAAB8(p,0x95,0);
            ((struct Obj00467 *)p)->f1CC=0xa4;
        } else {
            ((struct Obj00467 *)p)->f1353=0x4c;
            ((struct Obj00467 *)p)->f1CC=0x8a;
        }
        break;
    case 6:
        if (func_021BDDD0(p)==0) {
            func_021BAAB8(p,0x79,0);
            ((struct Obj00467 *)p)->f1CC=0x47;
        } else if (((struct Obj22026 *)(*(char * *)&((struct Obj00467 *)p)->f248))->f44!=((struct Obj22027 *)(*(char * *)&((struct Obj00467 *)p)->f248))->f45) {
            ((struct Obj00467 *)p)->f1352=6;
            ((struct Obj00467 *)p)->f1CC=0x7d;
        } else {
            ((struct Obj00467 *)p)->f1353=0x4d;
            ((struct Obj00467 *)p)->f1CC=0x8a;
        }
        break;
    case 7: ((struct Obj00467 *)p)->f1CC=0x4e; break;
    }
    ((struct Obj00467 *)p)->f1A4=(void *)func_021BA8BC(((struct Obj00467 *)p)->f1A4);
    func_0202020C(((struct Obj00467 *)p)->fBC,0,(u16 *)(p+0x23c));
    func_0201F868(((struct Obj00467 *)p)->fB8);
    return v;
}
