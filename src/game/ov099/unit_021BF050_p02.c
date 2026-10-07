/*
 * file:     unit_021BF050_p02.c
 * unit:     yes
 * function: func_021BFC04, func_021BFC94
 * address:  0x021BFC04
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02156A3C 0x02156A3C thumb ov009
 *   func_021C23B8 0x021C23B8 thumb ov099
 *   func_021BDD48 0x021BDD48 thumb ov099
 *   func_021BDD54 0x021BDD54 thumb ov099
 *   func_021BF280 0x021BF280 thumb ov099
 *   func_021C1BEC 0x021C1BEC thumb ov099
 *   func_020362DC 0x020362DC arm
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 *   func_021BA8EC 0x021BA8EC thumb ov099
 *   func_021BA874 0x021BA874 thumb ov099
 *   func_021BFBBC 0x021BFBBC thumb ov099
 *   func_021BA928 0x021BA928 thumb ov099
 *   func_021BA828 0x021BA828 thumb ov099
 */
#include "../../matched/include/Obj07956.h"
#include "../../matched/include/Obj07957.h"

typedef unsigned char u8;

typedef unsigned int u32;

extern int func_02156A3C(void);
extern int func_021C23B8(int i);
extern u8 func_021BDD48(char *, void *);
extern int func_021BDD54(char *, void *);
extern void func_021BF280(void *a, void *b);
extern void func_021C1BEC(u8 *p);
extern u32 func_020362DC(void);
extern void func_021BAAB8(char *, int, int);
extern void func_021BA8EC(char *);
extern void func_021BA874(char *, int);
extern void func_021BFBBC(char *);
extern int func_021BA928(char *);
extern void func_021BA828(char *);
int func_021BFC04(char *p, int ret);
int func_021BFC94(char *p, int ret);

int func_021BFC04(char *p, int ret)
{
    void *s = (void *)func_021C23B8(func_02156A3C());
    func_021BDD48(p, s);
    func_021BDD54(p, s);
    func_021BF280(p, (void *)0x21);
    func_021C1BEC((u8 *)p);
    if (func_020362DC() & 2) {
        func_021BAAB8(p, 0x11, 0);
        ((struct Obj07956 *)p)->f1CC = 0x11;
    } else if (((struct Obj07956 *)p)->f1355) {
        func_021BA8EC(p);
        func_021BA874(p, func_02156A3C());
        func_021BAAB8(p, 0x10, 0);
        ((struct Obj07956 *)p)->f1E0 = 0x3c;
        ((struct Obj07956 *)p)->f1CC = 0x94;
    } else {
        func_021BFBBC(p);
    }
    return ret;
}

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
