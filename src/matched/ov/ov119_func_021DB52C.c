/*
 * function: func_021DB52C
 * address: 0x021DB52C
 * packet: pkt_ov119_021DB52C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203633C 0x0203633C arm
 *   func_020355D8 0x020355D8 arm
 *   func_021DD018 0x021DD018 thumb ov119
 *   func_021E4E0C 0x021E4E0C thumb ov119
 *   func_021DB4EC 0x021DB4EC thumb ov119
 *   func_021DB4B4 0x021DB4B4 thumb ov119
 *   func_020061E4 0x020061E4 thumb
 *   func_021DB7AC 0x021DB7AC thumb ov119
 *   d_021E7FE0 0x021E7FE0 data a4
 */
#include "../include/Obj00130.h"
extern unsigned int func_0203633C(void);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void func_020355D8(u8 v);
extern void func_021DD018(char *, int);
extern int func_021E4E0C(char *, int *);
extern int func_021DB4EC(char *, int);
extern int func_021DB4B4(int);
extern void func_020061E4(u32 a);
extern void func_021DB7AC(char *, int, int);
extern const int d_021E7FE0[];
void func_021DB52C(char *p)
{
    int changed = 0;
    int i, v;
    unsigned int k = func_0203633C();
    if (((struct Obj00130 *)p)->fF60 != 0)
        return;
    if (k & 0x100) {
        func_020355D8(0);
        for (i = 0; i < ((struct Obj00130 *)p)->f630 + 1; i++) {
            if (d_021E7FE0[i] > ((struct Obj00130 *)p)->f107C) {
                ((struct Obj00130 *)p)->f107C = d_021E7FE0[i];
                changed = 1;
                break;
            }
        }
        if (!changed) {
            changed = 1;
            ((struct Obj00130 *)p)->f107C = d_021E7FE0[0];
        }
        func_021DD018(p, changed);
    } else if (k & 0x200) {
        func_020355D8(0);
        for (i = ((struct Obj00130 *)p)->f630; i >= 0; i--) {
            if (d_021E7FE0[i] < ((struct Obj00130 *)p)->f107C) {
                ((struct Obj00130 *)p)->f107C = d_021E7FE0[i];
                changed = 1;
                break;
            }
        }
        if (!changed) {
            changed = 1;
            ((struct Obj00130 *)p)->f107C = d_021E7FE0[((struct Obj00130 *)p)->f630];
        }
        func_021DD018(p, changed);
    } else if (func_0203633C() == 0x40) {
        func_020355D8(0);
        if (func_021E4E0C(p, &v) == 0)
            ((struct Obj00130 *)p)->fF74 = v;
        if (--((struct Obj00130 *)p)->fF78 < 0) {
            if (((struct Obj00130 *)p)->fF74 < 2)
                ((struct Obj00130 *)p)->fF78 = 2;
            else
                ((struct Obj00130 *)p)->fF78 = 4;
        }
        ((struct Obj00130 *)p)->f1080 = ((struct Obj00130 *)p)->f1080 - 1;
        changed = 1;
    } else if (func_0203633C() == 0x80) {
        int x;
        func_020355D8(0);
        if (func_021E4E0C(p, &v) == 0)
            ((struct Obj00130 *)p)->fF74 = v;
        x = ++((struct Obj00130 *)p)->fF78;
        if (((struct Obj00130 *)p)->fF74 < 2) {
            if (x >= 3)
                ((struct Obj00130 *)p)->fF78 = 0;
        } else if (x >= 5)
            ((struct Obj00130 *)p)->fF78 = 0;
        ((struct Obj00130 *)p)->f1080 = ((struct Obj00130 *)p)->f1080 - 1;
        changed = 1;
    } else if (func_0203633C() == 0x10) {
        func_020355D8(0);
        ((struct Obj00130 *)p)->f1080 = ((struct Obj00130 *)p)->f1080 - 1;
        changed = 1;
        if (func_021E4E0C(p, &v) == 0) {
            ((struct Obj00130 *)p)->fF74 = v;
        } else {
            ((struct Obj00130 *)p)->fF74 = ((struct Obj00130 *)p)->fF74 + 1;
            if (func_021DB4EC(p, ((struct Obj00130 *)p)->fF74) == 0) {
                ((struct Obj00130 *)p)->f107C = func_021DB4B4(((struct Obj00130 *)p)->fF74 + 1) - 0x100;
                ((struct Obj00130 *)p)->f1080 = -1;
            }
        }
        if (((struct Obj00130 *)p)->fF74 >= ((struct Obj00130 *)p)->f634)
            ((struct Obj00130 *)p)->fF74 = 0;
        if (((struct Obj00130 *)p)->fF74 < 2 && ((struct Obj00130 *)p)->fF78 >= 3)
            ((struct Obj00130 *)p)->fF78 = 2;
    } else if (func_0203633C() == 0x20) {
        func_020355D8(0);
        ((struct Obj00130 *)p)->f1080 = ((struct Obj00130 *)p)->f1080 + 1;
        changed = 1;
        if (func_021E4E0C(p, &v) == 0) {
            ((struct Obj00130 *)p)->fF74 = v;
        } else {
            ((struct Obj00130 *)p)->fF74 = ((struct Obj00130 *)p)->fF74 - 1;
            if (((struct Obj00130 *)p)->fF74 < 0)
                ((struct Obj00130 *)p)->fF74 = ((struct Obj00130 *)p)->f634 - 1;
            if (func_021DB4EC(p, ((struct Obj00130 *)p)->fF74) == 0) {
                ((struct Obj00130 *)p)->f107C = func_021DB4B4(((struct Obj00130 *)p)->fF74);
                ((struct Obj00130 *)p)->f1080 = -1;
            }
        }
        if (((struct Obj00130 *)p)->fF74 < 0)
            ((struct Obj00130 *)p)->fF74 = ((struct Obj00130 *)p)->f634 - 1;
        if (((struct Obj00130 *)p)->fF74 < 2 && ((struct Obj00130 *)p)->fF78 >= 3)
            ((struct Obj00130 *)p)->fF78 = 2;
    }
    if (changed) {
        ((struct Obj00130 *)p)->f1084 = 1;
        func_020061E4(0x548);
        func_021DB7AC(p, 0, 1);
    }
}
