/*
 * function: func_021F0438
 * address:  0x021F0438
 * packet:   pkt_ov032_021F0438
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F05E8  0x021F05E8  thumb  ov032
 *   func_021F0B10  0x021F0B10  thumb  ov032
 *   func_021F0668  0x021F0668  thumb  ov032
 *   func_021F055C  0x021F055C  thumb  ov032
 *   func_021659F0  0x021659F0  thumb  ov010
 *   func_021F0F44  0x021F0F44  thumb  ov032
 *   func_0201EE0C  0x0201EE0C  thumb
 *   func_021F029C  0x021F029C  thumb  ov032
 *   func_021F18C4  0x021F18C4  thumb  ov032
 *   func_021657E8  0x021657E8  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021F05E8(u8 *p, int a, u32 b);
extern void func_021F0B10(u8 *p, int a, void *b);
extern int func_021F0668(u8 *p, int i);
extern int func_021F055C(u8 *p);
extern int func_021659F0(int, int);
extern u8 *func_021F0F44(u8 *p, int a);
extern void func_0201EE0C(void *win, u32 slot, void *str, u32 a, u32 b, u32 c);
extern void func_021F029C(u8 *p, int a);
extern void func_021F18C4(u8 *p, int a);
extern void func_021657E8(int a, int b);

int func_021F0438(u8 *p)
{
    u8 *e;
    u8 s;

    if (*(int *)(p + 0xA8) != 0)
        return 5;
    switch (*(int *)(p + 0x6C)) {
    case 0:
        func_021F05E8(p, 2, 1);
        func_021F0B10(p, 2, p + 0xA8);
        (*(int *)(p + 0x6C))++;
        break;
    case 1:
        if (func_021F0668(p, 2) != 0)
            break;
        func_021F05E8(p, 0, 2);
        func_021F05E8(p, 1, 2);
        func_021F05E8(p, 3, 2);
        (*(int *)(p + 0x6C))++;
        break;
    case 2:
        *(int *)(p + 0x6C) = func_021F055C(p);
        if (*(int *)(p + 0x6C) == 3)
            return 3;
        break;
    case 4:
        s = func_021659F0(*(int *)(p + 0x3C), p[0x7E] + p[0x7C]);
        e = func_021F0F44(p, s);
        func_0201EE0C(*(void **)(p + 0x110), 0, *(void **)(e + 0x24), e[4], 1, 2);
        func_021F029C(p, 1);
        func_021F18C4(p, 3);
        func_021657E8(*(int *)(p + 4), *(u16 *)(e + 6));
        *(int *)(p + 0x6C) = 5;
        break;
    case 5:
        func_021F029C(p, 0);
        *(int *)(p + 0x6C) = 6;
        break;
    case 3:
        func_021F05E8(p, 2, 0);
        *(int *)(p + 0x6C) = 2;
        break;
    case 6:
        func_021F05E8(p, 4, 0);
        func_021F0B10(p, 1, p + 0xA8);
        *(int *)(p + 0x6C) = 7;
        break;
    case 7:
        *(int *)(p + 0x6C) = 0;
        return 0;
    }
    return 5;
}
