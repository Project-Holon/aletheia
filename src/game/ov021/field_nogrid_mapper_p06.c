/*
 * file:     field_nogrid_mapper_p06.c
 * unit:     yes
 * function: func_021B977C, func_021B97D0
 * address:  0x021B977C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B976C  0x021B976C  thumb  ov021
 *   func_021B87D8  0x021B87D8  thumb  ov021
 *   d_021DE2B0     0x021DE2B0  data  a4
 *   d_021DE2B4     0x021DE2B4  data  a4
 *   d_021DE2BC     0x021DE2BC  data  a4
 */
#include "../../matched/include/Obj04250.h"
#include "../../matched/include/Obj20089.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    char b[0x70];
} E70;

typedef struct {
    u16 h0;
    char pad[0xE];
    E70 *f10;
} Obj;

void func_021B976C(void *a, void *b, void *c);
u8 *func_021B87D8(u8 *p, u32 idx);
void func_021B977C(u8 *p);
int func_021B97D0(Obj *p, E70 *e);
extern u8 d_021DE2B0[];
extern u8 d_021DE2B4[];
extern u8 d_021DE2BC[];


/*
 * Addresses are Black-image addresses.
 */
void func_021B977C(u8 *p)
{
    void *x;
    void *y;

    if (((struct Obj04250 *)p)->f0 == 0) {
        func_021B976C(0, ((struct Obj04250 *)p)->f4, d_021DE2B0);
    } else if (((struct Obj04250 *)p)->f0 == 1) {
        x = func_021B87D8(((struct Obj04250 *)p)->f24, **(u32 * *)&((struct Obj04250 *)p)->f4);
        y = func_021B87D8(((struct Obj04250 *)p)->f24, ((struct Obj20089 *)(*(u8 * *)&((struct Obj04250 *)p)->f4))->f4);
        func_021B976C(d_021DE2B4, x, 0);
        func_021B976C(d_021DE2BC, y, d_021DE2B0);
    }
}


int func_021B97D0(Obj *p, E70 *e)
{
    int i;

    for (i = 0; i < p->h0; i++) {
        if (e == &p->f10[i]) {
            return i;
        }
    }
    return 0;
}
