/*
 * function: func_021FF474
 * address:  0x021FF474
 * packet:   pkt_021FF474
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020413B0  0x020413B0  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045808  0x02045808  arm
 *   func_021F91DC  0x021F91DC  thumb
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_020409B4(u32 layer);
extern void *func_02045EC0(void *bank, u32 index);
extern void func_02045808(void *p);
extern int func_021F91DC(void *p, void *b, u32 c, u32 d, u32 e, u16 f, void *g);

void func_021FF474(void *win, void *bank, int flag, void *g)
{
    void *str;
    u16 color;
    u8 pal;

    color = 0x3C40;
    if (flag != 0) {
        color = 0x440;
        pal = 0;
    } else {
        pal = 2;
    }
    func_020413B0(1, 0x11, 2, 0xF, 4, pal);
    func_020409B4(1);
    str = func_02045EC0(bank, 0x4B);
    func_021F91DC(win, str, 0, 0, 0, color, g);
    func_02045808(str);
}
