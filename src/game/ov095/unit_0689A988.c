/*
 * file:     unit_0689A988.c
 * function: func_0689A988
 * address: 0x0689A988
 * packet: pkt_ov095_0689A988
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B8588  0x021B8588  thumb
 *   func_021B8D8C  0x021B8D8C  thumb
 *   func_021B8E70  0x021B8E70  thumb
 *   func_021D5440  0x021D5440  thumb
 *   func_021D5448  0x021D5448  thumb
 *   func_021D54C0  0x021D54C0  thumb
 *   func_021D82D0  0x021D82D0  thumb
 *   func_021D8318  0x021D8318  thumb
 *   func_021D8424  0x021D8424  thumb
 *   func_021D8434  0x021D8434  thumb
 *   func_02202DC4  0x02202DC4  thumb
 *   d_0689D880 0x0689D880 data a4
 *   d_0689D91C 0x0689D91C data a4
 *   d_0689E128 0x0689E128 data a4
 *   d_0689E054 0x0689E054 data a4
 */
#include "../../matched/include/Obj01703.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const char d_0689D880[], d_0689D91C[], d_0689E128[], d_0689E054[];
extern u8 func_021D5440(void *);
extern int func_021B8D8C(void *, void *, u32);
extern u8 func_021B8E70(void *, u32);
extern u32 func_021B8588(void *);
extern int func_02202DC4(char *, const char *, int);
extern void func_021D8434(void *);
extern u8 func_021D5448(void *);
extern u16 func_021D54C0(void *, u8);
extern void func_021D82D0(void *, u32, u32);
extern void func_021D8318(void *);
extern void func_021D8424(void *);
int func_0689A988(int unused, u8 *s)
{
    int r;
    const char *q, *n;
    int flag;
    r = func_021B8E70(((struct Obj01703 *)s)->fA0, func_021B8D8C(((struct Obj01703 *)s)->fA0, ((struct Obj01703 *)s)->fA4, func_021D5440(((struct Obj01703 *)s)->f6C)));
    if (func_021B8588(((struct Obj01703 *)s)->fA0) == 2 && r != 4) q = d_0689D880;
    else q = d_0689D91C;
    if (func_021B8588(((struct Obj01703 *)s)->fA0) == 2 && r != 4) n = d_0689E128;
    else n = d_0689E054;
    r = func_02202DC4(*(char * *)&((struct Obj01703 *)s)->fB0, q, (int)n);
    if (r != -1) {
        if (r & 0x8000) flag = 1;
        else flag = 0;
        r &= ~0x8000;
        if (r == 4) {
            func_021D8434(((struct Obj01703 *)s)->f70);
            return 1;
        }
        if (r < func_021D5448(((struct Obj01703 *)s)->f6C)) {
            func_021D82D0(((struct Obj01703 *)s)->f70, func_021D54C0(((struct Obj01703 *)s)->f6C, r), 6);
            if (flag) func_021D8318(((struct Obj01703 *)s)->f70);
            return 1;
        }
        if (func_021B8588(((struct Obj01703 *)s)->fA0) == 2 && r == 5) {
            func_021D8424(((struct Obj01703 *)s)->f70);
            return 1;
        }
    }
    return 0;
}
