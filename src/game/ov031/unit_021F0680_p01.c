/*
 * file:     unit_021F0680_p01.c
 * unit:     yes
 * function: func_021F0AA0, func_021F0B98
 * address:  0x021F0AA0
 * region:   ov031
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F0A04  0x021F0A04  thumb  ov031
 *   func_021BBC2C  0x021BBC2C  thumb  ov021
 *   func_02034714  0x02034714  arm
 *   func_021F07AC  0x021F07AC  thumb  ov031
 *   d_021F10D0     0x021F10D0  data  a4
 *   func_02035CB8  0x02035CB8  arm
 *   func_0204B454  0x0204B454  arm
 *   func_02035C60  0x02035C60  arm
 *   func_0204B404  0x0204B404  arm
 */
#include "../../matched/include/Obj07626.h"
#include "../../matched/include/Obj01128.h"

struct Obj;
struct Actor;
struct PtS;
struct Vec2;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

extern void func_021F0A04(void *a, u8 i, u8 j, char *b, int d);
extern void *func_021BBC2C(void *r, int i);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_021F07AC(struct Obj *p, const u8 *e, u8 k);
extern u32 func_02035CB8(u32 *outA, u32 *outB);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern int func_02035C60(void);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
void func_021F0AA0(void *a, char *b, int n);
int func_021F0B98(char *o);
extern const char d_021F10D0[];


void func_021F0AA0(void *a, char *b, int n)
{
    long i;
    int j;
    void *e;

    if (n > 0) {
        for (i = n, j = 0; i < 3; i++) {
            func_021F0A04(a, i, j, b, ((struct Obj07626 *)b)->f440 - n);
            j++;
        }
        for (j = 3 - n; j < 3; j++) {
            e = func_021BBC2C(b, ((struct Obj07626 *)b)->f440 - 2 + j);
            if (e == 0)
                func_02034714(d_021F10D0, 0, d_021F10D0);
            func_021F07AC(a, e, (u8)j);
        }
    } else {
        for (i = n + 2, j = 2; i > -1; i--) {
            func_021F0A04(a, i, j, b, ((struct Obj07626 *)b)->f440 - n);
            j--;
        }
        for (j = -1 - n; j > -1; j--) {
            e = func_021BBC2C(b, ((struct Obj07626 *)b)->f440 - 2 + j);
            if (e == 0)
                func_02034714(d_021F10D0, 0, d_021F10D0);
            func_021F07AC(a, e, (u8)j);
        }
    }
}


int func_021F0B98(char *o)
{
    s16 buf[2];
    u32 x;
    u32 y;
    int r;

    if (func_02035CB8(&x, &y) == 0)
        return 0;
    r = 1;
    func_0204B454((struct Actor *)((struct Obj01128 *)o)->f2C, (struct PtS *)buf, 1);
    if (((struct Obj01128 *)o)->f31 == 0) {
        if (func_02035C60() == 0)
            return 0;
        if ((u32)(buf[0] - 0xB) <= x && (u32)(buf[0] + 0xB) >= x &&
            (u32)(buf[1] - 0xB) <= y && (u32)(buf[1] + 0xB) >= y)
            return r;
    } else {
        if (y < 0x1C)
            y = 0x1C;
        else if (y > 0x9C)
            y = 0x9C;
        buf[1] = y;
        func_0204B404((struct Obj *)(((struct Obj01128 *)o)->f2C), (const struct Vec2 *)buf, 1);
        return 1;
    }
    return 0;
}
