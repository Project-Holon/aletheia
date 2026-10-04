/*
 * function: func_021BFC94
 * address: 0x021BFC94
 * packet: pkt_ov099_021BFC94
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BFBBC 0x021BFBBC thumb ov099
 *   func_021BA928 0x021BA928 thumb ov099
 *   func_021BA8EC 0x021BA8EC thumb ov099
 *   func_02156A3C 0x02156A3C thumb ov009
 *   func_021BA874 0x021BA874 thumb ov099
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 *   func_021BA828 0x021BA828 thumb ov099
 */
#include "../include/Obj07957.h"
typedef unsigned char u8;
extern void func_021BFBBC(char *);
extern int func_021BA928(char *);
extern void func_021BA8EC(char *);
extern int func_02156A3C(void);
extern void func_021BA874(char *, int);
extern void func_021BAAB8(char *, int, int);
extern void func_021BA828(char *);
int func_021BFC94(char *p, int ret)
{
    func_021BFBBC(p);
    if (func_021BA928(p)) {
        if (((struct Obj07957 *)p)->f1355) {
            func_021BA8EC(p);
            func_021BA874(p, func_02156A3C());
            func_021BAAB8(p, 0x10, 0);
            ((struct Obj07957 *)p)->f1E0 = 0x3c;
            ((struct Obj07957 *)p)->f1CC = 0x94;
        } else {
            func_021BA828(p);
            ((struct Obj07957 *)p)->f1CC = 0x12;
        }
    }
    return ret;
}
