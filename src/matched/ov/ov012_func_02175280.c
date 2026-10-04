/*
 * function: func_02175280
 * address:  0x02175280
 * packet:   pkt_ov012_02175280
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_02034714  0x02034714  arm
 *   func_020399A8  0x020399A8  arm
 *   func_0203D1A4  0x0203D1A4  arm
 *   func_02175358  0x02175358  thumb  ov012
 *   func_020120F4  0x020120F4  thumb
 *   func_02012F2C  0x02012F2C  thumb
 */
#include "../include/Obj07341.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern void func_02082BCC(void *p, int v, int n);
struct Ctx;
extern void func_02034714(const char *expr, u32 line, const char *file);
struct Entry;
extern struct Entry *func_020399A8(void);
struct Link;
extern u32 func_0203D1A4(struct Link *p);
extern void func_02175358(u8 *a, u8 *slot, u8 i, int d);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012F2C(int *p);

void func_02175280(u8 *a, void *b, u8 *out, int d)
{
    int count;
    int i;
    int v;
    int self;
    int base;
    int y;

    count = 0;
    func_02082BCC(out, 0, 0x58);
    ((struct Obj07341 *)out)->f44 = 3;
    for (i = 0; i < 4; i++) {
        if (a[0x158 + i] == 0) {
            ((struct Obj07341 *)out)->f44 = 1;
            break;
        }
        count++;
    }
    if (count != 2 && count != 4) {
        func_02034714((void *)0x0217563C, 0, (void *)0x0217563C);
    }
    self = (a + func_0203D1A4((struct Link *)((u32)func_020399A8())))[0x15C];
    for (i = 0; i < count; i++) {
        y = a[0x15C + i];
        if ((y & 1) == (self & 1)) {
            base = 0;
        } else if (((struct Obj07341 *)out)->f44 == 1) {
            base = 1;
        } else {
            base = 2;
        }
        v = base + (y >> 1);
        if (v >= count) {
            func_02034714((void *)0x0217563C, 0, (void *)0x0217563C);
        }
        func_02175358(a, out + v * 16, (u8)i, d);
    }
    ((struct Obj07341 *)out)->f54 = (int)func_02012F2C(func_020120F4(b));
}
