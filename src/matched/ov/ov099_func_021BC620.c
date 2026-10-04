/*
 * function: func_021BC620
 * address:  0x021BC620
 * packet:   pkt_ov099_021BC620
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201DD68  0x0201DD68  thumb
 *   func_021BA858  0x021BA858  thumb  ov099
 *   func_021BDDD0  0x021BDDD0  thumb  ov099
 *   func_021BAAB8  0x021BAAB8  thumb  ov099
 *   func_0202EB14  0x0202EB14  thumb
 *   func_0202EB0C  0x0202EB0C  thumb
 *   func_021BA8EC  0x021BA8EC  thumb  ov099
 *
 * Lever: the +0x1CC store is written out in each arm (no early return), so the
 * compiler cross-jumps them into one shared store block.
 */
#include "../include/Obj04413.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;

extern void func_0201DD68(void);
extern u32 func_021BA858(char *p);
extern int func_021BDDD0(char *p);
extern void func_021BAAB8(char *p, int a, int b);
extern int func_0202EB14(void);
extern u32 func_0202EB0C(void);
extern void func_021BA8EC(char *p);

int func_021BC620(char *p, int v)
{
    int r;

    func_0201DD68();
    r = func_021BA858(p);
    if (r == -1) {
        return v;
    }
    if (r == 0) {
        if (func_021BDDD0(p) == 0 && ((struct Obj04413 *)p)->f132C == 0x4d) {
            func_021BAAB8(p, 0x79, 0);
            ((struct Obj04413 *)p)->f1CC = 0x96;
        } else if (func_0202EB14() == 0 && func_0202EB0C() != 0
                   && ((struct Obj04413 *)p)->f132C == 0x4c) {
            func_021BAAB8(p, 0x95, 0);
            ((struct Obj04413 *)p)->f1CC = 0xa6;
        } else {
            ((struct Obj04413 *)p)->f1CC = 0x52;
            func_021BA8EC(p);
        }
    } else {
        ((struct Obj04413 *)p)->f1353 = 0x90;
        ((struct Obj04413 *)p)->f1CC = 0x8a;
    }
    return v;
}
