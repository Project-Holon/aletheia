/*
 * function: func_021B9C04
 * address:  0x021B9C04
 * packet:   pkt_ov068_021B9C04
 * region:   ov068
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The rounded width goes through a u8 local that is both stored to the
 * table row and passed on (the call reloading the field is 4 bytes longer).
 * func_0201D304 takes the string first and the font second.
 *
 * symbols:
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201D304  0x0201D304  thumb
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_0201C7A4  0x0201C7A4  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_02045808  0x02045808  arm
 *   func_020437D4  0x020437D4  arm
 *   func_02082A90  0x02082A90  arm
 *   func_02045738  0x02045738  arm
 *   func_0201C7D0  0x0201C7D0  thumb
 *   func_02045C04  0x02045C04  arm
 *   func_0201D83C  0x0201D83C  thumb
 *   d_021BB820     0x021BB820  data  ov068  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

typedef struct {
    u32 msg;
    u8 x;
    u8 y;
    u8 w;
    u8 h;
} Ent;

extern Ent d_021BB820[];

extern u32  func_0201D7EC(u32 a, u32 b, u32 c, u32 d, u32 e);
extern u32  func_02045B38(u32 a, u32 b, u32 c, u32 d);
extern u32  func_02045EC0(u32 a, u32 b);
extern u32  func_0201D304(u32 a, u32 b, u32 c);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(u32 win, u32 c);
extern void func_0201C7A4(u32 a, s16 b, s16 c, u32 d, u32 e);
extern void func_0201C7D0(u32 a, s16 b, s16 c, u32 d, u32 e, u16 f);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(u32 a);
extern u32  func_02045730(u32 a);
extern void func_02041B6C(u32 a);
extern void func_02045808(u32 a);
extern u32  func_020437D4(u32 a);
extern void func_02082A90(u32 a, u32 b, u32 n);
extern u32  func_02045738(u32 a);
extern void func_02045C04(u32 a);
extern void func_0201D83C(u32 a);

void func_021B9C04(u32 *p)
{
    u32 font;
    u32 msg;
    u32 str;
    u32 w;
    int i;
    int x;
    Ent *e;
    u8 wv;

    font = func_0201D7EC(0x17, 0, 0, 0, 0x1c);
    msg = func_02045B38(0, 2, 0x1d, 0x1c);
    for (i = 0; i < 16; i++) {
        x = 0;
        switch (i) {
        case 0:
            x = 7;
            break;
        case 1:
            x = 4;
            break;
        case 2:
            x = 2;
            break;
        }
        e = &d_021BB820[i];
        str = func_02045EC0(msg, d_021BB820[i].msg);
        wv = (x + func_0201D304(str, font, 0) + 7) >> 3;
        e->w = wv;
        p[i] = func_020450F0(1, e->x, e->y, wv, e->h, 0, 1);
        func_02043B5C((u32)func_02045770((struct Descriptor *)p[i]), 0);
        func_0201C7A4((u32)func_02045770((struct Descriptor *)p[i]), x, 0, str, font);
        w = p[i];
        func_02045334((struct Descriptor *)w);
        func_02045374(w);
        func_02041B6C(func_02045730(w));
        func_02045808(str);
    }
    w = *(u32 *)(p[22] + 0x14);
    func_02082A90(w, func_020437D4((u32)func_02045770((struct Descriptor *)p[16])), 0x600);
    str = func_02045EC0(msg, 0);
    x = func_02045738(p[16]) * 4;
    x -= func_0201D304(str, font, 0) >> 1;
    func_0201C7D0((u32)func_02045770((struct Descriptor *)p[16]), x, 4, str, font, 0x3dc1);
    w = p[16];
    func_02045334((struct Descriptor *)w);
    func_02045374(w);
    func_02041B6C(func_02045730(w));
    func_02045808(str);
    func_02045C04(msg);
    func_0201D83C(font);
}
