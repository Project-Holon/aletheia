/*
 * file:     worldtrade_adapter_p11.c
 * unit:     yes
 * function: func_021FD66C, func_021FD698, func_021FD6D8
 * address:  0x021FD66C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020221A4 0x020221A4 thumb
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021F4EC0 0x021F4EC0 thumb ov135
 *   func_02202840  0x02202840  thumb  ov135
 */
#include "../../matched/include/Obj08188.h"
#include "../../matched/include/Obj10587.h"
#include "../../matched/include/Obj12211.h"

struct Obj;
typedef unsigned short u16;

typedef unsigned int u32;

typedef unsigned char  u8;

extern unsigned func_020221A4(void);
extern void func_0204B3DC(struct Obj *,unsigned);
extern void func_021F4EC0(u8 *p, u32 a, u32 b);
extern u32 func_02202840(u8 *p);
int func_021FD66C(char *p);
int func_021FD698(unsigned char *p);
int func_021FD6D8(u8 *p);

int func_021FD66C(char *p) { (((struct Obj08188 *)p)->fD3C)++; if(func_020221A4()) {((struct Obj08188 *)p)->fD3C=0; ((struct Obj08188 *)p)->f28=1; func_0204B3DC(*(struct Obj * *)&((struct Obj08188 *)p)->fD34,1);} return 2; }

/*
 * volatile: 021FD6B0 reads hardware register 04000304.
 */
int func_021FD698(unsigned char *p)
{
    --((struct Obj10587 *)p)->fD3C;
    if (func_020221A4()) {
        *(volatile u16 *)0x04000304 = (u16)(*(volatile u16 *)0x04000304 & ~0x8000);
        ((struct Obj10587 *)p)->f28 = 2;
        func_021F4EC0(p, 4, 15);
        ((struct Obj10587 *)p)->fD3C = 16;
    }
    return 2;
}


int func_021FD6D8(u8 *p)
{
    if (func_02202840(p + 0xfa0) == 0) {
        ((struct Obj12211 *)p)->f28 = ((struct Obj12211 *)p)->f2C;
    }
    return 2;
}
