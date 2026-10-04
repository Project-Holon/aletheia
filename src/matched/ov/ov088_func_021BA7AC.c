/*
 * function: func_021BA7AC
 * address:  0x021BA7AC
 * packet:   pkt_ov088_021BA7AC
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202EB0C  0x0202EB0C  thumb
 *   func_021BBE48  0x021BBE48  thumb  ov088
 *   func_0201C6B4  0x0201C6B4  thumb
 *   func_020362DC  0x020362DC  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_021BBD10  0x021BBD10  thumb  ov088
 *   func_021BB840  0x021BB840  thumb  ov088
 *   func_021BB810  0x021BB810  thumb  ov088
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_02045770  0x02045770  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045334  0x02045334  arm
 */
#include "../include/Obj00263.h"

typedef unsigned char u8;
typedef unsigned int u32;

struct Descriptor;
struct PrintSys;
extern u32 func_0202EB0C(void);
extern void func_021BBE48(char *p);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern u32 func_020362DC(void);
extern void func_020061E4(u32);
extern void func_021BBD10(char *p, int mode);
extern int func_021BB840(char *p, int y);
extern void func_021BB810(void *, int, int, int);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void *func_02045770(struct Descriptor *p);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *d);

int func_021BA7AC(char *p)
{
    void *t;
    if (func_0202EB0C() == 1) {
        switch (((struct Obj00263 *)p)->f12A) {
        case 0:
            func_021BBE48(p);
            ((struct Obj00263 *)p)->f12A = ((struct Obj00263 *)p)->f12A + 1;
            break;
        case 1:
            if (func_0201C6B4(((struct Obj00263 *)p)->f68) == 1)
                ((struct Obj00263 *)p)->f12A = ((struct Obj00263 *)p)->f12A + 1;
            break;
        case 2:
            if (func_020362DC() & 3) {
                func_020061E4(0x54c);
                func_021BBD10(p, 0);
                func_021BB810(p, *(u8 *)(p + ((struct Obj00263 *)p)->f128 + 0x120),
                              func_021BB840(p, ((struct Obj00263 *)p)->f12F), 2);
                ((struct Obj00263 *)p)->f12A = 0;
                return 5;
            }
            break;
        }
        func_0201C4E4(((struct Obj00263 *)p)->f68);
        t = ((struct Obj00263 *)p)->f68;
        if (((struct Obj00263 *)p)->fF4 != 0 && func_0201C6C4(t, func_02045770(((struct Obj00263 *)p)->fF0)) == 0) {
            func_02045334(((struct Obj00263 *)p)->fF0);
            ((struct Obj00263 *)p)->fF4 = 0;
        }
        return 9;
    }
    ((struct Obj00263 *)p)->f129 = *(u8 *)(p + ((struct Obj00263 *)p)->f128 + 0x120);
    return 11;
}
