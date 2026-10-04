/*
 * function: func_021C10A8
 * address: 0x021C10A8
 * packet: pkt_ov099_021C10A8
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02156A3C 0x02156A3C thumb ov009
 *   func_021C23C0 0x021C23C0 thumb ov099
 *   func_021C23B8 0x021C23B8 thumb ov099
 *   func_021BA874 0x021BA874 thumb ov099
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 *   func_021BDD48 0x021BDD48 thumb ov099
 *   func_021C27E0 0x021C27E0 thumb ov099
 *   func_021BA7D8 0x021BA7D8 thumb ov099
 */
#include "../include/Obj03735.h"
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int   u32;
extern int func_02006224(u32 a0);
extern int func_02156A3C(void);
extern int func_021C23C0(int);
extern int func_021C23B8(int i);
extern void func_021BA874(char *, int);
extern void func_021BAAB8(char *, int, int);
extern u8 func_021BDD48(char *, void *);
extern int func_021C27E0(void *);
extern void func_021BA7D8(void *p);
int func_021C10A8(char *p, int ret)
{
    int zero = 0;
    void *s;
    if (func_02006224(0) != 0) return ret;
    if (func_021C23C0(func_02156A3C()) == 0) {
        func_021BA874(p, ((struct Obj03735 *)p)->f1F0);
        func_021BAAB8(p, 15, zero);
        ((struct Obj03735 *)p)->f1CC = 19;
        return ret;
    }
    s = (void *)func_021C23B8(func_02156A3C());
    func_021BDD48(p, ((struct Obj03735 *)p)->f8);
    func_021BDD48(p, s);
    func_021C27E0(((struct Obj03735 *)p)->f8);
    ((struct Obj03735 *)p)->f242 = func_02156A3C() + 1;
    if (((struct Obj03735 *)p)->f1351 == 0) {
        func_021BA874(p, func_02156A3C());
        func_021BAAB8(p, 8, zero);
    }
    func_021BA7D8(p);
    ((struct Obj03735 *)p)->f1CC = 41;
    ((struct Obj03735 *)p)->f1E0 = 30;
    return ret;
}
