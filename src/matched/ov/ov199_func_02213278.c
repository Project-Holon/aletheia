/*
 * function: func_02213278
 * address: 0x02213278
 * packet: pkt_ov199_02213278
 * region: ov199
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   func_02034714 0x02034714 arm
 *   func_02213808 0x02213808 thumb ov199
 *   func_0221380C 0x0221380C thumb ov199
 *   d_02213D00 0x02213D00 data ov199 a1
 */
#include "../include/Obj14578.h"
extern void func_020307B0(void *);
typedef unsigned int   u32;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_02213808(char *, int);
extern void func_0221380C(unsigned char *p);
extern const char d_02213D00[];
int func_02213278(char *a, void *work, char *p)
{
    switch (((struct Obj14578 *)p)->f1C) {
    case 0:
        if (((struct Obj14578 *)p)->f24 != 0)
            func_0221380C((unsigned char *)a);
        else
            func_02213808(a, 0);
        break;
    case 1:
        func_02034714(d_02213D00, 0, d_02213D00);
        break;
    case 2:
    case 3:
        func_0221380C((unsigned char *)a);
        break;
    }
    func_020307B0(work);
    return 1;
}
