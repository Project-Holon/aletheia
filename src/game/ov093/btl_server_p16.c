/*
 * file:     btl_server_p16.c
 * unit:     yes
 * function: func_021BC220, func_021BC2B0
 * address:  0x021BC220
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
 *   func_021BB85C  0x021BB85C  thumb  ov093
 *   func_021BB8A8  0x021BB8A8  thumb  ov093
 *   func_021BB8B0  0x021BB8B0  thumb  ov093
 *   func_021BD9D4  0x021BD9D4  thumb  ov093
 *   func_021BDA00  0x021BDA00  thumb  ov093
 *   func_021C5200  0x021C5200  thumb  ov093
 *   func_021B8B9C  0x021B8B9C  thumb  ov093
 *   func_021B8BC4  0x021B8BC4  thumb  ov093
 *   func_021B8FF4  0x021B8FF4  thumb  ov093
 *   func_021B9AEC  0x021B9AEC  thumb  ov093
 *   func_021B9B98  0x021B9B98  thumb  ov093
 */
#include "../../matched/include/Obj00003.h"

typedef unsigned char u8;

typedef unsigned int u32;

typedef struct {
    u32 a : 4;
    u32 b : 3;
    u32 c : 3;
    u32 d : 1;
} Bf;

extern u8 *func_021BB85C(u8 *p, unsigned int i);
extern u8 func_021BB8A8(u8 *p, u8 i);
extern Bf func_021BB8B0(u8 *p, u8 i, u8 j);
extern void func_021BD9D4(u8 *p, u8 i, u8 a, u8 b, int c);
extern int func_021BDA00(u8 *p);
extern int func_021C5200(u8 *p);
extern int func_021B8B9C(u8 *p, u8 k);
extern unsigned char func_021B8BC4(int unused, unsigned int b);
extern u8 func_021B8FF4(u8 *p);
extern char *func_021B9AEC(char *p, int i);
extern u8 func_021B9B98(u8 *p);
int func_021BC220(u8 *p, u8 *o);
int func_021BC2B0(u8 *p);


/*
 * func_021BB8B0 returns a 4-byte bitfield struct: declaring it that way
 * (a u32 return with shifts and masks gives a different frame) is what
 * matches.
 */
int func_021BC220(u8 *p, u8 *o)
{
    u32 i;
    u32 j;
    u32 n;
    Bf v;

    for (i = 0; i < 4; i++) {
        if (func_021BB85C((u8 *)(*(int *)&((struct Obj00003 *)p)->f0), (u8)i) != 0) {
            n = func_021BB8A8(o, i);
            for (j = 0; j < n; j++) {
                v = func_021BB8B0(o, i, j);
                if (v.a == 3 && v.d == 0)
                    func_021BD9D4(p, i, v.b, v.c, 1);
            }
        }
    }
    func_021BDA00(p);
    return func_021C5200(p);
}


int func_021BC2B0(u8 *p)
{
    u8 f[2];
    u32 i;

    f[1] = 0;
    f[0] = f[1];
    for (i = 0; i < 4; i++) {
        if (func_021B8B9C(*(u8 * *)&((struct Obj00003 *)p)->f4, i) != 0) {
            char *q = func_021B9AEC(*(char * *)&((struct Obj00003 *)p)->f8, i);
            u8 k = func_021B8BC4((int)(*(u8 * *)&((struct Obj00003 *)p)->f4), (u8)i);

            if (func_021B9B98((u8 *)q) != 0)
                f[k] = 1;
        }
    }
    if (f[0] == 0 || f[1] == 0)
        return 1;
    return 0;
}
