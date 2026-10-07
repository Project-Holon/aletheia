/*
 * file:     btl_server_p17.c
 * unit:     yes
 * function: func_021BC310, func_021BC360, func_021BC390
 * address:  0x021BC310
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B8B9C  0x021B8B9C  thumb  ov093
 *   func_021B8BC4  0x021B8BC4  thumb  ov093
 *   func_021B8FF4  0x021B8FF4  thumb  ov093
 *   func_021B9AEC  0x021B9AEC  thumb  ov093
 *   func_021B9B98  0x021B9B98  thumb  ov093
 *   func_021B990C 0x021B990C thumb ov093
 *   func_021BD584 0x021BD584 thumb ov093
 *   func_021BC3B0 0x021BC3B0 thumb ov093
 */
#include "../../matched/include/Obj06224.h"
#include "../../matched/include/Obj00003.h"
#include "../../matched/include/Obj05189.h"

typedef unsigned char u8;

typedef unsigned int u32;

extern int func_021B8B9C(u8 *p, u8 k);
extern unsigned char func_021B8BC4(int unused, unsigned int b);
extern u8 func_021B8FF4(u8 *p);
extern char *func_021B9AEC(char *p, int i);
extern u8 func_021B9B98(u8 *p);
extern void *func_021B990C(char *, u32, u32);
extern int func_021BD584(u8 *, u8 *);
extern void func_021BC3B0(int *);
int func_021BC310(u8 *p);
int func_021BC360(u8 *p);
int func_021BC390(u8 *p);


int func_021BC310(u8 *p)
{
    u32 i;

    for (i = 0; i < 4; i++) {
        if (func_021B8B9C(*(u8 * *)&((struct Obj06224 *)p)->f4, i) != 0) {
            u8 a = func_021B8BC4((int)(*(u8 * *)&((struct Obj06224 *)p)->f4), (u8)i);
            u8 b = func_021B8BC4((int)(*(u8 * *)&((struct Obj06224 *)p)->f4), (u8)func_021B8FF4(*(u8 * *)&((struct Obj06224 *)p)->f4));

            if (a == b) {
                if (func_021B9B98((u8 *)func_021B9AEC(*(char * *)&((struct Obj06224 *)p)->f8, i)) != 0)
                    return 1;
            }
        }
    }
    return 0;
}

/*
 * extent: two zero alignment bytes at 0x021BC38E, then func_021BC390.
 * Lever: bind the first call result before initializing the boolean result.
 */
int func_021BC360(u8 *p)
{
    u8 *a;
    u32 side;
    int result;
    u32 *out;
    side = func_021B8FF4(*(u8 * *)&((struct Obj00003 *)p)->f4);
    result = 0;
    a = func_021B990C(*(char * *)&((struct Obj00003 *)p)->f8, side, 0);
    out = *(u32 * *)&((struct Obj00003 *)p)->fC;
    out[0] = 0;
    out[1] = 0;
    if (func_021BD584(p, a)) result = 1;
    return result;
}

/*
 * extent: two zero alignment bytes at 0x021BC3AE, then matched func_021BC3B0.
 */
int func_021BC390(u8 *p)
{
    int result = 0;
    u32 *out = *(u32 * *)&((struct Obj05189 *)p)->fC;
    out[0] = 0;
    out[1] = 0;
    func_021BC3B0((int *)p);
    if (**(u32 * *)&((struct Obj05189 *)p)->fC) result = 1;
    return result;
}
