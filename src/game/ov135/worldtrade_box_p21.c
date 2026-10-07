/*
 * file:     worldtrade_box_p21.c
 * unit:     yes
 * function: func_021F7FD4, func_021F8010, func_021F8078, func_021F8098, func_021F8104
 * address:  0x021F7FD4
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045808  0x02045808  arm
 *   func_022028C8  0x022028C8  thumb
 *   func_021F91A0  0x021F91A0  thumb
 *   func_021F7F80  0x021F7F80  thumb
 *   tbl_02202EB0   0x02202EB0  data
 */
struct MsgBank;
struct U16Vec;
typedef signed short s16;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_022028C8(void *win, u32 z, void *str, u32 x, u32 y, u32 z2, u16 color, void *g);
extern int func_021F91A0(u8 *p, u32 b, u32 c, u32 d, u32 e, u16 f, u32 g);
extern u16 func_021F7F80(int mode);
void func_021F7FD4(void *win, void *bank, u32 index, u32 y, u16 color, void *g);
void func_021F8010(void *win, void *bank, void *bank2, u32 index, u32 y, u32 x, u16 color, void *g);
u16 func_021F8078(int mode, u16 color);
void func_021F8098(void *win, void *bank, int mode, int force, u32 x, int y, u16 color, void *g);
void func_021F8104(void *win, void *bank, int mode, int force, u32 x, u32 y, u16 color, void *g);
extern const u32 tbl_02202EB0[];


void func_021F7FD4(void *win, void *bank, u32 index, u32 y, u16 color, void *g)
{
    void *str;

    if (index != 0) {
        str = func_02045EC0(bank, index);
        func_022028C8(win, 0, str, 0, y, 0, color, g);
        func_02045808(str);
    }
}


void func_021F8010(void *win, void *bank, void *bank2, u32 index, u32 y, u32 x, u16 color, void *g)
{
    void *str;

    if (index != 0) {
        str = func_02045EC0(bank, index);
        func_021F91A0(win, (u32)str, 0, x, y, color, (u32)g);
        func_02045808(str);
    } else {
        str = func_02045EC0(bank2, 0xBB);
        func_021F91A0(win, (u32)str, 0, x, y, color, (u32)g);
        func_02045808(str);
    }
}


u16 func_021F8078(int mode, u16 color)
{
    if (mode == 1) {
        return func_021F7F80(0);
    }
    if (mode == 2) {
        color = func_021F7F80(1);
    }
    return color;
}


void func_021F8098(void *win, void *bank, int mode, int force, u32 x, int y, u16 color, void *g)
{
    void *str;

    if (force != 0 || mode != 3) {
        str = func_02045EC0(bank, tbl_02202EB0[mode]);
        if (y > 3) {
            func_021F91A0(win, (u32)str, y, x, 0, func_021F8078(mode, color), (u32)g);
        } else {
            func_021F91A0(win, (u32)str, 0, x, y, func_021F8078(mode, color), (u32)g);
        }
        func_02045808(str);
    }
}


void func_021F8104(void *win, void *bank, int mode, int force, u32 x, u32 y, u16 color, void *g)
{
    void *str;

    if (force != 0 || mode != 3) {
        str = func_02045EC0(bank, tbl_02202EB0[mode]);
        func_022028C8(win, 0, str, x, y, 0, func_021F8078(mode, color), g);
        func_02045808(str);
    }
}
