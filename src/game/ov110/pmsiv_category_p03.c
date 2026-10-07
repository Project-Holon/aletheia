/*
 * file:     pmsiv_category_p03.c
 * unit:     yes
 * function: func_021BB5A0, func_021BB5E0
 * address:  0x021BB5A0
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02040618 0x02040618 arm
 */
#include "../../matched/include/Obj22359.h"
#include "../../matched/include/Obj22360.h"

struct Descriptor;
struct CharBuf;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

extern u32 func_020450F0(u32,u32,u32,u32,u8,u8,u8);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *);
extern void func_02045374(u32);
extern void func_020409B4(u32);
extern void func_02040618(u32,u32,u32);
u8 *func_021BB5A0(u8 *p,u8 *q);
void func_021BB5E0(u8 *p);

/*
 * extent: trailing two-byte zero padding
 */
u8 *func_021BB5A0(u8 *p,u8 *q) {
    u32 a;
    a=func_020450F0(1,10,3,11,2,12,1);
    func_02043B5C(func_02045770((struct Descriptor *)a),1);
    func_02045334((struct Descriptor *)a);
    ((struct Obj22359 *)p)->f94=a;
    return q+0x16;
}

void func_021BB5E0(u8 *p) { u32 win; win=func_020450F0(6,1,1,30,22,0,1); func_02045374(win); func_020409B4(6); func_02040618(6,3,-192); ((struct Obj22360 *)p)->f98=win; }
