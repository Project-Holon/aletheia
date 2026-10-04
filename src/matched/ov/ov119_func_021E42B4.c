/*
 * function: func_021E42B4
 * address: 0x021E42B4
 * packet: pkt_ov119_021E42B4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E4DBC 0x021E4DBC thumb ov119
 *   func_021E421C 0x021E421C thumb ov119
 *   func_021E41A0 0x021E41A0 thumb ov119
 *   func_02042FB0 0x02042FB0 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj00001.h"
extern int func_021E4DBC(char *);
extern int func_021E421C(char *, int, int);
extern unsigned short func_021E41A0(int, int, char *, int);
typedef unsigned short u16;
typedef unsigned int   u32;
extern void func_02042FB0(u32 idx, u32 x, u32 y, u16 value);
extern void func_02041B6C(u32 bit);
void func_021E42B4(char *p)
{
    int x, y, n, mode;
    n = ((struct Obj00001 *)p)->f107C / 8;
    func_021E4DBC(p);
    for (y = 0; y < 24; y++) {
        for (x = 0; x < 52; x++) {
            mode = func_021E421C(p, x, y);
            func_02042FB0(7, x, y, func_021E41A0(n + x, y, p, mode));
        }
    }
    ((struct Obj00001 *)p)->f108C = ((struct Obj00001 *)p)->f107C % 8;
    ((struct Obj00001 *)p)->f1084 = 1;
    func_02041B6C(7);
}
