/*
 * function: func_022130D4
 * address: 0x022130D4
 * packet: pkt_ov199_022130D4
 * region: ov199
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   func_02213808 0x02213808 thumb ov199
 */
#include "../include/Obj08371.h"
#include "../include/Obj25294.h"
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
extern void func_02213808(char *, int);
int func_022130D4(char *a, char *work, char *p)
{
    int state = ((struct Obj25294 *)work)->f8;
    func_020307B0(work);
    if (((struct Obj08371 *)p)->f1C == 1) {
        switch (state) {
        case 0: func_02213808(a, 3); break;
        case 2: ((struct Obj08371 *)p)->f1C0 = 1; func_02213808(a, 0); break;
        }
    } else {
        switch (state) {
        case 0: func_02213808(a, 3); break;
        case 1: ((struct Obj08371 *)p)->f220 = 1; func_02213808(a, 4); break;
        case 3: ((struct Obj08371 *)p)->f20 = 2; func_02213808(a, 1); break;
        }
    }
    return 1;
}
