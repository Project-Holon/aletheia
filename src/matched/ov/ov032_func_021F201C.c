/*
 * function: func_021F201C
 * address:  0x021F201C
 * packet:   pkt_ov032_021F201C
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F201C 0x021F201C thumb
 *   func_021F20A8 0x021F20A8 thumb
 *   func_02043B5C 0x02043B5C arm
 *   func_0201C7D0 0x0201C7D0 thumb
 *   func_0201C724 0x0201C724 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02045770 0x02045770 arm
 *   func_020409B4 0x020409B4 arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Cfg;
struct CharBuf;
struct Descriptor;
extern void func_021F20A8(char *p, char *q, int *r);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201C7D0(u32 bmp, u32 x, u32 y, const void *text, u32 f, u16 color);
extern void func_0201C724(u32 a, u32 bmp, u32 x, u32 y, const void *text, u32 f, u16 color);
struct Descriptor;
extern void func_02045334(struct Descriptor *a);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void *func_02045770(struct Descriptor *p);
extern void func_020409B4(u32 index);

void func_021F201C(char *p, char *q, void *text, u16 x, u8 y, u8 a5, u16 col, u32 a7)
{
    u32 w;
    u32 v;

    func_02043B5C((struct CharBuf *)(*(u32 *)(q + 4)), a5);
    if (*(u8 *)(p + 0x7a) != 0) {
        func_0201C7D0(*(u32 *)(q + 4), x, y, text, *(u32 *)(p + 0xb0), col);
        w = *(u32 *)q;
        func_02045334((struct Descriptor *)w);
        func_02045374((struct Cfg *)w);
        func_020409B4(func_02045730((struct Descriptor *)w));
        return;
    }
    v = *(u32 *)(p + 0xb4);
    func_0201C724(v, (u32)func_02045770((struct Descriptor *)*(u32 *)(q + 8)), x, y, text,
                  *(u32 *)(p + 0xb0), col);
    *(u8 *)(q + 0xc) = 1;
    func_021F20A8(p, q, (int *)a7);
}
