/*
 * function: ov208_func_021C4EAC
 * address:  0x021C4EAC
 * packet:   pkt_ov208_021C4EAC
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201C6EC        0x0201C6EC  thumb
 *   func_02045770        0x02045770  arm
 *   func_02043B5C        0x02043B5C  arm
 *   func_02045334        0x02045334  arm
 *   ov208_func_021C4D68  0x021C4D68  thumb
 */

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

extern void func_0201C6EC(u32 print);
struct Descriptor;
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(u32 bmp, u8 v);
extern void func_02045334(struct Descriptor *win);
extern void ov208_func_021C4D68(u16 *heap, struct Ov208Menu *p, int key, int i, u32 print, u32 win,
                                u32 *active, u16 idx);

void ov208_func_021C4EAC(u16 *heap, struct Ov208Menu *p, int key)
{
    p->active[4] = 0;
    func_0201C6EC(p->print[4]);
    func_02043B5C((u32)func_02045770((struct Descriptor *)p->win[4]), 0);
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
