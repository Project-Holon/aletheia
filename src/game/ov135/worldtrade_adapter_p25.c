/*
 * file:     worldtrade_adapter_p25.c
 * unit:     yes
 * function: func_021FF474, func_021FF4D0, func_021FF50C, func_021FF570
 * address:  0x021FF474
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
 *   func_020413B0  0x020413B0  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045808  0x02045808  arm
 *   func_021F91DC  0x021F91DC  thumb
 *   func_02040618  0x02040618  arm
 */
struct MsgBank;
struct U16Vec;
typedef signed char s8;

typedef signed short s16;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    s16 a;
    s8 b;
    s8 c;
    s8 d;
} Rec;

typedef struct {
    u8 pad0[0xD3C];
    int scroll;
} Work;

typedef signed int s32;

extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_020409B4(u32 layer);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045808(struct U16Vec *vec);
extern int func_021F91DC(u8 *p, u32 b, u32 c, u32 d, u32 e, u16 f, u32 g);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_0207D658(u32 addr, int plane, int brightness);
void func_021FF474(void *win, void *bank, int flag, void *g);
int func_021FF4D0(Rec *x, Rec *y, int m, int n);
void func_021FF50C(Work *p);
void func_021FF570(u32 v);


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
    func_021F91DC(win, (u32)str, 0, 0, 0, color, (u32)g);
    func_02045808(str);
}


/*
 * True when two {s16, s8, s8, s8} records are equal field by field and
 * the two trailing arguments are equal.
 */
int func_021FF4D0(Rec *x, Rec *y, int m, int n)
{
    if (x->a == y->a && x->b == y->b && x->c == y->c && x->d == y->d && m == n) {
        return 1;
    }
    return 0;
}


void func_021FF50C(Work *p)
{
    func_02040618(0, 3, p->scroll);
    func_02040618(1, 3, p->scroll);
    func_02040618(2, 3, p->scroll);
    func_02040618(3, 3, p->scroll);
    func_02040618(4, 3, -p->scroll);
    func_02040618(5, 3, -p->scroll);
    func_02040618(6, 3, -p->scroll);
    func_02040618(7, 3, -p->scroll);
}


/*
 * Program the 0x04000050 display register from the flag, or clear it.
 */
void func_021FF570(u32 v)
{
    if (v != 0) {
        func_0207D658(0x04000050, 0xa, v);
    } else {
        *(u16 *)0x04000050 = 0;
    }
}
