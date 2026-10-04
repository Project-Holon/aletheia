/*
 * function: func_021C1768
 * address: 0x021C1768
 * packet: pkt_ov099_021C1768
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * follower: two zero alignment bytes at 0x021C17D2.
 * symbols:
 *   func_021BA928 0x021BA928 thumb ov099
 *   func_021BA858 0x021BA858 thumb ov099
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 *   func_021BC090 0x021BC090 thumb ov099
 *   func_021BA8EC 0x021BA8EC thumb ov099
 *   func_0203C554 0x0203C554 arm
 */
#include "../include/Obj00008.h"
extern int func_021BA928(char *, int);
typedef unsigned int   u32;
extern u32 func_021BA858(char *p);
extern void func_021BAAB8(char *, int, int);
extern void func_021BC090(char *);
extern void func_021BA8EC(char *);
extern void func_0203C554(u32 a);
int func_021C1768(char *p, int ret)
{
    int choice;
    if (func_021BA928(p, ret) == 0) return ret;
    choice = func_021BA858(p);
    if (choice == -1) return ret;
    if (choice == 0) {
        func_021BAAB8(p, 76, 0);
        func_021BC090(p);
        ((struct Obj00008 *)p)->f244 = 1;
        ((struct Obj00008 *)p)->f1CC = 41;
        ((struct Obj00008 *)p)->f1E0 = 30;
    } else {
        func_021BA8EC(p);
        func_0203C554(1);
        ((struct Obj00008 *)p)->f1E0 = 20;
        ((struct Obj00008 *)p)->f1CC = 57;
    }
    return ret;
}
