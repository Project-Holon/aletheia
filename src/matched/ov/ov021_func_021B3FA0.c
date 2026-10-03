/*
 * function: func_021B3FA0
 * address:  0x021B3FA0
 * packet:   pkt_ov021_021B3FA0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021DE18C    0x021DE18C data ov021 a4
 *   d_021DE170    0x021DE170 data ov021 a4
 *   func_020450F0 0x020450F0 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045770 0x02045770 arm
 *   func_0201C7D0 0x0201C7D0 thumb
 *   func_02045808 0x02045808 arm
 *   func_0201C440 0x0201C440 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

typedef struct {
    u32 f0;
    u8  f4;
    u8  f5;
    u8  f6;
    u8  f7;
    u16 f8;
} WinTmpl;

extern WinTmpl *d_021DE18C[];
extern WinTmpl *d_021DE170[];

extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern u32 func_02045EC0(u32 a, u32 b);
extern u32 func_02045770(u32 a);
extern void func_0201C7D0(u32 a, s16 b, s16 c, u32 d, u32 e, u32 f);
extern void func_02045808(u32 a);
extern u32 func_0201C440(u16 heap);
extern void func_02045334(u32 a);
extern void func_02045374(u32 a);
extern u32 func_02045730(u32 a);
extern void func_020409B4(u32 a);

void func_021B3FA0(char *w)
{
    WinTmpl **tbl;
    WinTmpl *e;
    int i;
    u32 t;
    u32 bg;

    tbl = d_021DE18C;
    if (*(u8 *)(w + 0x163) != 1) {
        tbl = d_021DE170;
    }
    for (i = 0; i < 7; i++) {
        e = tbl[i];
        ((u32 *)(w + 0x164))[i] = func_020450F0((u8)e->f0, e->f4, e->f5, e->f6, e->f7, (u8)e->f8, 1);
    }
    t = func_02045EC0(*(u32 *)(w + 0x188), 0x14);
    func_0201C7D0(func_02045770(*(u32 *)(w + 0x164)), 0, 0, t, *(u32 *)(w + 8), 0x3C4F);
    func_02045808(t);
    *(u32 *)(w + 0x1A8) = *(u32 *)(w + 0x16C);
    *(u8 *)(w + 0x1AC) = 0;
    *(u32 *)(w + 0x1B0) = func_0201C440(*(u16 *)(w + 4));
    if (*(u8 *)(w + 0x163) == 1) {
        bg = *(u32 *)(w + 0x168);
        func_02045334(bg);
        func_02045374(bg);
        func_020409B4(func_02045730(bg));
    } else {
        bg = *(u32 *)(w + 0x164);
        func_02045334(bg);
        func_02045374(bg);
        func_020409B4(func_02045730(bg));
        bg = *(u32 *)(w + 0x168);
        func_02045334(bg);
        func_02045374(bg);
        func_020409B4(func_02045730(bg));
    }
}
