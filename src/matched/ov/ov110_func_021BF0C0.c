/*
 * function: func_021BF0C0
 * address: 0x021BF0C0
 * packet: pkt_ov110_021BF0C0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: emit case 5 before cases 1/2/3 as in the original jump table.
 * symbols:
 *   func_021BE7F0 0x021BE7F0 thumb ov110
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   func_021B9BEC 0x021B9BEC thumb ov110
 *   func_021BE4C0 0x021BE4C0 thumb ov110
 *   func_021BF08C 0x021BF08C thumb ov110
 *   func_021BF408 0x021BF408 thumb ov110
 *   func_021BEF4C 0x021BEF4C thumb ov110
 *   func_021BF444 0x021BF444 thumb ov110
 *   func_021BD894 0x021BD894 thumb ov110
 */
#include "../include/Obj00493.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef int (*Handler)(u8 *, void *);
extern int func_021BE7F0(void);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern void func_021B9BEC(u8 *, int);
extern int func_021BE4C0(u8 *, unsigned *);
extern int func_021BF08C(u8 *);
extern int func_021BF408(u8 *, u8 *);
extern int func_021BEF4C(u8 *);
extern int func_021BF444(u8 *);
extern int func_021BD894(u8 *, void *);
void func_021BF0C0(u8 *p, u32 *q)
{
    if (!func_021BE7F0()) {
        GFL_USE_PlaySeDefaultVolume(1361);
        func_021B9BEC(*(u8 * *)&((struct Obj00493 *)p)->f14, 13);
        *(Handler *)&((struct Obj00493 *)p)->f28 = (Handler)func_021BE4C0;
        *q = 4;
        return;
    }
    if (func_021BF08C(p) == 1) {
        switch (func_021BF408(*(u8 * *)&((struct Obj00493 *)p)->f14, p + 84)) {
        case 2:
            func_021B9BEC(*(u8 * *)&((struct Obj00493 *)p)->f14, 31);
            *q = 3;
            break;
        case 3:
            func_021B9BEC(*(u8 * *)&((struct Obj00493 *)p)->f14, 31);
            func_021B9BEC(*(u8 * *)&((struct Obj00493 *)p)->f14, 19);
            *q = 3;
            break;
        }
        return;
    }
    switch (func_021BEF4C(p)) {
    case 0: break;
    case 5:
        GFL_USE_PlaySeDefaultVolume(1356);
        func_021BF444(p);
        *(Handler *)&((struct Obj00493 *)p)->f28 = func_021BD894;
        func_021B9BEC(*(u8 * *)&((struct Obj00493 *)p)->f14, 34);
        func_021B9BEC(*(u8 * *)&((struct Obj00493 *)p)->f14, 14);
        *q = 4;
        break;
    case 1:
        GFL_USE_PlaySeDefaultVolume(1352);
        func_021B9BEC(*(u8 * *)&((struct Obj00493 *)p)->f14, 19);
        break;
    case 2:
        GFL_USE_PlaySeDefaultVolume(1352);
        func_021B9BEC(*(u8 * *)&((struct Obj00493 *)p)->f14, 31);
        *q = 3;
        break;
    case 3:
        GFL_USE_PlaySeDefaultVolume(1352);
        func_021B9BEC(*(u8 * *)&((struct Obj00493 *)p)->f14, 20);
        func_021B9BEC(*(u8 * *)&((struct Obj00493 *)p)->f14, 19);
        *q = 2;
        break;
    case 4: break;
    }
}
