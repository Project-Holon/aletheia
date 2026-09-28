/*
 * function: func_021F8098
 * address:  0x021F8098
 * packet:   pkt_021F8098
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045808  0x02045808  arm
 *   func_021F8078  0x021F8078  thumb
 *   func_021F91A0  0x021F91A0  thumb
 *   tbl_02202EB0   0x02202EB0  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern const u32 tbl_02202EB0[];

extern void *func_02045EC0(void *bank, u32 index);
extern void func_02045808(void *p);
extern u16 func_021F8078(int mode, u16 color);
extern int func_021F91A0(void *p, void *b, u32 c, u32 d, u32 e, u16 f, void *g);

void func_021F8098(void *win, void *bank, int mode, int force, u32 x, int y, u16 color, void *g)
{
    void *str;

    if (force != 0 || mode != 3) {
        str = func_02045EC0(bank, tbl_02202EB0[mode]);
        if (y > 3) {
            func_021F91A0(win, str, y, x, 0, func_021F8078(mode, color), g);
        } else {
            func_021F91A0(win, str, 0, x, y, func_021F8078(mode, color), g);
        }
        func_02045808(str);
    }
}
