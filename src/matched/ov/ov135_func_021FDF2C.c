/*
 * function: func_021FDF2C
 * address:  0x021FDF2C
 * packet:   pkt_021FDF2C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02040C14  0x02040C14  arm
 *   tbl_022037A8   0x022037A8  data  a2
 *   tbl_022037B0   0x022037B0  data  a2
 *   tbl_022037BC   0x022037BC  data  a2
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 x;
    u16 y;
} Pos;

typedef struct {
    u8 pad0[0xD40];
    u32 frame;
    u8 padD44[0xD90 - 0xD44];
    u32 item[6];
    u32 page[3];
    u8 padDB4[0xDD8 - 0xDB4];
    u32 tab[2];
} Menu;

extern const Pos tbl_022037A8[];
extern const Pos tbl_022037B0[];
extern const Pos tbl_022037BC[];

extern u32 func_020450F0(u32 bg, u8 x, u8 y, u8 w, u8 h, u8 pal, u16 base);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
struct Cfg;
struct CharBuf;
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 v);
extern void func_02040C14(u32 a, u32 b, u32 c, u32 d);

void func_021FDF2C(Menu *p)
{
    int i;
    u32 v;

    p->frame = func_020450F0(0, 2, 0x15, 0x1b, 2, 0xd, 1);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->frame)), 0);
    v = p->frame;
    func_02045334((struct Descriptor *)v);
    func_02045374((struct Cfg *)v);
    func_020409B4(func_02045730((struct Descriptor *)v));
    func_02040C14(3, 0, 1, 0);
    for (i = 0; i < 6; i++) {
        p->item[i] = func_020450F0(3, tbl_022037BC[i].x, tbl_022037BC[i].y, 0xb, 2, 0xd, 0);
        func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->item[i])), 0);
        v = p->item[i];
        func_02045334((struct Descriptor *)v);
        func_02045374((struct Cfg *)v);
        func_020409B4(func_02045730((struct Descriptor *)v));
    }
    for (i = 0; i < 2; i++) {
        p->tab[i] = func_020450F0(3, tbl_022037A8[i].x, tbl_022037A8[i].y, 0x1c, 2, 0xd, 0);
        func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->tab[i])), 0);
        v = p->tab[i];
        func_02045334((struct Descriptor *)v);
        func_02045374((struct Cfg *)v);
        func_020409B4(func_02045730((struct Descriptor *)v));
    }
    for (i = 0; i < 3; i++) {
        p->page[i] = func_020450F0(3, tbl_022037B0[i].x, tbl_022037B0[i].y, 0xa, 2, 0xd, 0);
        func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->page[i])), 0);
        v = p->page[i];
        func_02045334((struct Descriptor *)v);
        func_02045374((struct Cfg *)v);
        func_020409B4(func_02045730((struct Descriptor *)v));
    }
}
