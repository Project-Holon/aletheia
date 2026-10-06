/*
 * function: func_021F3E2C
 * address:  0x021F3E2C
 * packet:   pkt_ov048_021F3E2C
 * region:   ov048
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F47B8  0x021F47B8  thumb
 *   func_021F4058  0x021F4058  thumb
 *   func_021F3E6C  0x021F3E6C  thumb
 *   func_021F3EE8  0x021F3EE8  thumb
 *   func_021F43E4  0x021F43E4  thumb
 *   func_021F4290  0x021F4290  thumb
 */
#include "../include/Obj00270.h"
#include "../include/Obj20537.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern int func_021F47B8(void *p);
extern void func_021F4058(int *p);
extern void func_021F3E6C(int *p);
extern void func_021F3EE8(int *p);
extern void func_021F43E4(int *p);
extern void func_021F4290(int *p);

void func_021F3E2C(u8 *p)
{
    if (func_021F47B8((void *)(((struct Obj00270 *)p)->f14)) == 0) {
        if (((struct Obj00270 *)p)->f20 != 0) {
            u32 q = *(u32 *)&((struct Obj00270 *)p)->f1C;

            if (q != 0 && ((struct Obj20537 *)q)->f78 != 0) {
                func_021F4058((int *)p);
                func_021F3E6C((int *)p);
                func_021F3EE8((int *)p);
                func_021F43E4((int *)p);
                func_021F4290((int *)p);
            }
        }
    }
}
