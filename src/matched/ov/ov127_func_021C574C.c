/*
 * function: func_021C574C
 * address: 0x021C574C
 * packet: pkt_ov127_021C574C
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: alignment at 021C57D6 then already-filed 57D8, 57DC, 57E8 leaves.
 * symbols:
 *   func_021C49A4 0x021C49A4 thumb ov127
 *   func_021C58F8 0x021C58F8 thumb ov127
 *   func_021C5944 0x021C5944 thumb ov127
 *   func_021C5914 0x021C5914 thumb ov127
 *   func_021C41DC 0x021C41DC thumb ov127
 *   func_021C5878 0x021C5878 thumb ov127
 *   func_021C4214 0x021C4214 thumb ov127
 *   func_021C42C4 0x021C42C4 thumb ov127
 */
#include "../include/Obj00328.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int   u32;
extern int func_021C49A4(u8 *p, unsigned int i);
extern int func_021C58F8(char *p, int b);
extern void func_021C5944(u8 *p, int n, int a);
extern void func_021C5914(void *, s16 *, s16 *);
extern void func_021C41DC(u8 *p, int x, int y);
extern int func_021C5878(int, int);
extern void func_021C4214(u8 *p, u32 v);
extern void func_021C42C4(u8 *p);
void func_021C574C(u8 *p)
{
    if (p[19]) {
        int a = func_021C49A4(((struct Obj00328 *)p)->f0, 5);
        int b = func_021C49A4(((struct Obj00328 *)p)->f0, 6);
        s16 c = func_021C49A4(((struct Obj00328 *)p)->f0, 8);
        s16 x, y;
        u16 d;
        if (((struct Obj00328 *)p)->f8 != a || ((struct Obj00328 *)p)->fA != b || c == 0) {
            ((struct Obj00328 *)p)->f8 = a;
            ((struct Obj00328 *)p)->fA = b;
            func_021C5944(p, func_021C58F8(((struct Obj00328 *)p)->f4, a), b);
        }
        func_021C5914(p, &x, &y);
        func_021C41DC(((struct Obj00328 *)p)->f4, x, y);
        d = func_021C5878(y, p[18]);
        func_021C4214(((struct Obj00328 *)p)->f4, d);
        func_021C42C4(((struct Obj00328 *)p)->f4);
    }
}
