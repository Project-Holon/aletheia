/*
 * function: func_021C8470
 * address: 0x021C8470
 * packet: pkt_ov128_021C8470
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020355C4 0x020355C4 arm
 *   func_021C875C 0x021C875C thumb ov128
 *   func_021C8784 0x021C8784 thumb ov128
 *   d_021CA68C 0x021CA68C data a4
 */
#include "../include/Obj06478.h"
typedef unsigned char u8;
extern void func_02027974(void *);
typedef unsigned int   u32;
struct TaskMenu;
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *);
extern void func_02027858(struct TaskMenu *m);
extern u8 func_020355C4(void);
extern void func_021C875C(u8 *, void *);
extern void func_021C8784(char *);
extern const int d_021CA68C[][8];
int func_021C8470(u8 *p, int *a, void *b)
{
    int n;
    int result;
    func_02027974(((struct Obj06478 *)p)->f194);
    if (func_020279E8(((struct Obj06478 *)p)->f194) == 1) {
        n = func_02027A04(*(u8 * *)&((struct Obj06478 *)p)->f194);
        func_02027858(((struct Obj06478 *)p)->f194);
    } else return 8;
    if (n == 3) {
        *a = func_020355C4();
        result = 2;
    } else {
        *a = func_020355C4();
        result = d_021CA68C[((struct Obj06478 *)p)->f198][n * 2];
    }
    if (result == 2) func_021C875C(p, b);
    else if (result == 9 || result == 12) func_021C875C(p, b);
    else func_021C8784((char *)p);
    return result;
}
