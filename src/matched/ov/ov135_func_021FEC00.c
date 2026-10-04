/*
 * function: func_021FEC00
 * address:  0x021FEC00
 * packet:   pkt_021FEC00
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
  *
  *
 * symbols:
 *   func_021F99F0  0x021F99F0  thumb
 *   func_021FF570  0x021FF570  thumb
 *   func_021F89A8  0x021F89A8  thumb
 *   func_021F7F9C  0x021F7F9C  thumb
 *   func_021F7B9C  0x021F7B9C  thumb
 *   func_021F8098  0x021F8098  thumb
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u8 pad0[4];
    u16 x4;
    u16 x6;
    u16 x8;
    u16 xA;
    u8 padC[0x20 - 0xC];
    u32 x20;
} Target;

typedef struct {
    u8 pad0[0x28];
    u32 state;
    u8 pad2C[0xB56 - 0x2C];
    u16 sel;
    s8 mode;
    u8 padB59[0xB6C - 0xB59];
    void *bankA;
    void *bankB;
    u8 padB74[0xD94 - 0xB74];
    void *winA;
    u8 padD98[0xD9C - 0xD98];
    void *winB;
    u8 padDA0[0xDE4 - 0xDA0];
    void *obj;
    u8 padDE8[0xE00 - 0xDE8];
    Target *target;
    u8 padE04[0xEEC - 0xE04];
    u8 area[0xFA0 - 0xEEC];
    u8 g[4];
} Work;

extern int func_021F99F0(void *obj);
extern void func_021FF570(u32 v);
struct CharBuf;
struct Descriptor;
extern void func_021F89A8(u8 *p, int i, u16 a, u16 b);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_021F7F9C(void *win, void *bank, u32 index, u32 y, u32 x, u16 color, void *g);
extern void *func_0201ADE4(unsigned int species, int form, unsigned int heap);
struct Personal;
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern void func_0201AE14(void *p);
extern int func_021F7B9C(void *p, int event);
extern void func_021F8098(void *win, void *bank, int mode, int force, u32 x, int y, u16 color, void *g);

int func_021FEC00(Work *p)
{
    int r = func_021F99F0(p->obj);
    u32 h;
    u32 v;

    switch (r) {
    case -2:
        func_021FF570(0);
        p->state = 0;
        func_021F89A8(p->area, p->target->x6 + p->target->x4, p->target->xA, p->target->x8);
        break;
    case -1:
        break;
    default:
        func_021FF570(0);
        p->sel = r;
        p->state = 0;
        func_02043B5C(func_02045770(p->winA), 0);
        func_021F7F9C(p->winA, p->bankB, r, 0, 0, 0x3C40, p->g);
        h = (u32)func_0201ADE4((u16)r, 0, 0x48);
        v = func_0201AE1C((const struct Personal *)h, 0x14);
        func_0201AE14((void *)h);
        p->target->x20 = v;
        func_021F89A8(p->area, p->target->x6 + p->target->x4, p->target->xA, p->target->x8);
        if (func_021F7B9C(&p->sel, p->target->x20) != 0) {
            func_02043B5C(func_02045770(p->winB), 0);
            func_021F8098(p->winB, p->bankA, p->mode, 1, 0, 0, 0x3C40, p->g);
        }
        break;
    }
    return 2;
}
