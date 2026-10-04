/*
 * function: func_021FD790
 * address:  0x021FD790
 * packet:   pkt_021FD790
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
 *   func_021F91DC  0x021F91DC  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    void *win;
} Pane;

struct Cfg;
struct Descriptor;
struct MsgBank;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045808(struct U16Vec *vec);
extern int func_021F91DC(u8 *p, u32 b, u32 c, u32 d, u32 e, u16 f, u32 g);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);

void func_021FD790(void *bank, Pane *pane, u32 index, void *g)
{
    void *str = func_02045EC0(bank, index);
    void *win;

    func_021F91DC(pane->win, (u32)str, 0, 0, 1, 0x3C40, (u32)g);
    win = pane->win;
    func_02045334(win);
    func_02045374(win);
    func_020409B4(func_02045730(win));
    func_02045808(str);
}
