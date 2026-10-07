/*
 * file:     gtsnego_disp_p12.c
 * unit:     yes
 * function: func_021D5758, func_021D57B0
 * address:  0x021D5758
 * region:   ov120
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D7AF4 0x021D7AF4 thumb ov120
 *   func_021D79F4 0x021D79F4 thumb ov120
 *   func_021D6988 0x021D6988 thumb ov120
 *   func_021B64D0 0x021B64D0 thumb ov067
 *   func_021D4244 0x021D4244 thumb ov120
 *   func_021D5AD4 0x021D5AD4 thumb ov120
 *   func_020355C4 0x020355C4 arm
 *   func_021D69F4 0x021D69F4 thumb ov120
 *   func_021D7D3C 0x021D7D3C thumb ov120
 *   func_021D6BB0 0x021D6BB0 thumb ov120
 *   func_021D81E0 0x021D81E0 thumb ov120
 *   func_021D82A8 0x021D82A8 thumb ov120
 *   func_021D72A0 0x021D72A0 thumb ov120
 *   func_021D6D10 0x021D6D10 thumb ov120
 *   func_021D7ECC 0x021D7ECC thumb ov120
 *   func_021D733C 0x021D733C thumb ov120
 *   func_021D5334 0x021D5334 thumb ov120
 */
#include "../../matched/include/Obj05345.h"
#include "../../matched/include/Obj00532.h"

struct Sub02009D9CObj;
struct Ctx;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int   u32;

extern int func_021D7AF4(char *p);
extern void func_021D79F4(u8 *p, u16 n);
extern u32 func_021D6988(u8 *p);
extern void func_021B64D0(u8 *p, u32 v);
extern void func_021D4244(int *p, int v, int a2);
extern void func_021D5AD4(u8 *p);
extern u8 func_020355C4(void);
extern void func_021D69F4(u8 *p, void *q, u32 n);
extern void *func_02012F14(void **);
extern int func_02009E8C(struct Sub02009D9CObj *obj);
extern void func_021D7D3C(char *p);
extern void func_021D6BB0(u8 *, int);
extern void func_021D81E0(char *, void *);
extern void func_021D82A8(char *p, void *q, int start);
extern void func_021D72A0(u8 *p, void *container, int offset);
extern void func_021D6D10(u8 *p, void *list, int first);
extern void *func_021D7ECC(char *, u16);
extern void func_021D733C(u8 *p, int index, int count);
extern void func_021D5334(struct Ctx *p);
void func_021D5758(u8 *p);
void func_021D57B0(u8 *p);

void func_021D5758(u8 *p)
{
    if (func_021D7AF4(((struct Obj05345 *)p)->f40)) {
        if (--((struct Obj05345 *)p)->f14 <= 0) {
            func_021D79F4(((struct Obj05345 *)p)->f40, 0x20);
            func_021B64D0((u8 *)func_021D6988(((struct Obj05345 *)p)->f3C), 1);
            func_021D4244((int *)p, (int)func_021D5AD4, 0x7c7);
            if (func_020355C4() == 0)
                func_021D69F4(((struct Obj05345 *)p)->f3C, 0, ((struct Obj05345 *)p)->f15C);
        }
    }
}

void func_021D57B0(u8 *p)
{
    int flag = 1;
    int n = func_02009E8C(func_02012F14(*(void ** *)&((struct Obj00532 *)p)->f2C));
    ((struct Obj00532 *)p)->f138 = flag;
    if (n == 0) {
        func_021D79F4(((struct Obj00532 *)p)->f40, 0x1d);
        ((struct Obj00532 *)p)->f14 = 0x78;
        func_021D4244((int *)p, (int)func_021D5758, 0x7e7);
        return;
    }
    ((struct Obj00532 *)p)->f150 = n;
    func_021D79F4(((struct Obj00532 *)p)->f40, 0x13);
    if (func_020355C4() == 0)
        func_021D69F4(((struct Obj00532 *)p)->f3C, 0, ((struct Obj00532 *)p)->f164);
    else
        func_021D69F4(((struct Obj00532 *)p)->f3C, 0, 9);
    func_021D7D3C(((struct Obj00532 *)p)->f40);
    if (n <= 3) flag = 0;
    func_021D6BB0(*(u8 * *)&((struct Obj00532 *)p)->f3C, flag);
    func_021D81E0(*(char * *)&((struct Obj00532 *)p)->f40, ((struct Obj00532 *)p)->f2C);
    func_021D82A8(((struct Obj00532 *)p)->f40, ((struct Obj00532 *)p)->f2C, ((struct Obj00532 *)p)->f158 - 2);
    func_021D72A0(((struct Obj00532 *)p)->f3C, ((struct Obj00532 *)p)->f2C, ((struct Obj00532 *)p)->f158 - 2);
    func_021D6D10(((struct Obj00532 *)p)->f3C, ((struct Obj00532 *)p)->f2C, ((struct Obj00532 *)p)->f158 - 2);
    ((struct Obj00532 *)p)->f34 = func_021D7ECC(*(char * *)&((struct Obj00532 *)p)->f40, 0x2c);
    func_021D733C(((struct Obj00532 *)p)->f3C, ((struct Obj00532 *)p)->f158 + ((struct Obj00532 *)p)->f164 - 6, ((struct Obj00532 *)p)->f150);
    func_021D4244((int *)p, (int)func_021D5334, 0x815);
}
