/*
 * function: func_021DDFFC
 * address: 0x021DDFFC
 * packet: pkt_ov137_021DDFFC
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DCF50 0x021DCF50 thumb ov137
 *   func_021841A4 0x021841A4 thumb ov022
 *   func_02039338 0x02039338 arm
 *   func_021DD924 0x021DD924 thumb ov137
 */
#include "../include/Obj03840.h"
typedef unsigned short u16;
typedef signed short s16;
extern void *func_021DCF50(void *);
extern int func_021841A4(unsigned char *p);
extern u16 func_02039338(void);
extern void func_021DD924(char *);
int func_021DDFFC(char *p, int state) {
    if (((struct Obj03840 *)p)->f481C != 0) {
        if (((struct Obj03840 *)p)->f481C != func_021841A4(func_021DCF50(p)))
            ((struct Obj03840 *)p)->f481C = 0;
    }
    if (--((struct Obj03840 *)p)->f4818 < 0)
        ((struct Obj03840 *)p)->f481C = 0;
    if (++((struct Obj03840 *)p)->f124 > 60 && ((struct Obj03840 *)p)->f481C == 0) {
        ((struct Obj03840 *)p)->f118 = 0;
        func_02039338();
    }
    func_021DD924(p);
    return state;
}
