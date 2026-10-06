/*
 * function: func_021B8968
 * address:  0x021B8968
 * packet:   pkt_ov071_021B8968
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * `func_020355D8(0)`/`func_020355D8(1)` in the arms of `if (t & 2)`: the
 * two calls tail-merge into one `blx` with the then-arm's `movs r0, #0`
 * falling through; every ternary or `!` spelling of the argument emits
 * `bne` to the 1 instead (same size, polarity flipped).
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045334  0x02045334  arm
 *   func_021B8EDC  0x021B8EDC  thumb  ov071
 *   func_020362DC  0x020362DC  arm
 *   func_02035C08  0x02035C08  arm
 *   func_021B7108  0x021B7108  thumb  ov071
 *   func_020355D8  0x020355D8  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_021B7114  0x021B7114  thumb  ov071
 *   d_021BAAA4     0x021BAAA4  data  a4
 */
#include "../include/Obj07702.h"

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    char pad0[8];
    void *f8;
} Q;

typedef struct {
    void **f0;
    Q *f4;
    char pad8[0x24];
    u8 f2c;
    u8 f2d;
    u8 f2e;
} C;

extern char d_021BAAA4[];

struct Descriptor;
struct PrintSys;
int func_021B8968(int a, int *b, C *c, u8 *d)
{
    extern void *func_02045770(struct Descriptor *p);
    extern u32 func_0201C6C4(struct PrintSys *p, void *v);
    extern void func_02045334(struct Descriptor *d);
    extern void func_021B8EDC(void *);
    extern u32 func_020362DC(void);
    extern int func_02035C08(const void *p);
    extern void func_021B7108(void *);
    extern void func_020355D8(u8 v);
    extern void func_020061E4(unsigned int);
    extern int func_021B7114(void *p);
    int i;
    int t;

    if (c->f2e == 1) {
        return 1;
    }
    for (i = 0; i < 6; i++) {
        void *q = c->f4->f8;
        u8 *s = d + i * 8;
        if (s[0x1c] != 0) {
            if (func_0201C6C4(q, (void *)((unsigned)func_02045770(((struct Obj07702 *)s)->f18))) == 0) {
                func_02045334(((struct Obj07702 *)s)->f18);
                s[0x1c] = 0;
            }
        }
    }
    func_021B8EDC(d);
    switch (*b) {
    case 0:
        t = func_020362DC();
        if (func_02035C08(d_021BAAA4) != -1 || (t & 2) != 0) {
            func_021B7108(d + 0x48);
            if (t & 2) {
                func_020355D8(0);
            } else {
                func_020355D8(1);
            }
            func_020061E4(0x551);
            *b = *b + 1;
        }
        break;
    case 1:
        if (func_021B7114(d + 0x48) == 0) {
            c->f2c = 0;
            return 1;
        }
        break;
    }
    return 0;
}
