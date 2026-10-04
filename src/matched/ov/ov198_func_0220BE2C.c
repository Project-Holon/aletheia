/*
 * function: func_0220BE2C
 * address:  0x0220BE2C
 * packet:   pkt_0220BE2C
 * region:   ov198
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0220C60C  0x0220C60C  thumb  ov198
 *   func_0220D884  0x0220D884  thumb  ov198
 *   func_0220D9B4  0x0220D9B4  thumb  ov198
 *   func_0220DCA8  0x0220DCA8  thumb  ov198
 *   func_0220DC04  0x0220DC04  thumb  ov198
 *   func_0220DD78  0x0220DD78  thumb  ov198
 *   func_0220DE4C  0x0220DE4C  thumb  ov198
 *   func_0220DF20  0x0220DF20  thumb  ov198
 *   func_0220E088  0x0220E088  thumb  ov198
 */
#include "../include/Obj00507.h"

extern int func_0220C60C(char *, int);
extern int func_0220D884(char *);
extern int func_0220D9B4(char *);
extern int func_0220DCA8(char *);
extern int func_0220DC04(char *);
extern int func_0220DD78(char *);
extern int func_0220DE4C(char *);
extern int func_0220DF20(char *);
extern int func_0220E088(char *);

int func_0220BE2C(char *a, int idx)
{
    switch (idx) {
    case 0: {
        unsigned char c;
        func_0220D884(a);
        c = *(unsigned char *)(*(int *)&((struct Obj00507 *)a)->f0 + 0x1f);
        if (c == 3)
            return func_0220C60C(a, 7);
        if (c == 2)
            return func_0220C60C(a, 9);
        return func_0220C60C(a, 6);
    }
    case 8:
        func_0220D884(a);
        return func_0220C60C(a, 0xa);
    case 1:
        return func_0220D9B4(a);
    case 2:
        return func_0220DCA8(a);
    case 3:
        return func_0220DC04(a);
    case 4:
        return func_0220DD78(a);
    case 5:
        return func_0220E088(a);
    case 6:
        return func_0220DE4C(a);
    case 7:
        return func_0220DF20(a);
    }
}
