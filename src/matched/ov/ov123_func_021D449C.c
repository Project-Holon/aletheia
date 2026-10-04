/*
 * function: func_021D449C
 * address: 0x021D449C
 * packet: pkt_ov123_021D449C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020414EC 0x020414EC arm
 *   func_021D4244 0x021D4244 thumb ov123
 *   func_021D4FB8 0x021D4FB8 thumb ov123
 *   func_021D4A04 0x021D4A04 thumb ov123
 *   func_021D4D40 0x021D4D40 thumb ov123
 */
#include "../include/Obj00273.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
struct TaskMenu;
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *p);
extern void func_020414EC(u32 i);
extern void func_02027858(struct TaskMenu *m);
extern void func_021D4244(char *, void *, int);
extern void func_021D4FB8(void);
extern void func_021D4A04(char *p);
extern void func_021D4D40(char *, int);
void func_021D449C(char *p)
{
    if (func_020279E8(((struct Obj00273 *)p)->f238)) {
        if (!func_02027A04(((struct Obj00273 *)p)->f238)) {
            func_021D4244(p, func_021D4FB8, 0x1b6);
        } else {
            func_020414EC(5);
            ((struct Obj00273 *)p)->f8 = 0;
            func_021D4244(p, func_021D4A04, 0x1bb);
        }
        func_02027858(((struct Obj00273 *)p)->f238);
        *(int *)&((struct Obj00273 *)p)->f238 = 0;
        func_021D4D40(p, 0);
    }
}
