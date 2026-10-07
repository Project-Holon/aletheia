/*
 * file:     unit_021B6100_p05.c
 * unit:     yes
 * function: func_021B74D8, func_021B74F8, func_021B7568
 * address:  0x021B74D8
 * region:   ov173
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201F7A8  0x0201F7A8  thumb
 *   func_020456F8  0x020456F8  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_02006238 0x02006238 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_02005DE4 0x02005DE4 thumb
 *   func_02005E64 0x02005E64 thumb
 *   func_02005D90 0x02005D90 thumb
 *   func_02005F38 0x02005F38 thumb
 *   func_02005E9C 0x02005E9C thumb
 *   func_02017E1C 0x02017E1C thumb
 */
#include "../../matched/include/Obj14315.h"

struct Descriptor;
typedef unsigned int u32;

typedef unsigned char  u8;

typedef unsigned short u16;

extern void func_0201F7A8(void *desc, u32 kind);
extern void func_020456F8(struct Descriptor *d);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32 bit);
extern int func_02006238(void);
extern void func_020061E4(unsigned int);
extern void func_02005DE4(void *p);
extern int func_02005E64(void);
extern void func_02005D90(unsigned int, unsigned int);
extern int func_02005F38(void);
extern int func_02005E9C(void);
extern u32 func_02017E1C(void *,u32,u32);
void func_021B74D8(char *p);
int func_021B74F8(unsigned int state);
u8 func_021B7568(void ***p);


void func_021B74D8(char *p)
{
    u32 x;

    func_0201F7A8((void *)(((struct Obj14315 *)p)->f20), 2);
    x = ((struct Obj14315 *)p)->f20;
    func_020456F8((struct Descriptor *)x);
    func_02041B6C(func_02045730((struct Descriptor *)x));
}

int func_021B74F8(unsigned int state)
{
    switch (state) {
    case 1: return func_02006238();
    case 2: return func_02006238();
    case 3: func_020061E4(0x56b); break;
    case 4:
        func_02005DE4((void *)1);
        func_02005E64();
        func_02005D90(0x515, 0xffff);
        break;
    case 5:
        if (func_02005F38() == 0) {
            func_02005E9C();
            func_02005DE4(0);
        } else {
            return 1;
        }
        break;
    }
    return 0;
}

u8 func_021B7568(void ***p) {u8 i;for(i=0;i<4;i++)if(!func_02017E1C(**p,i+54,0))break;return i;}
