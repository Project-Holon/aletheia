/*
 * file:     field_place_name_p24.c
 * unit:     yes
 * function: func_021BDBF8, func_021BDC0C
 * address:  0x021BDBF8
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
 *   func_02012A30  0x02012A30  thumb
 *   func_02029D7C  0x02029D7C  thumb
 */
#include "../../matched/include/Obj02661.h"

struct BigObj;
struct Evt;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct {
    int pad0;
    void *f4;
    void *f8;
} Inner;

typedef struct {
    Inner *f0;
} Obj;

extern u32 func_02012A30(const struct BigObj *p);
extern u32 func_02029D7C(u32, u32);
extern u8 *func_020294C0(u8 *p, u32 a);
extern void func_02012374(struct Evt *evt, struct Evt **out);
int func_021BDBF8(u32 a);
void func_021BDC0C(Obj *p, void *b);


int func_021BDBF8(u32 a)
{
return func_02029D7C(func_02012A30((const struct BigObj *)*(u32 *)((u8 *)(*(u32 *)&((struct Obj02661 *)((u8 *)(a)))->f0) + 8)), *(u32 *)((u8 *)(*(u32 *)&((struct Obj02661 *)((u8 *)(a)))->f0) + 8));
}


void func_021BDC0C(Obj *p, void *b)
{
    Inner *q = p->f0;
    void *r = q->f4;

    func_02012A30(q->f8);
    func_02012374(b, (struct Evt **)func_020294C0(r, 6));
}
