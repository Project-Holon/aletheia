/*
 * function: func_021C1634
 * address: 0x021C1634
 * packet: pkt_ov099_021C1634
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA928 0x021BA928 thumb ov099
 *   func_021BA858 0x021BA858 thumb ov099
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 *   func_021BA8EC 0x021BA8EC thumb ov099
 *   func_021C2408 0x021C2408 thumb ov099
 */
#include "../include/Obj00008.h"
extern int func_021BA928(char *, int);
typedef unsigned int   u32;
extern u32 func_021BA858(char *p);
extern void func_021BAAB8(char *, int, int);
extern void func_021BA8EC(char *);
extern void func_021C2408(char *);
int func_021C1634(char *p, int ret)
{
    int choice;
    if (func_021BA928(p, ret) == 0) return ret;
    choice = func_021BA858(p);
    if (choice == -1) return ret;
    if (choice == 0) {
        *(int *)&((struct Obj00008 *)p)->f108 = 0;
        func_021BAAB8(p, 26, 1);
        ((struct Obj00008 *)p)->f1CC = 51;
        ((struct Obj00008 *)p)->f1E0 = 1;
    } else {
        *(int *)&((struct Obj00008 *)p)->f108 = 0;
        func_021BA8EC(p);
        ((struct Obj00008 *)p)->f1CC = 11;
        func_021C2408(p);
    }
    return ret;
}
