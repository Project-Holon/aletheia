/*
 * function: func_021F8010
 * address:  0x021F8010
 * packet:   pkt_021F8010
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045808  0x02045808  arm
 *   func_021F91A0  0x021F91A0  thumb
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_02045EC0(void *bank, u32 index);
extern void func_02045808(void *p);
extern int func_021F91A0(void *p, void *b, u32 c, u32 d, u32 e, u16 f, void *g);

void func_021F8010(void *win, void *bank, void *bank2, u32 index, u32 y, u32 x, u16 color, void *g)
{
    void *str;

    if (index != 0) {
        str = func_02045EC0(bank, index);
        func_021F91A0(win, str, 0, x, y, color, g);
        func_02045808(str);
    } else {
        str = func_02045EC0(bank2, 0xBB);
        func_021F91A0(win, str, 0, x, y, color, g);
        func_02045808(str);
    }
}
