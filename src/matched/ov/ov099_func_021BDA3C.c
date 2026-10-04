/*
 * function: func_021BDA3C
 * address: 0x021BDA3C
 * packet: pkt_ov099_021BDA3C
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1E8 0x0203D1E8 arm
 *   func_0203D378 0x0203D378 arm
 *   func_021BA874 0x021BA874 thumb ov099
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 *   func_021BC090 0x021BC090 thumb ov099
 *   func_02039C68 0x02039C68 arm
 */
#include "../include/Obj07952.h"
typedef unsigned short u16;
struct Entry;
extern struct Entry *func_020399A8(void);
extern int func_0203D1E8(int, int);
extern int func_0203D378(int);
extern void func_021BA874(void *, int);
extern void func_021BAAB8(char *, int, int);
extern void func_021BC090(char *);
struct Link;
extern void func_02039C68(struct Link *, unsigned int, unsigned int);
int func_021BDA3C(char *p, int v)
{
    int zero;
    zero = 0;
    if (func_0203D378(func_0203D1E8((int)func_020399A8(), 0)) == 0) {
        func_021BA874(p, ((struct Obj07952 *)p)->f242 - 1);
        func_021BAAB8(p, 0x77, zero);
        ((struct Obj07952 *)p)->f1CC = 0xaa;
    } else {
        func_021BA874(p, ((struct Obj07952 *)p)->f242 - 1);
        func_021BAAB8(p, 0x4c, zero);
        func_021BC090(p);
        func_02039C68((struct Link *)func_020399A8(), 0x1b, 10);
        ((struct Obj07952 *)p)->f1CC = 0x49;
    }
    return v;
}
