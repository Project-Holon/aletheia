/*
 * function: func_021BC868
 * address: 0x021BC868
 * packet: pkt_ov099_021BC868
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045334 0x02045334 arm
 *   func_020200CC 0x020200CC thumb
 *   func_021BA8EC 0x021BA8EC thumb ov099
 *   func_021BA8BC 0x021BA8BC thumb ov099
 *   func_0202020C 0x0202020C thumb
 *   func_0201F868 0x0201F868 thumb
 *   func_021BA874 0x021BA874 thumb ov099
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 */
#include "../include/Obj00977.h"
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
extern void func_021BA874(void *, int);
extern void func_021BAAB8(char *, int, int);
int func_021BC868(char *p, int v)
{
    int r;
    void *q;
    q = ((struct Obj00977 *)p)->f1B8;
    if (((struct Obj00977 *)p)->f1B0 != 0) {
        if (func_0201C6C4(q, func_02045770(((struct Obj00977 *)p)->f1AC)) == 0) {
            func_02045334(((struct Obj00977 *)p)->f1AC);
            ((struct Obj00977 *)p)->f1B0 = 0;
        }
    }
    r = func_020200CC(((struct Obj00977 *)p)->fBC);
    if (r == -1) return v;
    func_021BA8EC(p);
    ((struct Obj00977 *)p)->f1A4 = (void *)func_021BA8BC(((struct Obj00977 *)p)->f1A4);
    func_0202020C(((struct Obj00977 *)p)->fBC, 0, (u16 *)(p + 0x234));
    func_0201F868(((struct Obj00977 *)p)->fB8);
    if (r == -2) {
        if (((struct Obj00977 *)p)->f135C == 3 || ((struct Obj00977 *)p)->f135C == 4) {
            func_021BA874(p, ((struct Obj00977 *)p)->f242 - 1);
            func_021BAAB8(p, 0x60, 0);
            ((struct Obj00977 *)p)->f1CC = 0x45;
        } else {
            ((struct Obj00977 *)p)->f1CC = 0x1c;
        }
    } else {
        if (((struct Obj00977 *)p)->f135C == 3 || ((struct Obj00977 *)p)->f135C == 4) {
            ((struct Obj00977 *)p)->f1CC = r;
        } else if (r == 0x5b) {
            ((struct Obj00977 *)p)->f1CC = 0x75;
        } else {
            ((struct Obj00977 *)p)->f1CC = r;
        }
    }
    return v;
}
