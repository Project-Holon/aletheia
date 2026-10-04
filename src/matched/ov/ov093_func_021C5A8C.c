/*
 * function: func_021C5A8C
 * address: 0x021C5A8C
 * packet: pkt_ov093_021C5A8C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021D5DC0 0x021D5DC0 thumb ov093
 *   func_021D5E38 0x021D5E38 thumb ov093
 *   func_021CD4B0 0x021CD4B0 thumb ov093
 *   func_021CD64C 0x021CD64C thumb ov093
 */
#include "../include/Obj04360.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 func_021D5440(u8 *p);
extern u8 func_021D5DC0(s8 *p, int i, u8 n);
extern u8 func_021D5E38(s8 *p, int i, u8 n);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern void func_021CD64C(void *, u8, ...);
void func_021C5A8C(u8 *p, u8 *a, int c, int d, u16 msg, int flag)
{
    u8 n = func_021D5440(a);
    if (d > 0) {
        int x = func_021D5DC0((s8 *)a, c, d);
        u8 t = x;
        func_021CD4B0(((struct Obj04360 *)p)->fC, 9, n, (u8)c, t);
        func_021CD4B0(((struct Obj04360 *)p)->fC, 0x37, n, (u8)c, t);
        if (flag) {
            if (msg == 0) func_021CD64C(((struct Obj04360 *)p)->fC, 0x5b, 0x1b, n, c, x, 0xffff0000);
            else func_021CD64C(((struct Obj04360 *)p)->fC, 0x5b, 0x3aa, n, msg, c, x, 0xffff0000);
        }
    } else {
        int x = func_021D5E38((s8 *)a, c, -d);
        u8 t = x;
        func_021CD4B0(((struct Obj04360 *)p)->fC, 10, n, (u8)c, t);
        func_021CD4B0(((struct Obj04360 *)p)->fC, 0x38, n, (u8)c, t);
        func_021CD64C(((struct Obj04360 *)p)->fC, 0x5b, 0x5a, n, c, x, 0xffff0000);
    }
}
