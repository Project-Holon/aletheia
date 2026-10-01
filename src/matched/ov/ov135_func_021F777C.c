/*
 * function: func_021F777C
 * address: 0x021F777C
 * packet: pkt_ov135_021F777C
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02200BAC 0x02200BAC thumb ov135
 *   tbl_02202EC0 0x02202EC0 data a2
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned u32;
typedef struct { u8 pad0[0xD40]; void *win; u8 padD44[0xD90-0xD44]; void *wins[6]; } Work;
extern const u16 tbl_02202EC0[][2];
extern void *func_020450F0(u32 bg, u8 x, u8 y, u8 w, u8 h, u8 pal, u16 base);
extern void *func_02045770(void *win);
extern void func_02043B5C(void *bmp, u32 color);
extern void func_02045334(void *win);
extern void func_02045374(void *win);
extern u32 func_02045730(void *win);
extern void func_020409B4(u32 layer);
extern void func_02200BAC(void *p, u32 mode);
void func_021F777C(Work *p)
{
    void *w;
    int i;
    p->win = func_020450F0(0, 2, 21, 27, 2, 13, 1);
    func_02043B5C(func_02045770(p->win), 0);
    w = p->win;
    func_02045334(w);
    func_02045374(w);
    func_020409B4(func_02045730(w));
    for (i = 0; i < 6; i++) {
        p->wins[i] = func_020450F0(3, tbl_02202EC0[i][0], tbl_02202EC0[i][1], 12, 2, 13, 1);
        func_02043B5C(func_02045770(p->wins[i]), 0);
        w = p->wins[i];
        func_02045334(w);
        func_02045374(w);
        func_020409B4(func_02045730(w));
    }
    func_02200BAC(p, 3);
}
