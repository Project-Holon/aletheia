/*
 * file:     queue_p08.c
 * unit:     yes
 * function: func_021C0E3C, func_021C0E4C, func_021C0E54, func_021C0E5C, func_021C0E64, func_021C0E6C
 * address:  0x021C0E3C
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C0E98  0x021C0E98  thumb  ov217
 *   func_020307B0  0x020307B0  arm
 *   func_021C0EA4  0x021C0EA4  thumb  ov217
 *   func_021C0EC0  0x021C0EC0  thumb  ov217
 *   func_021C0EDC  0x021C0EDC  thumb  ov217
 *   func_021C0EE4  0x021C0EE4  thumb  ov217
 */
#include "../../matched/include/Obj06714.h"

struct Ring;
typedef unsigned char  u8;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef signed int     s32;

extern void func_021C0E98(u8 *a0);
extern u32 func_020307B0(void *p);
extern void func_021C0EA4(char *p, int v);
extern u32 func_021C0EC0(struct Ring *r);
extern void func_021C0EDC(void);
extern void func_021C0EE4(void);
void func_021C0E3C(void *p);
void func_021C0E4C(u32 a0, u32 a1);
u32 func_021C0E54(struct Ring *r);
void func_021C0E5C(void);
void func_021C0E64(void);
void func_021C0E6C(void *p);


void func_021C0E3C(void *p)
{
    func_021C0E98(p);
    func_020307B0(p);
}

void func_021C0E4C(u32 a0, u32 a1)
{
    func_021C0EA4((char *)a0, (int)a1);
}


/*
 * Tail-call veneer: branch to func_021C0EC0.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C0E54(struct Ring *r)
{
    return func_021C0EC0(r);
}


/*
 * Tail-call veneer: branch to func_021C0EDC.
 *
 * Addresses are Black-image addresses.
 */
void func_021C0E5C(void)
{
    func_021C0EDC();
}


/*
 * Tail-call veneer: branch to func_021C0EE4.
 *
 * Addresses are Black-image addresses.
 */
void func_021C0E64(void)
{
    func_021C0EE4();
}


/*
 * Clear the u32 fields at +0, +8 and +0xc.
 *
 * Addresses are Black-image addresses.
 */
void func_021C0E6C(void *p)
{
    ((struct Obj06714 *)p)->f0 = 0;
    ((struct Obj06714 *)p)->f8 = 0;
    ((struct Obj06714 *)p)->fC = 0;
}
