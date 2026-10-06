/*
 * function: func_021BAC04
 * address:  0x021BAC04
 * packet:   pkt_ov093_021BAC04
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BB718  0x021BB718  thumb  ov093
 *   func_021BB798  0x021BB798  thumb  ov093
 *   func_021BB7D0  0x021BB7D0  thumb  ov093
 *   func_021B86B8  0x021B86B8  thumb  ov093
 *   func_021BBB60  0x021BBB60  thumb  ov093
 *   func_021BB5FC  0x021BB5FC  thumb  ov093
 *   func_021BABEC  0x021BABEC  thumb  ov093
 *   func_021BABF4  0x021BABF4  thumb  ov093
 *   func_021BB724  0x021BB724  thumb  ov093
 *   func_021BB280  0x021BB280  thumb  ov093
 */
#include "../include/Obj09946.h"

extern void func_021BB718(int a, int b);
extern int func_021BB798(unsigned char *p);
extern void func_021BB7D0(const unsigned char *p);
extern void *func_021B86B8(void ***);
extern int func_021BBB60(unsigned char *p);
extern int func_021BB5FC(unsigned char *p, int b);
extern void func_021BABEC(int *p, void *f);
extern void func_021BABF4(void *);
extern void func_021BB724(unsigned char *p, int a, int b, int c);
typedef unsigned char  u8;
extern int func_021BB280(u8 *p);

int func_021BAC04(char *p, int *st)
{
    int *q;

    switch (*st) {
    case 0:
        func_021BB718((int)p, 1);
        (*st)++;
    case 1:
        if (func_021BB798((unsigned char *)p)) {
            func_021BB7D0((const unsigned char *)p);
            if (func_021B86B8(*(void *** *)&((struct Obj09946 *)p)->fC) != (void *)4) {
                func_021BB5FC((unsigned char *)p, func_021BBB60((unsigned char *)(((struct Obj09946 *)p)->f44)));
                (*st)++;
            } else {
                func_021BABEC((int *)p, (void *)func_021BB280);
            }
        }
        break;
    case 2:
        if (func_021BB798((unsigned char *)p)) {
            func_021BB7D0((const unsigned char *)p);
            (*st)++;
        }
        break;
    case 3:
        q = *(int * *)&((struct Obj09946 *)p)->fCB0;
        func_021BB724((unsigned char *)p, 8, (int)(q + 2), *q);
        (*st)++;
        break;
    case 4:
        if (func_021BB798((unsigned char *)p)) {
            func_021BB7D0((const unsigned char *)p);
            func_021BABF4(p);
        }
        break;
    }
    return 0;
}
