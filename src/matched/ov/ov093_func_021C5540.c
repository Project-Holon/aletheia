/*
 * function: func_021C5540
 * address: 0x021C5540
 * packet: pkt_ov093_021C5540
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021CD4B0 0x021CD4B0 thumb ov093
 *   func_021CD64C 0x021CD64C thumb ov093
 *   func_021C5B74 0x021C5B74 thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 func_021D5440(u8 *p);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern void func_021CD64C(void *, u8, ...);
extern void func_021C5B74(u8 *, u8 *, int, int);
void func_021C5540(u8 *p, u8 *a, int c)
{
    int n;
    n = func_021D5440(a);
    func_021CD4B0(((struct Obj00003 *)p)->fC, 0x36, n);
    func_021C5B74(p, a, (int)(0u - (u32)c), 1);
    func_021CD64C(((struct Obj00003 *)p)->fC, 0x5a, 0x50, n, 0xffff0000);
}
