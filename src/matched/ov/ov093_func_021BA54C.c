/*
 * function: func_021BA54C
 * address:  0x021BA54C
 * packet:   pkt_ov093_021BA54C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B86B8  0x021B86B8  thumb  ov093
 *   func_021D826C  0x021D826C  thumb  ov093
 *   func_021D8270  0x021D8270  thumb  ov093
 */
#include "../include/Obj00324.h"
#include "../include/Obj21014.h"
#include "../include/Obj21015.h"

typedef unsigned char u8;

struct F {
    u8 b : 1;
};

extern void *func_021B86B8(void *);
extern unsigned int func_021D826C(void *);
extern int func_021D8270(void *, int, unsigned int);

int func_021BA54C(char *p)
{
    int v;

    if ((int)func_021B86B8(p) == 4) {
        v = 1;
    } else if (((struct F *)(p + 0x473))->b) {
        v = 6;
    } else if (((struct Obj21014 *)(*(char * *)&((struct Obj00324 *)p)->f0))->f90 != 6) {
        v = 5;
    } else if (func_021D826C(p + 0x448)) {
        v = func_021D8270(p + 0x448, *(u8 *)&((struct Obj00324 *)p)->f46C, (unsigned int)func_021B86B8(p));
    } else {
        if (((struct Obj00324 *)p)->f444 == 7) {
            ((struct Obj00324 *)p)->f444 = 1;
        }
        v = ((struct Obj00324 *)p)->f444;
    }
    ((struct Obj21015 *)(*(char * *)&((struct Obj00324 *)p)->f0))->f8C = v;
    return v;
}
