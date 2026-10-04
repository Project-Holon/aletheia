/*
 * function: func_021C604C
 * address: 0x021C604C
 * packet: pkt_ov093_021C604C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021CD4B0 0x021CD4B0 thumb ov093
 *   func_021B911C 0x021B911C thumb ov093
 *   func_021D5F90 0x021D5F90 thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 func_021D5440(u8 *p);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern int func_021B911C(void *, int);
extern void func_021D5F90(u8 *, u16);
void func_021C604C(u8 *p, u8 *a, int n)
{
    if (func_021B911C(((struct Obj00003 *)p)->f4, 4) == 0) {
        func_021D5F90(a, n);
        func_021CD4B0(((struct Obj00003 *)p)->fC, 1, func_021D5440(a), (u16)n);
    }
}
