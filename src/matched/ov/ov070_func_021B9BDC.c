/*
 * function: func_021B9BDC
 * address:  0x021B9BDC
 * packet:   pkt_ov070_021B9BDC
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020450F0  0x020450F0  arm
 *   func_021B9BA0  0x021B9BA0  thumb  ov070
 *   func_020456F8  0x020456F8  arm
 *   func_02045374  0x02045374  arm
 *   func_020490F4  0x020490F4  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_02049238  0x02049238  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_021BB6E0  0x021BB6E0  thumb  ov070
 *   func_020355C4  0x020355C4  arm
 *   func_021B9850  0x021B9850  thumb  ov070
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef short s16;

extern int func_020450F0(int, int, int, int, int, int, int);
extern void func_021B9BA0(char *);
extern void func_020456F8(int);
extern void func_02045374(int);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern int func_0204AF28(int, int, int, u16);
extern void func_02049238(int);
extern void func_02045CAC(u32, u32, u32);
extern void func_021BB6E0(char *p, u32 *obj, u32 str, u16 x, s16 y, u16 color);
extern int func_020355C4(void);
extern void func_021B9850(char *);

void func_021B9BDC(char *p)
{
    void *bg;

    *(int *)(p + 0x774) = func_020450F0(3, 0x12, 9, 0xc, 3, 3, 1);
    func_021B9BA0(p);
    func_020456F8(*(int *)(p + 0x774));
    *(int *)(p + 0x754) = func_020450F0(3, 0x11, 0xd, 0xb, 2, 3, 1);
    *(int *)(p + 0x76C) = func_020450F0(3, 0x11, 0xf, 0xb, 2, 3, 1);
    *(int *)(p + 0x734) = func_020450F0(6, 0, 0x13, 0x20, 5, 0, 1);
    *(int *)(p + 0x73C) = func_020450F0(6, 7, 5, 0x12, 3, 0, 1);
    *(int *)(p + 0x744) = func_020450F0(6, 0x14, 8, 6, 3, 0, 1);
    *(int *)(p + 0x74C) = func_020450F0(6, 2, 0xc, 0x1d, 7, 0, 1);
    func_02045374(*(int *)(p + 0x73C));
    func_02045374(*(int *)(p + 0x744));
    func_02045374(*(int *)(p + 0x74C));
    func_02045374(*(int *)(p + 0x734));
    bg = func_020490F4(0x19, *(u16 *)(p + 0x544));
    *(int *)(p + 0x550) = func_0204AF28(bg, 1, 0, *(u16 *)(p + 0x544));
    func_02049238(bg);
    func_02045CAC(*(u32 *)(p + 0x51C), 0x66, *(u32 *)(p + 0x524));
    func_021BB6E0(p, (u32 *)(p + 0x734), *(u32 *)(p + 0x524), 8, 4, 0x3DC0);
    func_02045CAC(*(u32 *)(p + 0x51C), 0x5d, *(u32 *)(p + 0x524));
    func_021BB6E0(p, (u32 *)(p + 0x734), *(u32 *)(p + 0x524), 8, 0x18, 0x3DC0);
    func_02045CAC(*(u32 *)(p + 0x51C), 0x5b, *(u32 *)(p + 0x524));
    func_021BB6E0(p, (u32 *)(p + 0x734), *(u32 *)(p + 0x524), 0x70, 4, 0x3DC0);
    func_02045CAC(*(u32 *)(p + 0x51C), 0x5c, *(u32 *)(p + 0x524));
    func_021BB6E0(p, (u32 *)(p + 0x734), *(u32 *)(p + 0x524), 0x70, 0x18, 0x3DC0);
    func_02045CAC(*(u32 *)(p + 0x51C), 0x5a, *(u32 *)(p + 0x524));
    func_021BB6E0(p, (u32 *)(p + 0x734), *(u32 *)(p + 0x524), 0xd0, 4, 0x3DC0);
    if (func_020355C4() == 0) {
        func_021B9850(p);
    }
}
