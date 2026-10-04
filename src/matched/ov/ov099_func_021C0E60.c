/*
 * function: func_021C0E60
 * address: 0x021C0E60
 * packet: pkt_ov099_021C0E60
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: signed int locals with the witnessed byte return prevent index-minus-one hoisting.
 * prototype: C23B8 forwards the visible index to 56860 and returns its pointer.
 * symbols:
 *   func_0201AC80 0x0201AC80 thumb
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 *   func_021C23B8 0x021C23B8 thumb ov099
 *   func_021BDD48 0x021BDD48 thumb ov099
 *   func_021BDD54 0x021BDD54 thumb ov099
 *   func_021C27E0 0x021C27E0 thumb ov099
 *   func_021BA874 0x021BA874 thumb ov099
 *   func_021C23C0 0x021C23C0 thumb ov099
 *   func_021C23C8 0x021C23C8 thumb ov099
 *   func_021BDE30 0x021BDE30 thumb ov099
 *   func_021C18C8 0x021C18C8 thumb ov099
 *   func_021BAADC 0x021BAADC thumb ov099
 *   func_021BC090 0x021BC090 thumb ov099
 */
#include "../include/Obj03224.h"
typedef unsigned short u16;
extern unsigned func_0201AC80(void *);
extern void func_021BAAB8(char *, int, int);
extern int func_021C23B8(int i);
extern unsigned char func_021BDD48(char *, void *);
extern int func_021BDD54(char *, void *);
extern unsigned char func_021C27E0(void *);
extern void func_021BA874(char *, int);
extern void func_021C23C0(void *a);
extern int func_021C23C8(char *, int);
extern void func_021BDE30(void *, int, int);
extern void func_021C18C8(char *, int, int);
extern void func_021BAADC(char *, int, int);
extern void func_021BC090(void *);
int func_021C0E60(char *p, int ret)
{
    int index;
    void *state;
    int kind, value, flag;
    index = ((struct Obj03224 *)p)->f242;
    func_0201AC80(((struct Obj03224 *)p)->fC8);
    if (((struct Obj03224 *)p)->f242 == 0) {
        func_021BAAB8(p, 0x4a, 0);
        ((struct Obj03224 *)p)->f1CC = 21;
    }
    state = (void *)func_021C23B8(index - 1);
    kind = func_021BDD48(p, state);
    value = func_021BDD54(p, state);
    flag = func_021C27E0(state);
    if (kind != func_021BDD48(p, p + 0x24c) ||
        value != func_021BDD54(p, p + 0x24c) ||
        flag != func_021C27E0(p + 0x24c) || kind == 6) {
        func_021BA874(p, index - 1);
        func_021BAAB8(p, 13, 0);
        ((struct Obj03224 *)p)->f1CC = 21;
        return ret;
    }
    func_021C23C0((void *)(index - 1));
    if (func_021C23C8(p, index - 1)) {
        ((struct Obj03224 *)p)->f1C4 = 0xe10;
        func_021BDE30(p, 3, value);
        func_021C18C8(p, 3, value);
        func_021BA874(p, index - 1);
        func_021BAADC(p, 14, 0);
        func_021BC090(p);
        ((struct Obj03224 *)p)->f242 = index;
        ((struct Obj03224 *)p)->f1CC = 37;
    } else {
        func_021BA874(p, index - 1);
        func_021BAAB8(p, 13, 0);
        ((struct Obj03224 *)p)->f1CC = 21;
    }
    return ret;
}
