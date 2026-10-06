/*
 * function: func_02186324
 * address:  0x02186324
 * packet:   pkt_ov023_02186324
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02186164  0x02186164  thumb  ov023
 *   func_02186558  0x02186558  thumb  ov023
 *   func_02186480  0x02186480  thumb  ov023
 *   func_02186304  0x02186304  thumb  ov023
 *   func_0218654C  0x0218654C  thumb  ov023
 *   func_0204B878  0x0204B878  arm
 */
#include "../include/Obj00460.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02186164(char *p);
extern int func_02186558(char *p);
extern void func_02186480(char *p);
extern void func_02186304(char *p, int a);
extern int func_0218654C(char *p);
struct Obj;
extern void func_0204B878(struct Obj *p, u16 value);

int func_02186324(u8 *p)
{
    int st;
    int r;

    st = func_02186164((char *)p);
    switch (st) {
    case 0:
        break;
    case 1:
        if (((struct Obj00460 *)p)->f198 > 0x10) {
            break;
        }
        if (func_02186558((char *)p) != 1) {
            ((struct Obj00460 *)p)->f9E78 = 1;
        }
        ((struct Obj00460 *)p)->f19C = 0x16;
        if (((struct Obj00460 *)p)->f9E70 != 0) {
            func_02186480((char *)p);
            func_0204B878(((struct Obj00460 *)p)->fF0, 0x15);
        }
        return 2;
    case 2:
    case 3:
    case 4:
        if (st < ((struct Obj00460 *)p)->f1A8) {
            if (((struct Obj00460 *)p)->f9E6C == 2) {
                func_02186304((char *)p, 0);
            } else if (((struct Obj00460 *)p)->f9E7C == 0) {
                func_02186304((char *)p, 1);
            } else {
                func_02186304((char *)p, 0);
            }
        }
        break;
    case 5:
        break;
    }
    if (st < ((struct Obj00460 *)p)->f1A8) {
        ((struct Obj00460 *)p)->f1AC = func_0218654C((char *)p);
        r = func_02186558((char *)p);
        ((struct Obj00460 *)p)->f1B0 = r;
        if (((struct Obj00460 *)p)->f9E7C != 0 && (r & ((struct Obj00460 *)p)->f9E80) == 0) {
            func_02186304((char *)p, 1);
            ((struct Obj00460 *)p)->f9E6C = 1;
            ((struct Obj00460 *)p)->f9E7C = 0;
            ((struct Obj00460 *)p)->f9E80 = 0;
        }
    }
    ((struct Obj00460 *)p)->f1A8 = func_02186164((char *)p);
    if (((struct Obj00460 *)p)->f1AC < func_0218654C((char *)p)) {
        ((struct Obj00460 *)p)->f9E6C = 2;
        ((struct Obj00460 *)p)->f9E7C = 1;
        ((struct Obj00460 *)p)->f9E80 = func_02186558((char *)p) ^ ((struct Obj00460 *)p)->f1B0;
    }
    return 1;
}
