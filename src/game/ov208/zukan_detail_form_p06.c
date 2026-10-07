/*
 * file:     zukan_detail_form_p06.c
 * unit:     yes
 * function: func_021C4E54, func_021C4EAC, func_021C4F30
 * address:  0x021C4E54
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201C6EC        0x0201C6EC  thumb
 *   func_02045770        0x02045770  arm
 *   func_02043B5C        0x02043B5C  arm
 *   func_02045334        0x02045334  arm
 *   ov208_func_021C4D68  0x021C4D68  thumb
 *   func_02041EE4  0x02041EE4  arm
 */
#include "../../matched/include/Obj14663.h"

struct CharBuf;
struct PrintSys;
struct Descriptor;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Ov208Menu {
    u32 f0;
    u32 font;
    u8  pad8[0x540];
    u16 count;
    u16 pad54a[2];
    u16 sel;
    u16 sel2;
    u16 pad552;
    u32 win[5];
    u32 active[5];
    u32 print[5];
    u8  pad590[0x128];
    u32 state;
};

extern void func_0201C6EC(struct PrintSys *p);
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void ov208_func_021C4D68(u16 *heap, struct Ov208Menu *p, int key, int i, u32 print, u32 win,
                                u32 *active, u16 idx);
extern void func_02041EE4(u32 index, u32 a, u32 b);
void ov208_func_021C4E54(u16 *heap, struct Ov208Menu *p, int key);
void ov208_func_021C4EAC(u16 *heap, struct Ov208Menu *p, int key);
void ov208_func_021C4F30(void *unused, u8 *p);


void ov208_func_021C4E54(u16 *heap, struct Ov208Menu *p, int key)
{
    p->active[3] = 0;
    func_0201C6EC((struct PrintSys *)p->print[3]);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->win[3])), 0);
    ov208_func_021C4D68(heap, p, key, 3, p->print[3], p->win[3], &p->active[3], p->sel);
}


void ov208_func_021C4EAC(u16 *heap, struct Ov208Menu *p, int key)
{
    p->active[4] = 0;
    func_0201C6EC((struct PrintSys *)p->print[4]);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->win[4])), 0);
    switch (p->state) {
    case 0:
        func_02045334((struct Descriptor *)p->win[4]);
        break;
    case 4:
        if (p->count >= 2)
            ov208_func_021C4D68(heap, p, key, 4, p->print[4], p->win[4], &p->active[4], p->sel2);
        break;
    }
}


void ov208_func_021C4F30(void *unused, u8 *p)
{
    switch (((struct Obj14663 *)p)->f6B8) {
    case 0:
        func_02041EE4(2, 0, -0x40);
        break;
    case 4:
        if (((struct Obj14663 *)p)->f548 >= 2)
            func_02041EE4(2, 0, 0);
        else
            func_02041EE4(2, 0, -0x40);
        break;
    }
}
